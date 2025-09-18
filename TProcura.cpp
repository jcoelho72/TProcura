#include "TProcura.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024

// Resultado retornado pelo algoritmo na última execução.
int TProcura::resultado = 0;
// tempo consumido na última execução.
int TProcura::tempo = 0;
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


// conjuntos de valores de parâmetros, para teste
TVector<TVector<int>> TProcura::configuracoes;


void TProcura::ResetParametros()
{
	static const char* nomesAlgoritmos[] = {
		"Algoritmo base" };
	static const char* nomesDebug[] = {
		"nada",
		"atividade",
		"passos",
		"detalhe",
		"completo" };

	// definir indicadores base
	indicador = {};
	indicador += { "Resultado", "Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).", 0 };
	indicador += { "Tempo(ms)", "Tempo em milisegundos da execução (medida de esforço computacional).", 1 };
	indicador += { "Iterações", "Iterações do algoritmo, intrepretadas conforme o algoritmo (medida de esforço independente do hardware).", 2 };
	for (int i = 0; i < indicador.Count(); i++) // ativar todos os indicadores
		indAtivo += i;

	// definir parametros base
	parametro = {};
	// algoritmos
	parametro += { "Algoritmo", 1, 1, 1, "Algoritmo base a executar.", nomesAlgoritmos };
	// nivel de debug
	parametro += { "Debug", 0, 0, 4, "Nível de debug, de reduzido a completo.", nomesDebug };
	// seed 
	parametro += { "Seed", 1, 1, 1000000, "Semente aleatória para inicializar a sequência de números pseudo-aleatórios.", NULL };
	// limite tempo
	parametro += { "Tempo", 10, 1, 3600, "Limnite de tempo em segundos. ", NULL };
	// máximo de iterações
	parametro += { "Iterações", 0, 0, 1000000000, "Limite de número de iterações (0 não há limite). ", NULL };

	// colocar as configurações vazias (podem ser inicializadas se existirem configurações de omissão)
	configuracoes = {};
}

// retorna o valor do indicador[id]
int TProcura::Indicador(int id) {
	switch (id) {
	case indResultado:
		return resultado;
	case indTempo:
		return tempo;
	case indIteracoes:
		return iteracoes;
	}
	return 0;
}

// Escrever informacao de debug sobre o objecto atual
void TProcura::Debug(void)
{
	if (Parametro(nivelDebug) > nada)
		printf("\nTProcura::Debug() método não redefinido.");
}

// Chamar antes de iniciar uma procura
void TProcura::LimparEstatisticas(clock_t& inicio)
{
	resultado = tempo = iteracoes = 0;
	inicio = clock();
	instanteFinal = inicio + Parametro(limiteTempo) * CLOCKS_PER_SEC;
	memoriaEsgotada = false;
}

// Metodo para teste manual do objecto (chamadas aos algoritmos, construcao de uma solucao manual)
// Este metodo destina-se a testes preliminares, e deve ser redefinido apenas se forem definidos novos algoritmos
void TProcura::TesteManual(const char* nome)
{
	int selecao;
	clock_t inicio;
	TVector<TResultado> resultados;
	ResetParametros();
	TRand::srand(Parametro(seed));
	Inicializar();
	LimparEstatisticas(inicio);
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
		case 1: TRand::srand(Parametro(seed)); SolicitaInstancia(); Inicializar(); break;
		case 2: Explorar(); break;
		case 3: EditarParametros(); break;
		case 4: MostrarSolucao(); break;
		case 5: if (EditarIndicadores())
			resultados = {};
			  break;
		case 6:
			// executar um algoritmo 
			LimparEstatisticas(inicio);
			resultado = ExecutaAlgoritmo();
			MostraParametros(0);
			ExecucaoTerminada(inicio);
			InserirRegisto(resultados, instancia.valor, 0);
			break;
		case 7: EditarConfiguracoes(); break;
		case 8: {
			TVector<int> instancias = SolicitaInstancias();
			char* ficheiro = NovoTexto("Ficheiro (nada para mostrar no ecrã):");
			int mostrarSol = NovoValor("Mostrar soluções? ");
			TesteEmpirico(instancias, mostrarSol, ficheiro);
			break;
		}
		case 9: return;
		default: printf("\nOpção não definida."); break;
		}
	}
}

