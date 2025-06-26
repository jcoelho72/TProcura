#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "TVector.h"
#include <time.h>
#include <stdint.h>
#include <limits.h>


// código para número não lido (não deve ser utilizado num parâmetro)
#define NAO_LIDO -1000000


enum EIndicadoresProcura {
	indResultado = 0, ///< resultado do algoritmo
	indTempo,         ///< tempo em milisegundos consumidos
	indIteracoes,     ///< número de iterações consumidas
	indProcura        ///< Marcador para permitir a extensão do enum em subclasses.
};

/**
 * @enum EParametrosProcura
 * @brief Identifica um parâmetro específico no código.
 *
 * Permite aceder a cada parâmetro sem precisar saber seu código numérico.
 * Índice do vetor de parametros, na classe TProcura.
 *
 * @note O último elemento (`parametrosProcura`) não representa um parâmetro real.
 * Existe para permitir a criação de uma enumeração adicional em subclasses, caso
 * seja necessário adicionar parâmetros específicos.
 *
 * @see TParametro, ExecutaAlgoritmo()
 *
 * @code
 * if(parametro[nivelDebug].valor > passos)
 *     // mostrar informação de debug correspondendo ao nível detalhe ou superior
 * @endcode
 */
enum EParametrosProcura {
	algoritmo = 0,         ///< Algoritmo base a executar.
	nivelDebug,            ///< Nível de debug, de reduzido a completo.
	seed,                  ///< Semente aleatória para inicializar a sequência de números pseudo-aleatórios.
	limiteTempo,           ///< Tempo limite em segundos. 
	limiteIteracoes,      ///< Número máximo de iterações (0 significa sem limite).
	parametrosProcura      ///< Marcador para permitir a extensão do enum em subclasses.
};

/**
 * @brief Níveis de detalhamento para debug.
 *
 * Controla a quantidade de informações exibidas durante a execução do algoritmo.
 *
 * @see nivelDebug
 *
 * @code
 * if(parametro[nivelDebug].valor > passos)
 *     // mostrar informação de debug correspondendo ao nível detalhe ou superior
 * @endcode
 */
enum ENivelDebug {
	nada = 0,  ///< Sem informações de debug.
	atividade, ///< Apenas eventos principais.
	passos,    ///< Exibe passos intermediários.
	detalhe,   ///< Debug detalhada sobre estados e decisões.
	completo   ///< Mostra toda a execução detalhadamente.
};

/**
 * @brief Define o sentido da operação de entrada/saída de dados.
 *
 * @note Utilizado em funções que requerem distinção entre operação de leitura e gravação.
 */
enum EOperacao { gravar = 0, ler };


// identificação de todos os indicadores definidos
typedef struct SIndicador {
	/// @brief nome do indicador
	const char* nome;
	/// @brief descrição do indicador, opcional 
	const char* descricao;
	/// @brief indice onde aparece o indicador nos resultados, c.c. -1 para não aparecer 
	int indice;
} TIndicador;

/**
 * @brief Estrutura para registo de um parâmetro
 *
 * Permite registrar um parâmetro, armazenando seu valor,
 * limites máximo e mínimo, além de nome e descrição.
 * Cada valor pode ter também um nome, em vez de ser um número.
 * Podem e devem ser adicionados parâmetros específicos de cada problema,
 * de modo a poderem ser testados no teste empírico.
 *
 * @note
 * Existe uma vetor de parametros declarada de forma estática,
 * de modo a aceder a qualquer parametro de forma global no código.
 * A ordem dos parametros estão de acordo com o tipo enumerado EParametrosConstrutiva
 *
 * @see EParametrosProcura e ResetParametros()
 *
 * Exemplo:
 * @code
 * if(parametro[nivelDebug].valor > passos)
 *     // mostrar informação de debug correspondendo ao nível detalhe ou superior
 * @endcode
 */
typedef struct SParametro {
	/// @brief nome do parametro, opcional mas aconselhado nos parâmetros específicos
	const char* nome;
	/// @brief valor do parametro
	int valor;
	/// @brief valor mínimo que o parametro pode tomar
	int min;
	/// @brief valor máximo que o parametro pode tomar
	int max;
	/// @brief descrição do parametro, opcional 
	const char* descricao;
	/// @brief Nome associado a cada valor do parâmetro, útil para variáveis categóricas.
	/// @note Especialmente relevante quando os valores não seguem uma sequência ordenada.
	const char** nomeValores;
} TParametro;


/**
 * @internal
 * @brief Estrutura para guardar o resultado de uma execução
 *
 * Permite registar informação para testes empíricos, de modo a avaliar
 * o desempenho de algoritmos e respetivas parametrizações.
 */
