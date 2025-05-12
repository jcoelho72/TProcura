// teste.cpp : programa para teste da classe TProcuraConstrutiva
//

#include <stdio.h>
#include <locale>

#include "..\TProcuraConstrutiva.h"
#include "ProblemaArtificial.h"

int main(int argc, char* argv[])
{
	CProblemaArtificial problema;

	std::locale::global(std::locale(""));

	problema.TesteManual("Problema artificial");
}
