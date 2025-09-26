#pragma once

#include "TProcuraConstrutiva.h"

/**
 * @brief Estrutura de �ndice para lista de estados.
 *
 * Utilizada internamente pela CListaNo para gerir a lista ordenada.
 */
typedef struct SIndice {
	TNo estado;           ///< Estado armazenado.
	int prox;             ///< Pr�ximo elemento na lista (ordem por custo).
	int proxDistinto;     ///< Pr�ximo elemento na lista com custo distinto.
} TIndice;

/**
 * @brief Lista ordenada de n�s para algoritmos de procura informada.
 *
 * Utilizada nos algoritmos CustoUniforme e AStar para gerir estados ordenados por custo.
 */
class CListaNo {
private:
	int limite;                   ///< Tamanho da lista. Se !=0, a lista � limpa quando atinge o dobro deste valor.
	TVector<TIndice> indice;      ///< Estrutura de �ndice para a lista.
	TVector<int> livre;           ///< �ndices livres para reutiliza��o.
	bool completa;                ///< Indica se a lista nunca foi limpa.
public:
	/**
	 * @brief Construtor da lista de n�s.
	 * @param limite Tamanho limite da lista (opcional).
	 */
	CListaNo(int limite = 0) :
		limite(limite),
		indice(2 * limite),
		livre(limite),
		completa(true),
		atual(0) {}
	~CListaNo();

	int atual; ///< �ndice do elemento atual a processar.

	 /**
	 * @brief Indica se a lista � completa (nunca foi limpa).
	 * @return true se nunca foi limpa; false caso contr�rio.
	 */
	bool Completa() { return completa; }

	/**
	 * @brief Retorna o valor (LowerBound) de um elemento.
	 * @param i �ndice do elemento.
	 * @return Valor do elemento ou INT_MAX se inv�lido.
	 */
	int Valor(int i) {
		TNo estado;
		if ((estado = Estado(i)) != NULL)
			return estado->LowerBound();
		return INT_MAX;
	}

	/**
	 * @brief Retorna o pr�ximo elemento na lista.
	 * @param i �ndice de refer�ncia (opcional). Se n�o fornecido, usa o atual.
	 * @return �ndice do pr�ximo elemento ou -1 se n�o existir.
	 */
	int Proximo(int i = -1) {
		if (i < 0)
			return indice[atual].prox;
		if (i >= 0 && i < indice.Count())
			return indice[i].prox;
		return -1;
	}

	/**
	 * @brief Retorna o pr�ximo elemento com custo distinto.
	 * @param i �ndice de refer�ncia (opcional).
	 * @return �ndice do pr�ximo elemento distinto ou -1.
	 */
	int ProximoDistinto(int i = -1) {
		if (i < 0)
			return indice[atual].proxDistinto;
		if (i >= 0 && i < indice.Count())
			return indice[i].proxDistinto;
		return -1;
	}

	/**
	 * @brief Retorna o estado armazenado no elemento.
	 * @param i �ndice do elemento (opcional).
	 * @return Ponteiro para o estado ou NULL se inv�lido.
	 */
	TNo Estado(int i = -1) {
		if (i < 0)
			return indice[atual].estado;
		if (i >= 0 && i < indice.Count())
			return indice[i].estado;
		return NULL;
	}

	/**
	 * @brief Insere um novo estado na lista, por ordem de LowerBound.
	 * @param elemento Estado a inserir.
	 * @param id ID associado (opcional).
	 * @return �ndice do primeiro elemento com o mesmo valor.
	 */
	int Inserir(TNo elemento, int id = 0); 

	/**
	 * @brief Insere v�rios estados na lista, por ordem.
	 * @param elementos Vetor de estados a inserir.
	 */
	void Inserir(TVector<TNo>& elementos); 

private:
	/**
	 * @brief Cria um novo elemento na lista.
	 * @param elemento Estado a inserir.
	 * @return �ndice onde foi inserido.
	 */
	int NovoElemento(TNo elemento);

	/// Liberta toda a lista (limpeza).
	void LibertarLista();

	/// Liberta o elemento seguinte ao ID fornecido.
	void LibertarSeguinte(int id);
};