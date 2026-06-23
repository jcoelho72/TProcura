#pragma once
#include "TProcuraMelhorativa.h"

enum ETiposVizinhancaPermutacao {
	vizInserirCP = 1,        // insere um elemento noutro local (deslocando os outros)
	vizTrocaParCP,           // troca dois elementos (permuta)
	vizInverterSegmentoCP,   // inverte um segmento 
};

enum ETiposDistanciaPermutacao {
	distHammingCP = 1,	 // número de posições com valores diferentes
	distKendallTauCP,		 // distância Kendall tau (número de pares fora de ordem)
	distSpearmanFootruleCP // distância Spearman footrule (soma das diferenças absolutas das posições)
};

class TCodificacaoPermutacao :
    public TProcuraMelhorativa
{
public:
	TCodificacaoPermutacao() {}
	~TCodificacaoPermutacao() {}

	TVector<int> estado; // codificação por permutação
	static int nElementos; // número de elementos na permutação

	// métodos necessários redefinir
	int Avaliar(void) = 0;
	TPonto Duplicar(void) = 0;

	// deve carregar a instância, para variáveis estáticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void)=0; 

	// métodos que podem ser redefinidos
	void Debug(bool completo = true) override;

	// métodos que não se prevê que sejam redefinidos
	void Copiar(TPonto objeto);
	void NovaSolucao(void);
	bool Acao(TString acao);
	void ResetParametros();
	// operadores melhorativos
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);

	using TProcura::Debug;

	// nomes dos parâmetros fixos na codificação binária
	static int TIPO_CRUZAR_CP;
	static int TIPO_MUTAR_CP;
	static int TIPO_VIZINHO_CP;
	static int LIMITE_VIZINHOS_CP;
	static int TIPO_DISTANCIA_CP;

};

