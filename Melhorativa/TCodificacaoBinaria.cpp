#include "TCodificacaoBinaria.h"

// número de elementos binários na codificação
int TCodificacaoBinaria::nElementos = 0;

void TCodificacaoBinaria::Copiar(TPonto objecto) {
	TCodificacaoBinaria& obj = *((TCodificacaoBinaria*)objecto);
	estado = obj.estado;
}

void TCodificacaoBinaria::NovaSolucao(void) {
	int n = (nElementos + 63) / 64;
	estado.Count(n);
	for (int i = 0; i < n; i++)
		estado[i] = ((uint64_t)TRand::rand()) << 32 | ((uint64_t)TRand::rand());
	custo = -1;
}

// métodos que podem ser redefinidos
void TCodificacaoBinaria::Debug(void) {
	for (int i = 0; i < nElementos; i++) 
		printf("%d", Bit(i) ? 1 : 0);
}

void TCodificacaoBinaria::ResetParametros() {
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
	TProcuraMelhorativa::ResetParametros();

	// parametros da codificação binária
	parametro += {
		{ "tCruzamento", 1, 0, 10, "Cruzamento: 1 - um ponto, >=2 N-pontos, 0 - uniforme", nomesCruzamento },
		{ "tMutação", 0,0,100, "Mutação: 0 - aplica um vizinho aleatório (seja 1 só elemento ou segmento), 1 a 100, probabilidade de mutação de cada bit, em percentagem (1 a 100)", NULL },
		{ "tVizinhanca", 1,1,1000, "Troca segmento: 1 - apenas 1 bit de cada vez, >=2 troca um segmento de N bits", NULL }
	};
}


void TCodificacaoBinaria::Vizinhanca(TVector<TPonto>& vizinhos) {
	// inverter segmento de N bits
	int tamanho = Parametro(vizinhancaCB);
	if (tamanho < 1)
		tamanho = 1;
	for (int i = 0; i < nElementos - tamanho + 1; i++) {
		TCodificacaoBinaria* vizinho = (TCodificacaoBinaria*)Duplicar();
		if (vizinho != NULL) {
			for (int j = 0; j < tamanho; j++)
				vizinho->Troca(i + j);
			vizinho->custo = -1;
			vizinhos += vizinho;
		}
		else
			memoriaEsgotada = true;
	}
	TProcuraMelhorativa::Vizinhanca(vizinhos);
}

void TCodificacaoBinaria::Mutar(void) {
	// mutação com probabilidade p de trocar cada bit
	int p = Parametro(mutacaoCB);
	if (p == 0) {
		// um vizinho aleatório
		int tamanho = Parametro(vizinhancaCB);
		if (tamanho < 1)
			tamanho = 1;
		int i = TRand::rand() % (nElementos - tamanho + 1);
		for (int j = 0; j < tamanho; j++)
			Troca(i + j);
		custo = -1;
	}
	else {
		// cada bit com probabilidade p
		for (int i = 0; i < nElementos; i++)
			if (TRand::rand() % 100 < p)
				Troca(i);
		custo = -1;
	}
}

void TCodificacaoBinaria::Cruzamento(TPonto a, TPonto b) {
	int pontos = Parametro(cruzamentoCB);
	TVector<int> divisoes;
	if(pontos>nElementos/2)
		pontos = nElementos / 2;
	while (divisoes.Count() < pontos) {
		divisoes += (TRand::rand() % nElementos);
		divisoes.BeASet();
	}
	if (divisoes.Count() == 0) { // cruzamento uniforme
		for (int i = 0; i < nElementos; i++)
			Bit(i) = ((TCodificacaoBinaria*)(TRand::rand() % 2 == 0?a:b))->Bit(i);
		custo = -1;
	}
	else { // cruzamento em N pontos
		int i=0;
		divisoes.Invert();
		do {
			while (i < divisoes.Last()) {
				Bit(i) = ((TCodificacaoBinaria*)(divisoes.Count() % 2 == 0 ? a : b))->Bit(i);
				i++;
			}
			divisoes.Pop();
		} while (divisoes.Count() > 0);
		while (i < nElementos) {
			Bit(i) = ((TCodificacaoBinaria*)(a))->Bit(i);
			i++;
		}
	}

	TProcuraMelhorativa::Cruzamento(a, b);
}

int TCodificacaoBinaria::Distancia(TPonto a) { // distância de Hamming
	int dist = 0;
	for (int i = 0; i < nElementos; i++)
		if (Bit(i) != ((TCodificacaoBinaria*)a)->Bit(i))
			dist++;
	return dist;
}
