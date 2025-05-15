#pragma once

#include "../TProcuraConstrutiva.h"

// estrutura para caracterização do espaço de procura
typedef struct SParametrosEspaco {
	int minRamificacao, maxRamificacao; // valores mínimos e máximos para a ramificação
	int minNivelObjetivo; // valor mínimo do nível para um estado poder ser objetivo
	int maxNivel; // valor máximo de nível de um estado (se atingido, não gera sucessores)
	int objetivo; // se ID módulo objetivo for nulo, e o nível mínimo for respeitado, o estado é objetivo
	int maxCusto; // custo máximo de uma ação, mínimo é 1
	int maxEstados; // os IDs dos estados ficam em módulo de maxEstados, de modo a poderem ser repetidos (0 não repete)
	int maxEstadosNivel; // IDs dos estados ficam em módulo de maxEstadosNivel, concatenado com o nível para não haver colisões entre níveis (0 não repete)
	unsigned int sementeAleatoria; // semente aleatória, definindo esta instância (para poder reproduzir a árvore de procura)
	// procurar ver como simular heurísticas: 
	// - na geração do custo dos filhos, ter atenção para não contradizer a heurística do pai
	// - o valor aleatório poderia ser a percentagem entre 0 e o valor da heurística perfeita
	// - no entanto não é possível na geração do pai saber sequer se um filho será solução
	//   nesse caso a heurística não pode ultrapassar o custo desse filho
} TParametrosEspaco;


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
	static TParametrosEspaco espaco;

	// estrutura de dados (suficiente um inteiro)
	unsigned int id; // número arbitrário para representar este estado, será o ID do estado, gerado aleatóriamente
	int nivel; // nível a que o estado foi gerado
	int heur; // valor gerado para a heurística, conforme os parâmetros da instância

	// Metodos virtuais redefinidos
	TProcuraConstrutiva* Duplicar(void);
	void Copiar(TNo objecto) {
		CProblemaArtificial& obj = *((CProblemaArtificial*)objecto);
		id = obj.id;
		nivel = obj.nivel;
		heur = obj.heur;
	}
	void SolucaoVazia(void);
	void Sucessores(TVector<TNo>& sucessores);
	bool SolucaoCompleta(void);
	void Debug(void);
	void TesteManual(const char* nome);
	bool Distinto(TNo estado);
	void Codifica(uint64_t estado[OBJETO_HASHTABLE]);
	int Heuristica(void);
	void ResetParametros();

	const char* Acao(TProcuraConstrutiva* sucessor);


private:
	// carrega uma instância, das previamente definidas
	void CarregaInstancia();
};

