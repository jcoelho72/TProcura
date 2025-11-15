#include "TProcuraMelhorativa.h"

#include <stdio.h>
#include <time.h>
#include <string.h>

constexpr int BUFFER_SIZE = 1024;

/// @brief Lower Bound, se existir 
int TProcuraMelhorativa::lowerBound = 0;
/// @brief Número de estados gerados 
int TProcuraMelhorativa::geracoes = 0;
/// @brief Número de épocas decorridas num algoritmo evolutivo. Uma época é uma geração única. 
int TProcuraMelhorativa::epocas = 0;
/**
 * @brief Utilizar como prefixo em cada linha no método Debug() do estado
 */
const char* TProcuraMelhorativa::debugPrefixo = "";


TProcuraMelhorativa::TProcuraMelhorativa(void)
{
	geracoes++; // cada estado criado conta como uma geração
}

TProcuraMelhorativa::~TProcuraMelhorativa(void)
{
}

void TProcuraMelhorativa::ResetParametros()
{
	// ativo apenas Algoritmo Evolutivo
	static const char* nomesAlgoritmos[] = {
		//		"Escalada do Monte",
		//		"Algoritmo Genético",
				"Algoritmo Evolutivo" };
	//static const char* nomesMovePrimeiro[] = { "Primeiro","Melhor" };
	static const char* nomesSelecao[] = {
		"Roleta", // roleta implementada com Stochastic Universal Sampling (SUS)
		"Torneio", // requere tamanho do torneio, se é determinístico, se é com reposição
		"Uniforme" // todos com igual probabilidade
	};
	static const char* nomesSobrevivencia[] = {
		"Idade",
		"Substitui piores",
		"round-robin"   // cada elemento compete com q outros, os que perdem mais são eliminados
	};
	static const char* nomesDiversidade[] = {
		"Nenhuma",
		"Avaliação partilhada",
		"Limpeza"
	};

	TProcura::ResetParametros();

	// alterar parametros base
	Parametro(LIMITE_ITERACOES) = 1000000;
	//	parametro[ALGORITMO] = { "ALGORITMO",3,1,3,"Escolha do algoritmo base a executar.", nomesAlgoritmos };
	parametro[ALGORITMO] = { "ALGORITMO",1,1,1,"Escolha do algoritmo base a executar.", nomesAlgoritmos };

	// adicionar parâmetros da procura melhorativa
	parametro += {
		{ "POPULACAO", 20, 2, 1000000, "Número de elementos em cada geração" },
		{ "PROB_CRUZAR",100,0,100, "Probabilidade de um estado ser cruzado" },
		{ "PROB_MUTAR",50,0,100, "Probabilidade de um estado sofrer uma mutação após gerado" },
		{ "SELECAO",1,1,3, "Método de seleção dos pais para cruzamento", nomesSelecao },
		{ "PRESSAO",150,100,200,
"Pressão da seleção (1.0 a 2.0 > 100 a 200). \
Controla a diferença de probabilidade entre o melhor e o pior indivíduo no método Ranking Selection.\n\
Valores próximos de 1 (100) dão probabilidades quase iguais; valores próximos de 2 (200) favorecem fortemente os melhores.", NULL, TVector<int>({8,1}) },
		{ "TAMANHO_TORNEIO",2,2,100, "Tamanho do torneio, caso a sobrevivência seja do tipo torneio.", NULL, TVector<int>({8,2}) },
		{ "PROB_MELHOR_TORNEIO",100,0,100, "Probabilidade do melhor ganhar o torneio.", NULL, TVector<int>({8,2}) },
		{ "SOBREVIVENCIA",1,1,3, "Método de seleção dos elementos que sobrevivem à nova geração, utilizado nos Algoritmos Genéticos", nomesSobrevivencia },
		{ "PERC_DESCENDENTES",100,0,100, "Número de descendentes a substituirem elementos na população, em percentagem (100 toda a população é substituída, 0 apenas um elemento)" },
		{ "Q_ROUND_ROBIN",3,2,100, "Número de elementos no round-robin (valor de q)", NULL, TVector<int>({12,3}) },
		{ "ELITISMO",1,0,100, "Número absoluto de indivíduos melhores, que se mantêm na geração seguinte, excepto se há descendência com valor igual ou superior" },
		{ "IMIGRANTES",1,0,100, "Número absoluto de indivíduos imigrantes, substituindo quaisquer outros na população." },
		{ "DIVERSIDADE",3,1,3, "Estratégia de diversidade. ", nomesDiversidade },
		{ "DIST_MINIMA",0,0,1000, "Distância mínima imposta entre elementos da população" }
			//,{ "MOVE_PRIMEIRO",1,1,2, "Utilizado na Escalada do Monte", nomesMovePrimeiro, _TV("0,1") }
	};

	// adicionar indicadores da procura melhorativa
	indicador += {
		{ "Épocas", "Número de épocas decorridas num algoritmo evolutivo. Uma época é uma geração única.", IND_EPOCAS },
		{ "Gerações","número de estados gerados", IND_GERACOES }
	};
	indAtivo += {IND_EPOCAS, IND_GERACOES};
}

