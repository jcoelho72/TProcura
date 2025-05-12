#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "TVector.h"
#include <stdint.h>
#include <time.h>
#include <limits.h>

// número de elementos na hashtable com perdas
#define TAMANHO_HASHTABLE 1000000
// tamanho máximo de um objecto, em unidades de 64 bits
#define OBJETO_HASHTABLE 4
// código para número não lido (não deve ser utilizado num parâmetro)
#define NAO_LIDO -1000000

// um nó na árvore de procura é um apontador para um estado, uma solução parcial
class TProcuraConstrutiva;
typedef TProcuraConstrutiva* TNo;

// nomes dos parâmetros fixos na procura construtiva, e outras listas
enum EParametrosConstrutiva { algoritmo = 0, nivelDebug, verAcoes, seed, limiteTempo, limite, estadosRepetidos, 
	pesoAStar, ruidoHeur, baralharSuc, parametrosConstrutivas };
enum EEstadosGerados { ignorados = 1, ascendentes, gerados };
enum EOperacao { gravar = 0, ler };

// estrutura para parâmetros
typedef struct SParametro { 
	int valor, min, max; // valor atual, e mínimo/máximo
	// descritivo, opcionais mas aconselhado nos parâmetros específicos
	const char* nome; // nome do parâmetro
	const char* descricao; // explicação se necessário
	// nome/explicação de cada valor
	const char** nomeValores;
} TParametro;

// resultado de uma corrida, para testes empíricos 
typedef struct SResultado { 
	int instancia, custo, expansoes, geracoes, avaliacoes, configuracao; 
	clock_t tempo; 
} TResultado;


///////////////////////////////////////////////////////////////////////////////
//	TProcuraConstrutiva class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho
//	Last revision: 2025-01-30
//	Description:
//    Superclasse de procuras no espaço das soluções parciais (a solução e construida).
//    Esta classe tem 3 variáveis estruturais, deve criar as variáveis do problema
//    e a implementação dos métodos virtuais para o problema em concreto.
///////////////////////////////////////////////////////////////////////////////
class TProcuraConstrutiva
{
public:
	TProcuraConstrutiva(void);
	virtual ~TProcuraConstrutiva(void) {}

	// variáveis estruturais
	TProcuraConstrutiva* pai; // estado pai na árvore de procura
	int custo; // custo total desde o estado inicial (ou da solução no caso de soluções completas)
	int heuristica; // heurística, estimativa para o estado final, se disponível

	///////////////////////////////////////////////////////////////////////////////
	// Métodos para redefinir conforme o problema
	///////////////////////////////////////////////////////////////////////////////

	// Cria um objecto que é uma cópia deste
	virtual TProcuraConstrutiva* Duplicar(void) = 0;
	// Fica com uma cópia do objecto
	virtual void Copiar(TNo objecto) { }
	// Coloca o objecto no estado inicial da procura
	virtual void SolucaoVazia(void) { custo = 0; }
	// Coloca em sucessores a lista de objectos sucessores (são alocados neste método e têm de ser apagados)
	// Colocar no estado o custo do movimento, se não existir, deixar a 1 (valor de omissão)
	// Chamar o metodo desta classe após adicionar os sucessores para actualizar geracoes e expansoes,
	// bem como por custos totais e verificar a existência de estados repetidos
	virtual void Sucessores(TVector<TNo>& sucessores);
	// Executa uma ação (movimento, passo, jogada, lance, etc.) no estado atual. Caso não seja feito nada, retornar falso.
	virtual bool Acao(const char* acao);
	// Verifica se o estado actual é objectivo, ou seja, a solução parcial é uma solução completa
	virtual bool SolucaoCompleta(void) { return false; }

	// estados repetidos: verificação de ascendentes, é necessário operador de desigualdade
	virtual bool Distinto(TNo estado) { return true; }
	// estados repetidos: verificar todos os gerados
	// implementar para utilizar hashtables com perdas
	// converte o estado atual para a variável estadoHT, utilizando o menor espaço possível
	// caso existam simetrias, normalizar o estado antes de codificar, para considerar exploradas todas as versões
	virtual void Codifica(uint64_t estado[OBJETO_HASHTABLE]);

