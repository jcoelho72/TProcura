#include "TProcura.h"
#include <locale>
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>
#ifdef MPI_ATIVO
#include <mpi.h>
#endif
constexpr int BUFFER_SIZE = 1024;

// Resultado retornado pelo algoritmo na última execução.   
int TProcura::resultado = 0;
// tempo consumido na última execução.
double TProcura::tempo = 0;
// numero de iterações, conforme definido no algoritmo
int TProcura::iteracoes = 0;

// deadline da corrida atual
clock_t TProcura::instanteFinal = 0;
// flag de problemas de memória esgotada
bool TProcura::memoriaEsgotada = false;
// ID da instância atual (problemas com várias instâncias, a utilizar em SolucaoVazia())
TParametro TProcura::instancia = { NULL,1,1,1, NULL, NULL };
// nome do ficheiro de uma instância (utilizar como prefixo, concatenando com ID da instância)
char TProcura::ficheiroInstancia[256] = "instancia_";

// adicionar parâmetros específicos, se necessário
TVector<TParametro> TProcura::parametro;
// adicionar indicadores conforme a necessidade
TVector<TIndicador> TProcura::indicador;
// lista por ordem dos indicadores a utilizar
TVector<int> TProcura::indAtivo;

// MPI - rank do processo
int TProcura::mpiID = 0;
// MPI - número de processos
int TProcura::mpiCount = 1;
// Modo MPI : 0 = divisão estática, 1 = mestre-escravo
int TProcura::modoMPI = 0;


// conjuntos de valores de parâmetros, para teste
TVector<TVector<int>> TProcura::configuracoes;


void TProcura::ResetParametros()
{
	static const char* nomesAlgoritmos[] = {
		"Algoritmo base" };
	static const char* nomesDebug[] = {
		"NADA",
		"ATIVIDADE",
		"PASSOS",
		"DETALHE",
		"COMPLETO" };

	// definir parametros base
	parametro = {
		{ "ALGORITMO", 1, 1, 1, "Algoritmo base a executar.", nomesAlgoritmos },
		{ "NIVEL_DEBUG", 0, 0, 4, "Nível de debug, de reduzido a completo.", nomesDebug },
		{ "SEMENTE", 1, 1, 1000000, "Semente aleatória para inicializar a sequência de números pseudo-aleatórios." },
		{ "LIMITE_TEMPO", 10, 1, 3600, "Limnite de tempo em segundos. " },
		{ "LIMITE_ITERACOES", 0, 0, 1000000000, "Limite de número de iterações (0 não há limite). " }
	};

	// definir indicadores base
	indicador = {
		{ "Resultado", "Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).", IND_RESULTADO },
		{ "Tempo(ms)", "Tempo em milisegundos da execução (medida de esforço computacional).", IND_TEMPO },
		{ "Iterações", "Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).", IND_ITERACOES }
	};
	indAtivo = { IND_RESULTADO, IND_TEMPO, IND_ITERACOES };

	// colocar as configurações vazias (podem ser inicializadas se existirem configurações de omissão)
	configuracoes = {};
}

// retorna o valor do indicador[id]
int64_t TProcura::Indicador(int id) {
	switch (id) {
	case IND_RESULTADO:
		return resultado;
	case IND_TEMPO:
		return (int64_t)(1000 * tempo + 0.5);
	case IND_ITERACOES:
		return iteracoes;
	}
	return 0;
}

// Escrever informacao de debug sobre o objecto atual
void TProcura::Debug(bool completo)
{
	Debug(ATIVIDADE, false, "\nTProcura::Debug() método não redefinido.");
}

// Chamar antes de iniciar uma procura
void TProcura::LimparEstatisticas()
{
	resultado = iteracoes = 0;
	tempo = 0;
	instanteFinal = clock() + Parametro(LIMITE_TEMPO) * CLOCKS_PER_SEC;
	memoriaEsgotada = false;
	Cronometro(CONT_ALGORITMO, true);
}

// Metodo para teste manual do objecto (chamadas aos algoritmos, construcao de uma solucao manual)
// Este metodo destina-se a testes preliminares, e deve ser redefinido apenas se forem definidos novos algoritmos
void TProcura::TesteManual(const char* nome)
{
	int selecao;
	TVector<TResultado> resultados;
	ResetParametros();
	TRand::srand(Parametro(SEMENTE));
	Inicializar();
	LimparEstatisticas();
	while (true) {
		printf("\n%s", nome);
		MostraParametros();
		Debug();
		MostraRelatorio(resultados, true);
		printf("\n\
____________________________________________________________________\n\
| 1 - Inicializar | 2 - Explorar | 3 - Parâmetros    | 4 - Solução |\n\
| 5 - Indicadores | 6 - Executar | 7 - Configurações | 8 - Teste   |");
		if ((selecao = NovoValor("\nOpção: ")) == NAO_LIDO)
			return;
		switch (Dominio(selecao, 0, 9)) {
		case 0: return;
		case 1: TRand::srand(Parametro(SEMENTE)); SolicitaInstancia(); Inicializar(); break;
		case 2: Explorar(); break;
		case 3: EditarParametros(); break;
		case 4: MostrarSolucao(); break;
		case 5: if (EditarIndicadores())
			resultados = {};
			  break;
		case 6:
			// executar um algoritmo 
			LimparEstatisticas();
			resultado = ExecutaAlgoritmo();
			MostraParametros(0);
			tempo = Cronometro(CONT_ALGORITMO);
			ExecucaoTerminada();
			InserirRegisto(resultados, instancia.valor, 0);
			break;
		case 7: EditarConfiguracoes(); break;
		case 8: {
			TVector<int> instancias = SolicitaInstancias();
			TesteEmpirico(instancias, NovoTexto("Ficheiro (nada para mostrar no ecrã):"));
			break;
		}
		case 9: return;
		default: printf("\nOpção não definida."); break;
		}
	}
}

