#pragma once

#include "../TProcuraMelhorativa.h"
#include "../TCodificacaoBinaria.h"

///////////////////////////////////////////////////////////////////////////////
//	CParticao class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho
//	Last revision: 2025-01-30
//	Description:
//    Implementa o problema da particao. Este problema consiste em dividir
//    um conjunto de numeros naturais em duas partes cuja soma dos numeros em cada
//    parte seja igual.
///////////////////////////////////////////////////////////////////////////////
class CParticao :
	public TProcuraMelhorativa
{
public:
	CParticao(void);
	~CParticao(void);

	// estrutura de dados (números a colocar, números colocados em cada lado, e total de cada lado)
	TVector<int> numeros, esquerda, direita;
	int totalEsquerda, totalDireita;
	TVector<bool> solCompleta; // codificação de uma solução, na abordagem melhoriativa: vetor binário
	// na abordagem melhorativa, assume-se que os números estão em "numeros" e não são deslocados para esquerd/direita

	// Metodos virtuais redefinidos
	TPonto Duplicar(void) {
		CParticao* clone = new CParticao;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}

	void Copiar(TPonto objecto) {
		TProcuraMelhorativa::Copiar(objecto);
		numeros = ((CParticao*)objecto)->numeros;
		esquerda = ((CParticao*)objecto)->esquerda;
		direita = ((CParticao*)objecto)->direita;
		totalEsquerda = ((CParticao*)objecto)->totalEsquerda;
		totalDireita = ((CParticao*)objecto)->totalDireita;
		solCompleta = ((CParticao*)objecto)->solCompleta;
	}
	void Inicializar(void);
	void Debug(void);
	void MostrarSolucao(void) { Debug(); }
	void TesteManual(const char* nome);

	// métodos melhorativos
	void NovaSolucao(void);
	int Avaliar(void);
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);
};

class CParticaoCB :
	public TCodificacaoBinaria
{
public:
	CParticaoCB() {}
	~CParticaoCB() {}

	// dados da instância, em variáveis estáticas
	static TVector<int> numeros; // número de elementos a particionar

	int Avaliar(void);

	void ResetParametros() {
		TCodificacaoBinaria::ResetParametros();
		instancia = { NULL, 10,2,1000, NULL, NULL };
	}

	TPonto Duplicar(void) {
		CParticaoCB* clone = new CParticaoCB;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}
	void Inicializar(void);
	void Debug(void);
};
