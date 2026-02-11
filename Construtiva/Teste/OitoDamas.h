#pragma once
#include "../TProcuraConstrutiva.h"

constexpr int MAX_DAMAS = 40;

/**
 * @brief Representa um estado do problema das 8 damas 
 *
 * Este problema consiste em colocar oito damas de xadrez (movem-se na horizontal, vertical e diagonal), num
 * tabuleiro de xadrez, sem que estas se ataquem umas as outras. 
 * Generalizado para N damas, o ID da instância é o número de damas
 */
class COitoDamas :
	public TProcuraConstrutiva
{
public:
	COitoDamas(void);
	~COitoDamas(void);

	// estrutura de dados: posicao de cada dama
	TVector<int> damas;
	static int nDamas; // número de damas desta instância

	// metodos virtuais redefinidos de TProcuraConstrutiva

	TProcuraConstrutiva* Duplicar(void);
	void Copiar(TProcuraConstrutiva*objecto) {
		TProcuraConstrutiva::Copiar(objecto);
		damas=((COitoDamas*)objecto)->damas;
	}
	void Inicializar(void);
	void Gravar(void);
	void ResetParametros();
	void Sucessores(TVector<TNo>& sucessores);
	bool SolucaoCompleta(void) { return damas.Count() == nDamas; }
	void Debug(bool completo = true) override;
	void MostrarSolucao(void) { Debug(); }
	TString Acao(TProcuraConstrutiva* sucessor);
	void Codifica(uint64_t estado[OBJETO_HASHTABLE]);

private:
	// métodos de normalização de um estado
	void Normalizar(TVector<int>& damas); // coloca em damas o estado normalizado 
	int PesoVersao(int tab[MAX_DAMAS][MAX_DAMAS]); // peso da versão do estado
	void Simetria(int tab[MAX_DAMAS][MAX_DAMAS], int eixo); // aplica uma simetria
	void Troca(int& a, int& b); // troca dois valores
};

