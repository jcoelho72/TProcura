#pragma once

/**
 * @file   TVector.h
 * @brief  Vetor dinâmico genérico com operações de pilha, conjuntos e algoritmos úteis.
 *
 * A classe TVector implementa um array dinâmico que cresce
 * automaticamente, suporta acesso por índice, inserção, remoção,
 * operações de conjunto (união, interseção, diferença),
 * algoritmos de ordenação, baralhar, distância de edição, entre outros.
 *
 * @tparam Item Tipo dos elementos armazenados no vetor.
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <initializer_list>
#include <cstdarg>   
#include "TRand.h"

 ///////////////////////////////////////////////////////////////////////////////
 // TVector
 ///////////////////////////////////////////////////////////////////////////////

template <class Item>
class TVector
{
private:
	TVector<int>* idx = nullptr;    /**< Vetor de índices auxiliar para ordenação. */
	Item* v = nullptr;				/**< Array interno de elementos. */
	int sz = 0;						/**< Capacidade total do array. */
	int count = 0;					/**< Número atual de elementos. */

	/** Ajusta a capacidade interna para pelo menos @p size elementos. */
	void Size(int size);

	/** Implementação de QuickSort entre as posições @p start e @p end. */
	void QuickSort(int start, int end);

	/** Implementação de insertion sort entre as posições @p start e @p end. */
	void Insertion(int start, int end);

	/** Troca os elementos nas posições @p i e @p j. */
	void Exch(int i, int j) { Item a = v[i]; v[i] = v[j]; v[j] = a; }

	/** QuickSort aplicado ao vetor de índices. */
	void QuickSortIdx(int start, int end);

	/** Troca índices nas posições @p i e @p j do vetor idx. */
	void ExchIdx(int i, int j) { int a = (*idx)[i]; (*idx)[i] = (*idx)[j]; (*idx)[j] = a; }

	/// Retorna o mínimo de dois valores
	static inline int Min(int a, int b) noexcept { return (a < b) ? a : b; }

	/// Retorna o máximo de dois valores
	static inline int Max(int a, int b) noexcept { return (a > b) ? a : b; }

