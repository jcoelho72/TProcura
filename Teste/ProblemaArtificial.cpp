#include "ProblemaArtificial.h"
#include <stdio.h>
#include <string.h>

// valores mínimos e máximos para a ramificação
int CProblemaArtificial::maxRamificacao;
int CProblemaArtificial::minRamificacao;
// valores mínimos e máximos para a localização da solução
int CProblemaArtificial::minObjetivo;
int CProblemaArtificial::maxObjetivo;
// 1 em raridadeObjetivo estados, serão estados objetivo
int CProblemaArtificial::raridadeObjetivo;
// custo máximo de uma ação, mínimo é 1
int CProblemaArtificial::maxCusto;
// 1 em cada raridadeRepetidos serão estados já gerados anteriormente
int CProblemaArtificial::raridadeRepetidos;
// 1 em cada raridadeRepetidosNivel serão estados já gerados no mesmo nível
int CProblemaArtificial::raridadeRepetidosNivel;
// semente aleatória, definindo esta instância (para poder reproduzir a árvore de procura)
int CProblemaArtificial::seed;


CProblemaArtificial::CProblemaArtificial(void) 
{
}

CProblemaArtificial::~CProblemaArtificial(void)
{
}

TProcuraConstrutiva* CProblemaArtificial::Duplicar(void)
{
	CProblemaArtificial* clone = new CProblemaArtificial;
	if(clone!=NULL)
		clone->Copiar(this);
	else
		memoriaEsgotada = true;
	return clone;
}

void CProblemaArtificial::SolucaoVazia(void)
{
	TProcuraConstrutiva::SolucaoVazia();
	// acertar as variáveis estáticas, com a instância
	CarregaInstancia();

	nivel = 0;
	id = 1; // não pode ser 0

	tamanhoCodificado = 1; 
}

// gerar os sucessores de acordo com a instância, de forma aleatória
void CProblemaArtificial::Sucessores(TVector<TNo>&sucessores)
{
	CProblemaArtificial* sucessor;
	int ramificacao;

	// valores após o nível máximo, são becos sem saída
	if (nivel < maxObjetivo) {
		// para garantir que a árvore é gerada da mesma forma, a semente aleatória tem de ser reinicializada
		// depende de ID do pai, e do seed da instância
		// não utilizar TRand, para não perturbar sequência aleatória do algoritmo
		srand(id ^ (seed << 32));

		if (maxRamificacao > minRamificacao)
			ramificacao = rand() % (maxRamificacao - minRamificacao) + minRamificacao;
		else
			ramificacao = minRamificacao;

		for (int i = 0; i < ramificacao; i++) {
			sucessores.Add(sucessor = (CProblemaArtificial*)Duplicar());
			sucessor->nivel++;
			// ID tem de ser dependente do pai e da semente, para poder ser o mesmo em qualquer altura
			sucessor->id = rand();
			// ver custos
			if (maxCusto > 1) 
				sucessor->custo = 1 + rand() % maxCusto;
			// trocar o ID para ser igual a um já gerado, mediante uma probabilidade
		}
	}

	TProcuraConstrutiva::Sucessores(sucessores);
}

// Retorna a ação (movimento, passo, jogada, lance, etc.) que gerou o sucessor
const char* CProblemaArtificial::Acao(TProcuraConstrutiva* sucessor) {
	static char str[256];
	// dado que os estados são aleatórios independentes, colocar na ação o número
	sprintf(str, "%u", ((CProblemaArtificial*)sucessor)->id);
	return str; 
}


void CProblemaArtificial::Debug(void)
{
	NovaLinha();
	printf("[%u]", id);
}

bool CProblemaArtificial::SolucaoCompleta(void)
{
	// solução completa se o estado estiver num nível compativel, e o resto da divisão por raridadeObjeto for 0
	return (nivel >= minObjetivo && nivel <= maxObjetivo && (id % raridadeObjetivo) == 0); 
}


