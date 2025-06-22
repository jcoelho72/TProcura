#include "TProcura.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// numero de geracaes de estados
int TProcura::geracoes = 0;
// numero de expansoes de estados
int TProcura::expansoes = 0;
// numero de chamadas a funcao heuristica
int TProcura::avaliacoes = 0;

// deadline da corrida atual
clock_t TProcura::instanteFinal = 0;
// flag de problemas de memória esgotada
bool TProcura::memoriaEsgotada = false;
// ID da instância atual (problemas com várias instâncias, a utilizar em SolucaoVazia())
TParametro TProcura::instancia = { NULL,1,1,1, NULL, NULL };
// adicionar parâmetros específicos, se necessário
TVector<TParametro> TProcura::parametro;

// conjuntos de valores de parâmetros, para teste
TVector<TVector<int>> TProcura::configuracoes;


void TProcura::ResetParametros()
{
	static const char* nomesAlgoritmos[] = {
		"Não definido" };
	static const char* nomesDebug[] = {
		"nada",
		"atividade",
		"passos",
		"detalhe",
		"completo" };
	// definir parametros base
	parametro.Count(0);
	// algoritmos
	parametro.Add({ "Algoritmo",1,1,1,"Algoritmo base a executar.", nomesAlgoritmos });
	// nivel de debug
	parametro.Add({ "Debug",0,0,4,"Nível de debug, de reduzido a completo.",nomesDebug });
	// seed 
	parametro.Add({ "Seed",1,1,1000000, "Semente aleatória para inicializar a sequência de números pseudo-aleatórios.",NULL });
	// limite tempo
	parametro.Add({ "Tempo",10,1,3600, "Tempo limite em segundos. ",NULL });
	// máximo de gerações
	parametro.Add({ "Gerações",0,0,1000000000, "Número de gerações máximo (0 não há limite). ", NULL });
	// máximo de expansões
	parametro.Add({ "Expansões",0,0,1000000000, "Número de expansões máximo (0 não há limite). ",NULL });
	// máximo de avaliacoes
	parametro.Add({ "Avaliações",0,0,1000000000, "Número de avaliações máximo (0 não há limite). ",NULL });

	// colocar as configurações vazias (podem ser inicializadas se existirem configurações de omissão)
	configuracoes.Count(0);
}


// Escrever informacao de debug sobre o objecto atual
void TProcura::Debug(void)
{
	if (parametro[nivelDebug].valor > nada)
		printf("\nTProcura::Debug() não definido.");
}



// Chamar antes de iniciar uma procura
void TProcura::LimparEstatisticas(clock_t& inicio)
{
	expansoes = geracoes = avaliacoes = 0;
	inicio = clock();
	instanteFinal = inicio + parametro[limiteTempo].valor * CLOCKS_PER_SEC;
	memoriaEsgotada = false;
}

// Metodo para teste manual do objecto (chamadas aos algoritmos, construcao de uma solucao manual)
// Este metodo destina-se a testes preliminares, e deve ser redefinido apenas se forem definidos novos algoritmos
void TProcura::TesteManual(const char* nome)
{
	int selecao, resultado;
	clock_t inicio;
	ResetParametros();
	TRand::srand(parametro[seed].valor);
	SolucaoVazia();
	LimparEstatisticas(inicio);
	while (true) {
		printf("\n%s", nome);
		MostraParametros();
		printf("\n[Estatísticas] expansões %d | gerações %d | avaliações %d ",
			expansoes, geracoes, avaliacoes);
		Debug();
		printf("\n\
_______________________________________________________________________________\n\
| 1 - Inicializar | 2 - Explorar | 3 - Solução/Caminho |\n\
| 4 - Parâmetros  | 5 - Executar | 6 - Configurações   | 7 - Teste");
		if ((selecao = NovoValor("\nOpção: ")) == NAO_LIDO)
			return;
		switch (Dominio(selecao, 0, 8)) {
		case 0: return;
		case 1: TRand::srand(parametro[seed].valor); SolicitaInstancia(); SolucaoVazia(); break;
		case 2: ExplorarSucessores(); break;
		case 3: MostrarSolucao(); break;
		case 4: EditarParametros(); break;
		case 5:
			// executar um algoritmo 
			LimparEstatisticas(inicio);
			resultado = ExecutaAlgoritmo();
			MostraParametros(0);
			printf("\nResultado: %d", resultado);
			FinalizarCorrida(inicio);
			break;
		case 6: EditarConfiguracoes(); break;
		case 7:
			TesteEmpirico(
				NovoValor("Instância inicial: "),
				NovoValor("Instancia final: "),
				NovoValor("Mostrar soluções? "));
			break;
		case 8: return;
		default: printf("\nOpção não definida."); break;
		}
	}
}