public:
	static Item erro;  /**< Valor retornado em casos de erro (acesso inválido). */

	/// @name Construtores e Destrutor
	///@{
	/** Construtor. Se @p size>0, aloca capacidade inicial. */
	TVector(int size = 0);

	/** Construtor com inicialização de elementos a partir de @p init. */
	TVector(int size, Item const* init);

	/** Destrutor, libera o buffer interno. */
	virtual ~TVector() noexcept;

	///@name Construtores e operadores especiais
	///@{

	/**
	 * @brief Construtor de cópia.
	 * @param o Vetor a copiar.
	 */
	TVector(const TVector& o);

	/**
	 * @brief Operador de atribuição por cópia.
	 * @param o Vetor a atribuir.
	 * @return Referência ao próprio vetor.
	 */
	TVector& operator=(const TVector& o);

	/**
	 * @brief Construtor de movimentação.
	 * @param o Vetor temporário a mover.
	 * @details Transfere o buffer interno sem copiar elementos.
	 */
	TVector(TVector&& o) noexcept;

	/**
	 * @brief Constrói um vetor a partir de uma lista de inicialização.
	 * @param init Lista de elementos a copiar para o vetor.
	 */
	TVector(std::initializer_list<Item> init) {
		Count(static_cast<int>(init.size())); // ajusta capacidade 
		int i = 0;
		for (const auto& val : init)
			v[i++] = val;
	}


	/**
	 * @brief Constrói um vetor de inteiros a partir de uma string no formato de lista.
	 * @param str String com a lista de inteiros ou intervalos.
	 * @details
	 * Sintaxe suportada (sem espaços):
	 * - "A" ou "A,B,C" : valores individuais separados por vírgulas
	 * - "A:B"          : intervalo de A até B (passo 1)
	 * - "A:B:C"        : intervalo de A até B com passo C
	 *
	 * Exemplos:
	 * @code
	 * TVector<int> v("1,3,5");        // {1,3,5}
	 * TVector<int> v("0:10:2,15");    // {0,2,4,6,8,10,15}
	 * @endcode
	 *
	 * - Valores inválidos ou passo <= 0 são ajustados para passo = 1.
	 * - Se A > B, a ordem é invertida.
	 * - Remove duplicados e ordena no final (BeASet()).
	 */
	TVector(const char* str) {}

	/**
	 * @brief Operador de atribuição por movimentação.
	 * @param o Vetor temporário a mover.
	 * @return Referência ao próprio vetor.
	 */
	TVector& operator=(TVector&& o) noexcept;
	///@}


	/**
	 * @brief Concatena outro vetor a este.
	 *
	 * Adiciona todos os elementos de @p o no final deste vetor.
	 *
	 * @param o Vetor cujos elementos serão adicionados.
	 * @return Referência ao próprio vetor.
	 */
	TVector& operator+=(const TVector& o);

	/**
	 * @brief Adiciona múltiplos elementos ao final do vetor.
	 * @param init Lista de elementos a adicionar.
	 * @return Referência ao próprio vetor.
	 */
	TVector& operator+=(std::initializer_list<Item> init) {
		int oldCount = Count();
		Count(oldCount + static_cast<int>(init.size()));
		int i = 0;
		for (const auto& val : init)
			v[oldCount + i++] = val;
		return *this;
	}

	/**
	 * @brief Acrescenta elementos a partir de uma string no formato de lista.
	 * @param str String com a lista de inteiros ou intervalos.
	 * @details
	 * - Apenas disponível para TVector<int>.
	 * - Sintaxe: "A" ou "A,B,C" ou "A:B" ou "A:B:C".
	 * - O parsing e a remoção de duplicados/ordenação são feitos apenas
	 *   dentro da string, não no vetor final.
	 * - Os elementos são adicionados no final, preservando os já existentes.
	 */
	TVector<Item>& operator+=(const char* str) {}

	///@}

	/// @name Acesso a Elementos
	///@{
	/** Adiciona @p a no final do vetor. */
	inline TVector<Item>& Add(Item a) { operator[](count) = a; return *this; }

	/** Insere um elemento @p a na posição @p index, deslocando os seguintes. */
	TVector<Item>& Insert(Item a, int index = 0);

	/** Insere todos os elementos de @p v começando na posição @p index. */
	TVector<Item>& Insert(TVector<Item>& v, int index = 0);

	/** Alias de Add. */
	inline TVector<Item>& Push(Item a) { return Add(a); }

	/** Remove e retorna o último elemento; em vetor vazio retorna @c erro. */
	inline Item& Pop() { return (count > 0 ? v[--count] : TVector<Item>::erro); }

	/**
	 * @brief Acesso por índice com auto-expansão.
	 *
	 * Se @p i é maior ou igual à capacidade interna (@c sz),
	 * realoca o buffer para size = 2 × (i+1).
	 * Se @p i é maior ou igual ao número de elementos (@c count),
	 * ajusta @c count = i+1.
	 *
	 * @param i Índice do elemento a aceder (deve ser ≥ 0).
	 * @return Referência ao elemento interno @c v[i].
	 */
	Item& operator[](int i);

	/**
	 * @brief Acesso constante por índice sem modificação de tamanho.
	 *
	 * Se @p i é inválido (< 0 ou ≥ count), retorna @c erro.
	 *
	 * @param i Índice do elemento (0 ≤ i < count).
	 * @return Const-ref ao elemento @c v[i] ou @c TVector<Item>::erro.
	 */
	const Item& operator[](int i) const;

	/// Acesso direto
	Item* Data() { return v; }
	/// Acesso direto constante
	const Item* Data() const { return v; }

	/** Retorna o primeiro elemento ou @c erro se vazio. */
	inline Item& First() { return (count > 0 ? v[0] : TVector<Item>::erro); }

	/** Retorna o último elemento ou @c erro se vazio. */
	inline Item& Last() { return (count > 0 ? v[count - 1] : TVector<Item>::erro); }

	/** Número de elementos presentes. */
	int Count() const { return count; }

	/** Verifica se o vetor está vazio. */
	virtual bool Empty() const { return (count == 0); }

	/**
	 * @brief Ajusta o tamanho lógico do vetor para @p value.
	 *
	 * Realoca o buffer interno caso @p value exceda a capacidade atual.
	 * Os novos elementos entre a capacidade antiga e @p value não são inicializados.
	 *
	 * @param value Novo número de elementos do vetor.
	 * @return Referência ao próprio vetor (permite encadear chamadas).
	 */
	TVector<Item>& Count(int value)
	{
		if (value > sz)
			Size(value);
		count = value;
		return *this;
	}

	/** Retorna um elemento escolhido aleatoriamente. */
	Item& Random() { return (count > 0 ? operator[](TRand::rand() % count) : TVector<Item>::erro); }
	///@}

	/// @name Operações de Conjunto
	///@{
	/** Remove duplicados e ordena os elementos. */
	TVector<Item>& BeASet();

	/** União com @p v (supõe vetores já em forma de conjunto). */
	TVector<Item>& Union(const TVector<Item>& v);

	/** Interseção com @p v (vetores em conjunto). */
	TVector<Item>& Intersection(const TVector<Item>& v);

	/** Diferença com @p v (vetores em conjunto). */
	TVector<Item>& Difference(const TVector<Item>& v);

	/** Verifica igualdade com @p v (vetores em conjunto e ordenados). */
	bool Equal(const TVector<Item>& v) const;

	/** Verifica se este conjunto está contido em @p v (ordenados). */
	bool Contained(const TVector<Item>& v) const;
	///@}

	/// @name Algoritmos e Modificadores
	///@{
	/** Deleta o elemento na posição @p i. */
	TVector<Item>& Delete(int i);

	/** Remove todas as ocorrências de @p i. */
	TVector<Item>& Remove(Item const& i);

	/** Procura @p i; se @p binary=true faz busca binária em [left,right]. */
	int Find(Item& i, bool binary = false, int left = 0, int right = -1);

	/** Substitui todas ocorrências de @p iold por @p inew. */
	TVector<Item>& Replace(Item const& iold, Item const& inew);

	/** Ordena e, opcionalmente, preenche vetor de índices @p idxvect. */
	TVector<Item>& Sort(TVector<int>* idxvect = nullptr);

	/** Ordena apenas o intervalo [start,end]. */
	void Sort(int start, int end = -1);

	/** Coloca os elementos em ordem aleatória. */
	TVector<Item>& RandomOrder();

	/** Inverte a ordem atual dos elementos. */
	TVector<Item>& Invert();

	/** Preenche todos os elementos com @p i. */
	TVector<Item>& Reset(Item const& i);

	/**
	 * Calcula a distância entre este vetor e @p v.
	 * @param type Tipo de distância:
	 *    - 0: correspondência exata (O(N))
	 *    - 1: distância de desvio (O(N))
	 *    - 2: R-distance (O(N^2))
	 *    - 3: edit distance (O(N^2))
	 */
	int Distance(TVector<Item>& v, int type = 0);
	///@}

	/// @name Iteradores
	///@{
	Item* begin()       noexcept { return v; }
	Item* end()         noexcept { return v + count; }
	const Item* begin() const noexcept { return v; }
	const Item* end()   const noexcept { return v + count; }
	///@}

	/// @name Operadores Adicionais
	///@{
	/** Adiciona elemento @p x ao final (alias de Add). */
	TVector<Item>& operator+=(const Item& x) { return Add(x); }

	/** Remove todas ocorrências de @p x (alias de Remove). */
	TVector<Item>& operator-=(const Item& x) { return Remove(x); }

	/** Concatena dois vetores, retornando o resultado. */
	friend TVector<Item> operator+(TVector<Item> a, const TVector<Item>& b) { a += b; return a; }

	/** Compara igualdade de conjuntos (usando Equal). */
	friend bool operator==(const TVector<Item>& a, const TVector<Item>& b) { return a.Equal(b); }

	/** Compara desigualdade de conjuntos. */
	friend bool operator!=(const TVector<Item>& a, const TVector<Item>& b) { return !a.Equal(b); }
	///@}
};

