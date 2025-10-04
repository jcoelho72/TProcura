// teste.cpp : programa para teste da classe TProcuraConstrutiva 
//

#include <stdio.h>

#include "../TProcuraAdversa.h"
#include "JogoDoGalo.h"
#include "JogoEmLinha.h"

int main(int argc, char* argv[])
{
	compat::init_io();

#ifndef MPI_ATIVO
	printf("\n\
Teste TProcuraAdversa\nProblema:\n\
  1 - Jogo do Galo\n\
  2 - Jogo Em Linha\n\
Opção: ");
	int caso = TProcura::NovoValor("");
#else
	// não utilizar o stdin em programas MPI
	if (argc < 2) {
		printf("Utilizar o primeiro argumento para identificar o problema:\n\
Teste TProcuraAdversa\nProblema:\n\
  1 - Jogo do Galo\n\
  2 - Jogo Em Linha");
		return 1;
	}
	int caso = atoi(argv[1]);
	argc--;
	argv++;
#endif

	switch (caso) {
	case 1:	CJogoDoGalo().main(argc, argv, "Jogo do Galo"); break;
	case 2:	CJogoEmLinha().main(argc, argv, "Jogo Em Linha"); break;
	default: printf("Problema não implementado.");
	}
}
