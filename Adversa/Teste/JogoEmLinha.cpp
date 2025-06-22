#include "JogoEmLinha.h"
#include <stdio.h>

// dados da instância
TJogoEmLinha CJogoEmLinha::inst = { 3,3,3,regular }; // Jogo do Galo

CJogoEmLinha::CJogoEmLinha(void)
{
}

CJogoEmLinha::~CJogoEmLinha(void)
{
}

// Cria um objecto que é uma cópia deste
TProcuraConstrutiva* CJogoEmLinha::Duplicar(void)
{
	CJogoEmLinha* clone = new CJogoEmLinha;
	if (clone != NULL)
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

// Fica com uma cópia de objecto
void CJogoEmLinha::Copiar(TProcuraConstrutiva*objecto)
{
	tabuleiro = ((CJogoEmLinha*)objecto)->tabuleiro;
	minimizar = ((CJogoEmLinha*)objecto)->minimizar;
}

// Coloca o objecto no estado inicial da procura
void CJogoEmLinha::SolucaoVazia(void)
{
	TJogoEmLinha instancias[] = {
		{3,3,3,regular}, // Jogo do Galo
		{4,4,4,regular}, // 4 em linha 4x4
		{4,4,6,regular}, // 4 em linha 4x6
		{4,6,7,gravidade}, // 4 em linha 6x7 gravidade
		{4,6,14,gravidade}, // 4 em linha 6x14 gravidade
		{5,8,8,regular}, // 5 em linha 8x8
		{5,8,12,regular}, // 5 em linha 8x12
		{5,9,9,regular}, // 5 em linha 9x9
		{6,9,11,regular}, // 6 em linha 10x10
		{6,12,12,regular}, // 6 em linha 12x12
	};

	TProcuraConstrutiva::SolucaoVazia();
	infinito = 10000;
	minimizar = true;
	inst = instancias[instancia.valor - 1];

	tabuleiro.Count(inst.N * inst.M);
	for (int i = 0; i < inst.N * inst.M; i++)
		tabuleiro[i] = '.';

	tamanhoCodificado = (inst.N * inst.M * 2) / 64 + 1;
}

void CJogoEmLinha::Sucessores(TVector<TNo>&sucessores)
{
	CJogoEmLinha* novo;
	if (SolucaoCompleta())
		return;
	
	for (int j = 0; j < inst.M; j++)
		for (int i = inst.N - 1; i >= 0; i--)
			if (Casa(i,j) == '.') {
				sucessores.Add(novo = (CJogoEmLinha*)Duplicar());
				novo->minimizar = !minimizar;
				novo->Casa(i, j, (minimizar ? 'x' : 'o'));
				if (inst.variante == gravidade)
					break; // apenas a primeira posição livre da coluna
			}
	TProcuraAdversa::Sucessores(sucessores);
}

bool CJogoEmLinha::VerLinha(int i, int j, int di, int dj) 
{
	int nMax = 0, nMin = 0;
	
	for (int k = 0; 
		i >= 0 && i < inst.N && j >= 0 && j < inst.M; // valores dentro do tabuleiro
		i += di, j += dj, k++) 
	{
		// contabilizar nova casa
		switch (Casa(i, j)) {
		case 'x': nMin++; break;
		case 'o': nMax++; break;
		}
		if (k >= inst.K - 1) {
			if (nMax == inst.K || nMin == inst.K)
				return true;
			switch (Casa(i-di*(inst.K-1), j - dj * (inst.K - 1))) {
			case 'x': nMin--; break;
			case 'o': nMax--; break;
			}
		}
	}
	return false;
}

// Retorna verdade caso o estado actual seja um estado objectivo
bool CJogoEmLinha::SolucaoCompleta(void)
{
	// Processar linhas e diagonais
	for (int linha = 0; linha < inst.N; linha++)
		if (VerLinha(linha, 0, 0, 1) || 
			VerLinha(linha, 0, 1, 1) || 
			VerLinha(linha, inst.M - 1, 1, -1))
			return true;

	// Processar colunas e diagonais
	for (int coluna = 0; coluna < inst.M; coluna++)
		if (VerLinha(0, coluna, 1, 0) || 
			VerLinha(0, coluna, 1, 1) || 
			VerLinha(0, coluna, 1, -1))
			return true;

	// verificar se há espaço para mais jogadas
	for (int i = 0; i < inst.N * inst.M; i++)
		if (tabuleiro[i] == '.')
			return false; // podem ser feitas mais jogadas
	return true; // não há hipótese de mais jogadas
}

// Escrever informação de debug sobre o objecto currente 
// (utilizar variável TProcuraConstrutiva::debug para seleccionar o detalhe pretendido)
void CJogoEmLinha::Debug(void)
{
	// identificação do tipo de jogo
	NovaLinha();
	printf("%d em Linha (%dx%d)", inst.K, inst.M, inst.N);
	if (inst.variante == gravidade)
		printf(" gravidade");
	NovaLinha(); // cabeçalho
	printf("  ");
	for (int i = 0; i < inst.M; i++)
		printf(" %c", 'A' + i);
	for (int i = 0; i < inst.N; i++) {
		NovaLinha();
		printf("%2d", i + 1);
		for (int j = 0; j < inst.M; j++)
			printf(" %c", Casa(i, j));
		printf(" %d ", i + 1);
	}
	NovaLinha(); // final
	printf("  ");
	for (int i = 0; i < inst.M; i++)
		printf(" %c", 'A' + i);
}

void CJogoEmLinha::ResetParametros()
{
	TProcuraAdversa::ResetParametros();
}

const char* CJogoEmLinha::Acao(TNo sucessor)
{
	static char str[20];
	CJogoEmLinha* suc = (CJogoEmLinha*)sucessor;
	int diferenca = -1;
	// verificar que há uma só diferença
	for (int i = 0; i < inst.N * inst.M; i++)
		if (tabuleiro[i] != suc->tabuleiro[i]) {
			if (diferenca == -1)
				diferenca = i;
			else // duas diferenças
				return "Inv";
		}
	sprintf(str, "%c%d", 'a' + diferenca % inst.M, 1 + diferenca / inst.M);
	return str;
}

void CJogoEmLinha::TesteManual(const char* nome)
{
	instancia = { NULL, 1,1,10, NULL, NULL };
	TProcuraAdversa::TesteManual(nome);
}

void CJogoEmLinha::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	TProcuraConstrutiva::Codifica(estado);
	// codificar números de 2 bits: ".xo"
	for (int i = 0, index = 0; i < inst.N * inst.M; i++, index += 2)
		estado[index >> 6] |= ((uint64_t)Codigo(tabuleiro[i])) << (index & 63);
}

