#include "TProcuraAdversa.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>

#define BUFFER_SIZE 1024


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
	parametro[ALGORITMO] = { "Algoritmo",2,1,2,"Seleção do algoritmo de procura adversa base.", nomesAlgoritmos };

	Parametro(LIMITE) = 0; // procura iterativa preferencial
	Parametro(ESTADOS_REPETIDOS) = 1; // nas procuras adversas, não utilizar este parametro (utilizar ordenar=2)
	Parametro(BARALHAR_SUCESSORES) = 0; // de omissão está com valor 0, para facilitar nos testes, mas deve ficar com 1 para obter jogos distintos

	// O "infinito" é dependente do problema, não faz sentido alterar senão no código
	parametro += { "Ordenar",2,0,2, "0 não ordena sucessores, 1 ordena por heurística, 2 usa o melhor valor de procuras anteriores.",NULL };
	parametro += { "PodaHeuristica",0,0,1000, "0 não existe poda, caso contrário é o número máximo de sucessores a considerar (tem de se ordenar sucessores).",NULL };
	parametro += { "PodaCega",0,0,10000, "Igual a PodaHeuristica, mas é efetuado de forma aleátoria, sem calcular a heurística. Utilizar um valor sempre maior que Poda. ",NULL };
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

		if (((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, LER) &&
			valorConhecido.nivel >= nivel)
		{
			valor = valorConhecido.valor;
		}
		else {
			// chamada recursiva, com um nível a menos, idêntico à procura em profundidade
			valor = ((TProcuraAdversa*)sucessores[id[i]])->MiniMax(nivel - 1);
			valorConhecido = { valor, nivel, EXATO };
			((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, GRAVAR);
		}

		// pretende-se obter o melhor resultado, que oscila entre minimizar ou maximizar
		if (i == 0 || (minimizar ? resultado > valor : resultado < valor)) {
			resultado = valor;
			melhor = id[i];
			if (nivel > 1 && Parametro(NIVEL_DEBUG) >= PASSOS) { // colocar valor actual alterado
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
	DebugCorte(sucessores.Count(), minimizar);
	LibertarVector(sucessores, melhor);
	return resultado;
}

int TProcuraAdversa::Heuristica(void) {
	TValorEstado calculado;
	heuristica = TProcuraConstrutiva::Heuristica(); // incrementa avaliações e adiciona ruído se for caso disso
	// valor da heurística já calculado, gravar
	calculado = { heuristica,0,EXATO }; // valor da heurística com nível 0
	ValorEstado(calculado, GRAVAR);
	return heuristica;
}

// chamar em CSubProblema::Heuristica() para verificar se a heurística já existe, ou precisa de ser calculada
bool TProcuraAdversa::ExisteHeuritica(void) {
	TValorEstado calculado;
	if (ValorEstado(calculado, LER)) {
		heuristica = calculado.valor;
		return true;
	}
	return false;
}

void TProcuraAdversa::OrdenarSucessores(
	TVector<TNo>& sucessores, TVector<int>& id, int nivel)
{
	if (Parametro(PODA_CEGA) > 0 &&
		sucessores.Count() > Parametro(PODA_CEGA))
	{
		// podar de forma aleatória, nem heurística deve ser calculada
		while (sucessores.Count() > Parametro(PODA_CEGA)) {
			int id = TRand::rand() % sucessores.Count();
			delete sucessores[id];
			sucessores[id] = sucessores.Last();
			sucessores.Pop();
		}
	}

	id = {};
	if (nivel > 2 && Parametro(ORDENAR_SUCESSORES) >= 1) {
		CalcularHeuristicas(sucessores, &id); // id fica ordenado por heurística

		if (!minimizar)
			id.Invert();

		// podar sucessores
		if (Parametro(PODA_HEURISTICA) > 0 &&
			Parametro(PODA_HEURISTICA) < id.Count()) {
			TVector<TNo> manterSuc;
			for (int i = 0; i < Parametro(PODA_HEURISTICA); i++)
				manterSuc += sucessores[id[i]];
			for (int i = Parametro(PODA_HEURISTICA); i < id.Count(); i++)
				delete sucessores[id[i]];
			sucessores = manterSuc;
			id = {}; 
			for (int i = 0; i < sucessores.Count(); i++)
				id += i;
		}

	}
	else
		for (int i = 0; i < sucessores.Count(); i++)
			id += i;
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
			if (Parametro(NIVEL_DEBUG) > NADA && solOK != NULL)
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
	if (Parametro(NIVEL_DEBUG) > ATIVIDADE)
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

		if (((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, LER) &&
			Utilizavel(valorConhecido, nivel, alfa, beta))
		{
			valor = valorConhecido.valor;
		}
		else {
			// chamada recursiva, com um nível a menos, idêntico à procura em profundidade
			valor = ((TProcuraAdversa*)sucessores[id[i]])->MiniMaxAlfaBeta(nivel - 1, alfa, beta);
			valorConhecido = { valor, nivel, EXATO };
			if (valor <= alfa)
				valorConhecido.tipo = UPPER_BOUND;  // Causado por corte alfa
			else if (valor >= beta)
				valorConhecido.tipo = LOWER_BOUND;  // Causado por corte beta
			// registar valor apenas se estiver dentro de alfa/beta (para não influenciarem o resultado)
			((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, GRAVAR);
		}

		if (i == 0 || (minimizar ? resultado > valor : resultado < valor)) {
			resultado = valor;
			melhor = id[i];
			if (nivel > 1 && Parametro(NIVEL_DEBUG) >= PASSOS) {
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
		if (solucao != NULL)
			delete solucao;
		solucao = sucessores[melhor];
	}
	DebugCorte(sucessores.Count(), minimizar);
	LibertarVector(sucessores, melhor);
	return resultado;
}

bool TProcuraAdversa::Utilizavel(TValorEstado& valor, int nivel, int alfa, int beta) {
	return valor.nivel >= nivel &&
		(valor.tipo == EXATO ||
			valor.tipo == lowerBound && valor.valor >= beta ||
			valor.tipo == UPPER_BOUND && valor.valor <= alfa);
}


// verifica se há um corte alfa/beta, atualizando alfa e beta
bool TProcuraAdversa::CorteAlfaBeta(int valor, int& alfa, int& beta) {
	if (minimizar) { // pretas
		// ver se ja e maximo
		if (valor <= custo + 1 - infinito)
			return true;
		if (alfa >= valor) {
			// corte alfa
			if (Parametro(NIVEL_DEBUG) > ATIVIDADE) {
				// substituir o ultimo caracter por um corte
				ramo.Last() = '>';
				NovaLinha();
				printf(" alfa(%d)", alfa);
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
			if (Parametro(NIVEL_DEBUG) > ATIVIDADE) {
				ramo.Last() = '>';
				NovaLinha();
				printf(" beta(%d)", beta);
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
void TProcuraAdversa::TesteEmpirico(TVector<int> instancias, bool mostrarSolucoes, char* ficheiro) {
	TVector<int> atual;
	int backupID = instancia.valor;
	for (auto item : instancias)
		if (item<instancia.min || item>instancia.max)
			item = -1;
	instancias -= (-1);
	ConfiguracaoAtual(atual, LER);
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
				for (auto inst : instancias) {
					instancia.valor = inst;
					int resultado = -1, njogada = 0;
					clock_t inicioCorrida;
					printf("\n Instância %d: ", instancia.valor);
					// carregar instância
					Inicializar();
					// jogar ora de brancas ora de pretas, até o jogo terminar
					while (!SolucaoCompleta()) {
						ConfiguracaoAtual(configuracoes[njogada % 2 == 0 ? brancas : pretas], GRAVAR);
						TRand::srand(Parametro(SEMENTE));
						inicioCorrida = clock();
						LimparEstatisticas(inicioCorrida);
						resultado = ExecutaAlgoritmo();
						tempoTotal[njogada % 2 == 0 ? brancas : pretas] += clock() - inicioCorrida;
						if (solucao != NULL) { // efetuado um lance
							const char* strAcao = Acao(solucao);
							Copiar(solucao);
							if (mostrarSolucoes) {
								if (Parametro(VER_ACOES) == 1 ||
									njogada % Parametro(VER_ACOES) == 0) {
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
						torneio[brancas][pretas] += (resultado < 0 ? -1 : 1) * (inverter ? -1 : 1);
						printf(" Vitória %s", (inverter ? resultado < 0 : resultado > 0) ? "Branca" : "Preta");
					}
					else
						printf(" Empate");
				}
			}

	if (ficheiro == NULL || strlen(ficheiro) <= 1) {
		MostrarTorneio(torneio, true);
		printf("\nTempos: ");
		for (int i = 0; i < tempoTotal.Count(); i++)
			printf("%.3fs ", 1.0 * tempoTotal[i] / CLOCKS_PER_SEC);
		MostrarConfiguracoes(1);
		printf("\n");
	}
	else {
		char* pt = strtok(ficheiro, " \n\t\r");
		char str[BUFFER_SIZE];
		strcpy(str, pt);
		strcat(str, ".csv");
		FILE* f = fopen(str, "wt");
		if (f != NULL) {
			// escrever BOM UTF-8
			const unsigned char bom[] = { 0xEF,0xBB,0xBF };
			fwrite(bom, 1, sizeof(bom), f);
			fprintf(f, "sep=;\n");
			RelatorioCSV(torneio, f);
			printf("\nFicheiro %s gravado.", str);
			fclose(f);
		}
		else
			printf("\nErro ao gravar ficheiro %s.", str);

	}

	ConfiguracaoAtual(atual, GRAVAR);
	instancia.valor = backupID;
	TRand::srand(Parametro(SEMENTE));
	Inicializar();
}


void TProcuraAdversa::RelatorioCSV(TVector<TVector<int>>& torneio, FILE* f) {
	// Jogador, Adversário, cor, resultado (positivo caso o jogador ganhe, negativo c.c.) 
	// Nota: cada confronto fica com 2 entradas; se existir várias instâncias, o resultado do confronto é somado
	fprintf(f, "Jogador;Adversário;Cor;Resultado\n");
	for (int jogador = 0; jogador < torneio.Count(); jogador++)
		for (int adversario = 0; adversario < torneio[jogador].Count(); adversario++)
			if (jogador != adversario) {
				fprintf(f, "%d;%d;%s;%d\n", jogador, adversario, "Brancas", torneio[jogador][adversario]);
				fprintf(f, "%d;%d;%s;%d\n", adversario, jogador, "Pretas", -torneio[jogador][adversario]);
			}
	if(configuracoes.Count()!=torneio.Count())
		return; 
	// No final, mostrar as configurações
	fprintf(f,"\nJogador;");
	for (int i = 0; i < parametro.Count(); i++)
		fprintf(f, "P%d(%s);", i + 1, parametro[i].nome);
	fprintf(f, "\n");
	for (int jogador = 0; jogador < configuracoes.Count(); jogador++) {
		fprintf(f, "%d;", jogador);
		for (int j = 0; j < parametro.Count(); j++)
			if (parametro[j].nomeValores == NULL)
				fprintf(f, "%d;", configuracoes[jogador][j]);
			else
				fprintf(f, "%d:%s;",
					configuracoes[jogador][j],
					parametro[j].nomeValores[configuracoes[jogador][j] - parametro[j].min]);
		fprintf(f, "\n");
	}
}


int TProcuraAdversa::ExecutaAlgoritmo() {
	int resultado = -1;
	if (Parametro(ORDENAR_SUCESSORES) == 2) {
		Parametro(ESTADOS_REPETIDOS) = GERADOS;
		if (reutilizadoAvaliacao > 0 && Parametro(NIVEL_DEBUG) >= ATIVIDADE) {
			float taxa = 1.0 * reutilizadoAvaliacao / colocadosHT;
			LimparHT();
			printf(" HT: reutilização %.2f vezes ", taxa);
		}
		else
			LimparHT();
		reutilizadoAvaliacao = 0;
		Parametro(ESTADOS_REPETIDOS) = IGNORADOS;
	}
	switch (Parametro(ALGORITMO)) {
	case 1: resultado = MiniMax(Dominio(Parametro(LIMITE), 0)); break;
	case 2: resultado = MiniMaxAlfaBeta(Dominio(Parametro(LIMITE), 0)); break;
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
	if (Parametro(ORDENAR_SUCESSORES) != 2)
		return false;
	ExisteHT(); // calcula indiceHT
	if (operacao == LER) {
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