void TProcura::MostraParametros(int detalhe, TVector<int>* idParametros) {
	int nElementos = (idParametros == NULL ? parametro.Count() : idParametros->Count());
	printf("\n");
	for (int i = 0; i < nElementos; i++) {
		int parID = (idParametros == NULL ? i : (*idParametros)[i]);
		// identificação do parâmetro
		if (detalhe == 0 || parametro[parID].nome == NULL)
			printf("P%d:", parID + 1);
		else
			printf("P%d(%s): ", parID + 1, parametro[parID].nome);
		// valor do parâmetro
		if (detalhe == 0 || parametro[parID].nomeValores == NULL)
			printf("%d", parametro[parID].valor);
		else
			printf("%s", parametro[parID].nomeValores[parametro[parID].valor - parametro[parID].min]);
		// mostrar intervalo permitido
		if (detalhe > 1)
			printf(" (%d a %d)", parametro[parID].min, parametro[parID].max);
		// separador/mudança de linha
		if (i < nElementos - 1) {
			if (detalhe > 1 || (i + 1) % (detalhe == 0 ? 10 : 4) == 0)
				printf("\n");
			else if (detalhe > 0)
				printf(" | ");
			else
				printf(" ");
		}
	}
}

void TProcura::EditarParametros() {
	int opcao = 0, valor;
	while (1) {
		MostraParametros(2);
		if ((opcao = NovoValor("\nParametro:")) == NAO_LIDO || opcao == 0)
			return;
		opcao = Dominio(opcao, 1, parametro.Count());
		// mostrar descrição se existir
		if (parametro[opcao - 1].descricao != NULL)
			printf("\n%s", parametro[opcao - 1].descricao);
		// mostrar textos dos valores possíveis, caso existam
		if (parametro[opcao - 1].nomeValores != NULL)
			for (int i = parametro[opcao - 1].min; i <= parametro[opcao - 1].max; i++)
				printf("\n%d: %s", i,
					parametro[opcao - 1].nomeValores[i - parametro[opcao - 1].min]);

		// valor atual
		if (parametro[opcao - 1].nome != NULL)
			printf("\n%s (atual %d): ", parametro[opcao - 1].nome, parametro[opcao - 1].valor);
		else
			printf("\nP%d (atual %d): ", opcao, parametro[opcao - 1].valor);
		// solicitar valor
		valor = NovoValor("");
		if (valor != NAO_LIDO || valor == 0)
			parametro[opcao - 1].valor = Dominio(
				valor,
				parametro[opcao - 1].min,
				parametro[opcao - 1].max);
	}
}

// gravar (ou ler) a configuração atual
void TProcura::ConfiguracaoAtual(TVector<int>& parametros, int operacao) {
	if (operacao == gravar) {
		for (int i = 0; i < parametro.Count() && i < parametros.Count(); i++)
			parametro[i].valor = parametros[i];
	}
	else if (operacao == ler) {
		parametros.Count(0);
		for (int i = 0; i < parametro.Count(); i++)
			parametros.Add(parametro[i].valor);
	}
}