void CProblemaArtificial::TesteManual(const char* nome)
{
	// definir as instâncias
	instancia = { 1,1,10, "Problema", "Caracteristicas dos problemas", NULL };
	TProcuraConstrutiva::TesteManual(nome);
}

void CProblemaArtificial::ResetParametros() 
{
	TProcuraConstrutiva::ResetParametros();
	// ação e estado é o mesmo neste problema artificial, já que um estado muda completamente do pai para o filho
	parametro[verAcoes].valor = 1; 
}


bool CProblemaArtificial::Distinto(TNo estado) {
	return CProblemaArtificial::id != ((CProblemaArtificial*)estado)->id;
}

// o problema artificial, simular heurística com diferentes características:
int CProblemaArtificial::Heuristica(void) {
	
	return 0;
}


// método para lidar com estados repetidos
void CProblemaArtificial::Codifica(uint64_t estado[OBJETO_HASHTABLE])
{
	int i, index;
	TProcuraConstrutiva::Codifica(estado);
	estado[0] = id ^ (nivel << 32);
}

void CProblemaArtificial::CarregaInstancia() {
	switch (instancia.valor) {
	case 1: // pequena instância, ramificação baixa 
		maxRamificacao = minRamificacao = 2;
		minObjetivo = 4;
		maxObjetivo = 5;
		raridadeObjetivo = 10;
		maxCusto = 1;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 2;
		break;
	case 2: // custos não unitários, ramificação variável
		minRamificacao = 1;
		maxRamificacao = 3;
		minObjetivo = 4;
		maxObjetivo = 7;
		raridadeObjetivo = 10;
		maxCusto = 10;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 3;
		break;
	case 3: // profundidade elevada, solução a nível fixo
		minRamificacao = 1;
		maxRamificacao = 3;
		minObjetivo = 20;
		maxObjetivo = 20;
		raridadeObjetivo = 10;
		maxCusto = 10;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 4;
		break;
	case 4: // ramificação média, profundidade média
		minRamificacao = 10;
		maxRamificacao = 20;
		minObjetivo = 10;
		maxObjetivo = 20;
		raridadeObjetivo = 10;
		maxCusto = 10;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 5;
		break;
	case 5: // ramificação elevada, profundidade elevada
		minRamificacao = 20;
		maxRamificacao = 100;
		minObjetivo = 40;
		maxObjetivo = 60;
		raridadeObjetivo = 10;
		maxCusto = 1;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 6;
		break;
	case 6: // pequena instância, ramificação baixa, raridade alta
		maxRamificacao = minRamificacao = 2;
		minObjetivo = 4;
		maxObjetivo = 5;
		raridadeObjetivo = 100;
		maxCusto = 1;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 7;
		break;
	case 7: // custos não unitários, ramificação variável, raridade alta
		minRamificacao = 1;
		maxRamificacao = 3;
		minObjetivo = 4;
		maxObjetivo = 7;
		raridadeObjetivo = 100;
		maxCusto = 10;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 8;
		break;
	case 8: // profundidade elevada, solução a nível fixo, raridade alta
		minRamificacao = 1;
		maxRamificacao = 3;
		minObjetivo = 20;
		maxObjetivo = 20;
		raridadeObjetivo = 100;
		maxCusto = 10;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 9;
		break;
	case 9: // ramificação média, profundidade média, raridade alta
		minRamificacao = 10;
		maxRamificacao = 20;
		minObjetivo = 10;
		maxObjetivo = 20;
		raridadeObjetivo = 100;
		maxCusto = 10;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 10;
		break;
	case 10: // ramificação elevada, profundidade elevada, raridade alta
		minRamificacao = 20;
		maxRamificacao = 100;
		minObjetivo = 40;
		maxObjetivo = 60;
		raridadeObjetivo = 100;
		maxCusto = 1;
		raridadeRepetidos = 0;
		raridadeRepetidosNivel = 0;
		seed = 11;
		break;
	}
}
