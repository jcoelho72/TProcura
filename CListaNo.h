#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "TProcuraConstrutiva.h"

// estrutura para �ndice a fazer a fun��o de lista (em vetor), de modo a reduzir custos de inser��o ordenada 
// utilizado em CListaNo
typedef struct SIndice {
	TNo estado; // elemento na lista
	int prox; // pr�ximo elemento da lista, pela ordem mantida (de custo)
	int proxDistinto; // pr�ximo elemento da lista com custo distinto
} TIndice;

// classe para manter lista ordenada de estados (CustoUniforme e AStar)
class CListaNo {
private:
	int limite; // tamanho da lista, se !=0 --- tamanho vai at� ao dobro, ap�s o qual � limpa para metade dos elementos
	TVector<TIndice> indice; // �ndice com a estrutura de lista
	TVector<int> livre; // �ndices da lista apagados, que est�o livres e podem ser utilizados
	bool completa; // se verdade, nunca foi limpa, pelo que a lista � completa
public:
	CListaNo(int limite = 0) :
		limite(limite),
		indice(2 * limite),
		livre(limite),
		completa(true),
		atual(0) {}
	~CListaNo();

	// elemento a ser processado 
	// (anteriores a este, excepto o primeiro, podem ser apagados, quando h� falta de espa�o)
	int atual;

	bool Completa() { return completa; }

	// retorna o valor de um elemento
	int Valor(int i) {
		TNo estado;
		if ((estado = Estado(i)) != NULL)
			return estado->LowerBound();
		return INT_MAX;
	}

	// retorna o pr�ximo elemento, ou -1 se n�o h� mais
	int Proximo(int i = -1) {
		if (i < 0)
			return indice[atual].prox;
		if (i >= 0 && i < indice.Count())
			return indice[i].prox;
		return -1;
	}
	// este passo � cr�tico para poder inserir rapido numa lista ordenada com muitos elementos iguais
	int ProximoDistinto(int i = -1) {
		if (i < 0)
			return indice[atual].proxDistinto;
		if (i >= 0 && i < indice.Count())
			return indice[i].proxDistinto;
		return -1;
	}
	// retorna o estado deste elemento
	TNo Estado(int i = -1) {
		if (i < 0)
			return indice[atual].estado;
		if (i >= 0 && i < indice.Count())
			return indice[i].estado;
		return NULL;
	}

	int Inserir(TNo elemento, int id = 0); // insere por ordem de LB, retorna o primeiro elemento com o mesmo valor
	void Inserir(TVector<TNo>& elementos); // inserir todos os elementos por ordem (n�o alterar atual)

private:
	int NovoElemento(TNo elemento); // retorna o �ndice onde foi inserido
	void LibertarLista();
	void LibertarSeguinte(int id);
};