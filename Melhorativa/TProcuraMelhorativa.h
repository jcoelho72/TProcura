#pragma once

#include "../TProcura.h"

// um ponto no espaço de estados das soluções completas, é um apontador para um estado 
class TProcuraMelhorativa;
typedef TProcuraMelhorativa* TPonto;

// nomes dos parâmetros fixos na procura melhorativa
enum EMelhorativas {
	POPULACAO = PARAMETROS_PROCURA, PROB_CRUZAR,
	PROB_MUTAR, SELECAO, PRESSAO, TAMANHO_TORNEIO, 
	PROB_MELHOR_TORNEIO, SOBREVIVENCIA, PERC_DESCENDENTES, 
	Q_ROUND_ROBIN, ELITISMO, IMIGRANTES, 
	DIVERSIDADE, DIST_MINIMA, //MOVE_PRIMEIRO,
	PARAMETROS_MELHORATIVA
};

enum EIndicadoresConstrutiva {
	IND_EPOCAS = IND_PROCURA,    ///< Número de épocas decorridas num algoritmo evolutivo. Uma época é uma geração única. 
	IND_GERACOES,               ///< número de estados gerados durante a procura
	IND_MELHORATIVA             ///< Marcador para permitir a extensão do enum em subclasses.
};


///////////////////////////////////////////////////////////////////////////////
//	TProcuraMelhorativa class
///////////////////////////////////////////////////////////////////////////////
//	Author: José Coelho
//	Last revision: 2025-01-30
//	Description:
//    Superclasse de procuras no espaço das soluções completas (a solução é melhorada).
//    As variaveis da classe devem ser apenas de uma solucao, se existir informação
//    sobre a instancia, esta informação deve ser colocada em variaveis estáticas
//    para não serem duplicadas desnecessariamente.
//	  A única variavel é o valor da solução que após ser calculada em Avaliar
//	  deve ser actualizada (se o valor não estiver actualizado, deve ter -1)
///////////////////////////////////////////////////////////////////////////////
class TProcuraMelhorativa :
	public TProcura
{
public:
	TProcuraMelhorativa(void);
	~TProcuraMelhorativa(void);

	/// @brief Custo total, atualizada após Avaliar()
	int custo = -1;
	/// @brief Lower Bound, se existir
	static int lowerBound;
	/// @brief Número de estados gerados 
	static int geracoes;
	/// @brief Número de épocas decorridas num algoritmo evolutivo. Uma época é uma geração única. 
	static int epocas;

	///////////////////////////////////////////////////////////////////////////////
	// Métodos para redefinir
	///////////////////////////////////////////////////////////////////////////////

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
	  * TPonto CSubClasse::Duplicar(void)
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
	virtual TPonto Duplicar(void) = 0;

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
	 * void CSubClasse::Copiar(TPonto objecto) {
	 * 		CSubProblema& obj = *((CSubProblema*)objecto);
	 * 		// copiar todas as variáveis do estado
	 * 		variavel = obj.variavel;
	 * }
	 * @endcode
	 */
	virtual void Copiar(TPonto objecto) {}

	virtual void NovaSolucao(void) {}
	// Retorna o valor da solução completa actual. Atribuir o valor a custo
	virtual int Avaliar(void);
	// redefinir, para aceitar ações que sejam operadores
	bool Acao(const char* acao) { return false; }
	// Método para inicializar os parâmetros (redefinir se forem adicionados parâmetros específicos)
	void ResetParametros() override;

	// critrio de paragem adicionado para procuras melhorativas:
	// - custo nulo, significa obter o ótimo (lowerBound pode ser atualizado, caso exista, de omissão é 0)
	// - número gerações (ou épocas) sem melhoria - futuro
	// - diversidade da população - futuro
	bool Parar(void) { return TProcura::Parar() || custo <= lowerBound; }

	///////////////////////////////////////////////////////////////////////////////
	// Operadores a redefinir para Escalada-do-Monte
	///////////////////////////////////////////////////////////////////////////////

	// Operador de vizinhanca (apenas em soluções completas)
	// chamar a função nesta classe para actualizacao de estatisticas
	virtual void Vizinhanca(TVector<TPonto>& vizinhos) {}

	///////////////////////////////////////////////////////////////////////////////
	// Algorithmos Evolutivos
	///////////////////////////////////////////////////////////////////////////////

	// Operador mutação, altera o estado actual (de acordo com a parametrizacao global)
	virtual void Mutar(void) {}
	// Operador cruzamento, cruza os dois elementos a e b, colocando o resultado no estado atual
	virtual void Cruzamento(TPonto a, TPonto b) { }
	// Função distância: distancia deste elemento ao elemento a
	// (opcional para manter os elementos diversos)
	virtual int Distancia(TPonto a) { return 0; }

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmo de procura local: Escalada do Monte
	///////////////////////////////////////////////////////////////////////////////
	// retorna a avaliação do resultado actual
	int EscaladaDoMonte();

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmo de procura local: Algoritmos Geneticos
	///////////////////////////////////////////////////////////////////////////////
	// retorna a avaliação do resultado final
	int AlgoritmoGenetico();

	///////////////////////////////////////////////////////////////////////////////
	// Algoritmo Evolutivo: Algoritmos Geneticos + Estratégia de Evolução
	///////////////////////////////////////////////////////////////////////////////
	// Implementação em linha com Eiben & Smith, 2015
	// retorna a avaliação do resultado final
	int AlgoritmoEvolutivo();



	// Chamar sempre que uma solução melhor que a actual e encontrada
	void DebugMelhorEncontrado(TPonto ponto);

	/**
	 * @brief Redefinição. Ver TProcura::Indicador().
	 */
	int64_t Indicador(int id) override;

	/**
	 * @brief Inicializar a instância. No final, chamar NovaSolucao() para inicializar o estado.
	 */
	void Inicializar(void) {}

	void LimparEstatisticas();

	/**
	 * @brief Utilizar como prefixo em cada linha no método Debug() do estado
	 */
	static const char* debugPrefixo;

protected:
	// métodos internos
	void Selecao(int& pai, int& mae, TVector<int>& pesos, int total);
	void OrdemValor(TVector<TPonto>& populacao, TVector<int>& id);
	void CalcularAvaliacoes(TVector<TPonto>& vizinhos, int& melhorValor, int& melhorIndice);
	void VerificaMelhor(TPonto& melhor, TPonto atual);
	bool VerificaMelhor(TPonto atual);
	int MelhorCusto(TVector<TPonto>& populacao, bool inverter = false);
	TPonto MelhorAtual(TPonto& atual, TVector<TPonto>& vizinhos, int indice);
	void ObterExtremos(TVector<TPonto>& populacao, int& minCusto, int& maxCusto);
	void Explorar() override;
	void LibertarVector(TVector<TPonto>& vector, int excepto = -1);
	int ExecutaAlgoritmo();
	// Mostrar vizinhos
	void DebugInicioEM(int ID, TPonto solucao);
	void DebugOptimoLocal(TPonto solucao);
	void DebugPassoEM(TPonto solucao);
	void DebugPassoAG(int pop, int min, int max);
	void DebugCruzamentoAG(int gPai, int gMae, int gFilho, int mutou);
	// algoritmo evolutivo
	TVector<TPonto> CompletarPopulacaoAE(TVector<TPonto>& populacao);
	TVector<TPonto> SelecionarPaisAE(TVector<TPonto>& populacao);
	TVector<TPonto> ReproduzirAE(TVector<TPonto>& pais, TVector<TPonto>& populacao);
	TVector<TPonto> SelecionarSobreviventesAE(TVector<TPonto>& populacao, TVector<TPonto>& descendentes);
	TVector<TPonto> AplicarDiversidadeAE(TVector<TPonto>& populacao);
	void DebugGeracaoAE(int epoca, TVector<TPonto>& populacao);
	void DebugPopulacaoAE(TVector<TPonto>& populacao, const char* titulo); // mostrar toda a população
	void DebugDiversidadeAE(TVector<TPonto>& populacao, const char* titulo); // diversidade da população
	void DebugID(int id, int pop); // mostra indivíduo ID com cor única, se elemento da população
	void DiversidadeAE(TVector<TPonto>& populacao,
		int& minDist, int& maxDist, int& avgDist, int& melhorPior);
};