//----------------------------------------------------------------------------
// instanciação da variável com o conteúdo de erro
//----------------------------------------------------------------------------

/**
 * @brief Valor retornado em casos de acesso inválido.
 * @details Deve ser definido pelo utilizador do template para o tipo @p Item.
 */
template <class Item>
Item TVector<Item>::erro;




//----------------------------------------------------------------------------
// Redimensionamento interno
//----------------------------------------------------------------------------

/**
 * @brief Ajusta a capacidade interna do vetor.
 * @param size Nova capacidade mínima desejada.
 * @details
 *   - Aloca um buffer de tamanho @p size.
 *   - Copia até @c count elementos do buffer antigo.
 *   - Liberta o buffer anterior.
 *   - Atualiza @c sz para o novo valor.
 */
template <class Item>
void TVector<Item>::Size(int size)
{
	if (size <= 0) {
		delete[] v;
		v = nullptr;
		sz = 0;
		return;
	}
	Item* aux = new Item[size];
	if (v != nullptr) {
		int limite = (count < size ? count : size);
		for (int k = limite - 1; k >= 0; --k)
			aux[k] = v[k];
		delete[] v;
	}
	v = aux;
	sz = size;
}


//----------------------------------------------------------------------------
// Construtor com inicialização
//----------------------------------------------------------------------------


