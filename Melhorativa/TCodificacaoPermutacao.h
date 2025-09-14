#pragma once
#include "TProcuraMelhorativa.h"

// nomes dos par�metros fixos na codifica��o bin�ria
enum ECodificacaoPermutacao {
	cruzamentoCP = parametrosMelhorativas,
	mutacaoCP, vizinhancaCP, limiteVizinhancaCP, distanciaCP,
	parametrosCodificacaoPermutacao
};

enum ETiposVizinhancaPermutacao {
	vizInserirCP = 1,        // insere um elemento noutro local (deslocando os outros)
	vizTrocaParCP,           // troca dois elementos (permuta)
	vizInverterSegmentoCP,   // inverte um segmento
};

enum ETiposDistanciaPermutacao {
	distHammingCP = 1,	 // n�mero de posi��es com valores diferentes
	distKendallTauCP,		 // dist�ncia Kendall tau (n�mero de pares fora de ordem)
	distSpearmanFootruleCP // dist�ncia Spearman footrule (soma das diferen�as absolutas das posi��es)
};

class TCodificacaoPermutacao :
    public TProcuraMelhorativa
{
public:
	TCodificacaoPermutacao() {}
	~TCodificacaoPermutacao() {}

	TVector<int> estado; // codifica��o por permuta��o
	static int nElementos; // n�mero de elementos na permuta��o

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
	bool Acao(const char* acao);
	void ResetParametros();
	// operadores melhorativos
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);
};

