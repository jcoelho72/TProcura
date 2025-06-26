#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "TVector.h"
#include <time.h>
#include <stdint.h>
#include <limits.h>


// c�digo para n�mero n�o lido (n�o deve ser utilizado num par�metro)
#define NAO_LIDO -1000000


enum EIndicadoresProcura {
	indResultado = 0, ///< resultado do algoritmo
	indTempo,         ///< tempo em milisegundos consumidos
	indIteracoes,     ///< n�mero de itera��es consumidas
	indProcura        ///< Marcador para permitir a extens�o do enum em subclasses.
};

/**
 * @enum EParametrosProcura
 * @brief Identifica um par�metro espec�fico no c�digo.
 *
 * Permite aceder a cada par�metro sem precisar saber seu c�digo num�rico.
 * �ndice do vetor de parametros, na classe TProcura.
 *
 * @note O �ltimo elemento (`parametrosProcura`) n�o representa um par�metro real.
 * Existe para permitir a cria��o de uma enumera��o adicional em subclasses, caso
 * seja necess�rio adicionar par�metros espec�ficos.
 *
 * @see TParametro, ExecutaAlgoritmo()
 *
 * @code
 * if(parametro[nivelDebug].valor > passos)
 *     // mostrar informa��o de debug correspondendo ao n�vel detalhe ou superior
 * @endcode
 */
enum EParametrosProcura {
	algoritmo = 0,         ///< Algoritmo base a executar.
	nivelDebug,            ///< N�vel de debug, de reduzido a completo.
	seed,                  ///< Semente aleat�ria para inicializar a sequ�ncia de n�meros pseudo-aleat�rios.
	limiteTempo,           ///< Tempo limite em segundos. 
	limiteIteracoes,      ///< N�mero m�ximo de itera��es (0 significa sem limite).
	parametrosProcura      ///< Marcador para permitir a extens�o do enum em subclasses.
};

/**
 * @brief N�veis de detalhamento para debug.
 *
 * Controla a quantidade de informa��es exibidas durante a execu��o do algoritmo.
 *
 * @see nivelDebug
 *
 * @code
 * if(parametro[nivelDebug].valor > passos)
 *     // mostrar informa��o de debug correspondendo ao n�vel detalhe ou superior
 * @endcode
 */
enum ENivelDebug {
	nada = 0,  ///< Sem informa��es de debug.
	atividade, ///< Apenas eventos principais.
	passos,    ///< Exibe passos intermedi�rios.
	detalhe,   ///< Debug detalhada sobre estados e decis�es.
	completo   ///< Mostra toda a execu��o detalhadamente.
};

/**
 * @brief Define o sentido da opera��o de entrada/sa�da de dados.
 *
 * @note Utilizado em fun��es que requerem distin��o entre opera��o de leitura e grava��o.
 */
enum EOperacao { gravar = 0, ler };


// identifica��o de todos os indicadores definidos
typedef struct SIndicador {
	/// @brief nome do indicador
	const char* nome;
	/// @brief descri��o do indicador, opcional 
	const char* descricao;
	/// @brief indice onde aparece o indicador nos resultados, c.c. -1 para n�o aparecer 
	int indice;
} TIndicador;

/**
 * @brief Estrutura para registo de um par�metro
 *
 * Permite registrar um par�metro, armazenando seu valor,
 * limites m�ximo e m�nimo, al�m de nome e descri��o.
 * Cada valor pode ter tamb�m um nome, em vez de ser um n�mero.
 * Podem e devem ser adicionados par�metros espec�ficos de cada problema,
 * de modo a poderem ser testados no teste emp�rico.
 *
 * @note
 * Existe uma vetor de parametros declarada de forma est�tica,
 * de modo a aceder a qualquer parametro de forma global no c�digo.
 * A ordem dos parametros est�o de acordo com o tipo enumerado EParametrosConstrutiva
 *
 * @see EParametrosProcura e ResetParametros()
 *
 * Exemplo:
 * @code
 * if(parametro[nivelDebug].valor > passos)
 *     // mostrar informa��o de debug correspondendo ao n�vel detalhe ou superior
 * @endcode
 */
typedef struct SParametro {
	/// @brief nome do parametro, opcional mas aconselhado nos par�metros espec�ficos
	const char* nome;
	/// @brief valor do parametro
	int valor;
	/// @brief valor m�nimo que o parametro pode tomar
	int min;
	/// @brief valor m�ximo que o parametro pode tomar
	int max;
	/// @brief descri��o do parametro, opcional 
	const char* descricao;
	/// @brief Nome associado a cada valor do par�metro, �til para vari�veis categ�ricas.
	/// @note Especialmente relevante quando os valores n�o seguem uma sequ�ncia ordenada.
	const char** nomeValores;
} TParametro;


