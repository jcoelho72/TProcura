#pragma once
#include "../TProcuraAdversa.h"

///////////////////////////////////////////////////////////////////////////////
//	CJogoDoGalo class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho
//	Last revision: 2025-01-30
//	Description:
//    Implementa o Jogo do Galo. Este jogo e jogado num tabuleiro 3x3 por dois jogadores
//    em que cada jogador joga a vez numa posicao vazia, colocando a sua marca.
//    Ganha o jogador que conseguir fazer 3 em linha com a sua marca.
///////////////////////////////////////////////////////////////////////////////
class CJogoDoGalo :
	public TProcuraAdversa
{
public:
	CJogoDoGalo(void);
	~CJogoDoGalo(void);

	// estrutura de dados
	TVector<char> tabuleiro;

	// métodos virtuais redefinidos

	TProcuraConstrutiva* Duplicar(void);
	void Copiar(TProcuraConstrutiva* objecto);
	void SolucaoVazia(void);
	void Sucessores(TVector<TNo>&sucessores);
	bool SolucaoCompleta(void);
	void Debug(void);
	const char* Acao(TProcuraConstrutiva* sucessor);
	void TesteManual(const char* nome);
	void Codifica(uint64_t estado[OBJETO_HASHTABLE]);
	int Heuristica(void);

private:
	// métodos de normalização de um estado
	void Normalizar(TVector<char>& tabuleiro); // coloca em tabuleiro o estado normalizado 
	int PesoVersao(TVector<char>& tabuleiro); // peso da versão do estado
	void Simetria(TVector<char>& tabuleiro, int eixo); // aplica uma simetria
	void Troca(char& a, char& b); // troca dois valores
	int Codigo(char peca) { return peca == 'x' ? 1 : (peca == 'o' ? 2 : 3); }
	int Indice(int i, int j) { return i * 3 + j; }
};
