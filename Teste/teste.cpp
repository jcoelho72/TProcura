// teste.cpp : programa para teste da classe TProcura
//

#include <stdio.h>
#include <locale>

#include "../TProcura.h"
#include "CTesteTVector.h"

int main(int argc, char* argv[])
{
	CTesteTVector tstVector;

	std::locale::global(std::locale(""));

	printf("\nTeste TProcura\nClasse:\n\
  1 TVector\nOpção: ");
	switch(TProcura::NovoValor("")) {
	case 1:
		tstVector.TesteManual("TVector");
		break;
	default: printf("Classe não implementada.");
	} 
}
