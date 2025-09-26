#pragma once

#include "../TProcuraMelhorativa.h"

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

/**
 * @brief Representa um estado num problema artificial
 *
 * Neste problema um estado é um número inteiro, sendo abstrato. O número poderia representar um estado de um problema real. 
 * Pretende-se atingir estados múltiplos de um dado valor, tipicamente 10 ou 100, ficando os dígitos menos significativos a 0
 * Cada instância define características do espaço de estados como ramificação, nível mímimo em que está a solução, ou
 * mesmo a profundidade máxima. Podemos observar o comportamento dos algoritmos em espaços de cada tipo de características.
 */
class CProblemaArtificial :
	public TProcuraMelhorativa
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
	TPonto Duplicar(void) {
		CProblemaArtificial* clone = new CProblemaArtificial;
		if (clone != NULL)
			clone->Copiar(this);
		else
			memoriaEsgotada = true;
		return clone;
	}

	void Copiar(TPonto objecto) {
		TProcuraMelhorativa::Copiar(objecto);
		id = ((CProblemaArtificial*)objecto)->id;
		nivel = ((CProblemaArtificial*)objecto)->nivel;
		heur = ((CProblemaArtificial*)objecto)->heur;
	}
	void Inicializar(void);
	void Debug(bool completo = true) override;
	void TesteManual(const char* nome);
	bool Distinto(TPonto estado);
	int Heuristica(void);
	void ResetParametros();

private:
	// carrega uma instância, das previamente definidas
	void CarregaInstancia();
};

