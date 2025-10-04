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
void TCodificacaoBinaria::Debug(bool completo) {
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
		{ "TIPO_CRUZAR", 1, 0, 10, "TIPO_CRUZAR: 1 - um ponto, >=2 N-pontos, 0 - uniforme", nomesCruzamento, _TV("0,2,3") },
		{ "TIPO_MUTAR", 0,0,100, "TIPO_MUTAR: 0 - aplica um vizinho aleatório (seja 1 só elemento ou segmento), 1 a 100, probabilidade de mutação de cada bit, em percentagem (1 a 100)", NULL, _TV("0,2,3") },
		{ "TIPO_VIZINHO", 1,1,1000, "Troca segmento: 1 - apenas 1 bit de cada vez, >=2 troca um segmento de N bits" }
	};
}


void TCodificacaoBinaria::Vizinhanca(TVector<TPonto>& vizinhos) {
	// inverter segmento de N bits
	int tamanho = Parametro(TIPO_VIZINHO_CB);
	if (tamanho < 1)
		tamanho = 1;
	Debug(EXTRA_DEBUG, false, " vizinhança %d bits", tamanho);
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
	int p = Parametro(TIPO_MUTAR_CB);
	if (p == 0) {
		// um vizinho aleatório
		int tamanho = Parametro(TIPO_VIZINHO_CB);
		if (tamanho < 1)
			tamanho = 1;
		int i = TRand::rand() % (nElementos - tamanho + 1);
		Debug(EXTRA_DEBUG, false, " mutar vizinho #bits %d (%d)",
			tamanho, i);
		for (int j = 0; j < tamanho; j++)
			Troca(i + j);
		custo = -1;
	}
	else {
		Debug(EXTRA_DEBUG, false, " mutar prob p(%d)",	p);
		// cada bit com probabilidade p
		for (int i = 0; i < nElementos; i++)
			if (TRand::rand() % 100 < (unsigned)p)
				Troca(i);
		custo = -1;
	}
}

void TCodificacaoBinaria::Cruzamento(TPonto a, TPonto b) {
	int pontos = Parametro(TIPO_CRUZAR_CB);
	TVector<int> divisoes;
	if(pontos>nElementos/2)
		pontos = nElementos / 2;
	while (divisoes.Count() < pontos) {
		divisoes += (TRand::rand() % nElementos);
		divisoes.BeASet();
	}
	if (divisoes.Empty()) { // cruzamento uniforme
		Debug(EXTRA_DEBUG, false, " cruzamento uniforme");
		for (int i = 0; i < nElementos; i++)
			Bit(i) = ((TCodificacaoBinaria*)(TRand::rand() % 2 == 0?a:b))->Bit(i);
	}
	else { // cruzamento em N pontos
		int i=0;
		bool copiaPai = true;
		if (Parametro(NIVEL_DEBUG) >= EXTRA_DEBUG) {
			Debug(EXTRA_DEBUG, false, " cruzamento %d-ponto(s): ", divisoes.Count());
			for (auto ponto : divisoes)
				Debug(EXTRA_DEBUG, false, "%d ", ponto);
		}
		divisoes += nElementos; // ponto final
		for (auto ponto : divisoes) {
			while (i < ponto) {
				Bit(i) = ((TCodificacaoBinaria*)(copiaPai ? a : b))->Bit(i);
				i++;
			}
			copiaPai = !copiaPai;
		}
	}
	custo = -1;

	TProcuraMelhorativa::Cruzamento(a, b);
}

int TCodificacaoBinaria::Distancia(TPonto a) { // distância de Hamming
	int dist = 0;
	for (int i = 0; i < nElementos; i++)
		if (Bit(i) != ((TCodificacaoBinaria*)a)->Bit(i))
			dist++;
	return dist;
}