	// Redefinir para poder utilizar os algoritmos informados
	// Esta função deve devolver o custo estimado por baixo, 
	// desde este estado até ao estado final mais proximo (é um valor minimo),
	// colocando esse valor na variável heuristica
	// chamar este método para actualiacao de avaliacoes
	virtual int Heuristica(void);

	// Escrever informacao de debug sobre o objecto atual
	// (utilizar variavel TProcuraConstrutiva::debug para seleccionar o detalhe pretendido)
	virtual void Debug(void);
	// Retorna a ação (movimento, passo, jogada, lance, etc.) que gerou o sucessor
	virtual const char* Acao(TProcuraConstrutiva* sucessor) { return "ação inválida"; }
	// Mostrar solução, seja um caminho ou o próprio estado
	virtual void MostrarSolucao(void) { MostrarCaminho(); }
	// Método para teste manual (chamadas aos algoritmos, construção de uma solucao manual)
	// Redefinir para colocar parameterização de omissão para um problema específico
	virtual void TesteManual(const char* nome);
	// Verifica se é altura de parar
	virtual bool Parar(void) { return TempoExcedido() || memoriaEsgotada; }
	// Método para inicializar os parâmetros (redefinir se forem inicializados ou adicionados parâmetros)
	virtual void ResetParametros();


	///////////////////////////////////////////////////////////////////////////////
	// Algoritmos de procura cega 
	// Não necessitam da implementacao da funcao heuristica
	///////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////
	// Procura em Largura Primeiro: expande primeiro o estado gerado não expandido mais antigo
	// retorna o valor da solução e coloca o caminho no vector (se calcularCaminho=true), ou -1 caso não encontre solução
	// limite é o número de estados gerados não expandidos, que não pode ultrapassar esse limite
	// os que ultrapassarem são deitados fora (se 0 este limite não importa, podendo haver problemas de memória)
	int LarguraPrimeiro(int limite = 0);

	///////////////////////////////////////////////////////////////////////////////
	// Procura Custo Uniforme: expande primeiro o estado gerado não expandido de menor custo acumulado
	// Idêntico a LarguraPrimeiro()
	int CustoUniforme(int limite = 0);

	///////////////////////////////////////////////////////////////////////////////
	// Procura em Profundidade Primeiro: expande primeiro o estado gerado não expandido mais novo
	// caso o nivel=-1, e feita uma procura em profunidade normal, não limitada
	// caso o nivel>0, e feita uma procura em profundidade limitada
	// caso o nivel=0, e feita uma procura em profundidade iterativa, sem limite
	// implementada a versão recursiva deste algoritmo
	int ProfundidadePrimeiro(int nivel = 0);

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmos de procura informados 
	// Necessitam da implementação da função Heuristica
	///////////////////////////////////////////////////////////////////////////////

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmo Melhor Primeiro: expande primeiro o estado gerado não expandido com melhor heurística
	// versão recursiva, idêntico a ProcuraPrimeiro()
	int MelhorPrimeiro(int nivel = 0);

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmo AStar: expande primeiro o estado gerado não expandido com melhor custo+heurística
	// Idêntico a CustoUniforme()
	int AStar(int limite = 0);

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmo IDAStar: procura em profundidade iterativa, limitada a um upperBound
	// idêntico a MelhorPrimeiro() mas cortando quando upperBound já não consegue ser obtido 
	int IDAStar(int upperBound = 0);

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmo BranchAndBound: 
	// idêntico a MelhorPrimeiro(), mas continua após a primeira solução
	// explorando apenas os estados em que f(n) < atual solução (LB<UB)
	// recebe a melhor solução até ao momento, upperBound, ou 0 caso não exista
	int BranchAndBound(int upperBound = 0);

	// utilizar para executar testes empíricos, utilizando todas as instâncias,
	// Utiliza as configurações existentes, ou parâmetros atuais
	virtual void TesteEmpirico(int inicio = -1, int fim = -1, bool mostrarSolucoes = true);