void TProcura::MostraParametros(int detalhe, TVector<int>* idParametros) {
	int nElementos = (idParametros == NULL ? parametro.Count() : idParametros->Count());
	printf("\n ");
	for (int i = 0; i < nElementos; i++) {
		int parID = (idParametros == NULL ? i : (*idParametros)[i]);
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
			if (detalhe > 1 || (i + 1) % (detalhe == 0 ? 10 : 5) == 0)
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
	if (operacao == gravar) {
		for (int i = 0; i < parametro.Count() && i < parametros.Count(); i++)
			Parametro(i) = parametros[i];
	}
	else if (operacao == ler) {
		parametros = {};
		for (int i = 0; i < parametro.Count(); i++)
			parametros += Parametro(i);
	}
}

void TProcura::InserirRegisto(TVector<TResultado>& resultados, int inst, int conf)
{
	resultados += { inst, conf };
	for (auto ind : indAtivo)
		Registo(resultados.Last(), ind, Indicador(ind));
	// adicionar no final a solução codificada em inteíros
	resultados.Last().valor += CodificarSolucao();
}

int TProcura::Registo(TResultado& resultado, int id)
{
	if (id >= 0 && id < indicador.Count() && indicador[id].indice >= 0)
		return resultado.valor[indicador[id].indice];
	return 0;
}

void TProcura::Registo(TResultado& resultado, int id, int valor)
{
	if (id >= 0 && id < indicador.Count() && indicador[id].indice >= 0)
		resultado.valor[indicador[id].indice] = valor;
}

// Sintaxe de <lista> (apenas inteiros, sem espaços):
//   A ou A,B,C   - único valor ou enumeração
//   A:B ou A:B:C - intervalo A a B, ou com passo C
TVector<int> TProcura::ExtraiLista(char* str) {
	TVector<int> lista;
	char* pt;

	if (!str || *str == '\0')
		return lista;

	// separar por vírgulas
	if (pt = strchr(str, ',')) {
		*pt = 0;
		lista = ExtraiLista(str);
		do {
			str = pt + 1;
			if (pt = strchr(str, ','))
				*pt = 0;
			lista += ExtraiLista(str);
		} while (pt);
	}
	else {
		// procurar por : (intervalo)
		if (pt = strchr(str, ':')) {
			char* pt2;
			*pt = 0;
			int A = atoi(str);
			int C = 1;
			A = atoi(str);
			if (pt2 = strchr(pt + 1, ':')) { // A:B:C
				*pt2 = 0;
				if ((C = atoi(pt2 + 1)) <= 0)
					C = 1;
			} // c.c. A:B
			int B = atoi(pt + 1);
			if (A > B) { // ordem não interessa
				int aux = A;
				A = B;
				B = aux;
			}
			for (int i = A; i <= B; i += C)
				lista += i;
		}
		else // inteiro apenas
			lista += atoi(str);
	}
	lista.BeASet();
	return lista;
}

TVector<int> TProcura::SolicitaInstancias()
{
	TVector<int> instancias;
	char str[BUFFER_SIZE];
	printf("\nSintaxe (apenas inteiros, sem espaços):\n\
  A ou A,B,C   - único valor ou enumeração\n\
  A:B ou A:B:C - intervalo A a B, ou com passo C\n\
Introduza IDs das instâncias (de %d a %d): ", instancia.min, instancia.max);
	fgets(str, BUFFER_SIZE, stdin);
	if (strlen(str) > 1)
		return ExtraiLista(str);
	instancias += instancia.valor; // colocar apenas a instância atual
	return instancias;
}


void TProcura::EditarConfiguracoes() {
	TVector<int> atual; // parâmetros atuais
	int id = -1, auxID;
	char* str;

	ConfiguracaoAtual(atual, ler);

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
			ConfiguracaoAtual(atual, gravar);
		}
	} while (true);
	ConfiguracaoAtual(atual, gravar);
}