/**
 * @internal
 * @brief Estrutura para guardar o resultado de uma execu��o
 *
 * Permite registar informa��o para testes emp�ricos, de modo a avaliar
 * o desempenho de algoritmos e respetivas parametriza��es.
 */
typedef struct SResultado {
	int instancia, configuracao;
	TVector<int> valor; // valor para cada indicador selecionado (fixos os EIndicadoresProcura, resultado, tempo, itera��es)
} TResultado;


/**
 * @brief Classe base para todas as procuras.
 *
 * Esta classe base para procuras... (separa��o de TProcurasConstrutivas, em curso).
 *   pretende-se que depois as sub-classes tipo TProcuraMelhorativa, possa herdar de
 *   TProcura, n�o ficando com partes da procura construtiva que s�o desnecess�rias
 *
 * **Observa��o:** Alguns m�todos e par�metros ter�o efeito apenas se determinados m�todos forem
 * redefinidos na subclasse.
 */

class TProcura
{
public:
	TProcura(void) {}
	virtual ~TProcura(void) {}

	/**
	 * @brief Coloca o objecto no estado inicial da procura.
	 * @note Obrigat�ria a redefini��o.
	 *
	 * Este m�todo inicializa as vari�veis de estado no estado inicial vazio.
	 * Representa o estado inicial antes de qualquer a��o ser realizada na procura.
	 * Caso existam dados de inst�ncia, deve neste m�todo carregar a inst�ncia.
	 * A primeira instru��o dever� chamar o m�todo da superclasse, conforme modelo em baixo.
	 *
	 * @note A vari�vel instancia.valor, tem o ID da inst�ncia que deve ser carregada.
	 * @note Se a fun��o Codifica() estiver implementada, o tamanho do estado codificado
	 * deve ser determinado ap�s o carregamento da inst�ncia, pois diferentes inst�ncias
	 * podem exigir tamanhos distintos.
	 *
	 * @see Codifica()
	 *
	 * @code
	 * void CSubProblema::Inicializar(void)
	 * {
	 *     TProcura::Inicializar();
	 * 	   // acertar as vari�veis est�ticas, com a inst�ncia (ID: instancia.valor)
	 * 	   CarregaInstancia(); // exemplo de m�todo em CSubProblema para carregar uma inst�ncia
	 *     // inicializar todas as vari�veis de estado
	 * 	   variavel = 0;
	 *     // Determinar o tamanho m�ximo do estado codificado, se aplic�vel
	 * 	   tamanhoCodificado = 1;
	 * }
	 * @endcode
	 */
	virtual void Inicializar(void) { }


	/**
	 * @brief Executa o algoritmo com os parametros atuais
	 * @note Redefini��o necess�ria
	 *
	 * No caso de adicionar algum algoritmo, chame o algoritmo com base em parametro[algoritmo].valor
	 * Se `TesteManual()` n�o for utilizado, esta fun��o pode ser chamada diretamente,
	 * desde que os par�metros necess�rios j� estejam configurados corretamente.
	 */
	virtual int ExecutaAlgoritmo() { return -1; }

	// retorna o valor do indicador[id]
	virtual int Indicador(int id);

	/**
	 * @brief Mostra o estado no ecr�, para debug.
	 * @note Redefini��o opcional. Necess�rio para visualizar a procura, e explorar o espa�o manualmente.
	 *
	 * Esta fun��o dever� mostrar claramente o estado atual, em texto mas da forma mais confort�vel poss�vel.
	 * O formato texto destina-se principalmente a quem implementa o problema, e n�o utilizadores
	 * finais.
	 * � importante poder explorar o espa�o de estados, para verificar a correta implementa��o
	 * dos sucessores, como tamb�m possa ver a �rvore de procura dos algoritmos, para �rvores pequenas,
	 * e assim detectar bugs.
	 *
	 * @note Antes de cada linha, chame a fun��o NovaLinha(). Dependendo do contexto, `NovaLinha()` pode
	 * imprimir caracteres que representam os ramos da �rvore de procura, criando uma visualiza��o textual
	 * que simula a estrutura da procura.
	 *
	 * @note A exibi��o do estado pode variar conforme o n�vel de debug definido
	 * em `parametro[nivelDebug].valor`. Um n�vel menor pode mostrar informa��es mais sucintas,
	 * enquanto um n�vel maior pode detalhar todas as vari�veis do estado.
	 *
	 * @see NovaLinha()
	 *
	 * @code
	 * void CSubProblema::Debug(void)
	 * {
	 * 	   NovaLinha();
	 *     // neste exemplo o estado � apenas um n�mero
	 *     if(parametro[nivelDebug].valor <= atividade)
	 * 	       printf("--<([%d])>--", variavel); // vers�o compacta do estado
	 *     else {
	 *         // vers�o mais elaborada do estado
	 *     }
	 * }
	 * @endcode
	 */
	virtual void Debug(void);