/**
 * @brief Construtor.
 * @param size Capacidade inicial do vetor.
 *             Se zero, não aloca buffer até ao primeiro acesso.
 */
template <class Item>
TVector<Item>::TVector(int size)
	: idx(nullptr), v(nullptr), sz(0), count(0)
{
	if (size > 0)
		Size(size);
}


/**
 * @brief Constrói um vetor pré-carregado a partir de um array.
 * @param size Número de elementos a copiar de @p init.
 * @param init Ponteiro para o array de origem.
 * @details
 *   - Se @p size > 0, redimensiona a capacidade via Size().
 *   - Copia cada elemento de @p init para o vetor interno.
 *   - Ajusta @c count para @p size.
 */
template <class Item>
TVector<Item>::TVector(int size, Item const* init)
{
	v = nullptr;
	sz = 0;
	count = 0;
	if (size > 0) {
		Size(size);
		for (int k = 0; k < size; ++k)
			operator[](k) = init[k];
	}
}

/**
 * @brief Destrutor.
 *
 * Liberta o buffer interno alocado para @c v.
 */
template <class Item>
TVector<Item>::~TVector() noexcept
{
	delete[] v;
}


template <class Item>
/**
 * @brief Construtor de cópia.
 * @param o Vetor a copiar.
 */
TVector<Item>::TVector(const TVector<Item>& o)
{
	*this = o;
}

template <class Item>
/**
 * @brief Operador de atribuição por cópia.
 * @param o Vetor a atribuir.
 * @return Referência ao próprio vetor.
 */
TVector<Item>& TVector<Item>::operator=(const TVector<Item>& o)
{
	if (this != &o) {
		// garante capacidade e atualiza count
		Count(o.count);
		// copia elementos
		for (int i = 0; i < o.count; ++i) {
			v[i] = o.v[i];
		}
	}
	return *this;
}

template <class Item>
/**
 * @brief Construtor de movimentação.
 * @param o Vetor temporário a mover.
 * @details Transfere o buffer interno sem cópia de elementos.
 */
TVector<Item>::TVector(TVector<Item>&& o) noexcept
	: v(o.v), sz(o.sz), count(o.count)
{
	o.v = nullptr;
	o.sz = 0;
	o.count = 0;
}

template <class Item>
/**
 * @brief Operador de atribuição por movimentação.
 * @param o Vetor temporário a mover.
 * @return Referência ao próprio vetor.
 */
TVector<Item>& TVector<Item>::operator=(TVector<Item>&& o) noexcept
{
	if (this != &o) {
		delete[] v;
		v = o.v;
		sz = o.sz;
		count = o.count;
		o.v = nullptr;
		o.sz = 0;
		o.count = 0;
	}
	return *this;
}

template <class Item>
/**
 * @brief Concatena outro vetor a este.
 *
 * Adiciona todos os elementos de @p o no final do vetor atual.
 *
 * @param o Vetor cujos elementos serão adicionados.
 * @return Referência ao próprio vetor.
 */
TVector<Item>& TVector<Item>::operator+=(const TVector<Item>& o)
{
	int oldCount = count;
	// ajusta tamanho lógico e realoca se necessário
	Count(oldCount + o.count);
	// copia elementos
	for (int k = 0; k < o.count; ++k) {
		v[oldCount + k] = o.v[k];
	}
	return *this;
}



//----------------------------------------------------------------------------
// Implementação de operator[] para auto-expansão
//----------------------------------------------------------------------------

/**
 * @copybrief TVector::operator[](int)
 */
template <class Item>
Item& TVector<Item>::operator[](int i)
{
	if (i >= sz)
		Size(2 * (i + 1));

	if (i >= count)
		count = i + 1;

	return v[i];
}


/**
 * @copybrief TVector::operator[](int) const
 */
template <class Item>
const Item& TVector<Item>::operator[](int i) const
{
	if (i < 0 || i >= count)
		return TVector<Item>::erro;

	return v[i];
}

//----------------------------------------------------------------------------
// Pesquisa de elementos
//----------------------------------------------------------------------------

/**
 * @brief Procura um elemento no vetor.
 * @param i      Referência ao item a procurar.
 * @param binary Se true, faz busca binária (vetor deve estar ordenado).
 * @param left   Índice inicial da busca binária (opcional).
 * @param right  Índice final da busca binária (opcional).
 * @return Índice do elemento se encontrado, ou -1 caso contrário.
 */
