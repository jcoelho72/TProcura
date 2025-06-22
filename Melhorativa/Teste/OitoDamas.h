#pragma once
#include "../TProcuraMelhorativa.h"

///////////////////////////////////////////////////////////////////////////////
//	COitoDamas class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho
//	Last revision: 2025-01-30
//	Description:
//    Implementa o problema das oito damas. Este problema consiste em colocar
//    oito damas de xadrez (movem-se na horizontal, vertical e diagonal), num
//    tabuleiro de xadrez, sem que estas se ataquem umas as outras.
//    Generalizado para N damas, o ID da instância é o número de damas
///////////////////////////////////////////////////////////////////////////////

#define MAX_DAMAS 40

class COitoDamas :
	public TProcuraMelhorativa
{
public:
	COitoDamas(void);
	~COitoDamas(void);

	// estrutura de dados: posicao de cada dama
	TVector<int> damas;
	static int nDamas; // número de damas desta instância

	// Metodos virtuais redefinidos
	TPonto Duplicar(void) {
		COitoDamas* clone = new COitoDamas;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}

	void Copiar(TPonto objecto) {
		TProcuraMelhorativa::Copiar(objecto);
		damas = ((COitoDamas*)objecto)->damas;
		nDamas = ((COitoDamas*)objecto)->nDamas;
	}

	void SolucaoVazia(void); 
	bool SolucaoCompleta(void) { return damas.Count() == nDamas; }
	void Debug(void);
	void MostrarSolucao(void) { Debug(); }
	void TesteManual(const char* nome);

	// metodos virtuais redefinidos de TProcuraMelhorativa

	void NovaSolucao(void);
	int Avaliar(void);
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);

private:
	// métodos de normalização de um estado
	void Normalizar(TVector<int>& damas); // coloca em damas o estado normalizado 
	int PesoVersao(int tab[MAX_DAMAS][MAX_DAMAS]); // peso da versão do estado
	void Simetria(int tab[MAX_DAMAS][MAX_DAMAS], int eixo); // aplica uma simetria
	void Troca(int& a, int& b); // troca dois valores
};

/* Testes nas procuras cegas (instâncias 8 a 17)

 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
  8 |  1 |        8 |       1665 |      1965 |          0 |   0,002s |
  9 |  1 |        9 |       6977 |      8042 |          0 |   0,007s |
 10 |  1 |       10 |      30779 |     34815 |          0 |   0,023s |
 11 |  1 |       11 |     149131 |    164246 |          0 |   0,133s |
 12 |  1 |       12 |     773731 |    841989 |          0 |   0,787s |
 13 |  1 |       13 |    4250877 |   4601178 |          0 |   5,084s |
 14 |  1 | não res. |    6900138 |  12939175 |          0 |  11,908s |
 15 |  1 | não res. |    5445913 |  15967696 |          0 |  12,279s |
 16 |  1 | não res. |    4123889 |  16996518 |          0 |  12,649s |
 17 |  1 | não res. |    3651739 |  18318707 |          0 |  13,096s |
  8 |  2 |        8 |        113 |       124 |          0 |   0,000s |
  9 |  2 |        9 |         41 |        60 |          0 |   0,000s |
 10 |  2 |       10 |        102 |       124 |          0 |   0,001s |
 11 |  2 |       11 |         52 |        83 |          0 |   0,000s |
 12 |  2 |       12 |        261 |       295 |          0 |   0,001s |
 13 |  2 |       13 |        111 |       154 |          0 |   0,000s |
 14 |  2 |       14 |       1899 |      1944 |          0 |   0,006s |
 15 |  2 |       15 |       1359 |      1414 |          0 |   0,005s |
 16 |  2 |       16 |      10052 |     10112 |          0 |   0,028s |
 17 |  2 |       17 |       5374 |      5449 |          0 |   0,016s |
  8 |  3 |        8 |        113 |       120 |          0 |   0,001s |
  9 |  3 |        9 |         41 |        56 |          0 |   0,000s |
 10 |  3 |       10 |        102 |       119 |          0 |   0,001s |
 11 |  3 |       11 |         52 |        78 |          0 |   0,000s |
 12 |  3 |       12 |        261 |       289 |          0 |   0,001s |
 13 |  3 |       13 |        111 |       148 |          0 |   0,000s |
 14 |  3 |       14 |       1899 |      1937 |          0 |   0,006s |
 15 |  3 |       15 |       1359 |      1407 |          0 |   0,008s |
 16 |  3 |       16 |       2850 |      2896 |          0 |   0,020s |
 17 |  3 |       17 |       5206 |      5258 |          0 |   0,030s |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |       63 |   25334839 |  69874331 |          0 |  55,968s |   6
Total  2 |      125 |      19364 |     19759 |          0 |   0,057s |  10
Total  3 |      125 |      11994 |     12308 |          0 |   0,067s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|
 1    | -7 | -7 |-14
 |----|----|----|
 2  7 |    |  0 |  7
 |----|----|----|
 3  7 |  0 |    |  7
 |----|----|----|
Configuração 1
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0 | P11(Max. Avaliações): 1000000 | P12(Move Primeiro): Sim
P13(População): 20 | P14(Prob. Mutação): 50 | P15(Dist. Mínima): 0
Configuração 2
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): -1 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0 | P11(Max. Avaliações): 1000000 | P12(Move Primeiro): Sim
P13(População): 20 | P14(Prob. Mutação): 50 | P15(Dist. Mínima): 0
Configuração 3
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): -1 | P7(Repetidos): gerados | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0 | P11(Max. Avaliações): 1000000 | P12(Move Primeiro): Sim
P13(População): 20 | P14(Prob. Mutação): 50 | P15(Dist. Mínima): 0

*/