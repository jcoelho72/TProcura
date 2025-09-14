// ProcuraEngine.cpp : Defines the entry point for the console application.
//

#include <stdio.h>
#include <locale>

#include "../TProcuraMelhorativa.h"
#include "OitoDamas.h"
#include "Particao.h"
#include "ProblemaArtificial.h"

int main(int argc, char* argv[])
{
	std::locale::global(std::locale(""));

	printf("\n\
Teste TProcuraMelhorativa\nProblema:\n\
  1 - 8 Damas\n\
  2 - 8 Damas Inteira\n\
  3 - 8 Damas Permutacao\n\
  4 - Partição\n\
  5 - Partição Binária\n\
  6 - Artificial\n\
Opção: ");
	switch (TProcura::NovoValor("")) {
	case 1:	COitoDamas().main(argc, argv, "8 Damas"); break;
	case 2:	COitoDamasCI().main(argc, argv, "8 Damas Inteira"); break;
	case 3:	COitoDamasCP().main(argc, argv, "8 Damas Permutação"); break;
	case 4:	CParticao().main(argc, argv, "Partição"); break;
	case 5: CParticaoCB().main(argc, argv, "Partição Binária"); break;
	case 6:	CProblemaArtificial().main(argc, argv, "Artificial"); break;
	default: printf("Problema não implementado.");
	}
}