template <class Item>
int TVector<Item>::Find(Item& i, bool binary, int left, int right)
{
	if (binary) {
		if (right < 0 || right > count - 1) right = count - 1;
		if (left  < 0 || left  > right)    left = 0;
		while (left <= right) {
			int mid = (left + right) >> 1;
			if (v[mid] == i) return mid;
			if (v[mid] < i) left = mid + 1;
			else              right = mid - 1;
		}
	}
	else {
		for (int k = 0; k < count; ++k)
			if (v[k] == i)
				return k;
	}
	return -1;
}

//----------------------------------------------------------------------------
// Ordenação
//----------------------------------------------------------------------------

/**
 * @brief Ordena todo o vetor, opcionalmente devolvendo índices ordenados.
 * @param idxvect Se não nulo, recebe um vetor de índices ordenados em vez de ordenar os elementos.
 * @return Referência ao próprio vetor (permite encadeamento).
 */
template <class Item>
TVector<Item>& TVector<Item>::Sort(TVector<int>* idxvect)
{
	if (idxvect == nullptr) {
		QuickSort(0, count - 1);
		Insertion(0, count - 1);
	}
	else {
		idx = idxvect;
		idx->Count(count);
		for (int k = 0; k < count; ++k)
			(*idx)[k] = k;
		QuickSortIdx(0, count - 1);
	}
	return *this;
}


/**
 * @brief Ordena um subintervalo [start,end] do vetor.
 * @param start Índice inicial (será ajustado a 0 se negativo).
 * @param end   Índice final (será ajustado a count-1 se inválido).
 */
template <class Item>
void TVector<Item>::Sort(int start, int end)
{
	if (end > count - 1 || end < 0) end = count - 1;
	if (start < 0)                  start = 0;
	if (start < end) {
		QuickSort(start, end);
		Insertion(start, end);
	}
}


/**
 * @brief Particiona recursivamente via QuickSort.
 * @param start Índice inicial do segmento a ordenar.
 * @param end   Índice final do segmento a ordenar.
 * @details Combina QuickSort para partição e Insertion Sort para segmentos pequenos.
 */
template <class Item>
void TVector<Item>::QuickSort(int start, int end)
{
	if (end - start > 32) {
		// pivôs median-of-three
		Exch((start + end) >> 1, end - 1);
		if (v[end - 1] < v[start]) Exch(end - 1, start);
		if (v[end] < v[start]) Exch(end, start);
		if (v[end] < v[end - 1]) Exch(end, end - 1);

		start++; end--;

		// partição
		int i = start - 1, j = end;
		Item pivot = v[end];
		for (;;) {
			while (v[++i] < pivot);
			while (pivot < v[--j] && j > start);
			if (i >= j) break;
			Exch(i, j);
		}
		Exch(i, end);

		QuickSort(start - 1, i - 1);
		QuickSort(i + 1, end + 1);
	}
}


/**
 * @brief Realiza Insertion Sort num segmento.
 * @param start Índice inicial.
 * @param end   Índice final.
 */
template <class Item>
void TVector<Item>::Insertion(int start, int end)
{
	for (int i = end; i > start; --i)
		if (v[i - 1] > v[i])
			Exch(i - 1, i);

	for (int i = start + 2; i <= end; ++i) {
		Item tmp = v[i];
		int j = i;
		while (tmp < v[j - 1]) {
			v[j] = v[j - 1];
			--j;
		}
		v[j] = tmp;
	}
}



/**
 * @brief QuickSort aplicado ao vetor de índices.
 * @param start Índice inicial.
 * @param end   Índice final.
 */
template <class Item>
void TVector<Item>::QuickSortIdx(int start, int end)
{
	if (end - start < 3) {
		// pequenos casos
		if (end - start == 1) {
			if (v[(*idx)[end]] < v[(*idx)[start]])
				ExchIdx(end, start);
		}
		else if (end - start == 2) {
			if (v[(*idx)[end - 1]] < v[(*idx)[start]])
				ExchIdx(end - 1, start);
			if (v[(*idx)[end]] < v[(*idx)[start]])
				ExchIdx(end, start);
			if (v[(*idx)[end]] < v[(*idx)[end - 1]])
				ExchIdx(end, end - 1);
		}
	}
	else {
		// pivôs median-of-three em idx
		ExchIdx((start + end) >> 1, end - 1);
		if (v[(*idx)[end - 1]] < v[(*idx)[start]])
			ExchIdx(end - 1, start);
		if (v[(*idx)[end]] < v[(*idx)[start]])
			ExchIdx(end, start);
		if (v[(*idx)[end]] < v[(*idx)[end - 1]])
			ExchIdx(end, end - 1);

		start++; end--;

		// partição em idx
		int i = start - 1, j = end;
		Item pivot = v[(*idx)[end]];
		for (;;) {
			while (v[(*idx)[++i]] < pivot);
			while (pivot < v[(*idx)[--j]] && j > start);
			if (i >= j) break;
			ExchIdx(i, j);
		}
		ExchIdx(i, end);

		if (i > start)         QuickSortIdx(start - 1, i - 1);
		if (i < end)           QuickSortIdx(i + 1, end + 1);
	}
}


