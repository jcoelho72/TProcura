#pragma once

#include "..\TProcuraConstrutiva.h"

///////////////////////////////////////////////////////////////////////////////
//	CProblemaArtificial class
///////////////////////////////////////////////////////////////////////////////
//	Author: Jose Coelho
//	Last revision: 2025-05-12
//	Description:
//    Implementa um problema artificial, para teste da procura construtiva
///////////////////////////////////////////////////////////////////////////////
class CProblemaArtificial :
	public TProcuraConstrutiva
{
public:
	CProblemaArtificial(void);
	~CProblemaArtificial(void);

	// dados da instância
	static int maxRamificacao, minRamificacao; // valores mínimos e máximos para a ramificação
	static int minSolucao, maxSolucao; // valores mínimos e máximos para a localização da solução
	static int raridadeObjetivo; // 1 em raridadeObjetivo estados, serão estados objetivo
	static int maxCusto; // custo máximo de uma ação, mínimo é 1
	static int raridadeRepetidos; // 1 em cada raridadeRepetidos serão estados já gerados anteriormente
	static int raridadeRepetidosNivel; // 1 em cada raridadeRepetidosNivel serão estados já gerados no mesmo nível
	static int seed; // semente aleatória, definindo esta instância (para poder reproduzir a árvore de procura)
	// ver como simular heurísticas: obter o valor ótimo para simular diferentes níveis de informação?

	// estrutura de dados (suficiente um inteiro)
	int estado; // número arbitrário para representar este estado, será o ID do estado, incremental

	// Metodos virtuais redefinidos
	TProcuraConstrutiva* Duplicar(void);
	void Copiar(TProcuraConstrutiva*objecto) {
		estado = ((CProblemaArtificial*)objecto)->estado;
	}
	void SolucaoVazia(void);
	void Sucessores(TVector<TNo>& sucessores);
	bool SolucaoCompleta(void);
	void Debug(void);
	void TesteManual(const char* nome);
	bool Distinto(TNo estado);
	void Codifica(uint64_t estado[OBJETO_HASHTABLE]);
	int Heuristica(void);
};

