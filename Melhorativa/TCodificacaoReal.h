#pragma once
#include "TProcuraMelhorativa.h"
class TCodificacaoReal :
    public TProcuraMelhorativa
{
public:
	TCodificacaoReal() {}
	~TCodificacaoReal() {}

	TVector<double> estado; // codifica��o real
	static int nElementos; // n�mero de elementos no estado
	static TVector<double> minValor, maxValor; // valores m�nimo e m�ximo para cada elemento, se vazios, o dom�nio � de 0 a 1

	// m�todos necess�rios redefinir
	int Avaliar(void) = 0;

	// deve carregar a inst�ncia, para vari�veis est�ticas, da subclasse
	// definir valores globais: nElementos, minValor, maxValor
	void Inicializar(void)=0;

	// m�todos que podem ser redefinidos
	void Debug(bool completo = true) override;


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

	using TProcura::Debug;
};

