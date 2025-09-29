#include "TCodificacaoInteira.h"

int TCodificacaoInteira::nElementos = 0; // número de elementos na permutação
TVector<int> TCodificacaoInteira::maxValor; // valor máximo para cada elemento
const char* TCodificacaoInteira::nomesVizinhanca[] = {
	"incDecValor",
	"incDecPot2",
	"trocaValor",
	"inserir",
	"trocaPar",
	"inverterSegmento" };

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

void TCodificacaoInteira::Debug(bool completo) {
	for (int i = 0; i < nElementos; i++)
		printf("%d ", estado[i]);
}

void TCodificacaoInteira::ResetParametros() {
	static const char* nomesCruzamento[] = {
		"uniforme",
		"1-ponto",
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
		"Hamming", // número de posições com valores diferentes
		"Euclidiana", // distância euclidiana (raiz quadrada da soma dos quadrados das diferenças)
		"Manhattan" }; // distância Manhattan (soma das diferenças absolutas)

	TProcuraMelhorativa::ResetParametros();
	// parametros da codificação inteira
	parametro += {
		{ "TIPO_CRUZAR", 1, 0, 10, "Cruzamento: N - N-pontos, 0 - uniforme", nomesCruzamento, _TV("0,2,3") },
		{ "TIPO_MUTAR", 0,0,100, "Mutação: 0 - aplica um vizinho aleatório (seja 1 só elemento ou segmento), 1 a 100, probabilidade de mutação de cada elemento, em percentagem (1 a 100)", NULL, _TV("0,2,3") },
		{ "TIPO_VIZINHO", 1,1,6, "Vizinhança: vários métodso para vizinhanças de inteiros", nomesVizinhanca },
		{ "LIMITE_VIZINHOS", 0,0,1000,
"LIMITE_VIZINHOS, conforme a vizinhança, se 0 não há limite\n\
- incDecPot2 + trocaValor - limita a diferença máxima de valores\n\
- inserir + trocaPar + inverterSegmento - limita a distância entre pares" },
		{ "TIPO_DISTANCIA", 1,1,3, "Distância: vários métodso para distâncias de inteiros", nomesDistancias, _TV("0,2,3") }
	};
}

void TCodificacaoInteira::Cruzamento(TPonto a, TPonto b) {
	int pontos = Parametro(TIPO_CRUZAR_CI);
	TVector<int> divisoes;
	if (pontos > nElementos / 2)
		pontos = nElementos / 2;
	while (divisoes.Count() < pontos) {
		divisoes += (TRand::rand() % nElementos);
		divisoes.BeASet();
	}
	if (divisoes.Empty()) { // cruzamento uniforme
		Debug(EXTRA_DEBUG, false, " cruzamento uniforme");
		for (int i = 0; i < nElementos; i++)
			estado[i] = ((TCodificacaoInteira*)(TRand::rand() % 2 == 0 ? a : b))->estado[i];
	}
	else { // cruzamento em N pontos
		bool copiaPai = true;
		int i = 0;
		if (Parametro(NIVEL_DEBUG) >= EXTRA_DEBUG) {
			Debug(EXTRA_DEBUG, false, " cruzamento %d-ponto(s): ", divisoes.Count());
			for (auto ponto : divisoes)
				Debug(EXTRA_DEBUG, false, "%d ", ponto);
		}
		divisoes += nElementos; // ponto final
		for(auto ponto : divisoes) {
			while (i < ponto) {
				estado[i] = ((TCodificacaoInteira*)(copiaPai ? a : b))->estado[i];
				i++;
			}
			copiaPai = !copiaPai;
		}
	}
	custo = -1;

	TProcuraMelhorativa::Cruzamento(a, b);
}


