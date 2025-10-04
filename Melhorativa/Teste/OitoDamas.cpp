#include "OitoDamas.h"
#include <stdio.h>
#include <string.h>

int COitoDamas::nDamas = 8; // número de damas desta instância 

COitoDamas::COitoDamas(void)
{
}

COitoDamas::~COitoDamas(void)
{
}

void COitoDamas::Inicializar(void)
{
	TProcuraMelhorativa::Inicializar();
	damas = {}; 
	nDamas = instancia.valor;
	NovaSolucao();
}


void COitoDamas::Debug(bool completo)
{
	for (int i = 0; i < nDamas; i++) {
		printf("\n");
		for (int j = 0; j < nDamas; j++) {
			int cor = ((i + j) % 2 ? ' ' : ':');
			if (damas.Count() > i && damas[i] == j)
				printf("%c%c", '#', '#');
			else
				printf("%c%c", cor, cor);
		}
	}
}

// e gerada uma nova solucao aleatoriamente.
void COitoDamas::NovaSolucao(void)
{
	damas.Count(nDamas);
	for (int i = 0; i < nDamas; i++)
		damas[i] = TRand::rand() % nDamas;
}

// Retorna o valor da solucao completa actual.
int COitoDamas::Avaliar(void)
{
	custo = 0;
	TProcuraMelhorativa::Avaliar();
	// calcular o numero de pares de damas atacadas
	for (int i = 0; i < nDamas - 1; i++)
		for (int j = i + 1; j < nDamas; j++)
			if (damas[i] == damas[j] || damas[i] - damas[j] == i - j || damas[i] - damas[j] == j - i)
				custo++;
	return custo;
}

void COitoDamas::Vizinhanca(TVector<TPonto>& vizinhos)
{
	// trocar a posicao de cada dama
	for (int i = 0; i < nDamas; i++)
		for (int j = 0; j < nDamas; j++)
			if (j != damas[i]) {
				COitoDamas* vizinho = (COitoDamas*)Duplicar();
				vizinho->damas[i] = j;
				vizinhos += vizinho;
			}
	TProcuraMelhorativa::Vizinhanca(vizinhos);
}

void COitoDamas::Mutar(void)
{
	// trocar a posicao de uma das damas (50%)
	damas[TRand::rand() % nDamas] = TRand::rand() % nDamas;
}

void COitoDamas::Cruzamento(TPonto a, TPonto b)
{
	int divisao = 1 + TRand::rand() % (nDamas - 2); // divisao tem de ter elementos de um e de outro
	damas.Count(8);
	for (int i = 0; i < divisao; i++)
		damas[i] = ((COitoDamas*)a)->damas[i];
	for (int i = divisao; i < 8; i++)
		damas[i] = ((COitoDamas*)b)->damas[i];
	TProcuraMelhorativa::Cruzamento(a, b);
}

int COitoDamas::Distancia(TPonto a)
{
	int distancia = 0;
	for (int i = 0; i < nDamas; i++)
		if (damas[i] != ((COitoDamas*)a)->damas[i])
			distancia++;
	return distancia;
}


