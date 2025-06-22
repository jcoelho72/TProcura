#include "TProcuraAdversa.h"
#include <stdio.h>
#include <time.h>
#include <math.h>

// valor de infinito (vitoria/derrota), omissao 1000
int TProcuraAdversa::infinito = 1000;
// controlo para indicar se a procura foi realizada de forma completa (c.c. foi cortada)
bool TProcuraAdversa::completo;
// hashtable / valor e nível obtido
TValorEstado TProcuraAdversa::valorHT[TAMANHO_HASHTABLE];
// profundidade máxima no método iterativo
int TProcuraAdversa::nivelOK = 0;
// número de vezes que uma avaliação é reutilizada
int TProcuraAdversa::reutilizadoAvaliacao; 

TProcuraAdversa::TProcuraAdversa(void) : minimizar(true), indiceHT(-1)
{
	
}

TProcuraAdversa::~TProcuraAdversa(void)
{
}

void TProcuraAdversa::ResetParametros()
{
	static const char* nomesAlgoritmos[] = { "MiniMax",	"MiniMax alfa/beta" };
	TProcuraConstrutiva::ResetParametros();

	// adicionar parâmetros da procura adversa
	// alterar algoritmos
	parametro[algoritmo] = { "Algoritmo",2,1,2,"Seleção do algoritmo de procura adversa base.", nomesAlgoritmos };

	parametro[limite].valor = 0; // procura iterativa preferencial
	parametro[estadosRepetidos].valor = 1; // nas procuras adversas, não utilizar este parametro (utilizar ordenar=2)
	parametro[baralharSuc].valor = 0; // de omissão está com valor 0, para facilitar nos testes, mas deve ficar com 1 para obter jogos distintos

	// O "infinito" é dependente do problema, não faz sentido alterar senão no código
	parametro.Add({ "Ordenar",2,0,2, "0 não ordena sucessores, 1 ordena por heurística, 2 usa o melhor valor de procuras anteriores.",NULL });
	parametro.Add({ "PodaHeuristica",0,0,1000, "0 não existe poda, caso contrário é o número máximo de sucessores a considerar (tem de se ordenar sucessores).",NULL });
	parametro.Add({ "PodaCega",0,0,10000, "Igual a PodaHeuristica, mas é efetuado de forma aleátoria, sem calcular a heurística. Utilizar um valor sempre maior que Poda. ",NULL });
}


