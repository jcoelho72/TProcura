#include "Particao.h"
#include <stdio.h>
#include <string.h>

CParticao::CParticao(void) : totalDireita(0), totalEsquerda(0)
{
}

CParticao::~CParticao(void)
{
}

void CParticao::SolucaoVazia(void)
{
	TProcura::SolucaoVazia();
	direita.Count(0);
	esquerda.Count(0);
	numeros.Count(0);
	totalDireita = totalEsquerda = 0;
	solCompleta.Count(0);

	// gerar uma instancia provavelmente possivel
	int soma1, soma2;
	soma1 = soma2 = 0;
	for (int i = 0; i < instancia.valor; i++) {
		numeros.Add(TRand::rand() % (3 * instancia.valor));
		if (soma1 < soma2)
			soma1 += numeros.Last();
		else soma2 += numeros.Last();
	}
	// acertar a paridade, muito embora não se saiba se há ou não solução
	if ((soma1 + soma2) % 2 == 1)
		numeros.Last() + 1;
	// garantir que há uma solução
	//if (soma1 != soma2)
	//	numeros.Add(abs(soma1 - soma2));
	numeros.Remove(0);
	numeros.Sort();
}

void CParticao::Debug(void)
{
	int i, j;
	printf("\nColocar #%d: %d = %d",
		numeros.Count(), totalEsquerda, totalDireita);
	if (solCompleta.Count() > 0) {
		for (i = 0, j = 0; i < solCompleta.Count(); i++) {
			if (solCompleta[i]) { // esquerda
				if (j++ % 4 == 0) {
					printf("\n    ");
				}
				printf("%3d ", numeros[i]);
				if (j % 4 == 0) 
					printf(" <<<");
			}
		}
		if (j % 4 != 0) {
			while (j++ % 4 != 0) 
				printf("    ");
			printf(" <<<");
		}
		for (i = 0, j = 0; i < solCompleta.Count(); i++) {
			if (!solCompleta[i]) { // direita
				if (j++ % 4 == 0) {
					printf("\n>>> ");
				}
				printf("%3d ", numeros[i]);
			}
		}
	}
	else {
		for (i = 0; i < numeros.Count(); i++) {
			if (i % 4 == 0) {
				printf("\n--- ");
			}
			printf("%3d ", numeros[i]);
			if ((i + 1) % 4 == 0)
				printf(" ---");
		}
		if (i % 4 != 0) {
			while (i++ % 4 != 0)
				printf("    ");
			printf(" ---");
		}
		for (i = 0; i < esquerda.Count(); i++) {
			if (i % 4 == 0) {
				printf("\n    ");
			}
			printf("%3d ", esquerda[i]);
			if ((i + 1) % 4 == 0)
				printf(" <<<");
		}
		if (i % 4 != 0) {
			while (i++ % 4 != 0)
				printf("    ");
			printf(" <<<");
		}
		for (i = 0; i < direita.Count(); i++) {
			if (i % 4 == 0) {
				printf("\n>>> ");
			}
			printf("%3d ", direita[i]);
		}
	}
}

void CParticao::TesteManual(const char* nome)
{
	instancia = { NULL, 10,2,1000, NULL, NULL };
	TProcuraMelhorativa::TesteManual(nome);
}

// métodos melhorativos
void CParticao::NovaSolucao(void) {
	TProcura::SolucaoVazia();
	solCompleta.Count(numeros.Count());
	for (int i = 0; i < solCompleta.Count(); i++)
		solCompleta[i] = TRand::rand() % 2;
}

int CParticao::Avaliar(void) {
	TProcuraMelhorativa::Avaliar();
	totalEsquerda = totalDireita = 0;
	for (int i = 0; i < solCompleta.Count(); i++)
		if (solCompleta[i])
			totalEsquerda += numeros[i];
		else
			totalDireita += numeros[i];
	return custo = abs(totalDireita - totalEsquerda);
}

void CParticao::Vizinhanca(TVector<TPonto>& vizinhos) {
	// trocar cada valor
	for (int i = 0; i < solCompleta.Count(); i++) {
		CParticao* vizinho = (CParticao*)Duplicar();
		vizinho->solCompleta[i] = !solCompleta[i];
		vizinhos.Add(vizinho);
	}
	TProcuraMelhorativa::Vizinhanca(vizinhos);
}

void CParticao::Mutar(void) {
	// coloca um valor aleatório, com probabilidade de nova mudança em 75%
	do {
		solCompleta.Random() = TRand::rand() % 2;
	} while (TRand::rand() % 4);
}

void CParticao::Cruzamento(TPonto a, TPonto b) {
	// divisao tem de ter elementos de um e de outro
	int divisao = 1 + TRand::rand() % solCompleta.Count()-2; 
	for (int i = 0; i < divisao; i++)
		solCompleta[i] = ((CParticao*)a)->solCompleta[i];
	for (int i = divisao; i < solCompleta.Count(); i++)
		solCompleta[i] = ((CParticao*)b)->solCompleta[i];
	TProcuraMelhorativa::Cruzamento(a, b);
}

int CParticao::Distancia(TPonto a) {
	int diferentes = 0; // número de posições distintas
	for (int i = 0; i < solCompleta.Count(); i++)
		if (solCompleta[i] != ((CParticao*)a)->solCompleta[i])
			diferentes++;
	return diferentes;
}

