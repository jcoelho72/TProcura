﻿#pragma once

#define _CRT_SECURE_NO_WARNINGS

#include "TVector.h"
#include <stdint.h>
#include <time.h>
#include <limits.h>

// número de elementos na hashtable com perdas
#define TAMANHO_HASHTABLE 1000000
// tamanho máximo de um objecto, em unidades de 64 bits
#define OBJETO_HASHTABLE 5
// código para número não lido (não deve ser utilizado num parâmetro)
#define NAO_LIDO -1000000

class TProcuraConstrutiva;

/**
 * @brief Representa um nó na árvore de busca, apontando para um estado.
 *
 * @note É um alias para `TProcuraConstrutiva*`, facilitando a leitura e uso.
 */
typedef TProcuraConstrutiva* TNo;

/**
 * @enum EParametrosConstrutiva
 * @brief Identifica um parâmetro específico no código.
 *
 * Permite aceder a cada parâmetro sem precisar saber seu código numérico.
 * Índice do vetor de parametros, na classe TProcuraConstrutiva. 
 *
 * @note O último elemento (`parametrosConstrutivas`) não representa um parâmetro real.
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
enum EParametrosConstrutiva {
	algoritmo = 0,         ///< Algoritmo base a executar.
	nivelDebug,            ///< Nível de debug, de reduzido a completo.
	verAcoes,              ///< Mostra estado a cada K ações. Se 1, mostra sempre estados e nunca ações.
	seed,                  ///< Semente aleatória para inicializar a sequência de números pseudo-aleatórios.
	limiteTempo,           ///< Tempo limite em segundos. 
	limiteGeracoes,        ///< Número máximo de gerações (0 significa sem limite).
	limiteExpansoes,       ///< Número máximo de expansões (0 significa sem limite).
	limiteAvaliacoes,      ///< Número máximo de avaliações (0 significa sem limite).
	limite,                ///< Valor dependente do algoritmo. Exemplo: Profundidade limitada.
	estadosRepetidos,      ///< Forma de lidar com estados repetidos (ignorá-los, ascendentes, gerados).
	pesoAStar,             ///< Peso aplicado à heuristica, na soma com o custo para calculo do lower bound. 
	ruidoHeur,             ///< Ruído a adicionar à heurística para testes de robustez.
	baralharSuc,           ///< Baralhar os sucessores ao expandir.
	parametrosConstrutivas ///< Marcador para permitir a extensão do enum em subclasses.
};


/**
 * @brief Algoritmos disponíveis para procura construtiva.
 *
 * Estes algoritmos utilizam diferentes estratégias de expansão de estados
 * e podem ser ajustados conforme os parâmetros de execução.
 *
 * @see EParametrosConstrutiva
 */
enum EAlgoritmo {
	larguraPrimeiro = 1, ///< Executa a procura em largura primeiro, algoritmo cego. @see TProcuraConstrutiva::LarguraPrimeiro()
	custoUniforme,       ///< Executa a procura por custo uniforme, algoritmo cego. @see TProcuraConstrutiva::CustoUniforme()
	profundidadePrimeiro,///< Executa a procura em profundidade primeiro, algoritmo cego. @see TProcuraConstrutiva::ProfundidadePrimeiro()
	melhorPrimeiro,      ///< Executa a procura melhor primeiro, algoritmo informado. @see TProcuraConstrutiva::MelhorPrimeiro()
	aStar,               ///< Executa a procura A*, algoritmo informado. @see TProcuraConstrutiva::AStar()
	idAStar,             ///< Executa a procura IDA*, algoritmo informado. @see TProcuraConstrutiva::IDAStar()
	branchAndBound       ///< Executa o algoritmo Branch-and-Bound, um algoritmo informado. @see TProcuraConstrutiva::BranchAndBound()
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
 * @brief Enumerado com os valores possíveis do parametro estadosRepetidos
 * 
 * Os estados gerados que sejam repetidos, podem não ser removidos, ou podem ser 
 * removidos se existir um ascendente igual, ou ainda serem guardados numa hashtable
 * de modo a serem removidos todos os estados gerados que sejam repetidos. 
 * 
 * @see Sucessores(), estadosRepetidos
 */
enum EEstadosRepetidos { 
	ignorados = 1, ///< ignorados os estados gerados repetidos
	ascendentes,   ///< estados são comparados com ascendentes, e se forem repetidos são removidos
	gerados        ///< estados são comparados com todos os gerados, e se forem repetidos são removidos
};

/**
 * @brief Define o sentido da operação de entrada/saída de dados.
 *
 * @note Utilizado em funções que requerem distinção entre operação de leitura e gravação.
 */
enum EOperacao { gravar = 0, ler };

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
 * @see EParametrosConstrutiva e ResetParametros()
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
	int instancia, custo, expansoes, geracoes, avaliacoes, configuracao; 
	clock_t tempo; 
} TResultado;

