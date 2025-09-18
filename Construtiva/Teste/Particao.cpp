#include "Particao.h"
#include <stdio.h>
#include <string.h>

CParticao::CParticao(void) : totalDireita(0), totalEsquerda(0)
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
	TProcuraConstrutiva::Inicializar();
	direita = esquerda = numeros = {}; 
	totalDireita = totalEsquerda = 0;

	// gerar uma instancia provavelmente possivel
	int soma1, soma2;
	soma1 = soma2 = 0;
	for (int i = 0; i < instancia.valor; i++) {
		numeros += (TRand::rand() % (3 * instancia.valor));
		if (soma1 < soma2)
			soma1 += numeros.Last();
		else soma2 += numeros.Last();
	}
	// acertar a paridade, muito embora não se saiba se há ou não solução
	if ((soma1 + soma2) % 2 == 1)
		numeros.Last() + 1;
	// garantir que há uma solução
	//if (soma1 != soma2)
	//	numeros += abs(soma1 - soma2);
	numeros -= 0;
	numeros.Sort();
	tamanhoCodificado = 2; // apenas dois inteiro de 64 bits, para colocar 3 inteiros de 32 bits
}

void CParticao::Sucessores(TVector<TNo>& sucessores)
{
	int faltaDistribuir = 0;
	for (int i = 0; i < numeros.Count(); i++)
		faltaDistribuir += numeros[i];
	if (faltaDistribuir < abs(totalEsquerda - totalDireita)) { // ja nao ha hipotese
		TProcuraConstrutiva::Sucessores(sucessores);
		return;
	}

	if (numeros.Count() > 0) {
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

void CParticao::Debug(void)
{
	int i, j;
	NovaLinha();
	printf("Colocar #%d: %d = %d",
		numeros.Count(), totalEsquerda, totalDireita);
	for (i = 0; i < numeros.Count(); i++) {
		if (i % 4 == 0) {
			NovaLinha();
			printf("--- ");
		}
		printf("%3d ", numeros[i]);
		if ((i + 1) % 4 == 0)
			printf(" ---");
	}
	if (i % 4 != 0) {
		while (i++ % 4 != 0)
			printf("    ");
		printf(" ---");
	}
	for (i = 0; i < esquerda.Count(); i++) {
		if (i % 4 == 0) {
			NovaLinha();
			printf("    ");
		}
		printf("%3d ", esquerda[i]);
		if ((i + 1) % 4 == 0)
			printf(" <<<");
	}
	if (i % 4 != 0) {
		while (i++ % 4 != 0)
			printf("    ");
		printf(" <<<");
	}
	for (i = 0; i < direita.Count(); i++) {
		if (i % 4 == 0) {
			NovaLinha();
			printf(">>> ");
		}
		printf("%3d ", direita[i]);
	}
}


// método para lidar com estados repetidos
void CParticao::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	int valorMaior, valorMenor, porColocar;
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
	estado[1] |= (uint64_t)valorMenor << 32;
}

void CParticao::ResetParametros()
{
	TProcuraConstrutiva::ResetParametros();
	instancia = { NULL, 10,2,1000, NULL, NULL };
}

