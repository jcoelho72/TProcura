#pragma once
#include "TProcuraMelhorativa.h"
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

	// deve carregar a inst�ncia, para vari�veis est�ticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void)=0; 

	// m�todos que podem ser redefinidos
	void Debug(void);


	// m�todos que n�o se prev� que sejam redefinidos
	TPonto Duplicar(void);
	void Copiar(TPonto objecto);
	void NovaSolucao(void);
	bool Acao(const char* acao);
	void ResetParametros();
	// operadores melhorativos
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
};