void TProcura::EditarConfiguracoes() {
	TVector<int> atual; // parâmetros atuais
	int id = -1;

	ConfiguracaoAtual(atual, ler);

	// procurar a configuração atual
	for (int i = 0; i < configuracoes.Count() && id < 0; i++)
		if (configuracoes[i].Equal(atual))
			id = i;
	// caso a configuração atual não exista, adicionar
	if (id < 0) {
		configuracoes.Count(configuracoes.Count() + 1);
		configuracoes.Last() = atual;
		id = configuracoes.Count() - 1;
	}

	MostrarConfiguracoes(0, id);

	if ((id = NovoValor("\nSelecionar configuração (negativo apaga): ")) != NAO_LIDO) {
		id = Dominio(id, -configuracoes.Count() - 1, configuracoes.Count() + 1);
		if (id < 0) {
			configuracoes.Delete(-id - 1);
		}
		else if (id > 0) {
			atual = configuracoes[id - 1];
		}
	}
	ConfiguracaoAtual(atual, gravar);
}

void TProcura::MostrarConfiguracoes(int detalhe, int atual) {
	TVector<int> comum, distinto;
	// identificar parametros comuns e distintos entre as parametrizações
	for (int i = 0; i < configuracoes.First().Count(); i++) {
		bool igual = true;
		for (int j = 1; j < configuracoes.Count() && igual; j++)
			igual = (configuracoes.First()[i] == configuracoes[j][i]);
		if (igual)
			comum.Add(i);
		else
			distinto.Add(i);
	}
	// mostra parametros comuns, evitando repetição em cada configuração
	printf("\nParametros comuns a %d configurações:", configuracoes.Count());
	MostraParametros(detalhe, &comum);

	// visualizar configurações atuais, assinalando a atualmente escolhida
	for (int i = 0; i < configuracoes.Count(); i++) {
		printf("\n--- Configuração %d", i + 1);
		if (i == atual)
			printf(" --- atual");
		ConfiguracaoAtual(configuracoes[i], gravar);
		MostraParametros(detalhe, &distinto);
	}
}


// utilizar para executar testes empíricos, utilizando todas as instãncias,
// com o último algoritmo executado e configurações existentes
void TProcura::TesteEmpirico(int inicio, int fim, bool mostrarSolucoes) {
	TVector<TResultado> resultados; // guarda as soluções obtidas
	TVector<int> atual;
	int backupID = instancia.valor;
	if (inicio == NAO_LIDO || inicio == 0)
		inicio = instancia.min;
	if (fim == NAO_LIDO || fim == 0)
		fim = instancia.max;
	Dominio(inicio, instancia.min, instancia.max);
	Dominio(fim, instancia.min, instancia.max);
	ConfiguracaoAtual(atual, ler);
	if (configuracoes.Count() == 0) {
		// não foram feitas configurações, utilizar a atual
		configuracoes.Count(1);
		configuracoes.Last() = atual;
	}
	// percorrer todas as instâncias
	for (int configuracao = 0; configuracao < configuracoes.Count(); configuracao++) {
		ConfiguracaoAtual(configuracoes[configuracao], gravar);
		MostraParametros();
		for (instancia.valor = inicio; instancia.valor <= fim; instancia.valor++) {
			int resultado = -1;
			clock_t inicioCorrida;
			TRand::srand(parametro[seed].valor);
			// carregar instância
			SolucaoVazia();
			// executar um algoritmo 
			printf("\nInstância %d: ", instancia.valor);
			inicioCorrida = clock();
			LimparEstatisticas(inicioCorrida);
			resultado = ExecutaAlgoritmo();
			resultados.Add({
				instancia.valor,
				resultado,
				expansoes,geracoes,avaliacoes,configuracao,
				clock() - inicioCorrida });
			if (resultado >= 0) {
				if (mostrarSolucoes)
					MostrarSolucao();
			}
			else {
				if (Parar())
					printf("Não resolvido. ");
				if (TempoExcedido())
					printf("Tempo excedido. ");
				if (memoriaEsgotada)
					printf("Memória esgotada. ");
				if (resultado < 0 && !Parar())
					printf("Instância Impossível! (se algoritmo completo) ");
				else // não resolvido, cancelar resultados 
					resultados.Last().custo = -2;
			}
			printf("DONE.");
		}
	}
	MostraRelatorio(resultados);
	ConfiguracaoAtual(atual, gravar);
	instancia.valor = backupID;
	TRand::srand(parametro[seed].valor);
	SolucaoVazia();
}

