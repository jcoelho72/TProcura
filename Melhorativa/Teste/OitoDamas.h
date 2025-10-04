#pragma once
#include "../TProcuraMelhorativa.h"
#include "../TCodificacaoInteira.h"
#include "../TCodificacaoPermutacao.h"

///////////////////////////////////////////////////////////////////////////////
//	COitoDamas class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho 
//	Last revision: 2025-01-30
//	Description:
//    Implementa o problema das oito damas. Este problema consiste em colocar
//    oito damas de xadrez (movem-se na horizontal, vertical e diagonal), num
//    tabuleiro de xadrez, sem que estas se ataquem umas as outras.
//    Generalizado para N damas, o ID da instância é o número de damas
///////////////////////////////////////////////////////////////////////////////

constexpr int MAX_DAMAS = 40;

class COitoDamas :
	public TProcuraMelhorativa
{
public:
	COitoDamas(void);
	~COitoDamas(void);

	// estrutura de dados: posicao de cada dama
	TVector<int> damas;
	static int nDamas; // número de damas desta instância

	// Metodos virtuais redefinidos
	TPonto Duplicar(void) {
		COitoDamas* clone = new COitoDamas;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}

	void Copiar(TPonto objecto) {
		TProcuraMelhorativa::Copiar(objecto);
		damas = ((COitoDamas*)objecto)->damas;
		nDamas = ((COitoDamas*)objecto)->nDamas;
	}

	void Inicializar(void);
	bool SolucaoCompleta(void) const { return damas.Count() == nDamas; }
	void Debug(bool completo = true) override;
	void MostrarSolucao(void) { Debug(); }
	void ResetParametros() {
		TProcuraMelhorativa::ResetParametros();
		instancia = { NULL, 8,4,MAX_DAMAS, NULL, NULL };
	}

	// metodos virtuais redefinidos de TProcuraMelhorativa

	void NovaSolucao(void);
	int Avaliar(void);
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);

private:
	// métodos de normalização de um estado
	void Normalizar(TVector<int>& damas); // coloca em damas o estado normalizado 
	int PesoVersao(int tab[MAX_DAMAS][MAX_DAMAS]); // peso da versão do estado
	void Simetria(int tab[MAX_DAMAS][MAX_DAMAS], int eixo); // aplica uma simetria
	void Troca(int& a, int& b); // troca dois valores
};

// versão com codificação inteira
class COitoDamasCI :
	public TCodificacaoInteira
{
public:
	COitoDamasCI() {}
	~COitoDamasCI() {}

	int Avaliar(void) {
		custo = 0;
		TProcuraMelhorativa::Avaliar();
		// calcular o numero de pares de damas atacadas
		for (int i = 0; i < nElementos - 1; i++)
			for (int j = i + 1; j < nElementos; j++)
				if (estado[i] == estado[j] || estado[i] - estado[j] == i - j || estado[i] - estado[j] == j - i)
					custo++;
		return custo;
	}

	void ResetParametros() {
		TCodificacaoInteira::ResetParametros();
		instancia = { NULL, 8,4,MAX_DAMAS, NULL, NULL };
	}

	TPonto Duplicar(void) {
		COitoDamasCI* clone = new COitoDamasCI;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}

	// deve carregar a instância, para variáveis estáticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void) {
		TProcuraMelhorativa::Inicializar();
		nElementos = instancia.valor;
		maxValor.Count(nElementos);
		maxValor.Reset(nElementos);
		NovaSolucao();
	}

	void Debug(bool completo) {
		if (!completo) {
			TCodificacaoInteira::Debug();
			return;
		}
		for (int i = 0; i < nElementos; i++) {
			printf("\n");
			for (int j = 0; j < nElementos; j++) {
				int cor = ((i + j) % 2 ? ' ' : ':');
				if (estado.Count() > i && estado[i] == j)
					printf("%c%c", '#', '#');
				else
					printf("%c%c", cor, cor);
			}
		}
		printf("\n");
	}

};

// versão com codificação por permutação
class COitoDamasCP :
	public TCodificacaoPermutacao
{
public:
	COitoDamasCP() {}
	~COitoDamasCP() {}

	int Avaliar(void) {
		custo = 0;
		TProcuraMelhorativa::Avaliar();
		// calcular o numero de pares de damas atacadas
		for (int i = 0; i < nElementos - 1; i++)
			for (int j = i + 1; j < nElementos; j++)
				if (estado[i] - estado[j] == i - j || estado[i] - estado[j] == j - i)
					custo++;
		return custo;
	}

	TPonto Duplicar(void) {
		COitoDamasCP* clone = new COitoDamasCP;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}

	// deve carregar a instância, para variáveis estáticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void) {
		TProcuraMelhorativa::Inicializar();
		nElementos = instancia.valor;
		NovaSolucao();
	}

	void ResetParametros() {
		TCodificacaoPermutacao::ResetParametros();
		instancia = { NULL, 8,4,MAX_DAMAS, NULL, NULL };
	}

	void Debug(bool completo) {
		if (!completo) {
			TCodificacaoPermutacao::Debug();
			return;
		}
		for (int i = 0; i < nElementos; i++) {
			printf("\n");
			for (int j = 0; j < nElementos; j++) {
				int cor = ((i + j) % 2 ? ' ' : ':');
				if (estado.Count() > i && estado[i] == j)
					printf("%c%c", '#', '#');
				else
					printf("%c%c", cor, cor);
			}
		}
		printf("\n");
	}

};

