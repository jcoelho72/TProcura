// teste.cpp : programa para teste da classe TProcura
//

#include <stdio.h>
#include <locale>

#include "../TProcura.h"
#include "CTesteTVector.h"

int main(int argc, char* argv[])
{
	std::locale::global(std::locale(""));
	CTesteTVector().main(argc, argv, "TVector");
}
