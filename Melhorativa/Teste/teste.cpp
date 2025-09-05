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
  2 - Partição\n\
  3 - Artificial\n\
Opção: ");
	switch (TProcura::NovoValor("")) {
	case 1:	COitoDamas().main(argc, argv, "8 Damas"); break;
	case 2:	CParticao().main(argc, argv, "Partição"); break;
	case 3:	CProblemaArtificial().main(argc, argv, "Artificial"); break;
	default: printf("Problema não implementado.");
	}
}
