#include "TProcuraConstrutiva.h"
#include <stdio.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define BUFFER_SIZE 1024


// numero de geracaes de estados
int TProcuraConstrutiva::geracoes = 0;
// numero de expansoes de estados
int TProcuraConstrutiva::expansoes=0;
// numero de chamadas a funcao heuristica
int TProcuraConstrutiva::avaliacoes=0;
// auxiliar para construcao da arvore de procura
TVector<unsigned char> TProcuraConstrutiva::ramo;
// espacamento entre ramos da arvore de debug
int TProcuraConstrutiva::espacosRamo=2;
// valor retornado pela procura (tem de ser libertado)
TVector<TNo> TProcuraConstrutiva::caminho;
// valor retornado pela procura (tem de ser libertado)
TProcuraConstrutiva* TProcuraConstrutiva::solucao=NULL;
// lowerBound: valor mínimo que a solução pode obter
int TProcuraConstrutiva::lowerBound = 0;

// deadline da corrida atual
clock_t TProcuraConstrutiva::instanteFinal = 0;
// flag de problemas de memória esgotada
bool TProcuraConstrutiva::memoriaEsgotada = false;
// ID da instância atual (problemas com várias instâncias, a utilizar em SolucaoVazia())
TParametro TProcuraConstrutiva::instancia = { 1,1,1, NULL, NULL, NULL };
// adicionar parâmetros específicos, se necessário
TVector<TParametro> TProcuraConstrutiva::parametro;

// conjuntos de valores de parâmetros, para teste
TVector<TVector<int>> TProcuraConstrutiva::configuracoes;

// tamanho em inteiros de 64 bits de um objeto (inferior ou igual a OBJETO_HASHTABLE)
int TProcuraConstrutiva::tamanhoCodificado = OBJETO_HASHTABLE;

uint64_t TProcuraConstrutiva::elementosHT[TAMANHO_HASHTABLE][OBJETO_HASHTABLE]; // hashtable0
int TProcuraConstrutiva::custoHT[TAMANHO_HASHTABLE]; // hashtable / custo do estado que foi gerado
uint64_t TProcuraConstrutiva::estadoCodHT[OBJETO_HASHTABLE]; // elemento codificado


TProcuraConstrutiva::TProcuraConstrutiva(void) : pai(NULL), heuristica(0), custo(1) {
}

void TProcuraConstrutiva::ResetParametros() 
{
	static const char* nomesAlgoritmos[] = {
		"Largura Primeiro",
		"Custo Uniforme",
		"Profundidade Primeiro",
		"Melhor Primeiro",
		"A*",
		"IDA*",
		"Branch and Bound" };
	static const char* nomesDebug[] = {
		"nada",
		"atividade",
		"passos",
		"detalhe",
		"completo" };
	static const char* nomesRepetidos[] = {
		"ignorar",
		"ascendentes",
		"gerados" };
	// definir parametros base
	parametro.Count(0);
	// algoritmos
	parametro.Add({ 1,1,7,"Algoritmo","Escolha do algoritmo base a executar.", nomesAlgoritmos });
	// nivel de debug
	parametro.Add({ 0,0,4,"Debug","Nível de debug, desde reduzido a completo.",nomesDebug });
	// ver Acoes (ou apenas estados completos)
	parametro.Add({ 4,1,100,"Ver","Mostra estado a cada K ações. Se 1 mostra sempre estados e nunca ações.",NULL });
	// seed 
	parametro.Add({ 1,1,1000000, "Seed","Semente aleatória para inicializar a sequência de números pseudo-aleatórios. Alterar para garantir diferentes números.",NULL });
	// limite tempo
	parametro.Add({ 10,1,3600, "Tempo","Tempo limite em segundos. Caso seja ultrapassado, o algoritmo pára.",NULL });
	// máximo de gerações
	parametro.Add({ 0,0,1000000000, "Gerações","Número de gerações máximo (0 não há limite). Caso seja ultrapassado, o algoritmo pára.", NULL });
	// máximo de expansões
	parametro.Add({ 0,0,1000000000, "Expansões","Número de expansões máximo (0 não há limite). Caso seja ultrapassado, o algoritmo pára.",NULL });
	// máximo de avaliacoes
	parametro.Add({ 0,0,1000000000, "Avaliações","Número de avaliações máximo (0 não há limite). Caso seja ultrapassado, o algoritmo pára.",NULL });
	// limite (algoritmo)
	parametro.Add({ 0,-1,1000000, "Limite",
		"Valor dependente do algoritmo. \n\
Largura: 0 sem limite, >0 número máximo de estados gerados não expandidos. \n\
Profundidade: >0 limite de profundidade, =0 iterativo, <0 sem limite.",NULL });
	// estados repetidos
	parametro.Add({ 1,1,3, "Repetidos", "Forma de lidar com os estados repetidos",
			nomesRepetidos });
	// pesoAStar 
	parametro.Add({ 100,0,10000, "pesoAStar",
		"Utilizado no A*. Se peso 0, fica custo uniforme, h(n) não conta, se peso 100 fica A* normal, se superior a 100 aproxima-se do melhor primeiro.",NULL });
	// ruido heuristica
	parametro.Add({ 0,-100,100, "ruido",
		"Ruído a adicionar à heurística. Se K positivo, adicionar entre 0 e K-1, se negativo, o valor a adicionar pode ser positivo ou negativo.",NULL });
	// baralhar sucessores
	parametro.Add({ 0,0,1, "baralhar",
		"Baralhar a ordem dos sucessores.",NULL });

	// colocar as configurações vazias (podem ser inicializadas se existirem configurações de omissão)
	configuracoes.Count(0);
}