	/**
	 * @brief Inicializa os parametros
	 * @note Redefini��o necess�ria se forem adicionados novos parametros, ou for alterado
	 * o valor de omiss�o de parametros existentes.
	 *
	 * Nesta fun��o, a primeira instru��o dever� ser a chamada da fun��o da superclasse,
	 * para que sejam criados os parametros da superclasse antes de qualquer outra instru��o.
	 *
	 * Cada problema pode ter um algoritmo e configura��es padr�o que funcionam bem na maioria dos casos.
	 * Nesta fun��o, podem ser definidos estes valores de omiss�o, que se n�o forem alterados,
	 * ir� executar a configura��o mais gen�rica.
	 *
	 * Novos par�metros podem ser adicionados conforme necess�rio para atender �s particularidades do problema.
	 * Estes parametros podem depois ser selecionados ou inclu�dos num teste emp�rico, de modo a averiguar
	 * em fase de testes, qual a melhor configura��o, evitando escolhas arbitr�rias ou n�o fundamentadas.
	 *
	 * @note Na cria��o de um novo parametro, dar uma estrutura TParametro.
	 *
	 * @note Ao adicionar novos par�metros, � recomend�vel manter a enumera��o sincronizada
	 * com a da superclasse. O primeiro elemento deve ser `parametrosConstrutivos`,
	 * garantindo que novas adi��es na superclasse sejam automaticamente refletidas aqui.
	 *
	 * @see TParametro
	 *
	 * Exemplo com a altera��o do valor de omiss�o de um parametro, e adi��o de dois novos parametros.
	 * @code
	 * // continua��o da enumera��o EParametrosConstrutiva
	 * enum ESubProblema { opcaoHeur = parametrosConstrutivas, opcaoSuc };
	 * void CSubProblema::ResetParametros(void)
	 * {
	 *     static const char* nomesSuc[] = { "todas", "contributo" }; // nomes para os valores de opcaoSuc
	 *     // chamar primeiro o m�todo na superclasse
	 *     TProcura::ResetParametros();
	 *     // neste exemplo considerou-se que se pretende ver apenas estados completos, ignorando a��es
	 *     parametro[verAcoes].valor = 1;
	 *
	 *     // novo parametro para utilizar na fun��o Heuristica()
	 *     parametro.Add({ "Op��o Heur�stica", 0,0,10,
	 *         "explica��o do que acontece na heuristica, com este parametro entre 0 e 10",NULL });
	 *     // novo parametro para utilizar na fun��o Sucessores()
	 *     parametro.Add({ "Op��o Sucessores", 0,0,1,
	 *         "0 gera todas as a��es; 1 gera apenas a��es que tenham um contributo para a solu��o.",nomesSuc });
	 * }
	 * @endcode
	 */
	virtual void ResetParametros();

	/**
	 * @brief Verifica se a procura deve ser interrompida
	 * @note A redefini��o � opcional e deve ser feita apenas se houver necessidade de crit�rios
	 * de paragem adicionais, al�m dos j� estabelecidos.
	 * @return Retorna verdadeiro se a procura deve parar de imediato
	 *
	 * O crit�rio de paragem pode ser especificado em limite de tempo, expans�es, gera��es e avalia��es.
	 * Caso exista uma falha na aloca��o de mem�ria de um estado, em chamadas futuras ir� retornar verdadeiro.
	 *
	 * @note Redefinir apenas se o crit�rio de paragem n�o puder ser contemplado nestes pontos.
	 * @note Esta fun��o deve manter a efici�ncia elevada, dado que � chamada em ciclos internos
	 * dos algoritmos de procura.
	 *
	 * @code
	 * bool CSubProblema::Parar(void) {
	 *     return TProcuraConstrutiva::Parar() || CriterioParagem(); // crit�rio de paragem definido em CSubProblema
	 * }
	 * @endcode
	 */
	virtual bool Parar(void) {
		return TempoExcedido() || IteracoesExcedido() || memoriaEsgotada;
	}

