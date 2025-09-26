#include "ProblemaArtificial.h"
#include <stdio.h>
#include <string.h>


TParametrosEspaco CProblemaArtificial::espaco;

CProblemaArtificial::CProblemaArtificial(void) 
{
}

CProblemaArtificial::~CProblemaArtificial(void)
{
}

void CProblemaArtificial::Inicializar(void)
{
	TProcuraMelhorativa::Inicializar();
	// acertar as variáveis estáticas, com a instância
	CarregaInstancia();

	nivel = 0;
	id = 1; 
	heur = 0;
}


void CProblemaArtificial::Debug(bool completo)
{
	printf("\n--<([%u])>--", id);
}


void CProblemaArtificial::TesteManual(const char* nome)
{
	// definir as instâncias
	instancia = { "Problema", 1,1,10, "Caracteristicas dos problemas", NULL };
	TProcuraMelhorativa::TesteManual(nome);
}

void CProblemaArtificial::ResetParametros() 
{
	TProcuraMelhorativa::ResetParametros();
	// limitar as iterações, para que a paragem por tempo não ocorra
	Parametro(LIMITE_ITERACOES) = 1000000;
}

bool CProblemaArtificial::Distinto(TPonto estado) {
	return CProblemaArtificial::id != ((CProblemaArtificial*)estado)->id;
}

/*
TParametrosEspaco:
int minRamificacao, maxRamificacao; // valores mínimos e máximos para a ramificação
int minNivelObjetivo; // valor mínimo do nível para um estado poder ser objetivo
int maxNivel; // valor máximo de nível de um estado (se atingido, não gera sucessores)
int objetivo; // se ID módulo objetivo for nulo, e o nível mínimo for respeitado, o estado é objetivo
int maxCusto; // custo máximo de uma ação, mínimo é 1
int maxEstados; // os IDs dos estados ficam em módulo de maxEstados, de modo a poderem ser repetidos (0 não repete)
int maxEstadosNivel; // IDs dos estados ficam em módulo de maxEstadosNivel, concatenado com o nível para não haver colisões entre níveis (0 não repete)
unsigned int sementeAleatoria; // semente aleatória, definindo esta instância (para poder reproduzir a árvore de procura)
*/
void CProblemaArtificial::CarregaInstancia() {
	TParametrosEspaco instancias[] = {
		{2,2,4,5,10,1,0,0,1}, // pequena instância, ramificação baixa, profundidade baixa, objetivo 1 em 10 (termina em 0)
		{4,4,1,6,10,1,100,0,2}, // ramificação média, estados máximos 100 (repetem-se, resto da divisão por 100). minNivelObjetivo tem de ser 1 sempre que maxEstados>0
		{6,6,5,7,10,1,0,100,3}, // estados máximos em cada nível 100 (repetem-se, resto da divisão por 100, mas sem colisões entre níveis)
		{1,4,4,7,10,10,0,0,4}, // custos não unitários (até 10), ramificação variável baixa
		{1,4,20,20,100,2,0,0,5}, // profundidade média, solução no último nível apenas, custos variáveis mas menos, objetivo 1 em 100 (termina em 00)
		{1,4,1,20,100,2,10000,0,6}, // máximo número de estados 10K (minNivelObjetivo tem de ser 1 sempre que maxEstados>0)
		{1,4,20,20,100,2,0,1000,7}, // máximo número de estados num nível 1K
		{10,20,10,20,100,1,0,0,8}, // ramificação média, profundidade média, solução variável, custo fixo
		{10,20,1,20,100,1,10000,0,9}, // máximo número de estados 10K (minNivelObjetivo tem de ser 1 sempre que maxEstados>0)
		{20,100,40,60,100,2,0,0,10}, // ramificação elevada, profundidade elevada, 
	};

	espaco = instancias[instancia.valor - 1];
}