void TProcura::MostraParametros(int detalhe, TVector<int>* idParametros) {
	int nElementos = (idParametros == NULL ? parametro.Count() : idParametros->Count());
	int count = 0;
	printf("\n ");
	for (int i = 0; i < nElementos; i++) {
		int parID = (idParametros == NULL ? i : (*idParametros)[i]);
		if (!ParametroAtivo(parID))
			continue;
		count++;
		// identificação do parâmetro
		if (detalhe == 0 || parametro[parID].nome == NULL)
			printf("P%d=", parID + 1);
		else
			printf("P%d(%s): ", parID + 1, parametro[parID].nome);
		// valor do parâmetro
		if (detalhe == 0 || parametro[parID].nomeValores == NULL)
			printf("%d", Parametro(parID));
		else
			printf("%s", parametro[parID].nomeValores[Parametro(parID) - parametro[parID].min]);
		// mostrar intervalo permitido
		if (detalhe > 1)
			printf(" (%d a %d)", parametro[parID].min, parametro[parID].max);
		// separador/mudança de linha
		if (i < nElementos - 1) {
			if (detalhe > 1 || count % (detalhe == 0 ? 8 : 4) == 0)
				printf("\n ");
			else if (detalhe > 0)
				printf(" | ");
			else
				printf(" ");
		}
	}
}

bool TProcura::EditarIndicadores() {
	int opcao = 0;
	bool editado = false;
	while (true) {
		MostraIndicadores();
		if ((opcao = NovoValor("\nAlterar indicador: ")) == NAO_LIDO || opcao == 0)
			return editado;
		opcao = Dominio(opcao, 1, indicador.Count());
		if (indicador[opcao - 1].indice >= 0) {
			for (int i = 0; i < indicador.Count(); i++)
				if (i != opcao - 1 && indicador[i].indice > indicador[opcao - 1].indice)
					indicador[i].indice--;
			indicador[opcao - 1].indice = -1;
			indAtivo -= (opcao - 1);
		}
		else {
			indicador[opcao - 1].indice = 0;
			for (int i = 0; i < indicador.Count(); i++)
				if (i != opcao - 1 && indicador[i].indice >= indicador[opcao - 1].indice)
					indicador[opcao - 1].indice = indicador[i].indice + 1;
			indAtivo += (opcao - 1); // coloca no fim
		}
		// invalidar resultados atuais
		editado = true;
	}
	return editado;
}

void TProcura::EditarParametros() {
	int opcao = 0, valor;
	while (true) {
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
			printf("\n%s (atual %d): ", parametro[opcao - 1].nome, Parametro(opcao - 1));
		else
			printf("\nP%d (atual %d): ", opcao, Parametro(opcao - 1));
		// solicitar valor
		valor = NovoValor("");
		if (valor != NAO_LIDO || valor == 0)
			Parametro(opcao - 1) =
			Dominio(valor,
				parametro[opcao - 1].min,
				parametro[opcao - 1].max);
	}
}

int TProcura::NovaConfiguracao(TVector<int>& parametros)
{
	int id = -1;
	// procurar pela configuração
	for (int i = 0; i < configuracoes.Count() && id < 0; i++)
		if (configuracoes[i].Equal(parametros))
			id = i;
	if (id < 0) {
		configuracoes.Count(configuracoes.Count() + 1);
		configuracoes.Last() = parametros;
		return configuracoes.Count() - 1;
	}
	return id;
}


// gravar (ou ler) a configuração atual
void TProcura::ConfiguracaoAtual(TVector<int>& parametros, int operacao) {
	if (operacao == GRAVAR) {
		for (int i = 0; i < parametro.Count() && i < parametros.Count(); i++)
			Parametro(i) = parametros[i];
	}
	else if (operacao == LER) {
		parametros = {};
		for (int i = 0; i < parametro.Count(); i++)
			parametros += Parametro(i);
	}
}

char* TProcura::MostraTempo(double segundos)
{
	static char str[BUFFER_SIZE];
	static const int64_t segundo = 1000;
	static const int64_t minuto = 60 * segundo;
	static const int64_t hora = 60 * minuto;
	static const int64_t dia = 24 * hora;
	static const int64_t semana = 7 * dia;
	static const int64_t mes = 30 * dia;
	static const int64_t ano = 365 * dia;

	static TVector<int64_t> unidades = { ano, mes, semana, dia, hora, minuto, segundo };

	static TVector<char> unidadesStr = {
		'a', 'm', 's', 'd', 'h', '\'', '"'
	};

	int64_t ms = (int64_t)(1000 * segundos + 0.5);
	int len = 0;
	str[0] = 0;

	for (int i = 0; i < unidades.Count(); i++)
		if (ms >= unidades[i]) {
			len += snprintf(str + len, sizeof(str) - len, "%" PRId64 "%c ", ms / unidades[i], unidadesStr[i]);
			ms %= unidades[i];
		}
	if (ms > 0)
		len += snprintf(str + len, sizeof(str) - len, "%" PRId64 "ms ", ms);

	return str;
}

void TProcura::InserirRegisto(TVector<TResultado>& resultados, int inst, int conf)
{
	resultados += { inst, conf };
	for (auto ind : indAtivo)
		Registo(resultados.Last(), ind, Indicador(ind));
	// adicionar no final a solução codificada em inteíros
	resultados.Last().valor += CodificarSolucao();
}

int64_t TProcura::Registo(TResultado& resultado, int id)
{
	if (id >= 0 && id < indicador.Count() && indicador[id].indice >= 0)
		return resultado.valor[indicador[id].indice];
	return 0;
}

void TProcura::Registo(TResultado& resultado, int id, int64_t valor)
{
	if (id >= 0 && id < indicador.Count() && indicador[id].indice >= 0)
		resultado.valor[indicador[id].indice] = valor;
}

TVector<int> TProcura::SolicitaInstancias()
{
	char str[BUFFER_SIZE];
	printf("\nSintaxe (apenas inteiros, sem espaços):\n\
  A ou A,B,C   - único valor ou enumeração\n\
  A:B ou A:B:C - intervalo A a B, ou com passo C\n\
Introduza IDs das instâncias (de %d a %d): ", instancia.min, instancia.max);
	if (fgets(str, BUFFER_SIZE, stdin))
		if (strlen(str) > 1)
			return _TV(str);
	// colocar apenas a instância atual
	return TVector<int>() += instancia.valor;
}