	/**
	* @brief Inicializa a intera��o com o utilizador
	* @note Redefini��o necess�ria para definir as instancias existentes.
	*
	* Esta fun��o arranca com o teste manual, orientada para o programador.
	* A interface permite:
	* - visualizar e trocar de inst�ncia
	* - explorar o espa�o de estados nessa instancia, executando a��es
	* - ver um caminho que esteja gravado (por explora��o manual ou por execu��o de um algoritmo)
	* - ver e editar qualquer parametro de execu��o
	* - o algoritmo � tamb�m um parametro, podendo naturalmente ser alterado
	* - h� parametros sobre limites de execu��o, informa��o de debug, op��es de implementa��o e op��es de algoritmos
	* - executar o algoritmo com a configura��o atual
	* - adicionar a configura��o atual a um conjunto de configura��es de teste
	* - executar um teste emp�rico, executando todas as configura��es de teste, no conjunto de inst�ncias selecionadas
	*
	* Esta fun��o deve ser redefinida para inicializar a vari�vel com informa��o dos IDs das inst�ncias dispon�veis.
	* Essa vari�vel � do tipo TParametro, mas n�o est� na lista de parametros, devendo ser inicializada aqui.
	*
	* @note A inst�ncia selecionada ir� ser carregada em SolucaoVazia(), utilizando o valor atual.
	* @note Esta fun��o deve ser o ponto de entrada, a executar no main.
	*
	* @see TParametro
	*
	* @code
	* void CSubProblema::TesteManual(const char* nome)
	* {
	*     // indicar que h� 10 inst�ncias, sendo a inst�ncia inicial a 1
	* 	   instancia = { "Problema", 1,1,10, "Caracter�sticas dos problemas", NULL };
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
	 * @brief Executa testes emp�ricos, em todas as configura��es guardadas, nas inst�ncias selecionadas
	 * @note Redefini��o n�o � necess�ria
	 * @param inicio - ID da primeira inst�ncia no teste (ou -1 para a primeira)
	 * @param fim - ID da �ltima inst�ncia no teste (ou -1 para a �ltima)
	 * @param mostrarSolucoes - se true, mostra a solu��o ap�s cada execu��o, c.c. indica apenas a inst�ncia em processamento.
	 *
	 * Esta fun��o � chamada de TesteManual() para executar testes emp�ricos.
	 * A fun��o apresenta-se como m�todo virtual, atendendo a que ser� redefinida nas
	 * procuras adversas. � gen�rica e n�o se prev� outras situa��es que seja necess�rio
	 * redefini-la.
	 *
	 * @note Pode ser chamada diretamente do c�digo, e nesse caso � necess�rio que a vari�vel
	 * est�tica 'configuracoes' tenha as configura��es em teste.
	 * Se `configuracoes` estiver vazia, o teste emp�rico ser� executado apenas
	 * com a configura��o atual, avaliando seu desempenho isoladamente, sem compara��o com outras configura��es.
	 *
	 * @see TesteManual()
	 */
	virtual void TesteEmpirico(int inicio = -1, int fim = -1, bool mostrarSolucoes = true);

	// LimparEstatisticas: Chamar antes da corrida
	virtual void LimparEstatisticas(clock_t& inicio);
	// FinalizarCorrida: Chamar ap�s a corrida
	virtual void FinalizarCorrida(clock_t inicio);
	// ExplorarSucessores: definir para explorar manualmente o espa�o
	virtual void ExplorarSucessores() {}
	// MostrarSolucao: definir para visualizar a solu��o
	virtual void MostrarSolucao() {}

	/// @brief ID da inst�ncia atual, a ser utilizado em SolucaoVazia().
	static TParametro instancia;
	/// @brief Par�metros a serem utilizados na configura��o atual.
	/// @see EParametrosConstrutiva
	static TVector<TParametro> parametro;
	/// @brief Indicadores que podem ser calculados ap�s a execu��o, quer com informa��o da inst�ncia, quer com resultado da �ltima corrida.
	/// @see Indicador()
	static TVector<TIndicador> indicador;
	/// @brief Conjuntos de configura��es para teste emp�rico.
	static TVector<TVector<int>> configuracoes;
	/// @brief Resultado retornado pelo algoritmo na �ltima execu��o.
	static int resultado;
	/// @brief tempo consumido na �ltima execu��o.
	static int tempo;
	/// @brief N�mero total de itera��es realizadas na �ltima execu��o.
	static int iteracoes;
	/// @brief Instante final (deadline) da corrida atual.
	static clock_t instanteFinal;
	/// @brief Flag indicando problemas de mem�ria esgotada.
	static bool memoriaEsgotada;

	bool TempoExcedido() { return instanteFinal < clock(); }
	bool IteracoesExcedido() {
		return parametro[limiteIteracoes].valor > 0 && parametro[limiteIteracoes].valor < iteracoes;
	}
	// ler um n�mero, ou retorna NAO_LIDO
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
	void ConfiguracaoAtual(TVector<int>& parametros, int operacao); // gravar (ou ler) a configura��o atual
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

