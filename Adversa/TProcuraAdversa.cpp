#include "TProcuraAdversa.h"
#include <stdio.h>
#include <time.h>
#include <math.h>
#include <string.h>
#ifdef MPI_ATIVO
#include <mpi.h>
#endif

constexpr int BUFFER_SIZE = 1024;

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
	parametro[ALGORITMO] = { "ALGORITMO",2,1,2,"Seleção do algoritmo de procura adversa base.", nomesAlgoritmos };

	Parametro(LIMITE) = 0; // procura iterativa preferencial
	Parametro(ESTADOS_REPETIDOS) = 1; // nas procuras adversas, não utilizar este parametro (utilizar ordenar=2)
	Parametro(BARALHAR_SUCESSORES) = 0; // de omissão está com valor 0, para facilitar nos testes, mas deve ficar com 1 para obter jogos distintos

	// O "infinito" é dependente do problema, não faz sentido alterar senão no código

	// adicionar parametros da procura adversa
	parametro += {
		{ "ORDENAR_SUCESSORES", 2, 0, 2, "0 não ordena sucessores, 1 ordena por heurística, 2 usa o melhor valor de procuras anteriores." },
		{ "PODA_HEURISTICA",0,0,1000, "0 não existe poda, caso contrário é o número máximo de sucessores a considerar (tem de se ordenar sucessores)." },
		{ "PODA_CEGA",0,0,10000, "Igual a PodaHeuristica, mas é efetuado de forma aleátoria, sem calcular a heurística. Utilizar um valor sempre maior que Poda. " },
		{ "HEUR_BASE", 200, 100, 1000, "Valor base para diferença entre ameaças de K e K-1 (100 não há diferença, 200 corresponde ao doubro e é o valor de omissão)" },
		{ "HEUR_MAX_PONTOS", 100, 2, 1000000, "Pontos de amaeaças máximos, para colocar a função sigmoide a saturar por essa altura (ficando perto do +/-infinito)" }
	};
}


void TProcuraAdversa::Sucessores(TVector<TNo>& sucessores) {
	TProcuraConstrutiva::Sucessores(sucessores);
	if (Parametro(NIVEL_DEBUG) >= PASSOS && !sucessores.Empty()) {
		if (minimizar)
			ramo.Push(RAMO_ESTADO2);
		else
			ramo.Push(RAMO_ESTADO);
	}
}

void TProcuraAdversa::DebugChamada(bool noFolha, int alfa, int beta) {
	bool raiz = (ramo.Count() <= 1);

	if (Parametro(NIVEL_DEBUG) == ATIVIDADE && expansoes % 1000 == 0)
		printf("#");
	if (Parametro(NIVEL_DEBUG) >= PASSOS) {
		if (raiz)
			ramo.First() = (minimizar ? RAMO_ESTADO2 : RAMO_ESTADO);
		NovaLinha(true);
		ramo.Last() = (ramo.Last() == RAMO_ESTADO || ramo.Last() == RAMO_ESTADO2 ? RAMO_CONTINUA : RAMO_VAZIO);
		ramo.First() = RAMO_CONTINUA;
		DebugEstado(false);
		if (alfa || beta)
			printf(" α=%d β=%d ═══", alfa, beta);
		if (pai != NULL)
			printf(" %-2s%s", Icon(EIcon::ACCAO), pai->Acao(this)); // mostra sempre a ação
		if ((noFolha && Parametro(NIVEL_DEBUG) >= DETALHE) ||
			Parametro(NIVEL_DEBUG) >= COMPLETO)
			Debug();
	}
}


