// teste.cpp : programa para teste da classe TProcuraConstrutiva
//

#include <stdio.h>
#include <locale>

#include "../TProcuraAdversa.h"
#include "JogoDoGalo.h"
#include "JogoEmLinha.h"

int main(int argc, char* argv[])
{
	std::locale::global(std::locale(""));

	printf("\n\
Teste TProcuraAdversa\nProblema:\n\
  1 - Jogo do Galo\n\
  2 - Jogo Em Linha\n\
Opção: ");
	switch (TProcuraConstrutiva::NovoValor("")) {
	case 1:	CJogoDoGalo().main(argc, argv, "Jogo do Galo"); break;
	case 2:	CJogoEmLinha().main(argc, argv, "Jogo Em Linha"); break;
	default: printf("Problema não implementado.");
	}
}