void TProcura::EditarConfiguracoes() {
	TVector<int> atual; // parâmetros atuais
	int id = -1, auxID;
	char* str;

	ConfiguracaoAtual(atual, LER);

	id = NovaConfiguracao(atual);

	do {
		MostrarConfiguracoes(0, id);

		str = NovoTexto("\nSintaxe comando:\n\
  id / -id     - Seleciona configuração como atual ou apaga 'id'\n\
  Pk=<conj.>   - Varia Pk na configuração atual (gera N configurações)\n\
  Pk=<conj.> x Pw=<conj.> - produto externo de Pk e Pw (gera NxM configurações)\n\
Sintaxe de <conj.> (apenas inteiros, sem espaços):\n\
  A ou A,B,C   - único valor ou enumeração\n\
  A:B ou A:B:C - intervalo A a B, ou com passo C\n\
Comando: ");
		if (strlen(str) <= 1)
			break;

		if ((auxID = atoi(str)) != 0) {
			id = auxID;
			id = Dominio(id, -configuracoes.Count(), configuracoes.Count());
			if (id < 0) {
				id++;
				configuracoes.Delete(-id);
			}
			else if (id > 0) {
				id--;
				atual = configuracoes[id];
			}
		}
		else {
			InserirConfiguracoes(str, atual);
			configuracoes[id] = atual; // alterar atual se necessário
			ConfiguracaoAtual(atual, GRAVAR);
		}
	} while (true);
	ConfiguracaoAtual(atual, GRAVAR);
}

void TProcura::InserirConfiguracoes(char* str, TVector<int>& base) {
	char* pt, * contexto;
	TVector<int> currente, produto;
	TVector<TVector<int>> valores;

	// processar todos os itens a iniciar em P, obtendo informação entre quais existe x
	pt = compat::strtok(str, " \n\t\r", &contexto);
	while (pt) {
		if (*pt == 'P') {
			char* pt2;
			int param;
			if ((pt2 = strchr(pt + 1, '='))) {
				*pt2 = 0;
				param = atoi(pt + 1);
				if (param > 0 && param <= parametro.Count()) {
					valores.Count(valores.Count() + 1);
					valores.Last() = {};
					valores.Last() += param; // primeiro valor é ID do parâmetro
					valores.Last() += _TV(pt2 + 1); // valores para o parâmetro tomar
					if (valores.Last().Count() == 2) {
						// apenas um elemento, altera a configuração atual 
						// (se fosse para alternar, colocava o valor base masi o valor a alternar)
						int valor = valores.Last().Last();
						if (valor >= parametro[param - 1].min &&
							valor <= parametro[param - 1].max)
							base[param - 1] = valor;
					}
					if (valores.Last().Count() <= 2)
						valores.Count(valores.Count() - 1);
				}
			}
		}
		else if (*pt == 'x') {
			valores.Count(valores.Count() + 1);
			valores.Last() += 0; // produto externo
		}
		pt = compat::strtok(NULL, " \n\t\r", &contexto);
	}
	// inserir configurações de acordo com o pretendido (produto externo, ou apenas à configuração base)
	produto = {};
	for (int i = 0; i < valores.Count(); i++)
		if (valores[i].First() > 0) { // c.c. é o operador produto externo
			if (i == valores.Count() - 1 || valores[i + 1].First() != 0) { // não há outro produto externo, colocar na configuração atual
				produto += i;
				InserirConfiguracoes(base, produto, valores);
				produto = {};
			}
			else
				produto += i;
		}
}

void TProcura::InserirConfiguracoes(TVector<int>& base, TVector<int>& produto, TVector<TVector<int>>& valores)
{
	// inserir os valores do último elemento de forma recursiva
	int idLista = produto.Pop();
	TVector<int> backup = base;
	TVector<int>& lista = valores[idLista];
	int param = lista.First();

	for (int i = 1; i < lista.Count(); i++)
		if (lista[i] >= parametro[param - 1].min &&
			lista[i] <= parametro[param - 1].max)
		{
			base[param - 1] = lista[i];
			if (produto.Empty())
				NovaConfiguracao(base);
			else
				InserirConfiguracoes(base, produto, valores);
		}
	base = backup;
	produto += idLista;
}

void TProcura::MostrarConfiguracoes(int detalhe, int atual) {
	TVector<int> comum, distinto;
	// identificar parametros comuns e distintos entre as parametrizações
	for (int i = 0; i < configuracoes.First().Count(); i++) {
		bool igual = true;
		for (int j = 1; j < configuracoes.Count() && igual; j++)
			igual = (configuracoes.First()[i] == configuracoes[j][i]);
		if (igual)
			comum += i;
		else
			distinto += i;
	}
	// mostra parametros comuns, evitando repetição em cada configuração
	printf("\nParâmetros comuns:");
	MostraParametros(detalhe, &comum);

	// visualizar configurações atuais, assinalando a atualmente escolhida
	printf("\n- Configurações geradas (total: %d) -", configuracoes.Count());
	for (int i = 0; i < configuracoes.Count(); i++) {
		ConfiguracaoAtual(configuracoes[i], GRAVAR);
		MostraParametros(detalhe, &distinto);
		printf(" [%d]", i + 1);
		if (i == atual)
			printf(" --- atual");
	}
}


