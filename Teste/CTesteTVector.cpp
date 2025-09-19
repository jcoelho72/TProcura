#include "CTesteTVector.h"
#include <stdio.h>
#include <algorithm>
#include <random>
#include <iterator>

static std::mt19937_64 rng{ std::random_device{}() };

enum EParametrosVector {
	estruturaDados = PARAMETROS_PROCURA         ///< estrutura base a utilizar
};

enum EIndicadoresVector {
	indOrdenar = IND_PROCURA, ///< verifica se está ordenado
};

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
	static const char* nomesEstrutura[] = {
			"TVector",
			"std::vector",
			"TVector/std::algorithm",
	};

	TProcura::ResetParametros();

	parametro[ALGORITMO] = { "Método",1,1,12,"Método para teste.", nomesMetodo };

	// estrutura de dados
	parametro += { "Estrutura",1,1,3,"Estrutura de dados utilizada para vetor.",nomesEstrutura };

	indicador += { "Ordenado","verifica se o indicador está ordenado", indOrdenar };
	indAtivo += indOrdenar;

	instancia = { "Dados", 1,1,10, "Vetores aleatórios de K milhões", NULL };
}

void CTesteTVector::Inicializar(void)
{
	int tamanho = instancia.valor * 1000000;
	if (Parametro(estruturaDados) != 2) { // TVector
		dadosA.Count(tamanho);
		dadosB.Count(tamanho);
		for (int i = 0; i < tamanho; i++) {
			dadosA[i] = TRand::rand();
			dadosB[i] = TRand::rand();
		}
	}
	else { // std::vector
		// define o tamanho e inicializa com zeros (ou itens padrão)
		stdA.resize(tamanho);
		stdB.resize(tamanho);
		for (int i = 0; i < tamanho; i++) {
			stdA[i] = TRand::rand();
			stdB[i] = TRand::rand();
		}
	}
}

void CTesteTVector::Debug(void)
{
	if (Parametro(estruturaDados) != 2) {
		if (dadosA.Count() < 6)
			return;
		printf("\nDados #%d: ", dadosA.Count());
		for (int i = 0; i < 3; i++)
			printf("%d ", dadosA[i]);
		printf("... ");
		for (int i = dadosA.Count() - 3; i < dadosA.Count(); i++)
			printf("%d ", dadosA[i]);
	}
	else {
		if (stdA.size() < 6)
			return;
		printf("\nDados #%d: ", stdA.size());
		for (int i = 0; i < 3; i++)
			printf("%d ", stdA[i]);
		printf("... ");
		for (int i = stdA.size() - 3; i < stdA.size(); i++)
			printf("%d ", stdA[i]);
	}
}