/**
 * @brief Representa um estado no espaço de estados.
 *
 * Esta classe base deve ser redefinida com um problema concreto,
 * permitindo a execução de procuras construtivas. 
 *
 * Para utilizar a classe, é necessário:
 * - Redefinir os métodos de duplicação e cópia de estados (Duplicar() e Copiar()).
 * - Implementar funções essenciais de procura: SolucaoVazia(), SolucaoCompleta(),
 *   Sucessores() e Debug().
 * 
 * Permite execução dos algoritmos:
 * - **Cegos**: LarguraPrimeiro(), CustoUniforme(), ProfundidadePrimeiro() 
 * - **Informados**: MelhorPrimeiro(), AStar(), IDAStar(), BranchAndBound()
 * - **Testes e avaliação**: TesteManual(), TesteEmpirico()
 *
 * **Observação:** Alguns métodos e parâmetros terão efeito apenas se determinados métodos forem
 * redefinidos na subclasse.
 */
class TProcuraConstrutiva
{
public:
	TProcuraConstrutiva(void);
	virtual ~TProcuraConstrutiva(void) {}

	/**
	 * @defgroup VariaveisEstado Variáveis de estado
	 * Variáveis de estado que pertencem a cada instância da classe.
	 * Na implementação do problema concreto, defina as variáveis necessárias para armazenar a informação do estado.
	 * @{
	 */

	/// @brief Ponteiro para o estado pai, na árvore de procura.
	TNo pai;
	/// @brief Custo total acumulado desde o estado inicial.
	int custo;
	/// @brief Estimativa para o custo até um estado objetivo, se disponível.
	int heuristica;

	/** @} */ // Fim do grupo VariaveisEstado 


	/**
	 * @defgroup RedefinicaoMandatoria Métodos para redefinir mandatórios
	 * Métodos de redefinição obrigatória no problema
	 * @{
	 */

	 /**
	  * @brief Cria um objecto que é uma cópia deste.
	  * @note Obrigatória a redefinição.
	  *
	  * Este método tem de ser criado na subclasse, de modo a criar uma cópia
	  * do mesmo tipo.
	  * O código da subclasse geralmente segue um padrão e pode utilizar
	  * o modelo abaixo, aproveitando o método Copiar().
	  * É especialmente útil na função de Sucessores(), na geração de um novo estado.
	  *
	  * @return Retorna o novo estado, acabado de gerar.
	  *
	  * @note Caso exista falha de memória, colocar a variável memoriaEsgotada a true,
	  * para tentativa de terminar a execução de forma graciosa.
	  *
	  * @code
	  * TNo CSubClasse::Duplicar(void)
	  * {
	  *     CSubClasse* clone = new CSubClasse;
	  * 	   if(clone!=NULL)
	  * 	       clone->Copiar(this);
	  * 	   else
	  * 		    memoriaEsgotada = true;
	  * 	   return clone;
	  * }
	  * @endcode
	  */
	virtual TNo Duplicar(void) = 0;

	/**
	 * @brief Fica com uma cópia do objecto.
	 * @note Obrigatória a redefinição.
	 *
	 * Este método tem de ser criado na subclasse, de modo a um estado poder ficar
	 * igual a outro. As variáveis de estado, devem ser todas copiadas.
	 *
	 * Deve garantir que as variáveis copiadas sejam suficientes para reconstruir o estado corretamente.
	 * No entanto, uma instância pode ter dados que não mudam em cada estado. Essas
	 * variáveis não precisam de estar no estado, e podem ser alocadas de forma estática
	 * na subclasse, não sendo necessário copiar nesta função.
	 *
	 * A não ser que exista uma estrutura de dados completa, o modelo de código em baixo
	 * pode ser facilmente reproduzido para qualquer subclasse.
	 *
	 * @note Não é preciso copiar as variáveis da classe TProcuraConstrutiva, pai, custo, heuristica.
	 * @see Sucessores() e Heuristica()
	 *
	 * @code
	 * void CSubClasse::Copiar(TNo objecto) {
	 * 		CSubProblema& obj = *((CSubProblema*)objecto);
	 * 		// copiar todas as variáveis do estado
	 * 		variavel = obj.variavel;
	 * 	}
	 * @endcode
	 */
	virtual void Copiar(TNo objecto) { }

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
	 * void CSubProblema::SolucaoVazia(void)
	 * {
	 *     TProcuraConstrutiva::SolucaoVazia();
	 * 	   // acertar as variáveis estáticas, com a instância (ID: instancia.valor)
	 * 	   CarregaInstancia(); // exemplo de método em CSubProblema para carregar uma instância
	 *     // inicializar todas as variáveis de estado
	 * 	   variavel = 0;
	 *     // Determinar o tamanho máximo do estado codificado, se aplicável
	 * 	   tamanhoCodificado = 1;
	 * }
	 * @endcode
	 */
	virtual void SolucaoVazia(void) { custo = 0; }

