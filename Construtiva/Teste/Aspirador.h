#pragma once

#include "../TProcuraConstrutiva.h"

/**
 * @brief Representa um estado no problema do Aspirador.
 *
 * Este problema consiste ter salas vizinhas, que podem estar sujas ou limpas. 
 * Pretende-se ter todas as salas limpas, sendo as ações de mover para a sala do lado, ou aspirar. 
 */
class CAspirador :
	public TProcuraConstrutiva
{
public:
	CAspirador(void);
	~CAspirador(void);

	// estrutura de dados (números a colocar, números colocados em cada lado, e total de cada lado)
	TVector<char> salas;
	int aspirador; // posição do aspirador

	// Metodos virtuais redefinidos
	TProcuraConstrutiva* Duplicar(void);
	void Copiar(TProcuraConstrutiva*objecto) {
		aspirador = ((CAspirador*)objecto)->aspirador;
		salas = ((CAspirador*)objecto)->salas;
	}
	void SolucaoVazia(void);
	void Sucessores(TVector<TNo>& sucessores);
	bool SolucaoCompleta(void);
	void Debug(void);
	const char* Acao(TProcuraConstrutiva* sucessor);
	void TesteManual(const char* nome);
	bool Distinto(TNo estado);
	void Codifica(uint64_t estado[OBJETO_HASHTABLE]);
	int Heuristica(void);
};

/* Testes nas procuras cegas (instâncias 2 a 10)

 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------| resolvidas
Total  1 |       72 |   18771257 |  54577352 |          0 |  22,708s |   8
Total  2 |       72 |   24694811 |  71755670 |          0 |  13,330s |   8
Total  3 |       91 |      51377 |     71308 |          0 |   0,036s |   9
Total  4 |       91 |      21104 |     26778 |          0 |   0,489s |   9
Total  5 |      189 |        260 |       347 |          0 |   0,000s |   9
Total  6 |       91 |       3019 |      3432 |          0 |   0,002s |   9
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|-06-|
 1    |  2 | -4 | -4 |  7 | -4 | -3
 |----|----|----|----|----|----|
 2 -2 |    | -4 | -4 |  7 | -4 | -7
 |----|----|----|----|----|----|
 3  4 |  4 |    |  0 |  9 |  0 | 17
 |----|----|----|----|----|----|
 4  4 |  4 |  0 |    |  9 |  0 | 17
 |----|----|----|----|----|----|
 5 -7 | -7 | -9 | -9 |    | -9 |-41
 |----|----|----|----|----|----|
 6  4 |  4 |  0 |  0 |  9 |    | 17
 |----|----|----|----|----|----|
Configuração 1
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 2
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 3
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ascendentes | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 4
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): gerados | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 5
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): -1 | P7(Repetidos): gerados | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 6
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): gerados | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0

*/