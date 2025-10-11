// ProcuraEngine.cpp : Defines the entry point for the console application.
//

#include <stdio.h>

#include "../TProcuraMelhorativa.h"
#include "OitoDamas.h"
#include "Particao.h"
#include "ProblemaArtificial.h"

int main(int argc, char* argv[])
{
	compat::init_io();

#ifndef MPI_ATIVO
	TProcura::MostraCaixa({
		"Teste TProcuraMelhorativa",
		"1 - 8 Damas (Inteira)",
		"2 - 8 Damas (Permutacao)",
		"3 - Partição (Binária)"
		}, 30, false);
	int caso = TProcura::NovoValor("\nOpção: ");

#else
	// não utilizar o stdin em programas MPI
	if (argc < 2) {
		printf("Utilizar o primeiro argumento para identificar o problema:\n\
Teste TProcuraMelhorativa\nProblema:\n\
  1 - 8 Damas\n\
  2 - 8 Damas Inteira\n\
  3 - 8 Damas Permutacao\n\
  4 - Partição\n\
  5 - Partição Binária\n\
  6 - Artificia");
		return 1;
	}
	int caso = atoi(argv[1]);
	argc--;
	argv++;
#endif


	switch (caso) {
	case 1:	COitoDamasCI().main(argc, argv, "8 Damas (Inteira)"); break;
	case 2:	COitoDamasCP().main(argc, argv, "8 Damas (Permutação)"); break;
	case 3: CParticaoCB().main(argc, argv, "Partição (Binária)"); break;
	default: printf("Problema não implementado.");
	}

}
