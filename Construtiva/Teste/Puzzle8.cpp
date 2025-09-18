#include "Puzzle8.h"
#include <stdio.h>
#include <string.h>

CPuzzle8::CPuzzle8(void) : zero(0)
{
}

CPuzzle8::~CPuzzle8(void)
{
}

TProcuraConstrutiva* CPuzzle8::Duplicar(void)
{
	CPuzzle8* clone = new CPuzzle8;
	if (clone != NULL) 
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

void CPuzzle8::Inicializar(void)
{
	int backup = Parametro(estadosRepetidos);
	TProcuraConstrutiva::Inicializar();
	// colocar a posição final
	puzzle.Count(9);
	for (int i = 0; i < 9; i++)
		puzzle[i] = i;
	zero=0;
	// efectuar trocas ao acaso
	Parametro(estadosRepetidos) = ignorados;
	for (int i = 0; i < instancia.valor; i++) { // utilizar o ID da instância
		TVector<TNo> sucessores;
		Sucessores(sucessores);
		TNo filho = sucessores.Random();
		puzzle = ((CPuzzle8*)filho)->puzzle;
		zero = ((CPuzzle8*)filho)->zero;
		LibertarVector(sucessores);
	}
	Parametro(estadosRepetidos) = backup;
	tamanhoCodificado = 1; // apenas um inteiro de 64 bits é suficiente para 4*9 bits
}

void CPuzzle8::Sucessores(TVector<TNo>&sucessores)
{
	static int direcao[] = { -3,3,-1,1 }; // subir, baixar, esquerda, direita

	for (int i = 0; i < 4; i++) {
		int novaCasa = zero + direcao[i];
		if (novaCasa >= 0 && novaCasa < 9 && // dentro do tabuleiro
			(zero / 3 == novaCasa / 3 || zero % 3 == novaCasa % 3)) // muda apenas na horizontal ou na vertical
		{
			CPuzzle8* sucessor = (CPuzzle8*)Duplicar();
			if (memoriaEsgotada)
				return;
			sucessor->Trocar(zero, novaCasa);
			sucessores += sucessor;
		}
	}
	TProcuraConstrutiva::Sucessores(sucessores);
}

bool CPuzzle8::SolucaoCompleta(void)
{
	for (int i = 0; i < 9; i++)
		if (puzzle[i] != i)
			return false;
	return true;
}

int CPuzzle8::Heuristica(void)
{
	int resultado = 0;
	TProcuraConstrutiva::Heuristica();

	// distância de manhatan de cada posição à sua possição final
	for (int i = 1; i < 9; i++) {
		int posicaoI = 0;
		while (puzzle[posicaoI] != i)
			posicaoI++;
		resultado += abs(posicaoI % 3 - i % 3) + abs(posicaoI / 3 - i / 3);
	}

	return resultado;
}

const char* CPuzzle8::Acao(TProcuraConstrutiva* sucessor) {
	CPuzzle8* suc = (CPuzzle8*)sucessor;
	if (zero == suc->zero - 1)
		return "esq";
	if (zero == suc->zero + 1)
		return "dir";
	if (zero == suc->zero - 3)
		return "cima";
	if (zero == suc->zero + 3)
		return "baixo";
	return "Inv";
}

void CPuzzle8::Debug(void)
{
	for (int i = 0; i < 3; i++) {
		NovaLinha();
		for (int j = 0; j < 3; j++)
			if (puzzle[i * 3 + j] == 0)
				printf(" . ");
			else 
				printf(" %d ", puzzle[i * 3 + j]);
	}
}

void CPuzzle8::MostrarSolucao(void) {
	TVector<int> contador;
	CPuzzle8* atual, *arranque;
	contador.Count(9);
	contador.Reset(0);
	arranque = (CPuzzle8*)caminho.First();
	for (int i = 0, passos = 0, parte = 1; i < caminho.Count(); i++, passos++) {
		atual = (CPuzzle8*)caminho[i];
		contador[atual->zero]++;
		// reportar uma parte, e iniciar outra
		if (i == caminho.Count()-1 ||
			contador[((CPuzzle8*)caminho[i + 1])->zero] > 0 ||
			i<caminho.Count()-2 && contador[((CPuzzle8*)caminho[i + 2])->zero] > 0)
		{
			printf("\nParte %d, ações:", parte);
			// mostrar ações
			for (int j = i - passos; j < i; j++)
				printf(" %s", caminho[j]->Acao(caminho[j + 1]));

			for (int i = 0; i < 3; i++) {
				printf("\n");
				for (int j = 0; j < 3; j++)
					if (contador[i * 3 + j]) {
						if (arranque->puzzle[i * 3 + j] == 0)
							printf(" . "); // não marcar o próprio zero
						else
							printf("(%d)", arranque->puzzle[i * 3 + j]);
					}
					else {
						if (arranque->puzzle[i * 3 + j] == 0)
							printf(" . ");
						else
							printf(" %d ", arranque->puzzle[i * 3 + j]);
					}
			}

			arranque = atual;
			contador.Reset(0);
			contador[atual->zero]++;
			passos = 0;
			parte++;
		}
	}
}


void CPuzzle8::ResetParametros() {
	TProcuraConstrutiva::ResetParametros();
	// opções de omissão:
	Parametro(estadosRepetidos) = ascendentes;
	// instâncias
	instancia = { NULL, 40,1,1000, NULL, NULL };
}


bool CPuzzle8::Distinto(TProcuraConstrutiva *estado)
{
	CPuzzle8* outro = (CPuzzle8*)estado;
	if (zero != outro->zero)
		return true;
	for (int i = 0; i < 9; i++)
		if (puzzle[i] != outro->puzzle[i])
			return true;
	return false;
}

void CPuzzle8::Codifica(uint64_t estado[OBJETO_HASHTABLE]) 
{
	TProcuraConstrutiva::Codifica(estado);
	// não há simetrias, simplesmente codificar números de 4 bits (0 a 8)
	for (int i = 0, index = 0; i < 9; i++, index += 4)
		estado[index >> 6] |= (uint64_t)puzzle[i] << (index & 63);
}
