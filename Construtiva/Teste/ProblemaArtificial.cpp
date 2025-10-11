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

TNo CProblemaArtificial::Duplicar(void)
{
	CProblemaArtificial* clone = new CProblemaArtificial;
	if(clone!=NULL)
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

void CProblemaArtificial::Inicializar(void)
{
	// acertar as variáveis estáticas, com a instância
	CarregaInstancia();

	nivel = 0;
	id = 1; 
	heur = 0;

	tamanhoCodificado = 1; 
	TProcuraConstrutiva::Inicializar();
}

// gerar os sucessores de acordo com a instância, de forma aleatória
void CProblemaArtificial::Sucessores(TVector<TNo>&sucessores)
{
	// valores após o nível máximo, são becos sem saída
	if (nivel < espaco.maxNivel) {
		CProblemaArtificial* sucessor;
		int ramificacao;
		// para garantir que a árvore é gerada da mesma forma, a semente aleatória tem de ser reinicializada
		// depende de ID do pai, e do seed da instância
		// utilizar sequência 1 de TRand, para não perturbar sequência aleatória do algoritmo base
		TRand::srand(id ^ (espaco.sementeAleatoria << 8 | espaco.sementeAleatoria), 1);

		if (espaco.maxRamificacao > espaco.minRamificacao)
			ramificacao = TRand::rand(1) % (espaco.maxRamificacao - espaco.minRamificacao) + espaco.minRamificacao;
		else
			ramificacao = espaco.minRamificacao;

		for (int i = 0; i < ramificacao; i++) {
			sucessores += (sucessor = (CProblemaArtificial*)Duplicar());
			sucessor->nivel++;
			// ID tem de ser dependente do pai e da semente, para poder serem gerados os mesmos sucessores,
			//    independente da ordem de expansão que o algoritmo utilizar
			// caso possam ser repetidos globalmente, utilizar o resto da divisão pela quantidade de estados
			// caso possam ser repetidos no mesmo nível, mas não em níveis distintos, 
			//   utilizar o resto da divisão pela quantidade de estados no nível e concatenar o nível
			if (espaco.maxEstadosNivel > 0)
				sucessor->id = sucessor->nivel * espaco.maxEstadosNivel + TRand::rand(1) % espaco.maxEstadosNivel;
			else if (espaco.maxEstados > 0)
				sucessor->id = TRand::rand(1) % espaco.maxEstados;
			else
				sucessor->id = TRand::rand(1);

			// custos
			sucessor->custo = 1 + (espaco.maxCusto > 1 ? TRand::rand(1) % espaco.maxCusto : 0);

			// heuristica
			sucessor->heur = 0; 
		}
	}

	TProcuraConstrutiva::Sucessores(sucessores);
}

// Retorna a ação (movimento, passo, jogada, lance, etc.) que gerou o sucessor
const char* CProblemaArtificial::Acao(TProcuraConstrutiva* sucessor) {
	static char str[256];
	// dado que os estados são aleatórios independentes, colocar na ação o número
	sprintf(str, "a%u", ((CProblemaArtificial*)sucessor)->id);
	return str; 
}

void CProblemaArtificial::Debug(bool completo)
{
	unsigned int idaux = id;
	NovaLinha();
	printf(" ");
	for (int i = 0; i < 4; i++) {
		DebugHSL((idaux & 0xff) * 360.0f / 256.0f);
		printf("%02X",idaux & 0xff);
		idaux >>= 8;
		if (i < 3) {
			DebugHSL();
			printf("-");
		}
	}
	DebugHSL();
}

bool CProblemaArtificial::SolucaoCompleta(void)
{
	// solução completa se o estado estiver num nível compativel, e o resto da divisão por raridadeObjeto for 0
	return (nivel >= espaco.minNivelObjetivo && (id % espaco.objetivo) == 0);
}

void CProblemaArtificial::ResetParametros() 
{
	TProcuraConstrutiva::ResetParametros();
	// ação e estado é o mesmo neste problema artificial, já que um estado muda completamente do pai para o filho
	Parametro(VER_ACOES) = 1; 
	// limitar as iterações, para que a paragem por tempo não ocorra
	Parametro(LIMITE_ITERACOES) = 1000000;

	// definir as instâncias
	instancia = { "Problema", 1,1,10, "Caracteristicas dos problemas", NULL };

}


bool CProblemaArtificial::Distinto(TNo estado) {
	return CProblemaArtificial::id != ((CProblemaArtificial*)estado)->id;
}

// o problema artificial, simular heurística com diferentes características:
int CProblemaArtificial::Heuristica(void) {
	heuristica = heur = 0;
	// utilizar apenas a distância até ao nível mínimo onde pode estar a solução
	if(nivel < espaco.minNivelObjetivo)
		heuristica = heur = espaco.minNivelObjetivo - nivel;
	return TProcuraConstrutiva::Heuristica();
}


// método para lidar com estados repetidos
void CProblemaArtificial::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	TProcuraConstrutiva::Codifica(estado);
	estado[0] = id;
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
