#include "TProcuraMelhorativa.h"

#include <stdio.h>
#include <time.h>
#include <string.h>


#define BUFFER_SIZE 1024

/// @brief Número de estados gerados 
int TProcuraMelhorativa::geracoes = 0;
/// @brief Número de épocas decorridas num algoritmo evolutivo. Uma época é uma geração única. 
int TProcuraMelhorativa::epocas = 0;

TProcuraMelhorativa::TProcuraMelhorativa(void)
{
	geracoes++; // cada estado criado conta como uma geração
}

TProcuraMelhorativa::~TProcuraMelhorativa(void)
{
}

void TProcuraMelhorativa::ResetParametros()
{
	static const char* nomesAlgoritmos[] = {
		"Escalada do Monte",
		"Algoritmo Genético" };
	static const char* nomesMovePrimeiro[] = { "Primeiro","Melhor" };
	TProcura::ResetParametros();

	parametro[limiteIteracoes].valor = 1000000;

	// adicionar parâmetros da procura melhorativa
	// alterar algoritmos
	parametro[algoritmo] = { "Algoritmo",1,1,2,"Escolha do algoritmo base a executar.", nomesAlgoritmos };

	// move primeiro
	parametro.Add({ "Move",1,1,2, "Utilizado na Escalada do Monte", nomesMovePrimeiro });
	// população
	parametro.Add({ "População",20,2,1000000, "Número de elementos em cada geração, utilizado nos Algoritmos Genéticos",NULL });
	// probabilidade de mutação
	parametro.Add({ "Mutação",50,0,100, "Probabilidade de um estado sofrer uma mutação após gerado, utilizado nos Algoritmos Genéticos",NULL });
	// distância mínima
	parametro.Add({ "Distância",0,0,1000, "Distância mínima imposta entre elementos da população, utilizado nos Algoritmos Genéticos",NULL });

	indicador.Add({ "Épocas","Número de épocas decorridas num algoritmo evolutivo. Uma época é uma geração única.", indEpocas });
	indicador.Add({ "Gerações","número de estados gerados", indGeracoes });
	indAtivo.Add(indEpocas).Add(indGeracoes);
}

