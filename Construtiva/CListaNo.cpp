#include "CListaNo.h"

CListaNo::~CListaNo() {
	// não libertar o primeiro elemento
	for (int i = 1; i < indice.Count(); i++)
		if (indice[i].estado != NULL)
			delete indice[i].estado;
}

// retorna o índice onde foi inserido
int CListaNo::NovoElemento(TNo elemento) {
	int id = -1;
	if (limite == 0 || indice.Count() < 2 * limite) {
		// adicionar, há espaço
		indice.Add({ elemento, 1, 1 });
		id = indice.Count() - 1;
	}
	else {
		// limite de estados atingido, gerar o espaço
		if (livre.Count() == 0)
			// não há livres, libertar metade
			LibertarLista();

		// utilizar o primeiro livre
		indice[id = livre.Pop()] = { elemento, 1, 1 };
	}
	return id;
}

void CListaNo::LibertarLista() {
	bool jaProcessados = false; // libertar primeiro estados já processados (anteriores a atual)
	// parar assim que existam "limite" estados livres
	completa = false;
	while (livre.Count() < limite) {
		if (!jaProcessados) {
			jaProcessados = true;
			// apagar elementos após o estado inicial
			while (livre.Count() < limite && Proximo(0) != atual)
				LibertarSeguinte(0);
		}
		else {
			int anteriorID = -1, piorID = -1;
			for (int i = atual; ProximoDistinto(i) != 1; i = ProximoDistinto(i)) {
				piorID = ProximoDistinto(i);
				anteriorID = i;
			}
			if (piorID < 0) {
				// valores todos iguais após atual, apagar o seguinte ao atual
				while (livre.Count() < limite)
					LibertarSeguinte(atual);
			}
			else {
				// começar por libertar todos após o primeiro elemento com o pior ID
				while (livre.Count() < limite && Proximo(piorID) != 1)
					LibertarSeguinte(piorID);
				if (livre.Count() < limite) {
					// tem de se eliminar o primeiro elemento com o pior valor
					// o que implica atualizar o proxDistinto de todos os anteriores
					while (Proximo(anteriorID) != piorID) {
						indice[anteriorID].proxDistinto = 1; // último elemento
						anteriorID = Proximo(anteriorID);
					}
					LibertarSeguinte(anteriorID);
				}
				// tudo liberto com este valor, se ainda não é suficiente, seguir para o próximo
			}
		}
	}
}

void CListaNo::LibertarSeguinte(int id) {
	int i = Proximo(id);
	livre.Push(i);
	if (indice[i].estado != NULL) {
		delete indice[i].estado;
		indice[i].estado = NULL;
	}
	indice[id].prox = indice[i].prox;
	indice[id].proxDistinto = indice[i].proxDistinto;
}

// insere por ordem de LB
int CListaNo::Inserir(TNo elemento, int id) {
	int valor, valorI;
	int idNovo = NovoElemento(elemento);
	if (idNovo == 0) {
		// primeiro elemento, inserir um elemento final
		indice.Add({ NULL,-1,-1 });
		return 0;
	}
	valor = Valor(idNovo);
	// atualizar índice
	for (int i = id, j = -1; i >= 0; i = ProximoDistinto(i)) {
		valorI = Valor(i);
		if (valorI == valor) {
			// inserir logo a seguir, já que assim nada mais altera
			indice[idNovo].prox = Proximo(i);
			indice[idNovo].proxDistinto = ProximoDistinto(i);
			indice[i].prox = idNovo;
			return i;
		}
		else if (valorI < valor)
			j = i; // mantem o primeiro elemento anterior
		else { // valor atual já é superior, valor novo
			if (j < 0) {
				// heurística não consistente, 
				// e agora está a gerar um estado com menor valor que o pai
				// i, novo, i.prox, ...
				// o i fica com o próximo distinto em novo, o que não é verdade mas mais vale assim
				indice[idNovo].prox = Proximo(i);
				indice[idNovo].proxDistinto = Proximo(i);
				indice[i].prox = idNovo;
				indice[i].proxDistinto = idNovo;
				return idNovo;
			}
			else {
				// utilizar o índice de j, anterior, colocando antes de i
				// j, ... , novo, i
				// atualizar o proxDistinto de j, passa a novo
				indice[idNovo].prox = i;
				indice[idNovo].proxDistinto = i;
				while (j != idNovo) {
					indice[j].proxDistinto = idNovo;
					if (Proximo(j) == i || Proximo(j) == j)
						indice[j].prox = idNovo;
					j = Proximo(j);
				}
				return idNovo;
			}
		}
	}
	return 0;
}

// inserir todos os elementos por ordem
void CListaNo::Inserir(TVector<TNo>& elementos) {
	TVector<int> lbElementos, idElementos;
	int id = atual;

	// 1. Ordenar elementos, complexidaded O(N log(N))
	for (int j = 0; j < elementos.Count(); j++)
		lbElementos.Add(elementos[j]->LowerBound());
	lbElementos.Sort(&idElementos);

	// 2. inserir por ordem, tirando partido do local onde já está o último elemento
	for (int j = 0; j < idElementos.Count(); j++)
		id = Inserir(elementos[idElementos[j]], id);

}