//----------------------------------------------------------------------------
// Baralhar
//----------------------------------------------------------------------------

/**
 * @brief Coloca os elementos em ordem aleatória (Fisher–Yates shuffle).
 * @return Referência ao próprio vetor.
 */
template <class Item>
TVector<Item>& TVector<Item>::RandomOrder()
{
	for (int k = count - 1; k > 0; --k)
		Exch(k, TRand::rand() % (k + 1));
	return *this;
}

/**
 * @brief Remove todas as ocorrências de um dado elemento.
 * @param i Referência ao elemento a remover.
 * @return Referência ao próprio vetor (permite encadear chamadas).
 */
template <class Item>
TVector<Item>& TVector<Item>::Remove(const Item& i)
{
	int k = 0;
	for (int w = 0; w < count; ++w) {
		if (v[w] != i) {
			v[k++] = v[w];
		}
	}
	count = k;
	return *this;
}


/**
 * @brief Preenche todo o vetor com um mesmo valor.
 * @param i Valor a atribuir a cada posição.
 * @return Referência ao próprio vetor.
 */
template <class Item>
TVector<Item>& TVector<Item>::Reset(const Item& i)
{
	for (int j = 0; j < count; ++j) {
		v[j] = i;
	}
	return *this;
}


/**
 * @brief Substitui todas as ocorrências de um valor antigo por um novo.
 * @param iold Valor a ser substituído.
 * @param inew Novo valor que substitui @p iold.
 * @return Referência ao próprio vetor.
 */
template <class Item>
TVector<Item>& TVector<Item>::Replace(const Item& iold, const Item& inew)
{
	for (int k = 0; k < count; ++k) {
		if (v[k] == iold) {
			v[k] = inew;
		}
	}
	return *this;
}


/**
 * @brief Remove o elemento na posição @p i deslocando os seguintes.
 * @param i Índice do elemento a eliminar (0 ≤ i < count).
 * @return Referência ao próprio vetor.
 */
template <class Item>
TVector<Item>& TVector<Item>::Delete(int i)
{
	for (int k = i; k < count - 1; ++k) {
		v[k] = v[k + 1];
	}
	--count;
	return *this;
}


/**
 * @brief Converte o vetor num conjunto: remove duplicados e ordena.
 * @details
 *   - Ordena o vetor completo.
 *   - Percorre e elimina valores consecutivos iguais.
 *   - Atualiza @c count para o novo número de elementos.
 * @return Referência ao próprio vetor.
 */
template <class Item>
TVector<Item>& TVector<Item>::BeASet()
{
	if (count > 0) {
		Sort();
		int k = 0, w = 1;
		while (w < count) {
			if (v[k] != v[w]) {
				v[++k] = v[w];
			}
			++w;
		}
		count = k + 1;
	}
	return *this;
}


/**
 * @brief Realiza a união deste conjunto com outro.
 * @param other Conjunto a unir (deve estar ordenado e sem duplicados).
 * @return Referência ao próprio vetor já representando a união.
 */
template <class Item>
TVector<Item>& TVector<Item>::Union(const TVector<Item>& other)
{
	int k = 0, w = 0, s = Count();
	while (k < other.Count()) {
		while (w < s && operator[](w) < other[k]) {
			++w;
		}
		if (w >= s || operator[](w) > other[k]) {
			Add(other[k++]);
		}
		else {
			++k;
		}
	}
	Sort();
	return *this;
}


/**
 * @brief Interseção deste conjunto com outro.
 * @param other Conjunto contra o qual intersectar (ordenado).
 * @return Referência ao próprio vetor já representando a interseção.
 */
template <class Item>
TVector<Item>& TVector<Item>::Intersection(const TVector<Item>& other)
{
	int k = 0, w = 0, z = 0;
	while (k < other.Count() && w < Count()) {
		if (operator[](w) < other[k]) {
			++w;
		}
		else if (operator[](w) == other[k]) {
			v[z++] = v[w++];
			++k;
		}
		else {
			++k;
		}
	}
	Count(z);
	return *this;
}


