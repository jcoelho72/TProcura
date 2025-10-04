#pragma once
#include "TProcuraMelhorativa.h"

// nomes dos parâmetros fixos na codificação binária
enum ECodificacaoBinaria {
	TIPO_CRUZAR_CB = PARAMETROS_MELHORATIVA, 
	TIPO_MUTAR_CB, TIPO_VIZINHO_CB, PARAMETROS_CB
};

// classe para permitir referência a um bit, para leitura e escrita 
class BitRef {
	uint64_t& word;
	uint64_t mask;
public:
	BitRef(uint64_t& w, uint64_t m) : word(w), mask(m) {}
	// conversão para leitura
	operator bool() const { return (word & mask) != 0; }
	// atribuição para escrita
	BitRef& operator=(bool v) {
		if (v) word |= mask;
		else   word &= ~mask;
		return *this;
	}
	// atribuição de outro BitRef
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

	TVector<uint64_t> estado; // codificação binária (em números de 64 bits)
	static int nElementos; // número de elementos binários na codificação

	// troca o bit i
	void Troca(int i) { estado[i >> 6] ^= ((uint64_t)1 << (i & 63)); }
	// acesso a um bit para atribuir 
	BitRef Bit(int i) { return BitRef(estado[i >> 6], uint64_t(1) << (i & 63)); }
	// acesso a um bit para ler
	bool Bit(int i) const { return (estado[i >> 6] & ((uint64_t)1 << (i & 63))) != 0; }

	// métodos necessários redefinir
	TPonto Duplicar(void) = 0;
	int Avaliar(void) = 0;

	// deve carregar a instância, para variáveis estáticas, da subclasse
	// definir valores globais: nElementos
	void Inicializar(void)=0;

	// métodos que podem ser redefinidos
	void Debug(bool completo = true) override;

	// métodos que não se prevê que sejam redefinidos
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