// Retorna o valor da solucao completa actual.
int TProcuraMelhorativa::Avaliar(void)
{
	// dar informação de progresso, serão 128 pontos até ao limite de iterações
	if (iteracoes % (Parametro(LIMITE_ITERACOES) >> 7) == 0)
		Debug(ATIVIDADE, true, ".");
	iteracoes++;
	return custo;
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo de procura local: Escalada do Monte
///////////////////////////////////////////////////////////////////////////////
// retorna a avaliacao do resultado actual
int TProcuraMelhorativa::EscaladaDoMonte()
{
	bool movePrimeiro = true; //(Parametro(MOVE_PRIMEIRO) == 1);
	TPonto atual = this; // estado atual
	TPonto melhor = this; // melhor estado para todas as escaladas
	int procuras = 0;
	TPonto solucao;
	NovaSolucao();
	melhor->custo = atual->custo = Avaliar(); // avaliar o proprio estado
	// estado atual distinto do melhor
	atual = solucao = (TProcuraMelhorativa*)Duplicar();
	while (!melhor->Parar()) {
		// iniciar uma escalada
		epocas++;
		// ponto de partida uma solução aleatória (local no espaço de soluções completas)
		solucao->NovaSolucao();
		atual->custo = solucao->Avaliar();
		DebugInicioEM(++procuras, solucao);

		while (!melhor->Parar()) {
			// ver de entre os vizinhos, qual o melhor, para avançar um degrau
			TVector<TPonto> vizinhos;
			bool alterado = false;
			solucao->Vizinhanca(vizinhos);
			if (movePrimeiro) {
				// move logo que encontre um vizinho melhor
				// (pode estar a ser ignorados vizinhos melhores)
				while (!vizinhos.Empty()) {
					((TProcuraMelhorativa*)vizinhos.Last())->Avaliar();
					if (atual->custo > vizinhos.Last()->custo) {
						solucao = MelhorAtual(atual, vizinhos, vizinhos.Count() - 1);
						VerificaMelhor(melhor, atual);
						// novos vizinhos a partir do estado atual são apagados
						LibertarVector(vizinhos);
						alterado = true;
					}
					else {
						delete vizinhos.Last();
						vizinhos.Pop();
					}
				}
			}
			else {
				// analisa todos os vizinhos e avança apenas para o melhor vizinho
				int melhorValor = 0, melhorIndice = 0;
				CalcularAvaliacoes(vizinhos, melhorValor, melhorIndice);
				// trocar caso melhore
				if (atual->custo > melhorValor) {
					solucao = MelhorAtual(atual, vizinhos, melhorIndice);
					VerificaMelhor(melhor, atual);
					// novos vizinhos a partir do estado atual
					alterado = true;
				}
				// tudo explorado, libertar
				LibertarVector(vizinhos);
			}
			// final da análise da vizinhança, ver se se subiu alguma coisa
			if (!alterado) {
				// significa que estamos num óptimo local, no topo do moonte
				DebugOptimoLocal(solucao);
				break; // recomeçar nova escalada
			}
			else
				DebugPassoEM(solucao);
		}
	}
	//delete atual;
	delete solucao;

	return melhor->custo;
}

void TProcuraMelhorativa::DebugPassoEM(TPonto solucao) {
	if (Parametro(NIVEL_DEBUG) >= COMPLETO)
		solucao->Debug();
}


void TProcuraMelhorativa::DebugOptimoLocal(TPonto solucao) {
	Debug(PASSOS, false, ">> %d]", solucao->custo);
	if (Parametro(NIVEL_DEBUG) >= DETALHE)
		solucao->Debug();
}

void TProcuraMelhorativa::DebugInicioEM(int ID, TPonto solucao)
{
	if (Debug(PASSOS, true, "\nEscalada %d - ", ID) ||
		Debug(DETALHE, false, "\n\nEscalada %d - ", ID))
		solucao->Debug();
}


void TProcuraMelhorativa::LibertarVector(TVector<TPonto>& vector, int excepto)
{
	for (int i = 0; i < vector.Count(); i++)
		if (i != excepto && vector[i] != NULL)
			delete vector[i];
	vector = {};
}

void TProcuraMelhorativa::VerificaMelhor(TPonto& melhor, TPonto atual) {
	if (melhor->custo > atual->custo) {
		Copiar(atual);
		custo = melhor->custo = atual->custo;
		DebugMelhorEncontrado(melhor);
	}
}

bool TProcuraMelhorativa::VerificaMelhor(TPonto atual)
{
	if (custo > atual->custo) {
		Copiar(atual);
		custo = atual->custo;
		DebugMelhorEncontrado(this);
		return true;
	}
	return false;
}

int TProcuraMelhorativa::MelhorCusto(TVector<TPonto>& populacao, bool inverter)
{
	int custo = inverter ? 0 : INT_MAX;
	for (int i = 0; i < populacao.Count(); i++)
		if (inverter ? custo < populacao[i]->custo : custo > populacao[i]->custo)
			custo = populacao[i]->custo;
	return custo;
}

TProcuraMelhorativa* TProcuraMelhorativa::MelhorAtual(TPonto& atual, TVector<TPonto>& vizinhos, int indice) {
	atual->Copiar(vizinhos[indice]);
	atual->custo = vizinhos[indice]->custo;
	LibertarVector(vizinhos);
	return (TProcuraMelhorativa*)atual;
}


void TProcuraMelhorativa::CalcularAvaliacoes(TVector<TPonto>& vizinhos, int& melhorValor, int& melhorIndice) {
	for (int i = 0; i < vizinhos.Count(); i++) {
		((TProcuraMelhorativa*)vizinhos[i])->Avaliar();
		if (i == 0 || melhorValor > vizinhos[i]->custo) {
			melhorValor = vizinhos[i]->custo;
			melhorIndice = i;
		}
	}
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo de procura local: Algoritmos Geneticos
///////////////////////////////////////////////////////////////////////////////
// retorna a avaliacao do resultado final
// parametros para a mutacao e cruzamento podem ser dados em variaveis globais
int TProcuraMelhorativa::AlgoritmoGenetico()
{
	int populacao = Parametro(POPULACAO);
	int probablidadeMutacao = Parametro(PROB_MUTAR);
	int distanciaMinima = Parametro(DIST_MINIMA);
	TVector<TPonto> geracaoAntiga, geracaoNova;
	TVector<int> id;
	TPonto melhor = this; // melhor estado para toda a procura
	NovaSolucao();
	melhor->Avaliar(); // avaliar o proprio
	Debug(PASSOS, false, "\nPopulação inicial (%d elementos)", populacao);
	// construir a geracao inicial
	for (int i = 0; i < populacao; i++) {
		geracaoAntiga += ((TPonto)Duplicar());
		geracaoAntiga.Last()->NovaSolucao();
		geracaoAntiga.Last()->Avaliar();
		VerificaMelhor(melhor, geracaoAntiga.Last());
	}
	while (!melhor->Parar()) {
		// iniciar uma nova geração, com base na antiga
		epocas++;

		////////////////////////////
		// cruzar conforme o custo
		////////////////////////////
		int minimo, maximo, total;
		TVector<int> probabilidade;
		total = 0;
		ObterExtremos(geracaoAntiga, minimo, maximo);
		DebugPassoAG(geracaoAntiga.Count(), minimo, maximo);
		// calcular a probabilidade de um elemento ser selecionado
		for (int i = 0; i < geracaoAntiga.Count(); i++) {
			// cada elemento tem de ter sempre probabilidade de ser escolhido
			// por isso adiciona-se 1 para que o custo maximo tenha probabilidade minima
			probabilidade += (maximo - geracaoAntiga[i]->custo + 1);
			total += probabilidade.Last();
		}
		// gerar novos elementos. gera-se o doubro para poder seleccionar os melhores
		while (geracaoNova.Count() < 2 * populacao) {
			// escolher dois individuos aleatoriamente de acordo com as probabilidades
			int pai, mae, mutou = 0;
			Selecao(pai, mae, probabilidade, total);
			// gerar um novo individuo por cruzamento
			geracaoNova += ((TPonto)Duplicar());
			geracaoNova.Last()->Cruzamento(geracaoAntiga[pai], geracaoAntiga[mae]);
			// mudar o novo elemento, dependente da probabilidade
			if (TRand::rand() % 100 < (unsigned)probablidadeMutacao) {
				mutou = 1;
				geracaoNova.Last()->Mutar();
			}
			// avaliar o valor do elemento
			geracaoNova.Last()->Avaliar();
			DebugCruzamentoAG(
				geracaoAntiga[pai]->custo,
				geracaoAntiga[mae]->custo,
				geracaoNova.Last()->custo,
				mutou);
			VerificaMelhor(melhor, geracaoNova.Last());
		}

		// a nova geração já tem elementos, apagar a antiga
		LibertarVector(geracaoAntiga);
		// seleccao: os melhores, com base no valor
		OrdemValor(geracaoNova, id);
		// remover os elementos que são muito parecidos
		for (int i = 0; i < populacao && i < geracaoNova.Count(); i++) {
			// verificar se ha outro elemento muito parecido la
			if (i > 0 && distanciaMinima > 0) {
				bool diferente = true;
				for (int j = 0; j < geracaoAntiga.Count(); j++)
					if (geracaoAntiga[j]->Distancia(geracaoNova[id[i]]) < distanciaMinima) {
						diferente = false;
						break;
					}
				if (!diferente)
					continue;
			}
			// este elemento fica, passando para a geração antiga
			geracaoAntiga += geracaoNova[id[i]];
			geracaoNova[id[i]] = NULL;
		}
		// todos os novos que não se mantêm, são apagados
		LibertarVector(geracaoNova);
		// tudo pronto para uma nova geração
	}
	// não há mais gerações, apagar tudo
	LibertarVector(geracaoAntiga);
	return melhor->custo;
}

void TProcuraMelhorativa::DebugCruzamentoAG(int gPai, int gMae, int gFilho, int mutou)
{
	Debug(DETALHE, false, "\n  Cruzar g %d x %d -> %d%s",
		gPai, gMae, gFilho, mutou ? "*" : "");
}

void TProcuraMelhorativa::DebugPassoAG(int pop, int min, int max)
{
	Debug(PASSOS, false, "\nÉpoca %d #%d - %d|%d [%d-%d]",
		epocas, pop, geracoes, iteracoes, min, max);
}


void TProcuraMelhorativa::OrdemValor(TVector<TPonto>& populacao, TVector<int>& id) {
	TVector<int> valor;
	for (int i = 0; i < populacao.Count(); i++)
		valor += populacao[i]->custo;
	valor.Sort(&id);
}

void TProcuraMelhorativa::Selecao(int& pai, int& mae, TVector<int>& pesos, int total) {
	int valor = TRand::rand() % total;
	pai = 0;
	while (valor >= 0)
		valor -= pesos[pai++];
	pai--;
	valor = TRand::rand() % total;
	mae = 0;
	while (valor >= 0)
		valor -= pesos[mae++];
	mae--;
}

void TProcuraMelhorativa::ObterExtremos(TVector<TPonto>& populacao, int& minCusto, int& maxCusto) {
	minCusto = maxCusto = populacao.First()->custo;
	for (auto elemento : populacao) {
		if (elemento->custo < minCusto)
			minCusto = elemento->custo;
		if (elemento->custo > maxCusto)
			maxCusto = elemento->custo;
	}
}

int TProcuraMelhorativa::AlgoritmoEvolutivo()
{
	TVector<TPonto> populacao, pais, descendentes;
	Avaliar(); // avaliar a solução atual, fica sempre com o melhor resultado
	while (!Parar()) {
		// Repor o tamanho da população nesta geração
		populacao = CompletarPopulacaoAE(populacao);
		// Reportar informação sobre a geração
		DebugGeracaoAE(epocas, populacao);
		// Selecionar pais
		pais = SelecionarPaisAE(populacao);
		// Gerar descendentes por cruzamento
		// Mutar descendentes
		// Avaliar descendentes
		descendentes = ReproduzirAE(pais, populacao);
		// Selecionar sobreviventes entre pais e descendentes
		populacao = SelecionarSobreviventesAE(populacao, descendentes);
		// Aplicar a diversidade
		populacao = AplicarDiversidadeAE(populacao);
		epocas++;
	}
	return custo;
}

void TProcuraMelhorativa::DebugGeracaoAE(int epoca, TVector<TPonto>& populacao) {
	// mostrar informação sobre a população
	if (Debug(PASSOS, false, "\n ├─"))
	{
		int minimo, maximo;
		Debug(PASSOS, true, "─") || Debug(DETALHE, false, "┬");
		Debug(PASSOS, false, "─ %-2s%d %-2s%s ────",
			Icon(EIcon::EPOCA), epoca, Icon(EIcon::TEMPO), MostraTempo(Cronometro(CONT_ALGORITMO)));
		if (populacao.Empty())
			return;
		ObterExtremos(populacao, minimo, maximo);
		Debug(PASSOS, false, " %-2sg%d-%d", Icon(EIcon::VALOR), minimo, maximo);
		if (Parametro(NIVEL_DEBUG) == DETALHE) { // mostrar custos de toda a população
			int minDist, maxDist, avgDist, melhorPior, maiorCusto = 0;
			TVector<int> custos;
			// mostrar diversidade da população
			DiversidadeAE(populacao, minDist, maxDist, avgDist, melhorPior);
			Debug(DETALHE, false, " [%-2s%d-%d (μ=%d, melhor/pior %d)]",
				Icon(EIcon::DIST), minDist, maxDist, avgDist, melhorPior);
			for (auto individuo : populacao) {
				custos += individuo->custo;
				if (maiorCusto < individuo->custo)
					maiorCusto = individuo->custo;
			}
			char str[256];
			snprintf(str, sizeof(str), "%-2s%-2s", Icon(EIcon::ELEMENTO), Icon(EIcon::VALOR));
			DebugTabela(DETALHE, custos, str, " │ │", 1000000 + maiorCusto);
			Debug(DETALHE, false, "\n │ └──────────────────────────────────── ");
		}
		else if (Parametro(NIVEL_DEBUG) >= COMPLETO) { // mostrar diversidade da população
			DebugPopulacaoAE(populacao, Icon(EIcon::POP));
			DebugDiversidadeAE(populacao, Icon(EIcon::DIVERSIDADE));
		}
	}
}

void TProcuraMelhorativa::DebugPopulacaoAE(TVector<TPonto>& populacao, const char* titulo)
{
	int maiorCusto = 0;
	for (auto ind : populacao)
		if (maiorCusto < ind->custo)
			maiorCusto = ind->custo;
	printf("\n │ ├───── %s ───── ", titulo);
	for (int i = 0; i < populacao.Count(); i++) {
		printf("\n │ │ %-2s", Icon(EIcon::ELEMENTO));
		DebugID(i + 1, populacao.Count());
		populacao[i]->Debug(false);
		printf(" %-2s", Icon(EIcon::VALOR));
		DebugHSL((1 - 1.0f * populacao[i]->custo / maiorCusto) * 120, .75, .5, false);
		printf("g:%d", populacao[i]->custo);
		DebugHSL();
	}
}

void TProcuraMelhorativa::DebugDiversidadeAE(TVector<TPonto>& populacao, const char* titulo)
{
	printf("\n │ ├───── %s ───── ", titulo);
	if (populacao.Count() <= 10) { // matriz de distâncias
		printf("\n │ │  %-2s │", Icon(EIcon::ELEMENTO));
		for (int i = 0; i < populacao.Count(); i++) {
			DebugID(i + 1, populacao.Count());
			printf("│");
		}
		printf("\n │ │ ────┼");
		for (int i = 0; i < populacao.Count(); i++)
			printf("────┼");
		for (int i = 0; i < populacao.Count(); i++) {
			printf("\n │ │ ");
			DebugID(i + 1, populacao.Count());
			printf("│");
			for (int j = 0; j < populacao.Count(); j++)
				if (i == j)
					printf("    │");
				else
					printf("%4d│", populacao[i]->Distancia(populacao[j]));
		}
		printf("\n │ │ ────┴");
		for (int i = 0; i < populacao.Count(); i++)
			printf("────┴");
	}
	else { // distâncias entre dois elementos aleatórios
		TVector<int> id;
		for (int i = 0; i < populacao.Count(); i++)
			id += i;
		//id.RandomOrder(); // não utilizar aleatório para não alterar a sequência para o algoritmo principal
		printf("\n │ │  %-2s │ %-2s │ %-2s │\n │ │ ────┼────┼────┼",
			Icon(EIcon::ELEMENTO), Icon(EIcon::ELEMENTO), Icon(EIcon::DIST));
		for (int i = 0; i < id.Count(); i += 2) {
			printf("\n │ │ ");
			DebugID(id[i] + 1, populacao.Count());
			printf("│");
			DebugID(id[i + 1] + 1, populacao.Count());
			printf("│%4d│", populacao[id[i]]->Distancia(populacao[id[i + 1]]));
		}
		printf("\n │ │ ────┴────┴────┴");
	}
}

void TProcuraMelhorativa::DebugID(int id, int pop)
{
	DebugHSL(360.0f * id / pop);
	printf("%-4d", id);
	DebugHSL();
}

void TProcuraMelhorativa::DiversidadeAE(TVector<TPonto>& populacao,
	int& minDist, int& maxDist, int& avgDist, int& melhorPior)
{
	// processar todos os pares 
	// Futuro: caso POPULACAO seja grande, processar apenas alguns pares
	int contagem = 0, melhor = 0, pior = populacao.Count() - 1;
	minDist = INT_MAX;
	maxDist = 0;
	avgDist = 0;
	for (int i = 0; i < populacao.Count(); i++) {
		if (populacao[i]->custo < populacao[melhor]->custo)
			melhor = i;
		if (populacao[i]->custo > populacao[pior]->custo)
			pior = i;
		for (int j = i + 1; j < populacao.Count(); j++) {
			int dist = populacao[i]->Distancia(populacao[j]);
			if (dist < minDist)
				minDist = dist;
			if (dist > maxDist)
				maxDist = dist;
			avgDist += dist;
			contagem++;
		}
	}
	melhorPior = populacao[melhor]->Distancia(populacao[pior]);
	if (contagem > 0)
		avgDist /= contagem;
	else
		minDist = avgDist = maxDist = 0;
}


TVector<TPonto> TProcuraMelhorativa::CompletarPopulacaoAE(TVector<TPonto>& populacao) {
	while (populacao.Count() < Parametro(POPULACAO) && !Parar()) {
		auto novo = Duplicar();
		novo->NovaSolucao();
		novo->Avaliar();
		VerificaMelhor(novo);
		populacao += novo;
	}
	return populacao;
}

TVector<TPonto> TProcuraMelhorativa::SelecionarPaisAE(TVector<TPonto>& populacao) {
	TVector<TPonto> pais;
	// selecionar os pais, de acordo com o método escolhido
	int descendentes = (Parametro(PERC_DESCENDENTES) * populacao.Count()) / 100;
	int pop = populacao.Count();
	pais = {};
	if (Parar())
		return pais;
	if (descendentes < 1)
		descendentes = 1;
	else if (descendentes > pop)
		descendentes = pop;

	Debug(COMPLETO, false, "\n │ ├─┬─── FASE %-2s Selecionar %d %-2spais ───── ",
		Icon(EIcon::SEL_PAIS), descendentes, Icon(EIcon::PAIS));
	if (Parametro(SELECAO) == 1) { // roleta
		// roleta implementada como Stochastic Universal Sampling (SUS)
		TVector<int> id, peso;
		TVector<float> probabilidades;
		int pressao = Parametro(PRESSAO);
		Debug(COMPLETO, false, "\n │ │ ├───── Roleta, pressão %d ───── ", pressao);
		OrdemValor(populacao, id);
		peso.Count(id.Count());
		peso.Reset(0);
		for (int i = 0; i < id.Count(); i++)
			peso[id[i]] = id.Count() - i;
		for (int i = 0; i < populacao.Count(); i++) {
			// calcular a probabilidade de um elemento ser selecionado
			// utilizando o método Ranking Selection
			probabilidades += ((2.0f - (float)pressao / 100.0f) / pop +
				(2.0f * (peso[i] - 1) * ((float)pressao / 100.0f - 1.0f)) / (float)(pop * (pop - 1)));
			if (i > 0)
				probabilidades[i] += probabilidades[i - 1];
		}
		probabilidades.Last() = 1;
		if (Parametro(NIVEL_DEBUG) >= COMPLETO) {
			TVector<int> prob;
			for (int i = 0; i < probabilidades.Count(); i++)
				prob += (int)((i == 0 ? probabilidades[i] :
					probabilidades[i] - probabilidades[i - 1]) * 1000 + 0.5);
			DebugTabela(COMPLETO, prob, "100%", " │ │ │ ", -1);
		}
		// escolher os pais (roleta implementado como SUS)
		float valor = (float)(TRand::rand() % 10000) / (descendentes * 10000.0f);
		for (int escolhido = 0; pais.Count() < descendentes; escolhido++) {
			while (pais.Count() < descendentes && valor <= probabilidades[escolhido]) {
				pais += populacao[escolhido];
				valor += 1.0f / (float)descendentes;
			}
		}
	}
	else if (Parametro(SELECAO) == 3) { // uniforme
		Debug(COMPLETO, false, "\n │ │ ├───── Uniforme ───── ");
		for (int i = 0; i < descendentes; i++)
			pais += populacao.Random();
	}
	else if (Parametro(SELECAO) == 2) { // torneio
		int tamanho = Parametro(TAMANHO_TORNEIO);
		int probMelhor = Parametro(PROB_MELHOR_TORNEIO);
		Debug(COMPLETO, false, "\n │ │ ├───── Torneio, tamanho %d, probabilidade melhor %d ───── ",
			tamanho, probMelhor);
		for (int i = 0; i < descendentes; i++) {
			TVector<TPonto> competidores;
			TVector<int> id;
			for (int j = 0; j < tamanho; j++)
				competidores += populacao.Random();
			// ordenar por custo
			OrdemValor(competidores, id);
			// escolher melhor ou segundo melhor
			if ((TRand::rand() % 100) < (unsigned)probMelhor)
				pais += competidores[id[0]];
			else
				pais += competidores[id[1 % tamanho]];
		}
	}
	// reportar quantas vezes cada elemento foi pai
	if (Parametro(NIVEL_DEBUG) >= COMPLETO) {
		TVector<int> pai;
		Debug(COMPLETO, false, "\n │ │ ├───── Número de seleções ───── ");
		pai.Count(populacao.Count());
		pai.Reset(0);
		for (auto elemento : pais) {
			int id = populacao.Find(elemento);
			if (id >= 0)
				pai[id]++;
		}
		DebugTabela(COMPLETO, pai, "#Pai", " │ │ │ ", -1);
	}
	Debug(COMPLETO, false, "\n │ │ └──────────────────────────────────── ");
	return pais;
}

TVector<TPonto> TProcuraMelhorativa::ReproduzirAE(TVector<TPonto>& pais, TVector<TPonto>& popoulacao) {
	TVector<TPonto> descendentes;
	int cruzamentos = 0, mutacoes = 0;
	int melhor, pior, igual; // estatística do avanço da nova geração
	TVector<int> custoPais, custoFilhos;
	descendentes = {};
	if (Parar()) 
		return descendentes;
	Debug(COMPLETO, false, "\n │ ├─┬─── FASE %-2s Reproduzir %d pais ───── ", Icon(EIcon::CRUZAR), pais.Count());
	Debug(COMPLETO, false, "\n │ │ ├───── Pais (%-2s) ───── ", Icon(EIcon::PAIS));
	pais.RandomOrder();
	if (Parametro(NIVEL_DEBUG) >= COMPLETO) {
		TVector<int> paiID;
		for (auto elemento : pais) {
			int id = popoulacao.Find(elemento);
			if (id >= 0)
				paiID += (id + 1);
		}
		DebugTabela(COMPLETO, paiID, Icon(EIcon::ELEMENTO), " │ │ │ ", popoulacao.Count(), true);
	}
	while (!pais.Empty()) {
		TPonto pai = pais.Pop();
		custoPais += pai->custo;

		if (pais.Empty()) {
			// não há mãe, apenas copiar o pai
			descendentes += pai->Duplicar();
		}
		else {
			TPonto mae = pais.Pop();
			custoPais += mae->custo;
			if (TRand::rand() % 100 < (unsigned)Parametro(PROB_CRUZAR)) {
				// gerar um novo individuo por cruzamento
				TPonto filho = pai->Duplicar();
				filho->Cruzamento(pai, mae);
				descendentes += filho;
				filho = mae->Duplicar();
				filho->Cruzamento(mae, pai);
				descendentes += filho;
				cruzamentos++;
			}
			else {
				// copia o elemento sem alterações
				descendentes += pai->Duplicar();
				descendentes += mae->Duplicar();
			}
		}
	}
	custoPais.Invert();
	// mutar e avaliar descendentes
	for (auto descendente : descendentes) {
		// mudar o novo elemento, dependente da probabilidade
		if (TRand::rand() % 100 < (unsigned)Parametro(PROB_MUTAR)) {
			descendente->Mutar();
			mutacoes++;
		}
		// avaliar o valor do elemento
		descendente->Avaliar();
		custoFilhos += descendente->custo;
		VerificaMelhor(descendente);
	}
	int maiorCusto = 0;
	for (auto custo : custoPais)
		if (maiorCusto < custo)
			maiorCusto = custo;
	for (auto custo : custoFilhos)
		if (maiorCusto < custo)
			maiorCusto = custo;

	melhor = pior = igual = 0;
	for (int i = 0; i < custoPais.Count(); i += 2) {
		int paiMelhor, paiPior;
		paiMelhor = paiPior = custoPais[i];
		if (paiMelhor > custoPais[i + 1])
			paiMelhor = custoPais[i + 1];
		if (paiPior < custoPais[i + 1])
			paiPior = custoPais[i + 1];
		for (int j = i; j <= i + 1; j++)
			if (custoFilhos[j] > paiPior)
				pior++;
			else if (custoFilhos[j] < paiMelhor)
				melhor++;
			else
				igual++;
	}

	Debug(COMPLETO, false, "\n │ │ ├───── Pais (%-2s) ───── ", Icon(EIcon::VALOR));
	DebugTabela(COMPLETO, custoPais, " 🧑‍🔬 ", " │ │ │ ", 1000000 + maiorCusto, true);
	Debug(COMPLETO, false, "\n │ │ ├───── Filhos (%.2s) %.2s%d  %.2s%d ───── %.2s%d %.2s%d %.2s%d",
		Icon(EIcon::VALOR),
		Icon(EIcon::CRUZAR), cruzamentos,
		Icon(EIcon::MUTAR), mutacoes,
		Icon(EIcon::UB), melhor,
		Icon(EIcon::EMPATE), igual,
		Icon(EIcon::LB), pior);
	DebugTabela(COMPLETO, custoFilhos, Icon(EIcon::ELEMENTO), " │ │ │ ", 1000000 + maiorCusto, true);
	Debug(COMPLETO, false, "\n │ │ └──────────────────────────────────── ");
	return descendentes;
}

TVector<TPonto> TProcuraMelhorativa::SelecionarSobreviventesAE(TVector<TPonto>& populacao, TVector<TPonto>& descendentes) {
	TVector<TPonto> elite;
	TVector<int> idElite;
	int nElite = Parametro(ELITISMO);
	int imigrantes = Parametro(IMIGRANTES);
	int melhorDescendente = INT_MAX;
	if(Parar()) 
		return populacao;
	Debug(COMPLETO, false, "\n │ ├─┬─── FASE %-2s Sobrevivência ───── ", Icon(EIcon::SOBREVIVENCIA));
	if (nElite > 0) {
		// 1. Copiar os N melhores da população atual
		TVector<int> id;
		OrdemValor(populacao, id); // melhor primeiro
		for (int i = 0; i < nElite && i < populacao.Count(); i++) {
			elite += populacao[id[i]]->Duplicar();
			elite.Last()->custo = populacao[id[i]]->custo;
			idElite += id[i];
		}
		// encontrar o melhor descendente
		melhorDescendente = MelhorCusto(descendentes);
	}

	if (Parametro(SOBREVIVENCIA) == 1) { // idade
		Debug(COMPLETO, false, "\n │ │ ├───── %-2s Idade ───── ", Icon(EIcon::IDADE));
		// remover os mais velhos (os que estão mais tempo na população)
		for (int i = 0; i < descendentes.Count() && i < populacao.Count(); i++) {
			delete populacao[i];
			populacao[i] = NULL;
		}
		populacao -= NULL;
		populacao += descendentes;
		descendentes = {};
	}
	else if (Parametro(SOBREVIVENCIA) == 2) { // substituir piores
		TVector<int> custos;
		Debug(COMPLETO, false, "\n │ │ ├───── Substituir piores ───── ");
		populacao += descendentes;
		descendentes = {};
		if (Parametro(NIVEL_DEBUG) >= COMPLETO) {
			for (auto individuo : populacao)
				custos += individuo->custo;
			Debug(COMPLETO, false, "\n │ │ ├───── Custos em ambas gerações ───── ");
			DebugTabela(COMPLETO, custos, "Ind", " │ │ │ ");
		}
		TVector<int> id;
		OrdemValor(populacao, id); // ordena por custo (melhor primeiro)
		TVector<TPonto> novaPopulacao;
		for (int i = 0; i < Parametro(POPULACAO); i++) {
			novaPopulacao += populacao[id[i]];
			populacao[id[i]] = NULL;
		}
		LibertarVector(populacao);
		populacao = novaPopulacao;
	}
	else if (Parametro(SOBREVIVENCIA) == 3) { // round-robin
		// cada elemento compete com q outros, os que perdem mais são eliminados
		int q = Parametro(Q_ROUND_ROBIN); // número de competidores
		TVector<int> perdas, custos;
		Debug(COMPLETO, false, "\n │ │ ├───── Round Robin (q: %d) ───── ", q);
		populacao += descendentes;
		descendentes = {};
		if (Parametro(NIVEL_DEBUG) >= COMPLETO) {
			for (auto individuo : populacao)
				custos += individuo->custo;
			Debug(COMPLETO, false, "\n │ │ ├───── Custos em ambas gerações ───── ", q);
			DebugTabela(COMPLETO, custos, "Ind", " │ │ │ ");
		}
		perdas.Count(populacao.Count());
		perdas.Reset(0);
		for (int i = 0; i < populacao.Count(); i++) {
			TPonto atual = populacao[i];
			for (int j = 0; j < q; j++) {
				TPonto oponente;
				do {
					oponente = populacao.Random();
				} while (oponente == atual && populacao.Count() > 1);
				if (atual->custo > oponente->custo)
					perdas[i]++;
			}
		}
		Debug(COMPLETO, false, "\n │ │ ├───── Número de perdas ───── ");
		DebugTabela(COMPLETO, perdas, "Perd", " │ │ │ ");
		// ordenar por número de perdas
		TVector<int> id;
		perdas.Sort(&id);
		TVector<TPonto> novaPopulacao;
		for (int i = 0; i < Parametro(POPULACAO); i++) {
			novaPopulacao += populacao[id[i]];
			populacao[id[i]] = NULL;
		}
		LibertarVector(populacao);
		populacao = novaPopulacao;
	}

	if (imigrantes > 0) {
		// 3. Adicionar novos elementos aleatórios
		Debug(COMPLETO, false, "\n │ │ ├───── 🚶‍♂️🌍 Imigrantes ",
			Icon(EIcon::IMIGRANTES));
		for (int i = 0; i < imigrantes && populacao.Count() - i > 0; i++) {
			// remover um aleatório para dar lugar a um imigrante
			int idx = TRand::rand() % populacao.Count();
			if (populacao[idx] != NULL)
				delete populacao[idx];
			populacao[idx] = NULL;
			Debug(COMPLETO, false, " %d✖ →🆕", idx + 1, Icon(EIcon::APAGADO), Icon(EIcon::IMIGRANTES));
		}
		Debug(COMPLETO, false, " ───── ");
	}
	populacao -= NULL;

	if (nElite > 0) {
		// 2. Garantir que os elites estão presentes
		//    (apenas se forem melhores que o melhor descendente)
		bool primeiro = false;
		for (int i = 0; i < elite.Count() && populacao.Count() - i > 0; i++) {
			if (elite[i]->custo < melhorDescendente) {
				// remover um aleatório para dar lugar ao elite
				int idx = TRand::rand() % populacao.Count();
				delete populacao[idx];
				populacao[idx] = elite[i];
				elite[i] = NULL;
				if (!primeiro) {
					Debug(COMPLETO, false, "\n │ │ ├───── %-2s Elite %d→%d",
						Icon(EIcon::ELITE), idElite[i] + 1, idx + 1);
					primeiro = true;
				}
				else
					Debug(COMPLETO, false, " %d→%d",
						idElite[i] + 1, idx + 1);
			}
		}
		LibertarVector(elite);
		if (primeiro)
			Debug(COMPLETO, false, " ───── ");
	}
	Debug(COMPLETO, false, "\n │ │ └──────────────────────────────────── ");
	return populacao;
}

TVector<TPonto> TProcuraMelhorativa::AplicarDiversidadeAE(TVector<TPonto>& populacao)
{
	int distMinima = Parametro(DIST_MINIMA);
	if (Parar())
		return populacao;
	if (Parametro(DIVERSIDADE) == 2) { // avaliação partilhada
		TVector<int> id, penalizados;
		int count = 0;
		for (int i = 0; i < populacao.Count(); i++)
			id += i;
		Debug(COMPLETO, false, "\n │ ├───── FASE %-2s Diversidade - avaliação partilhada ───── ",
			Icon(EIcon::DIVERSIDADE));
		for (int j = 0; j < populacao.Count(); j++) {
			if (id.Count() > 20)
				id.RandomOrder();
			for (int i = 0; i < id.Count() && i < 20; i++)
				if (j != id[i] &&
					populacao[j]->Distancia(populacao[id[i]]) <= distMinima) {
					populacao[j]->custo++; // soma 1 por cada elemento muito parecido
					populacao[id[i]]->custo++;
					count++;
					penalizados += (id[i] + 1);
					penalizados += (j + 1);
				}
		}
		if (!penalizados.Empty()) {
			penalizados.BeASet();
			Debug(COMPLETO, false, " (%d penalizações aplicadas)", count);
			DebugTabela(COMPLETO, penalizados, "Ind", " │ │ ");
		}
		Debug(COMPLETO, false, "\n │ └────────────────────────────────────── ");
	}
	else if (Parametro(DIVERSIDADE) == 3) { // limpeza
		TVector<int> id, remover;
		remover = {};
		for (int i = 0; i < populacao.Count(); i++)
			id += i;
		Debug(COMPLETO, false, "\n │ └───── FASE Diversidade - limpeza ───── ");
		for (int j = 0; j < populacao.Count(); j++) {
			if (id.Count() > 20)
				id.RandomOrder();
			for (int i = 0; i < id.Count() && i < 20; i++)
				if (j != id[i] &&
					populacao[j]->Distancia(populacao[id[i]]) <= distMinima)
				{
					remover += id[i];
					//remover += j; // apenas um
					id -= id[i];
					id -= j;
					break;
				}
		}
		for (auto i : remover) {
			delete populacao[i];
			populacao[i] = NULL;
			Debug(COMPLETO, false, " %-2s%d", Icon(EIcon::APAGADO), i + 1);
		}
		populacao -= NULL;
	}
	return populacao;
}


// Chamar sempre que uma solucao melhor que a actual e encontrada
void TProcuraMelhorativa::DebugMelhorEncontrado(TPonto ponto)
{
	if (Debug(ATIVIDADE, false, "\n │ %-2s %-2s%s %-2sg:%d\n─┴───────────────────",
		Icon(EIcon::TORNEIO), Icon(EIcon::TEMPO), MostraTempo(Cronometro(CONT_ALGORITMO)),
		Icon(EIcon::VALOR), custo))
	{
		Debug();
		printf("\n─┬───────────────────");
	}
}

int64_t TProcuraMelhorativa::Indicador(int id)
{
	if (id == IND_EPOCAS)
		return epocas;
	else if (id == IND_GERACOES)
		return geracoes;
	return TProcura::Indicador(id);
}

void TProcuraMelhorativa::LimparEstatisticas()
{
	TProcura::LimparEstatisticas();
	geracoes = epocas = 0;
}

int TProcuraMelhorativa::ExecutaAlgoritmo() {
	// escolher o algoritmo a executar
	switch (Parametro(ALGORITMO)) {
	case 1: return AlgoritmoEvolutivo();
		//case 3: return EscaladaDoMonte();
		//case 2: return AlgoritmoGenetico();
	}
	return -1;
}

void TProcuraMelhorativa::Explorar() {
	TVector<TPonto> populacao;
	TVector<TPonto> vizinhos;
	int melhorValor, melhorIndice;
	int opcao = 0, indA, indB, indC;
	int backupPopulacao = Parametro(POPULACAO);
	int backupNivelDebug = Parametro(NIVEL_DEBUG);
	int backupLimiteTempo = Parametro(LIMITE_TEMPO);
	int epoca = 0;

	Parametro(NIVEL_DEBUG) = EXTRA_DEBUG; // mostrar todo o debug existente, incluindo operadores
	Parametro(POPULACAO) = 4; // manter um número baixo de elementos, só para explorar manualmente
	Parametro(LIMITE_TEMPO) = 3600; // 1h para resolução manual

	LimparEstatisticas();
	Avaliar();
	populacao = {};
	populacao = CompletarPopulacaoAE(populacao);
	do {
		DebugGeracaoAE(epoca, populacao);
		if ((opcao = NovoValor("\n │ └─■ ⚡ Operação (1 ✨ Mutar, 2 🧬 Cruzar, 3 🔗 Vizinhos): ")) == NAO_LIDO)
			break;
		Dominio(opcao, 0, 3);
		debugPrefixo = " │ │ ";
		if (opcao == 1) { // mutar
			printf(" │ ┌───── %-2s ───── ", Icon(EIcon::MUTAR));
			printf("\n │ │ %-2s [1-%d]: ", Icon(EIcon::ELEMENTO), populacao.Count());
			indA = NovoValor("") - 1;
			Dominio(indA, 0, populacao.Count());
			printf(" │ │ %-2s  ", Icon(EIcon::ELEMENTO));
			populacao[indA]->Debug(false);
			populacao[indA]->Mutar();
			printf("\n │ │ %-2s  ", Icon(EIcon::MUTAR));
			populacao[indA]->Debug(false);
			populacao[indA]->Avaliar();
			if (!VerificaMelhor(populacao[indA]))
				populacao[indA]->Debug();
			printf("\n │ └────────────── ");
		}
		else if (opcao == 2) { // cruzar
			printf(" │ ┌───── %-2s ───── ", Icon(EIcon::CRUZAR));
			printf("\n │ │ %-2sPai [1-%d]: ", Icon(EIcon::ELEMENTO), populacao.Count());
			indA = NovoValor("") - 1;
			printf(" │ │ %-2sMãe [1-%d]: ", Icon(EIcon::ELEMENTO), populacao.Count());
			indB = NovoValor("") - 1;
			printf(" │ │ %-2sFilho [1-%d]: ", Icon(EIcon::ELEMENTO), populacao.Count());
			indC = NovoValor("") - 1;
			printf(" │ │ ");
			Dominio(indA, 0, populacao.Count());
			Dominio(indB, 0, populacao.Count());
			Dominio(indC, 0, populacao.Count());
			printf("\n │ │ %-2sPai   ", Icon(EIcon::ELEMENTO));
			populacao[indA]->Debug(false);
			printf("\n │ │ %-2sMãe   ", Icon(EIcon::ELEMENTO));
			populacao[indB]->Debug(false);
			populacao[indC]->Cruzamento(populacao[indA], populacao[indB]);
			printf("\n │ │ %-2sFilho ", Icon(EIcon::CRUZAR));
			populacao[indC]->Debug(false);
			populacao[indC]->Avaliar();
			if (!VerificaMelhor(populacao[indC]))
				populacao[indC]->Debug();
			printf("\n │ └────────────── ");
		}
		else if (opcao == 3) { // vizinhos
			printf(" │ ┌───── %-2s ───── ", Icon(EIcon::VIZINHO));
			printf("\n │ │ %-2s[1-%d]: ", Icon(EIcon::ELEMENTO), populacao.Count());
			indA = NovoValor("") - 1;
			Dominio(indA, 0, populacao.Count() - 1);
			printf(" │ │ %-2s  ", Icon(EIcon::ELEMENTO));
			populacao[indA]->Debug(false);
			populacao[indA]->Vizinhanca(vizinhos);
			CalcularAvaliacoes(vizinhos, melhorValor, melhorIndice);
			DebugPopulacaoAE(vizinhos, "Vizinhos");
			printf("\n │ │ %-2s[1-%d]: ", Icon(EIcon::ELEMENTO), vizinhos.Count());
			indB = NovoValor("") - 1;
			printf(" │ │ ");
			Dominio(indB, 0, vizinhos.Count() - 1);
			delete populacao[indA];
			populacao[indA] = vizinhos[indB];
			vizinhos[indB] = NULL;
			if (!VerificaMelhor(populacao[indA]))
				populacao[indA]->Debug();
			LibertarVector(vizinhos);
			printf("\n │ └────────────── ");
		}

		epoca++;
	} while (opcao > 0 && !Parar());
	printf(" └──────────────── ");
	debugPrefixo = "";
	LibertarVector(populacao);
	Parametro(NIVEL_DEBUG) = backupNivelDebug;
	Parametro(POPULACAO) = backupPopulacao;
	Parametro(LIMITE_TEMPO) = backupLimiteTempo;
}