// utilizar para executar testes empíricos, utilizando todas as instãncias,
// com o último algoritmo executado e configurações existentes
void TProcura::TesteEmpirico(TVector<int> instancias, char* ficheiro) {
	TVector<TResultado> resultados; // guarda as soluções obtidas
	TVector<int> atual;
	int backupID = instancia.valor;
	int nTarefa = 0;
	double periodoReporte = 60;
	switch (Parametro(NIVEL_DEBUG)) {
	case DETALHE: periodoReporte = 10; break;
	case COMPLETO: periodoReporte = 1; break;
	}
	Cronometro(CONT_TESTE, true); // reiniciar cronómetro global
	Cronometro(CONT_REPORTE, true); // reiniciar cronómetro evento
	for (auto item : instancias)
		if (item<instancia.min || item>instancia.max)
			item = -1;
	instancias -= (-1);
	ConfiguracaoAtual(atual, LER);
	if (configuracoes.Empty()) {
		// não foram feitas configurações, utilizar a atual
		configuracoes.Count(1);
		configuracoes.Last() = atual;
	}
	if (mpiID == 0)
		Debug(ATIVIDADE, false,
			"\nTeste com %d tarefas, %d instâncias, %d configurações, utilizando %d processo(s). ",
			instancias.Count() * configuracoes.Count(), instancias.Count(), configuracoes.Count(), mpiCount) &&
		fflush(stdout);
	// percorrer todas as instâncias
	for (int configuracao = 0; configuracao < configuracoes.Count(); configuracao++) {
		ConfiguracaoAtual(configuracoes[configuracao], GRAVAR);

		for (auto inst : instancias) {
			// distribuir tarefas por MPI
			if ((nTarefa++) % mpiCount != mpiID)
				continue;

			if (Parametro(NIVEL_DEBUG) > NADA && mpiID == 0 && Cronometro(CONT_REPORTE) > periodoReporte) {
				Debug(ATIVIDADE, false, "\n%s Tarefa %d. ",
					MostraTempo(Cronometro(CONT_TESTE)), nTarefa - 1) &&
					fflush(stdout);
				Cronometro(CONT_REPORTE, true);
			}

			ExecutaTarefa(resultados, inst, configuracao);
		}
	}

	if (ficheiro == NULL || strlen(ficheiro) <= 1)
		MostraRelatorio(resultados);
	else {
		// gravar resultados em ficheiro CSV
		RelatorioCSV(resultados, ficheiro);

		double tempoLocal = Cronometro(CONT_TESTE);
		double tempoTotal = tempoLocal;
		double tempoMaximo = tempoLocal;
#ifdef MPI_ATIVO
		MPI_Reduce(&tempoLocal, &tempoTotal, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);
		MPI_Reduce(&tempoLocal, &tempoMaximo, 1, MPI_DOUBLE, MPI_MAX, 0, MPI_COMM_WORLD);
#endif

		if (mpiCount > 1 && mpiID == 0)
			// tenta juntar ficheiros, caso existam os ficheiros dos outros processos
			JuntarCSV(ficheiro);
		if (mpiID == 0)
			Debug(ATIVIDADE, false,
				"\nFicheiro %s.csv gravado.\n"
				"Tempo real: %s",
				ficheiro, MostraTempo(Cronometro(CONT_TESTE))) &&
			Debug(ATIVIDADE, false, "\nCPU total: %s",
				MostraTempo(Cronometro(CONT_TESTE) * mpiCount)) &&
			Debug(ATIVIDADE, false, "\nTaxa de utilização: %.1f%%",
				100. * tempoTotal / (tempoMaximo * mpiCount));
	}

	ConfiguracaoAtual(atual, GRAVAR);
	instancia.valor = backupID;
	TRand::srand(Parametro(SEMENTE));
	Inicializar();
}

