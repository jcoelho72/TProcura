#pragma once

#include "../TProcuraMelhorativa.h"

///////////////////////////////////////////////////////////////////////////////
//	CParticao class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho
//	Last revision: 2025-01-30
//	Description:
//    Implementa o problema da particao. Este problema consiste em dividir
//    um conjunto de numeros naturais em duas partes cuja soma dos numeros em cada
//    parte seja igual.
///////////////////////////////////////////////////////////////////////////////
class CParticao :
	public TProcuraMelhorativa
{
public:
	CParticao(void);
	~CParticao(void);

	// estrutura de dados (números a colocar, números colocados em cada lado, e total de cada lado)
	TVector<int> numeros, esquerda, direita;
	int totalEsquerda, totalDireita;
	TVector<bool> solCompleta; // codificação de uma solução, na abordagem melhoriativa: vetor binário
	// na abordagem melhorativa, assume-se que os números estão em "numeros" e não são deslocados para esquerd/direita

	// Metodos virtuais redefinidos
	TPonto Duplicar(void) {
		CParticao* clone = new CParticao;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}

	void Copiar(TPonto objecto) {
		TProcuraMelhorativa::Copiar(objecto);
		numeros = ((CParticao*)objecto)->numeros;
		esquerda = ((CParticao*)objecto)->esquerda;
		direita = ((CParticao*)objecto)->direita;
		totalEsquerda = ((CParticao*)objecto)->totalEsquerda;
		totalDireita = ((CParticao*)objecto)->totalDireita;
		solCompleta = ((CParticao*)objecto)->solCompleta;
	}
	void SolucaoVazia(void);
	void Debug(void);
	void MostrarSolucao(void) { Debug(); }
	void TesteManual(const char* nome);

	// métodos melhorativos
	void NovaSolucao(void);
	int Avaliar(void);
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);
};

/* Testes nas procuras cegas (instâncias 20 a 29)

 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
 20 |  1 |       20 |     163979 |    228706 |          0 |   0,249s |
 21 |  1 |       20 |      97485 |    129560 |          0 |   0,134s |
 22 |  1 |       21 |     179777 |    243832 |          0 |   0,231s |
 23 |  1 | sem sol. |     384627 |    384626 |          0 |   0,374s |
 24 |  1 | sem sol. |    1226523 |   1226522 |          0 |   1,398s |
 25 |  1 | sem sol. |    3461151 |   3461150 |          0 |   4,136s |
 26 |  1 | sem sol. |    3731307 |   3731306 |          0 |   4,743s |
 27 |  1 | não res. |    8559764 |  11039290 |          0 |  15,341s |
 28 |  1 | não res. |    7480665 |   9616932 |          0 |  14,188s |
 29 |  1 | não res. |    7859585 |  10463074 |          0 |  14,493s |
 20 |  2 |       20 |     432100 |    660794 |          0 |   0,408s |
 21 |  2 |       20 |     274472 |    404018 |          0 |   0,244s |
 22 |  2 |       21 |     521564 |    765382 |          0 |   0,504s |
 23 |  2 | não res. |   13574376 |  13958958 |          0 |  10,001s |
 24 |  2 | não res. |   13623338 |  14849840 |          0 |  10,001s |
 25 |  2 | não res. |   11727455 |  15188590 |          0 |  10,001s |
 26 |  2 | não res. |   11099210 |  14830500 |          0 |  10,001s |
 27 |  2 | não res. |    9276509 |  15074684 |          0 |  10,001s |
 28 |  2 | não res. |    9712819 |  15076786 |          0 |  10,001s |
 29 |  2 | não res. |    9693709 |  14481126 |          0 |  10,001s |
 20 |  3 |       20 |        184 |       192 |          0 |   0,001s |
 21 |  3 |       20 |         33 |        40 |          0 |   0,001s |
 22 |  3 |       21 |         34 |        42 |          0 |   0,000s |
 23 |  3 | sem sol. |     384627 |    384626 |          0 |   0,218s |
 24 |  3 | sem sol. |    1226523 |   1226522 |          0 |   0,814s |
 25 |  3 | sem sol. |    3461151 |   3461150 |          0 |   2,372s |
 26 |  3 | sem sol. |    3731307 |   3731306 |          0 |   2,658s |
 27 |  3 |       27 |         45 |        54 |          0 |   0,000s |
 28 |  3 |       27 |         86 |        96 |          0 |   0,000s |
 29 |  3 |       29 |         50 |        58 |          0 |   0,000s |
 20 |  4 |       20 |        148 |       155 |          0 |   0,000s |
 21 |  4 |       20 |         33 |        39 |          0 |   0,000s |
 22 |  4 |       21 |         34 |        41 |          0 |   0,000s |
 23 |  4 | sem sol. |       1008 |      1007 |          0 |   0,002s |
 24 |  4 | sem sol. |       1389 |      1388 |          0 |   0,001s |
 25 |  4 | sem sol. |       1874 |      1873 |          0 |   0,004s |
 26 |  4 | sem sol. |       1473 |      1472 |          0 |   0,002s |
 27 |  4 |       27 |         45 |        53 |          0 |   0,000s |
 28 |  4 |       27 |         81 |        90 |          0 |   0,000s |
 29 |  4 |       29 |         50 |        57 |          0 |   0,000s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |       61 |   33144863 |  40524998 |          0 |  55,287s |   7
Total  2 |       61 |   79935552 | 105290678 |          0 |  71,163s |   3
Total  3 |      144 |    8804040 |   8804086 |          0 |   6,064s |  10
Total  4 |      144 |       6135 |      6175 |          0 |   0,009s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|
 1    |  7 |-10 |-10 |-13
 |----|----|----|----|
 2 -7 |    |-10 |-10 |-27
 |----|----|----|----|
 3 10 | 10 |    | -4 | 16
 |----|----|----|----|
 4 10 | 10 |  4 |    | 24
 |----|----|----|----|
Configuração 1
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0 | P11(Max. Avaliações): 1000000 | P12(Move Primeiro): Sim
P13(População): 20 | P14(Prob. Mutação): 50 | P15(Dist. Mínima): 0
Configuração 2
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0 | P11(Max. Avaliações): 1000000 | P12(Move Primeiro): Sim
P13(População): 20 | P14(Prob. Mutação): 50 | P15(Dist. Mínima): 0
Configuração 3
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): -1 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0 | P11(Max. Avaliações): 1000000 | P12(Move Primeiro): Sim
P13(População): 20 | P14(Prob. Mutação): 50 | P15(Dist. Mínima): 0
Configuração 4
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): -1 | P7(Repetidos): gerados | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0 | P11(Max. Avaliações): 1000000 | P12(Move Primeiro): Sim
P13(População): 20 | P14(Prob. Mutação): 50 | P15(Dist. Mínima): 0


*/