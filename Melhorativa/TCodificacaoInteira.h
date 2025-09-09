#pragma once
#include "TProcuraMelhorativa.h"

// nomes dos par�metros fixos na codifica��o bin�ria
enum ECodificacaoInteira {
	cruzamentoCI = parametrosMelhorativas,
	mutacaoCI, vizinhancaCI, limiteVizinhancaCI, distanciaCI,
	parametrosCodificacaoInteira
};

enum ETiposVizinhancaInteira {
	vizIncDecValor = 1,    // incrementa/decrementa valor
	vizIncDecPot2,         // incrementa/decrementa pot�ncia de 2
	vizTrocaValor,         // troca valores entre dois elementos
	vizInserir,            // insere um elemento noutro local (deslocando os outros)
	vizTrocaPar,           // troca dois elementos (permuta)
	vizInverterSegmento,   // inverte um segmento
};

enum ETiposDistanciaInteira {
	distHamming = 1, // n�mero de posi��es com valores diferentes
	distEuclidiana,  // dist�ncia euclidiana (raiz quadrada da soma dos quadrados das diferen�as)
	distManhattan    // dist�ncia Manhattan (soma das diferen�as absolutas)
};

class TCodificacaoInteira :
    public TProcuraMelhorativa
{
	TCodificacaoInteira() {}
	~TCodificacaoInteira() {}

	TVector<int> estado; // codifica��o inteira
	static int nElementos; // n�mero de elementos na permuta��o
	static TVector<int> maxValor; // valor m�ximo para cada elemento

	// m�todos necess�rios redefinir
	int Avaliar(void) = 0;
	TPonto Duplicar(void) = 0;

	// deve carregar a inst�ncia, para vari�veis est�ticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void)=0;

	// m�todos que podem ser redefinidos
	void Debug(void);

	// m�todos que n�o se prev� que sejam redefinidos
	void Copiar(TPonto objecto);
	void NovaSolucao(void);
	void ResetParametros();
	// operadores melhorativos
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);
};

