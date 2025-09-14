#pragma once
#include "TProcuraMelhorativa.h"

// nomes dos par�metros fixos na codifica��o bin�ria
enum ECodificacaoInteira {
	cruzamentoCI = parametrosMelhorativas,
	mutacaoCI, vizinhancaCI, limiteVizinhancaCI, distanciaCI,
	parametrosCodificacaoInteira
};

enum ETiposVizinhancaInteira {
	vizIncDecValorCI = 1,    // incrementa/decrementa valor
	vizIncDecPot2CI,         // incrementa/decrementa pot�ncia de 2
	vizTrocaValorCI,         // troca valores entre dois elementos
	vizInserirCI,            // insere um elemento noutro local (deslocando os outros)
	vizTrocaParCI,           // troca dois elementos (permuta)
	vizInverterSegmentoCI,   // inverte um segmento
};

enum ETiposDistanciaInteira {
	distHammingCI = 1, // n�mero de posi��es com valores diferentes
	distEuclidianaCI,  // dist�ncia euclidiana (raiz quadrada da soma dos quadrados das diferen�as)
	distManhattanCI    // dist�ncia Manhattan (soma das diferen�as absolutas)
};

class TCodificacaoInteira :
    public TProcuraMelhorativa
{
public:
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