void TProcura::MostraRelatorio(TVector<TResultado>& resultados)
{
	TVector<TResultado> total; // totais por cada configuração
	total.Count(configuracoes.Count());
	for (int i = 0; i < total.Count(); i++)
		total[i] = { 0,0,0,0,0,0,0 };

	// mostrar os resultados
	printf("\n ID |conf| custo(g) |  expansões |  gerações | avaliações | tempo(s) |");
	printf("\n----|----|----------|------------|-----------|------------|----------|");
	for (int i = 0; i < resultados.Count(); i++) {
		if (resultados[i].custo >= -1)
			total[resultados[i].configuracao].instancia++;
		printf("\n%3d |%3d |", resultados[i].instancia, resultados[i].configuracao + 1);
		if (resultados[i].custo < 0)
			printf(" %8s |", resultados[i].custo < -1 ? "não res." : "sem sol.");
		else
			printf(" %8d |", resultados[i].custo);
		printf(" %10d | %9d | %10d | %7.3fs |",
			resultados[i].expansoes,
			resultados[i].geracoes,
			resultados[i].avaliacoes,
			1. * resultados[i].tempo / CLOCKS_PER_SEC);
		if (resultados[i].custo > 0)
			total[resultados[i].configuracao].custo += resultados[i].custo;
		total[resultados[i].configuracao].expansoes += resultados[i].expansoes;
		total[resultados[i].configuracao].geracoes += resultados[i].geracoes;
		total[resultados[i].configuracao].avaliacoes += resultados[i].avaliacoes;
		total[resultados[i].configuracao].tempo += resultados[i].tempo;
	}
	printf("\n----|----|----------|------------|-----------|------------|----------| resolvidas");
	// tabela com os totais por configuração
	for (int i = 0; i < total.Count(); i++) {
		printf("\nTotal%3d |", i + 1);
		printf(" %8d | %10d | %9d | %10d | %7.3fs | %3d",
			total[i].custo,
			total[i].expansoes,
			total[i].geracoes,
			total[i].avaliacoes,
			1. * total[i].tempo / CLOCKS_PER_SEC,
			total[i].instancia);
	}
	// mostrar torneio entre configurações
	CalculaTorneio(resultados);
	MostrarConfiguracoes(1);
	printf("\n");
}

void TProcura::CalculaTorneio(TVector<TResultado>& resultados) {
	TVector<TVector<int>> torneio; // pares de configurações: 1 melhor, 0 igual -1 pior
	torneio.Count(configuracoes.Count());
	for (int i = 0; i < configuracoes.Count(); i++) {
		torneio[i].Count(configuracoes.Count());
		torneio[i].Reset(0);
	}
	// registar resultados mediante o melhor resultado
	for (int i = 0; i < configuracoes.Count(); i++)
		for (int j = 0; j < configuracoes.Count(); j++)
			if (i != j) {
				TVector<TResultado> configuracaoI, configuracaoJ;
				ExtrairConfiguracao(resultados, configuracaoI, i);
				ExtrairConfiguracao(resultados, configuracaoJ, j);
				for (int k = 0; k < configuracaoI.Count() && k < configuracaoJ.Count(); k++)
					if (configuracaoI[k].instancia == configuracaoJ[k].instancia)
						torneio[i][j] += MelhorResultado(configuracaoI[k], configuracaoJ[k]);
			}
	MostrarTorneio(torneio);
}


