#include "TProcuraConstrutiva.h"
#include "CListaNo.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

constexpr int BUFFER_SIZE = 1024;

// auxiliar para construcao da arvore de procura 
TVector<const char*> TProcuraConstrutiva::ramo;
// valor retornado pela procura (tem de ser libertado)
TVector<TNo> TProcuraConstrutiva::caminho;
// valor retornado pela procura (tem de ser libertado)
TProcuraConstrutiva* TProcuraConstrutiva::solucao = NULL;
// lowerBound: valor mínimo que a solução pode obter
int TProcuraConstrutiva::lowerBound = 0;
/// @brief Número de expansões efetuadas.
int TProcuraConstrutiva::expansoes = 0;
/// @brief Número de estados gerados.
int TProcuraConstrutiva::geracoes = 0;
/// @brief custo da última ação realizada (Acao(TString))
int TProcuraConstrutiva::custoAcao = 0;


TBits TProcuraConstrutiva::elementosHT[TAMANHO_HASHTABLE]; // hashtable0
int TProcuraConstrutiva::custoHT[TAMANHO_HASHTABLE]; // hashtable / custo do estado que foi gerado
TBits TProcuraConstrutiva::estadoCodHT; // elemento codificado
int TProcuraConstrutiva::colocadosHT = 0; // número de elementos colocados na HT

TProcuraConstrutiva::TProcuraConstrutiva(void) {}


void TProcuraConstrutiva::ResetParametros()
{
	TProcura::ResetParametros();

	// definir parametros base
	// algoritmos, alterar
	parametro[ALGORITMO] = { "ALGORITMO",1,1,7,"Algoritmo base a executar.", {
		"Largura Primeiro",
		"Custo Uniforme",
		"Profundidade Primeiro",
		"Melhor Primeiro",
		"A*",
		"IDA*",
		"Branch and Bound" }
	};
	// parametros adicionados
	parametro += {
		{ "VER_ACOES", 4, 1, 100, "Mostra estado a cada K ações. Se 1 mostra sempre estados e nunca ações." },
		{ "LIMITE",0,-1,1000000,
"Valor dependente do algoritmo. \n\
Largura: 0 sem limite, >0 número máximo de estados gerados não expandidos. \n\
Profundidade: >0 limite de profundidade, =0 iterativo, <0 sem limite." },
		{ "ESTADOS_REPETIDOS", 1,1,3, "Forma de lidar com os estados repetidos (ignorá-los, ascendentes, gerados).", {
			"ignorar",
			"ascendentes",
			"gerados" } },
		{ "PESO_ASTAR", 100, 0, 10000,
		  "Peso aplicado à heuristica, na soma com o custo para calculo do lower bound. No A*, se peso 0, fica custo uniforme, h(n) não conta, se peso 100 fica A* normal, se superior a 100 aproxima-se do melhor primeiro.",
		  "", _TV("0,5:7") },
		{ "RUIDO_HEURISTICA",0,-100,100, "Ruído a adicionar à heurística, para testes de robustez. Se K positivo, adicionar entre 0 e K-1, se negativo, o valor a adicionar pode ser positivo ou negativo.",
		  "", _TV("0,5:7") },
		{ "BARALHAR_SUCESSORES",0,0,1, "Baralhar os sucessores ao expandir." }
	};

	// indicadores, alterar
	indicador[IND_CUSTO].nome = "IND_CUSTO";
	indicador[IND_CUSTO].descricao = "o resultado é o custo da solução atual";
	// indicadores adicionados
	indicador += {
		{ "IND_EXPANSOES", "número de expansões efetuadas", IND_EXPANSOES },
		{ "IND_GERACOES","número de estados gerados", IND_GERACOES },
		{ "IND_LOWER_BOUND", "valor mínimo para a melhor solução, se igual ao custo da solução obtida, então esta é ótima", IND_LOWER_BOUND }
	};
	indAtivo += {IND_EXPANSOES, IND_GERACOES, IND_LOWER_BOUND};
}

// Executa uma ação (movimento, passo, jogada, lance, etc.) no estado atual. Caso não seja feito nada, retornar falso.
bool TProcuraConstrutiva::Acao(TString acao) {
	TVector<TNo> sucessores;
	Sucessores(sucessores);
	for (int i = 0; i < sucessores.Count(); i++)
		if (acao == Acao(sucessores[i])) {
			custoAcao = sucessores[i]->custo - custo;
			Copiar(sucessores[i]);
			TProcuraConstrutiva::LibertarVector(sucessores);
			return true;
		}
	return false;
}