	/**
	 * @brief Coloca em sucessores a lista de estados sucessores
	 * @note Obrigatória a redefinição.
	 * @param sucessores - variável com a lista de estados sucessores a retornar.
	 *
	 * Este é o método principal, que define a árvore de procura.
	 * Para o estado atual, duplicar o estado por cada ação / estado que seja sucessor.
	 * Alterar as variáveis de estado para corresponderem à ação efetuada no estado sucessor.
	 * Caso o custo não seja unitário, definir o custo da ação.
	 * Chamar o método da superclasse no final, já que irá atualizar estatísticas,
	 * bem como eliminar estados que sejam repetidos, dependendo da parametrização.
	 *
	 * @note O custo da ação deve ser definido aqui, mas ao chamar Sucessores() da superclasse,
	 * ele será acumulado para representar o custo total desde o estado inicial.
	 * @note O método Duplicar() já coloca as variáveis de estado iguais ao estado atual.
	 * Apenas modifique as variáveis de estado que precisam refletir a ação i.
	 * @note Caso seja feita uma verificação e a ação afinal não é válida, apagar o estado.
	 * @note Não é preciso considerar estados repetidos, a verificação será feita na superclasse.
	 *
	 * @code
	 * void CSubProblema::Sucessores(TVector<TNo>&sucessores)
	 * {
	 *     CSubProblema* novo;
	 *     for(int i = 0; i < numeroAcoes; i++) {
	 *         sucessores.Add(novo = (CSubProblema*)Duplicar());
	 *         // aplicar a ação i nas variáveis de estado
	 *         novo->variavel = i;
	 * 		   // se o custo não for unitário, indicar o custo da ação
	 *         novo->custo = 1 + i / 10;
	 *         // Caso o estado gerado não seja válido, remova-o da lista e liberte a memória:
	 *         if (!novo->EstadoValido()) // exemplo de método em CSubProblema para verificar a validade
	 *             delete sucessores.Pop();
	 * 	   }
	 *     TProcuraConstrutiva::Sucessores(sucessores);
	 * }
	 * @endcode
	 */
	virtual void Sucessores(TVector<TNo>& sucessores);

	/**
	 * @brief Verifica se o estado actual é objectivo (é uma solução completa)
	 * @note Obrigatória a redefinição.
	 * @return Retorna verdadeiro se é um estado objetivo, ou falso caso contrário.
	 *
	 * Este método verifica se o estado atual é objetivo, e portanto temos uma solução completa.
	 * A complexidade da verificação depende do problema, podendo ser um teste simples ou
	 * envolver múltiplas condições.
	 *
	 * @note Este método será chamado pelos algoritmos de procura no momento adequado,
	 * **não necessariamente na geração de sucessores**. Por isso, deve ser implementado
	 * separadamente de `Sucessores()`, garantindo que a avaliação do objetivo seja feita
	 * apenas quando necessário.
	 *
	 * @code
	 * bool CSubProblema::SolucaoCompleta(void) {
	 *     // pode ser um simples teste, ou algo mais complexo, dependente do problema
	 *     // verificar se as condições pretendidas estão satisfeitas
	 *     return variavel > 1000;
	 * }
	 * @endcode
	 */
	virtual bool SolucaoCompleta(void) { return false; }

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

	 /** @} */ // Fim do grupo RedefinicaoMandatoria

	/**
	 * @defgroup RedefinicaoSugerida Métodos para redefinir, sugeridos
	 * Métodos de redefinição aconselhados a uma boa implementação
	 * @{
	 */