void TProcura::TesteEmpiricoGestor(TVector<int> instancias, char* ficheiro)
{
#ifdef MPI_ATIVO
	int dados[3] = { 0, 0, 0 }; // instância, configuração
	double esperaTrabalhadores = 0, esperaGestor = 0;
	TVector<double> terminou; // instante em que terminou cada trabalhador
	TVector<int> trabalhador, trabalhar;
	double periodoReporte = 60;
	switch (Parametro(NIVEL_DEBUG)) {
	case DETALHE: periodoReporte = 10; break;
	case COMPLETO: periodoReporte = 1; break;
	}
	for (int i = 1; i < mpiCount; i++)
		trabalhador += i;

	terminou.Count(mpiCount);
	terminou.Reset(0);

	// Ciclo:
	// 1. Enviar trabalho para os escravos
	// 2. Encerrar escravos a mais
	// 3. Receber resultados e repetir 1 ou 2 conforme as necessidades

	TVector<TResultado> resultados; // guarda as soluções obtidas
	TVector<TResultado> tarefas; // guarda informação apenas das tarefas a realizar (sem resultados)
	TVector<int> atual;
	int backupID = instancia.valor;
	Cronometro(CONT_TESTE, true); // reiniciar cronómetro global
	Cronometro(CONT_REPORTE, true); // reiniciar cronómetro evento
	for (auto item : instancias)
		if (item<instancia.min || item>instancia.max)
			item = -1;
	instancias -= (-1);
	ConfiguracaoAtual(atual, LER);
	if (configuracoes.Empty()) {
		// não foram feitas configurações, utilizar a atual
		configuracoes.Count(1);
		configuracoes.Last() = atual;
	}

	// construir todas as tarefas
	for (int configuracao = 0; configuracao < configuracoes.Count(); configuracao++)
		for (auto inst : instancias)
			tarefas += { inst, configuracao };

	Debug(ATIVIDADE, false, "\nTeste com %d tarefas, %d instâncias, %d configurações, utilizando %d processo(s). ",
		tarefas.Count(), instancias.Count(), configuracoes.Count(),
		trabalhador.Count() + 1) &&
		fflush(stdout);

	// dar uma tarefa a cada escravo
	while (!tarefas.Empty() && !trabalhador.Empty()) {
		auto tarefa = tarefas.Pop();
		dados[0] = tarefa.instancia;
		dados[1] = tarefa.configuracao;
		trabalhar += trabalhador.Last();
		MPI_Send(dados, 2, MPI_INT, trabalhador.Pop(), TAG_TRABALHO, MPI_COMM_WORLD);
		esperaTrabalhadores += Cronometro(CONT_TESTE); // estava parado até esta altura
	}
	// caso existam escravos sem trabalho, mandar fechar todos, não há mais tarefas
	dados[0] = dados[1] = -1;
	while (!trabalhador.Empty()) {
		auto trabalhadorID = trabalhador.Pop();
		MPI_Send(dados, 2, MPI_INT, trabalhadorID, TAG_TRABALHO, MPI_COMM_WORLD);
		terminou[trabalhadorID] = Cronometro(CONT_TESTE);
	}

	// receber resultados e continuar a dar trabalho caso exista
	while (!trabalhar.Empty()) {
		MPI_Status stat;

		if (Parametro(NIVEL_DEBUG) > NADA && Cronometro(CONT_REPORTE) > periodoReporte) {
			// mostrar uma linha por cada execução
			Debug(ATIVIDADE, false, "\n%s Faltam %d tarefas, em curso %d",
				MostraTempo(Cronometro(CONT_TESTE)), tarefas.Count(), trabalhar.Count()) &&
				fflush(stdout);
			Cronometro(CONT_REPORTE, true);
		}

		double inicioEspera = Cronometro(CONT_TESTE);
		MPI_Recv(dados, 3, MPI_INT, MPI_ANY_SOURCE, TAG_CABECALHO, MPI_COMM_WORLD, &stat);
		esperaGestor += Cronometro(CONT_TESTE) - inicioEspera;
		resultados += {dados[0], dados[1]};
		resultados.Last().valor.Count(dados[2]);
		trabalhar -= stat.MPI_SOURCE;
		trabalhador += stat.MPI_SOURCE;
		MPI_Recv(resultados.Last().valor.Data(), dados[2], MPI_LONG_LONG,
			stat.MPI_SOURCE, TAG_VALORES, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		// tempo de espera do trabalhador
		esperaTrabalhadores += (double)((int64_t)resultados.Last().valor.Pop()) / 1000.;

		// ainda há tarefas
		if (!tarefas.Empty()) {
			auto tarefa = tarefas.Pop();
			dados[0] = tarefa.instancia;
			dados[1] = tarefa.configuracao;
			trabalhar += trabalhador.Last();
			MPI_Send(dados, 2, MPI_INT, trabalhador.Pop(), TAG_TRABALHO, MPI_COMM_WORLD);
		}
		else { // tudo feito, mandar sair
			dados[0] = dados[1] = -1;
			auto trabalhadorID = trabalhador.Pop();
			MPI_Send(dados, 2, MPI_INT, trabalhadorID, TAG_TRABALHO, MPI_COMM_WORLD);
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
			"\nFicheiro %s.csv gravado.\n"
			"Tempo real: %s",
			ficheiro, MostraTempo(Cronometro(CONT_TESTE))) &&
		Debug(ATIVIDADE, false, "\nCPU total: %s",
			MostraTempo(Cronometro(CONT_TESTE) * (backupCount - 1))) &&
		Debug(ATIVIDADE, false, "\nEspera do gestor: %s",
			MostraTempo(esperaGestor)) &&
		Debug(ATIVIDADE, false, "\nEspera total dos trabalhadores: %s",
			MostraTempo(esperaTrabalhadores)) &&
		Debug(ATIVIDADE, false, "\nTaxa de utilização:\n- Total: %.1f%%\n- Gestor: %.1f%%\n- Trabalhadores: %.1f%% ",
			taxaUtilizacao * 100, taxaUtilizacaoG * 100, taxaUtilizacaoT * 100);
	mpiCount = backupCount;

#endif
}

void TProcura::TesteEmpiricoTrabalhador(TVector<int> instancias, char* ficheiro)
{
#ifdef MPI_ATIVO
	int dados[3] = { 0, 0, 0 }; // instância, configuração
	// Ciclo:
	// 1. Solicitar tarefa ao mestre
	// 2. Executar tarefa
	// 3. Enviar resultados ao mestre
	// 4. Repetir até receber ordem de paragem

	TVector<TResultado> resultados; // guarda as soluções obtidas
	TVector<int> atual;
	int backupID = instancia.valor;
	Cronometro(CONT_TESTE, true); // reiniciar cronómetro global
	for (auto item : instancias)
		if (item<instancia.min || item>instancia.max)
			item = -1;
	instancias -= (-1);
	ConfiguracaoAtual(atual, LER);
	if (configuracoes.Empty()) {
		// não foram feitas configurações, utilizar a atual
		configuracoes.Count(1);
		configuracoes.Last() = atual;
	}

	for (;;) {
		// receber nova tarefa
		MPI_Recv(dados, 2, MPI_INT, 0, TAG_TRABALHO, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
		if (dados[0] < 0)
			break;

		ExecutaTarefa(resultados, dados[0], dados[1]);

		// enviar registo para master, e apagar
		// dados[0] e dados[1] já têm a configuração e instância
		dados[2] = resultados.Last().valor.Count() + 1;
		double inicioEspera = Cronometro(CONT_TESTE);
		MPI_Send(dados, 3, MPI_INT, 0, TAG_CABECALHO, MPI_COMM_WORLD);
		// colocar a espera no final do vetor de resultados
		resultados.Last().valor += (int64_t)((Cronometro(CONT_TESTE) - inicioEspera) * 1000 + 0.5);
		MPI_Send(resultados.Last().valor.Data(), dados[2], MPI_LONG_LONG, 0, TAG_VALORES, MPI_COMM_WORLD);

		resultados.Pop();
	}

	// saída, enviar o tempo de trabalho e tempo de espera totais

#endif
}

void TProcura::ExecutaTarefa(TVector<TResultado>& resultados, int inst, int conf)
{
	// carregar a configuração
	ConfiguracaoAtual(configuracoes[conf], GRAVAR);
	instancia.valor = inst;
	TRand::srand(Parametro(SEMENTE));
	// carregar instância
	Inicializar();
	// executar um algoritmo 
	Debug(COMPLETO, false, "instância %d: ", instancia.valor) && fflush(stdout);
	LimparEstatisticas();
	{
		ENivelDebug backupDebug = (ENivelDebug)Parametro(NIVEL_DEBUG);
		Parametro(NIVEL_DEBUG) = NADA; // remover informação de debug do algoritmo, já que é um teste empírico
		resultado = ExecutaAlgoritmo();
		Parametro(NIVEL_DEBUG) = backupDebug;
	}
	tempo = Cronometro(CONT_ALGORITMO);
	InserirRegisto(resultados, instancia.valor, conf);

	if (resultado >= 0) {
		if (Parametro(NIVEL_DEBUG) >= COMPLETO)
			MostrarSolucao();
	}
	else {
		if (Parar())
			Debug(COMPLETO, false, "Não resolvido. ");
		if (TempoExcedido())
			Debug(COMPLETO, false, "Tempo excedido. ");
		if (memoriaEsgotada)
			Debug(COMPLETO, false, "Memória esgotada. ");
		if (resultado < 0 && !Parar())
			Debug(COMPLETO, false, "Instância Impossível! (se algoritmo completo) ");
		else // não resolvido, cancelar resultados 
			resultados.Last().valor.First() = -2;
	}
	Debug(COMPLETO, false, "DONE.") && fflush(stdout);
}

// processa os argumentos da função main
void TProcura::main(int argc, char* argv[], const char* nome) {
	TVector<int> instancias;
	char fichResultados[256];
	char argParametros[BUFFER_SIZE] = "";

	compat::init_io();

	if (argc <= 1) {
		TesteManual(nome);
		return;
	}
	else if (strcmp(argv[1], "-h") == 0) {
		AjudaUtilizacao(argv[0]);
		return;
	}

	// 1:10  --- conjunto de instâncias (idêntico ao interativo)
	instancias = argv[1];
	if (instancias.Empty()) {
		AjudaUtilizacao(argv[0]);
		return;
	}

	snprintf(fichResultados, sizeof(fichResultados), "resultados");

	ResetParametros();

	// opcionais:
	// -R resultados --- ficheiro de resultados em CSV (adicionada extensão .csv)
	// -F instancia_ --- prefixo dos ficheiros de instâncias
	// -I 2,1,3 --- indicadores selecionados por ordem 
	// -P P1=1:3 x P2=0:2 --- formatação de parâmetros (idêntico ao interativo)
	for (int i = 2; i < argc; i++) {
		if (strcmp(argv[i], "-R") == 0 && i + 1 < argc) {
			snprintf(fichResultados, sizeof(fichResultados), "%s", argv[i + 1]);
		}
		else if (strcmp(argv[i], "-F") == 0 && i + 1 < argc) {
			snprintf(ficheiroInstancia, sizeof(ficheiroInstancia), "%s", argv[i + 1]);
		}
		else if (strcmp(argv[i], "-M") == 0 && i + 1 < argc) {
			if ((modoMPI = atoi(argv[i + 1])) != 1)
				modoMPI = 0; // apenas 0 ou 1
		}
		else if (strcmp(argv[i], "-I") == 0 && i + 1 < argc) {
			char* contexto;
			char* pt = compat::strtok(argv[i + 1], ",", &contexto);
			indAtivo = {};
			while (pt) {
				indAtivo += (atoi(pt) - 1);
				indicador[indAtivo.Last()].indice = indAtivo.Count() - 1;
				pt = compat::strtok(NULL, ",", &contexto);
			}
		}
		else if (strcmp(argv[i], "-P") == 0 && i + 1 < argc) {
			TVector<int> base;
			// o resto é para concatenar e enviar
			int len = 0;
			argParametros[0] = 0;
			while (++i < argc)
				len += snprintf(argParametros + len, sizeof(argParametros) - len, " %s", argv[i]);
			ConfiguracaoAtual(base, LER);
			InserirConfiguracoes(argParametros, base);
			ConfiguracaoAtual(base, GRAVAR);
			break;
		}
	}

	// arrancar MPI apenas após processar os argumentos
	InicializaMPI(argc, argv);

	if (Parametro(NIVEL_DEBUG) >= DETALHE && mpiID == 0)
		MostrarConfiguracoes(0, -1);

	if (modoMPI == 0 || mpiCount == 1)
		// divisão estática ou execução em série
		TesteEmpirico(instancias, fichResultados);
	else {
		if (mpiID == 0)
			// processo mestre
			TesteEmpiricoGestor(instancias, fichResultados);
		else
			// processos escravos
			TesteEmpiricoTrabalhador(instancias, fichResultados);
	}

	FinalizaMPI();
}

void TProcura::AjudaUtilizacao(const char* programa) {
	printf(
		"Uso: %s <instâncias> [opções]\n"
		"  <instâncias>    Conjunto de IDs: A | A,B,C | A:B[:C]\n"
		"Opções:\n"
		"  -R <ficheiro>   Nome do CSV de resultados (omissão: resultados.csv)\n"
		"  -F <prefixo>    Prefixo dos ficheiros de instância (omissão: instancia_)\n"
		"  -M <modo>       Modo MPI: 0 = divisão estática, 1 = gestor-trabalhador\n"
		"  -I <ind>        Lista de indicadores (e.g. 2,1,3)\n"
		"  -h              Esta ajuda\n"
		"  -P <expr>       Parâmetros (e.g. P1=1:3 x P2=0:2) - último campo\n"
		"Exemplo: %s 1:5 -R out -F fich_ -I 3,1,4,2 -P P1=1:5 x P6=1,2 \n"
		"   Executar sem argumentos entra em modo interativo, para explorar todos os parametros e indicadores\n",
		programa, programa
	);
	ResetParametros();
	printf("\nLista de parâmetros:");
	MostraParametros(2);
	printf("\n\nLista de indicadores:");
	MostraIndicadores();
}


bool TProcura::RelatorioCSV(TVector<TResultado>& resultados, char* ficheiro) {
	char* contexto;
	char* pt = compat::strtok(ficheiro, " \n\t\r", &contexto);
	char str[BUFFER_SIZE];
	if (mpiCount > 1)
		snprintf(str, sizeof(str), "%s_%d.csv", pt, mpiID);
	else
		snprintf(str, sizeof(str), "%s.csv", pt);
	FILE* f = compat::fopen(str, "wt");
	if (f != NULL) {
		// escrever BOM UTF-8 (apenas no mpiID 0)
		const unsigned char bom[] = { 0xEF,0xBB,0xBF };
		if (mpiID == 0) {
			fwrite(bom, 1, sizeof(bom), f);
			fprintf(f, "sep=;\n");
		}

		// cabeçalho: instância, parametros, indicadores
		fprintf(f, "Instância;");
		for (int i = 0; i < parametro.Count(); i++)
			fprintf(f, "P%d(%s);", i + 1, parametro[i].nome);
		for (auto item : indAtivo)
			fprintf(f, "I%d(%s);", item + 1, indicador[item].nome);
		fprintf(f, "\n");

		for (auto& res : resultados) {
			fprintf(f, "%d;", res.instancia);
			for (int j = 0; j < parametro.Count(); j++)
				// ver se parametro j está ativo na configuração configuracoes[res.configuracao]
				if (!ParametroAtivo(j, &(configuracoes[res.configuracao])))
					fprintf(f, ";"); // parametro inativo, não mostrar
				else if (parametro[j].nomeValores == NULL)
					fprintf(f, "%d;", configuracoes[res.configuracao][j]); // mostrar valor
				else
					fprintf(f, "%d:%s;", // mostrar valor e texto
						configuracoes[res.configuracao][j],
						parametro[j].nomeValores[configuracoes[res.configuracao][j] - parametro[j].min]);
			for (auto ind : indAtivo)
				fprintf(f, "%" PRId64 ";", Registo(res, ind));
			fprintf(f, "\n");
		}

		fclose(f);
	}
	else {
		printf("\nErro ao gravar ficheiro %s.", str);
		return false;
	}
	return true;
}

void TProcura::MostraRelatorio(TVector<TResultado>& resultados, bool ultimo)
{
	if (ultimo) {
		if (!resultados.Empty()) {
			int elementos = 0;
			for (auto ind : indAtivo) {
				if (elementos > 0)
					printf(" | ");
				if (elementos % 5 == 0)
					printf("\n");
				printf("I%d(%s): %" PRId64, ind + 1, indicador[ind].nome, Registo(resultados.Last(), ind));
				elementos++;
			}
		}
		return;
	}

	TVector<TResultado> total; // totais por cada configuração
	total.Count(configuracoes.Count());
	for (int i = 0; i < total.Count(); i++) {
		total[i].instancia = total[i].configuracao = 0;
		total[i].valor.Count(indicador.Count());
		total[i].valor.Reset(0);
	}

	// mostrar os resultados dos indicadores escolhidos
	printf("\n ID |conf|");
	for (auto ind : indAtivo)
		printf("%10s|", indicador[ind].nome);

	printf("\n----|----|");
	for (int i = 0; i < indAtivo.Count(); i++)
		printf("----------|");

	for (auto& res : resultados) {
		if (Registo(res, IND_RESULTADO) >= -1)
			total[res.configuracao].instancia++;
		printf("\n%3d |%3d |", res.instancia, res.configuracao + 1);

		for (auto ind : indAtivo)
			printf(" %8" PRId64 " |", Registo(res, ind));

		for (auto ind : indAtivo)
			Registo(total[res.configuracao], ind,
				Registo(total[res.configuracao], ind) +
				Registo(res, ind));
	}
	printf("\n----|----|");
	for (int i = 0; i < indAtivo.Count(); i++)
		printf("----------|");
	printf("resolvidas");
	// tabela com os totais por configuração
	for (int i = 0; i < total.Count(); i++) {
		printf("\nTotal%3d |", i + 1);

		for (auto ind : indAtivo)
			printf(" %8" PRId64 " |", Registo(total[i], ind));

		printf(" %d", total[i].instancia);
	}
	// mostrar torneio entre configurações
	CalculaTorneio(resultados);
	MostrarConfiguracoes(1);
	printf("\n");
}

void TProcura::CalculaTorneio(TVector<TResultado>& resultados) {
	TVector<TVector<int>> torneio; // pares de configurações: 1 melhor, 0 igual -1 pior
	torneio.Count(configuracoes.Count());
	for (int i = 0; i < torneio.Count(); i++) {
		torneio[i].Count(configuracoes.Count());
		torneio[i].Reset(0);
	}
	// registar resultados mediante o melhor resultado
	for (int i = 0; i < configuracoes.Count(); i++) {
		TVector<TResultado> configuracaoI = ExtrairConfiguracao(resultados, i);
		for (int j = 0; j < configuracoes.Count(); j++)
			if (i != j) {
				TVector<TResultado> configuracaoJ = ExtrairConfiguracao(resultados, j);
				// resultados sempre por mesma ordem de instância
				for (int k = 0; k < configuracaoI.Count() && k < configuracaoJ.Count(); k++)
					torneio[i][j] += MelhorResultado(configuracaoI[k], configuracaoJ[k]);
			}
	}
	MostrarTorneio(torneio);
}

void TProcura::MostraIndicadores()
{
	printf("\n");
	for (int i = 0; i < indicador.Count(); i++) {
		printf("\nI%d(%s): ", i + 1, indicador[i].nome);
		if (indicador[i].indice < 0)
			printf("inativo ");
		else
			printf("%dº lugar ", indicador[i].indice + 1);
		printf("(%s)", indicador[i].descricao);
	}
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

TVector<TResultado>  TProcura::ExtrairConfiguracao(TVector<TResultado>& resultados, int configuracao) {
	TVector<TResultado> extracao;
	for (auto& res : resultados)
		if (res.configuracao == configuracao)
			extracao += res;
	return extracao;
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
	// se não resolvido por ambos, retornar igualdade (assumir código -1 para impossível, -2 para não resolvido, menor é melhor)
	if (Registo(base, IND_RESULTADO) == -2 && Registo(alternativa, IND_RESULTADO) == -2)
		return 0;
	// se igual no custo e o tempo menor que 100, retornar igualdade
	if (Registo(base, IND_RESULTADO) == Registo(alternativa, IND_RESULTADO) &&
		abs(Registo(base, IND_TEMPO) - Registo(alternativa, IND_TEMPO)) / 100 == 0)
		return 0;
	// primeiro custo (ou não resolvido, -2)
	if ((Registo(base, IND_RESULTADO) == -2 &&
		Registo(alternativa, IND_RESULTADO) > -2) ||
		(Registo(alternativa, IND_RESULTADO) > 0 &&
			Registo(base, IND_RESULTADO) > Registo(alternativa, IND_RESULTADO)))
		return -1;
	if ((Registo(base, IND_RESULTADO) > -2 &&
		Registo(alternativa, IND_RESULTADO) == -2) ||
		(Registo(base, IND_RESULTADO) > 0 &&
			Registo(alternativa, IND_RESULTADO) > Registo(base, IND_RESULTADO)))
		return 1;
	// agora o tempo
	return Registo(base, IND_TEMPO) < Registo(alternativa, IND_TEMPO) ? 1 : -1;
}

void TProcura::ExecucaoTerminada()
{
	if (TempoExcedido())
		printf(" Tempo excedido.");
	else if (memoriaEsgotada)
		printf(" Memória esgotada.");
}

// MostrarSolucao: definir para visualizar a solução
void TProcura::MostrarSolucao() {
	TVector<int64_t> solucao = CodificarSolucao();
	printf("\nSolução: ");
	for (auto& x : solucao)
		printf("%" PRId64 " ", x);
	printf(".");
}


int TProcura::NovoValor(const char* prompt) {
	char str[BUFFER_SIZE];
	printf("%s", prompt);
	if (fgets(str, BUFFER_SIZE, stdin))
		if (strlen(str) > 1)
			return atoi(str);
	return NAO_LIDO;
}

// ler uma string
char* TProcura::NovoTexto(const char* prompt) {
	static char str[BUFFER_SIZE];
	printf("%s", prompt);
	if (fgets(str, BUFFER_SIZE, stdin) == nullptr)
		str[0] = 0;
	return str;
}


void TProcura::SolicitaInstancia() {
	if (instancia.max != instancia.min) {
		int resultado;
		char* texto;
		printf("\nID atual: %d  Intervalo: [%d–%d]  ",
			instancia.valor, instancia.min, instancia.max);
		printf("Prefixo atual: '%s' ", ficheiroInstancia);
		printf("\nNovo ID (ENTER mantém) ou novo prefixo (texto): ");

		texto = NovoTexto("");
		resultado = atoi(texto);
		if (resultado != 0 || strlen(texto) <= 1) {
			if (resultado != 0)
				instancia.valor = resultado;
			Dominio(instancia.valor, instancia.min, instancia.max);
		}
		else if (strlen(texto) < 256) {
			char* contexto;
			char* pt = compat::strtok(texto, " \n\t\r", &contexto);
			snprintf(ficheiroInstancia, sizeof(ficheiroInstancia), "%s", pt);
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

void TProcura::InicializaMPI(int argc, char* argv[])
{
#ifdef MPI_ATIVO
	MPI_Init(&argc, &argv);
	MPI_Comm_size(MPI_COMM_WORLD, &mpiCount);
	MPI_Comm_rank(MPI_COMM_WORLD, &mpiID);
	Debug(COMPLETO, false, "\nProcesso %d de %d iniciado.", mpiID, mpiCount) &&
		fflush(stdout);
#endif
}

void TProcura::FinalizaMPI()
{
#ifdef MPI_ATIVO
	Debug(COMPLETO, false, "\nProcesso %d de %d terminado.", mpiID, mpiCount) &&
		fflush(stdout);
	MPI_Finalize();
#endif
}

void TProcura::DebugTabela(ENivelDebug nivel, TVector<int> tabela, const char* tipo)
{
	Debug(nivel, false, "\n%4s|", tipo);
	for (int i = 0; i < 10 && i < tabela.Count(); i++)
		Debug(nivel, false, "%4d|", i + 1);
	Debug(nivel, false, "\n----|");
	for (int i = 0; i < 10 && i < tabela.Count(); i++)
		Debug(nivel, false, "----|");
	for (int i = 0; i < tabela.Count(); i++) {
		if (i % 10 == 0)
			Debug(nivel, false, "\n%4d|", i);
		Debug(nivel, false, "%4d|", tabela[i]);
	}
}

bool TProcura::JuntarCSV(const char* ficheiro)
{
	// ficheiros CSV com o mesmo cabeçalho, ficheiro0.csv, ficheiro1.csv, ..., ficheiroN.csv
	FILE* fGravar = NULL, * fLer = NULL;
	char nome[256], str[BUFFER_SIZE];

	// verifica se existem os ficheiros intermédios
	for (int i = 0; i < mpiCount; i++) {
		snprintf(nome, sizeof(nome), "%s_%d.csv", ficheiro, i);
		if ((fLer = compat::fopen(nome, "rt")) == NULL)
			// não existe este ficheiro, ainda não está tudo
			return false;
		fclose(fLer);
	}

	// todos os ficheiros existem, juntar
	snprintf(nome, sizeof(nome), "%s.csv", ficheiro);
	fGravar = compat::fopen(nome, "wt");
	if (fGravar == NULL) {
		printf("\nErro ao gravar ficheiro %s.", nome);
		return false;
	}

	for (int i = 0; i < mpiCount; i++) {
		snprintf(nome, sizeof(nome), "%s_%d.csv", ficheiro, i);
		fLer = compat::fopen(nome, "rt");
		if (fLer == NULL) {
			printf("\nErro ao ler ficheiro %s.", nome);
			continue;
		}
		while (!feof(fLer)) {
			if (fgets(str, BUFFER_SIZE, fLer) != NULL) {
				// evitar escrever o cabeçalho mais do que uma vez
				if (i > 0 && strncmp(str, "Instância;", 10) == 0)
					continue;
				fputs(str, fGravar);
			}
		}
		fclose(fLer);
		remove(nome); // apagar ficheiro intermédio
	}
	fclose(fGravar);
	return true;
}