///////////////////////////////////////////////////////////////////////////////
// Algoritmo MiniMax
///////////////////////////////////////////////////////////////////////////////
// retorna o valor do estado actual, apos procura de profundidade nivel
int TProcuraAdversa::MiniMax(int nivel)
{
	DebugChamada();
	// no final da árvore, retornar (valor da heuristica)
	if (nivel == 1 || Parar()) {
		completo = false; // árvore cortada, a procura deixa de ser completa
		return NoFolha(true);
	}

	if (nivel == 0)
		return MetodoIterativo(false);

	// expandir o estado
	TVector<TNo> sucessores;
	Sucessores(sucessores);
	// caso não existam sucessores, é como se fosse um nó folha
	if (sucessores.Count() == 0)
		return NoFolha(false);

	TVector<int> id; // índice para ordenar os sucessores por heurística
	OrdenarSucessores(sucessores, id, nivel);

	int resultado = 0, melhor = -1;
	// processar os sucessores
	for (int i = 0; i < sucessores.Count(); i++) {
		DebugExpansao(i, sucessores.Count(), minimizar);
		int valor;
		TValorEstado valorConhecido;

		if (((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, ler) &&
			valorConhecido.nivel >= nivel) 
		{
			valor = valorConhecido.valor;
		} 
		else {
			// chamada recursiva, com um nível a menos, idêntico à procura em profundidade
			valor = ((TProcuraAdversa*)sucessores[id[i]])->MiniMax(nivel - 1);
			valorConhecido = { valor, nivel, exato };
			((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, gravar);
		}

		// pretende-se obter o melhor resultado, que oscila entre minimizar ou maximizar
		if (i == 0 || (minimizar ? resultado > valor : resultado < valor)) {
			resultado = valor;
			melhor = id[i];
			if (nivel > 1 && parametro[nivelDebug].valor >= 2) { // colocar valor actual alterado
				NovaLinha();
				printf("(%d)", resultado);
			}
			if (minimizar ? resultado <= custo + 1 - infinito : resultado >= infinito - custo - 1)
				break; // nao e possivel melhorar
		}
	}
	// todos os sucessores analizados, se houver uma solução melhor, retornar
	if (melhor >= 0) {
		if (solucao != NULL)
			delete solucao;
		solucao = sucessores[melhor];
	}
	DebugCorte(sucessores.Count(),minimizar);
	LibertarVector(sucessores, melhor);
	return resultado;
}

int TProcuraAdversa::Heuristica(void) {
	TValorEstado calculado;
	heuristica = TProcuraConstrutiva::Heuristica(); // incrementa avaliações e adiciona ruído se for caso disso
	// valor da heurística já calculado, gravar
	calculado = { heuristica,0,exato }; // valor da heurística com nível 0
	ValorEstado(calculado, gravar);
	return heuristica;
}

// chamar em CSubProblema::Heuristica() para verificar se a heurística já existe, ou precisa de ser calculada
bool TProcuraAdversa::ExisteHeuritica(void) {
	TValorEstado calculado;
	if (ValorEstado(calculado, ler)) {
		heuristica = calculado.valor;
		return true;
	}
	return false;
}

void TProcuraAdversa::OrdenarSucessores(
	TVector<TNo>& sucessores, TVector<int>& id, int nivel) 
{
	if (parametro[podaCega].valor > 0 && 
		sucessores.Count() > parametro[podaCega].valor) 
	{
		// podar de forma aleatória, nem heurística deve ser calculada
		while (sucessores.Count() > parametro[podaCega].valor) {
			int id = TRand::rand() % sucessores.Count();
			delete sucessores[id];
			sucessores[id] = sucessores.Last();
			sucessores.Pop();
		}
	}

	id.Count(0);
	if (nivel>2 && parametro[ordenarSucessores].valor >= 1) {
		CalcularHeuristicas(sucessores, &id); // id fica ordenado por heurística

		if (!minimizar)
			id.Invert();

		// podar sucessores
		if (parametro[podaHeuristica].valor > 0 &&
			parametro[podaHeuristica].valor < id.Count()) {
			TVector<TNo> manterSuc;
			for (int i = 0; i < parametro[podaHeuristica].valor; i++)
				manterSuc.Add(sucessores[id[i]]);
			for (int i = parametro[podaHeuristica].valor; i < id.Count(); i++) 
				delete sucessores[id[i]];
			sucessores = manterSuc;
			id.Count(0);
			for (int i = 0; i < sucessores.Count(); i++)
				id.Add(i);
		}

	}
	else
		for (int i = 0; i < sucessores.Count(); i++)
			id.Add(i);
}

// iteração, aumentando o nível progressivamente
int TProcuraAdversa::MetodoIterativo(int alfaBeta) {
	int resultado = 0, resOK = 0, nivel = 0;
	nivelOK = 0;
	TNo solOK = NULL;
	do {
		DebugIteracao(nivel + 1);
		completo = true;
		// chamar a profundidade nível 1, e se não resolver, o nível 2, e assim sucessivamente
		resultado = (alfaBeta ? MiniMaxAlfaBeta(++nivel) : MiniMax(++nivel));
		if (!Parar() || nivel == 0) {
			// guardar a última solução realizada sem interrupções, bem como o resultado
			if (solOK != NULL)
				delete solOK;
			solOK = solucao;
			solucao = NULL;
			resOK = resultado;
			nivelOK = nivel;
			if (parametro[nivelDebug].valor > 0 && solOK != NULL)
				printf("\n%d: %s (%d)", nivel, Acao(solOK), resultado);
		}
		else
			completo = false;
	} while (!completo && !Parar());
	if (solucao != NULL)
		delete solucao;
	solucao = solOK;
	return resOK;
}

// Utilitário para calculo de uma heurística standard em jogos simples (tipicamente sem empates):
// - calcular o número de ameaças de vitória, para cada lado, de menor comprimento:
//   - qMin - vetor com número de ameaças (1 ou mais) a 1 jogada (na primeira posição), a 2 (na segunda posição), e assim sucessivamente; 
//   - qMax - vetor com número de ameaças (1 ou mais) a 1 jogada (na primeira posição), a 2 (na segunda posição), e assim sucessivamente; 
int TProcuraAdversa::MaiorAmeaca(TVector<int>& qMin, TVector<int>& qMax, int maxAmeaca)
{
	int pontos = 0, peso = 1;

	// verificar situações de ganho imediato
	if (!minimizar && qMax.First() > 0)
		return infinito;  // Vitória imediata para o max
	if (minimizar && qMin.First() > 0)
		return -infinito; // Vitória imediata para o min 

	// Ameaças iguais a maxAmeaca ou superior, valem 1, todas as outras valem conforme 
	if (maxAmeaca > qMin.Count())
		peso <<= (maxAmeaca - qMin.Count());
	for (int i = qMin.Count() - 1, peso = 1; i >= 0; i--) {
		pontos -= qMin[i] * peso;
		if (i < maxAmeaca) // peço começa a duplicar
			peso <<= 1;
	}
	peso = 1;
	if (maxAmeaca > qMax.Count())
		peso <<= (maxAmeaca - qMin.Count());
	for (int i = qMax.Count() - 1, peso = 1; i >= 0; i--) {
		pontos += qMax[i] * peso;
		if (i < maxAmeaca) // peço começa a duplicar
			peso <<= 1;
	}

	return infinito * (2 / (1 + exp(-0.01 * pontos)) - 1);
}

// fim da procura, por corte de nível (ou não haver sucessores), retornar heurística
int TProcuraAdversa::NoFolha(bool nivel) {
	int resultado;
	DebugCorte(nivel ? -1 : 0, minimizar);

	resultado = Heuristica();

	if (resultado >= infinito) {
		resultado = infinito - custo; // subtrair
		// jogo ganho pelo branco
		// se o agente minimiza, tentar o jogo mais longo possível
		// caso contrário, quanto maior o jogo pior, quer o jogo mais curto
		// a minimizar, entre um nível 10 e 20, irá preferir o 20, já que -20 é menor que -10
		// a maximizar, entre um nível 10 e 20, irá preferir o 10, já que 10 é menor que 20
	}
	else if (resultado <= -infinito) {
		resultado = custo - infinito; // somar
		// jogo ganho pelo preto
		// se o agente maximiza, tentar o jogo mais longo possível
		// caso contrário, quanto maior o jogo pior, quer o jogo mais curto
		// a maximizar, entre 10 e 20, irá preferir 20, sempre é maior
		// a minimizar, entre 10 e 20, irá preferir 10 que é menor
	}
	if (parametro[nivelDebug].valor > 1)
		printf(" %d", resultado);
	return resultado;
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo MiniMaxAlfaBeta
///////////////////////////////////////////////////////////////////////////////
// retorna o valor do estado actual, apos procura de profundidade nivel
// idêntico a MiniMax
int TProcuraAdversa::MiniMaxAlfaBeta(int nivel, int alfa, int beta)
{
	DebugChamada();
	if (nivel == 1 || Parar()) {
		completo = false; 
		return NoFolha(true);
	}

	if (nivel == 0)
		return MetodoIterativo(true);

	TVector<TNo> sucessores;
	Sucessores(sucessores);
	if (sucessores.Count() == 0)
		return NoFolha(false);

	TVector<int> id; // índice para ordenar os sucessores por heurística
	OrdenarSucessores(sucessores, id, nivel);

	int resultado = 0, melhor = -1;
	for (int i = 0; i < sucessores.Count(); i++) {
		DebugExpansao(i, sucessores.Count(), minimizar);
		int valor;
		TValorEstado valorConhecido;

		if (((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, ler) &&
			Utilizavel(valorConhecido, nivel, alfa, beta))
		{
			valor = valorConhecido.valor;
		}
		else {
			// chamada recursiva, com um nível a menos, idêntico à procura em profundidade
			valor = ((TProcuraAdversa*)sucessores[id[i]])->MiniMaxAlfaBeta(nivel - 1, alfa, beta);
			valorConhecido = { valor, nivel, exato };
			if (valor <= alfa)
				valorConhecido.tipo = upperbound;  // Causado por corte alfa
			else if (valor >= beta)
				valorConhecido.tipo = lowerbound;  // Causado por corte beta
			// registar valor apenas se estiver dentro de alfa/beta (para não influenciarem o resultado)
			((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, gravar);
		}

		if (i == 0 || (minimizar ? resultado > valor : resultado < valor)) {
			resultado = valor;
			melhor = id[i];
			if (nivel > 1 && parametro[nivelDebug].valor >= 2) { 
				// colocar valor actual alterado
				NovaLinha();
				printf("(%d)", resultado);
			}
		}
		// corte alfa/beta bem como atualização
		if (i < sucessores.Count() - 1) { // nao interessa cortar quando não há mais nada para cortar
			if (CorteAlfaBeta(resultado, alfa, beta))
				break;
		}
	}
	if (melhor >= 0) {
		if(solucao!=NULL)
			delete solucao;
		solucao = sucessores[melhor];
	}
	DebugCorte(sucessores.Count(),minimizar);
	LibertarVector(sucessores,melhor);
	return resultado;
}

bool TProcuraAdversa::Utilizavel(TValorEstado& valor, int nivel, int alfa, int beta) {
	return valor.nivel >= nivel &&
		(valor.tipo == exato ||
			valor.tipo == lowerBound && valor.valor >= beta ||
			valor.tipo == upperbound && valor.valor <= alfa);
}


// verifica se há um corte alfa/beta, atualizando alfa e beta
bool TProcuraAdversa::CorteAlfaBeta(int valor, int& alfa, int& beta) {
	if (minimizar) { // pretas
		// ver se ja e maximo
		if (valor <= custo + 1 - infinito)
			return true;
		if (alfa >= valor) {
			// corte alfa
			if (parametro[nivelDebug].valor > 1) {
				// substituir o ultimo caracter por um corte
				ramo.Last() = '>';
				NovaLinha();
				printf(" alfa(%d)",alfa);
			}
			return true; // as brancas tem uma alternativa, e escusado continuar a procurar aqui
		}
		// atualização beta
		if (beta > valor)
			beta = valor;
	}
	else { // brancas
		// ver se atingiu o maximo
		if (valor >= infinito - custo - 1)
			return true;
		if (beta <= valor) {
			// corte beta
			if (parametro[nivelDebug].valor > 1) {
				ramo.Last() = '>';
				NovaLinha();
				printf(" beta(%d)",beta);
			}
			return true; // as pretas tem uma alternativa, e escusado continuar a procurar aqui
		}
		// atualização alfa
		if (alfa < valor)
			alfa = valor;
	}
	// não há corte
	return false;
}

// utilizar para executar testes empíricos, utilizando todas as instâncias,
// Utiliza as configurações existentes, ou parâmetros atuais
// Efetua um torneio entre configurações
void TProcuraAdversa::TesteEmpirico(int inicio, int fim, bool mostrarSolucoes) {
	TVector<int> atual;
	int backupID = instancia.valor;
	if (inicio == NAO_LIDO)
		inicio = instancia.min;
	if (fim == NAO_LIDO)
		fim = instancia.max;
	Dominio(inicio, instancia.min, instancia.max);
	Dominio(fim, instancia.min, instancia.max);
	ConfiguracaoAtual(atual, ler);
	if (configuracoes.Count() == 0) {
		// não foram feitas configurações, utilizar a atual 
		configuracoes.Count(1);
		configuracoes.Last() = atual;
	}
	if (configuracoes.Count() == 1) {
		// apenas há uma configuração, utilizar a atual como segunda
		configuracoes.Count(2);
		configuracoes.Last() = atual;
	}

	TVector<TVector<int>> torneio; // pares de configurações: 1 melhor, 0 igual -1 pior
	TVector<int> tempoTotal; // tempo total de resposta, em todos os jogos
	torneio.Count(configuracoes.Count());
	for (int i = 0; i < configuracoes.Count(); i++) {
		torneio[i].Count(configuracoes.Count());
		torneio[i].Reset(0);
	}
	tempoTotal.Count(configuracoes.Count());
	tempoTotal.Reset(0);

	// dois jogadores, brancas é o primeiro a jogar, pretas é o segundo
	for (int brancas = 0; brancas < configuracoes.Count(); brancas++)
		for (int pretas = 0; pretas < configuracoes.Count(); pretas++)
			if (brancas != pretas) {
				printf("\nMatch %d vs %d:", brancas + 1, pretas + 1);
				for (instancia.valor = inicio; instancia.valor <= fim; instancia.valor++) {
					int resultado = -1, njogada=0;
					clock_t inicioCorrida;
					printf("\n Instância %d: ", instancia.valor);
					// carregar instância
					SolucaoVazia();
					// jogar ora de brancas ora de pretas, até o jogo terminar
					while (!SolucaoCompleta()) {
						ConfiguracaoAtual(configuracoes[njogada % 2 == 0 ? brancas : pretas], gravar);
						TRand::srand(parametro[seed].valor);
						inicioCorrida = clock();
						LimparEstatisticas(inicioCorrida);
						resultado = ExecutaAlgoritmo();
						tempoTotal[njogada % 2 == 0 ? brancas : pretas] += clock() - inicioCorrida;
						if (solucao != NULL) { // efetuado um lance
							const char* strAcao = Acao(solucao);
							Copiar(solucao);
							if (mostrarSolucoes) {
								if (parametro[verAcoes].valor == 1 ||
									njogada% parametro[verAcoes].valor==0) {
									printf("\n%s %d %s",
										(njogada % 2 == 0 ? "Brancas" : "Pretas"),
										(njogada / 2) + 1, strAcao);
									Debug();
									printf(" f:%d ", resultado);
								}
								else // mostrar apenas a ação
									printf(" %s", strAcao);
							}
							njogada++;
						}
						else {
							break; // não há lance efetuado
							resultado = 0; // erro, mas considerar empatado
						}
					}
					// jogo terminou, registar resultdo
					if (resultado != 0) {
						bool inverter;
						// brancas e minimizar ou pretas e maximizar, inverter
						inverter = (njogada % 2 == 0) && minimizar || 
							(njogada % 2 == 1) && !minimizar;
						// vitória/derrota branca/preta
						torneio[brancas][pretas] += (resultado < 0 ? -1 : 1) * (inverter ? -1:1);
						printf(" Vitória %s", (inverter ? resultado < 0 : resultado > 0) ? "Branca" : "Preta");
					}
					else 
						printf(" Empate");
				}
			}

	MostrarTorneio(torneio, true);
	printf("\nTempos: ");
	for (int i = 0; i < tempoTotal.Count(); i++)
		printf("%.3fs ", 1.0 * tempoTotal[i] / CLOCKS_PER_SEC);
	MostrarConfiguracoes(1);
	printf("\n");
	ConfiguracaoAtual(atual, gravar);
	instancia.valor = backupID;
	TRand::srand(parametro[seed].valor);
	SolucaoVazia();
}


int TProcuraAdversa::ExecutaAlgoritmo() {
	int resultado = -1;
	if (parametro[ordenarSucessores].valor == 2) {
		parametro[estadosRepetidos].valor = gerados;
		if (reutilizadoAvaliacao > 0 && parametro[nivelDebug].valor >= 1) {
			float taxa = 1.0 * reutilizadoAvaliacao / colocadosHT;
			LimparHT();
			printf(" HT: reutilização %.2f vezes ", taxa);
		} else
			LimparHT();
		reutilizadoAvaliacao = 0;
		parametro[estadosRepetidos].valor = ignorados;
	}
	switch (parametro[algoritmo].valor) {
	case 1: resultado = MiniMax(Dominio(parametro[limite].valor, 0)); break;
	case 2: resultado = MiniMaxAlfaBeta(Dominio(parametro[limite].valor, 0)); break;
	}
	return resultado;
}

// necessário redefinir para atualizar valorHT em caso de colisão
void TProcuraAdversa::SubstituirHT(int indice) {
	TProcuraConstrutiva::SubstituirHT(indice);
	valorHT[indiceHT = indice].nivel = -1;
}

bool TProcuraAdversa::ExisteHT() {
	// caso não exista, retorna falso e insere
	// se existe retorna falso à mesma para não remover, dado que é uma alternativa para este lance concreto
	// se estiver lá outro elemento, substitui
	unsigned int original = Hash();
	unsigned int indice = original % TAMANHO_HASHTABLE;
	indiceHT = indice;
	for (int i = 0; i < tamanhoCodificado; i++) {
		if (elementosHT[indice][i] != estadoCodHT[i]) {
			SubstituirHT(indice);
			colocadosHT++;
			return false; // não existia
		}
	}
	return false; // é como se não existisse, mas está lá
}


bool TProcuraAdversa::ValorEstado(TValorEstado& valor, int operacao) {
	if (parametro[ordenarSucessores].valor != 2)
		return false;
	ExisteHT(); // calcula indiceHT
	if (operacao == ler) {
		if (indiceHT >= 0 && valorHT[indiceHT].nivel >= 0) {
			valor = valorHT[indiceHT];
			reutilizadoAvaliacao++;
			return true;
		}
		return false;
	}
	// gravar
	if (indiceHT >= 0 && valorHT[indiceHT].nivel < valor.nivel)
		valorHT[indiceHT] = valor;

	return true;
}



