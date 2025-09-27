#pragma once
#include "TProcuraMelhorativa.h"
class TCodificacaoArvore :
    public TProcuraMelhorativa
{
	TCodificacaoArvore() {}
	~TCodificacaoArvore() {}

    // codificação por árvore
	// (definir operadores e argumentos....)
	//static int nElementos; // número de elementos binários na codificação

	// métodos necessários redefinir
	int Avaliar(void) = 0;

	// deve carregar a instância, para variáveis estáticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void)=0;

	// métodos que podem ser redefinidos
	void Debug(bool completo = true) override;


	// métodos que não se prevê que sejam redefinidos
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