void TProcura::InserirConfiguracoes(char* str, TVector<int>& base) {
	char* pt;
	TVector<int> currente, produto;
	TVector<TVector<int>> valores;

	// processar todos os itens a iniciar em P, obtendo informação entre quais existe x
	pt = strtok(str, " \n\t\r");
	while (pt) {
		if (*pt == 'P') {
			char* pt2;
			int param;
			if (pt2 = strchr(pt + 1, '=')) {
				*pt2 = 0;
				param = atoi(pt + 1);
				if (param > 0 && param <= parametro.Count()) {
					valores.Count(valores.Count() + 1);
					valores.Last() = {};
					valores.Last() += param; // primeiro valor é ID do parâmetro
					valores.Last() += ExtraiLista(pt2 + 1); // valores para o parâmetro tomar
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
		pt = strtok(NULL, " \n\t\r");
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
			if (produto.Count() == 0)
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
		ConfiguracaoAtual(configuracoes[i], gravar);
		MostraParametros(detalhe, &distinto);
		printf(" [%d]", i + 1);
		if (i == atual)
			printf(" --- atual");
	}
}


// utilizar para executar testes empíricos, utilizando todas as instãncias,
// com o último algoritmo executado e configurações existentes
void TProcura::TesteEmpirico(TVector<int> instancias, bool mostrarSolucoes, char* ficheiro) {
	TVector<TResultado> resultados; // guarda as soluções obtidas
	TVector<int> atual;
	int backupID = instancia.valor;
	for (auto item : instancias)
		if (item<instancia.min || item>instancia.max)
			item = -1;
	instancias -= (-1);
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
		for (auto inst : instancias) {
			instancia.valor = inst;
			clock_t inicioCorrida;
			TRand::srand(Parametro(seed));
			// carregar instância
			Inicializar();
			// executar um algoritmo 
			printf("\nInstância %d: ", instancia.valor);
			inicioCorrida = clock();
			LimparEstatisticas(inicioCorrida);
			resultado = ExecutaAlgoritmo();
			tempo = clock() - inicioCorrida;
			InserirRegisto(resultados, instancia.valor, configuracao);

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
					resultados.Last().valor.First() = -2;
			}
			printf("DONE.");
		}
	}
	if (ficheiro == NULL || strlen(ficheiro) <= 1)
		MostraRelatorio(resultados);
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
			RelatorioCSV(resultados, f);
			printf("\nFicheiro %s gravado.", str);
			fclose(f);
		}
		else
			printf("\nErro ao gravar ficheiro %s.", str);
	}

	ConfiguracaoAtual(atual, gravar);
	instancia.valor = backupID;
	TRand::srand(Parametro(seed));
	Inicializar();
}

// processa os argumentos da função main
void TProcura::main(int argc, char* argv[], const char* nome) {
	if (argc <= 1) {
		TesteManual(nome);
	}
	else {
		TVector<int> instancias;
		bool mostrarSolucoes = false;
		char fichResultados[256];
		char argParametros[BUFFER_SIZE];
		strcpy(fichResultados, "resultados");

		if (strcmp(argv[1], "-h") == 0) {
			AjudaUtilizacao(argv[0]);
			return;
		}

		ResetParametros();

		// 1:10  --- conjunto de instâncias (idêntico ao interativo)
		instancias = ExtraiLista(argv[1]);
		if (instancias.Count() == 0) {
			AjudaUtilizacao(argv[0]);
			return;
		}

		// opcionais:
		// -R resultados --- ficheiro de resultados em CSV (adicionada extensão .csv)
		// -F instancia_ --- prefixo dos ficheiros de instâncias
		// -I 2,1,3 --- indicadores selecionados por ordem 
		// -P P1=1:3 x P2=0:2 --- formatação de parâmetros (idêntico ao interativo)
		for (int i = 2; i < argc; i++) {
			if (strcmp(argv[i], "-R") == 0 && i + 1 < argc) {
				strcpy(fichResultados, argv[i + 1]);
			}
			else if (strcmp(argv[i], "-F") == 0 && i + 1 < argc) {
				strcpy(ficheiroInstancia, argv[i + 1]);
			}
			else if (strcmp(argv[i], "-S") == 0) {
				mostrarSolucoes = true;
			}
			else if (strcmp(argv[i], "-I") == 0 && i + 1 < argc) {
				char* pt = strtok(argv[i + 1], ",");
				indAtivo = {};
				while (pt) {
					indAtivo += (atoi(pt) - 1);
					indicador[indAtivo.Last()].indice = indAtivo.Count() - 1;
					pt = strtok(NULL, ",");
				}
			}
			else if (strcmp(argv[i], "-P") == 0 && i + 1 < argc) {
				TVector<int> base;
				// o resto é para concatenar e enviar
				strcpy(argParametros, "");
				while (++i < argc) {
					strcat(argParametros, " ");
					strcat(argParametros, argv[i]);
				}
				ConfiguracaoAtual(base, ler);
				InserirConfiguracoes(argParametros, base);
				ConfiguracaoAtual(base, gravar);
				break;
			}
		}
		MostrarConfiguracoes(0, -1);
		TesteEmpirico(instancias, mostrarSolucoes, fichResultados);
	}
}

