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
// flag de problemas de mem�ria esgotada
bool TProcura::memoriaEsgotada = false;
// ID da inst�ncia atual (problemas com v�rias inst�ncias, a utilizar em SolucaoVazia())
TParametro TProcura::instancia = { NULL,1,1,1, NULL, NULL };
// adicionar par�metros espec�ficos, se necess�rio
TVector<TParametro> TProcura::parametro;

// conjuntos de valores de par�metros, para teste
TVector<TVector<int>> TProcura::configuracoes;


void TProcura::ResetParametros()
{
	static const char* nomesAlgoritmos[] = {
		"N�o definido" };
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
	parametro.Add({ "Debug",0,0,4,"N�vel de debug, de reduzido a completo.",nomesDebug });
	// seed 
	parametro.Add({ "Seed",1,1,1000000, "Semente aleat�ria para inicializar a sequ�ncia de n�meros pseudo-aleat�rios.",NULL });
	// limite tempo
	parametro.Add({ "Tempo",10,1,3600, "Tempo limite em segundos. ",NULL });
	// m�ximo de gera��es
	parametro.Add({ "Gera��es",0,0,1000000000, "N�mero de gera��es m�ximo (0 n�o h� limite). ", NULL });
	// m�ximo de expans�es
	parametro.Add({ "Expans�es",0,0,1000000000, "N�mero de expans�es m�ximo (0 n�o h� limite). ",NULL });
	// m�ximo de avaliacoes
	parametro.Add({ "Avalia��es",0,0,1000000000, "N�mero de avalia��es m�ximo (0 n�o h� limite). ",NULL });

	// colocar as configura��es vazias (podem ser inicializadas se existirem configura��es de omiss�o)
	configuracoes.Count(0);
}


// Escrever informacao de debug sobre o objecto atual
void TProcura::Debug(void)
{
	if (parametro[nivelDebug].valor > nada)
		printf("\nTProcura::Debug() n�o definido.");
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
		printf("\n[Estat�sticas] expans�es %d | gera��es %d | avalia��es %d ",
			expansoes, geracoes, avaliacoes);
		Debug();
		printf("\n\
_______________________________________________________________________________\n\
| 1 - Inicializar | 2 - Explorar | 3 - Solu��o/Caminho |\n\
| 4 - Par�metros  | 5 - Executar | 6 - Configura��es   | 7 - Teste");
		if ((selecao = NovoValor("\nOp��o: ")) == NAO_LIDO)
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
				NovoValor("Inst�ncia inicial: "),
				NovoValor("Instancia final: "),
				NovoValor("Mostrar solu��es? "));
			break;
		case 8: return;
		default: printf("\nOp��o n�o definida."); break;
		}
	}
}