// Retorna o valor da solucao completa actual.
int TProcuraMelhorativa::Avaliar(void)
{
	iteracoes++;
	return custo;
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo de procura local: Escalada do Monte
///////////////////////////////////////////////////////////////////////////////
// retorna a avaliacao do resultado actual
int TProcuraMelhorativa::EscaladaDoMonte()
{
	bool movePrimeiro = (parametro[movePrimeiroEM].valor == 1);
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
				while (vizinhos.Count() > 0) {
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
				int melhorValor, melhorIndice;
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
	if (parametro[nivelDebug].valor > 2) {
		if (parametro[nivelDebug].valor > 3)
			solucao->Debug();
	}
}


void TProcuraMelhorativa::DebugOptimoLocal(TPonto solucao) {
	if (parametro[nivelDebug].valor > 1) {
		printf(">> %d]", solucao->custo);
		if (parametro[nivelDebug].valor > 2) {
			solucao->Debug();
		}
	}
}

void TProcuraMelhorativa::DebugInicioEM(int ID, TPonto solucao)
{
	if (parametro[nivelDebug].valor > 1) {
		if (parametro[nivelDebug].valor > 2)
			printf("\n");
		printf("\nEscalada %d - ", ID);
		solucao->Debug();
	}
	if (parametro[nivelDebug].valor > 1) {
		if (parametro[nivelDebug].valor > 2)
			printf("\n");
		printf(" [%d >> ", solucao->custo);
		if (parametro[nivelDebug].valor > 3)
			solucao->Debug();
	}
}


void TProcuraMelhorativa::LibertarVector(TVector<TPonto>& vector, int excepto)
{
	for (int i = 0; i < vector.Count(); i++)
		if (i != excepto && vector[i] != NULL)
			delete vector[i];
	vector.Count(0);
}

void TProcuraMelhorativa::VerificaMelhor(TPonto& melhor, TPonto atual) {
	if (melhor->custo > atual->custo) {
		Copiar(atual);
		custo = melhor->custo = atual->custo;
		DebugMelhorEncontrado(melhor);
	}
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
	int populacao = parametro[populacaoAG].valor;
	int probablidadeMutacao = parametro[probMutacaoAG].valor;
	int distanciaMinima = parametro[distMinimaAG].valor;
	TVector<TPonto> geracaoAntiga, geracaoNova;
	TVector<int> id;
	TPonto melhor = this; // melhor estado para toda a procura
	NovaSolucao();
	melhor->Avaliar(); // avaliar o proprio
	if (parametro[nivelDebug].valor > 1)
		printf("\nPopulação inicial (%d elementos)", populacao);
	// construir a geracao inicial
	for (int i = 0; i < populacao; i++) {
		geracaoAntiga.Add((TPonto)Duplicar());
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
			probabilidade.Add(maximo - geracaoAntiga[i]->custo + 1);
			total += probabilidade.Last();
		}
		// gerar novos elementos. gera-se o doubro para poder seleccionar os melhores
		while (geracaoNova.Count() < 2 * populacao) {
			// escolher dois individuos aleatoriamente de acordo com as probabilidades
			int pai, mae, mutou = 0;
			Selecao(pai, mae, probabilidade, total);
			// gerar um novo individuo por cruzamento
			geracaoNova.Add((TPonto)Duplicar());
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
			geracaoAntiga.Add(geracaoNova[id[i]]);
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
	if (parametro[nivelDebug].valor > 2)
		printf("\n  Cruzar g %d x %d -> %d%s",
			gPai, gMae, gFilho, mutou ? "*" : "");
}

void TProcuraMelhorativa::DebugPassoAG(int pop, int min, int max)
{
	if (parametro[nivelDebug].valor == 1)
		printf(".");
	else if (parametro[nivelDebug].valor >= 2)
		printf("\nÉpoca %d #%d - %d|%d [%d-%d]",
			epocas, pop, geracoes, iteracoes, min, max);
}


void TProcuraMelhorativa::OrdemValor(TVector<TPonto>& populacao, TVector<int>& id) {
	TVector<int> valor;
	for (int i = 0; i < populacao.Count(); i++)
		valor.Add(populacao[i]->custo);
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
	for (int i = 0; i < populacao.Count(); i++) {
		if (i == 0 || populacao[i]->custo < minCusto)
			minCusto = populacao[i]->custo;
		if (i == 0 || populacao[i]->custo > maxCusto)
			maxCusto = populacao[i]->custo;
	}
}

// Chamar sempre que uma solucao melhor que a actual e encontrada
void TProcuraMelhorativa::DebugMelhorEncontrado(TPonto ponto)
{
	if (parametro[nivelDebug].valor > 0) {
		Debug();
	}
	if (parametro[nivelDebug].valor > 2)
		Debug();
}

int TProcuraMelhorativa::Indicador(int id)
{
	if (id == indEpocas)
		return epocas;
	else if (id == indGeracoes)
		return geracoes;
	return TProcura::Indicador(id);
}

void TProcuraMelhorativa::LimparEstatisticas(clock_t& inicio)
{
	TProcura::LimparEstatisticas(inicio);
	geracoes = epocas = 0;
}

int TProcuraMelhorativa::ExecutaAlgoritmo() {
	if (parametro[algoritmo].valor == 1)
		return EscaladaDoMonte();
	if (parametro[algoritmo].valor == 2)
		return AlgoritmoGenetico();
	return -1;
}

void TProcuraMelhorativa::Explorar() {
	static int populacao = 1;
	TVector<TPonto> elementos;
	int melhorValor, melhorIndice;
	int opcao = 0, indA, indB, indC;

	populacao = NovoValor("População (1 para vizinhos):");
	if (populacao < 0)
		populacao = 1;

	if (populacao > 1) {
		printf("\nTeste da Mutação e Cruzamento:");
		elementos.Count(populacao);
		for (int i = 0; i < populacao; i++) {
			elementos[i] = (TPonto)Duplicar();
			elementos[i]->NovaSolucao();
		}
		CalcularAvaliacoes(elementos, melhorValor, melhorIndice);
		DebugVizinhos(elementos);
		do {
			// solicitar operação de mutação ou cruzamento
			opcao = NovoValor("\nOperação (1 - Mutar, 2 - Cruzar): ");
			Dominio(opcao, 0, 2);
			if (opcao == 1) { // mutar
				printf("Individuo [1-%d]: ", elementos.Count());
				indA = NovoValor("") - 1;
				elementos[Dominio(indA, 0, elementos.Count() - 1)]->Mutar();
			}
			else if (opcao == 2) { // cruzar
				printf("Pai [1-%d]: ", elementos.Count());
				indA = NovoValor("") - 1;
				printf("Mãe [1-%d]: ", elementos.Count());
				indB = NovoValor("") - 1;
				printf("Filho [1-%d]: ", elementos.Count());
				indC = NovoValor("") - 1;
				Dominio(indA, 0, elementos.Count());
				Dominio(indB, 0, elementos.Count());
				Dominio(indC, 0, elementos.Count());
				elementos[indC]->Cruzamento(elementos[indA], elementos[indB]);
			}
			if (opcao != 0) {
				CalcularAvaliacoes(elementos, melhorValor, melhorIndice);
				DebugVizinhos(elementos);
			}
		} while (opcao != 0);
	}
	else {
		printf("\nTeste da Vizinhança:");
		NovaSolucao();
		do {
			char str[BUFFER_SIZE];
			custo = Avaliar();
			Vizinhanca(elementos);
			CalcularAvaliacoes(elementos, melhorValor, melhorIndice);
			// linha com informação
			Debug();
			DebugVizinhos(elementos);
			if (elementos.Count() == 0) {
				printf("\nSem vizinhos.");
				opcao = 0;
			}
			else {
				printf("\nVizinho (0 sai) [1-%d, ação]: ", elementos.Count());
				fgets(str, BUFFER_SIZE, stdin);
				opcao = atoi(str);
			}
			if (opcao > 0 && opcao <= elementos.Count()) {
				Copiar(elementos[opcao - 1]);
				custo = elementos[opcao - 1]->custo;
			}
			else if (strlen(str) > 1) {
				opcao = Acao(strtok(str, " \t\n\r"));
			}
			LibertarVector(elementos);
		} while (opcao != 0);
	}
}

// Mostrar vizinhos
void TProcuraMelhorativa::DebugVizinhos(TVector<TPonto>& vizinhos) {

}