///////////////////////////////////////////////////////////////////////////////
// Algoritmo MiniMax
///////////////////////////////////////////////////////////////////////////////
// retorna o valor do estado actual, apos procura de profundidade nivel
int TProcuraAdversa::MiniMax(int nivel)
{
	bool noFolha = (nivel == 1 || Parar());

	if (nivel == 0)
		return MetodoIterativo(false);

	DebugChamada(noFolha);
	// no final da árvore, retornar (valor da heuristica)
	if (noFolha) {
		completo = false; // árvore cortada, a procura deixa de ser completa
		return NoFolha(true);
	}

	// expandir o estado
	TVector<TNo> sucessores;
	Sucessores(sucessores);
	// caso não existam sucessores, é como se fosse um nó folha
	if (sucessores.Empty())
		return NoFolha(false);

	TVector<int> id; // índice para ordenar os sucessores por heurística
	OrdenarSucessores(sucessores, id, nivel);

	int resultado = 0, melhor = -1;
	// processar os sucessores
	for (int i = 0; i < id.Count(); i++) {
		DebugExpansao(i, id.Count(), minimizar);
		int valor;
		TValorEstado valorConhecido;

		if (((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, LER) &&
			valorConhecido.nivel >= nivel)
		{
			valor = valorConhecido.valor;
			if (Parametro(NIVEL_DEBUG) >= PASSOS) {
				((TProcuraAdversa*)sucessores[id[i]])->DebugChamada(false);
				DebugFolha(false, "%-2s%d", Icon(EIcon::MEMORIA), valor);
			}
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
				ramo.Last() = (minimizar ? RAMO_ESTADO : RAMO_ESTADO2);
				NovaLinha();
				printf(" %d", resultado);
			}
			// caso de vitória/derrota
			if (minimizar ? resultado <= custo + 1 - infinito : resultado >= infinito - custo - 1) {
				DebugFolha(true, " %-2s%d", Icon(resultado < 0 ? EIcon::VIT_PRETA : EIcon::VIT_BRANCA), custo);
				// listar os nós não explorados
				if (Parametro(NIVEL_DEBUG) >= PASSOS) {
					TVector<int> valores;
					for (int j = i + 1; j < id.Count(); j++)
						valores += sucessores[id[j]]->debugID;
					MostraConjunto(valores, Icon(EIcon::ID));
				}
				break; // nao e possivel melhorar
			}
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
		DebugIteracao(nivel + 1, Icon(EIcon::LIMITE));
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
				printf("\n │ %-2s%-2s %d %-2s%s %-2s%d ",
					Icon(EIcon::ARVORE), Icon(EIcon::LIMITE), nivel,
					Icon(EIcon::ACCAO), Acao(solOK), Icon(EIcon::SUCESSO), resultado);
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
int TProcuraAdversa::MaiorAmeaca(TVector<int>& qMin, TVector<int>& qMax, int maxAmeaca) const
{
	double pontos = 0;
	double base = Parametro(HEUR_BASE) / 100.0;
	double peso = 1;

	// verificar situações de ganho imediato
	if (!minimizar && qMax.First() > 0)
		return infinito;  // Vitória imediata para o max
	if (minimizar && qMin.First() > 0)
		return -infinito; // Vitória imediata para o min 

	// Ameaças iguais a maxAmeaca ou superior, valem 1, todas as outras valem conforme
	peso = 1;
	for (int i = qMin.Count() - 1; i >= 0; i--) {
		pontos -= qMin[i] * peso;
		if (i < maxAmeaca) // peço começa a aumentar
			peso *= base;
	}
	peso = 1;
	for (int i = qMax.Count() - 1; i >= 0; i--) {
		pontos += qMax[i] * peso;
		if (i < maxAmeaca) // peço começa a aumentar
			peso *= base;
	}

	return (int)(infinito * (2 / (1 + exp(-pontos / Parametro(HEUR_MAX_PONTOS))) - 1));
}

// fim da procura, por corte de nível (ou não haver sucessores), retornar heurística
int TProcuraAdversa::NoFolha(bool nivel) {
	int resultado = Heuristica();

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
	DebugFolha(false, "%-2s%d", Icon(EIcon::FOLHA), resultado);
	return resultado;
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo MiniMaxAlfaBeta
///////////////////////////////////////////////////////////////////////////////
// retorna o valor do estado actual, apos procura de profundidade nivel
// idêntico a MiniMax
int TProcuraAdversa::MiniMaxAlfaBeta(int nivel, int alfa, int beta)
{
	bool noFolha = (nivel == 1 || Parar());

	if (nivel == 0)
		return MetodoIterativo(true);

	DebugChamada(noFolha, alfa, beta);
	if (noFolha) {
		completo = false;
		return NoFolha(true);
	}

	TVector<TNo> sucessores;
	Sucessores(sucessores);
	if (sucessores.Empty())
		return NoFolha(false);

	TVector<int> id; // índice para ordenar os sucessores por heurística
	OrdenarSucessores(sucessores, id, nivel);

	int resultado = 0, melhor = -1;
	for (int i = 0; i < id.Count(); i++) {
		DebugExpansao(i, id.Count(), minimizar);
		int valor;
		TValorEstado valorConhecido;

		if (((TProcuraAdversa*)sucessores[id[i]])->ValorEstado(valorConhecido, LER) &&
			Utilizavel(valorConhecido, nivel, alfa, beta))
		{
			valor = valorConhecido.valor;
			if (Parametro(NIVEL_DEBUG) >= PASSOS) {
				((TProcuraAdversa*)sucessores[id[i]])->DebugChamada(false, alfa, beta);
				DebugFolha(false, "%-2s%d", Icon(EIcon::MEMORIA), valor);
			}
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
				ramo.Last() = (minimizar ? RAMO_ESTADO : RAMO_ESTADO2);
				NovaLinha();
				printf(" %d", resultado);
			}
		}
		// corte alfa/beta bem como atualização
		if (i < sucessores.Count() - 1) { // nao interessa cortar quando não há mais nada para cortar
			if (CorteAlfaBeta(resultado, alfa, beta)) {
				// listar os nós não explorados
				if (Parametro(NIVEL_DEBUG) >= PASSOS) {
					TVector<int> valores;
					for (int j = i + 1; j < id.Count(); j++)
						valores += sucessores[id[j]]->debugID;
					MostraConjunto(valores, Icon(EIcon::ID));
				}
				break;
			}
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
			(valor.tipo == LOWER_BOUND && valor.valor >= beta) ||
			(valor.tipo == UPPER_BOUND && valor.valor <= alfa));
}


// verifica se há um corte alfa/beta, atualizando alfa e beta
bool TProcuraAdversa::CorteAlfaBeta(int valor, int& alfa, int& beta) {
	if (minimizar) { // pretas
		// ver se ja e maximo
		if (valor <= custo + 1 - infinito) {
			DebugFolha(true, "%-2s%d", Icon(EIcon::VIT_PRETA), custo);
			return true;
		}
		if (alfa >= valor) {
			// corte alfa
			DebugFolha(true, "%-2sα(%d)", Icon(EIcon::CORTE), alfa);
			return true; // as brancas tem uma alternativa, e escusado continuar a procurar aqui
		}
		// atualização beta
		if (beta > valor) {
			beta = valor;
			Debug(PASSOS, false, " → β");
		}
	}
	else { // brancas
		// ver se atingiu o maximo
		if (valor >= infinito - custo - 1) {
			DebugFolha(true, "%-2s%d", Icon(EIcon::VIT_BRANCA), custo);
			return true;
		}
		if (beta <= valor) {
			// corte beta
			DebugFolha(true, "%-2sβ(%d)", Icon(EIcon::CORTE), beta);
			return true; // as pretas tem uma alternativa, e escusado continuar a procurar aqui
		}
		// atualização alfa
		if (alfa < valor) {
			alfa = valor;
			Debug(PASSOS, false, " → α");
		}
	}
	// não há corte
	return false;
}

// utilizar para executar testes empíricos, utilizando todas as instâncias,
// Utiliza as configurações existentes, ou parâmetros atuais
// Efetua um torneio entre configurações
void TProcuraAdversa::TesteEmpirico(TVector<int> instancias, char* ficheiro) {
	TVector<TResultadoJogo> resultados; // guarda resultado dos jogos (qualquer ordem)
	TVector<int> atual;
	double periodoReporte = 60;
	int backupID = instancia.valor;
	int nTarefa = 0;

	TesteInicio(instancias, atual);

	switch (Parametro(NIVEL_DEBUG)) {
	case DETALHE: periodoReporte = 10; break;
	case COMPLETO: periodoReporte = 0; break; // reporte em todos os eventos
	}
	Cronometro(CONT_REPORTE, true); // reiniciar cronómetro evento

	TVector<TVector<int>> torneio; // pares de configurações: 1 melhor, 0 igual -1 pior
	torneio.Count(configuracoes.Count());
	for (int i = 0; i < configuracoes.Count(); i++) {
		torneio[i].Count(configuracoes.Count());
		torneio[i].Reset(0);
	}

	if (mpiID == 0)
		Debug(ATIVIDADE, false,
			"\n ├─ %-2sTarefas:%d   %-2sInstâncias: %d   %-2sConfigurações: %d   %-2sProcessos: %d.",
			Icon(EIcon::TAREFA), instancias.Count() * configuracoes.Count() * (configuracoes.Count() - 1),
			Icon(EIcon::INST), instancias.Count(),
			Icon(EIcon::CONF), configuracoes.Count(),
			Icon(EIcon::PROCESSO), mpiCount) &&
		fflush(stdout);

	// dois jogadores, brancas é o primeiro a jogar, pretas é o segundo
	for (int brancas = 0; brancas < configuracoes.Count(); brancas++)
		for (int pretas = 0; pretas < configuracoes.Count(); pretas++)
			if (brancas != pretas) {
				for (auto inst : instancias) {
					// distribuir tarefas por MPI
					if ((nTarefa++) % mpiCount != mpiID)
						continue;

					resultados += {inst, brancas, pretas};

					if (Parametro(NIVEL_DEBUG) > NADA && mpiID == 0 && Cronometro(CONT_REPORTE) > periodoReporte) {
						Debug(ATIVIDADE, false,
							"\n ├─ %-2s%-15s %-2s%-5d %-2s%-5d %-2s%-5d %-2s%-5d %-2s%-5d",
							Icon(EIcon::TEMPO), MostraTempo(Cronometro(CONT_TESTE)),
							Icon(EIcon::TAREFA), nTarefa,
							Icon(EIcon::INST), inst,
							Icon(EIcon::CONF), brancas + 1,
							Icon(EIcon::CONF), pretas + 1,
							Icon(EIcon::PROCESSO), mpiCount) &&
							fflush(stdout);
						Cronometro(CONT_REPORTE, true);
					}
					ExecutaTarefa(resultados, inst, brancas, pretas, &torneio);
				}
			}

	if (ficheiro == NULL || strlen(ficheiro) <= 1) {
		MostrarTorneio(torneio, true);
		MostrarConfiguracoes(1);
	}
	else {
		RelatorioCSV(resultados, ficheiro) &&
			printf("\n │ Ficheiro %s gravado.", ficheiro);
	}

	if (mpiCount > 1 && modoMPI == 0)
		// tenta juntar ficheiros, caso existam os ficheiros dos outros processos
		JuntarCSV(ficheiro);

	ConfiguracaoAtual(atual, GRAVAR);
	instancia.valor = backupID;
	TRand::srand(Parametro(SEMENTE));
	Inicializar();
	printf("\n═╧═ %-2s Fim do Teste (%-2s%d  %-2s%s) ═══",
		Icon(EIcon::FIM), Icon(EIcon::PROCESSO), mpiID,
		Icon(EIcon::TEMPO), MostraTempo(Cronometro(CONT_TESTE)));
	fflush(stdout);
}

void TProcuraAdversa::ExecutaTarefa(TVector<TResultadoJogo>& resultados,
	int inst, int brancas, int pretas, TVector<TVector<int>>* torneio)
{
	int resultado = -1, njogada = 0;
	// carregar instância
	instancia.valor = inst;
	Inicializar();
	// jogar ora de brancas ora de pretas, até o jogo terminar
	while (!SolucaoCompleta()) {
		ConfiguracaoAtual(configuracoes[njogada % 2 == 0 ? brancas : pretas], GRAVAR);
		TRand::srand(Parametro(SEMENTE));
		LimparEstatisticas();
		int backupDebug = Parametro(NIVEL_DEBUG);
		Parametro(NIVEL_DEBUG) = NADA;
		resultado = ExecutaAlgoritmo();
		Parametro(NIVEL_DEBUG) = backupDebug;
		if (njogada % 2 == 0)
			resultados.Last().tempoBrancas += Cronometro(CONT_ALGORITMO);
		else
			resultados.Last().tempoPretas += Cronometro(CONT_ALGORITMO);
		if (solucao != NULL) { // efetuado um lance
			const char* strAcao = Acao(solucao);
			Copiar(solucao);
			if (Parametro(NIVEL_DEBUG) >= COMPLETO)
				printf(" %s", strAcao);
			njogada++;
		}
		else {
			break; // não há lance efetuado
			resultado = 0; // erro, mas considerar empatado
		}
	}
	resultados.Last().resultado = Pontos(resultado);
	resultados.Last().nJogadas = njogada;

	// caso o primeiro a jogar pretenda minimizar, então inverter,
	// já que o positivo/primeiro a jogar é para as brancas a nível de torneio
	// mesmo que no jogo o primeiro jogador minimize
	if ((njogada % 2 == 0) == minimizar)
		resultados.Last().resultado *= -1;

	// jogo terminou, registar resultado
	if (torneio != NULL)
		(*torneio)[brancas][pretas] += resultados.Last().resultado;
	Debug(COMPLETO, false, " 🏆 %s",
		(resultados.Last().resultado < 0 ? Icon(EIcon::VIT_PRETA) :
			(resultados.Last().resultado > 0 ? Icon(EIcon::VIT_BRANCA) :
				Icon(EIcon::EMPATE))));
}

void TProcuraAdversa::TesteEmpiricoGestor(TVector<int> instancias, char* ficheiro)
{
#ifdef MPI_ATIVO
	int dados[5] = { 0, 0, 0, 4 }; // instância, brancas, pretas
	int64_t dadosD[3];
	double esperaTrabalhadores = 0, esperaGestor = 0;
	TVector<double> terminou; // instante em que terminou cada trabalhador
	TVector<int> trabalhador, trabalhar;
	TVector<int> atual;
	double periodoReporte = 60;

	TesteInicio(instancias, atual);

	switch (Parametro(NIVEL_DEBUG)) {
	case DETALHE: periodoReporte = 10; break;
	case COMPLETO: periodoReporte = 0; break;
	}
	for (int i = 1; i < mpiCount; i++)
		trabalhador += i;

	terminou.Count(mpiCount);
	terminou.Reset(0);

	// Ciclo:
	// 1. Enviar trabalho para os escravos
	// 2. Encerrar escravos a mais
	// 3. Receber resultados e repetir 1 ou 2 conforme as necessidades

	TVector<TResultadoJogo> resultados; // guarda as soluções obtidas
	TVector<TResultadoJogo> tarefas; // guarda informação apenas das tarefas a realizar (sem resultados)
	Cronometro(CONT_REPORTE, true); // reiniciar cronómetro evento

	// construir todas as tarefas
	// dois jogadores, brancas é o primeiro a jogar, pretas é o segundo
	for (int brancas = 0; brancas < configuracoes.Count(); brancas++)
		for (int pretas = 0; pretas < configuracoes.Count(); pretas++)
			if (brancas != pretas)
				for (auto inst : instancias)
					tarefas += { inst, brancas, pretas };


	int totalTarefas = tarefas.Count();
	Debug(ATIVIDADE, false, "\n ├─ %-2sTarefas:%d   %-2sInstâncias: %d   %-2sConfigurações: %d   %-2sProcessos: %d.",
		Icon(EIcon::TAREFA), tarefas.Count(),
		Icon(EIcon::INST), instancias.Count(),
		Icon(EIcon::CONF), configuracoes.Count(),
		Icon(EIcon::PROCESSO), trabalhador.Count() + 1) &&
		fflush(stdout);

	// dar uma tarefa a cada escravo
	while (!tarefas.Empty() && !trabalhador.Empty()) {
		auto tarefa = tarefas.Pop();
		dados[0] = tarefa.instancia;
		dados[1] = tarefa.brancas;
		dados[2] = tarefa.pretas;
		trabalhar += trabalhador.Last();
		MPI_Send(dados, 3, MPI_INT, trabalhador.Pop(), TAG_TRABALHO, MPI_COMM_WORLD);
		esperaTrabalhadores += Cronometro(CONT_TESTE); // estava parado até esta altura
	}
	// caso existam escravos sem trabalho, mandar fechar todos, não há mais tarefas
	dados[0] = dados[1] = -1;
	while (!trabalhador.Empty()) {
		auto trabalhadorID = trabalhador.Pop();
		MPI_Send(dados, 3, MPI_INT, trabalhadorID, TAG_TRABALHO, MPI_COMM_WORLD);
		terminou[trabalhadorID] = Cronometro(CONT_TESTE);
	}

	// receber resultados e continuar a dar trabalho caso exista
	while (!trabalhar.Empty()) {
		MPI_Status stat;

		double inicioEspera = Cronometro(CONT_TESTE);
		MPI_Recv(dados, 5, MPI_INT, MPI_ANY_SOURCE, TAG_CABECALHO, MPI_COMM_WORLD, &stat);
		esperaGestor += Cronometro(CONT_TESTE) - inicioEspera;
		resultados += {dados[0], dados[1], dados[2], dados[3], dados[4]};
		trabalhar -= stat.MPI_SOURCE;
		trabalhador += stat.MPI_SOURCE;
		MPI_Recv(dadosD, 3, MPI_LONG_LONG,
			stat.MPI_SOURCE, TAG_VALORES, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		// tempo de espera do trabalhador
		resultados.Last().tempoBrancas = (double)dadosD[0] / 1000.;
		resultados.Last().tempoPretas = (double)dadosD[1] / 1000.;
		esperaTrabalhadores += (double)((int64_t)dadosD[2]) / 1000.;

		if (Parametro(NIVEL_DEBUG) > NADA && Cronometro(CONT_REPORTE) > periodoReporte) {
			// mostrar uma linha por cada execução
			Debug(ATIVIDADE, false,
				"\n ├─ %-2s%-15s %-2s%-5d %-2s%-5d %-2s%-5d %-2s%-5d %-2s%-5d %-2s ",
				Icon(EIcon::TEMPO), MostraTempo(Cronometro(CONT_TESTE)),
				Icon(EIcon::TAREFA), totalTarefas - tarefas.Count(),
				Icon(EIcon::INST), resultados.Last().instancia,
				Icon(EIcon::CONF), resultados.Last().brancas,
				Icon(EIcon::CONF), resultados.Last().pretas,
				Icon(EIcon::PROCESSO), trabalhador.Last(),
				Icon(EIcon::IND));
			fflush(stdout);
			Cronometro(CONT_REPORTE, true);
		}

		// ainda há tarefas
		if (!tarefas.Empty()) {
			auto tarefa = tarefas.Pop();
			dados[0] = tarefa.instancia;
			dados[1] = tarefa.brancas;
			dados[2] = tarefa.pretas;
			trabalhar += trabalhador.Last();
			MPI_Send(dados, 3, MPI_INT, trabalhador.Pop(), TAG_TRABALHO, MPI_COMM_WORLD);
		}
		else { // tudo feito, mandar sair
			dados[0] = dados[1] = -1;
			auto trabalhadorID = trabalhador.Pop();
			MPI_Send(dados, 3, MPI_INT, trabalhadorID, TAG_TRABALHO, MPI_COMM_WORLD);
			terminou[trabalhadorID] = Cronometro(CONT_TESTE);
		}
	}

	// contar a espera dos trabalhadores, após terminarem
	for (int i = 1; i < mpiCount; i++)
		esperaTrabalhadores += Cronometro(CONT_TESTE) - terminou[i];

	// escrever o ficheiro de resultados
	int backupCount = mpiCount;
	double taxaUtilizacaoT = 1. - (esperaTrabalhadores / (Cronometro(CONT_TESTE) * (mpiCount - 1)));
	double taxaUtilizacaoG = 1. - (esperaGestor / Cronometro(CONT_TESTE));
	double taxaUtilizacao = 1. - ((esperaTrabalhadores + esperaGestor) / (Cronometro(CONT_TESTE) * mpiCount));
	mpiCount = 1; // forçar a escrita do ficheiro apenas neste processo
	RelatorioCSV(resultados, ficheiro) &&
		Debug(ATIVIDADE, false,
			"\n ├─ %-2s Ficheiro %s.csv gravado.\n"
			" │  %-2s Tempo real: %s",
			Icon(EIcon::RESULT), ficheiro,
			Icon(EIcon::TEMPO), MostraTempo(Cronometro(CONT_TESTE))) &&
		Debug(ATIVIDADE, false, "\n │  %-2s CPU total: %s",
			Icon(EIcon::TEMPO), MostraTempo(Cronometro(CONT_TESTE) * (backupCount - 1))) &&
		Debug(ATIVIDADE, false, "\n │  %-2s Espera do gestor: %s",
			Icon(EIcon::TEMPO), MostraTempo(esperaGestor)) &&
		Debug(ATIVIDADE, false, "\n │  %-2s Espera trabalhadores: %s",
			Icon(EIcon::TEMPO), MostraTempo(esperaTrabalhadores)) &&
		Debug(ATIVIDADE, false, "\n │  %-2s Utilização:\n │  - Total: %.1f%%\n │  - Gestor: %.1f%%\n │  - Trabalhadores: %.1f%% ",
			Icon(EIcon::TAXA), taxaUtilizacao * 100, taxaUtilizacaoG * 100, taxaUtilizacaoT * 100);
	mpiCount = backupCount;

	TesteFim();


#endif
}

void TProcuraAdversa::TesteEmpiricoTrabalhador(TVector<int> instancias, char* ficheiro)
{
#ifdef MPI_ATIVO
	int dados[5] = { 0, 0, 0, 0, 0 }; // instância, brancas, pretas
	int64_t dadosD[3];
	// Ciclo:
	// 1. Solicitar tarefa ao mestre
	// 2. Executar tarefa
	// 3. Enviar resultados ao mestre
	// 4. Repetir até receber ordem de paragem

	TVector<TResultadoJogo> resultados; // guarda resultados dos jogos
	TVector<int> atual;

	TesteInicio(instancias, atual);

	for (;;) {
		// receber nova tarefa
		MPI_Recv(dados, 3, MPI_INT, 0, TAG_TRABALHO, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if (dados[0] < 0)
			break;

		resultados += {dados[0], dados[1], dados[2]};
		ExecutaTarefa(resultados, dados[0], dados[1], dados[2]);

		// enviar registo para master, e apagar
		// dados[0], dados[1] e dados[2] já têm as configurações e instância
		dados[3] = resultados.Last().resultado;
		dados[4] = resultados.Last().nJogadas;
		double inicioEspera = Cronometro(CONT_TESTE);
		MPI_Send(dados, 5, MPI_INT, 0, TAG_CABECALHO, MPI_COMM_WORLD);
		// colocar a espera e tempos de brancas e pretas em milissegundos
		dadosD[0] = (int64_t)(resultados.Last().tempoBrancas * 1000 + 0.5);
		dadosD[1] = (int64_t)(resultados.Last().tempoPretas * 1000 + 0.5);
		dadosD[2] = (int64_t)((Cronometro(CONT_TESTE) - inicioEspera) * 1000 + 0.5);
		MPI_Send(dadosD, 3, MPI_LONG_LONG, 0, TAG_VALORES, MPI_COMM_WORLD);

		resultados.Pop();
	}
	TesteFim();
#endif
}



bool TProcuraAdversa::RelatorioCSV(TVector<TResultadoJogo>& resultados, char* ficheiro) {
	char* contexto;
	char* pt = compat::strtok(ficheiro, " \n\t\r", &contexto);
	char str[BUFFER_SIZE];
	if (mpiCount > 1)
		snprintf(str, sizeof(str), "%s_%d.csv", pt, mpiID);
	else
		snprintf(str, sizeof(str), "%s.csv", pt);
	FILE* f = compat::fopen(str, "wb");

	if (f == NULL) {
		printf("\nErro ao gravar ficheiro %s.", str);
		return false;
	}

	// Jogador, Adversário, cor, resultado (positivo caso o jogador ganhe, negativo c.c.) 
	// Nota: cada confronto fica com 2 entradas; se existir várias instâncias, o resultado do confronto é somado
	fprintf(f, "Instância;Brancas;Pretas;Resultado;Jogadas;TempoBranco;TempoPreto\n");
	for (auto& resultado : resultados)
		fprintf(f, "%d;%d;%d;%d;%d;%.3f;%.3f\n",
			resultado.instancia,
			resultado.brancas + 1,
			resultado.pretas + 1,
			resultado.resultado,
			resultado.nJogadas,
			resultado.tempoBrancas,
			resultado.tempoPretas);

	// No final, mostrar as configurações
	fprintf(f, "\nJogador;");
	for (int i = 0; i < parametro.Count(); i++)
		fprintf(f, "P%d(%s);", i + 1, parametro[i].nome);
	fprintf(f, "\n");
	for (int jogador = 0; jogador < configuracoes.Count(); jogador++) {
		fprintf(f, "%d;", jogador + 1);
		for (int j = 0; j < parametro.Count(); j++)
			if (parametro[j].nomeValores == NULL)
				fprintf(f, "%d;", configuracoes[jogador][j]);
			else
				fprintf(f, "%d:%s;",
					configuracoes[jogador][j],
					parametro[j].nomeValores[configuracoes[jogador][j] - parametro[j].min]);
		fprintf(f, "\n");
	}
	fclose(f);
	return true;
}


int TProcuraAdversa::ExecutaAlgoritmo() {
	int resultado = -1;

	switch (Parametro(ALGORITMO)) {
	case 1: resultado = MiniMax(Dominio(Parametro(LIMITE), 0)); break;
	case 2: resultado = MiniMaxAlfaBeta(Dominio(Parametro(LIMITE), 0)); break;
	}
	ramo.Last() = RAMO_CONTINUA;
	if (Parametro(ORDENAR_SUCESSORES) == 2) {
		Parametro(ESTADOS_REPETIDOS) = GERADOS;
		if (reutilizadoAvaliacao > 0 && Parametro(NIVEL_DEBUG) >= DETALHE) {
			float taxa = (float)(1.0 * reutilizadoAvaliacao / colocadosHT);
			LimparHT();
			printf(" HT: reutilização %.2f vezes ", taxa);
		}
		else
			LimparHT();
		reutilizadoAvaliacao = 0;
		Parametro(ESTADOS_REPETIDOS) = IGNORADOS;
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