// Executa uma ação (movimento, passo, jogada, lance, etc.) no estado atual. Caso não seja feito nada, retornar falso.
bool TProcuraConstrutiva::Acao(const char* acao) {
	TVector<TNo> sucessores;
	Sucessores(sucessores);
	for (int i = 0; i < sucessores.Count(); i++)
		if (strcmp(acao, Acao(sucessores[i])) == 0) {
			Copiar(sucessores[i]);
			TProcuraConstrutiva::LibertarVector(sucessores);
			return true;
		}
	return false;
}

// Coloca em sucessores a lista de objectos sucessores (sao alocados neste metodo e tem de ser apagados)
// O custo se não existir, deixar a 1 (valor de omissão)
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
	if (parametro[estadosRepetidos].valor == gerados) {
		for (int i = 0; i < sucessores.Count(); i++)
			if (sucessores[i]->ExisteHT()) {
				// estado já gerado anteriormente, está na hashtable, pelo que não interessa
				delete sucessores[i];
				sucessores[i] = NULL;
			}
	}
	else if (parametro[estadosRepetidos].valor == ascendentes) {
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
	sucessores.Remove(NULL);
	if (parametro[baralharSuc].valor == 1)
		sucessores.RandomOrder();
	expansoes++;
	geracoes += sucessores.Count();
}


// metodo interno para libertar objectos nao necessarios
void TProcuraConstrutiva::LibertarVector(TVector<TNo>&vector, int excepto, int maiorQue)
{
	for (int i = 0; i < vector.Count(); i++)
		if (i != excepto && i > maiorQue && vector[i] != NULL)
			delete vector[i];
	vector.Count(0);
}

