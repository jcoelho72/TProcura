#include "TCodificacaoInteira.h"

int TCodificacaoInteira::nElementos = 0; // n�mero de elementos na permuta��o
TVector<int> TCodificacaoInteira::maxValor; // valor m�ximo para cada elemento

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
	static const char* nomesCruzamento[] = {
		"uniforme",
		"2-pontos",
		"3-pontos",
		"4-pontos",
		"5-pontos",
		"6-pontos",
		"7-pontos",
		"8-pontos",
		"9-pontos",
		"10-pontos" };
	static const char* nomesDistancias[] = {
		"Hamming", // n�mero de posi��es com valores diferentes
		"Euclidiana", // dist�ncia euclidiana (raiz quadrada da soma dos quadrados das diferen�as)
		"Manhattan" }; // dist�ncia Manhattan (soma das diferen�as absolutas)

	TProcuraMelhorativa::ResetParametros();
	// parametros da codifica��o inteira
	parametro += {
		{ "tCruzamento", 1, 0, 9, "Cruzamento: 1 - um ponto, >=2 N-pontos, 0 - uniforme", nomesCruzamento },
		{ "tMuta��o", 0,0,100, "Muta��o: 0 - aplica um vizinho aleat�rio (seja 1 s� elemento ou segmento), 1 a 100, probabilidade de muta��o de cada elemento, em percentagem (1 a 100)", NULL },
		{ "tVizinhanca", 1,1,6, "Vizinhan�a: v�rios m�todso para vizinhan�as de inteiros", nomesVizinhanca },
		{ "LimiteViz", 0,0,1000,
"LimiteVizinhan�a, conforme a vizinhan�a, se 0 n�o h� limite\n\
- incDecPot2 + trocaValor - limita a diferen�a m�xima de valores\n\
- inserir + trocaPar + inverterSegmento - limita a dist�ncia entre pares", NULL },
		{ "tDist�ncia", 1,1,3, "Dist�ncia: v�rios m�todso para dist�ncias de inteiros", nomesDistancias }
	};
}

void TCodificacaoInteira::Cruzamento(TPonto a, TPonto b) {
	int pontos = Parametro(cruzamentoCI);
	TVector<int> divisoes;
	if (pontos > nElementos / 2)
		pontos = nElementos / 2;
	while (divisoes.Count() < pontos) {
		divisoes += (TRand::rand() % nElementos);
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

	if (tipo >= vizIncDecValorCI && tipo <= vizTrocaValorCI) {
		// alterar valor de um elemento
		for (int i = 0; i < nElementos; i++) {
			int j = 0;
			while (abs(j) <= maxValor[i] && (!limiteVizinhanca || abs(j) <= limiteVizinhanca)) {
				// incrementar j (+1, -1, +2, -2, +4, -4, etc no caso de pot�ncias, e incremental c.c.)
				if (j <= 0)
					j = -j + (tipo == vizIncDecPot2CI ? (j == 0 ? 1 : -j) : 1);
				else
					j = -j;
				if (tipo == vizIncDecValorCI && j > 1)
					break; // apenas incrementa/decrementa 1
				if (estado[i] + j < 0 || estado[i] + j >= maxValor[i])
					continue; // valor inv�lido
				TCodificacaoInteira* vizinho = (TCodificacaoInteira*)Duplicar();
				if (vizinho != NULL) {
					vizinho->estado[i] += j;
					vizinho->custo = -1;
					vizinhos += vizinho;
				}
				else 
					memoriaEsgotada = true;
			}
		}
	}
	else if (tipo >= vizInserirCI && tipo <= vizInverterSegmentoCI) {
		// alterar posi��o de elementos
		for (int i = 0; i < nElementos; i++) // elemento i
			for (int j = 0; j < nElementos; j++) // elemento j ou local j
				if (i != j && (!limiteVizinhanca || abs(i - j) <= limiteVizinhanca)) {
					TCodificacaoInteira* vizinho = (TCodificacaoInteira*)Duplicar();
					if (vizinho != NULL) {
						if (tipo == vizInserirCI) {
							int valor = vizinho->estado[i];
							vizinho->estado.Delete(i);
							vizinho->estado.Insert(j < i ? j : j - 1, valor);
							if (maxValor[i] != maxValor[j]) {
								// garantir que os valores est�o dentro dos limites
								for (int k = (i < j ? i : j); k < (i < j ? j : i); k++)
									vizinho->estado[k] %= maxValor[k];
							}
						}
						else if (tipo == vizTrocaParCI && i < j) { // trocaPar
							int valor = vizinho->estado[i];
							vizinho->estado[i] = vizinho->estado[j];
							vizinho->estado[j] = valor;
							if (maxValor[i] != maxValor[j]) {
								// garantir que os valores est�o dentro dos limites
								vizinho->estado[i] %= maxValor[i];
								vizinho->estado[j] %= maxValor[j];
							}
						}
						else if (tipo == vizInverterSegmentoCI && i < j) { // inverterSegmento
							int ii = i, jj = j;
							while (ii < jj) {
								int valor = vizinho->estado[ii];
								vizinho->estado[ii] = vizinho->estado[jj];
								vizinho->estado[jj] = valor;
								if (maxValor[ii] != maxValor[jj]) {
									// garantir que os valores est�o dentro dos limites
									vizinho->estado[ii] %= maxValor[ii];
									vizinho->estado[jj] %= maxValor[jj];
								}
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
	}
	TProcuraMelhorativa::Vizinhanca(vizinhos);
}

void TCodificacaoInteira::Mutar(void) {
	// muta��o com probabilidade p de trocar cada bit
	int p = Parametro(mutacaoCI);
	int limiteVizinhanca = Parametro(limiteVizinhancaCI);
	if (p == 0) {
		// um vizinho aleat�rio
		ETiposVizinhancaInteira tipo = (ETiposVizinhancaInteira)Parametro(vizinhancaCI);
		int i = TRand::rand() % nElementos;
		int j = TRand::rand() % nElementos;
		if (tipo == vizIncDecValorCI) {
			estado[i] += (TRand::rand() % 2 == 0 ? 1 : -1);
		} else if(tipo==vizIncDecPot2CI) {
			do {
				j = 1 << (TRand::rand() % 10); // pot�ncia de 2 at� 512 
			} while (j >= maxValor[i]); 
			estado[i] += (TRand::rand() % 2 == 0 ? j : -j);
		} else if (tipo == vizTrocaValorCI) {
			estado[i] = TRand::rand() % maxValor[i];
		} else if (tipo == vizInserirCI) {
			int valor = estado[i];
			estado.Delete(i);
			estado.Insert(j < i ? j : j - 1, valor);
		} else if (tipo == vizTrocaParCI) {
			int valor = estado[i];
			estado[i] = estado[j];
			estado[j] = valor;
		} else if (tipo == vizInverterSegmentoCI) {
			while (i < j) {
				int valor = estado[i];
				estado[i] = estado[j];
				estado[j] = valor;
				i++;
				j--;
			}
		}
		// garantir que os valores est�o dentro dos limites
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
	if (tipo == distEuclidianaCI) {
		int64_t d = 0;
		for (int i = 0; i < nElementos; i++) {
			int64_t dif = estado[i] - obj.estado[i];
			d += dif * dif;
		}
		dist = (int)d;
	}
	else if (tipo == distManhattanCI) {
		for (int i = 0; i < nElementos; i++) 
			dist += abs(estado[i] - obj.estado[i]);
	}
	else // Hamming
		for (int i = 0; i < nElementos; i++)
			dist += (estado[i] != obj.estado[i]);
	return dist;
}