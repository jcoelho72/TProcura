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
	ORDENAR_SUCESSORES = PARAMETROS_CONSTRUTIVA, ///< opção de ordenar sucessores por heurística, ou por último valor registado
	PODA_HEURISTICA,      ///< permite cortar sucessores, mas calcula a heurística a todos, de modo a mantendo os melhores
	PODA_CEGA,		     ///< corta os sucessores, mesmo sem calcular a heurística, por ordem aleatória
	HEUR_BASE,		     ///< valor base para diferença entre ameaças de K e K-1 (100 não há diferença, 200 é o valor de omissão)
	PARAMETROS_ADVERSA   ///< marcador para permitir a extensão do enum em subclasses.
};

/**
* @brief tipo de valor resultante do minimax com cortes alfa/beta
*/
enum ETipoValor {
	EXATO,      ///< o valor foi calculado sem cortes, ou seja, não sofreu influência de alfa ou beta;
	LOWER_BOUND, ///< o valor foi afetado por um corte de beta (ou seja, ele é pelo menos esse valor, mas pode ser maior);
	UPPER_BOUND  ///< o valor foi afetado por um corte de alfa (ou seja, ele é no máximo esse valor, mas pode ser menor).
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
 * @brief registo do valor de um estado, em procuras anteriores
 */
typedef struct SResultadoJogo {
	int instancia = 0; // no caso no jogo ter instâncias
	int brancas = 0; // configuração a jogar de brancas
	int pretas = 0; // configuração a jogar de pretas
	int resultado = 0; // -1 derrota, 0 empate, 1 vitória
	int nJogadas = 0; // número de jogadas efetuadas
	double tempoBrancas = 0.0; // tempo total de jogo das brancas
	double tempoPretas = 0.0; // tempo total de jogo das pretas
	char *jogo = NULL; // todos os lances do jogo
} TResultadoJogo;


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
	void TesteEmpirico(TVector<int> instancias, const char* ficheiro = NULL);
	/// @brief Teste empírico com modo mestre-escravo (este é o mestre)
	void TesteEmpiricoGestor(TVector<int> instancias, const char* ficheiro = NULL);
	/// @brief Teste empírico com modo mestre-escravo (este é o escravo)
	void TesteEmpiricoTrabalhador(TVector<int> instancias, const char* ficheiro = NULL);


	/// @brief Executa o algoritmo com os parametros atuais
	int ExecutaAlgoritmo();

	/// @brief chamar após calcular a heurística (grava o valor, dependendo da parametrização)
	int Heuristica(void);

	// @brief chamar em CSubProblema::Heuristica() para verificar se a heurística já existe, ou precisa de ser calculada
	bool ExisteHeuritica(void);

	void Sucessores(TVector<TNo>& sucessores);


	/**
	 * @brief Utilitário para calculo de uma heurística standard em jogos simples
	 *
	 * calcular o número de ameaças de vitória, para cada lado, de menor comprimento:
	 * - qMin - vetor com número de ameaças (1 ou mais) a 1 jogada (na primeira posição), a 2 (na segunda posição), e assim sucessivamente;
	 * - qMax - vetor com número de ameaças (1 ou mais) a 1 jogada (na primeira posição), a 2 (na segunda posição), e assim sucessivamente;
	 */
	int MaiorAmeaca(TVector<int>& qMin, TVector<int>& qMax, int maxAmeaca) const;

protected:
	/// @brief fim da procura, por corte de nível (ou não haver sucessores), retornar heurística
	int NoFolha(bool nivel);

	/// @brief  verifica se há um corte alfa/beta, atualizando alfa e beta
	bool CorteAlfaBeta(int valor, int& alfa, int& beta);

	/// @brief  iteração, aumentando o nível progressivamente
	int MetodoIterativo(int alfaBeta);

	/// @brief converte -infinito, 0, +infinito em -1 (vitória preta), 1 (vitória branca), 0 empate
	int Pontos(int resultado) { return resultado < 0 ? -1 : (resultado > 0 ? 1 : 0); }

	/**
	 * @brief Executa uma tarefa num teste empírico
	 * @param resultados Vetor onde inserir o resultado.
	 * @param inst ID da instância.
	 * @param conf ID da brancas
	 * @param conf ID da pretas
	 */
	void ExecutaTarefa(TVector<TResultadoJogo>& resultados,
		int inst, int brancas, int pretas, TVector<TVector<int>>* torneio = NULL);

	/**
	 * @brief Gera um relatório CSV com os resultados.
	 * @param resultados Vetor de resultados.
	 * @param ficheiro com o nome do ficheiro onde gravar.
	 */
	bool RelatorioCSV(TVector<TResultadoJogo>& resultados, const char* ficheiro);

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

	void DebugChamada(bool noFolha, int alfa = 0, int beta = 0);

	char* AdicionaLance(char* jogo, const char* lance);
};