	 /**
	  * @brief Retorna a ação (movimento, passo, jogada, lance, etc.) que gerou o sucessor
	  * @note Redefinição opcional.
	  * @param sucessor - estado filho deste, cuja ação deve ser identificada
	  * @return texto identificando a ação, pode ser uma constante
	  *
	  * Este método não é crítico, mas é importante para se poder visualizar ações.
	  * Se este método não for redefinido, a interface mostrará apenas os estados completos,
	  * sem detalhar as ações que os geraram.
	  *
	  * Durante a exploração manual do espaço de estados, permitir que ações sejam fornecidas
	  * diretamente, ao invés de depender do ID do sucessor, facilita testes e integração com outros sistemas.
	  * Esta situação é vantajosa, para permitir introduzir uma sequência de ações, que eventualmente
	  * venha de outro programa, permitindo assim a validação da solução.
	  *
	  * @code
	  * const char* CSubProblema::Acao(TNo sucessor) {
	  *     CSubProblema& filho = *((CSubProblema*)sucessor);
	  *     // determinar pela diferença das variáveis de estado, a ação
	  *     // exemplo de ações hipotéticas de manter, incrementar ou decrementar o valor da variável
	  *     if(variavel == filho.variavel)
	  *         return "manter";
	  *     if(variavel == filho.variavel + 1)
	  *         return "inc";
	  *     if(variavel == filho.variavel - 1)
	  *         return "dec";
	  *     return "Inválida";
	  * }
	  * @endcode
	  */
	virtual const char* Acao(TNo sucessor) { return "ação inválida"; }

    /**
	 * @brief Codifica o estado para um vetor de inteiros de 64 bits
	 * @note Redefinição opcional. Necessário para identificação de estados repetidos por hashtable.
	 *
	 * As variáveis de estado devem ser compactadas no vetor de inteiros de 64 bits.
	 * Todos os estados codificados têm de ser distintos de 0. Estados distintos, têm de 
	 * ficar com codificações distintas. 
	 * 
	 * Em diversos problemas, um mesmo estado pode ter múltiplas representações equivalentes.
	 * Por exemplo, se um conjunto de inteiros for um estado, este pode ser  representado em vetor.
	 * No entanto a ordem é irrelevante, dado que é um conjunto.
	 * Assim não faz sentido guardar vários estados que sejam representações do mesmo estado.
	 * Há que normalizar o estado antes de o guardar, de modo a que seja dado como estado repetido, 
	 * se uma das duas formas já tiver sido gerada.
	 * O exemplo do conjunto de inteiros, a normalização pode ser a ordenação do vetor,
	 * constituindo assim um estado único entre todas as formas que o conjunto pode ser representado em vetor.
	 * Problemas de tabuleiro, há simetrias que podem gerar várias versões da mesma posição.
	 * 
	 * @note Se a verificação de estados repetidos for baseada em hashtables,
	 * a superclasse chama este método dentro de `Sucessores()`.
	 * @note Para otimizar o consumo de memória, são utilizadas hashtables com perdas.
	 * Se necessário pode alterar o tamanho da hashtable editando a macro TAMANHO_HASHTABLE
	 * @note a variável tamanhoCodificado tem de ter o número de variáveis de 64 bits utilizadas,
	 * garantindo que o vetor estado[] não é acedido na posição tamanhoCodificado ou superior.
	 * 
	 * @see SolucaoVazia()
	 *
	 * @code
	 * void CSubProblema::Codifica(uint64_t estado[OBJETO_HASHTABLE])
	 * {
	 *     Vector<int> vetor; // assumindo neste exemplo que o estado é um vetor de inteiros pequenos
	 *     Normalizar(vetor); // o vetor tem várias formas, e agora é normalizado por uma função de CSubProblema
	 *     TProcuraConstrutiva::Codifica(estado); // chamar a superclasse após normalizar o estado
	 *     // codificar números de 4 bits, assumindo que os inteiros pequenos cabem em 4 bits
	 *     for (int i = 0, index = 0; i < vetor.Count(); i++, index += 4)
	 *         estado[index >> 6] |= (uint64_t)vetor[i] << (index & 63);
	 * }
	 * @endcode
	 */
	virtual void Codifica(uint64_t estado[OBJETO_HASHTABLE]);

