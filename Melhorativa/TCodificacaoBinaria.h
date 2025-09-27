#pragma once
#include "TProcuraMelhorativa.h"

// nomes dos par�metros fixos na codifica��o bin�ria
enum ECodificacaoBinaria {
	TIPO_CRUZAR_CB = PARAMETROS_MELHORATIVA, 
	TIPO_MUTAR_CB, TIPO_VIZINHO_CB, PARAMETROS_CB
};

// classe para permitir refer�ncia a um bit, para leitura e escrita
class BitRef {
	uint64_t& word;
	uint64_t mask;
public:
	BitRef(uint64_t& w, uint64_t m) : word(w), mask(m) {}
	// convers�o para leitura
	operator bool() const { return (word & mask) != 0; }
	// atribui��o para escrita
	BitRef& operator=(bool v) {
		if (v) word |= mask;
		else   word &= ~mask;
		return *this;
	}
	// atribui��o de outro BitRef
	BitRef& operator=(const BitRef& other) {
		return *this = bool(other); // reutiliza o operador=(bool)
	}
};


class TCodificacaoBinaria :
    public TProcuraMelhorativa
{
public:
	TCodificacaoBinaria() {}
	~TCodificacaoBinaria() {}

	TVector<uint64_t> estado; // codifica��o bin�ria (em n�meros de 64 bits)
	static int nElementos; // n�mero de elementos bin�rios na codifica��o

	// troca o bit i
	void Troca(int i) { estado[i >> 6] ^= ((uint64_t)1 << (i & 63)); }
	// acesso a um bit para atribuir 
	BitRef Bit(int i) { return BitRef(estado[i >> 6], uint64_t(1) << (i & 63)); }
	// acesso a um bit para ler
	bool Bit(int i) const { return (estado[i >> 6] & ((uint64_t)1 << (i & 63))) != 0; }

	// m�todos necess�rios redefinir
	TPonto Duplicar(void) = 0;
	int Avaliar(void) = 0;

	// deve carregar a inst�ncia, para vari�veis est�ticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void)=0;

	// m�todos que podem ser redefinidos
	void Debug(bool completo = true) override;

	// m�todos que n�o se prev� que sejam redefinidos
	void Copiar(TPonto objecto);
	void NovaSolucao(void);
	void ResetParametros();
	// operadores melhorativos
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);
	int Distancia(TPonto a);

	using TProcura::Debug;
};