// Coloca em sucessores a lista de objectos sucessores (sao alocados neste metodo e tem de ser apagados)
// O custo se não existir, deixar a 1 (valor por omissão)
// chamar o metodo desta classe apos adicionar os sucessores para actualizar geracoes e expansoes,
// bem como verificar a existência de estados repetidos
void TProcuraConstrutiva::Sucessores(TVector<TNo>& sucessores) {
	if (memoriaEsgotada)
		return;
	// colocar como pai o estado atual e atualizar custos
	for (int i = 0; i < sucessores.Count(); i++) {
		sucessores[i]->pai = this;
		sucessores[i]->custo += custo;
		// o custo total tem de estar atualizado antes de se utilizar nas hashtables
	}
	// verificação de estados repetidos
	if (Parametro(ESTADOS_REPETIDOS) == GERADOS) {
		for (int i = 0; i < sucessores.Count(); i++)
			if (sucessores[i]->ExisteHT()) {
				// estado já gerado anteriormente, está na hashtable, pelo que não interessa
				delete sucessores[i];
				sucessores[i] = NULL;
			}
	}
	else if (Parametro(ESTADOS_REPETIDOS) == ASCENDENTES) {
		// verificar se o estado já foi gerado na árvore de procura
		// remover todos os estados que ja tenham sido expandidos neste ramo
		for (int i = 0; i < sucessores.Count(); i++) {
			TNo avo = this;
			while (avo != NULL && avo->Distinto(sucessores[i]))
				avo = avo->pai;
			// estado é igual a um avô, não interessa
			if (avo != NULL) {
				delete sucessores[i];
				sucessores[i] = NULL;
			}
		}
	}
	sucessores -= NULL;
	if (Parametro(BARALHAR_SUCESSORES) == 1)
		sucessores.RandomOrder();
	expansoes++;
	if (Parametro(NIVEL_DEBUG) >= PASSOS && !sucessores.Empty()) {
		for (auto suc : sucessores)
			suc->debugID = ++geracoes;
		// avançar se for algoritmo em profundidade
		switch (Parametro(ALGORITMO)) {
		case PROFUNDIDADE_PRIMEIRO:
		case MELHOR_PRIMEIRO:
		case IDA_STAR:
		case BRANCH_AND_BOUND:
			ramo.Push(RAMO_ESTADO);
		}
	}
	else
		geracoes += sucessores.Count();
}


// metodo interno para libertar objectos nao necessarios
void TProcuraConstrutiva::LibertarVector(TVector<TNo>& vector, int excepto, int maiorQue)
{
	for (int i = 0; i < vector.Count(); i++)
		if (i != excepto && i > maiorQue && vector[i] != NULL)
			delete vector[i];
	vector = {};
}


bool TProcuraConstrutiva::Validar(TVector<TString> solucao) {
	int custoTotal = 0, nAcoes = 0;
	// aplicar todas as ações
	for (auto acao : solucao) {
		if (!Acao(acao)) {
			if (Debug(PASSOS, false, "\n │ Ação inválida: %s (custo atual: %d de %d ações válidas)",
				*acao, custoTotal, nAcoes))
				Debug();
			resultado = -1; // ação inválida
			return false;
		}
		custoTotal += custoAcao;
		nAcoes++;
	}
	if (SolucaoCompleta()) {
		resultado = custo = custoTotal; // custo da solução encontrada
		return true;
	}
	if (Debug(PASSOS, false, "\n │ Solução não completa (custo atual: %d de %d ações válidas)",
		custoTotal, nAcoes))
		Debug();
	resultado = -2; // solução incompleta
	return false;
}


///////////////////////////////////////////////////////////////////////////////
// Procura em Largura Primeiro: expande primeiro o estado gerado não expandido mais antigo
// retorna o valor da solução e coloca o caminho no vector (se calcularCaminho=true), ou -1 caso não encontre solucao
// limite é o número de estados gerados não expandidos, que não pode ultrapassar esse limite
// os que ultrapassarem são deitados fora (se 0 este limite não importa, podendo haver problemas de memória)
int TProcuraConstrutiva::LarguraPrimeiro(int limite)
{
	TVector<TNo> lista; // lista de nós gerados na árvore de procura (expandidos ou não)
	lista += this; // nó inical: estado, custo
	for (int i = 0; i < lista.Count() && !Parar(); i++) {
		// processar o próximo estado não expandido (estão expandidos todos os anteriores a i)
		lista[i]->DebugPasso();
		// expansão deste estado
		TVector<TNo> sucessores;
		lista[i]->Sucessores(sucessores);
		// garantir que os limites são respeitados, para evitar problemas de memória
		VerificaLimites(limite, lista.Count() - i, sucessores);

		if (Parametro(NIVEL_DEBUG) > DETALHE)
			lista[i]->DebugSucessores(sucessores);

		// inserir tudo no final da lista
		for (int j = 0; j < sucessores.Count(); j++) {
			lista += sucessores[j];
			// verificar se é um estado objetivo, a solução é completa nesse caso
			// teste na geração e não na expansão 
			if (lista.Last()->SolucaoCompleta()) {
				LibertarVector(sucessores, -1, j);
				return ObjetivoAlcancado(lista.Count() - 1, lista); // Sucesso! Terminar a procura e retornar
			}
		}

		// Nao se pode libertar estados ja expandidos porque nao se sabe se
		// os pais sao necessarios ou nao.
		// todos os estados antes de i, são os estados gerados e expandidos (fechados)
		// todos os estados após i são estados gerados mas não expandidos (abertos)
	}
	// nada feito, libertar tudo excepto o estado inicial que é este objeto, e retornar
	LibertarVector(lista, 0);
	return -1; // falhou
}

int TProcuraConstrutiva::ObjetivoAlcancado(TNo estado, bool completa)
{
	estado->CalculaCaminho(completa); // extrair o caminho do estado objetivo até ao estado inicial
	solucao = estado->Duplicar(); // registar este estado como a solução
	solucao->custo = estado->custo;
	solucao->DebugSolucao();
	return solucao->custo;
}

