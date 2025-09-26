#pragma once
#include "../TProcuraConstrutiva.h"

/**
 * @brief Representa um estado do puzzle 8
 * 
 * Este problema consiste em mover numa quadricula de 3x3
 * oito peças, em que os movimentos permitidos é mover uma peça para a 
 * posição vazia. Pretende-se de uma posição inicial atingir a posição final. 
 */
class CPuzzle8 :
	public TProcuraConstrutiva
{
public:
	CPuzzle8(void);
	~CPuzzle8(void);

	// puzzle-8, posição de cada número
	TVector<int> puzzle; 
	// posição do zero (espaço vazio)
	int zero; 

	// Métodos virtuais redefinidos
	TProcuraConstrutiva* Duplicar(void);
	void Copiar(TProcuraConstrutiva*objecto) {  
		puzzle = ((CPuzzle8*)objecto)->puzzle;
		zero = ((CPuzzle8*)objecto)->zero;
	}
	void Inicializar(void);
	void Sucessores(TVector<TNo>&sucessores);
	bool SolucaoCompleta(void);	
	void Debug(bool completo = true) override;
	void MostrarSolucao(void);
	const char* Acao(TProcuraConstrutiva* sucessor);
	void ResetParametros();

	int Heuristica(void);

	bool Distinto(TProcuraConstrutiva* estado);
	void Codifica(uint64_t estado[OBJETO_HASHTABLE]);

private:
	void Trocar(int a, int b) {
		if (puzzle[a] == 0) {
			puzzle[a] = puzzle[b];
			puzzle[b] = 0;
			zero = b;
		}
		else {
			puzzle[a] = puzzle[b];
			puzzle[b] = 0;
			zero = b;
		}
	}
};

/* Testes nas procuras cegas (instâncias 40 a 49)

 ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |
----|----|----------|------------|-----------|------------|----------|
Total  1 |      135 |      37353 |     63602 |          0 |   0,046s |  10
Total  2 |      135 |   10479715 |  29654461 |          0 |  12,209s |  10
Total  3 |      135 |   16213162 |  45867646 |          0 |  12,987s |  10
Total  4 |      135 |      87998 |    151568 |          0 |   0,079s |  10
Total  5 |      135 |      71137 |    116772 |          0 |   0,931s |  10
Torneio (#instâncias melhores):
 |-01-|-02-|-03-|-04-|-05-|
 1    |  8 |  8 |  0 |  4 | 20
 |----|----|----|----|----|
 2 -8 |    |  4 | -8 | -7 |-19
 |----|----|----|----|----|
 3 -8 | -4 |    | -8 | -8 |-28
 |----|----|----|----|----|
 4  0 |  8 |  8 |    |  3 | 19
 |----|----|----|----|----|
 5 -4 |  7 |  8 | -3 |    |  8
 |----|----|----|----|----|
Configuração 1
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ascendentes | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 2
P1(Algoritmo): Largura Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 3
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ignorar | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 4
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): ascendentes | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0
Configuração 5
P1(Algoritmo): Profundidade Primeiro | P2(Debug): nada | P3(Ver): 4 | P4(Seed): 1
P5(Tempo): 10 | P6(Limite): 0 | P7(Repetidos): gerados | P8(pesoAStar): 100
P9(ruido): 0 | P10(baralhar): 0

*/
