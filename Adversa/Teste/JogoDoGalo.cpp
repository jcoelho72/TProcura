#include "JogoDoGalo.h"
#include <stdio.h>

CJogoDoGalo::CJogoDoGalo(void)
{
}

CJogoDoGalo::~CJogoDoGalo(void)
{
}

TProcuraConstrutiva* CJogoDoGalo::Duplicar(void)
{
	CJogoDoGalo* clone = new CJogoDoGalo;
	if (clone != NULL)
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

void CJogoDoGalo::Copiar(TProcuraConstrutiva*objecto)
{
	tabuleiro = ((CJogoDoGalo*)objecto)->tabuleiro;
	minimizar = ((CJogoDoGalo*)objecto)->minimizar;
}

void CJogoDoGalo::SolucaoVazia(void)
{
	TProcuraConstrutiva::SolucaoVazia();
	minimizar = true;
	tabuleiro.Count(9);
	for (int i = 0; i < 9; i++)
		tabuleiro[i] = '.';
	tamanhoCodificado = 1; // 9 posições, 2 bits cada, 18 bits cabe em 64 bits
}

void CJogoDoGalo::Sucessores(TVector<TNo>&sucessores)
{
	CJogoDoGalo* novo;
	if (!SolucaoCompleta()) {
		for (int i = 0; i < 9; i++)
			if (tabuleiro[i] == '.') {
				sucessores.Add(novo = (CJogoDoGalo*)Duplicar());
				if (memoriaEsgotada)
					return;
				novo->minimizar = !minimizar;
				novo->tabuleiro[i] = (minimizar ? 'x' : 'o');
			}
		TProcuraAdversa::Sucessores(sucessores);
	}
}

bool CJogoDoGalo::SolucaoCompleta(void)
{
	// verificar se há três em linha
	for (int i = 0; i < 3; i++) // verificar todas as linhas
		if (tabuleiro[Indice(i, 0)] != '.' &&
			tabuleiro[Indice(i, 0)] == tabuleiro[Indice(i, 1)] &&
			tabuleiro[Indice(i, 2)] == tabuleiro[Indice(i, 1)])
			return true;
	for (int i = 0; i < 3; i++) // verificar todas as colunas
		if (tabuleiro[Indice(0, i)] != '.' &&
			tabuleiro[Indice(0, i)] == tabuleiro[Indice(1, i)] &&
			tabuleiro[Indice(2, i)] == tabuleiro[Indice(1, i)])
			return true;
	// verificar diagonais
	if (tabuleiro[Indice(0,0)] != '.' && 
		tabuleiro[Indice(0, 0)] == tabuleiro[Indice(1, 1)] && 
		tabuleiro[Indice(1, 1)] == tabuleiro[Indice(2, 2)])
		return true;
	if (tabuleiro[Indice(0, 2)] != '.' &&
		tabuleiro[Indice(0, 2)] == tabuleiro[Indice(1, 1)] &&
		tabuleiro[Indice(1, 1)] == tabuleiro[Indice(2, 0)])
		return true;
	// verificar se há espaço para mais jogadas
	for (int i = 0; i < 9; i++)
		if (tabuleiro[i] == '.')
			return false; // podem ser feitas mais jogadas
	return true; // nao ha hipotese de mais jogadas
}

const char* CJogoDoGalo::Acao(TProcuraConstrutiva* sucessor) {
	static char str[20];
	CJogoDoGalo* suc = (CJogoDoGalo*)sucessor;
	int diferenca = -1;
	// verificar que há uma só diferença
	for (int i = 0; i < 9; i++)
		if (tabuleiro[i] != suc->tabuleiro[i]) {
			if (diferenca == -1)
				diferenca = i;
			else // duas diferenças
				return "Inv"; 
		}
	sprintf(str, "%c%d", 'a' + diferenca % 3, 1 + diferenca / 3);
	return str;
}

void CJogoDoGalo::Debug(void)
{
	NovaLinha(); // cabeçalho
	printf(" ");
	for (int i = 0; i < 3; i++)
		printf(" %c", 'A' + i);
	for (int i = 0; i < 3; i++) {
		NovaLinha();
		printf("%d", i + 1);
		for (int j = 0; j < 3; j++)
			printf(" %c", tabuleiro[i * 3 + j]);
		printf(" %d ", i + 1);
	}
	NovaLinha(); // final
	printf(" "); 
	for (int i = 0; i < 3; i++)
		printf(" %c", 'A' + i);
}

void CJogoDoGalo::TesteManual(const char* nome)
{
	instancia = { NULL, 1,1,1, NULL, NULL };
	TProcuraAdversa::TesteManual(nome);
}

int CJogoDoGalo::Heuristica(void)
{
	heuristica = 0;

	if (ExisteHeuritica())
		return heuristica;
	
	// jogo muito pequeno, fazer so o obrigatorio
	// ver quem ganhou
	for (int i = 0; i < 3; i++) // verificar todas as linhas
		if (tabuleiro[i * 3] != '.' && 
			tabuleiro[i * 3] == tabuleiro[i * 3 + 1] && 
			tabuleiro[i * 3 + 2] == tabuleiro[i * 3 + 1]) 
			heuristica = tabuleiro[i * 3] == 'x' ? -infinito : infinito;
	for (int i = 0; i < 3; i++) // verificar todas as colunas
		if (tabuleiro[i] != '.' && 
			tabuleiro[i] == tabuleiro[i + 3] && 
			tabuleiro[i + 6] == tabuleiro[i + 3])
			heuristica = tabuleiro[i] == 'x' ? -infinito : infinito;
	// verificar diagonais
	if (tabuleiro[0] != '.' && tabuleiro[0] == tabuleiro[4] && tabuleiro[4] == tabuleiro[8])
		heuristica = tabuleiro[0] == 'x' ? -infinito : infinito;
	if (tabuleiro[2] != '.' && tabuleiro[2] == tabuleiro[4] && tabuleiro[4] == tabuleiro[6])
		heuristica = tabuleiro[2] == 'x' ? -infinito : infinito;
	// ninguem ganhou, retornar 0
	return TProcuraAdversa::Heuristica();;
}

// estados repetidos num nível podem ser obtidos por ordens distintas de movimentos, para além das simetrias
void CJogoDoGalo::Codifica(uint64_t estado[OBJETO_HASHTABLE]) {
	TVector<char> tabuleiro;
	// obter o estado normalizado, para que os estados fiquem iguais a menos de operações de simetria
	Normalizar(tabuleiro);
	TProcuraConstrutiva::Codifica(estado);
	// codificar números de 2 bits: ".xo"
	for (int i = 0, index = 0; i < 9; i++, index += 2)
		estado[index >> 6] |= ((uint64_t)Codigo(tabuleiro[i])) << (index & 63);
}

// métodos de normalização de um estado
// coloca em tabuleiro o estado normalizado 
void CJogoDoGalo::Normalizar(TVector<char>& tabuleiro) {
	int peso, atual;
	bool alterado;
	tabuleiro = CJogoDoGalo::tabuleiro;
	// obter o tabuleiro de menor peso, mediante as 3 simetrias
	peso = atual = PesoVersao(tabuleiro);
	do {
		alterado = false;
		for (int i = 0; i < 3; i++) {
			Simetria(tabuleiro, i);
			atual = PesoVersao(tabuleiro);
			if (atual < peso) {
				peso = atual;
				alterado = true;
			}
			else
				Simetria(tabuleiro, i); // repor
		}
	} while (alterado);
	// percorridas todas as simetrias e nada é melhor, escolher esta
}

// peso da versão do estado
int CJogoDoGalo::PesoVersao(TVector<char>& tabuleiro) {
	int peso = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			if (tabuleiro[Indice(i, j)] == 'x')
				peso += Indice(i, j);
			else if (tabuleiro[Indice(i, j)] == 'o')
				peso += Indice(i, j) * 100;
	return peso;
}

// aplica uma simetria
void CJogoDoGalo::Simetria(TVector<char>& tabuleiro, int eixo) {
	if (eixo == 0) { // simetria horizontal
		for (int i = 0; i < 3; i++)
			for (int j = 0; j < 1; j++)
				Troca(tabuleiro[Indice(i, j)], tabuleiro[Indice(i, 2 - j)]);
	}
	else if (eixo == 1) { // simetria vertical
		for (int i = 0; i < 1; i++)
			for (int j = 0; j < 3; j++)
				Troca(tabuleiro[Indice(i, j)], tabuleiro[Indice(2 - i, j)]);
	}
	else { // simetria diagonal
		for (int i = 0; i < 3; i++)
			for (int j = i + 1; j < 3; j++)
				Troca(tabuleiro[Indice(i, j)], tabuleiro[Indice(j, i)]);
	}
}

void CJogoDoGalo::Troca(char& a, char& b) {
	char aux = a;
	a = b;
	b = aux;
}
