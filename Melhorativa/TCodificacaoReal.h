#pragma once
#include "TProcuraMelhorativa.h"
class TCodificacaoReal :
    public TProcuraMelhorativa
{
public:
	TCodificacaoReal() {}
	~TCodificacaoReal() {}

	TVector<double> estado; // codificação real
	static int nElementos; // número de elementos no estado
	static TVector<double> minValor, maxValor; // valores mínimo e máximo para cada elemento, se vazios, o domínio é de 0 a 1

	// métodos necessários redefinir
	int Avaliar(void) = 0;

	// deve carregar a instância, para variáveis estáticas, da subclasse
	// definir valores globais: nElementos, minValor, maxValor
	void Inicializar(void)=0;

	// métodos que podem ser redefinidos
	void Debug(bool completo = true) override;


	// métodos que não se prevê que sejam redefinidos
	TPonto Duplicar(void);
	void Copiar(TPonto objecto);
	void NovaSolucao(void);
	bool Acao(const char* acao);
	void ResetParametros();
	// operadores melhorativos
	void Vizinhanca(TVector<TPonto>& vizinhos);
	void Mutar(void);
	void Cruzamento(TPonto a, TPonto b);

	using TProcura::Debug;
};