///////////////////////////////////////////////////////////////////////////////
// Procura em Largura Primeiro: expande primeiro o estado gerado não expandido mais antigo
// retorna o valor da solução e coloca o caminho no vector (se calcularCaminho=true), ou -1 caso não encontre solucao
// limite é o número de estados gerados não expandidos, que não pode ultrapassar esse limite
// os que ultrapassarem são deitados fora (se 0 este limite não importa, podendo haver problemas de memória)
int TProcuraConstrutiva::LarguraPrimeiro(int limite)
{
	TVector<TNo> lista; // lista de nós gerados na árvore de procura (expandidos ou não)
	lista.Add(this); // nó inical: estado, custo
	for (int i = 0; i < lista.Count() && !Parar(); i++) {
		// processar o próximo estado não expandido (estão expandidos todos os anteriores a i)
		lista[i]->DebugPasso();
		// expansão deste estado
		TVector<TNo> sucessores;
		lista[i]->Sucessores(sucessores);
		// garantir que os limites são respeitados, para evitar problemas de memória
		VerificaLimites(limite, lista.Count() - i, sucessores);
		// inserir tudo no final da lista
		for (int j = 0; j < sucessores.Count(); j++) {
			lista.Add(sucessores[j]);
			// verificar se é um estado objetivo, a solução é completa nesse caso
			// teste na geração e não na expansão 
			if (lista.Last()->SolucaoCompleta()) {
				LibertarVector(sucessores, -1, j);
				return ObjetivoAlcancado(lista.Count() - 1, lista); // Sucesso! Terminar a procura e retornar
			}
		}

		if(parametro[nivelDebug].valor > 3)
			lista[i]->DebugSucessores(sucessores);

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
	while (caminho.Count() > 0)
		delete caminho.Pop();
	caminho.Add(atual->Duplicar());
	caminho.Last()->custo = atual->custo;

	// apenas se a lista estiver completa, há a garantia dos pais não terem sido apagados
	if (completa) {
		// obter caminho para a solucao
		while (atual->pai != NULL) {
			atual = atual->pai;
			caminho.Add(atual->Duplicar());
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
		lista.Estado()->DebugPasso();
		if(lista.Estado()->SolucaoCompleta())
			return ObjetivoAlcancado(lista.Estado(), lista.Completa());

		TVector<TNo> sucessores;
		lista.Estado()->Sucessores(sucessores);
		// insere por ordem de custo, e não apenas no final
		lista.Inserir(sucessores);
		if (parametro[nivelDebug].valor > 3)
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
	DebugChamada();
	if (nivel == 0) { // metodo iterativo
		int resultado = -1;
		do {
			// limpar hashtable: estados gerados no nível anterior não devem impedir nova geração
			LimparHT();
			DebugIteracao(nivel + 1);
			// chamar a profundidade nível 1, e se não resolver, o nível 2, e assim sucessivamente
			resultado = ProfundidadePrimeiro(++nivel);
		} while (resultado == -1 && !Parar());
		return resultado;
	} 

	// metodo normal
	// verificar se o estado atual é objetivo, ou seja, a solução parcial é já completa
	if (SolucaoCompleta())
		return SolucaoEncontrada();
	
	if((nivel>1 || nivel<0) && !Parar()) {
		// caso o nível seja superior a 1 ou sem limite, expandir o estado atual
		TVector<TNo> sucessores;
		Sucessores(sucessores);
		// tentar todos os sucessores, um de cada vez
		for (int i = 0; i < sucessores.Count(); i++) {
			DebugExpansao(i, sucessores.Count());
			// chamada recursiva, reduzindo o nível 
			if (sucessores[i]->ProfundidadePrimeiro(nivel - 1) >= 0)
				// este sucessor resolveu o problema, retornar
				return SolucaoParcial(i, sucessores);
		}
		// nenhum dos sucessores resolveu o problema
		DebugCorte(sucessores.Count());
		LibertarVector(sucessores);
	}
	else
		DebugCorte();

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
	return solucao->custo = custo;
}

int TProcuraConstrutiva::SolucaoParcial(int i, TVector<TNo>& sucessores)
{
	// solução parcial já registada, adicionar este nó e retornar o custo até ao momento
	LibertarVector(sucessores, i);
	return solucao->custo;
}

void TProcuraConstrutiva::MostrarCaminho() {
	for (int i = 0; i < caminho.Count(); i++) {
		if (parametro[verAcoes].valor > 1) {
			// mostrar o estado a cada K ações, no início e no fim
			if (i % parametro[verAcoes].valor == 0 || i == caminho.Count() - 1) {
				caminho[i]->Debug();
				// mostrar custo
				printf(" (g:%d) ", caminho[i]->custo);
			}
			// mostrar a ação
			if(i < caminho.Count() - 1)
				printf(" %s", caminho[i]->Acao(caminho[i + 1]));
		}
		else {
			caminho[i]->Debug();
			printf(" (g:%d) ", caminho[i]->custo);
		}
	}
	if (caminho.Count() == 0)
		printf("Caminho vazio.");
}


///////////////////////////////////////////////////////////////////////////////
// Algoritmo Melhor Primeiro: expande primeiro o estado gerado não expandido com melhor heurística
// versão recursiva, idêntico a ProcuraPrimeiro()
int TProcuraConstrutiva::MelhorPrimeiro(int nivel)
{
	DebugChamada();
	if (SolucaoCompleta())
		return SolucaoEncontrada();

	if ((nivel <= 0 || nivel > 1) && !Parar()) {
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
		DebugCorte();
	return -1;
}

///////////////////////////////////////////////////////////////////////////////
// Algoritmo IDAStar: procura em profundidade limitada a um upperBound
// idêntico a MelhorPrimeiro() mas cortando quando upperBound já não consegue ser obtido 
int TProcuraConstrutiva::IDAStar(int upperBound)
{
	DebugChamada();
	if (upperBound == 0) { // parte iterativa
		int resultado = -1;
		// primeiro valor para o lower bound, a heurística no nó raiz
		lowerBound = Heuristica(); // o custo é zero atualmente
		if (lowerBound == 0)
			lowerBound++; 
		do {
			// limpar hashtable: estados gerados no nível anterior não devem impedir nova geração
			LimparHT();
			DebugIteracao(lowerBound);
			// ver se há uma solução com este valor
			resultado = IDAStar(lowerBound);
			// o valor de lowerBound é atualizado, para utilizar na próxima iteração se necessário
		} while (resultado == -1 && !Parar());
		return resultado;
	} 

	if (SolucaoCompleta())
		return SolucaoEncontrada();

	if (!Parar()) {
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
				// acima do permitido nesta iteração
				if (lowerBound == upperBound || lowerBound > atual)
					lowerBound = atual;
				DebugCorte(); // estado cortado, não expandido
			}
			else {
				if (sucessores[id[i]]->IDAStar(upperBound) >= 0)
					return SolucaoParcial(id[i], sucessores);
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
	DebugChamada();
	if (SolucaoCompleta())
		return SolucaoEncontrada(true);

	if (!Parar()) {
		TVector<TNo> sucessores;
		TVector<int> id; // índice para ordenar os sucessores por heurística
		Sucessores(sucessores);
		CalcularHeuristicas(sucessores, &id, true); // id fica ordenado por LB
		// processar todos os sucessores, mas apenas se LB<UB
		for (int i = 0; i < id.Count(); i++) {
			DebugExpansao(i, id.Count());
			if (upperBound && sucessores[id[i]]->LowerBound() >= upperBound) {
				DebugCorte(); // estado cortado, e os seguintes não serão expandidos
				break;
			}
			int resultado = sucessores[id[i]]->BranchAndBound(upperBound);
			// mesmo que exista um resultado, continuar à procura de melhor
			if (resultado > 0  && (!upperBound || resultado < upperBound))
				upperBound = resultado;
		}
		DebugCorte(sucessores.Count());
		LibertarVector(sucessores);
	}
	return (solucao != NULL ? solucao->custo : -1);
}

void TProcuraConstrutiva::CalcularHeuristicas(
	TVector<TNo>& sucessores, TVector<int> *id, bool sortLB)
{
	TVector<int> heuristicas;
	// obter os valores heurísticos, e ordentar o índice
	for (int i = 0; i < sucessores.Count(); i++) {
		sucessores[i]->heuristica = sucessores[i]->Heuristica();
		if (id != NULL)
			heuristicas.Add(sucessores[i]->heuristica + (sortLB ? sucessores[i]->custo : 0));
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

	for (lista.atual = 0; !Parar() && lista.Estado()!=NULL; lista.atual = lista.Proximo()) {
		lista.Estado()->DebugPasso();
		if (lista.Estado()->SolucaoCompleta())
			return ObjetivoAlcancado(lista.Estado(), lista.Completa());

		TVector<TNo> sucessores;
		lista.Estado()->Sucessores(sucessores);
		// atualiza as heurísticas, sendo esta a única diferença para CustoUniforme
		CalcularHeuristicas(sucessores);
		// insere por ordem de custo, e não apenas no final
		lista.Inserir(sucessores);
		if (parametro[nivelDebug].valor > 3)
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
	avaliacoes++;
	if (parametro[ruidoHeur].valor > 0) 
		heuristica += TRand::rand() % parametro[ruidoHeur].valor;
	if (parametro[ruidoHeur].valor < 0)
		heuristica += TRand::rand() % (-2 * parametro[ruidoHeur].valor) - parametro[ruidoHeur].valor;
	return heuristica;
}


// Escrever informacao de debug sobre o objecto atual
// (utilizar variavel TProcuraConstrutiva::debug para seleccionar o detalhe pretendido)
void TProcuraConstrutiva::Debug(void)
{
	if(parametro[nivelDebug].valor > 0)
		printf("\nTProcuraConstrutiva::Debug() não definido.");
}

// Metodo para ser chamado antes de analisar cada sucessor
void TProcuraConstrutiva::DebugExpansao(int sucessor, int sucessores, bool duplo)
{
	if(parametro[nivelDebug].valor >= 2) {
		if(sucessor > 0) 
			NovaLinha(false);

		if (sucessor == 0 && sucessores == 1) { // só um ramo
			DebugRamo(parametro[nivelDebug].valor < 4 ? '-' : ' ', duplo ? '#' : '+');
			ramo.Add(' '); // a ser impresso nesta posição nas linhas seguintes
		}
		else if (sucessor == 0) { // início e continua
			DebugRamo(parametro[nivelDebug].valor < 4 ? '-' : ' ', duplo ? '#' : '+');
			ramo.Add(duplo ? '/' : '|'); // a ser impresso nesta posição nas linhas seguintes
		}
		else if (sucessor > 0 && sucessor < sucessores - 1) { // no meio e continua
			DebugRamo(' ', duplo ? '#' : '+');
			ramo.Last() = (duplo ? '/' : '|');
		}
		else {
			DebugRamo(' ', duplo ? '#' : '+'); // no fim, vai acabar 
			ramo.Last() = ' '; // a ser impresso nesta posição nas linhas seguintes
		}
	}
}

void TProcuraConstrutiva::DebugRamo(char ramo, char folha) {
	for (int i = 0; i < espacosRamo; i++)
		printf("%c", ramo);
	printf("%c", folha);
}


// Metodo para ser chamado quando nao ha sucessores ou ha um corte de profundidade
void TProcuraConstrutiva::DebugCorte(int sucessores,bool duplo)
{
	if(parametro[nivelDebug].valor >= 2) {
		if(sucessores<0) {
			if (parametro[nivelDebug].valor < 4) {
				printf("%c ", '='); // corte de profundidade  
				DebugEstado();
				if (parametro[nivelDebug].valor >= 3)
					Debug();
			}
		} else if(sucessores>0)
			ramo.Pop();
		else if(parametro[nivelDebug].valor < 4) { // ramo em que nao e possivel continuar
			printf("%c ", '&');
			DebugEstado();
			if(parametro[nivelDebug].valor >= 3)
				Debug();
		}
	}
}

// Encontrou uma solucao
void TProcuraConstrutiva::DebugSolucao(bool continuar)
{
	if(parametro[nivelDebug].valor > 0 && SolucaoCompleta()) {
		printf(" Solução encontrada!");
		if(!continuar)
			ramo.Count(0);
		Debug();
		printf("(g:%d)", custo);
	} else {
		if(parametro[nivelDebug].valor > 1)
			Debug();
		if(parametro[nivelDebug].valor >= 2 && !continuar)
			ramo.Pop();
	}
}

// Informacao de debug na chamada ao metodo recursivo
void TProcuraConstrutiva::DebugChamada(void)
{
	if (parametro[nivelDebug].valor == 1 && expansoes % 1000 == 0)
		printf("#");
	if (parametro[nivelDebug].valor > 3) {
		// neste nível, cada estado expandido é visualizado, não apenas os estados folha
		DebugEstado();
		if(pai!=NULL)
			printf(" %s", pai->Acao(this)); // mostra sempre a ação
		if (parametro[verAcoes].valor == 1 || pai==NULL)
			Debug();
		NovaLinha();
	}
}

// Chamar sempre que se quer uma nova linha com a arvore em baixo
void TProcuraConstrutiva::NovaLinha(bool tudo)
{
	printf("\n");
	for (int i = 0; i < ramo.Count() - (tudo ? 0 : 1); i++)
		printf("%*s%c", espacosRamo, " ", ramo[i]);
}

// Passo no algoritmo em largura
void TProcuraConstrutiva::DebugPasso(void)
{
	if (parametro[nivelDebug].valor == 1 && expansoes % 1000 == 0)
		printf("#");
	if (parametro[nivelDebug].valor >= 2) {
		printf("\n");
		DebugEstado();
	}
	if (parametro[nivelDebug].valor > 2)
		Debug();
}
// Mostrar sucessores
void TProcuraConstrutiva::DebugSucessores(TVector<TNo>& sucessores) {
	if (parametro[verAcoes].valor > 2) {
		// mostrar apenas ações
		printf("\nAções: ");
		for (int i = 0; i < sucessores.Count() && i < 30; i++) {
			printf("%s ", Acao(sucessores[i]));
			if (i % 10 == 9)
				printf("\n ");
		}
	}
	else {
		ramo.Count(0);
			ramo.Add(' ');
			for (int i = 0; i < sucessores.Count() && i < 30; i++) {
				ramo.First() = '+';
					NovaLinha();
					sucessores[i]->DebugEstado(i + 1);
					if (i < sucessores.Count() - 1)
						ramo.First() = '|';
					else
						ramo.First() = ' ';
				printf(" %s", Acao(sucessores[i])); // mostra sempre a ação
				if (parametro[verAcoes].valor == 1)
					sucessores[i]->Debug();
			}
		ramo.Count(0);

	}
}


// uma nova iteração de um algoritmo iterativo
void TProcuraConstrutiva::DebugIteracao(int iteracao) {
	if (parametro[nivelDebug].valor == 1)
		printf("\n");
	if (parametro[nivelDebug].valor > 1) {
		printf("\nIteração %d:", iteracao);
		if (parametro[nivelDebug].valor > 2)
			printf(" (expansões %d, gerações %d, avaliações %d)\n", expansoes, geracoes, avaliacoes);
		else
			printf("\n");
	}
}

// informação geral sobre o estado 
void TProcuraConstrutiva::DebugEstado(int id, int pai) {
	if (id >= 0) {
		printf("#%d ", id);
		if(pai>=0)
			printf("(#%d) ", pai);
	}
	printf("g:%d ", custo);
	if (heuristica)
		printf("h:%d ", heuristica);

	if (expansoes)
		printf("%d", expansoes);
	if(geracoes)
		printf("|%d", geracoes);
	if(avaliacoes)
		printf("|%d", avaliacoes);
}



// Chamar antes de iniciar uma procura
void TProcuraConstrutiva::LimparEstatisticas(clock_t &inicio)
{
	expansoes = geracoes = avaliacoes = 0;
	ramo.Count(0);
	while (caminho.Count() > 0)
		delete caminho.Pop();
	if (solucao != NULL)
		delete solucao;
	solucao = NULL;
	LimparHT();
	inicio = clock();
	instanteFinal = inicio + parametro[limiteTempo].valor * CLOCKS_PER_SEC;
	memoriaEsgotada = false;
}

// Metodo para teste manual do objecto (chamadas aos algoritmos, construcao de uma solucao manual)
// Este metodo destina-se a testes preliminares, e deve ser redefinido apenas se forem definidos novos algoritmos
void TProcuraConstrutiva::TesteManual(const char *nome)
{
	int selecao, resultado;
	clock_t inicio;
	ResetParametros();
	TRand::srand(parametro[seed].valor);
	SolucaoVazia();
	LimparEstatisticas(inicio);
	while(true) {
		printf("\n%s (TProcuraConstrutiva)", nome);
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

void TProcuraConstrutiva::MostraParametros(int detalhe, TVector<int>* idParametros) {
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
		if(detalhe==0|| parametro[parID].nomeValores == NULL)
			printf("%d", parametro[parID].valor);
		else
			printf("%s", parametro[parID].nomeValores[parametro[parID].valor - parametro[parID].min]);
		// mostrar intervalo permitido
		if(detalhe>1)
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

void TProcuraConstrutiva::EditarParametros() {
	int opcao = 0, valor;
	while(1) {
		MostraParametros(2);
		if ((opcao = NovoValor("\nParametro:")) == NAO_LIDO || opcao == 0)
			return;
		opcao = Dominio(opcao, 1, parametro.Count() + 1);
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
void TProcuraConstrutiva::ConfiguracaoAtual(TVector<int>& parametros, int operacao) {
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


void TProcuraConstrutiva::EditarConfiguracoes() {
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

void TProcuraConstrutiva::MostrarConfiguracoes(int detalhe, int atual) {
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



int TProcuraConstrutiva::ExecutaAlgoritmo() {
	int resultado = -1;
	switch (parametro[algoritmo].valor) {
	case 1: resultado = LarguraPrimeiro(Dominio(parametro[limite].valor, 0)); break;
	case 2: resultado = CustoUniforme(Dominio(parametro[limite].valor, 0)); break;
	case 3: resultado = ProfundidadePrimeiro(parametro[limite].valor); break;
	case 4: resultado = MelhorPrimeiro(parametro[limite].valor); break;
	case 5: resultado = AStar(Dominio(parametro[limite].valor, 0)); break;
	case 6: resultado = IDAStar(Dominio(parametro[limite].valor, 0)); break;
	case 7: resultado = BranchAndBound(Dominio(parametro[limite].valor, 0)); break;
	}
	return resultado;
}


// utilizar para executar testes empíricos, utilizando todas as instãncias,
// com o último algoritmo executado e configurações existentes
void TProcuraConstrutiva::TesteEmpirico(int inicio, int fim, bool mostrarSolucoes) {
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
				(solucao != NULL ? solucao->custo : resultado),
				expansoes,geracoes,avaliacoes,configuracao,
				clock() - inicioCorrida });
			if (solucao != NULL && solucao->SolucaoCompleta()) {
				if (mostrarSolucoes)
					solucao->MostrarSolucao();
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
			if (solucao != NULL)
				delete solucao;
			solucao = NULL;
			printf("DONE.");
		}
	}
	MostraRelatorio(resultados);
	ConfiguracaoAtual(atual, gravar);
	instancia.valor = backupID;
	TRand::srand(parametro[seed].valor);
	SolucaoVazia();
}

void TProcuraConstrutiva::MostraRelatorio(TVector<TResultado>& resultados) 
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
		printf("\nTotal%3d |", i+1);
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

void TProcuraConstrutiva::CalculaTorneio(TVector<TResultado>& resultados) {
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


void TProcuraConstrutiva::MostrarTorneio(TVector<TVector<int>> &torneio, bool jogo)
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

void TProcuraConstrutiva::ExtrairConfiguracao(TVector<TResultado>& resultados, TVector<TResultado>& extracao, int configuracao) {
	extracao.Count(0);
	for (int i = instancia.min; i <= instancia.max; i++)
		for (int j = 0; j < resultados.Count(); j++)
			if (resultados[j].instancia == i && resultados[j].configuracao == configuracao)
				extracao.Add(resultados[j]);
}


void TProcuraConstrutiva::BarraTorneio(bool nomes) {
	// barra inical/final: |----|----|----|
	printf("\n |"); 
	for (int i = 0; i < configuracoes.Count(); i++)
		if(nomes)
			printf("-%02d-|", i + 1);
		else
			printf("----|");
}


int TProcuraConstrutiva::MelhorResultado(TResultado base, TResultado alternativa) {
	// se não resolvido por ambos, retornar igualdade
	if (base.custo == -2 && alternativa.custo == -2)
		return 0;
	// se igual no custo e o tempo menor que 0.1, retornar igualdade
	if (base.custo == alternativa.custo && 10 * abs(base.tempo - alternativa.tempo) / CLOCKS_PER_SEC == 0)
		return 0;
	// primeiro custo (ou não resolvido, -2)
	if (base.custo == -2 && alternativa.custo > -2 || alternativa.custo > 0 && base.custo > alternativa.custo)
		return -1;
	if (base.custo > -2 && alternativa.custo == -2 || base.custo > 0 && alternativa.custo > base.custo)
		return 1;
	// agora o tempo
	return base.tempo < alternativa.tempo ? 1 : -1;
}

void TProcuraConstrutiva::FinalizarCorrida(clock_t inicio)
{
	if (solucao != NULL) {
		Copiar(solucao);
		delete solucao;
		solucao = NULL;
	} 
	printf(" (%.3fs)", 1.0 * (clock() - inicio) / CLOCKS_PER_SEC);
	if (TempoExcedido())
		printf(" Tempo excedido.");
	else if (memoriaEsgotada)
		printf(" Memória esgotada.");
}

int TProcuraConstrutiva::NovoValor(const char* prompt) {
	char str[BUFFER_SIZE];
	printf("%s", prompt);
	fgets(str, BUFFER_SIZE, stdin);
	if (strlen(str) > 1)
		return atoi(str);
	return NAO_LIDO;
}

void TProcuraConstrutiva::SolicitaInstancia() {
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

void TProcuraConstrutiva::ExplorarSucessores(bool jogo) {
	TVector<TNo> sucessores;
	clock_t inicio;
	int opcao = 0;
	LimparEstatisticas(inicio);
	do {
		caminho.Add(Duplicar());
		if (caminho.Count() > 1)
			caminho.Last()->custo += caminho[caminho.Count() - 2]->custo;
		else
			caminho.Last()->custo = 0;
		heuristica = Heuristica();
		Sucessores(sucessores);
		CalcularHeuristicas(sucessores);
		// linha com informação
		DebugEstado();
		Debug();
		DebugSucessores(sucessores);
		if (sucessores.Count() == 0) {
			printf("\nSem sucessores.");
			opcao = 0;
		}
		else {
			char str[BUFFER_SIZE];
			printf("\nSucessor [1-%d, ação, exe]:", sucessores.Count());
			fgets(str, BUFFER_SIZE, stdin);
			opcao = atoi(str); 
			if (opcao == 0 && strlen(str)>1) {
				char* token;
				opcao = sucessores.Count() + 1;
				token = strtok(str, " \t\n\r");
				// executar algoritmo
				if (strcmp(token, "exe") == 0) {
					TVector<TNo> backup;
					backup = caminho;
					caminho.Count(0);
					LimparEstatisticas(inicio);
					if (jogo) {
						int valor = ExecutaAlgoritmo();
						printf("Valor: %d\n", valor);
						if (solucao != NULL) 
							Copiar(solucao);
						caminho = backup;
					}
					else {
						int resultado;
						switch (resultado=ExecutaAlgoritmo()) {
						case -1: printf("Impossível\n"); break;
						case -2: printf("Não resolvido\n"); break;
						default: printf("Resolvido (%d)\n", resultado); break;
						}
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
				} else if(!Acao(token)) // executar a ação
					printf("Ação %s inválida.\n", token);
			}
		}
		if (opcao > 0 && opcao <= sucessores.Count()) 
			Copiar(sucessores[opcao - 1]);
		LibertarVector(sucessores);
	} while (opcao != 0);
}

unsigned int TProcuraConstrutiva::Hash() {
	// utilizando FNV-1 hash (http://www.isthe.com/chongo/tech/comp/fnv/)
	uint32_t h = 2166136261;
	Codifica(estadoCodHT);
	for (int i = 0; i < OBJETO_HASHTABLE && estadoCodHT[i]; i++) {
		uint64_t valor = estadoCodHT[i];
		// processar cada octeto 
		// quando o valor fica 0, já não interessa
		// já que existindo dados, são distintos de 0
		for (int i = 0; i < 8 && valor; i++) {
			unsigned char octeto = valor & 255;
			valor >>= 8;
			h *= 16777619;
			h ^= octeto;
		}
	}
	return h % TAMANHO_HASHTABLE;
}

void TProcuraConstrutiva::LimparHT() {
	if (parametro[estadosRepetidos].valor == gerados) {
		for (int i = 0; i < TAMANHO_HASHTABLE; i++)
			for (int j = 0; j < tamanhoCodificado; j++)
				elementosHT[i][j] = 0;
		// coloca o estado atual na hasttable, para não ser gerado
		ExisteHT();
	}
}

bool TProcuraConstrutiva::ExisteHT() {
	// caso não exista, retorna falso e insere
	// se existe retorna verdade, e estiver lá outro elemento, substitui
	unsigned int original = Hash();
	unsigned int indice = original % TAMANHO_HASHTABLE;
	for (int i = 0; i < tamanhoCodificado; i++)
		if (elementosHT[indice][i] != estadoCodHT[i]) {
			SubstituirHT(indice);
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
	for (int i = 0; i < tamanhoCodificado; i++)
		elementosHT[indice][i] = estadoCodHT[i];
	custoHT[indice] = custo;
}

// estados repetidos: verificar todos os gerados
// implementar para utilizar hashtables com perdas
// converte o estado atual para a variável estado, utilizando o menor espaço possível
// caso existam simetrias, normalizar o estado antes de codificar, para considerar exploradas todas as versões
void TProcuraConstrutiva::Codifica(uint64_t estado[OBJETO_HASHTABLE]) {
	for (int i = 0; i < tamanhoCodificado; i++)
		estado[i] = 0;
}

int TProcuraConstrutiva::Dominio(int& variavel, int min, int max) {
	if (variavel < min)
		variavel = min;
	if (variavel > max)
		variavel = max;
	return variavel;
}

CListaNo::~CListaNo() {
	// não libertar o primeiro elemento
	for (int i = 1; i < indice.Count(); i++)
		if (indice[i].estado != NULL)
			delete indice[i].estado;
}

// retorna o índice onde foi inserido
int CListaNo::NovoElemento(TNo elemento) {
	int id = -1;
	if (limite == 0 || indice.Count() < 2 * limite) { 
		// adicionar, há espaço
		indice.Add({ elemento, 1, 1 });
		id = indice.Count() - 1;
	}
	else {
		// limite de estados atingido, gerar o espaço
		if (livre.Count() == 0)
			// não há livres, libertar metade
			LibertarLista();
		
		// utilizar o primeiro livre
		indice[id = livre.Pop()] = { elemento, 1, 1 };
	}
	return id;
}

void CListaNo::LibertarLista() {
	bool jaProcessados = false; // libertar primeiro estados já processados (anteriores a atual)
	// parar assim que existam "limite" estados livres
	completa = false;
	while (livre.Count() < limite) {
		if (!jaProcessados) {
			jaProcessados = true;
			// apagar elementos após o estado inicial
			while (livre.Count() < limite && Proximo(0) != atual)
				LibertarSeguinte(0);
		}
		else {
			int anteriorID = -1, piorID = -1;
			for (int i = atual; ProximoDistinto(i) != 1; i = ProximoDistinto(i)) {
				piorID = ProximoDistinto(i);
				anteriorID = i;
			}
			if (piorID < 0) {
				// valores todos iguais após atual, apagar o seguinte ao atual
				while (livre.Count() < limite)
					LibertarSeguinte(atual);
			}
			else {
				// começar por libertar todos após o primeiro elemento com o pior ID
				while (livre.Count() < limite && Proximo(piorID) != 1)
					LibertarSeguinte(piorID);
				if (livre.Count() < limite) {
					// tem de se eliminar o primeiro elemento com o pior valor
					// o que implica atualizar o proxDistinto de todos os anteriores
					while (Proximo(anteriorID) != piorID) {
						indice[anteriorID].proxDistinto = 1; // último elemento
						anteriorID = Proximo(anteriorID);
					}
					LibertarSeguinte(anteriorID);
				}
				// tudo liberto com este valor, se ainda não é suficiente, seguir para o próximo
			}
		}
	}
}

void CListaNo::LibertarSeguinte(int id) {
	int i = Proximo(id);
	livre.Push(i);
	if (indice[i].estado != NULL) {
		delete indice[i].estado;
		indice[i].estado = NULL;
	}
	indice[id].prox = indice[i].prox;
	indice[id].proxDistinto = indice[i].proxDistinto;
}

// insere por ordem de LB
int CListaNo::Inserir(TNo elemento, int id) {
	int valor, valorI;
	int idNovo = NovoElemento(elemento);
	if (idNovo == 0) {
		// primeiro elemento, inserir um elemento final
		indice.Add({ NULL,-1,-1 });
		return 0;
	}
	valor = Valor(idNovo);
	// atualizar índice
	for (int i = id, j = -1; i >= 0; i = ProximoDistinto(i)) {
		valorI = Valor(i);
		if (valorI == valor) {
			// inserir logo a seguir, já que assim nada mais altera
			indice[idNovo].prox = Proximo(i);
			indice[idNovo].proxDistinto = ProximoDistinto(i);
			indice[i].prox = idNovo;
			return i;
		}
		else if (valorI < valor)
			j = i; // mantem o primeiro elemento anterior
		else { // valor atual já é superior, valor novo
			if (j < 0) { 
				// heurística não consistente, 
				// e agora está a gerar um estado com menor valor que o pai
				// i, novo, i.prox, ...
				// o i fica com o próximo distinto em novo, o que não é verdade mas mais vale assim
				indice[idNovo].prox = Proximo(i);
				indice[idNovo].proxDistinto = Proximo(i);
				indice[i].prox = idNovo;
				indice[i].proxDistinto = idNovo;
				return idNovo;
			}
			else {
				// utilizar o índice de j, anterior, colocando antes de i
				// j, ... , novo, i
				// atualizar o proxDistinto de j, passa a novo
				indice[idNovo].prox = i;
				indice[idNovo].proxDistinto = i;
				while (j != idNovo) {
					indice[j].proxDistinto = idNovo;
					if (Proximo(j) == i || Proximo(j) == j)
						indice[j].prox = idNovo;
					j = Proximo(j);
				}
				return idNovo;
			}
		}
	}
	return 0;
}

// inserir todos os elementos por ordem
void CListaNo::Inserir(TVector<TNo>& elementos) {
	TVector<int> lbElementos, idElementos;
	int id = atual;

	// 1. Ordenar elementos, complexidaded O(N log(N))
	for (int j = 0; j < elementos.Count(); j++)
		lbElementos.Add(elementos[j]->LowerBound());
	lbElementos.Sort(&idElementos);

	// 2. inserir por ordem, tirando partido do local onde já está o último elemento
	for (int j = 0; j < idElementos.Count(); j++) 
		id = Inserir(elementos[idElementos[j]], id);

}


