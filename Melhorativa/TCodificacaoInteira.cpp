#include "TCodificacaoInteira.h"

int TCodificacaoInteira::nElementos = 0; // número de elementos na permutação
TVector<int> TCodificacaoInteira::maxValor; // valor máximo para cada elemento

void TCodificacaoInteira::Copiar(TPonto objecto) {
	TCodificacaoInteira& obj = *((TCodificacaoInteira*)objecto);
	estado = obj.estado;
}

void TCodificacaoInteira::NovaSolucao(void) {
	estado.Count(nElementos);
	for (int i = 0; i < nElementos; i++)
		estado[i] = TRand::rand() % maxValor[i];
	custo = -1;
}

void TCodificacaoInteira::Debug(void) {
	for (int i = 0; i < nElementos; i++)
		printf("%d ", estado[i]);
}

void TCodificacaoInteira::ResetParametros() {
	static const char* nomesVizinhanca[] = {
		"incDecValor",
		"incDecPot2",
		"trocaValor",
		"inserir",
		"trocaPar",
		"inverterSegmento" };
	static const char* nomesDistancias[] = {
		"Hamming",
		"Euclidiana",
		"Manhattan"};

	TProcuraMelhorativa::ResetParametros();
	// parametros da codificação inteira
	parametro.Add({ "Cruzamento", 1,0,10,
		"Cruzamento: 1 - um ponto, >=2 N-pontos, 0 - uniforme", NULL });
	parametro.Add({ "Mutação", 0,0,100,
		"Mutação: 0 - aplica um vizinho aleatório (seja 1 só elemento ou segmento), 1 a 100, probabilidade de mutação de cada elemento, em percentagem (1 a 100)", NULL });
	parametro.Add({ "Vizinhanca", 1,1,6,
		"Vizinhança: vários métodso para vizinhanças de inteiros", nomesVizinhanca });
	parametro.Add({ "LimiteVizinhança", 0,0,1000,
		"LimiteVizinhança, conforme a vizinhança, se 0 não há limite\n\
- incDecPot2 + trocaValor - limita a diferença máxima de valores\n\
- inserir + trocaPar + inverterSegmento + rodarSegmento + inserirSegmento - limita a distância entre pares", NULL });
	parametro.Add({ "Distância", 1,1,3,
		"Distância: vários métodso para distâncias de inteiros", nomesDistancias });
}

void TCodificacaoInteira::Cruzamento(TPonto a, TPonto b) {
	int pontos = Parametro(cruzamentoCI);
	TVector<int> divisoes;
	if (pontos > nElementos / 2)
		pontos = nElementos / 2;
	while (divisoes.Count() < pontos) {
		divisoes.Add(TRand::rand() % nElementos);
		divisoes.BeASet();
	}
	if (divisoes.Count() == 0) { // cruzamento uniforme
		for (int i = 0; i < nElementos; i++)
			estado[i] = ((TCodificacaoInteira*)(TRand::rand() % 2 == 0 ? a : b))->estado[i];
		custo = -1;
	}
	else { // cruzamento em N pontos
		int i = 0;
		divisoes.Invert();
		do {
			while (i < divisoes.Last()) {
				estado[i] = ((TCodificacaoInteira*)(divisoes.Count() % 2 == 0 ? a : b))->estado[i];
				i++;
			}
			divisoes.Pop();
		} while (divisoes.Count() > 0);
		while (i < nElementos) {
			estado[i] = ((TCodificacaoInteira*)(a))->estado[i];
			i++;
		}
	}

	TProcuraMelhorativa::Cruzamento(a, b);
}