int TProcuraConstrutiva::ObjetivoAlcancado(int item, TVector<TNo>& lista)
{
	ObjetivoAlcancado(lista[item]);
	LibertarVector(lista, 0);
	return solucao->custo;
}

void TProcuraConstrutiva::CalculaCaminho(bool completa) {
	TNo atual = this;
	// limpar o caminho anterior (caso do BnB que obtém mais que uma solução)
	while (!caminho.Empty())
		delete caminho.Pop();
	caminho += atual->Duplicar();
	caminho.Last()->custo = atual->custo;

	// apenas se a lista estiver completa, há a garantia dos pais não terem sido apagados
	if (completa) {
		// obter caminho para a solucao
		while (atual->pai != NULL) {
			atual = atual->pai;
			caminho += atual->Duplicar();
			caminho.Last()->custo = atual->custo;
		}
	}
	caminho.Invert();
}

void TProcuraConstrutiva::VerificaLimites(
	int limite, int porProcessar, TVector<TNo>& sucessores)
{
	// caso o limite seja ultrapassado, 
	// remover elementos a mais da lista de sucessores
	if (limite != 0 && limite < porProcessar + sucessores.Count()) {
		int maximo = limite - porProcessar;
		if (maximo >= 0 && maximo < sucessores.Count()) {
			for (int i = maximo; i < sucessores.Count(); i++)
				delete sucessores[i];
			sucessores.Count(maximo);
		}
		else if (maximo < 0)
			LibertarVector(sucessores);
	}
}


///////////////////////////////////////////////////////////////////////////////
// Procura Custo Uniforme: expande primeiro o estado gerado não expandido de menor custo acumulado
int TProcuraConstrutiva::CustoUniforme(int limite)
{
	CListaNo lista(limite);

	lista.Inserir(this); // começa apenas com o elemento atual

	for (lista.atual = 0; !Parar() && lista.Estado() != NULL; lista.atual = lista.Proximo()) {
		lista.Estado()->DebugPasso(&lista);
		if (lista.Estado()->SolucaoCompleta())
			return ObjetivoAlcancado(lista.Estado(), lista.Completa());

		TVector<TNo> sucessores;
		lista.Estado()->Sucessores(sucessores);
		// insere por ordem de custo, e não apenas no final
		lista.Inserir(sucessores);
		if (Parametro(NIVEL_DEBUG) > DETALHE)
			lista.Estado()->DebugSucessores(sucessores);
	}
	return -1; // falhou
}

///////////////////////////////////////////////////////////////////////////////
// Procura em Profundidade Primeiro: expande primeiro o estado gerado não expandido mais novo
// caso o nivel=-1, e feita uma procura em profunidade normal
// caso o nivel>0, e feita uma procura em profundidade limitada
// caso o nivel=0, e feita uma procura em profundidade iterativa, sem limite
// versão recursiva
int TProcuraConstrutiva::ProfundidadePrimeiro(int nivel)
{
	if (nivel == 0) { // metodo iterativo
		int resultado = -1;
		do {
			// limpar hashtable: estados gerados no nível anterior não devem impedir nova geração
			LimparHT();
			DebugIteracao(nivel + 1, "🪜");
			// chamar a profundidade nível 1, e se não resolver, o nível 2, e assim sucessivamente
			resultado = ProfundidadePrimeiro(++nivel);
		} while (resultado == -1 && !Parar());
		return resultado;
	}
	bool noFolha = !((nivel > 1 || nivel < 0) && !Parar());
	DebugChamada(noFolha);

	// metodo normal
	// verificar se o estado atual é objetivo, ou seja, a solução parcial é já completa
	if (SolucaoCompleta())
		return SolucaoEncontrada(true);

	if (!noFolha) {
		// caso o nível seja superior a 1 ou sem limite, expandir o estado atual
		TVector<TNo> sucessores;
		Sucessores(sucessores);
		// tentar todos os sucessores, um de cada vez
		for (int i = 0; i < sucessores.Count(); i++) {
			DebugExpansao(i, sucessores.Count());
			// chamada recursiva, reduzindo o nível 
			if (sucessores[i]->ProfundidadePrimeiro(nivel - 1) >= 0) {
				// este sucessor resolveu o problema, retornar
				return SolucaoParcial(i, sucessores);
			}
		}
		// nenhum dos sucessores resolveu o problema
		DebugCorte(sucessores.Count());
		LibertarVector(sucessores);
	}
	else
		DebugFolha(false, "%-2s%-2s", Icon(EIcon::FOLHA), Icon(EIcon::LIMITE));

	// falha na procura neste nó, ou não há estado objetivo a partir daqui
	// ou atingiu-se o limite, pelo que temos de retornar -1
	return -1;
}

int TProcuraConstrutiva::SolucaoEncontrada(bool continuar) {
	// sucesso!
	DebugSolucao(continuar);
	if (solucao == NULL)
		solucao = Duplicar();
	else // caso existam várias soluções, substitui a anterior
		solucao->Copiar(this);
	CalculaCaminho();
	DebugFolha(false, "%-2s%d → %-2s", Icon(EIcon::SUCESSO), custo, Icon(EIcon::UB));
	return solucao->custo = custo;
}