void TProcura::AjudaUtilizacao(const char* programa) {
	printf(
		"Uso: %s <instâncias> [opções]\n"
		"  <instâncias>    Conjunto de IDs: A | A,B,C | A:B[:C]\n"
		"Opções:\n"
		"  -R <ficheiro>   Nome do CSV de resultados (omissão: resultados.csv)\n"
		"  -F <prefixo>    Prefixo dos ficheiros de instância (omissão: instancia_)\n"
		"  -I <ind>        Lista de indicadores (e.g. 2,1,3)\n"
		"  -S              Mostrar soluções durante a execução\n"
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


void TProcura::RelatorioCSV(TVector<TResultado>& resultados, FILE* f) {
	// cabeçalho: instância, parametros, indicadores
	// TODO: poder-se selecionar parametros a mostrar
	fprintf(f, "Instância;");
	for (int i = 0; i < parametro.Count(); i++)
		fprintf(f, "P%d(%s);", i + 1, parametro[i].nome);
	for (auto item : indAtivo)
		fprintf(f, "I%d(%s);", item + 1, indicador[item].nome);
	fprintf(f, "\n");

	for (auto res : resultados) {
		fprintf(f, "%d;", res.instancia);
		for (int j = 0; j < parametro.Count(); j++)
			if (parametro[j].nomeValores == NULL)
				fprintf(f, "%d;", configuracoes[res.configuracao][j]);
			else
				fprintf(f, "%d:%s;",
					configuracoes[res.configuracao][j],
					parametro[j].nomeValores[configuracoes[res.configuracao][j] - parametro[j].min]);
		for (auto ind : indAtivo)
			fprintf(f, "%d;", Registo(res, ind));
		fprintf(f, "\n");
	}
}


void TProcura::MostraRelatorio(TVector<TResultado>& resultados, bool ultimo)
{
	if (ultimo) {
		if (resultados.Count() > 0) {
			int elementos = 0;
			for (auto ind : indAtivo) {
				if (elementos > 0)
					printf(" | ");
				if (elementos % 5 == 0)
					printf("\n");
				printf("I%d(%s): %d", ind + 1, indicador[ind].nome, Registo(resultados.Last(), ind));
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
	for (auto ind : indAtivo)
		printf("----------|");

	for (auto res : resultados) {
		if (Registo(res, indResultado) >= -1)
			total[res.configuracao].instancia++;
		printf("\n%3d |%3d |", res.instancia, res.configuracao + 1);

		for (auto ind : indAtivo)
			printf(" %8d |", Registo(res, ind));

		for (auto ind : indAtivo)
			Registo(total[res.configuracao], ind,
				Registo(total[res.configuracao], ind) +
				Registo(res, ind));
	}
	printf("\n----|----|");
	for (auto ind : indAtivo)
		printf("----------|");
	printf("resolvidas");
	// tabela com os totais por configuração
	for (int i = 0; i < total.Count(); i++) {
		printf("\nTotal%3d |", i + 1);

		for (auto ind : indAtivo)
			printf(" %8d |", Registo(total[i], ind));

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
	for (auto res : resultados)
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
	if (Registo(base, indResultado) == -2 && Registo(alternativa, indResultado) == -2)
		return 0;
	// se igual no custo e o tempo menor que 100, retornar igualdade
	if (Registo(base, indResultado) == Registo(alternativa, indResultado) &&
		abs(Registo(base, indTempo) - Registo(alternativa, indTempo)) / 100 == 0)
		return 0;
	// primeiro custo (ou não resolvido, -2)
	if ((Registo(base, indResultado) == -2 &&
		Registo(alternativa, indResultado) > -2) ||
		(Registo(alternativa, indResultado) > 0 &&
			Registo(base, indResultado) > Registo(alternativa, indResultado)))
		return -1;
	if ((Registo(base, indResultado) > -2 &&
		Registo(alternativa, indResultado) == -2) ||
		(Registo(base, indResultado) > 0 &&
			Registo(alternativa, indResultado) > Registo(base, indResultado)))
		return 1;
	// agora o tempo
	return Registo(base, indTempo) < Registo(alternativa, indTempo) ? 1 : -1;
}

void TProcura::ExecucaoTerminada(clock_t inicio)
{
	tempo = (int)(1000.0 * (clock() - inicio) / CLOCKS_PER_SEC);
	if (TempoExcedido())
		printf(" Tempo excedido.");
	else if (memoriaEsgotada)
		printf(" Memória esgotada.");
}

// MostrarSolucao: definir para visualizar a solução
void TProcura::MostrarSolucao() {
	TVector<int> solucao = CodificarSolucao();
	printf("\nSolução: ");
	for (auto& x : solucao)
		printf("%d ", x);
	printf(".");
}


int TProcura::NovoValor(const char* prompt) {
	char str[BUFFER_SIZE];
	printf("%s", prompt);
	fgets(str, BUFFER_SIZE, stdin);
	if (strlen(str) > 1)
		return atoi(str);
	return NAO_LIDO;
}

// ler uma string
char* TProcura::NovoTexto(const char* prompt) {
	static char str[BUFFER_SIZE];
	printf("%s", prompt);
	fgets(str, BUFFER_SIZE, stdin);
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
			instancia.valor = resultado;
			Dominio(instancia.valor, instancia.min, instancia.max);
		}
		else if (strlen(texto) < 256) {
			char* pt = strtok(texto, " \n\t\r");
			strcpy(ficheiroInstancia, pt);
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