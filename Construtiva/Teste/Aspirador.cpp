#include "Aspirador.h"
#include <stdio.h>
#include <string.h>


CAspirador::CAspirador(void) : aspirador(0)
{
}

CAspirador::~CAspirador(void)
{
}

TProcuraConstrutiva* CAspirador::Duplicar(void)
{
	CAspirador* clone = new CAspirador;
	if(clone!=NULL)
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

void CAspirador::Inicializar(void)
{
	salas.Count(instancia.valor);
	for (int i = 0; i < salas.Count(); i++) 
		salas[i] = (TRand::rand() % 2 ? '.' : '*');
	aspirador = TRand::rand() % salas.Count();
	tamanhoCodificado = 1; // dá já para bastantes salas
	TProcuraConstrutiva::Inicializar();
}

void CAspirador::ResetParametros()
{
	TProcuraConstrutiva::ResetParametros();
	instancia = { "", 4,2,50};
}

void CAspirador::Sucessores(TVector<TNo>&sucessores)
{
	CAspirador* sucessor;
	if (aspirador > 0) { // esquerda
		sucessores += (sucessor = (CAspirador*)Duplicar());
		sucessor->aspirador--;
	}
	if (aspirador < salas.Count() - 1) { // direita
		sucessores += (sucessor = (CAspirador*)Duplicar());
		sucessor->aspirador++;
	}
	// limpar
	sucessores += (sucessor = (CAspirador*)Duplicar());
	sucessor->salas[aspirador] = '.';
	if (memoriaEsgotada)
		return;
	TProcuraConstrutiva::Sucessores(sucessores);
}

TString CAspirador::Acao(TProcuraConstrutiva* sucessor) {
	CAspirador* suc = (CAspirador*)sucessor;
	if (aspirador == suc->aspirador && suc->salas[aspirador] == '.')
		return "asp";
	if (aspirador - 1 == suc->aspirador)
		return "esq";
	if (aspirador + 1 == suc->aspirador)
		return "dir";
	return "Inválida";
}

void CAspirador::Debug(bool completo)
{
	NovaLinha();
	for (int i = 0; i < salas.Count(); i++) {
		printf("%c%c%c",
			aspirador == i ? '[' : ' ',
			salas[i],
			aspirador == i ? ']' : ' ');
		if ((i + 1) < salas.Count() && (i + 1) % 10 == 0)
			NovaLinha();
	}
}

bool CAspirador::SolucaoCompleta(void)
{
	for (int i = 0; i < salas.Count(); i++)
		if (salas[i] == '*')
			return false;
	return true;
}

bool CAspirador::Distinto(TNo estado) {
	return aspirador != ((CAspirador*)estado)->aspirador ||
		!salas.Equal(((CAspirador*)estado)->salas);
}

// o problema é simples, é possível uma heurística perfeita:
// dá sempre o custo até à solução objetivo ótimo
int CAspirador::Heuristica(void) {
	// o aspirador tem de se mover para a salas mais extremas, e limpar todas as casas sujas
	int sujas = 0, max = -1, min = -1;
	for (int i = 0; i < salas.Count(); i++)
		if (salas[i] == '*') {
			sujas++;
			if (min < 0 || i < min)
				min = i;
			if (max < 0 || i > max)
				max = i;
		}
	if (sujas == 0)
		return heuristica = 0;
	return heuristica = sujas + // movimentos a aspirar as casas sujas
		(abs(aspirador - min) < abs(aspirador-max) ? // ver qual o extermo mais próximo
			abs(aspirador - min) :   // movimentos a ir para o extermo mais próximo
			abs(aspirador-max)) + 
		max - min; // após estar nesse extremo, ainda vai ao outro extremo
}


// método para lidar com estados repetidos
void CAspirador::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	int i, index;
	TProcuraConstrutiva::Codifica(estado);
	// não há simetrias, simplesmente codificar as salas, seguida do aspirador
	for (i = 0, index = 0; i < salas.Count(); i++, index++)
		estado[index >> 6] |= (uint64_t)(salas[i] == '*' ? 1 : 0) << (index & 63);
	// assumir que o aspirador cabe no resto dos elementos (número de salas pequeno)
	estado[index >> 6] |= (uint64_t)(aspirador + 1) << (index & 63); 
	// aspirador+1 para evitar o estado com tudo a zero
}
