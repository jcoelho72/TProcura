#pragma once
#include "../TProcuraAdversa.h"

enum EVariantesJogo {
	regular,  // jogar em qualquer casa livre
	gravidade, // jogar na linha de baixo, ou por cima de uma peça
	// ideias para outras variantes:
	jogadaDupla, // jogam sempre duas peças, mas a segunda peça + serve para ambos
	bordasLigadas, // linha de cima liga com a de baixo, coluna da esquerda liga com a da direita
	zonasOcupadas // algumas céculas já estão ocupadas e ficam inviáveis para uso
};

typedef struct SJogoEmLinha {
	int K; // número de marcas em linha
	int N; // número de linhas do tabuleiro
	int M; // número de colunas do tabuleiro
	EVariantesJogo variante; // qual a variante
} TJogoEmLinha;

///////////////////////////////////////////////////////////////////////////////
//	CJogo4emLinha class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho
//	Last revision: 2009-03-30
//	Description: 
///////////////////////////////////////////////////////////////////////////////
class CJogoEmLinha :
	public TProcuraAdversa
{
public:
	TVector<char> tabuleiro;
public:
	CJogoEmLinha(void);
	~CJogoEmLinha(void);

	// dados da instância
	static TJogoEmLinha inst; 

	// Cria um objecto que é uma cópia deste
	TProcuraConstrutiva* Duplicar(void);
	// Fica com uma cópia de objecto
	void Copiar(TProcuraConstrutiva*objecto);
	// Coloca o objecto no estado inicial da procura
	void SolucaoVazia(void);
	// Coloca em sucessores a lista de objectos sucessores (são alocados neste método e têm de ser apagados)
	// O custo não necessita de ser preenchido, caso seja sempre unitário
	// chamar o método desta classe após adicionar os sucessores para actualizar geracoes e expansoes
	void Sucessores(TVector<TNo>&sucessores);
	// Retorna verdade caso o estado actual seja um estado objectivo
	bool SolucaoCompleta(void);
	// Escrever informação de debug sobre o objecto currente 
	// (utilizar variável TProcuraConstrutiva::debug para seleccionar o detalhe pretendido)
	void Debug(void);

	void ResetParametros();


	// Redefinir para poder utilizar os algoritmos informados
	// O custo desde o nó inicial é tido em conta, esta função deve devolver o custo estimado
	// nunca sobre estimando, deste estado até ao nó final mais próximo (é um mínimo)
	// chamar para actualiação de avaliacoes
	int Heuristica(void);

	const char* Acao(TNo sucessor);
	void TesteManual(const char* nome);
	void Codifica(uint64_t estado[OBJETO_HASHTABLE]);
	int Codigo(char peca) { return peca == 'x' ? 1 : (peca == 'o' ? 2 : 3); }
	int Indice(int i, int j) { return i * inst.M + j; }
	char Casa(int i, int j) { return tabuleiro[Indice(i, j)]; }
	void Casa(int i, int j, char valor) { tabuleiro[Indice(i, j)] = valor; }
	bool VerLinha(int i, int j, int di, int dj);
};