int TProcuraConstrutiva::SolucaoParcial(int i, TVector<TNo>& sucessores, int iAux, TVector<int>* id)
{
	// solução parcial já registada, adicionar este nó e retornar o custo até ao momento
	if (Parametro(NIVEL_DEBUG) >= PASSOS) {
		TVector<int> valores;
		for (int j = (iAux >= 0 ? iAux + 1 : i + 1);
			j < (iAux >= 0 ? id->Count() : sucessores.Count()); j++)
			valores += (iAux >= 0 ? sucessores[(*id)[j]]->debugID : sucessores[j]->debugID);
		if (!valores.Empty()) {
			DebugFolha(true, "");
			MostraConjunto(valores, Icon(EIcon::ID));
		}
	}
	ramo.Pop();

	LibertarVector(sucessores, i);
	return solucao->custo;
}

TVector<TString> TProcuraConstrutiva::Solucao() {
	TVector<TString> resultado;
	for (int i = 0; i < caminho.Count() - 1; i++)
		resultado += caminho[i]->Acao(caminho[i + 1]);
	if (resultado.Empty())
		resultado += TString("vazio"); // para garantir que o resultado não é vazio, para efeitos de validação
	return resultado;
}

void TProcuraConstrutiva::MostrarCaminho() {
	printf("\n══ %-2s Solução ══", Icon(EIcon::SOL));
	for (int i = 0; i < caminho.Count() - 1; i++) {
		if (Parametro(VER_ACOES) > 1) {
			// mostrar o estado a cada K ações, no início e no fim
			if (i % Parametro(VER_ACOES) == 0) {
				caminho[i]->Debug();
				// mostrar custo
				printf(" (%-2sg:%d) %-2s", Icon(EIcon::VALOR), caminho[i]->custo, Icon(EIcon::ACCAO));
			}
			// mostrar a ação
			if (i < caminho.Count() - 1)
				printf(" → %s", *caminho[i]->Acao(caminho[i + 1]));
		}
		else {
			caminho[i]->Debug();
			printf(" (%-2sg:%d) %-2s", Icon(EIcon::VALOR), caminho[i]->custo, Icon(EIcon::ACCAO));
		}
	}
	if (caminho.Empty())
		printf("Caminho vazio.");
	else {
		caminho.Last()->Debug();
		// mostrar custo
		printf(" (%-2sg:%d) ", Icon(EIcon::VALOR), caminho.Last()->custo);
		if (caminho.Last()->SolucaoCompleta())
			printf("%-2s", Icon(EIcon::SUCESSO));
		else
			printf("%-2s", Icon(EIcon::INSUC));
	}
}


