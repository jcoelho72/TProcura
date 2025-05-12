#include "ProblemaArtificial.h"
#include <stdio.h>
#include <string.h>


CProblemaArtificial::CProblemaArtificial(void) 
{
}

CProblemaArtificial::~CProblemaArtificial(void)
{
}

TProcuraConstrutiva* CProblemaArtificial::Duplicar(void)
{
	CProblemaArtificial* clone = new CProblemaArtificial;
	if(clone!=NULL)
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

void CProblemaArtificial::SolucaoVazia(void)
{
	TProcuraConstrutiva::SolucaoVazia();
	// acertar as variáveis estáticas, com a instância


	tamanhoCodificado = 1; 
}

// gerar os sucessores de acordo com a instância, de forma aleatória
void CProblemaArtificial::Sucessores(TVector<TNo>&sucessores)
{
	CProblemaArtificial* sucessor;

	// depender de ID do pai, e do seed da instância, bem como restantes parametros

	/*
	if (aspirador > 0) { // esquerda
		sucessores.Add(sucessor = (CProblemaArtificial*)Duplicar());
		sucessor->aspirador--;
	}
	if (aspirador < salas.Count() - 1) { // direita
		sucessores.Add(sucessor = (CProblemaArtificial*)Duplicar());
		sucessor->aspirador++;
	}
	// limpar
	sucessores.Add(sucessor = (CProblemaArtificial*)Duplicar());
	sucessor->salas[aspirador] = '.';
	if (memoriaEsgotada)
		return;*/
	TProcuraConstrutiva::Sucessores(sucessores);
}

void CProblemaArtificial::Debug(void)
{
	NovaLinha();
	printf("%d", estado);
}

bool CProblemaArtificial::SolucaoCompleta(void)
{
	// teste de solução completa
	return true;
}


void CProblemaArtificial::TesteManual(const char* nome)
{
	// definir as instâncias
	instancia = { 4,2,50, NULL, NULL, NULL };
	TProcuraConstrutiva::TesteManual(nome);
}

bool CProblemaArtificial::Distinto(TNo estado) {
	return CProblemaArtificial::estado != ((CProblemaArtificial*)estado)->estado;
}

// o problema artificial, simular heurística com diferentes características:
int CProblemaArtificial::Heuristica(void) {
	
	return 0;
}


// método para lidar com estados repetidos
void CProblemaArtificial::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	int i, index;
	TProcuraConstrutiva::Codifica(estado);
	estado[0] = CProblemaArtificial::estado;
}
