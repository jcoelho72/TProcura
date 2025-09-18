#include "TCodificacaoPermutacao.h"

int TCodificacaoPermutacao::nElementos = 0; // número de elementos na permutação

void TCodificacaoPermutacao::Copiar(TPonto objecto) {
	TCodificacaoPermutacao& obj = *((TCodificacaoPermutacao*)objecto);
	estado = obj.estado;
}

void TCodificacaoPermutacao::NovaSolucao(void) {
	estado.Count(nElementos);
	for (int i = 0; i < nElementos; i++)
		estado[i] = i;
	estado.RandomOrder();
	custo = -1;
}

void TCodificacaoPermutacao::Debug(void) {
	for (int i = 0; i < nElementos; i++)
		printf("%d ", estado[i]);
}

void TCodificacaoPermutacao::ResetParametros() {
	static const char* nomesVizinhanca[] = {
		"inserir",
		"trocaPar",
		"inverterSegmento" };
	static const char* nomesCruzamento[] = {
		"PMX",
		"Edge",
		"Order",
		"Cycle"};
	static const char* nomesDistancias[] = {
		"Hamming", // número de posições com valores diferentes
		"Kendall tau", // número de pares fora de ordem
		"Spearman footrule" }; // soma das diferenças absolutas das posições

	TProcuraMelhorativa::ResetParametros();
	// parametros da codificação inteira
	parametro += { "tCruzamento", 3,1,4,
		"Cruzamento: 1 - PMX, 2 - Edge, 3 - Order; 4 - Cycle", nomesCruzamento };
	parametro += { "tMutação", 0,0,0,
		"Mutação: 0 - aplica um vizinho aleatório (seja 1 só elemento ou segmento)", NULL };
	parametro += { "tVizinhanca", 1,1,3,
		"Vizinhança: vários métodso para vizinhanças de inteiros", nomesVizinhanca };
	parametro += { "LimiteViz", 0,0,1000,
		"LimiteVizinhança, conforme a vizinhança, se 0 não há limite\n\
- inserir + trocaPar + inverterSegmento - limita a distância entre pares", NULL };
	parametro += { "tDistância", 1,1,3,
		"Distância: vários métodso para distâncias de permutações", nomesDistancias };

}

void TCodificacaoPermutacao::Cruzamento(TPonto a, TPonto b) {
	int operador = Parametro(cruzamentoCP);
	TVector<int> divisoes;
	auto& A = ((TCodificacaoPermutacao*)a)->estado;
	auto& B = ((TCodificacaoPermutacao*)b)->estado; 

	estado.Reset(-1);

	// vetor de marcação (usado/copied) disponível para todos os operadores
	TVector<bool> usado;
	usado.Count(nElementos);
	usado.Reset(false);

	// escolher dois pontos de corte distintos
	while (divisoes.Count() < 2) {
		divisoes += (TRand::rand() % nElementos);
		divisoes.BeASet();
	}

	int inicio = divisoes.First();
	int fim = divisoes.Last();

	if (operador == 1) { // PMX
		// mapeamento valor -> posição em B
		TVector<int> posB;
		posB.Count(nElementos);
		for (int i = 0; i < nElementos; i++)
			posB[B[i]] = i;

		// copiar segmento de A
		for (int i = inicio; i <= fim; i++) {
			estado[i] = A[i];
			usado[A[i]] = true;
		}

		// tratar elementos de B no segmento que não foram copiados
		for (int i = inicio; i <= fim; i++) {
			int val = B[i];
			if (!usado[val]) {
				int pos = i;
				while (true) {
					int novoValor = A[pos];
					int novaPos = posB[novoValor];
					if (estado[novaPos] < 0) {
						estado[novaPos] = val;
						usado[val] = true;
						break;
					}
					if (pos == novaPos) {
						if (estado[pos] < 0) {
							estado[pos] = val;
							usado[val] = true;
						}
						break;
					}
					pos = novaPos;
				}
			}
		}

		// preencher restantes posições com elementos de B
		for (int i = 0; i < nElementos; i++)
			if (estado[i] < 0)
				estado[i] = B[i];
	}
	else if (operador == 2) { // ERX
		TVector<TVector<int>> adj;
		adj.Count(nElementos);

		auto addEdge = [&](int from, int to) {
			if (adj[from].Find(to) < 0)
				adj[from] += to;
			};

		// adicionar arestas de A
		for (int i = 0; i < nElementos; i++) {
			int left = A[(i - 1 + nElementos) % nElementos];
			int right = A[(i + 1) % nElementos];
			addEdge(A[i], left);
			addEdge(A[i], right);
		}
		// adicionar arestas de B
		for (int i = 0; i < nElementos; i++) {
			int left = B[(i - 1 + nElementos) % nElementos];
			int right = B[(i + 1) % nElementos];
			addEdge(B[i], left);
			addEdge(B[i], right);
		}

		int current = TRand::rand() % nElementos;
		for (int i = 0; i < nElementos; i++) {
			estado[i] = current;
			usado[current] = true;

			// escolher próximo
			int next = -1;
			if (adj[current].Count() > 0) {
				int minSize = nElementos + 1;
				TVector<int> candidatos;
				for (int v : adj[current]) {
					if (!usado[v]) {
						int size = adj[v].Count();
						if (size < minSize) {
							minSize = size;
							candidatos = {}; 
							candidatos += v;
						}
						else if (size == minSize) {
							candidatos += v;
						}
					}
				}
				if (candidatos.Count() > 0)
					next = candidatos[TRand::rand() % candidatos.Count()];
			}

			if (next == -1) {
				for (int v = 0; v < nElementos; v++)
					if (!usado[v]) { next = v; break; }
			}

			current = next;
		}
	}
	else if (operador == 3) { // OX
		for (int i = inicio; i <= fim; i++) {
			estado[i] = A[i];
			usado[A[i]] = true;
		}

		int pos = (fim + 1) % nElementos;
		int idxB = (fim + 1) % nElementos;

		while (pos != inicio) {
			int val = B[idxB];
			if (!usado[val]) {
				estado[pos] = val;
				usado[val] = true;
				pos = (pos + 1) % nElementos;
			}
			idxB = (idxB + 1) % nElementos;
		}
	}
	else if (operador == 4) { // CX
		TVector<int> posB;
		posB.Count(nElementos);
		for (int i = 0; i < nElementos; i++)
			posB[B[i]] = i;

		bool fromA = true;
		int start = 0;

		while (true) {
			while (start < nElementos && usado[start])
				start++;
			if (start >= nElementos)
				break;

			int pos = start;
			do {
				estado[pos] = fromA ? A[pos] : B[pos];
				usado[pos] = true;
				int val = fromA ? A[pos] : B[pos];
				pos = posB[val];
			} while (pos != start);

			fromA = !fromA;
		}
	}
}