void TProcura::MostrarTorneio(TVector<TVector<int>>& torneio, bool jogo)
{
	TVector<int> pontos;
	pontos.Count(torneio.Count());
	pontos.Reset(0);
	// registar resultados mediante o melhor resultado
	for (int i = 0; i < torneio.Count(); i++)
		for (int j = 0; j < torneio.Count(); j++)
			if (i != j) {
				pontos[i] += torneio[i][j];
				if (jogo) // contar pontos perdidos de pretas
					pontos[j] -= torneio[i][j];
			}

	// mostrar tabela do torneio
	printf("\nTorneio (#instâncias melhores):");
	BarraTorneio(true);
	for (int i = 0; i < pontos.Count(); i++) {
		printf("\n%2d", i + 1);
		for (int j = 0; j < pontos.Count(); j++)
			if (i == j)
				printf("    |");
			else
				printf("%3d |", torneio[i][j]);
		// no final colocar os pontos totais
		printf("%3d", pontos[i]);
		BarraTorneio(false);
	}
}

void TProcura::ExtrairConfiguracao(TVector<TResultado>& resultados, TVector<TResultado>& extracao, int configuracao) {
	extracao.Count(0);
	for (int i = instancia.min; i <= instancia.max; i++)
		for (int j = 0; j < resultados.Count(); j++)
			if (resultados[j].instancia == i && resultados[j].configuracao == configuracao)
				extracao.Add(resultados[j]);
}


void TProcura::BarraTorneio(bool nomes) {
	// barra inical/final: |----|----|----|
	printf("\n |");
	for (int i = 0; i < configuracoes.Count(); i++)
		if (nomes)
			printf("-%02d-|", i + 1);
		else
			printf("----|");
}


int TProcura::MelhorResultado(TResultado base, TResultado alternativa) {
	// se não resolvido por ambos, retornar igualdade
	if (base.custo == -2 && alternativa.custo == -2)
		return 0;
	// se igual no custo e o tempo menor que 0.1, retornar igualdade
	if (base.custo == alternativa.custo && 10 * abs(base.tempo - alternativa.tempo) / CLOCKS_PER_SEC == 0)
		return 0;
	// primeiro custo (ou não resolvido, -2)
	if ((base.custo == -2 && alternativa.custo > -2) || (alternativa.custo > 0 && base.custo > alternativa.custo))
		return -1;
	if ((base.custo > -2 && alternativa.custo == -2) || (base.custo > 0 && alternativa.custo > base.custo))
		return 1;
	// agora o tempo
	return base.tempo < alternativa.tempo ? 1 : -1;
}

void TProcura::FinalizarCorrida(clock_t inicio)
{
	printf(" (%.3fs)", 1.0 * (clock() - inicio) / CLOCKS_PER_SEC);
	if (TempoExcedido())
		printf(" Tempo excedido.");
	else if (memoriaEsgotada)
		printf(" Memória esgotada.");
}


int TProcura::NovoValor(const char* prompt) {
	char str[BUFFER_SIZE];
	printf("%s", prompt);
	fgets(str, BUFFER_SIZE, stdin);
	if (strlen(str) > 1)
		return atoi(str);
	return NAO_LIDO;
}

void TProcura::SolicitaInstancia() {
	if (instancia.max != instancia.min) {
		int resultado;
		printf("\nNova instância (atual %d) [%d-%d]: ",
			instancia.valor,
			instancia.min,
			instancia.max);
		if ((resultado = NovoValor("")) != NAO_LIDO && resultado != 0) {
			instancia.valor = resultado;
			Dominio(instancia.valor, instancia.min, instancia.max);
		}
	}
	else
		instancia.valor = instancia.min;
}


int TProcura::Dominio(int& variavel, int min, int max) {
	if (variavel < min)
		variavel = min;
	if (variavel > max)
		variavel = max;
	return variavel;
}