typedef struct SResultado {
	int instancia, configuracao;
	TVector<int> valor; // valor para cada indicador selecionado (fixos os EIndicadoresProcura, resultado, tempo, iterações)
} TResultado;


/**
 * @brief Classe base para todas as procuras.
 *
 * Esta classe base para procuras... (separação de TProcurasConstrutivas, em curso).
 *   pretende-se que depois as sub-classes tipo TProcuraMelhorativa, possa herdar de
 *   TProcura, não ficando com partes da procura construtiva que são desnecessárias
 *
 * **Observação:** Alguns métodos e parâmetros terão efeito apenas se determinados métodos forem
 * redefinidos na subclasse.
 */

class TProcura
{
public:
	TProcura(void) {}
	virtual ~TProcura(void) {}

	/**
	 * @brief Coloca o objecto no estado inicial da procura.
	 * @note Obrigatória a redefinição.
	 *
	 * Este método inicializa as variáveis de estado no estado inicial vazio.
	 * Representa o estado inicial antes de qualquer ação ser realizada na procura.
	 * Caso existam dados de instância, deve neste método carregar a instância.
	 * A primeira instrução deverá chamar o método da superclasse, conforme modelo em baixo.
	 *
	 * @note A variável instancia.valor, tem o ID da instância que deve ser carregada.
	 * @note Se a função Codifica() estiver implementada, o tamanho do estado codificado
	 * deve ser determinado após o carregamento da instância, pois diferentes instâncias
	 * podem exigir tamanhos distintos.
	 *
	 * @see Codifica()
	 *
	 * @code
	 * void CSubProblema::Inicializar(void)
	 * {
	 *     TProcura::Inicializar();
	 * 	   // acertar as variáveis estáticas, com a instância (ID: instancia.valor)
	 * 	   CarregaInstancia(); // exemplo de método em CSubProblema para carregar uma instância
	 *     // inicializar todas as variáveis de estado
	 * 	   variavel = 0;
	 *     // Determinar o tamanho máximo do estado codificado, se aplicável
	 * 	   tamanhoCodificado = 1;
	 * }
	 * @endcode
	 */
	virtual void Inicializar(void) { }


	/**
	 * @brief Executa o algoritmo com os parametros atuais
	 * @note Redefinição necessária
	 *
	 * No caso de adicionar algum algoritmo, chame o algoritmo com base em parametro[algoritmo].valor
	 * Se `TesteManual()` não for utilizado, esta função pode ser chamada diretamente,
	 * desde que os parâmetros necessários já estejam configurados corretamente.
	 */
	virtual int ExecutaAlgoritmo() { return -1; }

	// retorna o valor do indicador[id]
	virtual int Indicador(int id);

	/**
	 * @brief Mostra o estado no ecrã, para debug.
	 * @note Redefinição opcional. Necessário para visualizar a procura, e explorar o espaço manualmente.
	 *
	 * Esta função deverá mostrar claramente o estado atual, em texto mas da forma mais confortável possível.
	 * O formato texto destina-se principalmente a quem implementa o problema, e não utilizadores
	 * finais.
	 * É importante poder explorar o espaço de estados, para verificar a correta implementação
	 * dos sucessores, como também possa ver a árvore de procura dos algoritmos, para árvores pequenas,
	 * e assim detectar bugs.
	 *
	 * @note Antes de cada linha, chame a função NovaLinha(). Dependendo do contexto, `NovaLinha()` pode
	 * imprimir caracteres que representam os ramos da árvore de procura, criando uma visualização textual
	 * que simula a estrutura da procura.
	 *
	 * @note A exibição do estado pode variar conforme o nível de debug definido
	 * em `parametro[nivelDebug].valor`. Um nível menor pode mostrar informações mais sucintas,
	 * enquanto um nível maior pode detalhar todas as variáveis do estado.
	 *
	 * @see NovaLinha()
	 *
	 * @code
	 * void CSubProblema::Debug(void)
	 * {
	 * 	   NovaLinha();
	 *     // neste exemplo o estado é apenas um número
	 *     if(parametro[nivelDebug].valor <= atividade)
	 * 	       printf("--<([%d])>--", variavel); // versão compacta do estado
	 *     else {
	 *         // versão mais elaborada do estado
	 *     }
	 * }
	 * @endcode
	 */
	virtual void Debug(void);