	///////////////////////////////////////////////////////////////////////////////
	// Variaveis globais a classe. Estas variaveis são reutilizadas para cada corrida.
	// O facto de serem globais evita que sejam copiadas vezes sem sentido, mas impede que
	// se possa fazer mais que uma corrida em simultaneo.
	///////////////////////////////////////////////////////////////////////////////

	// numero de geracaes de estados
	static int geracoes;
	// numero de expansoes de estados
	static int expansoes;
	// numero de chamadas a funcao heuristica
	static int avaliacoes;
	// auxiliar para construcao da arvore de procura
	static TVector<unsigned char> ramo;
	// espacamento entre ramos da arvore de debug
	static int espacosRamo;
	// valor retornado pela procura (tem de ser libertado)
	static TVector<TNo> caminho;
	// deadline da corrida atual
	static clock_t instanteFinal;
	// flag de problemas de memória esgotada
	static bool memoriaEsgotada;
	// valor retornado pela procura (tem de ser libertado)
	static TNo solucao;
	// lowerBound: valor mínimo que a solução pode obter
	static int lowerBound;
	// tamanho em inteiros de 64 bits de um objeto (inferior ou igual a OBJETO_HASHTABLE)
	static int tamanhoCodificado;

	// Parâmetros globais
	// ID da instância atual (problemas com várias instâncias, a utilizar em SolucaoVazia())
	static TParametro instancia;
	static TVector<TParametro> parametro; // adicionar parâmetros específicos 
	static TVector<TVector<int>> configuracoes; // conjuntos de valores de parâmetros, para teste

	// LimparEstatisticas: Chamar antes da corrida
	void LimparEstatisticas(clock_t &inicio);
	// FinalizarCorrida: Chamar após a corrida
	void FinalizarCorrida(clock_t inicio);

	int LowerBound() { return custo + parametro[pesoAStar].valor * heuristica / 100; } // f(n) = g(n) + W h(n)
	static void LibertarVector(TVector<TNo>& vector, int excepto = -1, int maiorQue = -1);

protected:

	// Métodos para visualizar a procura

	// Método para ser chamado antes de analisar cada sucessor
	void DebugExpansao(int sucessor, int sucessores, bool duplo = false);
	// Método para ser chamado quando não há sucessores ou há um corte de profundidade
	void DebugCorte(int sucessores = -1, bool duplo = false);
	// Encontrou uma solução
	void DebugSolucao(bool continuar = false);
	// Informação de debug na chamada ao método recursivo
	void DebugChamada(void);
	// Chamar sempre que se quer uma nova linha com a árvore em baixo
	void NovaLinha(bool tudo = true);
	// Passo no algoritmo em largura
	void DebugPasso(void);
	// Mostrar sucessores
	void DebugSucessores(TVector<TNo>& sucessores);
	// uma nova iteração de um algoritmo iterativo
	void DebugIteracao(int iteracao);
	// informação geral sobre o estado 
	void DebugEstado(int id = -1, int pai = -1);
	void DebugRamo(char ramo, char folha);

	// metodos internos
	int ObjetivoAlcancado(int item, TVector<TNo>& lista);
	int ObjetivoAlcancado(TNo estado, bool completa = true);
	int SolucaoEncontrada(bool continuar = false);
	void CalculaCaminho(bool completa = true); // coloca o caminho desde o estado objetivo
	void VerificaLimites(int limite, int porProcessar, TVector<TNo>& sucessores);
	void CalcularHeuristicas(TVector<TNo>& sucessores, TVector<int>* id = NULL, bool sortLB = false);
	int SolucaoParcial(int i, TVector<TNo>& sucessores);
	int NovoValor(const char* prompt); // ler um número, ou retorna NAO_LIDO
	void ExplorarSucessores(bool jogo=false);
	void EditarParametros();
	void EditarConfiguracoes();
	void MostrarConfiguracoes(int detalhe, int atual = -1);
	void SolicitaInstancia();
	bool TempoExcedido() { return instanteFinal < clock(); }
	void MostrarCaminho();
	void MostraParametros(int detalhe = 1);
	void MostraRelatorio(TVector<TResultado>& resultados);
	int Dominio(int& variavel, int min = INT_MIN, int max = INT_MAX);
	virtual int ExecutaAlgoritmo();
	void ConfiguracaoAtual(TVector<int>& parametros, int operacao); // gravar (ou ler) a configuração atual
	int MelhorResultado(TResultado base, TResultado alternativa);
	void CalculaTorneio(TVector<TResultado>& resultados);
	void MostrarTorneio(TVector<TVector<int>>& torneio, bool jogo=false);
	void BarraTorneio(bool nomes);
	void ExtrairConfiguracao(TVector<TResultado>& resultados, TVector<TResultado>& extracao, int configuracao);

