#include "Particao.h"
#include <stdio.h>
#include <string.h>

CParticao::CParticao(void)
{
}

CParticao::~CParticao(void)
{
}

TProcuraConstrutiva* CParticao::Duplicar(void)
{
	CParticao* clone = new CParticao;
	if (clone != NULL)
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

void CParticao::Inicializar(void)
{
	direita = esquerda = numeros = {};
	totalDireita = totalEsquerda = 0;

	// gerar uma instancia provavelmente possivel
	int64_t soma;
	soma = 0;
	for (int i = 0; i < instancia.valor; i++) {
		numeros += (instancia.valor * instancia.valor + 4 * (TRand::rand() % instancia.valor + 1) + TRand::rand() % 4);
		soma += (int)numeros.Last();
	}
	// acertar a paridade, muito embora não se saiba se há ou não solução
	if (soma % 2 == 1)
		numeros.Last() += 1;
	numeros.Sort();
	tamanhoCodificado = 3; // apenas três inteiro de 64 bits, para colocar 3 inteiros de 64 bits
	TProcuraConstrutiva::Inicializar();
}

void CParticao::Sucessores(TVector<TNo>& sucessores)
{
	int64_t faltaDistribuir = 0;
	for (int i = 0; i < numeros.Count(); i++)
		faltaDistribuir += numeros[i];
	if (faltaDistribuir < abs(totalEsquerda - totalDireita)) { // ja nao ha hipotese
		TProcuraConstrutiva::Sucessores(sucessores);
		return;
	}

	if (!numeros.Empty()) {
		CParticao* esquerda, * direita;
		sucessores += (esquerda = (CParticao*)Duplicar());
		sucessores += (direita = (CParticao*)Duplicar());
		if (memoriaEsgotada)
			return;
		esquerda->esquerda += (esquerda->numeros.Pop());
		esquerda->totalEsquerda += esquerda->esquerda.Last();
		direita->direita += (direita->numeros.Pop());
		direita->totalDireita += direita->direita.Last();
		TProcuraConstrutiva::Sucessores(sucessores);
	}
}

const char* CParticao::Acao(TProcuraConstrutiva* sucessor) {
	CParticao* suc = (CParticao*)sucessor;
	if (totalEsquerda == suc->totalEsquerda &&
		totalDireita != suc->totalDireita)
		return "dir";
	if (totalEsquerda != suc->totalEsquerda &&
		totalDireita == suc->totalDireita)
		return "esq";
	return "Inv";
}

void CParticao::Debug(bool completo)
{
	char str[256];
	int i, col;
	int64_t total = 0;
	for (auto numero : numeros)
		total += numero;
	snprintf(str, sizeof(str), "📦%" PRId64 " → ◀️%" PRId64 " = ▶️%" PRId64,
		total, totalEsquerda, totalDireita);
	NovaLinha();
	// apenas no modo completo mostra tudo
	if (Parametro(NIVEL_DEBUG) < COMPLETO) {
		MostraCaixa(str, ECaixaParte::Separador, 1, true, -2);
		return;
	}
	MostraCaixa(str, ECaixaParte::Topo, 70, true, -2);
	NovaLinha();
	MostraCaixa("📦", ECaixaParte::Separador, 1, true, -2);
	col = 2;
	for (i = 0; i < numeros.Count(); i++) {
		col += printf(" %d", numeros[i]);
		if (col > 60 && i < numeros.Count() - 1) {
			col = 2;
			NovaLinha();
			MostraCaixa("📦", ECaixaParte::Separador, 1, true, -2);
		}
	}
	NovaLinha();
	MostraCaixa("◀️", ECaixaParte::Separador, 1, true, -2);
	col = 2;
	for (i = 0; i < esquerda.Count(); i++) {
		col += printf(" %d", esquerda[i]);
		if (col > 60 && i < numeros.Count() - 1) {
			col = 2;
			NovaLinha();
			MostraCaixa("◀️", ECaixaParte::Separador, 1, true, -2);
		}
	}
	NovaLinha();
	MostraCaixa("▶️", ECaixaParte::Separador, 1, true, -2);
	col = 2;
	for (i = 0; i < direita.Count(); i++) {
		col += printf(" %d", direita[i]);
		if (col > 60 && i < numeros.Count() - 1) {
			col = 2;
			NovaLinha();
			MostraCaixa("▶️", ECaixaParte::Separador, 1, true, -2);
		}
	}
	NovaLinha();
	MostraCaixa("", ECaixaParte::Fundo, 70, true, -2);
}


// método para lidar com estados repetidos
void CParticao::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	int64_t valorMaior, valorMenor, porColocar;
	// como a ordem é fixa, um estado fica definido por:
	// - números que faltam colocar
	// - valor atual num lado, o menor
	// - valor atual no outro lado, o maior
	valorMaior = totalDireita;
	valorMenor = totalEsquerda;
	if (valorMaior < valorMenor) {
		porColocar = valorMaior;
		valorMaior = valorMenor;
		valorMenor = porColocar;
	}
	porColocar = numeros.Count();
	estado[0] = porColocar;
	estado[1] = valorMaior;
	estado[2] = valorMenor;
}

void CParticao::ResetParametros()
{
	TProcuraConstrutiva::ResetParametros();
	instancia = { NULL, 10,2,1000, NULL, NULL };
}