	/**
	 * @brief Inicializa os parametros
	 * @note Redefinição necessária se forem adicionados novos parametros, ou for alterado
	 * o valor de omissão de parametros existentes.
	 *
	 * Nesta função, a primeira instrução deverá ser a chamada da função da superclasse,
	 * para que sejam criados os parametros da superclasse antes de qualquer outra instrução.
	 *
	 * Cada problema pode ter um algoritmo e configurações padrão que funcionam bem na maioria dos casos.
	 * Nesta função, podem ser definidos estes valores de omissão, que se não forem alterados,
	 * irá executar a configuração mais genérica.
	 *
	 * Novos parâmetros podem ser adicionados conforme necessário para atender às particularidades do problema.
	 * Estes parametros podem depois ser selecionados ou incluídos num teste empírico, de modo a averiguar
	 * em fase de testes, qual a melhor configuração, evitando escolhas arbitrárias ou não fundamentadas.
	 *
	 * @note Na criação de um novo parametro, dar uma estrutura TParametro.
	 *
	 * @note Ao adicionar novos parâmetros, é recomendável manter a enumeração sincronizada
	 * com a da superclasse. O primeiro elemento deve ser `parametrosConstrutivos`,
	 * garantindo que novas adições na superclasse sejam automaticamente refletidas aqui.
	 *
	 * @see TParametro
	 *
	 * Exemplo com a alteração do valor de omissão de um parametro, e adição de dois novos parametros.
	 * @code
	 * // continuação da enumeração EParametrosConstrutiva
	 * enum ESubProblema { opcaoHeur = parametrosConstrutivas, opcaoSuc };
	 * void CSubProblema::ResetParametros(void)
	 * {
	 *     static const char* nomesSuc[] = { "todas", "contributo" }; // nomes para os valores de opcaoSuc
	 *     // chamar primeiro o método na superclasse
	 *     TProcura::ResetParametros();
	 *     // neste exemplo considerou-se que se pretende ver apenas estados completos, ignorando ações
	 *     parametro[verAcoes].valor = 1;
	 *
	 *     // novo parametro para utilizar na função Heuristica()
	 *     parametro.Add({ "Opção Heurística", 0,0,10,
	 *         "explicação do que acontece na heuristica, com este parametro entre 0 e 10",NULL });
	 *     // novo parametro para utilizar na função Sucessores()
	 *     parametro.Add({ "Opção Sucessores", 0,0,1,
	 *         "0 gera todas as ações; 1 gera apenas ações que tenham um contributo para a solução.",nomesSuc });
	 * }
	 * @endcode
	 */
	virtual void ResetParametros();

	/**
	 * @brief Verifica se a procura deve ser interrompida
	 * @note A redefinição é opcional e deve ser feita apenas se houver necessidade de critérios
	 * de paragem adicionais, além dos já estabelecidos.
	 * @return Retorna verdadeiro se a procura deve parar de imediato
	 *
	 * O critério de paragem pode ser especificado em limite de tempo, expansões, gerações e avaliações.
	 * Caso exista uma falha na alocação de memória de um estado, em chamadas futuras irá retornar verdadeiro.
	 *
	 * @note Redefinir apenas se o critério de paragem não puder ser contemplado nestes pontos.
	 * @note Esta função deve manter a eficiência elevada, dado que é chamada em ciclos internos
	 * dos algoritmos de procura.
	 *
	 * @code
	 * bool CSubProblema::Parar(void) {
	 *     return TProcuraConstrutiva::Parar() || CriterioParagem(); // critério de paragem definido em CSubProblema
	 * }
	 * @endcode
	 */
	virtual bool Parar(void) {
		return TempoExcedido() || IteracoesExcedido() || memoriaEsgotada;
	}

	/**
	* @brief Inicializa a interação com o utilizador
	* @note Redefinição necessária para definir as instancias existentes.
	*
	* Esta função arranca com o teste manual, orientada para o programador.
	* A interface permite:
	* - visualizar e trocar de instância
	* - explorar o espaço de estados nessa instancia, executando ações
	* - ver um caminho que esteja gravado (por exploração manual ou por execução de um algoritmo)
	* - ver e editar qualquer parametro de execução
	* - o algoritmo é também um parametro, podendo naturalmente ser alterado
	* - há parametros sobre limites de execução, informação de debug, opções de implementação e opções de algoritmos
	* - executar o algoritmo com a configuração atual
	* - adicionar a configuração atual a um conjunto de configurações de teste
	* - executar um teste empírico, executando todas as configurações de teste, no conjunto de instâncias selecionadas
	*
	* Esta função deve ser redefinida para inicializar a variável com informação dos IDs das instâncias disponíveis.
	* Essa variável é do tipo TParametro, mas não está na lista de parametros, devendo ser inicializada aqui.
	*
	* @note A instância selecionada irá ser carregada em SolucaoVazia(), utilizando o valor atual.
	* @note Esta função deve ser o ponto de entrada, a executar no main.
	*
	* @see TParametro
	*
	* @code
	* void CSubProblema::TesteManual(const char* nome)
	* {
	*     // indicar que há 10 instâncias, sendo a instância inicial a 1
	* 	   instancia = { "Problema", 1,1,10, "Características dos problemas", NULL };
	* 	   TProcuraConstrutiva::TesteManual(nome);
	* }
	*
	* // exemplo do main
	* int main()
	* {
	*     CSubProblema problema;
	*     problema.TesteManual("CSubProblema");
	* }
	* @endcode
	*/
	virtual void TesteManual(const char* nome);