int CJogoEmLinha::Heuristica()
{
	static int index[][2] = { {0,1},{1,0}, {1,1}, {1,-1} };
	TVector<int> qMin, qMax;
	int nMax, nMin;

	heuristica = 0;

	if (ExisteHeuritica())
		return heuristica;

	qMin.Count(inst.K - 1); // contabilizar ameaças a 1, 2 e 3 (até K-1)
	qMax.Count(inst.K - 1);
	qMin.Reset(0);
	qMax.Reset(0);
	// processar todas as sequências de 4 
	for (int linha = 0; linha < inst.N; linha++) {
		for (int coluna = 0; coluna < inst.M; coluna++) {
			for (int dir = 0; dir < 4; dir++) { // 4 direções (horizontal, vertical, duas diagonais)
				if ((index[dir][0] > 0 ? linha <= inst.N - inst.K : 1) &&
					(index[dir][1] > 0 ? coluna <= inst.M - inst.K : 
						index[dir][1] < 0 ? coluna >= inst.K - 1 : 1)) 
				{
					nMax = nMin = 0;
					for (int i = 0; i < inst.K && (nMax == 0 || nMin == 0); i++)
						if (Casa(linha + i * index[dir][0], coluna + i * index[dir][1]) == 'x')
							nMin++;
						else if (Casa(linha + i * index[dir][0], coluna + i * index[dir][1]) == 'o')
							nMax++;
					// verificar resultado exato
					if (nMax == inst.K) {
						heuristica = infinito;
						return TProcuraAdversa::Heuristica();
					}
					else if (nMin == inst.K) {
						heuristica = -infinito;
						return TProcuraAdversa::Heuristica();
					}
					// verificar se quem joga tem ameaça a 1, para ganhar na sua vez de jogar
					if (minimizar ? nMin == inst.K - 1 && nMax == 0 : nMax == inst.K - 1 && nMin == 0)
						heuristica = (minimizar ? -infinito : infinito); // vitória em 1, é igual a posição terminal
					// não reteornar de imediato, já que o jogo pode ter sido já ganho pelo adversário

					// registar resultado
					if (nMax > 0 && nMin == 0)
						qMax[inst.K - 1 - nMax]++;
					else if (nMin > 0 && nMax == 0)
						qMin[inst.K - 1 - nMin]++;
				}
			}
		}
	}
	if (heuristica != 0) 
		return TProcuraAdversa::Heuristica();

	heuristica = MaiorAmeaca(qMin, qMax, inst.K - 1);
	// retornar a soma das ameaças
	return TProcuraAdversa::Heuristica();
}
