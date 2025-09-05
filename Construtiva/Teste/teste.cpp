// teste.cpp : programa para teste da classe TProcuraConstrutiva
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
	std::locale::global(std::locale(""));

	printf("\nTeste TProcuraConstrutiva\nProblema:\n\
  1 - Aspirador\n  2 - Puzzle 8\n  3 - 8 Damas\n  4 - Partição\n  5 - Artificial\nOpção: ");
	switch (TProcura::NovoValor("")) {
	case 1:	CAspirador().main(argc, argv, "Aspirador"); break;
	case 2:	CPuzzle8().main(argc, argv, "Puzzle 8"); break;
	case 3:	COitoDamas().main(argc, argv, "8 Damas"); break;
	case 4:	CParticao().main(argc, argv, "Partição"); break;
	case 5:	CProblemaArtificial().main(argc, argv, "Artificial"); break;
	default: printf("Problema não implementado.");
	}
}
