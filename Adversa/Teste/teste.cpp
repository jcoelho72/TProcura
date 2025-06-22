// teste.cpp : programa para teste da classe TProcuraConstrutiva
//

#include <stdio.h>
#include <locale>

#include "../TProcuraAdversa.h"
#include "JogoDoGalo.h"
#include "JogoEmLinha.h"

int main(int argc, char* argv[])
{
	CJogoDoGalo jdg;
	CJogoEmLinha emLinha;


	std::locale::global(std::locale(""));

	printf("\n\
Teste TProcurasAdversas\nProblema:\n\
  1 - Jogo do Galo\n\
  2 - Jogo Em Linha\n\
Opção: ");
	switch (TProcuraConstrutiva::NovoValor("")) {
	case 1:	jdg.TesteManual("Jogo do Galo"); break;
	case 2:	emLinha.TesteManual("Jogo Em Linha"); break;
	default: printf("Problema não implementado.");
	}
}