/**
 * @brief Diferença deste conjunto em relação a outro.
 * @param other Conjunto cujos elementos serão subtraídos.
 * @return Referência ao próprio vetor já representando a diferença.
 */
template <class Item>
TVector<Item>& TVector<Item>::Difference(const TVector<Item>& other)
{
	int k = 0, w = 0, z = 0;
	while (k < other.Count() && w < Count()) {
		if (v[w] < other[k]) {
			v[z++] = v[w++];
		}
		else if (v[w] == other[k]) {
			++w; ++k;
		}
		else {
			++k;
		}
	}
	while (w < Count()) {
		v[z++] = v[w++];
	}
	Count(z);
	return *this;
}

/**
 * @brief Verifica se dois vetores-conjunto são iguais.
 * @param other Outro vetor a comparar (deve estar ordenado e sem duplicados).
 * @return true se tamanhos e elementos coincidem; false caso contrário.
 */
template <class Item>
bool TVector<Item>::Equal(const TVector<Item>& other) const
{
	if (count != other.Count()) return false;
	for (int k = 0; k < count; ++k) {
		if (v[k] != other[k]) return false;
	}
	return true;
}


/**
 * @brief Verifica se este conjunto está contido no outro.
 * @param other Conjunto suposto “contedor” (ordenado).
 * @return true se todos os elementos deste vetor aparecem em @p other.
 */
template <class Item>
bool TVector<Item>::Contained(const TVector<Item>& other) const
{
	if (count > other.Count()) return false;
	int k2 = 0;
	for (int k = 0; k < count; ++k) {
		while (k2 < other.Count() && v[k2] < v[k]) {
			++k2;
		}
		if (k2 >= other.Count() || other[k2] != v[k]) {
			return false;
		}
	}
	return true;
}


/**
 * @brief Insere um vetor de itens na posição indicada.
 * @param src   Vetor cujos elementos serão inseridos.
 * @param index Índice onde começa a inserção (defaults to end if <0).
 * @return Referência ao próprio vetor após inserção.
 */
template <class Item>
TVector<Item>& TVector<Item>::Insert(TVector<Item>& src, int index)
{
	if (index < 0) index = Count();
	int w = src.Count();
	if (w > 0) {
		int oldCount = Count();
		Count(oldCount + w);
		if (index > oldCount) index = oldCount;
		for (int k = oldCount - 1; k >= index; --k) {
			v[k + w] = v[k];
		}
		for (int k = 0; k < w; ++k) {
			v[index + k] = src[k];
		}
	}
	return *this;
}


/**
 * @brief Insere um único elemento na posição indicada.
 * @param a     Elemento a inserir.
 * @param index Índice de inserção (defaults to end if <0).
 * @return Referência ao próprio vetor após inserção.
 */
template <class Item>
TVector<Item>& TVector<Item>::Insert(Item a, int index)
{
	if (index < 0) index = Count();
	int oldCount = Count();
	Count(oldCount + 1);
	if (index > oldCount) index = oldCount;
	for (int k = oldCount - 1; k >= index; --k) {
		v[k + 1] = v[k];
	}
	v[index] = a;
	return *this;
}

/**
 * @brief Inverte a ordem dos elementos no vetor.
 * @return Referência ao próprio vetor.
 */
template <class Item>
TVector<Item>& TVector<Item>::Invert()
{
	for (int k = 0; k < count / 2; ++k) {
		Exch(k, count - 1 - k);
	}
	return *this;
}


/**
 * @brief Calcula várias métricas de “distância” entre vetores.
 * @param other Outro vetor para comparação.
 * @param type  Tipo de métrica:
 *    - 0: diferença exata de posições (O(N))
 *    - 1: soma de desvios absolutos (O(N))
 *    - 2: R-type distance (O(N²))
 *    - 3: edit distance (Levenshtein) (O(N²))
 * @return Valor inteiro representando a distância.
 */