///////////////////////////////////////////////////////////////////////////////
// Algoritmo Melhor Primeiro: expande primeiro o estado gerado não expandido com melhor heurística
// versão recursiva, idêntico a ProcuraPrimeiro()
int TProcuraConstrutiva::MelhorPrimeiro(int nivel)
{
	if (nivel > 0 && Parametro(LIMITE) == nivel)
		DebugIteracao(nivel, Icon(EIcon::LIMITE));

	bool noFolha = !((nivel <= 0 || nivel > 1) && !Parar());
	DebugChamada(noFolha);
	if (SolucaoCompleta())
		return SolucaoEncontrada(true);

	if (!noFolha) {
		TVector<TNo> sucessores;
		TVector<int> id; // índice para ordenar os sucessores por heurística
		Sucessores(sucessores);
		CalcularHeuristicas(sucessores, &id); // id fica ordenado por heurística
		// processar todos os sucessores da mesma forma que a procura em profundidade,
		// mas utilizando a ordem id, por heurística
		for (int i = 0; i < id.Count(); i++) {
			DebugExpansao(i, id.Count());
			if (sucessores[id[i]]->MelhorPrimeiro(nivel - 1) >= 0)
				return SolucaoParcial(id[i], sucessores);
		}
		DebugCorte(sucessores.Count());
		LibertarVector(sucessores);
	}
	else
		DebugFolha(false, "%-2s&-2s", Icon(EIcon::FOLHA), Icon(EIcon::LIMITE));
	return -1;
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo IDAStar: procura em profundidade limitada a um upperBound
// idêntico a MelhorPrimeiro() mas cortando quando upperBound já não consegue ser obtido 
int TProcuraConstrutiva::IDAStar(int upperBound)
{
	if (upperBound == 0) { // parte iterativa
		int resultado = -1;
		// primeiro valor para o lower bound, a heurística no nó raiz
		lowerBound = Heuristica(); // o custo é zero atualmente
		if (lowerBound == 0)
			lowerBound++;
		do {
			// limpar hashtable: estados gerados no nível anterior não devem impedir nova geração
			LimparHT();
			DebugIteracao(lowerBound, Icon(EIcon::LB));
			// ver se há uma solução com este valor
			resultado = IDAStar(lowerBound);
			// o valor de lowerBound é atualizado, para utilizar na próxima iteração se necessário
		} while (resultado == -1 && !Parar());
		return resultado;
	}
	bool noFolha = Parar();
	DebugChamada(!noFolha);

	if (SolucaoCompleta())
		return SolucaoEncontrada(true);

	if (!noFolha) {
		TVector<TNo> sucessores;
		TVector<int> id; // índice para ordenar os sucessores por heurística
		Sucessores(sucessores);
		CalcularHeuristicas(sucessores, &id, true); // id fica ordenado por LB
		// processar todos os sucessores da mesma forma que a procura em profundidade,
		// mas utilizando a ordem id, por heurística
		for (int i = 0; i < id.Count(); i++) {
			int atual = sucessores[id[i]]->LowerBound();
			DebugExpansao(i, id.Count());
			if (atual > upperBound) {
				// Nó folha, não identificado antes. Mostrar o estado no caso do detalhe
				if (Parametro(NIVEL_DEBUG) == DETALHE)
					Debug();
				// acima do permitido nesta iteração
				ramo.Last() = (i < id.Count() - 1 ? RAMO_NOVO : RAMO_FIM);
				if (lowerBound == upperBound || lowerBound > atual) {
					DebugFolha(false, "%-2s%d → %-2s", Icon(EIcon::FOLHA), atual, Icon(EIcon::LB));
					lowerBound = atual;
				}
				else
					DebugFolha(false, Icon(EIcon::FOLHA));
				// listar os nós não explorados
				if (Parametro(NIVEL_DEBUG) >= PASSOS) {
					TVector<int> valores;
					// apenas o atual, já que continua
					valores += sucessores[id[i]]->debugID;
					MostraConjunto(valores, Icon(EIcon::ID));
				}
			}
			else {
				if (sucessores[id[i]]->IDAStar(upperBound) >= 0)
					return SolucaoParcial(id[i], sucessores, i, &id);
			}
		}
		DebugCorte(sucessores.Count());
		LibertarVector(sucessores);
	}
	return -1;
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo BranchAndBound: 
// idêntico a MelhorPrimeiro(), mas continua após a primeira solução
// explora apenas os estados em que f(n) < atual solução (LB<UB)
int TProcuraConstrutiva::BranchAndBound(int upperBound)
{
	bool noFolha = Parar();
	DebugChamada(!noFolha);
	if (SolucaoCompleta())
		return SolucaoEncontrada(true);

	if (!noFolha) {
		TVector<TNo> sucessores;
		TVector<int> id; // índice para ordenar os sucessores por heurística
		Sucessores(sucessores);
		CalcularHeuristicas(sucessores, &id, true); // id fica ordenado por LB
		// processar todos os sucessores, mas apenas se LB<UB
		for (int i = 0; i < id.Count(); i++) {
			DebugExpansao(i, id.Count());
			if (upperBound && sucessores[id[i]]->LowerBound() >= upperBound) {
				// Nó folha, não identificado antes. Mostrar o estado no caso do detalhe
				if (Parametro(NIVEL_DEBUG) == DETALHE)
					Debug();
				DebugFolha(true, "%-2s%-2s", Icon(EIcon::FOLHA), Icon(EIcon::UB));
				// listar os nós não explorados
				if (Parametro(NIVEL_DEBUG) >= PASSOS) {
					TVector<int> valores;
					for (int j = i; j < id.Count(); j++)
						valores += sucessores[id[j]]->debugID;
					MostraConjunto(valores, Icon(EIcon::ID));
				}
				break;
			}
			int resultado = sucessores[id[i]]->BranchAndBound(upperBound);
			// mesmo que exista um resultado, continuar à procura de melhor
			if (resultado > 0 && (!upperBound || resultado < upperBound))
				upperBound = resultado;
		}
		DebugCorte(sucessores.Count());
		LibertarVector(sucessores);
	}
	return (solucao != NULL ? solucao->custo : -1);
}

void TProcuraConstrutiva::CalcularHeuristicas(
	TVector<TNo>& sucessores, TVector<int>* id, bool sortLB)
{
	TVector<int> heuristicas;
	// obter os valores heurísticos, e ordentar o índice
	for (int i = 0; i < sucessores.Count(); i++) {
		sucessores[i]->heuristica = sucessores[i]->Heuristica();
		if (id != NULL)
			heuristicas += (sucessores[i]->heuristica + (sortLB ? sucessores[i]->custo : 0));
	}
	if (id != NULL)
		heuristicas.Sort(id); // ordenar id
}


///////////////////////////////////////////////////////////////////////////////
// Algoritmo AStar: expande primeiro o estado gerado não expandido com melhor custo+heurística
// Idêntico a CustoUniforme()
int TProcuraConstrutiva::AStar(int limite)
{
	CListaNo lista(limite);
	lista.Inserir(this); // estado único

	for (lista.atual = 0; !Parar() && lista.Estado() != NULL; lista.atual = lista.Proximo()) {
		lista.Estado()->DebugPasso(&lista);
		if (lista.Estado()->SolucaoCompleta())
			return ObjetivoAlcancado(lista.Estado(), lista.Completa());

		TVector<TNo> sucessores;
		lista.Estado()->Sucessores(sucessores);
		// atualiza as heurísticas, sendo esta a única diferença para CustoUniforme
		CalcularHeuristicas(sucessores);
		// insere por ordem de custo, e não apenas no final
		lista.Inserir(sucessores);
		if (Parametro(NIVEL_DEBUG) > DETALHE)
			lista.Estado()->DebugSucessores(sucessores);
	}

	return -1; // falhou
}

// Redefinir para poder utilizar os algoritmos informados
// Esta função deve devolver o custo estimado por baixo, 
// desde este estado até ao estado final mais proximo (é um valor minimo),
// colocando esse valor na variável heuristica
// chamar este método para actualiacao de avaliacoes
int TProcuraConstrutiva::Heuristica(void) {
	iteracoes++;
	if (Parametro(RUIDO_HEURISTICA) > 0)
		heuristica += TRand::rand() % Parametro(RUIDO_HEURISTICA);
	if (Parametro(RUIDO_HEURISTICA) < 0)
		heuristica += TRand::rand() % (-2 * Parametro(RUIDO_HEURISTICA)) - Parametro(RUIDO_HEURISTICA);
	return heuristica;
}


// Metodo para ser chamado antes de analisar cada sucessor
void TProcuraConstrutiva::DebugExpansao(int sucessor, int sucessores, bool minimizar)
{
	if (minimizar)
		ramo.Last() = (sucessor < sucessores - 1 ? RAMO_ESTADO : RAMO_ESTADO_FIM);
	else
		ramo.Last() = (sucessor < sucessores - 1 ? RAMO_ESTADO2 : RAMO_ESTADO2_FIM);
}

void TProcuraConstrutiva::DebugRamo(const char* ramo, const char* folha) {
	printf("%s", ramo);
	printf("%s", folha);
}


// Metodo para ser chamado quando nao ha sucessores ou ha um corte de profundidade
void TProcuraConstrutiva::DebugCorte(int sucessores, bool duplo)
{
	if (Parametro(NIVEL_DEBUG) >= PASSOS && sucessores >= 0) {
		if (sucessores == 0)
			DebugFolha(false, Icon(EIcon::FOLHA));
		else
			ramo.Pop();
	}

	if (Parametro(NIVEL_DEBUG) >= PASSOS && sucessores < 0) {
		ramo.Last() = RAMO_FIM;
		NovaLinha();
		printf("%-2s%-2s %d ", Icon(EIcon::CORTE), Icon(EIcon::ID), debugID);
	}
}

// Encontrou uma solucao
void TProcuraConstrutiva::DebugSolucao(bool continuar)
{
	if (Parametro(NIVEL_DEBUG) > NADA && SolucaoCompleta()) {
		NovaLinha();
		printf(" %-2s Solução encontrada! %-2sg:%d",
			Icon(EIcon::SUCESSO), Icon(EIcon::VALOR), custo);
		ramo.Last() = RAMO_CONTINUA;
		Debug();
		if (!continuar)
			ramo = {};
	}
	else {
		if (Parametro(NIVEL_DEBUG) > ATIVIDADE)
			Debug();
		if (Parametro(NIVEL_DEBUG) >= PASSOS && !continuar)
			ramo.Pop();
	}
}

// Informacao de debug na chamada ao metodo recursivo
void TProcuraConstrutiva::DebugChamada(bool noFolha)
{
	if (Parametro(NIVEL_DEBUG) == ATIVIDADE && expansoes % 1000 == 0)
		printf("#");
	if (Parametro(NIVEL_DEBUG) >= PASSOS) {
		bool raiz = (ramo.Count() <= 1);
		// neste nível, cada estado expandido é visualizado, não apenas os estados folha
		if (raiz)
			ramo.First() = RAMO_ESTADO;
		NovaLinha(true);
		ramo.Last() = ((ramo.Last() == RAMO_ESTADO || ramo.Last() == RAMO_ESTADO2) ? RAMO_CONTINUA : RAMO_VAZIO);
		ramo.First() = RAMO_CONTINUA;
		DebugEstado(false);
		if (pai != NULL)
			printf(" %-2s%s", Icon(EIcon::ACCAO), *pai->Acao(this)); // mostra sempre a ação
		if ((noFolha && Parametro(NIVEL_DEBUG) >= DETALHE) ||
			Parametro(NIVEL_DEBUG) >= COMPLETO)
			Debug();
	}
}

// Chamar sempre que se quer uma nova linha com a arvore em baixo
void TProcuraConstrutiva::NovaLinha(bool tudo)
{
	printf("\n");
	for (int i = 0; i < ramo.Count() - (tudo ? 0 : 1); i++)
		printf("%s", ramo[i]);
}

// Passo no algoritmo em largura
void TProcuraConstrutiva::DebugPasso(CListaNo* lista)
{
	if (Parametro(NIVEL_DEBUG) == ATIVIDADE && expansoes % 1000 == 0)
		printf("#");
	if (Parametro(NIVEL_DEBUG) >= PASSOS) {
		TString str;
		ramo.First() = RAMO_ESTADO;
		NovaLinha(true);
		ramo.First() = RAMO_CONTINUA;
		DebugEstado(false);
		if (lista == NULL) {
			if (expansoes < geracoes) {
				str.printf("%d:%d", expansoes + 1, geracoes);
				MostraConjunto(_TV(str), Icon(EIcon::ID));
			}
			else
				printf(" { }");
		}
		else {
			int atual = lista->atual;
			TVector<int> valores;
			lista->atual = lista->Proximo();
			for (; lista->Estado() != NULL; lista->atual = lista->Proximo())
				valores += lista->Estado()->debugID;
			lista->atual = atual;
			MostraConjunto(valores, Icon(EIcon::ID));
		}
	}
	if (Parametro(NIVEL_DEBUG) > PASSOS)
		Debug();
}
// Mostrar sucessores
void TProcuraConstrutiva::DebugSucessores(TVector<TNo>& sucessores) {
	if (Parametro(VER_ACOES) > 2) {
		// mostrar apenas ações
		NovaLinha(true);
		TProcura::MostraCaixa(Icon(EIcon::ACCAO), ECaixaParte::Fundo, 1, true, -1);
		for (int i = 0; i < sucessores.Count(); i++) {
			printf(" %s", *Acao(sucessores[i]));
			if (i == 2 && sucessores.Count() > 10) {
				printf(" …");
				i = sucessores.Count() - 4;
			}
		}
		if (sucessores.Count() > 0) {
			TVector<int> valores;
			for (auto suc : sucessores)
				valores += suc->debugID;
			if (valores.First() != 0)
				MostraConjunto(valores, Icon(EIcon::ID));
		}
	}
	else {
		ramo.Push((sucessores.Count() > 1 ? RAMO_ESTADO : RAMO_ESTADO_FIM));
		for (int i = 0; i < sucessores.Count(); i++) {
			NovaLinha(true);
			sucessores[i]->DebugEstado(false);
			printf(" %s", *Acao(sucessores[i])); // mostra sempre a ação
			ramo.Last() = (i < sucessores.Count() - 1 ? RAMO_CONTINUA : RAMO_VAZIO);
			if (Parametro(VER_ACOES) == 1)
				sucessores[i]->Debug();
			// mostrar só alguns se forem muitos sucessores
			if (i == 2 && sucessores.Count() > 10) {
				NovaLinha(true);
				printf(" …");
				i = sucessores.Count() - 4;
			}
			ramo.Last() = (i < sucessores.Count() - 2 ? RAMO_ESTADO : RAMO_ESTADO_FIM);
		}
		ramo.Pop();
	}
}


// uma nova iteração de um algoritmo iterativo
void TProcuraConstrutiva::DebugIteracao(int iteracao, const char* simbolo) {
	Debug(PASSOS, false, "\n ├─────────── %-2s%s %d %-2s%s ──────────── ",
		Icon(EIcon::ARVORE), simbolo, iteracao, Icon(EIcon::TEMPO),
		MostraTempo(Cronometro(CONT_ALGORITMO)));
}

// informação geral sobre o estado 
void TProcuraConstrutiva::DebugEstado(bool novaLinha) const {
	if (novaLinha)
		printf("\n═╤═ "); // ╠ ║
	else
		printf("═╤═ ");

	if (debugID > 0) {
		printf("%-2s%d ", Icon(EIcon::ID), debugID);
	}
	printf("%-2sg:%d ", Icon(EIcon::VALOR), custo);
	if (heuristica)
		printf("%-2sh:%d ", Icon(EIcon::SUCESSO), heuristica);

	if (expansoes || geracoes || iteracoes) {
		printf("%-2s ", Icon(EIcon::IND));
		if (expansoes)
			printf("%d", expansoes);
		if (geracoes)
			printf("|%d", geracoes);
		if (iteracoes)
			printf("|%d", iteracoes);
	}

	printf(" ═══"); // ╣ ║
}

// Chamar antes de iniciar uma procura
void TProcuraConstrutiva::LimparEstatisticas()
{
	TProcura::LimparEstatisticas();
	geracoes = expansoes = 0;
	ramo = {};
	ramo.Add(RAMO_CONTINUA);
	while (!caminho.Empty())
		delete caminho.Pop();
	if (solucao != NULL)
		delete solucao;
	solucao = NULL;
	LimparHT();
}


int TProcuraConstrutiva::ExecutaAlgoritmo() {
	int resultado = -1;
	switch (Parametro(ALGORITMO)) {
	case 1: resultado = LarguraPrimeiro(Dominio(Parametro(LIMITE), 0)); break;
	case 2: resultado = CustoUniforme(Dominio(Parametro(LIMITE), 0)); break;
	case 3: resultado = ProfundidadePrimeiro(Parametro(LIMITE)); break;
	case 4: resultado = MelhorPrimeiro(Parametro(LIMITE)); break;
	case 5: resultado = AStar(Dominio(Parametro(LIMITE), 0)); break;
	case 6: resultado = IDAStar(Dominio(Parametro(LIMITE), 0)); break;
	case 7:
		if (Parametro(LIMITE) > 0)
			DebugIteracao(Parametro(LIMITE), Icon(EIcon::UB));
		resultado = BranchAndBound(Dominio(Parametro(LIMITE), 0));
		break;
	}
	ramo = {};
	LimparHT();
	return custo = resultado;
}



void TProcuraConstrutiva::ExecucaoTerminada()
{
	TProcura::ExecucaoTerminada();
	if (solucao != NULL) {
		Copiar(solucao);
		delete solucao;
		solucao = NULL;
	}
}


void TProcuraConstrutiva::Explorar() {
	TVector<TNo> sucessores;
	int opcao = 0;
	LimparEstatisticas();
	do {
		caminho += Duplicar();
		if (caminho.Count() > 1)
			caminho.Last()->custo += caminho[caminho.Count() - 2]->custo;
		else
			caminho.Last()->custo = 0;
		heuristica = Heuristica();
		ramo = {};
		ramo.Push(RAMO_CONTINUA);
		Sucessores(sucessores);
		CalcularHeuristicas(sucessores);
		// linha com informação
		DebugEstado();
		Debug();
		DebugSucessores(sucessores);
		if (sucessores.Empty()) {
			TProcura::Mensagem(Icon(EIcon::IMP), "Sem sucessores.");
			opcao = 0;
		}
		else {
			TString str;
			printf("\n%-2sSucessor [1-%d, ação(ões), exe]: ", Icon(EIcon::EXP), sucessores.Count());
			opcao = atoi(str = NovoTexto(""));
			if (opcao == 0 && strlen(str) > 1) {
				TVector<TString> acoes = str.tok();
				opcao = sucessores.Count() + 1;
				// executar algoritmo
				if (strcmp(acoes.First(), "exe") == 0) {
					TVector<TNo> backup;
					backup = caminho;
					caminho = {};
					LimparEstatisticas();
					int resultado = 0;
					switch (resultado = ExecutaAlgoritmo()) {
					case RES_IMPOSSIVEL: TProcura::Mensagem(Icon(EIcon::IMP), "Impossível"); break;
					case RES_NAO_RESOLVIDO: TProcura::Mensagem(Icon(EIcon::INSUC), "Não resolvido"); break;
					default: TProcura::Mensagem(Icon(EIcon::SOL), "Resolvido (%d)", resultado); break;
					}
					tempo = Cronometro(CONT_ALGORITMO);
					if (solucao != NULL) {
						Copiar(solucao);
						delete backup.Pop();
						backup += caminho;
						caminho = backup;
						caminho.Pop(); // este último estado será adicionado
					}
					else
						caminho = backup;
				}
				else {
					int nAcoes = 0;
					for (int i = 0; i < acoes.Count(); i++) {
						// executar a ação
						if (Acao(acoes[i]))
							nAcoes++;
						else {
							TProcura::Mensagem(Icon(EIcon::IMP), "Ação %s inválida.", *acoes[i]);
							break;
						}

						if (i < acoes.Count() - 1) {
							// há outra ação, é preciso atualizar o caminho
							caminho += Duplicar();
							if (caminho.Count() > 1)
								caminho.Last()->custo += caminho[caminho.Count() - 2]->custo;
							else
								caminho.Last()->custo = 0;
						}
					}
					if (nAcoes > 0)
						TProcura::Mensagem(Icon(EIcon::SOL), "Executadas %d ações.", nAcoes);
				}
			}
		}
		if (opcao > 0 && opcao <= sucessores.Count()) {
			Copiar(sucessores[opcao - 1]);
			TProcura::Mensagem(Icon(EIcon::SOL), "Ação executada.");
		}
		LibertarVector(sucessores);
	} while (opcao != 0);
}

unsigned int TProcuraConstrutiva::Hash() {
	Codifica(estadoCodHT);
	return estadoCodHT.Hash() % TAMANHO_HASHTABLE;
}

void TProcuraConstrutiva::LimparHT() {
	if (Parametro(ESTADOS_REPETIDOS) == GERADOS) {
		if (Parametro(NIVEL_DEBUG) >= ATIVIDADE) {
			int usado = 0; // contar para calcular taxa de ocupação
			for (int i = 0; i < TAMANHO_HASHTABLE; i++) 
				if (elementosHT[i].Count() > 0) {
					usado++;
					elementosHT[i].Count(0);
				}
			// reportar estatísticas se existir muito reuso
			if (Parametro(NIVEL_DEBUG) >= DETALHE && usado > 0 && usado * 2 <= colocadosHT) {
				NovaLinha();
				printf("HT: utilização %d%%, reuso: %.2f vezes",
					usado * 100 / TAMANHO_HASHTABLE,
					1.0 * colocadosHT / usado);
			}
		}
		else
			for (int i = 0; i < TAMANHO_HASHTABLE; i++)
				elementosHT[i].Count(0);
		colocadosHT = 0;
		// coloca o estado atual na hasttable, para não ser gerado
		ExisteHT();
	}
}

bool TProcuraConstrutiva::ExisteHT() {
	// caso não exista, retorna falso e insere
	// se existe retorna verdade, e estiver lá outro elemento, substitui
	unsigned int original = Hash();
	unsigned int indice = original % TAMANHO_HASHTABLE;
	if (elementosHT[indice] != estadoCodHT) {
		SubstituirHT(indice);
		colocadosHT++;
		return false; // não existia
	}
	// elemento é igual, mas se o custo for mais alto, não conta
	// já que este elemento com custo mais baixo, pode conduzir à solução ou melhores soluções
	// neste caso substitui e retorna que o estado não existe
	if (custoHT[indice] > custo) {
		SubstituirHT(indice);
		return false; // existe mas com um custo mais alto
	}
	return true; // igual, estado já analisado
}

void TProcuraConstrutiva::SubstituirHT(int indice)
{
	// substituir elemento
	elementosHT[indice]=estadoCodHT;
	custoHT[indice] = custo;
}

// estados repetidos: verificar todos os gerados
// implementar para utilizar hashtables com perdas
// converte o estado atual para a variável estado, utilizando o menor espaço possível
// caso existam simetrias, normalizar o estado antes de codificar, para considerar exploradas todas as versões
void TProcuraConstrutiva::Codifica(TBits &estado) {
	estado.Count(0);
}

int64_t TProcuraConstrutiva::Indicador(int id)
{
	if (id == IND_CUSTO)
		return custo;
	else if (id == IND_EXPANSOES)
		return expansoes;
	else if (id == IND_GERACOES)
		return geracoes;
	else if (id == IND_LOWER_BOUND)
		return lowerBound;
	return TProcura::Indicador(id);
}



