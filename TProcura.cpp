#include "TProcura.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
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
TParametro TProcura::instancia = { "",1,1,1 };
// nome do ficheiro de uma instância (utilizar como prefixo, concatenando com ID da instância)
TString TProcura::ficheiroInstancia = "";
// idêntico mas para gravar a instância (terá sido gerada)
TString TProcura::ficheiroGravar = "";


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
// Gravar solução CSV (todas as ações): 0 = não grava, 1 = grava
int TProcura::gravarSolucao = 0;

// conjuntos de valores de parâmetros, para teste
TVector<TVector<int>> TProcura::configuracoes;

void TProcura::ResetParametros()
{
	// definir parametros base
	parametro = {
		{ "ALGORITMO", 1, 1, 1, "Algoritmo base a executar.", {"Algoritmo base"} },
		{ "NIVEL_DEBUG", 0, 0, 4, "Nível de debug, de reduzido a completo.",
			{ "NADA", "ATIVIDADE", "PASSOS", "DETALHE", "COMPLETO" } },
		{ "SEMENTE", 1, 1, 1000000000, "Semente aleatória para inicializar a sequência de números pseudo-aleatórios." },
		{ "LIMITE_TEMPO", 10, 1, 3600, "Limite de tempo em segundos. " },
		{ "LIMITE_ITERACOES", 0, 0, 1000000000, "Limite de número de iterações (0 não há limite). " }
	};

	// definir indicadores base
	indicador = {
		{ "Resultado", "Resultado do algoritmo, interpretado conforme o algoritmo (sucesso/insucesso, custo, qualidade, valor, etc.).", IND_RESULTADO },
		{ "Tempo(ms)", "Tempo em milissegundos da execução (medida de esforço computacional).", IND_TEMPO },
		{ "Iterações", "Iterações do algoritmo, interpretadas conforme o algoritmo (medida de esforço independente do hardware).", IND_ITERACOES }
	};
	indAtivo = { IND_RESULTADO, IND_TEMPO, IND_ITERACOES };

	// colocar as configurações vazias (podem ser inicializadas se existirem configurações por omissão)
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
void TProcura::TesteManual(TString nome)
{
	int selecao;
	TVector<TResultado> resultados;
	ResetParametros();
	Inicializar();
	LimparEstatisticas();
	while (true) {
		printf("\n%s", *nome);
		MostraParametros();
		Debug();
		MostraRelatorio(resultados, true);
		printf("\n"
			"┌─ %-2sMenu ─────────┬────────────────┬─────────────────────┬──────────────┐\n"
			"│ 1 %-2s  " COR_LEVE "Instância" COR_RESET "  │ 2 %-2s " COR_LEVE "Explorar" COR_RESET " │ 3 %-2s  " COR_LEVE "Parâmetros" COR_RESET "    │ 4 %-2s " COR_LEVE "Solução" COR_RESET " │\n"
			"│ 5 %-2s  " COR_LEVE "Indicadores" COR_RESET " │ 6 %-2s  " COR_LEVE "Executar" COR_RESET " │ 7 %-2s " COR_LEVE "Configurações" COR_RESET " │ 8 %-2s " COR_LEVE "Teste" COR_RESET "  │\n"
			"└───────────────────┴────────────────┴─────────────────────┴──────────────┘",
			Icon(EIcon::MENU), Icon(EIcon::INST), Icon(EIcon::EXP), Icon(EIcon::PARAM),
			Icon(EIcon::SOL), Icon(EIcon::IND), Icon(EIcon::EXEC), Icon(EIcon::CONF),
			Icon(EIcon::TESTE));
		if ((selecao = NovoValor("\nOpção: ")) == NAO_LIDO)
			return;
		switch (Dominio(selecao, 0, 9)) {
		case 0: return;
		case 1: SolicitaInstancia(); break;
		case 2: Explorar(); break;
		case 3: EditarParametros(); break;
		case 4: MostrarSolucao(); break;
		case 5: if (EditarIndicadores())
			resultados = {};
			  break;
		case 6:
			// executar um algoritmo
			printf("\n═╤═ %-2s Execução iniciada ═══", Icon(EIcon::EXEC));
			LimparEstatisticas();
			resultado = ExecutaAlgoritmo();
			MostraParametros(0);
			tempo = Cronometro(CONT_ALGORITMO);
			ExecucaoTerminada();
			InserirRegisto(resultados, instancia.valor, 0);
			printf("\n═╧═ %-2s Execução terminada %-2s  %s ═══",
				Icon(EIcon::FIM), Icon(EIcon::TEMPO),
				*MostraTempo(Cronometro(CONT_ALGORITMO)));
			break;
		case 7: EditarConfiguracoes(); break;
		case 8: {
			TVector<int> instancias = SolicitaInstancias();
			TesteEmpirico(instancias, NovoTexto("🗎  Ficheiro resultados (nada para mostrar no ecrã): "));
			break;
		}
		case 9: return;
		default: Mensagem(Icon(EIcon::IMP), "Opção não definida."); break;
		}
	}
}

// Idêntico ao teste empírico, mas utiliza a configuração atual e verifica se uma solução é válida para cada instância
void TProcura::TesteValidacao(TVector<int> instancias, TVector<int> impossiveis, TVector<int> referencias, TString fichSolucoes, TString fichResultados)
{
	TVector<TResultado> solucoes; // guarda soluções para valiação
	TVector<TResultado> resultados; // guarda resultados da validação para gravação
	TVector<int> atual;
	TVector<TVector<int>> instSolucoes; // para cada instância, os IDs dos resultados
	int backupID = instancia.valor;

	TesteInicio(instancias, atual);
#ifdef VPL_ATIVO
	Debug(ATIVIDADE, false, "\n<|--\n");
#endif
	instSolucoes.Count(instancias.Count());

	// ler ficheiro de soluções, formato: id; (qualquer número de parâmetros); solução
	for (auto& linha : TString().printf("%s.csv", *fichSolucoes).readLines()) {
		TVector<TString> tokens = linha.tok(";");
		int id = atoi(tokens.First());
		int indice = instancias.Find(id);
		if (linha[linha.Count() - 2] == ';')
			tokens += TString("vazio");
		if (tokens.Count() < 3 || indice < 0)
			continue;
		instSolucoes[indice] += solucoes.Count(); // registar o índice do resultado para a instância correspondente
		int tempo = atoi(tokens[tokens.Count() - 2]);
		solucoes += { id, 0, { tempo }, tokens.Last().tok()}; // registar a instância, solução e indicadores (a preencher após validação)
	}

	Debug(ATIVIDADE, false,
		"\n ├─ %-2sSoluções:%d   %-2sInstâncias: %d.",
		Icon(EIcon::SUCESSO), solucoes.Count(),
		Icon(EIcon::INST), instancias.Count()) &&
		fflush(stdout);

	// verificar cada instância, para as soluções existentes
	for (auto inst : instancias) {
		int validas = 0, invalidas = 0, melhor = RES_VAZIO, pior = RES_VAZIO, tempo = 0;
		int indice = instancias.Find(inst);
		bool impossivel = impossiveis.Find(inst) >= 0;
		if (indice >= 0)
			for (auto solucao : instSolucoes[indice]) {
				tempo += (int)solucoes[solucao].valor.First(); // acumular tempo das soluções para a instância atual
				if (impossivel) {
					// se a instância é conhecida por ser impossível, a solução tem de ser vazia e o tempo dentro do permitido
					if (solucoes[solucao].solucao.First() == TString("vazio"))
					{
						validas++;
						melhor = RES_IMPOSSIVEL;
						if (pior == RES_VAZIO)
							pior = RES_IMPOSSIVEL;
						Debug(COMPLETO, false,
							"\n ├─ %-2s:%d %-2s %-2s %-2s %-2s %d",
							Icon(EIcon::INST), inst,
							Icon(EIcon::SUCESSO),
							Icon(EIcon::VALOR), Icon(EIcon::IMP),
							Icon(EIcon::TEMPO), tempo);
					}
					else {
						// se existe solução para uma instância impossível, é inválida
						invalidas++;
						if (melhor == RES_VAZIO)
							melhor = RES_INVALIDO;
						pior = RES_INVALIDO;
						Debug(COMPLETO, false,
							"\n ├─ %-2s:%d %-2s %-2s %d",
							Icon(EIcon::INST), inst,
							Icon(EIcon::INSUC),
							Icon(EIcon::TEMPO), tempo);
						for (auto& token : solucoes[solucao].solucao)
							Debug(COMPLETO, false, " %s", *token);
					}
				}
				else {
					// validar solução para a instância atual, e calcular indicadores
					// gravar o ID da instância atual
					instancia.valor = inst;
					Inicializar();
					LimparEstatisticas();
					// validar a solução para a instância atual
					if (Validar(solucoes[solucao].solucao)) {
						validas++;
						int resultado = (int)Indicador(IND_RESULTADO);
						if (resultado >= 0) {
							if (melhor == RES_VAZIO || melhor > resultado)
								melhor = resultado;
							if (pior == RES_VAZIO || (pior >= 0 && pior < resultado))
								pior = resultado;
						}
						Debug(COMPLETO, false,
							"\n ├─ %-2s:%d %-2s %-2s %d %-2s %d",
							Icon(EIcon::INST), inst,
							Icon(EIcon::SUCESSO),
							Icon(EIcon::VALOR), resultado,
							Icon(EIcon::TEMPO), tempo);
					}
					else {
						invalidas++;
						if (melhor == RES_VAZIO)
							melhor = RES_INVALIDO;
						pior = RES_INVALIDO;
						Debug(COMPLETO, false,
							"\n ├─ %-2s:%d %-2s %-2s %d",
							Icon(EIcon::INST), inst,
							Icon(EIcon::INSUC),
							Icon(EIcon::TEMPO), tempo);
					}
				}
			}
		if (validas + invalidas == 0) {
			// se não existem soluções para a instância, considerar como não resolvida
			invalidas++;
			melhor = pior = RES_INVALIDO;
		}
		// registar a instância e resultados (válidas, inválidas, melhor e pior valores), e tempo para gravação 
		resultados += { inst, 0, { validas, invalidas, melhor, pior, tempo }, { }};
	}

	if (Parametro(NIVEL_DEBUG) >= ATIVIDADE)
		RelatorioValidacao(resultados, referencias);

	// gravar resultados, um por instância
	RelatorioCSV(resultados, fichResultados, false);

	// repor a instância atual
	instancia.valor = backupID;
	Inicializar();
#ifdef VPL_ATIVO
	Debug(ATIVIDADE, false, "\n--|>\n");
#endif
	TesteFim();

}

void TProcura::RelatorioValidacao(TVector<TResultado> resultados, TVector<int> referencias) {
	int validas = 0, melhorCusto = 0, piorCusto = 0, tempoTotal = 0;
	double taxaEficacia = 0, taxaQualidade = 0, taxaEficiencia = 0, desempenho = 0;
	bool considerarQualidade = (referencias[1] > referencias[0]); // custoMin < custoMax (se iguais, o custo não é considerado para o indicador global)
	for (auto& res : resultados) {
		// instância válida apenas se todas as soluções para a instância forem válidas
		if (res.valor[0] > 0 && res.valor[1] == 0) {
			validas++;
			if (res.valor[2] >= 0)
				melhorCusto += (int)res.valor[2];
			if (res.valor[3] >= 0)
				piorCusto += (int)res.valor[3];
			tempoTotal += (int)res.valor[4];
		}
		// não resolvidas se existirem resultados inválidos
		if (res.valor[1] > 0) {
			// custo máximo por instância
			piorCusto += referencias[1] / resultados.Count();
			// tempo máximo por instância
			tempoTotal += referencias[3] / resultados.Count();
		}
	}
	Debug(ATIVIDADE, false,
		"\n ├─ %-2sVálidas:%d   %-2sInstâncias: %d.",
		Icon(EIcon::SUCESSO), validas,
		Icon(EIcon::INST), resultados.Count()) &&
		fflush(stdout);
	Debug(ATIVIDADE, false,
		"\n ├─ %-2sMelhor:%d   %-2sPior: %d.",
		Icon(EIcon::VALOR), melhorCusto,
		Icon(EIcon::VALOR), piorCusto) &&
		fflush(stdout);
	Debug(ATIVIDADE, false,
		"\n ├─ %-2sTempo(ms):%d.",
		Icon(EIcon::TEMPO), tempoTotal) &&
		fflush(stdout);

	// indicador de desempenho global:
	// - taxaEficacia * taxaQualidade * taxaEficiencia (todos entre 0 e 1)
	// - resultado final na escala entre 0 e 100 pontos.
	// eficácia: percentagem de instâncias resolvidas
	taxaEficacia = 100.0 * validas / resultados.Count();
	// qualidade: (custoMax - custoTotal) / (custoMax - custoMin)
	if (considerarQualidade)
		taxaQualidade = 100.0 * (referencias[1] - piorCusto) / (referencias[1] - referencias[0]);
	// eficiência: (tempoMax - tempoTotal) / (tempoMax - tempoMin)
	taxaEficiencia = 100.0 * (referencias[3] - tempoTotal) / (referencias[3] - referencias[2]);
	// ajuste de limites
	if (considerarQualidade)
		taxaQualidade = (taxaQualidade > 100 ? 100 : (taxaQualidade < 0 ? 0 : taxaQualidade));
	taxaEficiencia = (taxaEficiencia > 100 ? 100 : (taxaEficiencia < 0 ? 0 : taxaEficiencia));
	// calculo do indicador global
	desempenho = (taxaEficacia + taxaQualidade + taxaEficiencia) / (considerarQualidade ? 3 : 2);
	if (considerarQualidade)
		Debug(ATIVIDADE, false,
			"\n ├─ %-2s %.1f%% (%-2s %.1f%% %-2s %.1f%% %-2s %.1f%%)",
			Icon(EIcon::IND), desempenho,
			Icon(EIcon::SUCESSO), taxaEficacia,
			Icon(EIcon::VALOR), taxaQualidade,
			Icon(EIcon::TEMPO), taxaEficiencia);
	else
		Debug(ATIVIDADE, false,
			"\n ├─ %-2s %.1f%% (%-2s %.1f%% %-2s %.1f%%)",
			Icon(EIcon::IND), desempenho,
			Icon(EIcon::SUCESSO), taxaEficacia,
			Icon(EIcon::TEMPO), taxaEficiencia);
	fflush(stdout);

#ifdef VPL_ATIVO
	// nota no VPL
	Debug(ATIVIDADE, false, "\n--|>\nGrade :=>> %d\n<|--\n", (int)(desempenho + 0.5));
#endif
}


void TProcura::MostraCaixa(TVector<TString> titulo, ECaixaParte parte, TVector<int> largura, bool aberta, int identacao) {
	for (int i = 0; i < titulo.Count(); i++) {
		unsigned int len = (unsigned int)(
			parte == ECaixaParte::Fundo ?
			largura[i] :
			largura[i] - compat::ContaUTF8(titulo[i]) - (parte == ECaixaParte::Meio ? 1 : 4));

		if (len > 100)
			len = 0;

		switch (parte) {
		case ECaixaParte::Topo:

			if (i == 0) {
				if (!titulo[i].Empty())
					printf("\n%*s┌─ %s ─", identacao, "", *titulo[i]);
				else
					printf("\n%*s┌────", identacao, "");
				break;
			}
			if (!titulo[i].Empty())
				printf("┬─ %s ─", *titulo[i]);
			else
				printf("┬────");
			break;
		case ECaixaParte::Separador:
			if (i == 0) {
				if (!titulo[i].Empty())
					printf("\n%*s├─ %s ─", identacao, "", *titulo[i]);
				else
					printf("\n%*s├────", identacao, "");
				break;
			}
			if (!titulo[i].Empty())
				printf("┼─ %s ─", *titulo[i]);
			else
				printf("┼────");
			break;
		case ECaixaParte::Meio:
			if (i == 0) { printf("\n%*s│ %s", identacao, "", *titulo[i]); break; }
			printf("│ %s", *titulo[i]); break;
		case ECaixaParte::Fundo:
			if (i == 0) { printf("\n%*s└", identacao, ""); break; }
			printf("┴"); break;
		}

		// mostrar a barra com len de comprimento
		while (len-- > 0)
			printf(parte == ECaixaParte::Meio ? " " : "─");

	}

	if (!aberta)
		switch (parte) {
		case ECaixaParte::Topo: printf("┐"); break;
		case ECaixaParte::Separador: printf("┤"); break;
		case ECaixaParte::Meio: printf("│"); break;
		case ECaixaParte::Fundo: printf("┘"); break;
		}
}


void TProcura::MostraCaixa(TString titulo, ECaixaParte parte, int largura,
	bool aberta, int identacao, const char* icon)
{
	// início da caixa ou linha de separação ou fim da caixa
	bool novaLinha = true;
	if (identacao < 0) {
		novaLinha = false;
		identacao = -identacao - 1;
	}
	unsigned int len = (unsigned int)(
		parte == ECaixaParte::Fundo ?
		largura - (titulo.Empty() ? 0 : compat::ContaUTF8(titulo) - 4) :
		largura - compat::ContaUTF8(titulo) - (parte == ECaixaParte::Meio ? 1 : 4));

	if (icon[0] != 0)
		len -= 3;

	if (len > 100)
		len = 0;

	if (novaLinha)
		printf("\n");
	switch (parte) {
	case ECaixaParte::Topo:
		if (icon[0] != 0)
			printf("%*s┌─ %-2s%s ─", identacao, "", icon, *titulo);
		else
			printf("%*s┌─ %s ─", identacao, "", *titulo);
		break;
	case ECaixaParte::Separador:
		if (icon[0] != 0)
			printf("%*s├─ %-2s%s ─", identacao, "", icon, *titulo);
		else
			printf("%*s├─ %s ─", identacao, "", *titulo);
		break;
	case ECaixaParte::Meio:
		if (icon[0] != 0)
			printf("%*s│ %-2s%s", identacao, "", icon, *titulo);
		else
			printf("%*s│ %s", identacao, "", *titulo);
		break;
	case ECaixaParte::Fundo:
		printf("%*s└", identacao, "");
		if (!titulo.Empty()) { // texto a ser inserido no fundo
			if (icon[0] != 0)
				printf("─ %-2s%s ─", icon, *titulo);
			else
				printf("─ %s ─", *titulo);
		}
		break;
	}

	// mostrar a barra com len de comprimento
	while (len-- > 0)
		printf(parte == ECaixaParte::Meio ? " " : "─");

	if (!aberta)
		switch (parte) {
		case ECaixaParte::Topo: printf("┐"); break;
		case ECaixaParte::Separador: printf("┤"); break;
		case ECaixaParte::Meio: printf("│"); break;
		case ECaixaParte::Fundo: printf("┘"); break;
		}
}

void TProcura::MostraCaixa(TVector<TString> textos, int largura, bool aberta, int identacao) {
	MostraCaixa(textos.First(), ECaixaParte::Topo, largura, aberta, identacao);
	for (int i = 1; i < textos.Count(); i++)
		MostraCaixa(textos[i], ECaixaParte::Meio, largura, aberta, identacao);
	MostraCaixa("", ECaixaParte::Fundo, largura, aberta, identacao);
}

void TProcura::Mensagem(TString titulo, const char* fmt, ...) {
	if (titulo.Empty())
		titulo = "⚠️";

	va_list args;
	va_start(args, fmt);
	va_list args_copy;
	va_copy(args_copy, args);

	int64_t len = vsnprintf(nullptr, 0, fmt, args_copy);
	va_end(args_copy);

	TVector<char> texto((int)len + 1);
	if (texto.Data()) {
		vsnprintf(texto.Data(), len + 1, fmt, args);
		len = compat::ContaUTF8(texto.Data()) + 2;
		TVector<TString> textos = { titulo, texto.Data() };
		MostraCaixa(textos, len < 20 ? 20 : (int)len);
	}
	va_end(args);
}

/// @brief Muda a cor (fundo/letra) com HSL (h=0 a 360 saturação, luminosidade)
void TProcura::DebugHSL(float h, float s, float l, bool fundo) {
	if (h < 0 || h > 360) { // reset de cores
		printf("%s", COR_RESET);
	}
	else {
		float f = (2 * l - 1);
		float c = (1 - (f < 0 ? -f : f)) * s;

		float h60 = h / 60.0f;
		float hmod2 = h60 - 2 * int(h60 / 2);
		float x = c * (1 - ((hmod2 - 1) < 0 ? -(hmod2 - 1) : (hmod2 - 1)));
		float m = l - c / 2;

		float r, g, b;
		if (h < 60) { r = c; g = x; b = 0; }
		else if (h < 120) { r = x; g = c; b = 0; }
		else if (h < 180) { r = 0; g = c; b = x; }
		else if (h < 240) { r = 0; g = x; b = c; }
		else if (h < 300) { r = x; g = 0; b = c; }
		else { r = c; g = 0; b = x; }

		printf("\x1b[%d;2;%d;%d;%dm", (fundo ? 48 : 38),
			(int)((r + m) * 255), (int)((g + m) * 255), (int)((b + m) * 255));
	}
}



void TProcura::MostraParametros(int detalhe, TVector<int>* idParametros, TString titulo) {
	int nElementos = (idParametros == NULL ? parametro.Count() : idParametros->Count());
	int col = 2;
	bool parBin = false;
	if (titulo.Empty())
		titulo = "Parâmetros";
	// detalhe 0 é só uma linha (separador)
	if (detalhe) {
		MostraCaixa(titulo, ECaixaParte::Topo, 70, true, 0, Icon(EIcon::PARAM));
		MostraCaixa("", ECaixaParte::Meio, 1);
	}
	else {
		MostraCaixa(titulo, ECaixaParte::Separador, 1, true, 1);
		printf(" ");
	}
	col = 3;

	for (int i = 0; i < nElementos; i++) {
		int parID = (idParametros == NULL ? i : (*idParametros)[i]);
		if (!ParametroAtivo(parID))
			continue;
		// caso o parâmetro seja 0/1 mostrar o valor em cor 0=vermelho 1=verde
		if ((parBin = (parametro[parID].min == 0 && parametro[parID].max == 1)) == true) {
			// identificação do parâmetro e valor com cor 
			if (detalhe == 0 || parametro[parID].nome.Empty() ||
				(detalhe == 1 && !parametro[parID].dependencia.Empty()))
				col += printf("%sP%d%s%s" COR_RESET,
					(const char*)(Parametro(parID) == 1 ? COR_ATIVO_LEVE : COR_INATIVO_LEVE),
					parID + 1,
					(const char*)(Parametro(parID) == 1 ? COR_ATIVO : COR_INATIVO),
					Icon(Parametro(parID) == 1 ? EIcon::SEL : EIcon::NSEL)) - COR_LEVE_TAM;
			else {
				if (detalhe == 2 && !parametro[parID].dependencia.Empty())
					col += printf("  ");
				col += printf("%sP%d(%s)%s%s" COR_RESET,
					(const char*)(Parametro(parID) == 1 ? COR_ATIVO_LEVE : COR_INATIVO_LEVE),
					parID + 1, *parametro[parID].nome,
					(const char*)(Parametro(parID) == 1 ? COR_ATIVO : COR_INATIVO),
					Icon(Parametro(parID) == 1 ? EIcon::SEL : EIcon::NSEL)) - COR_LEVE_TAM;
			}
		}
		else {
			// identificação do parâmetro
			if (detalhe == 0 || parametro[parID].nome.Empty() ||
				(detalhe == 1 && !parametro[parID].dependencia.Empty()))
				col += printf(COR_LEVE "P%d=" COR_RESET, parID + 1) - COR_LEVE_TAM;
			else {
				if (detalhe == 2 && !parametro[parID].dependencia.Empty())
					col += printf("  ");
				col += printf(COR_LEVE "P%d(%s):" COR_RESET " ", parID + 1, *parametro[parID].nome) - COR_LEVE_TAM;
			}
			// valor do parâmetro
			if (detalhe > 1 && col < 30)
				col += printf("%*s", (30 - col), "");
			if (detalhe == 0 || parametro[parID].nomeValores.Empty() ||
				(detalhe == 1 && !parametro[parID].dependencia.Empty()))
				col += printf("%d", Parametro(parID));
			else
				col += printf("%s", *parametro[parID].nomeValores[Parametro(parID) - parametro[parID].min]);
		}

		// mostrar intervalo permitido
		if (detalhe > 1) {
			if (col < 40)
				col += printf("%*s", (40 - col), "");
			col += printf(" " COR_LEVE "(%d a %d)" COR_RESET, parametro[parID].min, parametro[parID].max) - COR_LEVE_TAM;
		}
		if (detalhe == 2 && !parametro[parID].dependencia.Empty()) {
			// mostrar variável dependente
			int dependente = parametro[parID].dependencia.First();
			col += printf(COR_LEVE " [P%d(%s)]" COR_RESET " ", dependente + 1, *parametro[dependente].nome) - COR_LEVE_TAM;
		}
		// separador/mudança de linha
		if (i < nElementos - 1) {
			if (detalhe > 1 || col > 70) { // limite de largura
				if (detalhe == 0) {
					MostraCaixa(" ", ECaixaParte::Separador, 1, true, 1, Icon(EIcon::PARAM));
					printf(" ");
				}
				else
					MostraCaixa("", ECaixaParte::Meio, 1);
				col = 3;
			}
			else if (detalhe > 0)
				col += printf(" | ");
			else
				col += printf(" ");
		}
	}
	if (detalhe)
		MostraCaixa("", ECaixaParte::Fundo, 70);
}

bool TProcura::EditarIndicadores() {
	int opcao = 0;
	bool editado = false;
	while (true) {
		MostraIndicadores();
		do {
			if (opcao < 0) {
				opcao = -opcao;
				opcao = Dominio(opcao, 1, indicador.Count());
				printf(COR_LEVE "I%d(%s):" COR_RESET " %d", opcao, *indicador[opcao - 1].nome, (int)Indicador(opcao - 1));
			}
			if ((opcao = NovoValor("\nIndicador (positivo ativa/desativa; negativo calcula): ")) == NAO_LIDO || opcao == 0)
				return editado;
		} while(opcao < 0);
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
		if ((opcao = NovoValor("\nParâmetro:")) == NAO_LIDO || opcao == 0)
			return;
		opcao = Dominio(opcao, 1, parametro.Count());
		if (!ParametroAtivo(opcao - 1)) {
			printf("\nParâmetro inativo.");
			continue;
		}
		// iniciar caixa com nome do parametro
		MostraCaixa(
			TString().printf("%-2s P%d(%s)", Icon(EIcon::PARAM), opcao, *parametro[opcao - 1].nome),
			ECaixaParte::Topo);
		// mostrar descrição se existir
		if (!parametro[opcao - 1].descricao.Empty())
			MostraCaixa(parametro[opcao - 1].descricao, ECaixaParte::Meio);
		// mostrar textos dos valores possíveis, caso existam
		if (!parametro[opcao - 1].nomeValores.Empty())
			for (int i = parametro[opcao - 1].min; i <= parametro[opcao - 1].max; i++) {
				MostraCaixa("", ECaixaParte::Meio, 1);
				printf(COR_LEVE "%d:" COR_RESET " %s", i,
					*parametro[opcao - 1].nomeValores[i - parametro[opcao - 1].min]);
			}
		else {
			// mostrar intervalo possível
			MostraCaixa("", ECaixaParte::Meio, 1);
			printf("Intervalo: %d a %d",
				parametro[opcao - 1].min,
				parametro[opcao - 1].max);
		}
		MostraCaixa("", ECaixaParte::Fundo);

		// valor atual
		if (!parametro[opcao - 1].nome.Empty())
			printf("\n%s (atual %d): ", *parametro[opcao - 1].nome, Parametro(opcao - 1));
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

TString TProcura::MostraTempo(double segundos)
{
	static const int64_t segundo = 1000;
	static const int64_t minuto = 60 * segundo;
	static const int64_t hora = 60 * minuto;
	static const int64_t dia = 24 * hora;
	static const int64_t semana = 7 * dia;
	static const int64_t mes = 30 * dia;
	static const int64_t ano = 365 * dia;
	static TVector<int64_t> unidades = { ano, mes, semana, dia, hora, minuto, segundo };
	static TVector<char> unidadesStr = { 'a', 'm', 's', 'd', 'h', '\'', '"' };
	TString str;

	int64_t ms = (int64_t)(1000 * segundos + 0.5);

	for (int i = 0; i < unidades.Count(); i++)
		if (ms >= unidades[i]) {
			str.printf("%" PRId64 "%c ", ms / unidades[i], unidadesStr[i]);
			ms %= unidades[i];
		}
	if (ms > 0)
		str.printf("%" PRId64 "ms ", ms);

	return str;
}

void TProcura::InserirRegisto(TVector<TResultado>& resultados, int inst, int conf)
{
	resultados += { inst, conf };
	for (auto ind : indAtivo)
		Registo(resultados.Last(), ind, Indicador(ind));
	// adicionar no final a solução codificada em inteiros
	resultados.Last().valor += CodificarSolucao();
	resultados.Last().solucao = Solucao();
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
	TString str;
	TVector<TString> textos = { "📖 Sintaxe comando"," " COR_LEVE "Instâncias:" COR_RESET " A,B,C | A:B | A : B : C" };

	MostraCaixa(textos, 40);

	printf("\n%-2s IDs das instâncias (%d a %d): ", Icon(EIcon::INST), instancia.min, instancia.max);

	str = NovoTexto("");
	if (!str.Empty())
		return _TV(str);
	// colocar apenas a instância atual
	return TVector<int>() += instancia.valor;
}

void TProcura::EditarConfiguracoes() {
	TVector<int> atual; // parâmetros atuais
	int id = -1, auxID;
	TString str;

	ConfiguracaoAtual(atual, LER);

	id = NovaConfiguracao(atual);

	do {
		TVector<TString> textos = {
			"📖 Sintaxe comando",
			"   id / -id " COR_LEVE "- Seleciona configuração como atual ou apaga 'id'" COR_RESET,
			"   Pk = <conj.> " COR_LEVE "- Varia Pk na configuração atual (gera N configs)" COR_RESET,
			"   Pk = <conj.> x Pw = <conj.> " COR_LEVE "- produto externo (gera NxM configs)" COR_RESET,
			" " COR_LEVE "Sintaxe de <conj.> :" COR_RESET " A,B,C | A:B | A:B:C"
		};
		MostrarConfiguracoes(0, id);

		MostraCaixa(textos, 70);

		if ((str = NovoTexto("\n✏️ Comando: ")).Empty())
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

void TProcura::InserirConfiguracoes(TString str, TVector<int>& base) {
	TVector<int> produto;
	TVector<TVector<int>> valores;
	auto tokens = str.tok();

	// processar todos os itens a iniciar em P, obtendo informação entre quais existe x
	for (auto& token : tokens) {
		if (token[0] == 'P') {
			int param;
			auto par = token.tok("="); // obter o token do parâmetro e o token dos valores
			if (par.Count() == 2) {
				param = atoi(*par.First() + 1);
				if (param > 0 && param <= parametro.Count()) {
					valores.Count(valores.Count() + 1);
					valores.Last() = {};
					valores.Last() += param; // primeiro valor é ID do parâmetro
					valores.Last() += _TV(par.Last()); // valores para o parâmetro tomar
					if (valores.Last().Count() == 2) {
						// apenas um elemento, altera a configuração atual 
						// (se fosse para alternar, colocava o valor base mais o valor a alternar)
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
		else if (token[0] == 'x') {
			valores.Count(valores.Count() + 1);
			valores.Last() += 0; // produto externo
		}
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
	MostraParametros(detalhe, &comum, Icon(EIcon::CONF));
	printf(COR_LEVE " (parâmetros comuns)" COR_RESET);

	if (configuracoes.Count() > 1) {
		// visualizar configurações atuais, assinalando a atualmente escolhida
		printf("\n═╪═ Configurações ═══");
		for (int i = 0; i < configuracoes.Count(); i++) {
			TString str;
			str.printf("%-2s [%d]", Icon(EIcon::PARAM), i + 1);
			ConfiguracaoAtual(configuracoes[i], GRAVAR);
			MostraParametros(detalhe, &distinto, str);
			if (i == atual)
				printf(" ⭐ atual");
			if (atual < 0 && i == 2 && configuracoes.Count() > 10) {
				printf("\n │ ...");
				i = configuracoes.Count() - 4;
			}
		}
	}
	printf("\n═╧═══════════════════");
}

void TProcura::MostraConjunto(TVector<int> valores, const char* etiqueta) {
	printf(" { ");
	if (valores.Count() <= 10) {
		for (auto ind : valores)
			printf("%-2s%d ", etiqueta, ind);
	}
	else {
		for (int i = 0; i <= 2; i++)
			printf("%-2s%d ", etiqueta, valores[i]);
		printf("… ");
		for (int i = valores.Count() - 3; i < valores.Count(); i++)
			printf("%-2s%d ", etiqueta, valores[i]);
	}
	printf("} ");
	if (valores.Count() > 10)
		printf("#%d", valores.Count());
}

void TProcura::TesteInicio(TVector<int>& instancias, TVector<int>& configAtual) {
	ConfiguracaoAtual(configAtual, LER);
	if (configuracoes.Empty()) {
		// não foram feitas configurações, utilizar a atual
		configuracoes.Count(1);
		configuracoes.Last() = configAtual;
	}
	for (auto item : instancias)
		if (item<instancia.min || item>instancia.max)
			item = -1;
	instancias -= (-1);
	if (mpiID == 0) {
		printf("\n\n═╤═ Instâncias ═══");
		MostraConjunto(instancias, Icon(EIcon::INST));
		MostrarConfiguracoes(0);
	}
	if (mpiCount < 10 || mpiID == 0)
		printf("\n═╤═ %-2s Início do Teste (%-2s%d) ═══",
			Icon(EIcon::TESTE), Icon(EIcon::PROCESSO), mpiID);
	fflush(stdout);
	Cronometro(CONT_TESTE, true); // reiniciar cronómetro global
}

void TProcura::TesteFim() {
	if (mpiCount < 10 || mpiID == 0)
		printf("\n═╧═ %-2s Fim do Teste (%-2s%d  %-2s%s) ═══",
			Icon(EIcon::FIM), Icon(EIcon::PROCESSO), mpiID, Icon(EIcon::TEMPO),
			*MostraTempo(Cronometro(CONT_TESTE)));
	fflush(stdout);
}


// utilizar para executar testes empíricos, utilizando todas as instâncias,
// com o último algoritmo executado e configurações existentes
void TProcura::TesteEmpirico(TVector<int> instancias, TString ficheiro) {
	TVector<TResultado> resultados; // guarda as soluções obtidas
	TVector<int> atual;
	int backupID = instancia.valor;
	int nTarefa = 0;
	double periodoReporte = 60;

	TesteInicio(instancias, atual);

	switch (Parametro(NIVEL_DEBUG)) {
	case DETALHE: periodoReporte = 10; break;
	case COMPLETO: periodoReporte = 0; break; // reporte em todos os eventos
	}
	Cronometro(CONT_REPORTE, true); // reiniciar cronómetro evento
	if (mpiID == 0)
		Debug(ATIVIDADE, false,
			"\n ├─ %-2sTarefas:%d   %-2sInstâncias: %d   %-2sConfigurações: %d   %-2sProcessos: %d.",
			Icon(EIcon::TAREFA), instancias.Count() * configuracoes.Count(),
			Icon(EIcon::INST), instancias.Count(),
			Icon(EIcon::CONF), configuracoes.Count(),
			Icon(EIcon::PROCESSO), mpiCount) &&
		fflush(stdout);
	// percorrer todas as instâncias
	for (int configuracao = 0; configuracao < configuracoes.Count(); configuracao++) {
		ConfiguracaoAtual(configuracoes[configuracao], GRAVAR);

		for (auto inst : instancias) {
			// distribuir tarefas por MPI
			if ((nTarefa++) % mpiCount != mpiID)
				continue;

			if (Parametro(NIVEL_DEBUG) > NADA && mpiID == 0 && Cronometro(CONT_REPORTE) > periodoReporte) {
				Debug(ATIVIDADE, false,
					"\n ├─ %-2s%-15s %-2s%-5d %-2s%-5d %-2s%-5d %-2s%-5d",
					Icon(EIcon::TEMPO), *MostraTempo(Cronometro(CONT_TESTE)),
					Icon(EIcon::TAREFA), nTarefa,
					Icon(EIcon::INST), inst,
					Icon(EIcon::CONF), configuracao + 1,
					Icon(EIcon::PROCESSO), mpiCount) &&
					fflush(stdout);
				Cronometro(CONT_REPORTE, true);
			}
			ExecutaTarefa(resultados, inst, configuracao);
		}
	}

	if (ficheiro.Empty())
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

		if (mpiCount > 1 && modoMPI == 0)
			// tenta juntar ficheiros, caso existam os ficheiros dos outros processos
			JuntarCSV(ficheiro);
		if (mpiID == 0)
			Debug(ATIVIDADE, false,
				"\n ├─ %-2s Ficheiro %s.csv gravado.\n"
				" │  %-2s Tempo real: %s",
				Icon(EIcon::RESULT), *ficheiro,
				Icon(EIcon::TEMPO), *MostraTempo(Cronometro(CONT_TESTE))) &&
			Debug(ATIVIDADE, false, "\n │  %-2s CPU total: %s",
				Icon(EIcon::TEMPO), *MostraTempo(Cronometro(CONT_TESTE) * mpiCount)) &&
			Debug(ATIVIDADE, false, "\n │  %-2s Utilização: %.1f%%",
				Icon(EIcon::TAXA), 100. * tempoTotal / (tempoMaximo * mpiCount));
	}

	ConfiguracaoAtual(atual, GRAVAR);
	instancia.valor = backupID;
	Inicializar();
	TesteFim();
}

void TProcura::TesteEmpiricoGestor(TVector<int> instancias, TString ficheiro)
{
#ifdef MPI_ATIVO
	int dados[3] = { 0, 0, 0 }; // instância, configuração
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

	TVector<TResultado> resultados; // guarda as soluções obtidas
	TVector<TResultado> tarefas; // guarda informação apenas das tarefas a realizar (sem resultados)
	Cronometro(CONT_REPORTE, true); // reiniciar cronómetro evento

	// construir todas as tarefas
	for (int configuracao = 0; configuracao < configuracoes.Count(); configuracao++)
		for (auto inst : instancias)
			tarefas += { inst, configuracao };

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

		if (Parametro(NIVEL_DEBUG) > NADA && Cronometro(CONT_REPORTE) > periodoReporte) {
			// mostrar uma linha por cada execução
			Debug(ATIVIDADE, false,
				"\n ├─ %-2s%-15s %-2s%-5d %-2s%-5d %-2s%-5d %-2s%-5d %-2s ",
				Icon(EIcon::TEMPO), *MostraTempo(Cronometro(CONT_TESTE)),
				Icon(EIcon::TAREFA), totalTarefas - tarefas.Count(),
				Icon(EIcon::INST), resultados.Last().instancia,
				Icon(EIcon::CONF), resultados.Last().configuracao,
				Icon(EIcon::PROCESSO), trabalhador.Last(),
				Icon(EIcon::IND));
			for (auto ind : resultados.Last().valor)
				printf("%" PRId64 " ", ind);
			fflush(stdout);
			Cronometro(CONT_REPORTE, true);
		}

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
			"\n ├─ %-2s Ficheiro %s.csv gravado.\n"
			" │  %-2s Tempo real: %s",
			Icon(EIcon::RESULT), *ficheiro,
			Icon(EIcon::TEMPO), *MostraTempo(Cronometro(CONT_TESTE))) &&
		Debug(ATIVIDADE, false, "\n │  %-2s CPU total: %s",
			Icon(EIcon::TEMPO), *MostraTempo(Cronometro(CONT_TESTE) * (backupCount - 1))) &&
		Debug(ATIVIDADE, false, "\n │  %-2s Espera do gestor: %s",
			Icon(EIcon::TEMPO), *MostraTempo(esperaGestor)) &&
		Debug(ATIVIDADE, false, "\n │  %-2s Espera trabalhadores: %s",
			Icon(EIcon::TEMPO), *MostraTempo(esperaTrabalhadores)) &&
		Debug(ATIVIDADE, false, "\n │  %-2s Utilização:\n │  - Total: %.1f%%\n │  - Gestor: %.1f%%\n │  - Trabalhadores: %.1f%% ",
			Icon(EIcon::TAXA), taxaUtilizacao * 100, taxaUtilizacaoG * 100, taxaUtilizacaoT * 100);
	mpiCount = backupCount;

	TesteFim();
#endif
}

void TProcura::TesteEmpiricoTrabalhador(TVector<int> instancias, TString ficheiro)
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

	TesteInicio(instancias, atual);

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

	TesteFim();
#endif
}

void TProcura::ExecutaTarefa(TVector<TResultado>& resultados, int inst, int conf)
{
	// carregar a configuração
	ConfiguracaoAtual(configuracoes[conf], GRAVAR);
	instancia.valor = inst;
	// carregar instância
	Inicializar();
	// executar um algoritmo 
	LimparEstatisticas();
	{
		ENivelDebug backupDebug = (ENivelDebug)Parametro(NIVEL_DEBUG);
		Parametro(NIVEL_DEBUG) = NADA; // remover informação de debug do algoritmo, já que é um teste empírico
		if (!ficheiroGravar.Empty()) {
			Gravar();
			resultado = RES_VAZIO;
		}
		else
			resultado = ExecutaAlgoritmo();
		Parametro(NIVEL_DEBUG) = backupDebug;
	}
	tempo = Cronometro(CONT_ALGORITMO);
	InserirRegisto(resultados, instancia.valor, conf);


	if (resultado >= 0) {
		mpiID == 0 && Debug(COMPLETO, false, "%-2s%-5d", Icon(EIcon::SUCESSO), resultado);
	}
	else {
		if (Parar())
			mpiID == 0 && Debug(COMPLETO, false, "%-2s", Icon(EIcon::INSUC));
		if (TempoExcedido())
			mpiID == 0 && Debug(COMPLETO, false, "%-2s", Icon(EIcon::TEMPO));
		if (memoriaEsgotada)
			mpiID == 0 && Debug(COMPLETO, false, "%-2s", Icon(EIcon::MEMORIA));
		if (resultado < 0 && !Parar()) { //Instância Impossível! (se algoritmo completo) ");
			mpiID == 0 && Debug(COMPLETO, false, "%-2s%-2s", Icon(EIcon::SUCESSO), Icon(EIcon::IMP));
			resultados.Last().solucao = "vazio";
		}
		else // não resolvido, cancelar resultados 
			resultados.Last().valor.First() = RES_NAO_RESOLVIDO;
	}
	if (mpiID == 0 && Parametro(NIVEL_DEBUG) >= COMPLETO) {
		printf("%-2s ", Icon(EIcon::IND));
		for (auto ind : resultados.Last().valor)
			printf("%" PRId64 " ", ind);
	}
}

// processa os argumentos da função main
void TProcura::main(int argc, char* argv[], TString nome) {
	TVector<int> instancias, impossiveis;
	TString fichResultados, fichSolucoes;
	TString argParametros;
	bool configIntroduzido = false; // caso sejam dadas configurações, remover as existentes
	TVector<int> referencias = { 0,100,0,100000 }; // custoMin, custoMax, tempoMin, tempoMax

	compat::init_io();

	if (argc <= 1) {
		TesteManual(*nome);
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

	fichResultados = "resultados";

	ResetParametros();

	// opcionais:
	// -R resultados --- ficheiro de resultados em CSV (adicionada extensão .csv)
	// -S solucoes [custoMin custoMax tempoMin tempoMax [<ids>]] --- ficheiro de solucoes em CSV
	// -F instancia_ --- prefixo dos ficheiros de instâncias
	// -I 2,1,3 --- indicadores selecionados por ordem 
	// -P P1=1:3 x P2=0:2 --- formatação de parâmetros (idêntico ao interativo)
	for (int i = 2; i < argc; i++) {
		if (strcmp(argv[i], "-R") == 0 && i + 1 < argc) {
			(fichResultados = "").printf("%s", argv[++i]);
		}
		else if (strcmp(argv[i], "-S") == 0 && i + 1 < argc) {
			(fichSolucoes = "").printf("%s", argv[++i]);
			// carregar as 4 referências, caso existam
			if (i + 1 < argc && isdigit(argv[i + 1][0])) {
				referencias = {};
				for (auto& token : TString(argv[++i]).tok(","))
					referencias += atoi(token);
				if (referencias.Count() != 4) // usar valores por omissão se não forem dadas as 4 referências
					referencias = { 0,100,0,100000 };
			}
			// e os ids de instâncias impossíveis, caso existam
			if (i + 1 < argc && isdigit(argv[i + 1][0]))
				impossiveis = argv[++i];
		}
		else if (strcmp(argv[i], "-F") == 0 && i + 1 < argc) {
			(ficheiroInstancia = "").printf("%s", argv[++i]);
		}
		else if (strcmp(argv[i], "-FG") == 0 && i + 1 < argc) {
			(ficheiroGravar = "").printf("%s", argv[++i]);
		}
		else if (strcmp(argv[i], "-M") == 0 && i + 1 < argc) {
			if ((modoMPI = atoi(argv[i + 1])) != 1)
				modoMPI = 0; // apenas 0 ou 1
		}
		else if (strcmp(argv[i], "-G") == 0 && i + 1 < argc) {
			if ((gravarSolucao = atoi(argv[i + 1])) != 1)
				gravarSolucao = 0; // apenas 0 ou 1
		}
		else if (strcmp(argv[i], "-I") == 0 && i + 1 < argc) {
			indAtivo = {};
			for (auto& token : TString(argv[i + 1]).tok(",")) {
				indAtivo += (atoi(token) - 1);
				indicador[indAtivo.Last()].indice = indAtivo.Count() - 1;
			}
		}
		else if (strcmp(argv[i], "-P") == 0 && i + 1 < argc) {
			TVector<int> base;
			if (!configIntroduzido) { // limpa configurações anteriores ou por omissão
				configIntroduzido = true;
				configuracoes = {};
			}
			// o resto é para concatenar e enviar, até outro "-P" ou fim
			argParametros = "";
			while (++i < argc && strcmp(argv[i], "-P") != 0)
				argParametros.printf(" %s", argv[i]);
			ConfiguracaoAtual(base, LER);
			InserirConfiguracoes(argParametros, base);
			ConfiguracaoAtual(base, GRAVAR);
			NovaConfiguracao(base);

			if (i >= argc) // era o último conjunto de argumentos
				break;
			else
				i -= 2; // recuar para processar o -P seguinte
		}
	}

	if (!fichSolucoes.Empty()) {
		// dado ficheiro de soluções, apenas validar as soluções, não executar o teste empírico
		TesteValidacao(instancias, impossiveis, referencias, fichSolucoes, fichResultados);
	}
	else {
		// arrancar MPI apenas após processar os argumentos
		InicializaMPI(argc, argv);

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
}

void TProcura::AjudaUtilizacao(TString programa) {
	printf(
		"Uso: %s <instâncias> [opções]\n"
		"  <instâncias>    Conjunto de IDs: A | A,B,C | A:B[:C]\n"
		"Opções:\n"
		"  -R <ficheiro>   Nome do CSV de resultados (omissão: resultados.csv)\n"
		"  -S solucoes [custoMin,custoMax,tempoMin,tempoMax [<ids>]]\n"
		"     caso exista ficheiro de soluções, pretende-se apenas validação\n"
		"     pode-se dar referências de custo min/max e tempo min/max para indicador de desempenho\n"
		"     <ids> - identificação das instâncias impossíveis\n"
		"  -F <prefixo>    Prefixo para leitura da instância por ficheiro (omissão: vazio)\n"
		"  -FG <prefixo>    Prefixo para gravação da instância em ficheiro (omissão: vazio)\n"
		"  -M <modo>       Modo MPI: 0 = divisão estática, 1 = gestor-trabalhador\n"
		"  -G <0/1>        Gravar solução (sequência de ações): 0 = não grava, 1 = grava\n"
		"  -I <ind>        Lista de indicadores (e.g. 2,1,3)\n"
		"  -h              Esta ajuda\n"
		"  -P <expr>       Parâmetros (e.g. P1=1:3 x P2=0:2) - valores para cada parâmetro, distintos dos por omissão\n"
		"Exemplo: %s 1:5 -R out -F fich_ -I 3,1,4,2 -P P1=1:5 x P6=1,2 \n"
		"   Executar sem argumentos entra em modo interativo, para explorar todos os parâmetros e indicadores\n",
		*programa, *programa
	);
	ResetParametros();
	MostraParametros(2);
	MostraIndicadores();
}


bool TProcura::RelatorioCSV(TVector<TResultado>& resultados, TString ficheiro, bool parametros) {
	TString nome;
	TVector<TString> linhas;
	if (mpiCount > 1)
		nome.printf("%s_%d.csv", *ficheiro.tok().First(), mpiID);
	else
		nome.printf("%s.csv", *ficheiro.tok().First());

	// cabeçalho: instância, parametros, indicadores
	linhas += TString("Instância;");
	if (parametros) {
		for (int i = 0; i < parametro.Count(); i++)
			linhas.Last().printf("P%d(%s);", i + 1, *parametro[i].nome);
		for (auto item : indAtivo)
			linhas.Last().printf("I%d(%s);", item + 1, *indicador[item].nome);
		linhas.Last().printf("Solução");
	}
	else {
		// apenas soluções: válidas, inválidas, melhor, pior
		linhas.Last().printf("Válidas;Inválidas;Melhor;Pior;Tempo(ms)");
	}
	for (auto& res : resultados) {
		linhas += TString().printf("%d;", res.instancia);
		if (parametros) {
			for (int j = 0; j < parametro.Count(); j++)
				// ver se parametro j está ativo na configuração configuracoes[res.configuracao]
				if (!ParametroAtivo(j, &(configuracoes[res.configuracao])))
					linhas.Last().printf(";"); // parametro inativo, não mostrar
				else if (parametro[j].nomeValores.Empty())
					linhas.Last().printf("%d;", configuracoes[res.configuracao][j]); // mostrar valor
				else
					linhas.Last().printf("%d:%s;", // mostrar valor e texto
						configuracoes[res.configuracao][j],
						*parametro[j].nomeValores[configuracoes[res.configuracao][j] - parametro[j].min]);
			for (auto ind : indAtivo)
				linhas.Last().printf("%" PRId64 ";", Registo(res, ind));

			if (gravarSolucao) {
				if (!res.solucao.Empty()) {
					for (auto& acao : res.solucao)
						linhas.Last().printf("%s ", *acao);
				}
				else {
					// imprimir todos os valores após os indicadores
					for (int i = indicador.Count(); i < res.valor.Count(); i++)
						linhas.Last().printf("%" PRId64 ";", res.valor[i]);
				}
			}
		}
		else {
			// apenas soluções: válidas, inválidas, melhor, pior, tempo
			for (auto item : res.valor)
				linhas.Last().printf("%" PRId64 ";", item);
		}
	}

	nome.writeLines(linhas);

	return true;
}

void TProcura::MostraRelatorio(TVector<TResultado>& resultados, bool ultimo)
{
	if (ultimo) {
		if (!resultados.Empty() && !indAtivo.Empty()) {
			int col = 2;
			MostraCaixa("Indicadores", ECaixaParte::Topo, 70, true, 0, Icon(EIcon::IND));
			MostraCaixa("", ECaixaParte::Meio, 1);
			for (auto ind : indAtivo) {
				if (col > 2)
					col += printf(" | ");
				if (col >= 70) {
					MostraCaixa("", ECaixaParte::Meio, 1);
					col = 2;
				}
				col += printf(COR_LEVE "I%d(%s):" COR_RESET " %" PRId64, ind + 1,
					*indicador[ind].nome, Registo(resultados.Last(), ind)) - COR_LEVE_TAM;
			}
			MostraCaixa("", ECaixaParte::Fundo);
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
	TVector<int> larguras = { 6,7,11,11 };
	TVector<TString> titulosVazios = { "", "", "", "" };
	TVector<TString> icons = {
		Icon(EIcon::INST),
		Icon(EIcon::CONF),
		Icon(EIcon::VALOR),
		Icon(EIcon::TEMPO)
	};

	// mostrar os resultados apenas do custo e tempo
	MostraCaixa(titulosVazios, ECaixaParte::Topo, larguras, false);
	MostraCaixa(icons, ECaixaParte::Meio, larguras, false);
	MostraCaixa(titulosVazios, ECaixaParte::Separador, larguras, false);


	for (auto& res : resultados) {
		TVector<TString> str(4);
		if (Registo(res, IND_RESULTADO) >= -1)
			total[res.configuracao].instancia++;

		str[0].printf("%d", res.instancia);
		str[1].printf("%d", res.configuracao + 1);
		str[2].printf("%" PRId64, Registo(res, IND_RESULTADO));
		str[3].printf("%" PRId64, Registo(res, IND_TEMPO));

		MostraCaixa(str, ECaixaParte::Meio, larguras, false);

		// somar tudo
		for (auto ind : indAtivo)
			Registo(total[res.configuracao], ind,
				Registo(total[res.configuracao], ind) +
				Registo(res, ind));
	}
	MostraCaixa(titulosVazios, ECaixaParte::Fundo, larguras, false);

	// tabela com os totais por configuração
	for (int i = 0; i < total.Count(); i++) {
		TString str;
		int col = 2;
		str.printf("%-2s Total %-2s%d", Icon(EIcon::TAXA), Icon(EIcon::CONF), i + 1);
		MostraCaixa(str, ECaixaParte::Topo);
		MostraCaixa("", ECaixaParte::Meio, 1);
		for (auto ind : indAtivo) {
			col += printf(COR_LEVE "%s:" COR_RESET " ", *indicador[ind].nome) - COR_LEVE_TAM;
			col += printf("%" PRId64 " ", Registo(total[i], ind));
			if (col > 70) {
				MostraCaixa("", ECaixaParte::Meio, 1);
				col = 2;
			}
		}
		if (col > 70)
			MostraCaixa("", ECaixaParte::Meio, 1);
		printf(COR_LEVE "Instâncias resolvidas:" COR_RESET " %d", total[i].instancia);
		MostraCaixa("", ECaixaParte::Fundo);
	}
	// mostrar torneio entre configurações
	CalculaTorneio(resultados);
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
	MostraCaixa("Indicadores", ECaixaParte::Topo, 70, true, 0, Icon(EIcon::IND));
	for (int i = 0; i < indicador.Count(); i++) {
		MostraCaixa("", ECaixaParte::Meio, 1);
		printf(COR_LEVE "I%d(%s):" COR_RESET " ", i + 1, *indicador[i].nome);
		if (indicador[i].indice < 0)
			printf("%-2sinativo ", Icon(EIcon::NSEL));
		else
			printf("%-2s%dº lugar ", Icon(EIcon::SEL), indicador[i].indice + 1);
		MostraCaixa("", ECaixaParte::Meio, 1);
		printf(COR_LEVE "%s" COR_RESET, *indicador[i].descricao);
	}
	MostraCaixa("", ECaixaParte::Fundo);
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
	printf("\n%-2s Torneio (#instâncias melhores):", Icon(EIcon::TORNEIO));
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
		Mensagem(Icon(EIcon::INSUC), " Tempo excedido");
	else if (memoriaEsgotada)
		Mensagem(Icon(EIcon::INSUC), " Memória esgotada");
}

// MostrarSolucao: definir para visualizar a solução
void TProcura::MostrarSolucao() {
	TVector<int64_t> solucao = CodificarSolucao();
	printf("\nSolução: ");
	for (auto& x : solucao)
		printf("%" PRId64 " ", x);
	printf(".");
}


int TProcura::NovoValor(TString prompt) {
	TString str;
	str.Count(BUFFER_SIZE);
	printf("%s", *prompt);
	if (fgets(str.Data(), BUFFER_SIZE, stdin))
		if (strlen(str) > 1)
			return atoi(str);
	return NAO_LIDO;
}

// ler uma string
TString TProcura::NovoTexto(TString prompt) {
	TString str;
	str.Count(BUFFER_SIZE);
	printf("%s", *prompt);

	if (fgets(str.Data(), BUFFER_SIZE, stdin) == nullptr)
		return TString("");

	// remover o '\n' do final
	int len = (int)strlen(str);
	if (len > 0 && str[len - 1] == '\n')
		str[len - 1] = 0;

	// retorna nova TString, com o tamanho certo
	return TString(*str);
}

void TProcura::SolicitaInstancia() {
	if (instancia.max != instancia.min) {
		int resultado;
		TString texto;

		MostraCaixa("Instância", ECaixaParte::Topo, 70, true, 0, Icon(EIcon::INST));
		MostraCaixa("", ECaixaParte::Meio, 1);
		printf(COR_LEVE "ID atual:" COR_RESET " %d  " COR_LEVE "Intervalo:" COR_RESET " [%d–%d]  ",
			instancia.valor, instancia.min, instancia.max);
		MostraCaixa("", ECaixaParte::Meio, 1);
		printf(COR_LEVE "Prefixo atual:" COR_RESET " '%s' ", *ficheiroInstancia);
		MostraCaixa("", ECaixaParte::Fundo);
		texto = NovoTexto("\nNovo ID (ENTER mantém) ou novo prefixo (texto): ");
		resultado = atoi(texto);
		if (resultado != 0 || texto.Empty()) {
			if (resultado != 0)
				instancia.valor = resultado;
			Dominio(instancia.valor, instancia.min, instancia.max);
		}
		else if (texto.Count() < 256)
			ficheiroInstancia = texto;
	}
	else
		instancia.valor = instancia.min;
	Inicializar();
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
#endif
}

void TProcura::FinalizaMPI()
{
#ifdef MPI_ATIVO
	MPI_Finalize();
#endif
}

void TProcura::DebugTabela(ENivelDebug nivel, TVector<int> tabela, TString tipo,
	TString prefixo, int modoCor, bool duplaColuna)
{
	if (Parametro(NIVEL_DEBUG) < nivel)
		return;
	printf("\n%s%-4s ", *prefixo, *tipo);
	for (int i = 0; i < 10 && i < tabela.Count(); i++)
		printf("%4d ", i + 1);
	printf("\n%s────┼", *prefixo);
	for (int i = 0; i < 10 && i < tabela.Count(); i++)
		printf("────┼");
	for (int i = 0; i < tabela.Count(); i++) {
		if (i % 10 == 0)
			printf("\n%s%4d│", *prefixo, i);
		if (modoCor > 0 && modoCor <= 1000000) // conteúdo com cor de 1 a modoCor
			DebugHSL(tabela[i] * 360.0f / modoCor);
		else if (modoCor > 1000000) // 0 - verde e maiorCusto vermelho
			DebugHSL((1 - 1.0f * tabela[i] / (modoCor - 1000000)) * 120, .75, .5, false);
		else if (modoCor < 0) // índice com a cor
			DebugHSL((i + 1) * 360.0f / tabela.Count());
		printf("%4d", tabela[i]);
		DebugHSL();
		if (duplaColuna && i % 2 == 0)
			printf("⇄");
		else
			printf("│");
	}
}

bool TProcura::JuntarCSV(TString ficheiro)
{
	// ficheiros CSV com o mesmo cabeçalho, ficheiro0.csv, ficheiro1.csv, ..., ficheiroN.csv
	TVector<TString> linhas, todasLinhas;

	// verifica se existem os ficheiros intermédios
	for (int i = 0; i < mpiCount; i++)
		if (TString().printf("%s_%d.csv", *ficheiro, i).readLines().Empty())
			// não existe este ficheiro, ainda não está tudo
			return false;

	for (int i = 0; i < mpiCount; i++) {
		linhas = TString().printf("%s_%d.csv", *ficheiro, i).readLines();
		if (i == 0)
			todasLinhas = linhas;
		else
			// não incluir a linha de cabeçalho
			for (int j = 1; j < linhas.Count(); j++)
				todasLinhas += linhas[j];

		remove(TString().printf("%s_%d.csv", *ficheiro, i)); // apagar ficheiro intermédio
	}
	TString().printf("%s.csv", *ficheiro).writeLines(todasLinhas);
	return true;
}

void TProcuraExecutavel::ResetParametros()
{
	TProcura::ResetParametros();

	// adicionar os indicadores e parâmetros específicos
	indicador += ind;
	parametro += par;

	// atualizar os valores por omissão
	omissao.Count(parametro.Count());
	for (int i = 0; i < parametro.Count(); i++)
		omissao[i] = parametro[i].valor;

	instancia = inst;

	indValores.Count(indicador.Count()).Reset(0);

	// colocar todos os indicadores ativos por ordem de ID
	indAtivo = {};
	for (int i = 0; i < indicador.Count(); i++)
		indAtivo += i;

	// corrigir prefixos ineixistentes
	while (parPrefixo.Count() < parametro.Count())
		parPrefixo += TString("");
	while (indPrefixo.Count() < indicador.Count())
		indPrefixo += TString("");
}

int TProcuraExecutavel::ExecutaAlgoritmo()
{
	TString resultFile, opcoes;
	int error;

	resultFile.printf("%s%d.txt", *ficheiroInstancia, mpiID);

	// construir as opções que são distintas dos valores por omissão
	for (int i = 0; i < parametro.Count(); i++)
		if (Parametro(i) != omissao[i])
			opcoes.printf("%s%d ", *parPrefixo[i], Parametro(i));

	error = system(TString().printf("%s %s %s%d > %s",
		*solver, *opcoes, *ficheiroInstancia, instancia.valor, *resultFile));
	if (error == -1) {
		Mensagem(Icon(EIcon::INSUC), " Erro ao executar o comando.");
		return RES_NAO_RESOLVIDO;
	}
	else if (error != 0) {
		Mensagem(Icon(EIcon::INSUC), " O comando retornou um código de erro: %d", error);
		return RES_NAO_RESOLVIDO;
	}

	// extrair indicadores com base no indPrefixo
	for (auto& linha : resultFile.readLines())
		for (int i = 0; i < indPrefixo.Count(); i++)
			if (!indPrefixo[i].Empty()) {
				const char* ptr = strstr(linha, indPrefixo[i]);
				if (ptr)
					indValores[i] = (int)(atof(ptr + indPrefixo[i].Count() - 1) + 0.5);
			}

	if (Parametro(NIVEL_DEBUG) < DETALHE)
		remove(resultFile); // apagar ficheiro de resultados intermédio
	return 0;
}

int64_t TProcuraExecutavel::Indicador(int id)
{
	if (id < indValores.Count())
		return indValores[id];
	return TProcura::Indicador(id);
}