void TCodificacaoPermutacao::Vizinhanca(TVector<TPonto>& vizinhos) {
	// inverter segmento de N bits
	ETiposVizinhancaPermutacao tipo = (ETiposVizinhancaPermutacao)Parametro(vizinhancaCP);
	int limiteVizinhanca = Parametro(limiteVizinhancaCP);

	// alterar posição de elementos
	for (int i = 0; i < nElementos; i++) // elemento i
		for (int j = 0; j < nElementos; j++) // elemento j ou local j
			if (i != j && (!limiteVizinhanca || abs(i - j) <= limiteVizinhanca)) {
				TCodificacaoPermutacao* vizinho = (TCodificacaoPermutacao*)Duplicar();
				if (vizinho != NULL) {
					if (tipo == vizInserirCP) {
						int valor = vizinho->estado[i];
						for (int k = i; k != j; (i < j ? k++ : k--)) 
							vizinho->estado[k] = vizinho->estado[i < j ? k + 1 : k - 1];
						vizinho->estado[j] = valor;
					}
					else if (tipo == vizTrocaParCP && i < j) { // trocaPar
						int valor = vizinho->estado[i];
						vizinho->estado[i] = vizinho->estado[j];
						vizinho->estado[j] = valor;
					}
					else if (tipo == vizInverterSegmentoCP && i < j) { // inverterSegmento
						int ii = i, jj = j;
						while (ii < jj) {
							int valor = vizinho->estado[ii];
							vizinho->estado[ii] = vizinho->estado[jj];
							vizinho->estado[jj] = valor;
							ii++;
							jj--;
						}
					}

					vizinho->custo = -1;
					vizinhos += vizinho;
				}
				else
					memoriaEsgotada = true;
			}
	TProcuraMelhorativa::Vizinhanca(vizinhos);
}

void TCodificacaoPermutacao::Mutar(void) {
	// mutação com probabilidade p de trocar cada bit
	int p = Parametro(mutacaoCP);
	int limiteVizinhanca = Parametro(limiteVizinhancaCP);
	if (p == 0) {
		// um vizinho aleatório
		ETiposVizinhancaPermutacao tipo = (ETiposVizinhancaPermutacao)Parametro(vizinhancaCP);
		int i = TRand::rand() % nElementos;
		int j = TRand::rand() % nElementos;
		if (tipo == vizInserirCP) {
			int valor = estado[i];
			for (int k = i; k != j; (i < j ? k++ : k--))
				estado[k] = estado[i < j ? k + 1 : k - 1];
			estado[j] = valor;
		}
		else if (tipo == vizTrocaParCP) {
			int valor = estado[i];
			estado[i] = estado[j];
			estado[j] = valor;
		}
		else if (tipo == vizInverterSegmentoCP) {
			while (i < j) {
				int valor = estado[i];
				estado[i] = estado[j];
				estado[j] = valor;
				i++;
				j--;
			}
		}
	}
}

int TCodificacaoPermutacao::Distancia(TPonto a) {
	int dist = 0;
	TCodificacaoPermutacao& obj = *(TCodificacaoPermutacao*)a;
	ETiposDistanciaPermutacao tipo = (ETiposDistanciaPermutacao)Parametro(distanciaCP);
	if (tipo == distKendallTauCP) {
		// número de pares fora de ordem
		for(int i=0; i<nElementos-1; i++)
			for(int j=i+1; j<nElementos; j++)
				if (obj.estado.Find(estado[i]) > obj.estado.Find(estado[j]))
					dist++;
	}
	else if (tipo == distSpearmanFootruleCP) {
		// soma das diferenças absolutas das posições
		for (int i = 0; i < nElementos; i++)
			dist += abs(i - obj.estado.Find(estado[i]));
	}
	else // Hamming
		for (int i = 0; i < nElementos; i++)
			dist += (estado[i] != obj.estado[i]);
	return dist;
}