	/**
	 * @brief Função para calcular quanto falta para o final, o valor da heurística.
	 * @note Redefinição opcional. Necessário para utilizar os algoritmos informados.
	 * @return Retorna a melhor estimativa, sem ultrapassar a real, do custo do estado atual até ao objetivo.
	 *
	 * A função heurística é crítica para utilizar os algoritmos informados.
	 * Deve devolver uma estimativa sem ultrapassar o custo real, 
	 * do custo que falta para atingir o estado objetivo mais próximo do estado atual. 
	 * Se a estimativa não ultrapassar o custo real, a heurística será **admissível**. 
	 * No entanto, em alguns casos, heurísticas **não admissíveis** podem ser utilizadas, 
	 * podendo acelerar a procura, mesmo que ocasionalmente levem a resultados subótimos.
	 * 
	 * No final, chame a função heurística da superclasse para atualizar as estatísticas 
	 * e o número de avaliações. Se estiver configurado, esse processo também pode introduzir 
	 * ruído na heurística, o que pode impactar certos algoritmos de procura.
	 * 
	 * Esta função pretende-se rápida, e o mais próxima possível do valor real, sem ultrapassar. 
	 * 
	 * @note Num problema, existindo alternativas, umas mais rápidas menos precisas,
	 * outras mais lentas mais precisas, é aconselhada a criação de um ou mais parametros
	 * para que a heurística possa ser calculada de acordo com o parametro definido. 
	 * Em fase de testes logo se averigua qual a versão que adiciona mais vantagem à procura.
	 * 
	 * @note Uma heurística pode resultar de um relaxamento do problema. Verifique se 
	 * o problema sem uma das restrições (fazendo batota), se consegue resolver mais facilmente.
	 * Utilize como heurística o custo de resolver o problema sem essa restrição.
	 * 
	 * @code
	 * void CSubProblema::Heuristica(void)
	 * {
	 *     heuristica = 0; // ponto de partida, há 0 de custo
	 *     // utilizar neste exemplo a distância até 1000, local onde estará o objetivo
	 *     heuristica = abs(variavel - 1000); 	
	 *     // chamar a função heurística da superclass
	 *     return TProcuraConstrutiva::Heuristica();
	 * }
	 * @endcode
	 */
	virtual int Heuristica(void);

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
	 *     TProcuraConstrutiva::ResetParametros();
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


	 /** @} */ // Fim do grupo RedefinicaoSugerida

	/**
	 * @defgroup RedefinicaoOpcional Métodos desnecessários redefinir
	 * Métodos que não precisam ser redefinidos para uma implementação eficaz
	 * @{
	 */