void TProcura::MostraParametros(int detalhe, TVector<int>* idParametros) {
	int nElementos = (idParametros == NULL ? parametro.Count() : idParametros->Count());
	printf("\n");
	for (int i = 0; i < nElementos; i++) {
		int parID = (idParametros == NULL ? i : (*idParametros)[i]);
		// identifica��o do par�metro
		if (detalhe == 0 || parametro[parID].nome == NULL)
			printf("P%d:", parID + 1);
		else
			printf("P%d(%s): ", parID + 1, parametro[parID].nome);
		// valor do par�metro
		if (detalhe == 0 || parametro[parID].nomeValores == NULL)
			printf("%d", parametro[parID].valor);
		else
			printf("%s", parametro[parID].nomeValores[parametro[parID].valor - parametro[parID].min]);
		// mostrar intervalo permitido
		if (detalhe > 1)
			printf(" (%d a %d)", parametro[parID].min, parametro[parID].max);
		// separador/mudan�a de linha
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
		// mostrar descri��o se existir
		if (parametro[opcao - 1].descricao != NULL)
			printf("\n%s", parametro[opcao - 1].descricao);
		// mostrar textos dos valores poss�veis, caso existam
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

// gravar (ou ler) a configura��o atual
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
	TVector<int> atual; // par�metros atuais
	int id = -1;

	ConfiguracaoAtual(atual, ler);

	// procurar a configura��o atual
	for (int i = 0; i < configuracoes.Count() && id < 0; i++)
		if (configuracoes[i].Equal(atual))
			id = i;
	// caso a configura��o atual n�o exista, adicionar
	if (id < 0) {
		configuracoes.Count(configuracoes.Count() + 1);
		configuracoes.Last() = atual;
		id = configuracoes.Count() - 1;
	}

	MostrarConfiguracoes(0, id);

	if ((id = NovoValor("\nSelecionar configura��o (negativo apaga): ")) != NAO_LIDO) {
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
	// identificar parametros comuns e distintos entre as parametriza��es
	for (int i = 0; i < configuracoes.First().Count(); i++) {
		bool igual = true;
		for (int j = 1; j < configuracoes.Count() && igual; j++)
			igual = (configuracoes.First()[i] == configuracoes[j][i]);
		if (igual)
			comum.Add(i);
		else
			distinto.Add(i);
	}
	// mostra parametros comuns, evitando repeti��o em cada configura��o
	printf("\nParametros comuns a %d configura��es:", configuracoes.Count());
	MostraParametros(detalhe, &comum);

	// visualizar configura��es atuais, assinalando a atualmente escolhida
	for (int i = 0; i < configuracoes.Count(); i++) {
		printf("\n--- Configura��o %d", i + 1);
		if (i == atual)
			printf(" --- atual");
		ConfiguracaoAtual(configuracoes[i], gravar);
		MostraParametros(detalhe, &distinto);
	}
}


// utilizar para executar testes emp�ricos, utilizando todas as inst�ncias,
// com o �ltimo algoritmo executado e configura��es existentes
void TProcura::TesteEmpirico(int inicio, int fim, bool mostrarSolucoes) {
	TVector<TResultado> resultados; // guarda as solu��es obtidas
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
		// n�o foram feitas configura��es, utilizar a atual
		configuracoes.Count(1);
		configuracoes.Last() = atual;
	}
	// percorrer todas as inst�ncias
	for (int configuracao = 0; configuracao < configuracoes.Count(); configuracao++) {
		ConfiguracaoAtual(configuracoes[configuracao], gravar);
		MostraParametros();
		for (instancia.valor = inicio; instancia.valor <= fim; instancia.valor++) {
			int resultado = -1;
			clock_t inicioCorrida;
			TRand::srand(parametro[seed].valor);
			// carregar inst�ncia
			SolucaoVazia();
			// executar um algoritmo 
			printf("\nInst�ncia %d: ", instancia.valor);
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
					printf("N�o resolvido. ");
				if (TempoExcedido())
					printf("Tempo excedido. ");
				if (memoriaEsgotada)
					printf("Mem�ria esgotada. ");
				if (resultado < 0 && !Parar())
					printf("Inst�ncia Imposs�vel! (se algoritmo completo) ");
				else // n�o resolvido, cancelar resultados 
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
	TVector<TResultado> total; // totais por cada configura��o
	total.Count(configuracoes.Count());
	for (int i = 0; i < total.Count(); i++)
		total[i] = { 0,0,0,0,0,0,0 };

	// mostrar os resultados
	printf("\n ID |conf| custo(g) |  expans�es |  gera��es | avalia��es | tempo(s) |");
	printf("\n----|----|----------|------------|-----------|------------|----------|");
	for (int i = 0; i < resultados.Count(); i++) {
		if (resultados[i].custo >= -1)
			total[resultados[i].configuracao].instancia++;
		printf("\n%3d |%3d |", resultados[i].instancia, resultados[i].configuracao + 1);
		if (resultados[i].custo < 0)
			printf(" %8s |", resultados[i].custo < -1 ? "n�o res." : "sem sol.");
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
	// tabela com os totais por configura��o
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
	// mostrar torneio entre configura��es
	CalculaTorneio(resultados);
	MostrarConfiguracoes(1);
	printf("\n");
}

void TProcura::CalculaTorneio(TVector<TResultado>& resultados) {
	TVector<TVector<int>> torneio; // pares de configura��es: 1 melhor, 0 igual -1 pior
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
	printf("\nTorneio (#inst�ncias melhores):");
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
	// se n�o resolvido por ambos, retornar igualdade
	if (base.custo == -2 && alternativa.custo == -2)
		return 0;
	// se igual no custo e o tempo menor que 0.1, retornar igualdade
	if (base.custo == alternativa.custo && 10 * abs(base.tempo - alternativa.tempo) / CLOCKS_PER_SEC == 0)
		return 0;
	// primeiro custo (ou n�o resolvido, -2)
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
		printf(" Mem�ria esgotada.");
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
		printf("\nNova inst�ncia (atual %d) [%d-%d]: ",
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