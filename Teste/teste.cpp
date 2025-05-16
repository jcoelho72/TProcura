﻿// teste.cpp : programa para teste da classe TProcuraConstrutiva
//

#include <stdio.h>
#include <locale>

#include "../TProcuraConstrutiva.h"
#include "ProblemaArtificial.h"
#include "Aspirador.h"
#include "OitoDamas.h"
#include "Particao.h"
#include "Puzzle8.h"

int main(int argc, char* argv[])
{
	CAspirador aspirador;
	CPuzzle8 puzzle8;
	COitoDamas damas;
	CParticao particao;
	CProblemaArtificial artificial;

	std::locale::global(std::locale(""));

	printf("\nTeste TProcurasConstrutivas\nProblema:\n\
  1 - Aspirador\n  2 - Puzzle 8\n  3 - 8 Damas\n  4 - Partição\n  5 - Artificial\nOpção: ");
	switch(TProcuraConstrutiva::NovoValor("")) {
	case 1:	aspirador.TesteManual("Aspirador"); break;
	case 2:	puzzle8.TesteManual("Puzzle 8"); break;
	case 3:	damas.TesteManual("8 Damas"); break;
	case 4:	particao.TesteManual("Partição"); break;
	case 5:	artificial.TesteManual("Artificial"); break;
	default: printf("Problema não implementado.");
	} 
}
