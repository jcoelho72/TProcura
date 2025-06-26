#include "CTesteTVector.h"
#include <stdio.h>

void CTesteTVector::ResetParametros()
{
	static const char* nomesMetodo[] = {
		"Add()",
		"Sort()",
		"RandomOrder()",
		"Invert()",
		"BeASet()",
		"Difference()",
		"Union()",
		"Contained()",
		"Intersection()",
		"operator=()",
		"operator+=()",
		"nada"
	};

	TProcura::ResetParametros();

	parametro[algoritmo] = { "Método",1,1,12,"Método para teste.", nomesMetodo };

	instancia = { "Dados", 1,1,10, "Vetores aleatórios de K milhões", NULL };

}

void CTesteTVector::Inicializar(void)
{
	dadosA.Count(instancia.valor * 1000000);
	dadosB.Count(instancia.valor * 1000000);
	for (int i = 0; i < instancia.valor * 1000000; i++) {
		dadosA[i] = TRand::rand();
		dadosB[i] = TRand::rand();
	}
}

void CTesteTVector::Debug(void)
{
	if (dadosA.Count() > 10) {
		printf("\nVetor A (#%d): ", dadosA.Count());
		for (int i = 0; i < 4 && i < dadosA.Count(); i++)
			printf("%d ", dadosA[i]);
		printf("... ");
		for (int i = dadosA.Count() - 4; i < dadosA.Count(); i++)
			printf("%d ", dadosA[i]);
	}
	if (dadosB.Count() > 10) {
		printf("\nVetor B (#%d): ", dadosB.Count());
		for (int i = 0; i < 4 && i < dadosB.Count(); i++)
			printf("%d ", dadosB[i]);
		printf("... ");
		for (int i = dadosB.Count() - 4; i < dadosB.Count(); i++)
			printf("%d ", dadosB[i]);
	}
}

int CTesteTVector::ExecutaAlgoritmo()
{
	while (!Parar()) {
		if (iteracoes > 0)
			Inicializar();
		switch (parametro[algoritmo].valor) {
		case 1: // add
			dadosA.Count(0);
			for (int i = 0; i < instancia.valor * 1000000; i++)
				dadosA.Add(TRand::rand());
			break;
		case 2: // Sort
			dadosA.Sort();
			break;
		case 3: // RandomOrder
			dadosA.RandomOrder();
			break;
		case 4: // Invert
			dadosA.Invert();
			break;
		case 5: // BeASet
			dadosA.BeASet();
			break;
		case 6: // Difference
			dadosA.BeASet();
			dadosB.BeASet();
			dadosA.Difference(dadosB);
			break;
		case 7: // Union
			dadosA.BeASet();
			dadosB.BeASet();
			dadosA.Union(dadosB);
			break;
		case 8: // Contained
			dadosA.BeASet();
			dadosB.BeASet();
			dadosA.Contained(dadosB);
			break;
		case 9: // Intersection
			dadosA.BeASet();
			dadosB.BeASet();
			dadosA.Intersection(dadosB);
			break;
		case 10: // operator=()
			dadosA = dadosB;
			break;
		case 11: // operator+=()
			dadosA += dadosB;
			break;
		case 12: // nada
			break;
		}
		iteracoes++;
		// se não foi definido limite de iterações, fazer apenas uma
		if (parametro[limiteIteracoes].valor == 0)
			break;
	}
	return 1;
}