	/**
	 * @brief Executa a ação (movimento, passo, jogada, lance, etc.) no estado atual.
	 * @note Redefinição caso necessário. A implementação é já genérica.
	 * @param acao - texto com a ação a executar
	 * @return Retorna verdadeiro, mas caso não seja feito uma ação, devido a ser impossível, retornar falso.
	 *
	 * @note A implementação gera os sucessores, e vê qual o que corresponde à ação fornecida.
	 * Copia o estado correspondente para o atual, ou retorna falso caso a ação não seja possível.
	 * O método não é eficiente, mas também não utilizado pelos algoritmos, apenas na interface. 
	 * Caso exista um motivo para que seja eficiente, deve ser implementada uma versão mais eficiente 
	 * para cada problema, tendo em atenção a sua coerência com a função Sucessores().
	 */
	virtual bool Acao(const char* acao);

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
		return TempoExcedido() || ExpansoesExcedido() || GeracoesExcedido() || AvaliacoesExcedido() || memoriaEsgotada;
	}

	/**
	 * @brief Verifica se o estado actual distinto do fornecido
	 * @note Redefinição opcional. Necessário para identificação de estados repetidos por teste de ascendentes.
	 * @return Retorna verdadeiro se o estado é distinto, e falso se é igual
	 *
	 * Compara as variáveis de estado para determinar se dois estados são iguais ou diferentes.
	 * 
	 * @note Se a verificação de estados repetidos for baseada na análise de ascendentes, 
	 * a superclasse chama este método dentro de `Sucessores()`.
	 *
	 * @code
	 * bool CSubProblema::Distinto(TNo estado) {
	 *     CSubProblema& outro = *((CSubProblema*)estado);
	 *     // verificar todas as variáveis de estado
	 *     return variavel != outro.variavel;
	 * }
	 * @endcode
	 */
	virtual bool Distinto(TNo estado) { return true; }

	/**
	 * @brief Mostrar solução, seja um caminho ou o próprio estado
	 * @note Redefinição opcional. 
	 * 
	 * Esta função exibe a solução, mostrando um estado a cada X ações 
	 * e exibindo as ações entre os estados. O valor padrão de `X` é 4, 
	 * ajustável pelo parâmetro `parametro[verAcoes].valor`.
	 * 
	 * @note Em problemas onde seja simples de seguir a ação, pode-se utilizar valores maiores, sem
	 * ser necessário mostrar muitos estados completos. Em problemas que as ações sejam mais complexas,
	 * ou alterem mais o estado, poderá ser até preferível colocar este valor a 1, para que o estado
	 * seja sempre mostrado em cada ação.
	 *
	 * @note Há problemas em que o estado é já a solução. Neste caso pode-se redefinir esta função
	 * chamando a função Debug().
	 * 
	 * @note Em situações particulares, poderá ser possível construir a solução de forma
	 * mais compacta, num único estado com as ações todas codificadas, por exemplo um caminho
	 * num mapa. Nesse caso há que redefinir este método, implementando a visualização da solução de raiz. 
	 * 
	 * @code
	 * void CSubProblema::MostrarSolucao(void)
	 * {
	 *     // caso o estado final seja a solução, simplesmente mostrar o estado atual
	 *     Debug();
	 *     // caso seja um caminho do estado inicial ao final, não redefinir
	 * }
	 * @endcode
	 */
	virtual void MostrarSolucao(void) { MostrarCaminho(); }

	/**
	 * @brief Executa o algoritmo com os parametros atuais
	 * @note Redefinição necessária no caso de se alterar os algoritmos disponíveis.
	 *
	 * No caso de adicionar algum algoritmo, chame o algoritmo com base em parametro[algoritmo].valor
	 * Se `TesteManual()` não for utilizado, esta função pode ser chamada diretamente,
	 * desde que os parâmetros necessários já estejam configurados corretamente.
	 *
	 * @see TesteManual(), EParametrosConstrutiva, LarguraPrimeiro(), CustoUniforme(), ProfundidadePrimeiro()
	 * @see MelhorPrimeiro(), AStar(), IDAStar(), BranchAndBound()
	 */
	virtual int ExecutaAlgoritmo();

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

	/** @} */ // Fim do grupo RedefinicaoOpcional


	/**
	 * @defgroup ProcurasCegas Algoritmos de Procura Cega
	 * Métodos que executam algoritmos de procura sem utilização de heurística.
	 * @{
	 */

	 /**
	  * @brief Executa a procura em largura primeiro, algoritmo cego.
	  * @param limite Com valor 0, executa sem limite. Se maior que 0, 
	  * os estados não expandidos são limitados a este valor.
	  * @return Retorna o valor da solução, ou -1 em caso de falha.
	  *
	  * O algoritmo expande primeiro os estados mais antigos. 
	  * Assim, somente após todos os estados de nível K serem expandidos,
	  * os estados de nível K+1 começam a ser expandidos.
	  *
	  * Caso o custo de cada ação seja unitário, o algoritmo retorna a solução ótima. 
	  * Se o custo for variável, pode não retornar a solução ótima.
	  *
	  * @note Se o limite de número de estados for atingido, 
	  * os estados gerados mais recentemente são removidos.
	  * 
	  * @see EAlgoritmo, ExecutaAlgoritmo();
	  */
	int LarguraPrimeiro(int limite = 0);


	/**
	 * @brief Executa a procura por custo uniforme, algoritmo cego.
	 * @param limite Com valor 0, executa sem limite. Se maior que 0, limita os estados gerados não expandidos a esse valor.
	 * @return Retorna o valor da solução, ou -1 em caso de falha.
	 *
	 * Semelhante à procura em largura, mas os estados são ordenados pelo custo. 
	 * Dessa forma, os estados de menor custo são expandidos antes dos de custo maior, 
	 * o que preserva a optimalidade mesmo quando os custos são variáveis.
	 *
	 * @note Se o limite de número de estados for atingido, os estados gerados mais recentemente são removidos.
	 *
	 * @see LarguraPrimeiro(), EAlgoritmo, ExecutaAlgoritmo();
	 */
	int CustoUniforme(int limite = 0);

	/**
	 * @brief Executa a procura em profundidade primeiro, algoritmo cego.
	 * @param nivel Se -1, efetua a procura em profundidade sem limite.
	 *              Se 0, efetua a procura iterativa, incrementando o nível a cada iteração.
	 *              Se um valor positivo, efetua a procura limitada a esse nível de profundidade.
	 * @return Retorna o valor da solução, ou -1 em caso de falha.
	 *
	 * O algoritmo expande os estados mais recentes primeiro, explorando em profundidade 
	 * antes de avaliar os estados vizinhos.
	 * Não garante a solução ótima e está implementada na versão recursiva.
	 * 
	 * @see EAlgoritmo, ExecutaAlgoritmo();
	 */
	int ProfundidadePrimeiro(int nivel = 0);

	/** @} */ // Fim do grupo ProcurasCegas

	/**
	 * @defgroup ProcurasInformadas Algoritmos de Procura Informada
	 * Métodos que executam algoritmos de procura utilizando heurística para orientar a procura.
	 * @{
	 */

	 /**
	  * @brief Executa a procura melhor primeiro, algoritmo informado.
	  * @param nivel Se 0 ou menor, efetua a procura em profundidade sem limite.
	  *              Se um valor positivo, efetua a procura limitada a esse nível de profundidade.
	  * @return Retorna o valor da solução, ou -1 em caso de falha.
	  *
	  * Este algoritmo funciona similarmente à procura em profundidade primeiro, mas os sucessores são
	  * ordenados de acordo com o valor da heurística. Assim, os estados com menor valor de heurística
	  * em cada nível são explorados primeiramente.
	  * Note que não garante a solução ótima e a implementação é recursiva.
	  *
	  * @see ProfundidadePrimeiro(), EAlgoritmo, ExecutaAlgoritmo();
	  */
	int MelhorPrimeiro(int nivel = 0);

	/**
	 * @brief Executa a procura A*, algoritmo informado.
	 * @param limite Com valor 0, executa sem limite. Se maior que 0, limita o número de estados gerados não expandidos.
	 * @return Retorna o valor da solução, ou -1 em caso de falha.
	 *
	 * Este algoritmo é semelhante ao Custo Uniforme, mas os estados são ordenados pelo lower bound,
	 * definido como o custo acumulado somado à heurística, ou seja, o mínimo custo ótimo da instância.
	 * Dessa forma, os estados com menor lower bound são expandidos primeiro, o que preserva a
	 * propriedade de optimalidade.
	 *
	 * @note Se o limite do número de estados for atingido, os estados gerados com maior lower bound serão removidos.
	 * @note O parâmetro parametro[pesoAStar].valor, com valor padrão 100, indica o peso (em percentagem) que a heurística
	 * terá no cálculo do lower bound. Se esse valor for reduzido, a heurística terá menor peso (pode chegar a 0, fazendo com
	 * que o algoritmo se comporte como o Custo Uniforme). Se for aumentado acima de 100, a heurística terá mais influência,
	 * aproximando a estratégia do Melhor Primeiro. Dessa forma, esse parâmetro permite modelar uma gama de estratégias entre
	 * Custo Uniforme, A* e Melhor Primeiro, o que pode resultar em melhor desempenho para determinados problemas.
	 *
	 * @note Se a procura for interrompida, é possível extrair um lower bound, embora isso não permita a obtenção de uma solução.
	 *
	 * @see CustoUniforme(), MelhorPrimeiro(), EAlgoritmo, ExecutaAlgoritmo();
	 */
	int AStar(int limite = 0);

	/**
	 * @brief Executa a procura IDA*, algoritmo informado.
	 * @param upperBound Se 0, executa a procura iterativa. Se for um valor positivo, efetua a procura limitada por esse upper bound.
	 * @return Retorna o valor da solução, ou -1 em caso de falha.
	 *
	 * Este algoritmo funciona similarmente ao Melhor Primeiro, mas limita a expansão da árvore com base no
	 * lower bound atual (custo acumulado mais heurística), em vez de limitar a profundidade. Trata-se de uma
	 * versão iterativa cuja nova limitação é determinada pelo melhor valor (mais baixo) dentre os estados descartados
	 * na iteração anterior, garantindo a obtenção da solução ótima.
	 *
	 * A ordem de expansão dos estados é a mesma do A*, pois utiliza o mesmo critério de lower bound. Porém, por ser
	 * um algoritmo de procura em profundidade, não sofre problemas de memória.
	 *
	 * @note Se a procura for interrompida, é possível extrair um lower bound, embora isso não permita a obtenção de uma solução.
	 *
	 * @see MelhorPrimeiro(), AStar(), EAlgoritmo, ExecutaAlgoritmo();
	 */
	int IDAStar(int upperBound = 0);

	/**
	 * @brief Executa o algoritmo Branch-and-Bound, um algoritmo informado.
	 * @param upperBound Se 0, executa a procura sem limite. Se for um valor positivo, efetua a procura limitada por esse upper bound.
	 * @return Retorna o valor da solução, ou -1 em caso de falha.
	 *
	 * Este algoritmo opera de forma semelhante ao Melhor Primeiro, mas, após encontrar uma solução, continua a
	 * explorar, eliminando todos os ramos cujo lower bound indique que não há possibilidade de melhorar a solução atual.
	 *
	 * Se o algoritmo iniciar com um upperBound definido, funcionará como se essa solução já tivesse sido encontrada,
	 * descartando todos os ramos que possam levar a soluções de custo igual ou superior. Embora isso possa resultar
	 * na exclusão de ramos muito longos, também podem remover ramos que eventualmente pudessem conduzir à solução.
	 * Caso o algoritmo retorne sem uma solução, não se pode afirmar com certeza que ela não exista.
	 *
	 * @note Se a procura for interrompida, é possível extrair um upper bound, apesar de não haver garantia de que seja o ótimo.
	 *
	 * @see MelhorPrimeiro(), EAlgoritmo, ExecutaAlgoritmo();
	 */
	int BranchAndBound(int upperBound = 0);

	/** @} */ // Fim do grupo ProcurasInformadas

	/**
	 * @defgroup VariaveisGlobais Variáveis globais à classe
	 * Essas variáveis são compartilhadas por todas as execuções do algoritmo.
	 * O fato de serem globais evita cópias desnecessárias, mas impede a execução simultânea de múltiplas corridas.
	 * @{
	 */

	 /// @brief ID da instância atual, a ser utilizado em SolucaoVazia().
	static TParametro instancia;
	/// @brief Parâmetros a serem utilizados na configuração atual.
	/// @see EParametrosConstrutiva
	static TVector<TParametro> parametro;
	/// @brief Conjuntos de configurações para teste empírico.
	static TVector<TVector<int>> configuracoes;
	/// @brief Número total de gerações realizadas na procura.
	static int geracoes;
	/// @brief Número total de expansões realizadas na procura.
	static int expansoes;
	/// @brief Número total de avaliações realizadas na procura.
	static int avaliacoes;
	/// @brief Solução retornada pela procura (os estados devem ser libertados).
	static TVector<TNo> caminho;
	/// @brief Flag indicando problemas de memória esgotada.
	static bool memoriaEsgotada;
	/// @brief Estado objetivo encontrado, retornado pela procura (deve ser libertado).
	static TNo solucao;
	/// @brief Valor mínimo que a solução pode apresentar, obtido pela procura.
	static int lowerBound;
	/// @brief Número de inteiros de 64 bits utilizados para codificar um objeto (≤ OBJETO_HASHTABLE).
	static int tamanhoCodificado;

	/// @internal Auxiliar para a construção da árvore de procura.
	static TVector<unsigned char> ramo;
	/// @internal Espaçamento entre os ramos na árvore de debug.
	static int espacosRamo;
	/// @internal Instante final (deadline) da corrida atual.
	static clock_t instanteFinal;

	/** @} */ // Fim do grupo VariaveisGlobais

	// LimparEstatisticas: Chamar antes da corrida
	void LimparEstatisticas(clock_t &inicio);
	// FinalizarCorrida: Chamar após a corrida
	void FinalizarCorrida(clock_t inicio);

	int LowerBound() { return custo + parametro[pesoAStar].valor * heuristica / 100; } // f(n) = g(n) + W h(n)
	static void LibertarVector(TVector<TNo>& vector, int excepto = -1, int maiorQue = -1);

	// Chamar sempre que se quer uma nova linha com a árvore em baixo
	void NovaLinha(bool tudo = true);

	// ler um número, ou retorna NAO_LIDO
	static int NovoValor(const char* prompt); 

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
	void ExplorarSucessores(bool jogo=false);
	void EditarParametros();
	void EditarConfiguracoes();
	void MostrarConfiguracoes(int detalhe, int atual = -1);
	void SolicitaInstancia();
	bool TempoExcedido() { return instanteFinal < clock(); }
	bool GeracoesExcedido() {
		return parametro[limiteGeracoes].valor > 0 && parametro[limiteGeracoes].valor < geracoes;
	}
	bool ExpansoesExcedido() {
		return parametro[limiteExpansoes].valor > 0 && parametro[limiteExpansoes].valor < expansoes;
	}
	bool AvaliacoesExcedido() {
		return parametro[limiteAvaliacoes].valor > 0 && parametro[limiteAvaliacoes].valor < avaliacoes;
	}
	void MostrarCaminho();
	void MostraParametros(int detalhe = 1, TVector<int>* idParametros = NULL);
	void MostraRelatorio(TVector<TResultado>& resultados);
	int Dominio(int& variavel, int min = INT_MIN, int max = INT_MAX);
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
	static int colocadosHT; // número de elementos colocados na HT
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