void TCodificacaoInteira::Vizinhanca(TVector<TPonto>& vizinhos) {
	// inverter segmento de N bits
	ETiposVizinhancaInteira tipo = (ETiposVizinhancaInteira)Parametro(vizinhancaCI);
	int limiteVizinhanca = Parametro(limiteVizinhancaCI);

	if (tipo >= vizIncDecValor && tipo <= vizTrocaValor) {
		// alterar valor de um elemento
		for (int i = 0; i < nElementos; i++) {
			int j = 0;
			while (abs(j) <= maxValor[i] && (!limiteVizinhanca || abs(j) <= limiteVizinhanca)) {
				// incrementar j (+1, -1, +2, -2, +4, -4, etc no caso de potências, e incremental c.c.)
				if (j <= 0)
					j = -j + (tipo == vizIncDecPot2 ? (j == 0 ? 1 : -j) : 1);
				else
					j = -j;
				if (tipo == vizIncDecValor && j > 1)
					break; // apenas incrementa/decrementa 1
				if (estado[i] + j < 0 || estado[i] + j >= maxValor[i])
					continue; // valor inválido
				TCodificacaoInteira* vizinho = (TCodificacaoInteira*)Duplicar();
				if (vizinho != NULL) {
					vizinho->estado[i] += j;
					vizinho->custo = -1;
					vizinhos.Add(vizinho);
				}
				else 
					memoriaEsgotada = true;
			}
		}
	}
	else if (tipo >= vizInserir && tipo <= vizInverterSegmento) {
		// alterar posição de elementos
		for (int i = 0; i < nElementos; i++) // elemento i
			for (int j = 0; j < nElementos; j++) // elemento j ou local j
				if (i != j && (!limiteVizinhanca || abs(i - j) <= limiteVizinhanca)) {
					TCodificacaoInteira* vizinho = (TCodificacaoInteira*)Duplicar();
					if (vizinho != NULL) {
						if (tipo == vizInserir) {
							int valor = vizinho->estado[i];
							vizinho->estado.Delete(i);
							vizinho->estado.Insert(j < i ? j : j - 1, valor);
							if (maxValor[i] != maxValor[j]) {
								// garantir que os valores estão dentro dos limites
								for (int k = (i < j ? i : j); k < (i < j ? j : i); k++)
									vizinho->estado[k] %= maxValor[k];
							}
						}
						else if (tipo == vizTrocaPar && i < j) { // trocaPar
							int valor = vizinho->estado[i];
							vizinho->estado[i] = vizinho->estado[j];
							vizinho->estado[j] = valor;
							if (maxValor[i] != maxValor[j]) {
								// garantir que os valores estão dentro dos limites
								vizinho->estado[i] %= maxValor[i];
								vizinho->estado[j] %= maxValor[j];
							}
						}
						else if (tipo == vizInverterSegmento && i < j) { // inverterSegmento
							int ii = i, jj = j;
							while (ii < jj) {
								int valor = vizinho->estado[ii];
								vizinho->estado[ii] = vizinho->estado[jj];
								vizinho->estado[jj] = valor;
								if (maxValor[ii] != maxValor[jj]) {
									// garantir que os valores estão dentro dos limites
									vizinho->estado[ii] %= maxValor[ii];
									vizinho->estado[jj] %= maxValor[jj];
								}
								ii++;
								jj--;
							}
						}

						vizinho->custo = -1;
						vizinhos.Add(vizinho);
					}
					else 
						memoriaEsgotada = true;
				}
	}
	TProcuraMelhorativa::Vizinhanca(vizinhos);
}

void TCodificacaoInteira::Mutar(void) {
	// mutação com probabilidade p de trocar cada bit
	int p = Parametro(mutacaoCI);
	int limiteVizinhanca = Parametro(limiteVizinhancaCI);
	if (p == 0) {
		// um vizinho aleatório
		ETiposVizinhancaInteira tipo = (ETiposVizinhancaInteira)Parametro(vizinhancaCI);
		int i = TRand::rand() % nElementos;
		int j = TRand::rand() % nElementos;
		if (tipo == vizIncDecValor) {
			estado[i] += (TRand::rand() % 2 == 0 ? 1 : -1);
		} else if(tipo==vizIncDecPot2) {
			do {
				j = 1 << (TRand::rand() % 10); // potência de 2 até 512 
			} while (j >= maxValor[i]); 
			estado[i] += (TRand::rand() % 2 == 0 ? j : -j);
		} else if (tipo == vizTrocaValor) {
			estado[i] = TRand::rand() % maxValor[i];
		} else if (tipo == vizInserir) {
			int valor = estado[i];
			estado.Delete(i);
			estado.Insert(j < i ? j : j - 1, valor);
		} else if (tipo == vizTrocaPar) {
			int valor = estado[i];
			estado[i] = estado[j];
			estado[j] = valor;
		} else if (tipo == vizInverterSegmento) {
			while (i < j) {
				int valor = estado[i];
				estado[i] = estado[j];
				estado[j] = valor;
				i++;
				j--;
			}
		}
		// garantir que os valores estão dentro dos limites
		for (int i = 0; i < nElementos; i++)
			estado[i] = (estado[i] + maxValor[i]) % maxValor[i]; 
		custo = -1;
	}
	else {
		// cada elemento com probabilidade p
		for (int i = 0; i < nElementos; i++)
			if (TRand::rand() % 100 < p) {
				if (limiteVizinhanca) {
					estado[i] += TRand::rand() % (2 * limiteVizinhanca + 1) - limiteVizinhanca;
					estado[i] = (estado[i] + maxValor[i]) % maxValor[i]; // garantir positivo
				} else 
					estado[i] += TRand::rand() % maxValor[i];
			}
		custo = -1;
	}
}

int TCodificacaoInteira::Distancia(TPonto a) {
	int dist = 0;
	TCodificacaoInteira& obj = *(TCodificacaoInteira*)a;
	ETiposDistanciaInteira tipo = (ETiposDistanciaInteira)Parametro(distanciaCI);
	if (tipo == distEuclidiana) {
		int64_t d = 0;
		for (int i = 0; i < nElementos; i++) {
			int64_t dif = estado[i] - obj.estado[i];
			d += dif * dif;
		}
		dist = (int)d;
	}
	else if (tipo == distManhattan) {
		for (int i = 0; i < nElementos; i++) 
			dist += abs(estado[i] - obj.estado[i]);
	}
	else // Hamming
		for (int i = 0; i < nElementos; i++)
			dist += (estado[i] != obj.estado[i]);
	return dist;
}