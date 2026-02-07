#include "OitoDamas.h"
#include <stdio.h>

int COitoDamas::nDamas = 8; // número de damas desta instância 

COitoDamas::COitoDamas(void)
{
}

COitoDamas::~COitoDamas(void)
{
}

TProcuraConstrutiva* COitoDamas::Duplicar(void)
{
	COitoDamas* clone = new COitoDamas;
	if (clone != NULL)
		clone->damas = damas;
	else
		memoriaEsgotada = true;
	return clone;
}

void COitoDamas::Inicializar(void)
{
	damas = {};
	nDamas = instancia.valor;
	// 4 bits por dama, com 40 damas no máximo dá 3 inteiros de 64 bits
	tamanhoCodificado = (nDamas - 1) * 4 / 64 + 1;
	TProcuraConstrutiva::Inicializar();
}

void COitoDamas::ResetParametros()
{
	TProcuraConstrutiva::ResetParametros();
	instancia = { "", 8,4,MAX_DAMAS};
}

void COitoDamas::Sucessores(TVector<TNo>& sucessores)
{
	int novaLinha = damas.Count();
	// tentar colocar damas em todas as colunas
	for (int i = 0; i < nDamas; i++) {
		int j = 0;
		// verificar se ha uma dama a atacar esta posicao
		for (; j < novaLinha; j++)
			if (i == damas[j] || i == damas[j] + (novaLinha - j) || i == damas[j] - (novaLinha - j))
				break;
		if (j == novaLinha) { // e possivel, adicionar sucessor
			COitoDamas* sucessor = (COitoDamas*)Duplicar();
			if (memoriaEsgotada)
				return;
			sucessor->damas += i;
			sucessores += sucessor;
		}
	}
	TProcuraConstrutiva::Sucessores(sucessores);
}

TString COitoDamas::Acao(TProcuraConstrutiva* sucessor) {
	COitoDamas* suc = (COitoDamas*)sucessor;
	if (damas.Count() + 1 == suc->damas.Count()) 
		return TString().printf("d%d", suc->damas.Last() + 1);
	return "Inv";
}

void COitoDamas::Debug(bool completo)
{
	if (!completo) {
		NovaLinha();
		for (auto dama : damas)
			printf("d%d ", dama);
		return;
	}
	for (int i = 0; i < nDamas; i++) {
		NovaLinha();
		for (int j = 0; j < nDamas; j++) {
			if (damas.Count() > i && damas[i] == j)
				printf("%2s", "♛ "); //"♛ ");
			else
				printf("%s", ((i + j) % 2 ? "  " : "::")); // "▒▒" "::" "░░"
		}
	}

}


void COitoDamas::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	TVector<int> damas;
	// obter o estado normalizado, para que os estados fiquem iguais a menos de operações de simetria
	Normalizar(damas);
	TProcuraConstrutiva::Codifica(estado);
	// codificar números de 4 bits 
	// (0 a 7 daria 3 bits, mas para ser múltiplo de 64 usa-se 4 bits)
	for (int i = 0, index = 0; i < damas.Count(); i++, index += 4)
		estado[index >> 6] |= (uint64_t)damas[i] << (index & 63);
}

// coloca em damas o estado normalizado segundo as 3 simetrias
void COitoDamas::Normalizar(TVector<int>& damas) {
	static int tab[MAX_DAMAS][MAX_DAMAS];
	int peso, atual;
	bool alterado;
	damas = COitoDamas::damas;
	// inicializar tabuleiro
	for (int i = 0; i < nDamas; i++)
		for (int j = 0; j < nDamas; j++)
			tab[i][j] = 0;
	for (int i = 0; i < damas.Count(); i++)
		tab[i][damas[i]] = 1;
	// obter o tabuleiro de menor peso, mediante as 3 simetrias
	peso = atual = PesoVersao(tab);
	do {
		alterado = false;
		for (int i = 0; i < 3; i++) {
			Simetria(tab, i);
			atual = PesoVersao(tab);
			if (atual < peso) {
				peso = atual;
				alterado = true;
			}
			else
				Simetria(tab, i); // repor
		}
	} while (alterado);
	// percorridas todas as simetrias e nada é melhor, escolher esta
	// converter para o outro formato, em que -1 é dama não existe na linha
	damas.Count(nDamas);
	damas.Reset(-1);
	for (int i = 0; i < nDamas; i++)
		for (int j = 0; j < nDamas; j++)
			if (tab[i][j])
				damas[i] = j;
}

int COitoDamas::PesoVersao(int tab[MAX_DAMAS][MAX_DAMAS]) {
	int peso = 0;
	for (int i = 0; i < nDamas; i++)
		for (int j = 0; j < nDamas; j++)
			if (tab[i][j])
				peso += i * nDamas + j;
	return peso;
}

void COitoDamas::Troca(int& a, int& b) {
	int aux = a;
	a = b;
	b = aux;
}

// é suficiente estas 3 simetrias para simular qualquer outra
void COitoDamas::Simetria(int tab[MAX_DAMAS][MAX_DAMAS], int eixo) {
	if (eixo == 0) { // simetria horizontal
		for (int i = 0; i < nDamas; i++)
			for (int j = 0; j < nDamas / 2; j++)
				Troca(tab[i][j], tab[i][nDamas - 1 - j]);
	}
	else if (eixo == 1) { // simetria vertical
		for (int i = 0; i < nDamas / 2; i++)
			for (int j = 0; j < nDamas; j++)
				Troca(tab[i][j], tab[nDamas - 1 - i][j]);
	}
	else { // simetria diagonal
		for (int i = 0; i < nDamas; i++)
			for (int j = i + 1; j < nDamas; j++)
				Troca(tab[i][j], tab[j][i]);
	}
}
