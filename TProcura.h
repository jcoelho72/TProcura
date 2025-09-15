#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "TVector.h"
#include <time.h>
#include <stdint.h>
#include <limits.h>
#include <stdio.h>
#include <cstdarg>


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
 * if(Parametro(nivelDebug) > passos)
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
 * if(Parametro(nivelDebug) > passos)
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
	 *
	 * @code
	 * void CSubProblema::Inicializar(void)
	 * {
	 *     TProcura::Inicializar();
	 * 	   // acertar as variáveis estáticas, com a instância (ID: instancia.valor)
	 * 	   CarregaInstancia(); // exemplo de método em CSubProblema para carregar uma instância
	 *     // pode/deve utilizar variável "ficheiroInstancia" concatenado com instancia.valor, com o ID da instância
	 *     // inicializar todas as variáveis de estado
	 * 	   variavel = 0;
	 *     // Determinar o tamanho máximo do estado codificado, se aplicável
	 * 	   tamanhoCodificado = 1;
	 * }
	 * @endcode
	 */
	virtual void Inicializar(void) {}


	/**
	 * @brief Executa o algoritmo com os parametros atuais
	 * @note Redefinição necessária
	 *
	 * No caso de adicionar algum algoritmo, chame o algoritmo com base em parametro[algoritmo].valor
	 * Se `TesteManual()` não for utilizado, esta função pode ser chamada diretamente,
	 * desde que os parâmetros necessários já estejam configurados corretamente.
	 */
	virtual int ExecutaAlgoritmo() { return -1; }

	/**
	 * @brief Retorna um indicador, após a execução do algoritmo
	 * @note Obrigatória a redefinição no caso de serem definidos indicadores na subclasse
	 *
	 * Este método é chamado após a execução do algoritmo, para cada indicador,
	 * pela ordem definida pelo utilizador. Caso tenham sido definidos outros indicadorews
	 * na subclasse, deve redefinir, e caso seja um indicador da subclasse, calcular,
	 * caso contrário deve chamar o método da superclasse.
	 *
	 * @note Um indicador pode ser uma verificação da solução, ou qualquer outro procedimento
	 * que executa após o algoritmo, não sendo o tempo de execução contabgilizado no algoritmo.
	 *
	 * @see ResetParametros()
	 *
	 * @code
	 * void CSubProblema::Indicador(int id)
	 * {
	 *     if(id == indicador-da-subclasse) {
	 *         // calcular indicador
	 *         return resultado;
	 *     }
	 *     return TProcura::Indicador(id);
	 * }
	 * @endcode
	 */
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
	 * @brief Inicializa os parametros, indicadores e instâncias
	 * @note Redefinição necessária, para pelo menos indicar as instâncias existentes
	 *
	 * Nesta função, a primeira instrução deverá ser a chamada da função da superclasse,
	 * para que sejam criados os parametros da superclasse antes de qualquer outra instrução.
	 *
	 * Cada problema pode ter um algoritmo e configurações padrão que funcionam bem na maioria dos casos.
	 * Nesta função, podem ser definidos estes valores de omissão.
	 *
	 * Novos parâmetros podem ser adicionados conforme necessário para atender às particularidades do problema.
	 * Estes parametros podem depois ser selecionados ou incluídos num teste empírico, de modo a averiguar
	 * em fase de testes, qual a melhor configuração, evitando escolhas arbitrárias ou não fundamentadas.
	 *
	 * Nesta função deve ser redefinida a variável com informação dos IDs das instâncias disponíveis.
	 * Essa variável é do tipo TParametro, mas não está na lista de parametros, devendo ser inicializada aqui.
	 *
	 * Existindo novos indicadores, devem ser adicionados aqui, e redefinida a função Indicador() para calcular o valor.
	 *
	 * @note Na criação de um novo parametro, dar uma estrutura TParametro.
	 *
	 * @note Ao adicionar novos parâmetros, é recomendável manter a enumeração sincronizada
	 * com a da superclasse. O primeiro elemento deve ser `parametrosConstrutivos`,
	 * garantindo que novas adições na superclasse sejam automaticamente refletidas aqui.
	 *
	 * @note A instância selecionada irá ser carregada em Inicializar(), utilizando o valor atual.
	 *
	 * @see TParametro
	 *
	 * Exemplo com a alteração do valor de omissão de um parametro, e adição de dois novos parametros.
	 * @code
	 * // continuação da enumeração EParametrosProcujra
	 * enum ESubProblema { opcaoHeur = parametrosProcura, opcaoSuc };
	 * void CSubProblema::ResetParametros(void)
	 * {
	 *     static const char* nomesSuc[] = { "todas", "contributo" }; // nomes para os valores de opcaoSuc
	 *     // chamar primeiro o método na superclasse
	 *     TProcura::ResetParametros();
	 *     // neste exemplo considerou-se que se pretende ver algum debug, de omissão
	 *     parametro[nivelDebug].valor = 1;
	 *
	 *     // novo parametro para utilizar na função Heuristica()
	 *     parametro.Add({ "Opção Heurística", 0,0,10,
	 *         "explicação do que acontece na heuristica, com este parametro entre 0 e 10",NULL });
	 *     // novo parametro para utilizar na função Sucessores()
	 *     parametro.Add({ "Opção Sucessores", 0,0,1,
	 *         "0 gera todas as ações; 1 gera apenas ações que tenham um contributo para a solução.",nomesSuc });
	 *
	 *     // novo indicador
	 *	   indicador.Add({ "Ordenado","verifica se um vetor está ordenado", indOrdenar });
	 *     indAtivo.Add(indOrdenar); // adicionar aos indicadores ativos de omissão
	 *
	 *     // indicar que há 10 instâncias, sendo a instância inicial a 1
	 * 	   instancia = { "Problema", 1,1,10, "Características dos problemas", NULL };
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
	 * O critério de paragem pode ser especificado em limite de tempo, limite de iterações.
	 * Caso exista uma falha na alocação de memória de um estado, em chamadas futuras irá retornar verdadeiro.
	 *
	 * @note Redefinir apenas se o critério de paragem não puder ser contemplado nestes pontos.
	 * @note Esta função deve manter a eficiência elevada, dado que é chamada em ciclos internos
	 * dos algoritmos de procura.
	 *
	 * @code
	 * bool CSubProblema::Parar(void) {
	 *     return TProcura::Parar() || CriterioParagem(); // critério de paragem definido em CSubProblema
	 * }
	 * @endcode
	 */
	virtual bool Parar(void) {
		return TempoExcedido() || IteracoesExcedido() || memoriaEsgotada;
	}

	/**
	* @brief Inicializa a interação com o utilizador
	* @note Redefinição opcional
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
	* @note Esta função deve ser o ponto de entrada, a executar no main, caso não se utilize a função TProcura::main().
	*
	* @see TParametro, main
	*
	* @code
	* void CSubProblema::TesteManual(const char* nome)
	* {
	*      // ações extra antes do teste manual, ou redefinição completa;
	* 	   TProcura::TesteManual(nome); // chamada do método da superclasse, caso não redefina por completo
	* }
	*
	* // exemplo do main, sem processar argumentos (ver TProcura::main)
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
	 * @param instancias - IDs das instâncias a serem utilizadas
	 * @param mostrarSolucoes - se true, mostra a solução após cada execução, c.c. indica apenas a instância em processamento.
	 * @param ficheiro - nome do ficheiro com os resultados, caso exista
	 *
	 * Esta função é chamada de TesteManual() para executar testes empíricos.
	 * A função apresenta-se como método virtual, atendendo a que é redefinida nas
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
	virtual void TesteEmpirico(TVector<int> instancias, bool mostrarSolucoes = true, char* ficheiro = NULL);

	/**
	* @brief Inicializa a interação com o utilizador
	* @note Redefinição opcional
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
	* @note Esta função deve ser o ponto de entrada, a executar no main, caso não se utilize a função TProcura::main().
	*
	* @see TParametro, TesteManual
	*
	* @code
	* // exemplo do main, processando argumentos (ver TProcura::TesteManual)
	* int main(int argc, char* argv[])
	* {
	*	std::locale::global(std::locale(""));
	*	CSubProblema().main(argc, argv, "SubProblema");
	* }
	* @endcode
	*/
	virtual void main(int argc, char* argv[], const char* nome);

	/// @brief Chapar antes da execução do algoritmo. Limpa valores estatísticos, e fixa o instante limite de tempo para a execução
	virtual void LimparEstatisticas(clock_t& inicio);
	/// @brief Chamar após a execução do algoritmo. Grava o tempo consumido.
	virtual void ExecucaoTerminada(clock_t inicio);
	/// @brief definir para explorar manualmente os dados (não definido em TProcura, apenas em TProcuraConstrutiva)
	virtual void Explorar() {}
	/// @brief definir para visualizar a solução
	virtual void MostrarSolucao();
	/// @brief  retorna um vetor de inteiros com a codifciação da solução (esta codificação será adicionada aos indicadores, no ficheiro CSV de resultados)
	virtual TVector<int> CodificarSolucao() { return TVector<int>(); }

	/// @brief ID da instância atual, a ser utilizado em SolucaoVazia().
	static TParametro instancia;
	/// @brief nome do ficheiro de uma instância - editado pelo utilizador 
	///        (utilizar como prefixo, concatenando com ID da instância)
	///        pode ser utilizado para gravar a instãncia num novo formato, colocando um indicador ativo 
	///        que é chamado após a execução (pode gravar a solução para ficheiro também, mas essa é mais facilmente
	///        gravada em CVS codificada em inteiros, onde fica associada à configuração utilizada para a gerar)
	/// @see Inicializar()
	static char ficheiroInstancia[256];
	/// @brief Parâmetros a serem utilizados na configuração atual.
	/// @see EParametrosConstrutiva
	static TVector<TParametro> parametro;
	/// @brief Indicadores que podem ser calculados após a execução, quer com informação da instãncia, quer com resultado da última corrida.
	/// @see Indicador()
	static TVector<TIndicador> indicador;
	static TVector<int> indAtivo; // lista por ordem dos indicadores a utilizar
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
		return Parametro(limiteIteracoes) > 0 && Parametro(limiteIteracoes) < iteracoes;
	}
	// ler um número, ou retorna NAO_LIDO
	static int NovoValor(const char* prompt);
	// ler uma string
	static char* NovoTexto(const char* prompt);

	// retorna o valor do parametro, para facilidade de uso (leitura e escrita)
	int Parametro(int id) const { return parametro[id].valor; }
	int& Parametro(int id) { return parametro[id].valor; }

	/// @brief Mostra uma informação de debug, se o nível de debug for suficiente.
	/// @param tipo Nível de detalhe necessário para exibir a mensagem.
	/// @param exato Se true, só imprime se o nível de debug for exatamente igual a `tipo`.
	///              Se false, imprime se for >= `tipo`.
	/// @param fmt Formato da mensagem, como no printf.
	/// @return true se a mensagem foi impressa, false caso contrário.
	/// 
	/// @note Pode ser usado com || para encadear mensagens de diferentes níveis, 
	/// imprimindo apenas a primeira que corresponda ao nível de debug atual.	
	/// 
	/// @code
	/// // Exemplo: tenta imprimir no nível passos, senão no detalhe
	/// Debug(passos, true,  "\nPasso %d", iteracoes) ||
	/// Debug(detalhe, false, "\nPasso %d | Melhor custo: %d", iteracoes, custo) ||
	/// @endcode
	bool Debug(ENivelDebug tipo, bool exato, const char* fmt, ...) {
		int nivel = Parametro(nivelDebug);
		if (exato ? nivel != tipo : nivel < tipo)
			return false;
		va_list args;
		va_start(args, fmt); // último parâmetro fixo é 'fmt'
		vprintf(fmt, args);
		va_end(args);
		return true;
	}


	/// @brief Mostra uma informação de debug, se o nível de debug for suficiente
	/// @param tipo Nível de detalhe necessário para exibir a mensagem.
	/// resto dos parâmetros como em printf
	bool Debug(ENivelDebug tipo, const char* fmt, ...) {
		if (Parametro(nivelDebug) < tipo)
			return false;
		va_list args;
		va_start(args, fmt);
		vprintf(fmt, args);
		va_end(args);
		return true;
	}