	/**
	 * @brief Executa testes empíricos, em todas as configurações guardadas, nas instâncias selecionadas
	 * @note Redefinição não é necessária
	 * @param inicio - ID da primeira instância no teste (ou -1 para a primeira)
	 * @param fim - ID da última instância no teste (ou -1 para a última)
	 * @param mostrarSolucoes - se true, mostra a solução após cada execução, c.c. indica apenas a instância em processamento.
	 *
	 * Esta função é chamada de TesteManual() para executar testes empíricos.
	 * A função apresenta-se como método virtual, atendendo a que será redefinida nas
	 * procuras adversas. É genérica e não se prevê outras situações que seja necessário
	 * redefini-la.
	 *
	 * @note Pode ser chamada diretamente do código, e nesse caso é necessário que a variável
	 * estática 'configuracoes' tenha as configurações em teste.
	 * Se `configuracoes` estiver vazia, o teste empírico será executado apenas
	 * com a configuração atual, avaliando seu desempenho isoladamente, sem comparação com outras configurações.
	 *
	 * @see TesteManual()
	 */
	virtual void TesteEmpirico(int inicio = -1, int fim = -1, bool mostrarSolucoes = true);

	// LimparEstatisticas: Chamar antes da corrida
	virtual void LimparEstatisticas(clock_t& inicio);
	// FinalizarCorrida: Chamar após a corrida
	virtual void FinalizarCorrida(clock_t inicio);
	// ExplorarSucessores: definir para explorar manualmente o espaço
	virtual void ExplorarSucessores() {}
	// MostrarSolucao: definir para visualizar a solução
	virtual void MostrarSolucao() {}

	/// @brief ID da instância atual, a ser utilizado em SolucaoVazia().
	static TParametro instancia;
	/// @brief Parâmetros a serem utilizados na configuração atual.
	/// @see EParametrosConstrutiva
	static TVector<TParametro> parametro;
	/// @brief Indicadores que podem ser calculados após a execução, quer com informação da instãncia, quer com resultado da última corrida.
	/// @see Indicador()
	static TVector<TIndicador> indicador;
	/// @brief Conjuntos de configurações para teste empírico.
	static TVector<TVector<int>> configuracoes;
	/// @brief Resultado retornado pelo algoritmo na última execução.
	static int resultado;
	/// @brief tempo consumido na última execução.
	static int tempo;
	/// @brief Número total de iterações realizadas na última execução.
	static int iteracoes;
	/// @brief Instante final (deadline) da corrida atual.
	static clock_t instanteFinal;
	/// @brief Flag indicando problemas de memória esgotada.
	static bool memoriaEsgotada;

	bool TempoExcedido() { return instanteFinal < clock(); }
	bool IteracoesExcedido() {
		return parametro[limiteIteracoes].valor > 0 && parametro[limiteIteracoes].valor < iteracoes;
	}
	// ler um número, ou retorna NAO_LIDO
	static int NovoValor(const char* prompt);

protected:

	void InserirRegisto(TVector<TResultado> &resultados, int inst, int conf);
	int Registo(TResultado &resultado, int id); // retorna id caso esteja no registo
	void Registo(TResultado& resultado, int id, int valor); // retorna id caso esteja no registo
	void MostraParametros(int detalhe = 1, TVector<int>* idParametros = NULL);
	void MostraIndicadores();
	void MostrarConfiguracoes(int detalhe, int atual = -1);
	bool EditarIndicadores();
	void EditarParametros();
	void EditarConfiguracoes();
	void MostraRelatorio(TVector<TResultado>& resultados, bool ultimo=false);
	void ConfiguracaoAtual(TVector<int>& parametros, int operacao); // gravar (ou ler) a configuração atual
	int NovaConfiguracao(TVector<int>& parametros);
	int MelhorResultado(TResultado base, TResultado alternativa);
	void CalculaTorneio(TVector<TResultado>& resultados);
	void MostrarTorneio(TVector<TVector<int>>& torneio, bool jogo = false);
	void BarraTorneio(bool nomes);
	void ExtrairConfiguracao(TVector<TResultado>& resultados, TVector<TResultado>& extracao, int configuracao);
	void SolicitaInstancia();

	TVector<int> ExtraiLista(char *str);
	void InserirConfiguracoes(char* str, TVector<int>& base);
	void InserirConfiguracoes(TVector<int>& base, TVector<int> &produto, TVector<TVector<int>> &valores);


	static int Dominio(int& variavel, int min = INT_MIN, int max = INT_MAX);
};