int CTesteTVector::ExecutaAlgoritmo()
{
	while (!Parar()) {
		if (iteracoes > 0)
			Inicializar();
		if (Parametro(estruturaDados) == 1) { // TVector
			switch (Parametro(ALGORITMO)) {
			case 1: // add
				dadosA = {}; 
				for (int i = 0; i < instancia.valor * 1000000; i++)
					dadosA += TRand::rand();
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
				dadosA.BeASet().Difference(dadosB.BeASet());
				break;
			case 7: // Union
				dadosA.BeASet().Union(dadosB.BeASet());
				break;
			case 8: // Contained
				dadosA.BeASet().Contained(dadosB.BeASet());
				break;
			case 9: // Intersection
				dadosA.BeASet().Intersection(dadosB.BeASet());
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
		}
		else { // std::vector ou TVegtor/std::algorithm
			switch (Parametro(ALGORITMO)) {
			case 1: // add
				if (Parametro(estruturaDados) == 2) {
					stdA.clear();
					for (int i = 0; i < instancia.valor * 1000000; i++)
						stdA.push_back(TRand::rand());
				}
				else {
					dadosA = {}; 
					for (int i = 0; i < instancia.valor * 1000000; i++)
						dadosA += TRand::rand();
				}
				break;
			case 2: // Sort
				if (Parametro(estruturaDados) == 2)
					std::sort(stdA.begin(), stdA.end());
				else
					std::sort(dadosA.begin(), dadosA.end());
				break;
			case 3: // RandomOrder
				if (Parametro(estruturaDados) == 2)
					std::shuffle(stdA.begin(), stdA.end(), rng);
				else
					std::shuffle(dadosA.begin(), dadosA.end(), rng);
				break;
			case 4: // Invert
				if (Parametro(estruturaDados) == 2)
					std::reverse(stdA.begin(), stdA.end());
				else
					std::reverse(dadosA.begin(), dadosA.end());
				break;
			case 5: // BeASet (sort + unique)
				if (Parametro(estruturaDados) == 2) {
					std::sort(stdA.begin(), stdA.end());
					stdA.erase(
						std::unique(stdA.begin(), stdA.end()),
						stdA.end()
					);
				}
				else {
					std::sort(dadosA.begin(), dadosA.end());
					dadosA.Count(std::unique(dadosA.begin(), dadosA.end()) - dadosA.begin());
				}
				break;
			case 6: // Difference
				if (Parametro(estruturaDados) == 2) {
					// deixa A e B como sets
					std::sort(stdA.begin(), stdA.end());
					std::sort(stdB.begin(), stdB.end());
					stdA.erase(
						std::unique(stdA.begin(), stdA.end()),
						stdA.end()
					);
					stdB.erase(
						std::unique(stdB.begin(), stdB.end()),
						stdB.end()
					);
					// diferença
					{
						std::vector<int> tmp;
						tmp.reserve(stdA.size());
						std::set_difference(
							stdA.begin(), stdA.end(),
							stdB.begin(), stdB.end(),
							std::back_inserter(tmp)
						);
						stdA.swap(tmp);
					}
				}
				else {
					// deixa A e B como sets
					std::sort(dadosA.begin(), dadosA.end());
					dadosA.Count(std::unique(dadosA.begin(), dadosA.end()) - dadosA.begin());
					std::sort(dadosB.begin(), dadosB.end());
					dadosB.Count(std::unique(dadosB.begin(), dadosB.end()) - dadosB.begin());
					dadosA.Difference(dadosB);
				}
				break;
			case 7: // Union
				if (Parametro(estruturaDados) == 2) {
					std::sort(stdA.begin(), stdA.end());
					std::sort(stdB.begin(), stdB.end());
					stdA.erase(
						std::unique(stdA.begin(), stdA.end()),
						stdA.end()
					);
					stdB.erase(
						std::unique(stdB.begin(), stdB.end()),
						stdB.end()
					);
					{
						std::vector<int> tmp2;
						tmp2.reserve(stdA.size() + stdB.size());
						std::set_union(
							stdA.begin(), stdA.end(),
							stdB.begin(), stdB.end(),
							std::back_inserter(tmp2)
						);
						stdA.swap(tmp2);
					}
				}
				else {
					std::sort(dadosA.begin(), dadosA.end());
					dadosA.Count(std::unique(dadosA.begin(), dadosA.end()) - dadosA.begin());
					std::sort(dadosB.begin(), dadosB.end());
					dadosB.Count(std::unique(dadosB.begin(), dadosB.end()) - dadosB.begin());
					dadosA.Union(dadosB);
				}
				break;
			case 8: // Contained
				if (Parametro(estruturaDados) == 2) {
					std::sort(stdA.begin(), stdA.end());
					std::sort(stdB.begin(), stdB.end());
					std::includes(
						stdB.begin(), stdB.end(),
						stdA.begin(), stdA.end()
					);
				}
				else {
					std::sort(dadosA.begin(), dadosA.end());
					std::sort(dadosB.begin(), dadosB.end());
					std::includes(
						dadosB.begin(), dadosB.end(),
						dadosA.begin(), dadosA.end()
					);
				}
				break;
			case 9: // Intersection
				if (Parametro(estruturaDados) == 2) {
					std::sort(stdA.begin(), stdA.end());
					std::sort(stdB.begin(), stdB.end());
					stdA.erase(
						std::unique(stdA.begin(), stdA.end()),
						stdA.end()
					);
					stdB.erase(
						std::unique(stdB.begin(), stdB.end()),
						stdB.end()
					);
					{
						std::vector<int> tmp3;
						tmp3.reserve(std::min(stdA.size(), stdB.size()));
						std::set_intersection(
							stdA.begin(), stdA.end(),
							stdB.begin(), stdB.end(),
							std::back_inserter(tmp3)
						);
						stdA.swap(tmp3);
					}
				}
				else {
					std::sort(dadosA.begin(), dadosA.end());
					dadosA.Count(std::unique(dadosA.begin(), dadosA.end()) - dadosA.begin());
					std::sort(dadosB.begin(), dadosB.end());
					dadosB.Count(std::unique(dadosB.begin(), dadosB.end()) - dadosB.begin());
					dadosA.Intersection(dadosB);
				}
				break;
			case 10: // operator=()
				if (Parametro(estruturaDados) == 2)
					stdA = stdB;
				else
					dadosA = dadosB;
				break;
			case 11: // operator+=()
				if (Parametro(estruturaDados) == 2) {
					stdA.insert(
						stdA.end(),
						stdB.begin(),
						stdB.end()
					);
				}
				else
					dadosA += dadosB;
				break;
			case 12: // nada
				break;
			}
		}

		iteracoes++;
		// se não foi definido limite de iterações, fazer apenas uma
		if (Parametro(LIMITE_ITERACOES) == 0)
			break;
	}
	return 1;
}

int CTesteTVector::Indicador(int id)
{
	if (id == indOrdenar) { // verifica se está ordenado
		if (Parametro(estruturaDados) != 2) {
			for (int i = 0; i < dadosA.Count() - 1; i++)
				if (dadosA[i] > dadosA[i + 1]) {
					if (Parametro(NIVEL_DEBUG) >= 4)
						printf("\nordem %d > %d (%d,%d)",
							i, i + 1, dadosA[i], dadosA[i + 1]);
					return 0;
				}
		}
		else {
			for (int i = 0; i < stdA.size() - 1; i++)
				if (stdA[i] > stdA[i + 1]) {
					if (Parametro(NIVEL_DEBUG) >= 4)
						printf("\nordem %d > %d (%d,%d)",
							i, i + 1, stdA[i], stdA[i + 1]);
					return 0;
				}
		}
		return 1;
	}
	return TProcura::Indicador(id);
}