void TCodificacaoInteira::Vizinhanca(TVector<TPonto>& vizinhos) {
	// inverter segmento de N bits
	ETiposVizinhancaInteira tipo = (ETiposVizinhancaInteira)Parametro(TIPO_VIZINHO_CI);
	int limiteVizinhanca = Parametro(LIMITE_VIZINHOS_CI);
	Debug(EXTRA_DEBUG, false, " vizinhança %s (limite %d)",
		nomesVizinhanca[tipo - 1], limiteVizinhanca);

	if (tipo >= vizIncDecValorCI && tipo <= vizTrocaValorCI) {
		// alterar valor de um elemento
		for (int i = 0; i < nElementos; i++) {
			int j = 0;
			while (abs(j) <= maxValor[i] && (!limiteVizinhanca || abs(j) <= limiteVizinhanca)) {
				// incrementar j (+1, -1, +2, -2, +4, -4, etc no caso de potências, e incremental c.c.)
				if (j <= 0)
					j = -j + (tipo == vizIncDecPot2CI ? (j == 0 ? 1 : -j) : 1);
				else
					j = -j;
				if (tipo == vizIncDecValorCI && j > 1)
					break; // apenas incrementa/decrementa 1
				if (estado[i] + j < 0 || estado[i] + j >= maxValor[i])
					continue; // valor inválido
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
		// alterar posição de elementos
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
								// garantir que os valores estão dentro dos limites
								for (int k = (i < j ? i : j); k < (i < j ? j : i); k++)
									vizinho->estado[k] %= maxValor[k];
							}
						}
						else if (tipo == vizTrocaParCI && i < j) { // trocaPar
							int valor = vizinho->estado[i];
							vizinho->estado[i] = vizinho->estado[j];
							vizinho->estado[j] = valor;
							if (maxValor[i] != maxValor[j]) {
								// garantir que os valores estão dentro dos limites
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
									// garantir que os valores estão dentro dos limites
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
	// mutação com probabilidade p de trocar cada bit
	int p = Parametro(TIPO_MUTAR_CI);
	int limiteVizinhanca = Parametro(LIMITE_VIZINHOS_CI);
	if (p == 0) {
		// um vizinho aleatório
		ETiposVizinhancaInteira tipo = (ETiposVizinhancaInteira)Parametro(TIPO_VIZINHO_CI);
		int i = TRand::rand() % nElementos;
		int j = TRand::rand() % nElementos;
		Debug(EXTRA_DEBUG, false, " mutar vizinho %s (%d,%d)",
			nomesVizinhanca[tipo - 1], i, j);
		if (tipo == vizIncDecValorCI) {
			estado[i] += (TRand::rand() % 2 == 0 ? 1 : -1);
		}
		else if (tipo == vizIncDecValorCI) {
			do {
				j = 1 << (TRand::rand() % 10); // potência de 2 até 512 
			} while (j >= maxValor[i]);
			estado[i] += (TRand::rand() % 2 == 0 ? j : -j);
		}
		else if (tipo == vizTrocaValorCI) {
			estado[i] = TRand::rand() % maxValor[i];
		}
		else if (tipo == vizInserirCI) {
			int valor = estado[i];
			estado.Delete(i);
			estado.Insert(j < i ? j : j - 1, valor);
		}
		else if (tipo == vizTrocaParCI) {
			int valor = estado[i];
			estado[i] = estado[j];
			estado[j] = valor;
		}
		else if (tipo == vizInverterSegmentoCI) {
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
		Debug(EXTRA_DEBUG, false, " mutar prob p(%d) limiteVizinhanca %d",
			p, limiteVizinhanca);
		// cada elemento com probabilidade p
		for (int i = 0; i < nElementos; i++)
			if (TRand::rand() % 100 < (unsigned)p) {
				if (limiteVizinhanca) {
					estado[i] += TRand::rand() % (2 * limiteVizinhanca + 1) - limiteVizinhanca;
					estado[i] = (estado[i] + maxValor[i]) % maxValor[i]; // garantir positivo
				}
				else
					estado[i] += TRand::rand() % maxValor[i];
			}
		custo = -1;
	}
}

int TCodificacaoInteira::Distancia(TPonto a) {
	int dist = 0;
	TCodificacaoInteira& obj = *(TCodificacaoInteira*)a;
	ETiposDistanciaInteira tipo = (ETiposDistanciaInteira)Parametro(TIPO_DISTANCIA_CI);
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