#include "CTesteTVector.h"
#include <stdio.h>
#include <algorithm>
#include <random>
#include <iterator>

static std::mt19937_64 rng{ std::random_device{}() };

enum EParametrosVector {
	estruturaDados = parametrosProcura         ///< estrutura base a utilizar
};

enum EIndicadoresVector {
	indOrdenar = indProcura, ///< verifica se está ordenado
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
			"std::vector"
	};

	TProcura::ResetParametros();

	parametro[algoritmo] = { "Método",1,1,12,"Método para teste.", nomesMetodo };

	// estrutura de dados
	parametro.Add({ "Estrutura",1,1,2,"Estrutura de dados utilizada para vetor.",nomesEstrutura });

	indicador.Add({ "Ordenado","verifica se o indicador está ordenado", indOrdenar });
	indAtivo.Add(indOrdenar);

	instancia = { "Dados", 1,1,10, "Vetores aleatórios de K milhões", NULL };

}

void CTesteTVector::Inicializar(void)
{
	int tamanho = instancia.valor * 1000000;
	if (parametro[estruturaDados].valor == 0) { // TVector
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
	if (parametro[algoritmo].valor == 0) {
		if(dadosA.Count()<6)
			return;
		printf("\nDados #%d: ", dadosA.Count());
		for(int i=0;i<3;i++)
			printf("%d ",dadosA[i]);
		printf("... ");
		for (int i = dadosA.Count() - 4; i < dadosA.Count(); i++)
			printf("%d ", dadosA[i]);
	}
	else {
		if (stdA.size() < 6)
			return;
		printf("\nDados #%d: ", stdA.size());
		for (int i = 0; i < 3; i++)
			printf("%d ", stdA[i]);
		printf("... ");
		for (int i = stdA.size() - 4; i < stdA.size(); i++)
			printf("%d ", stdA[i]);
	}
}

int CTesteTVector::ExecutaAlgoritmo()
{
	while (!Parar()) {
		if (iteracoes > 0)
			Inicializar();
		if (parametro[estruturaDados].valor == 0) { // TVector
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
		else { // std::vector
			switch (parametro[algoritmo].valor) {
			case 1: // add
				stdA.clear();
				for (int i = 0; i < instancia.valor * 1000000; i++)
					stdA.push_back(TRand::rand());
				break;
			case 2: // Sort
				std::sort(stdA.begin(),stdA.end());
				break;
			case 3: // RandomOrder
				std::shuffle(stdA.begin(), stdA.end(), rng);
				break;
			case 4: // Invert
				std::reverse(stdA.begin(), stdA.end());
				break;
			case 5: // BeASet (sort + unique)
				std::sort(stdA.begin(), stdA.end());
				stdA.erase(
					std::unique(stdA.begin(), stdA.end()),
					stdA.end()
				);
				break;
			case 6: // Difference
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
				break;
			case 7: // Union
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
				break;
			case 8: // Contained
				std::sort(stdA.begin(), stdA.end());
				std::sort(stdB.begin(), stdB.end());
				std::includes(
					stdB.begin(), stdB.end(),
					stdA.begin(), stdA.end()
				);
				break;
			case 9: // Intersection
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
				break;
			case 10: // operator=()
				stdA = stdB;
				break;
			case 11: // operator+=()
				stdA.insert(
					stdA.end(),
					stdB.begin(),
					stdB.end()
				);
				break;
			case 12: // nada
				break;
			}
		}
			
		iteracoes++;
		// se não foi definido limite de iterações, fazer apenas uma
		if (parametro[limiteIteracoes].valor == 0)
			break;
	}
	return 1;
}

int CTesteTVector::Indicador(int id)
{
	if (id == indOrdenar) { // verifica se está ordenado
		if (parametro[estruturaDados].valor == 0) {
			for (int i = 0; i < dadosA.Count() - 1; i++)
				if (dadosA[i] > dadosA[i + 1])
					return 0;
		} else {
			for (int i = 0; i < stdA.size() - 1; i++)
				if (stdA[i] > stdA[i + 1])
					return 0;
		}
		return 1;
	}
	return TProcura::Indicador(id);
}
