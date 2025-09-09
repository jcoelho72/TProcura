#pragma once
#include "TProcuraMelhorativa.h"

// nomes dos parâmetros fixos na codificação binária
enum ECodificacaoInteira {
	cruzamentoCI = parametrosMelhorativas,
	mutacaoCI, vizinhancaCI, limiteVizinhancaCI, distanciaCI,
	parametrosCodificacaoInteira
};

enum ETiposVizinhancaInteira {
	vizIncDecValor = 1,    // incrementa/decrementa valor
	vizIncDecPot2,         // incrementa/decrementa potência de 2
	vizTrocaValor,         // troca valores entre dois elementos
	vizInserir,            // insere um elemento noutro local (deslocando os outros)
	vizTrocaPar,           // troca dois elementos (permuta)
	vizInverterSegmento,   // inverte um segmento
};

enum ETiposDistanciaInteira {
	distHamming = 1, // número de posições com valores diferentes
	distEuclidiana,  // distância euclidiana (raiz quadrada da soma dos quadrados das diferenças)
	distManhattan    // distância Manhattan (soma das diferenças absolutas)
};

class TCodificacaoInteira :
    public TProcuraMelhorativa
{
	TCodificacaoInteira() {}
	~TCodificacaoInteira() {}

	TVector<int> estado; // codificação inteira
	static int nElementos; // número de elementos na permutação
	static TVector<int> maxValor; // valor máximo para cada elemento

	// métodos necessários redefinir
	int Avaliar(void) = 0;
	TPonto Duplicar(void) = 0;

	// deve carregar a instância, para variáveis estáticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void)=0;

	// métodos que podem ser redefinidos
	void Debug(void);

	// métodos que não se prevê que sejam redefinidos
	void Copiar(TPonto objecto);
	void NovaSolucao(void);
	void ResetParametros();
	// operadores melhorativos
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);
};

