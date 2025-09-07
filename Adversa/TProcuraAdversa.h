#pragma once
#include "../Construtiva/TProcuraConstrutiva.h"

/**
* @enum EParametrosAdversa
* @brief Identifica um parâmetro específico no código.
*
* Permite aceder a cada parâmetro sem precisar saber seu código numérico.
* Esta enumeração continua de EParametrosConstrutiva
* 
* @see EParametrosConstrutiva
*
*/	
enum EParametrosAdversa { 
	ordenarSucessores = parametrosConstrutivas, ///< opção de ordenar sucessores por heurística, ou por último valor registado
	podaHeuristica,      ///< permite cortar sucessores, mas calcula a heurística a todos, de modo a mantendo os melhores
	podaCega,		     ///< corta os sucessores, mesmo sem calcular a heurística, por ordem aleatória
	parametrosAdversas   ///< marcador para permitir a extensão do enum em subclasses.
};

/**
* @brief tipo de valor resultante do minimax com cortes alfa/beta
*/
enum ETipoValor { 
	exato,      ///< o valor foi calculado sem cortes, ou seja, não sofreu influência de alfa ou beta;
	lowerbound, ///< o valor foi afetado por um corte de beta (ou seja, ele é pelo menos esse valor, mas pode ser maior);
	upperbound  ///< o valor foi afetado por um corte de alfa (ou seja, ele é no máximo esse valor, mas pode ser menor).
};

/**
 * @brief registo do valor de um estado, em procuras anteriores 
 */
typedef struct SValorEstado {
	int valor;
	int nivel; // 0 - valor heurístico, -1 - inválido
	ETipoValor tipo; 
} TValorEstado;

/**
 * @brief Representa um estado no espaço de estados. 
 *
 * Esta classe base deve ser redefinida com um problema concreto,
 * permitindo a execução de procuras adversas.
 */
class TProcuraAdversa :
	public TProcuraConstrutiva
{
public:
	TProcuraAdversa(void);
	~TProcuraAdversa(void);

	/// @brief o jogador actual deve minimizar o custo (ou maximizar caso tenha o valor falso)
	bool minimizar;
	/// @brief valor de infinito (vitoria/derrota), omissao 1000
	static int infinito;
	/// @brief controlo para indicar se a procura foi realizada de forma completa (c.c. foi cortada)
	static bool completo;
	/// @brief profundidade máxima no método iterativo
	static int nivelOK;


	/// @brief Método para inicializar os parâmetros (redefinir se forem adicionados parâmetros específicos)
	void ResetParametros();

	/// @brief retorna o valor do estado actual, apos procura de profundidade nivel
	int MiniMax(int nivel = 4);

	/// @brief retorna o valor do estado actual, apos procura de profundidade nivel. Idêntico a MiniMax
	int MiniMaxAlfaBeta(int nivel = 4, int alfa = -infinito, int beta = +infinito);

	// Utilizar para executar testes empíricos
	// Utiliza as configurações existentes, ou parâmetros atuais
	// Efetua um torneio entre configurações
	void TesteEmpirico(TVector<int> instancias, bool mostrarSolucoes = true, char* ficheiro = NULL);

	/// @brief Executa o algoritmo com os parametros atuais
	int ExecutaAlgoritmo();

	/// @brief chamar após calcular a heurística (grava o valor, dependendo da parametrização)
	int Heuristica(void);

	// @brief chamar em CSubProblema::Heuristica() para verificar se a heurística já existe, ou precisa de ser calculada
	bool ExisteHeuritica(void);


	/**
	 * @brief Utilitário para calculo de uma heurística standard em jogos simples
	 *
	 * calcular o número de ameaças de vitória, para cada lado, de menor comprimento:
	 * - qMin - vetor com número de ameaças (1 ou mais) a 1 jogada (na primeira posição), a 2 (na segunda posição), e assim sucessivamente; 
	 * - qMax - vetor com número de ameaças (1 ou mais) a 1 jogada (na primeira posição), a 2 (na segunda posição), e assim sucessivamente; 
	 */
	int MaiorAmeaca(TVector<int>& qMin, TVector<int>& qMax, int maxAmeaca);

protected:
	/// @brief fim da procura, por corte de nível (ou não haver sucessores), retornar heurística
	int NoFolha(bool nivel); 

	/// @brief  verifica se há um corte alfa/beta, atualizando alfa e beta
	bool CorteAlfaBeta(int valor, int& alfa, int& beta);

	/// @brief  iteração, aumentando o nível progressivamente
	int MetodoIterativo(int alfaBeta);

	/**
	 * @brief Gera um relatório CSV com os resultados.
	 * @param resultados Vetor de resultados.
	 * @param f Ponteiro para o ficheiro onde gravar.
	 */
	void RelatorioCSV(TVector<TVector<int>>& torneio, FILE* f);

	void OrdenarSucessores(TVector<TNo>& sucessores, TVector<int>& id, int nivel);

	// hashtable
	void SubstituirHT(int indice); // necessário redefinir para invalidar valorHT 
	bool ExisteHT(); // necessário redefinir par não remover estados (reutilizar o valor)
	static TValorEstado valorHT[TAMANHO_HASHTABLE]; // hashtable / valor e nível obtido
	// índice obtido na HT, se positivo
	int indiceHT;
	/// @brief ler ou gravar o melhor valor conhecido
	bool ValorEstado(TValorEstado& valor, int operacao);
	/// @brief ver se o valor obtido é utilizável no contexto atual
	bool Utilizavel(TValorEstado& valor, int nivel, int alfa, int beta);

	static int reutilizadoAvaliacao; // número de vezes que uma avaliação é reutilizada
};