template <class Item>
int TVector<Item>::Distance(TVector<Item>& other, int type)
{
	int result = 0;
	int n1 = Count(), n2 = other.Count();

	if (type == 0) {
		result = abs(n1 - n2);
		int m = Min(n1, n2);
		for (int i = 0; i < m; ++i) {
			if (v[i] != other[i]) ++result;
		}
	}
	else if (type == 1) {
		int m = Min(n1, n2);
		for (int i = 0; i < m; ++i) {
			result += abs(v[i] - other[i]);
		}
	}
	else if (type == 2) {
		result = Max(n1, n2);
		for (int i = 0; i + 1 < n1; ++i) {
			int j = other.Find(v[i]);
			if (j >= 0 && j + 1 < n2 && v[i + 1] == other[j + 1]) {
				--result;
			}
		}
	}
	else if (type == 3) {
		int rows = n1 + 1, cols = n2 + 1;
		TVector<int> mtx(rows * cols);
		// inicialização da matriz
		for (int i = 0; i < rows; ++i) mtx[i] = i;
		for (int j = 1; j < cols; ++j) mtx[j * rows] = j;
		// cálculo da distância de edição
		for (int i = 1; i < rows; ++i) {
			for (int j = 1; j < cols; ++j) {
				int cost = (v[i - 1] == other[j - 1] ? 0 : 1);
				int val = mtx[(i - 1) + rows * (j - 1)] + cost;
				val = Min(val, mtx[(i - 1) + rows * j] + 1);
				val = Min(val, mtx[i + rows * (j - 1)] + 1);
				mtx[i + rows * j] = val;
			}
		}
		result = mtx[n1 + rows * n2];
	}

	return result;
}


class TString : public TVector<char> {
public:
	using TVector<char>::TVector; // herdar construtores

	TString() {
		Count(1);
		Data()[0] = 0;
	}

	// construtor a partir de const char*
	TString(const char* s) {
		if (!s) {
			Count(1);
			Data()[0] = 0;
			return;
		}
		int n = (int)strlen(s);
		Count(n + 1);
		memcpy(Data(), s, n + 1);
		Last() = 0;
	}

	// conversão implícita para const char*
	operator const char* () const noexcept {
		return Data();
	}

	// devolve const char* de forma curta:
	// em vez de printf("%s",(const char*)nome); basta printf("%s",*nome);
	const char* operator*() const noexcept {
		return Data();
	}

	// printf, adiciona o texto formatado à string atual
	TString& printf(const char* fmt, ...) {
		// calcular tamanho necessário
		va_list args;
		va_start(args, fmt);
		int needed = vsnprintf(nullptr, 0, fmt, args);
		va_end(args);

		if (needed < 0)
			return *this;

		// remover o '\0' anterior
		Pop();
		int old = Count();

		// expandir para conter o novo texto + '\0'
		Count(Count() + needed + 1);

		// escrever no fim
		va_start(args, fmt);
		vsnprintf(Data() + old, needed + 1, fmt, args);
		va_end(args);

		return *this;
	}

	// concatenação com outra TString
	TString& operator+=(const TString& other) {
		Pop(); // remover '\0'
		TVector<char>::operator+=(other);
		Last() = 0;
		return *this;
	}

	/** Verifica se a string é vazia. */
	bool Empty() const { return (Count() <= 1); }

	// tokenização: divide a string em partes usando os delimitadores fornecidos
	TVector<TString> tok(const char* delim = " \t\n\r") const {
		TVector<TString> out;
		const char* s = Data();
		int n = Count();
		int i = 0;
		while (i < n) {
			// saltar delimitadores
			while (i < n && strchr(delim, s[i]))
				i++;

			if (i >= n || s[i] == 0)
				break;

			int start = i;

			// avançar até próximo delimitador
			while (i < n && s[i] != 0 && !strchr(delim, s[i]))
				i++;

			// extrair token
			int len = i - start;
			TString tok;
			tok.Count(len + 1);
			memcpy(tok.Data(), s + start, len);
			tok[len] = 0;

			out += tok;
		}

		return out;
	}


};

template<>
inline TVector<int>::TVector(const char* str) {
	TString buffer(str);
	char* token = buffer.Data();
	char* pt;
	if (!str || *str == '\0')
		return;

	// separar por vírgulas
	if ((pt = strchr(token, ','))) {
		*pt = 0;
		*this = TVector(token);
		do {
			token = pt + 1;
			if ((pt = strchr(token, ',')))
				*pt = 0;
			*this += TVector(token);
		} while (pt);
	}
	else {
		// procurar por : (intervalo)
		if ((pt = strchr(token, ':'))) {
			char* pt2;
			*pt = 0;
			int A = atoi(token);
			int C = 1;
			if ((pt2 = strchr(pt + 1, ':'))) { // A:B:C
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
				*this += i;
		}
		else // inteiro apenas
			*this += atoi(token);
	}
	BeASet();
}

template<>
inline TVector<int>& TVector<int>::operator+=(const char* str) {
	*this += TVector<int>(str);
	return *this;
}

// permite fazer for(auto x : _TV("1:10,15:50:3,73")) printf("%d ", x);
inline TVector<int> _TV(const char* str) {
	return TVector<int>(str);
}

