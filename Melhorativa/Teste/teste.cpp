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
	COitoDamas damas;
	CParticao particao;
	CProblemaArtificial artificial;

	std::locale::global(std::locale(""));

	printf("\n\
Teste TProcurasConstrutivas\nProblema:\n\
  1 - 8 Damas\n\
  2 - Partição\n\
  3 - Artificial\n\
Opção: ");
	switch (TProcura::NovoValor("")) {
	case 1:	damas.TesteManual("8 Damas"); break;
	case 2:	particao.TesteManual("Partição"); break;
	case 3:	artificial.TesteManual("Artificial"); break;
	default: printf("Problema não implementado.");
	}
}
