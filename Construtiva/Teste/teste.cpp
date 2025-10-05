// teste.cpp : programa para teste da classe TProcuraConstrutiva 
//

#include <stdio.h>

#include "../TProcuraConstrutiva.h"
#include "ProblemaArtificial.h"
#include "Aspirador.h"
#include "OitoDamas.h"
#include "Particao.h"
#include "Puzzle8.h"

int main(int argc, char* argv[])
{
	compat::init_io();

#ifndef MPI_ATIVO
	TProcura::MostraCaixa({
		"Teste TProcuraConstrutiva",
		"1 - Aspirador",
		"2 - Puzzle 8",
		"3 - 8 Damas",
		"4 - Partição",
		"5 - Artificial"
		}, 30, false);
	int caso = TProcura::NovoValor("\nOpção: ");
#else
	// não utilizar o stdin em programas MPI
	if (argc < 2) {
		printf("Utilizar o primeiro argumento para identificar o problema:\n\
  1 - Aspirador\n  2 - Puzzle 8\n  3 - 8 Damas\n  4 - Partição\n  5 - Artificial");
		return 1;
	}
	int caso = atoi(argv[1]);
	argc--;
	argv++;
#endif

	switch (caso) {
	case 1:	CAspirador().main(argc, argv, "Aspirador"); break;
	case 2:	CPuzzle8().main(argc, argv, "Puzzle 8"); break;
	case 3:	COitoDamas().main(argc, argv, "8 Damas"); break;
	case 4:	CParticao().main(argc, argv, "Partição"); break;
	case 5:	CProblemaArtificial().main(argc, argv, "Artificial"); break;
	default: printf("Problema não implementado.");
	}
}