protected:

	/**
	 * @brief Insere um novo registo de resultados.
	 * @param resultados Vetor onde inserir o resultado.
	 * @param inst ID da instância.
	 * @param conf ID da configuração.
	 */
	void InserirRegisto(TVector<TResultado>& resultados, int inst, int conf);

	/**
	 * @brief Procura um registo com determinado id.
	 * @param resultado Vetor de resultados.
	 * @param id ID a procurar.
	 * @return Índice do registo, ou -1 se não encontrado.
	 */
	int Registo(TResultado& resultado, int id);

	/**
	 * @brief Atualiza o valor de um registo.
	 * @param resultado Referência ao resultado a atualizar.
	 * @param id ID do valor.
	 * @param valor Novo valor a atribuir.
	 */
	void Registo(TResultado& resultado, int id, int valor);

	/**
	 * @brief Mostra os parâmetros atuais.
	 * @param detalhe Nível de detalhe na apresentação.
	 * @param idParametros Vetor de IDs de parâmetros a mostrar (opcional).
	 */
	void MostraParametros(int detalhe = 1, TVector<int>* idParametros = NULL);

	/**
	 * @brief Mostra os indicadores definidos.
	 */
	void MostraIndicadores();

	/**
	 * @brief Mostra as configurações disponíveis.
	 * @param detalhe Nível de detalhe.
	 * @param atual Índice da configuração atual (opcional).
	 */
	void MostrarConfiguracoes(int detalhe, int atual = -1);

	/**
	 * @brief Permite ao utilizador editar os indicadores a utilizar.
	 * @return true se alterou indicadores, false caso contrário.
	 */
	bool EditarIndicadores();

	/**
	 * @brief Permite ao utilizador editar os parâmetros.
	 */
	void EditarParametros();

	/**
	 * @brief Permite ao utilizador editar as configurações.
	 */
	void EditarConfiguracoes();

	/**
	 * @brief Mostra um relatório dos resultados.
	 * @param resultados Vetor de resultados a apresentar.
	 * @param ultimo Indica se é o último relatório (opcional).
	 */
	void MostraRelatorio(TVector<TResultado>& resultados, bool ultimo = false);

	/**
	 * @brief Grava ou lê a configuração atual.
	 * @param parametros Vetor de parâmetros.
	 * @param operacao Tipo de operação (gravar ou ler).
	 */
	void ConfiguracaoAtual(TVector<int>& parametros, int operacao);

	/**
	 * @brief Adiciona uma nova configuração se ainda não existir.
	 * @param parametros Vetor de parâmetros.
	 * @return Índice da nova configuração.
	 */
	int NovaConfiguracao(TVector<int>& parametros);

	/**
	 * @brief Compara dois resultados para determinar o melhor.
	 * @param base Resultado base.
	 * @param alternativa Resultado alternativo.
	 * @return Índice do melhor resultado.
	 */
	int MelhorResultado(TResultado base, TResultado alternativa);

	/**
	 * @brief Calcula o torneio entre várias configurações.
	 * @param resultados Vetor de resultados a comparar.
	 */
	void CalculaTorneio(TVector<TResultado>& resultados);

	/**
	 * @brief Mostra os resultados do torneio.
	 * @param torneio Matriz de resultados do torneio.
	 * @param jogo Indica se é modo de jogo ou apenas comparação.
	 */
	void MostrarTorneio(TVector<TVector<int>>& torneio, bool jogo = false);

	/**
	 * @brief Mostra a barra de progresso ou nomes do torneio.
	 * @param nomes Se true, mostra nomes; caso contrário, mostra progresso.
	 */
	void BarraTorneio(bool nomes);

	/**
	 * @brief Extrai resultados de uma determinada configuração.
	 * @param resultados Vetor de resultados.
	 * @param configuracao Índice da configuração.
	 * @return Vetor com os resultados extraídos.
	 */
	TVector<TResultado> ExtrairConfiguracao(TVector<TResultado>& resultados, int configuracao);

	/**
	 * @brief Solicita ao utilizador o ID da instância a utilizar, permitindo alterar também o prefixo do ficheiro.
	 */
	void SolicitaInstancia();

	/**
	 * @brief Solicita ao utilizador uma lista de instâncias.
	 * @return Vetor com IDs das instâncias selecionadas.
	 */
	TVector<int> SolicitaInstancias();

	/**
	 * @brief Gera um relatório CSV com os resultados.
	 * @param resultados Vetor de resultados.
	 * @param f Ponteiro para o ficheiro onde gravar.
	 */
	void RelatorioCSV(TVector<TResultado>& resultados, FILE* f);

	/**
	 * @brief Extrai uma lista de inteiros a partir de uma string.
	 * @param str String a analisar.
	 * @return Vetor de inteiros extraídos.
	 */
	TVector<int> ExtraiLista(char* str);

	/**
	 * @brief Insere configurações a partir de uma string.
	 * @param str String com as configurações.
	 * @param base Vetor base para inserção.
	 */
	void InserirConfiguracoes(char* str, TVector<int>& base);

	/**
	 * @brief Insere configurações gerando o produto cartesiano de valores.
	 * @param base Vetor base.
	 * @param produto Vetor para resultados.
	 * @param valores Vetor de vetores de valores possíveis.
	 */
	void InserirConfiguracoes(TVector<int>& base, TVector<int>& produto, TVector<TVector<int>>& valores);

	/**
	 * @brief Mostra ajuda de utilização do programa.
	 * @param programa Nome do programa.
	 */
	void AjudaUtilizacao(const char* programa);

	/**
	 * @brief Limita o domínio de um parâmetro inteiro.
	 * @param variavel Variável a limitar.
	 * @param min Valor mínimo permitido.
	 * @param max Valor máximo permitido.
	 * @return Valor ajustado dentro do domínio.
	 */
	static int Dominio(int& variavel, int min = INT_MIN, int max = INT_MAX);
};