	// variáveis da hashtable com perdas, se existir uma colisão, substitui
	static uint64_t elementosHT[TAMANHO_HASHTABLE][OBJETO_HASHTABLE]; // hashtable
	static int custoHT[TAMANHO_HASHTABLE]; // hashtable / custo do estado que foi gerado
	static uint64_t estadoCodHT[OBJETO_HASHTABLE]; // elemento codificado
	unsigned int Hash(); // retorna um valor hash do estado atual, após codificado
	void LimparHT();
	// caso o estado não exista, retorna falso e insere para que não seja gerado novamente
	// caso exista um elemento, mas gerado com um custo mais alto, considerar que não existe ainda
	// se existe retorna true 
	bool ExisteHT();
	virtual void SubstituirHT(int indice);
};

// estrutura para índice a fazer a função de lista (em vetor), de modo a reduzir custos de inserção ordenada 
// utilizado em CListaNo
typedef struct SIndice {
	TNo estado; // elemento na lista
	int prox; // próximo elemento da lista, pela ordem mantida (de custo)
	int proxDistinto; // próximo elemento da lista com custo distinto
} TIndice;

// classe para manter lista ordenada de estados (CustoUniforme e AStar)
class CListaNo {
private:
	int limite; // tamanho da lista, se !=0 --- tamanho vai até ao dobro, após o qual é limpa para metade dos elementos
	TVector<TIndice> indice; // índice com a estrutura de lista
	TVector<int> livre; // índices da lista apagados, que estão livres e podem ser utilizados
	bool completa; // se verdade, nunca foi limpa, pelo que a lista é completa
public:
	CListaNo(int limite = 0) : 
		limite(limite), 
		indice(2*limite), 
		livre(limite), 
		completa(true), 
		atual(0) {}
	~CListaNo();

	// elemento a ser processado 
	// (anteriores a este, excepto o primeiro, podem ser apagados, quando há falta de espaço)
	int atual; 

	bool Completa() { return completa; }

	// retorna o valor de um elemento
	int Valor(int i) {
		TNo estado;
		if ((estado = Estado(i)) != NULL)
			return estado->LowerBound();
		return INT_MAX;
	}

	// retorna o próximo elemento, ou -1 se não há mais
	int Proximo(int i = -1) { 
		if (i < 0)
			return indice[atual].prox;
		if(i>=0 && i<indice.Count())
			return indice[i].prox; 
		return -1;
	}
	// este passo é crítico para poder inserir rapido numa lista ordenada com muitos elementos iguais
	int ProximoDistinto(int i = -1) {
		if (i < 0)
			return indice[atual].proxDistinto;
		if (i >= 0 && i < indice.Count())
			return indice[i].proxDistinto;
		return -1;
	}
	// retorna o estado deste elemento
	TNo Estado(int i = -1) {
		if (i < 0)
			return indice[atual].estado;
		if (i >= 0 && i < indice.Count())
			return indice[i].estado;
		return NULL;
	}
	
	int Inserir(TNo elemento, int id = 0); // insere por ordem de LB, retorna o primeiro elemento com o mesmo valor
	void Inserir(TVector<TNo>& elementos); // inserir todos os elementos por ordem (não alterar atual)

private:
	int NovoElemento(TNo elemento); // retorna o índice onde foi inserido
	void LibertarLista();
	void LibertarSeguinte(int id);

};