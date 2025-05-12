// TVector.h: interface for the TVector class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TVECTOR_H__7E674C3E_074D_4F78_8839_D28D9BAD66FD__INCLUDED_)
#define AFX_TVECTOR_H__7E674C3E_074D_4F78_8839_D28D9BAD66FD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#include <stdlib.h>
#include "TRand.h"


///////////////////////////////////////////////////////////////////////////////
//	TVector class
///////////////////////////////////////////////////////////////////////////////
//	Author: Jose Coelho
//	Last revision: 2007-04-17
//	Description: template vector class, to avoid the need to alloc/dealloc arrays
///////////////////////////////////////////////////////////////////////////////


template <class Item>
class TVector
{
private:
	TVector<int> *idx;
	Item *v;
	int sz,count;
	void Size(int size);
	// sort methods in vector
	void QuickSort(int start,int end);
	void Insertion(int start, int end);
	void Exch(int i, int j) { Item a=v[i]; v[i]=v[j]; v[j]=a; }
	// sort methods in index vector
	void QuickSortIdx(int start,int end);
	void ExchIdx(int i, int j) { int a=(*idx)[i]; (*idx)[i]=(*idx)[j]; (*idx)[j]=a; }
public:



	// ****************** alteração JM **************//
	static Item erro;
	// **********************************************//

	// constructors
	TVector(int size = 0) { v = NULL; idx = NULL; count = sz = 0; if (size > 0) Size(size); }
	TVector(int size,Item const *init);
	virtual ~TVector();

	// access methods
	inline void Add(Item a) { operator[](count)=a; } // O(1) - add an item in the end of the vector
	void Insert(Item a,int index=0); // O(N) - insert an element a at index
	TVector<Item>& Insert(TVector<Item>&v,int index=0); // O(N) - insert elements of v starting at index

	// 2007/04/17: push is the same as Add method
	inline void Push(Item a) { Add(a); }
	// 2007/04/17: pop is the same as Last(), but the element returned is removed from the vector
	inline Item& Pop() { if(count>0) return v[--count]; else { return TVector<Item>::erro; } }

	Item& operator[](int i) { // O(1) - acess operator
		if(i>=sz) Size(2*(i+1)); // duplicate the size used each time that need increase
		if(i>=count) count=i+1;
		return v[i];
	}
	inline Item& First() { if(count>0) return v[0]; else { return TVector<Item>::erro; } } // O(1) - first element of the vector (2007/04/17: added extra check)
	inline Item& Last() { if(count>0) return v[count-1]; else { return TVector<Item>::erro; } } // O(1) - last element of the vector (2007/04/17: added extra check)
	int Count() { return count; } // O(1) - return the number of elements in the vector
	void Count(int value) { // O(N) - set the vector to a fixed size (the elements are not initializated)
		if(value>=sz) Size(value);
		count=value;
	}
	// 2007/04/17: return an element at random
	Item& Random() { if(count>0) return operator[](TRand::rand()%count); else { return TVector<Item>::erro; } }

	// vector methods
	TVector<Item>& operator=(TVector<Item>&v); // O(N) - reset this vector to vector v
	TVector<Item>& operator+=(TVector<Item>&v); // O(N) - add vector v to this vector

	// set methods
	TVector<Item>& BeASet(); // remove duplicates and sort
	TVector<Item>& Union(TVector<Item>&v); // join elements of two sets
	TVector<Item>& Intersection(TVector<Item>&v); // intersects elements of two sets
	TVector<Item>& Difference(TVector<Item>&v); // subtract the elements of v (bug fixed in 2007/03/26)
	bool Equal(TVector<Item>&v); // return true if v is equal (assume sorted elements)
	bool Contained(TVector<Item>&v); // return true if it is contained in v or equal (assume sorted elements)

	// operations methods
	void Delete(int i); // O(N) - delete item i
	void Remove(Item const &i); // O(N) - remove all itens i
	int Find(Item &i,bool binary=false,int left=0,int right=-1); // return -1 if item not found (note: use binary sort only if itens are sorted)
	void Replace(Item const &iold,Item const &inew); // O(N) - replace iold by inew
	void Sort(TVector<int>*idxvect=NULL); // O(N.log(N)) - sort idx and not the vector (bug fixed in 2006/06/04)
	void Sort(int start,int end=-1); // sort only from start to end
    void RandomOrder(); // O(N) - put the actual vector in an random order
	void Invert(); // O(N) - invert the current element order
	void Reset(Item const &i); // O(N) - reset all itens to i
	int Distance(TVector<Item>&v,int type=0); // distance types: 0 - exact match - O(N); 1 - deviation distance - O(N); 2 - R-type distance - O(N^2); 3 - edit distance - O(N^2)
};
// O(N)

// **** JM 29/03/2018 *******
template <class Item>
Item TVector<Item>::erro;
// **************************

template <class Item>
void TVector<Item>::Size(int size)
{
	Item *aux=new Item[size];
	if(v!=NULL) {
		for(int k=0;k<count;k++)
			aux[k]=v[k];
		delete [] v;
	}
	v=aux;
	sz=size;
}

template <class Item>
TVector<Item>::TVector(int size,Item const *init)
{
	int k;
	v=NULL;
	count=sz=0;
	if(size>0) {
		Size(size);
		for(k=0;k<size;k++)
			operator[](k)=init[k];
	}
}

template <class Item>
TVector<Item>::~TVector() {
	if(v!=NULL) delete [] v;
}


/////////////////////////////////////////////////////////////////
// Searching
/////////////////////////////////////////////////////////////////

template <class Item>
int TVector<Item>::Find(Item &i,bool binary, int left, int right)
{
	if(binary) {
		if(right<0 || right>count-1) right=count-1;
		if(left<0 || left>right) left=0;
		int mid;

		while(left<=right) {
			mid=(left+right)>>1;
			if(v[mid]==i) return mid;
			if(v[mid]<i) left=mid+1;
			else right=mid-1;
		}
	} else {
		for(int k=0;k<count;k++)
			if(v[k]==i)
				return k;
	}
	return -1;
}

/////////////////////////////////////////////////////////////////
// Sorting
/////////////////////////////////////////////////////////////////

template <class Item>
void TVector<Item>::Sort(TVector<int>*idxvect) // quicksort & insertion
{
	if(idxvect==NULL) { // just sort this vector
		QuickSort(0,count-1); // make numbers more or less sorted
		Insertion(0,count-1); // finish sort
		// for integer numbers it takes about 1.5 seconds for 10^6 random numbers
		// performance ok for already sorted sequences
	} else { // sort the index
		idx=idxvect;
		idx->Count(count);
		for(int k=0;k<count;k++)
			(*idx)[k]=k;
		QuickSortIdx(0,count-1);
	}
}

template <class Item>
void TVector<Item>::Sort(int start,int end) // sort only from start to end
{
	if(end>count-1 || end<0) end=count-1;
	if(start<0) start=0;
	if(start<end) {
		QuickSort(start,end); // make numbers more or less sorted
		Insertion(start,end); // finish sort
	}
}


template <class Item>
void TVector<Item>::QuickSort(int start,int end) // quicksort
{
	if(end-start>32) { // otherwise left work to insertion sort
		Exch((start+end)>>1,end-1); // the middle element next to the end
		// sort the three elements
		if(v[end-1]<v[start]) Exch(end-1,start);
		if(v[end]<v[start]) Exch(end,start);
		if(v[end]<v[end-1]) Exch(end,end-1);

		// v[start] will be for sure less or equal than v[end-1]
		// v[end] will be for sure greater or equal than v[end-1]
		start++; end--;

		// partition
		int i=start-1,j=end;
		Item a=v[end];
		for(;;) {
			while(v[++i]<a);
			while(a<v[--j] && j>start);
			if(i>=j) break;
			Exch(i,j);
		}
		Exch(i,end);

		QuickSort(start-1,i-1);
		QuickSort(i+1,end+1);
	} //else Insertion(start,end);
}

template <class Item>
void TVector<Item>::Insertion(int start,int end) // insertion sort
{
	int i;
	for(i=end; i>start; i--)
		if(v[i-1]>v[i])
			Exch(i-1,i);

	for(i=start+2; i<=end; i++) {
		int j=i;
		Item a=v[i];
		while(a<v[j-1]) {
			v[j]=v[j-1];
			j--;
		}
		v[j]=a;
	}
}

template <class Item>
void TVector<Item>::QuickSortIdx(int start,int end) // quicksort
{
	if(end-start<3) { // few elements
		if(end-start==1) { // two elements
			if(v[(*idx)[end]]<v[(*idx)[start]]) ExchIdx(end,start);
		} else if(end-start==2) { // three elements
			if(v[(*idx)[end-1]]<v[(*idx)[start]]) ExchIdx(end-1,start);
			if(v[(*idx)[end]]<v[(*idx)[start]]) ExchIdx(end,start);
			if(v[(*idx)[end]]<v[(*idx)[end-1]]) ExchIdx(end,end-1);
		}
	} else { // otherwise is sorted
		ExchIdx((start+end)>>1,end-1); // the middle element next to the end
		// sort the three elements
		if(v[(*idx)[end-1]]<v[(*idx)[start]]) ExchIdx(end-1,start);
		if(v[(*idx)[end]]<v[(*idx)[start]]) ExchIdx(end,start);
		if(v[(*idx)[end]]<v[(*idx)[end-1]]) ExchIdx(end,end-1);

		// v[start] will be for sure less or equal than v[end-1]
		// v[end] will be for sure greater or equal than v[end-1]
		start++; end--;

		// partition
		int i=start-1,j=end;
		Item a=v[(*idx)[end]];
		for(;;) {
			while(v[(*idx)[++i]]<a);
			while(a<v[(*idx)[--j]] && j>start);
			if(i>=j) break;
			ExchIdx(i,j);
		}
		ExchIdx(i,end);

		if(i>start)	QuickSortIdx(start-1,i-1);
		if(i<end) QuickSortIdx(i+1,end+1);
	}
}

// O(N)
template <class Item>
void TVector<Item>::RandomOrder() // put the vector in an random order
{
    for(int k=count-1;k>0;k--) // select a random possition to k
        Exch(k,TRand::rand()%(k+1));
}

// O(N)
template <class Item>
void TVector<Item>::Remove(Item const &i)
{
	int k,w;
	for(w=0,k=0;w<count;w++) { // O(N)
		if(k!=w) v[k]=v[w];
		if(v[w]!=i) k++;
	}
	count=k;
}

// O(N)
template <class Item>
void TVector<Item>::Reset(Item const &i)
{
	for(int j=0;j<count;j++)
		v[j]=i;
}

// O(N)
template <class Item>
void TVector<Item>::Replace(Item const &iold,Item const &inew)
{
	for(int k=0;k<count;k++)
		if(v[k]==iold)  // O(N)
			v[k]=inew;
}

// O(N)
template <class Item>
void TVector<Item>::Delete(int i)
{
	int k;
	for(k=i;k<count-1;k++) { // O(N)
		v[k]=v[k+1];
	}
	count--;
}

// O(N)
template <class Item>
TVector<Item>& TVector<Item>::operator=(TVector<Item>&v)
{
	int k;
	Count(v.Count());
	for(k=v.Count()-1;k>=0;k--)
		operator[](k)=v[k];
	return *this;
}

// O(N)
template <class Item>
TVector<Item>& TVector<Item>::operator+=(TVector<Item>&v)
{
	int k,w;
	w=Count();
	Count(w+v.Count());
	for(k=v.Count()-1;k>=0;k--)
		operator[](w+k)=v[k];
	return *this;
}

// set methods
template <class Item>
TVector<Item>& TVector<Item>::BeASet() { // remove duplicates and sort

	if(count>0) {
		Sort();

		// remove duplicates
		int k=0,w=1;

		while(true) {
			while(w<count && v[k]==v[w]) w++; // move w to the next different position
			if(w>=count) break;
			k++;
			if(k!=w) v[k]=v[w];
		}

		count=k+1;
	}

	return *this;
}

template <class Item>
TVector<Item>& TVector<Item>::Union(TVector<Item>&v) { // join elements of two sets
	int k=0,w=0,s=Count();
	while(k<v.Count()) {
		while(w<s && operator[](w)<v[k]) w++; // see if v[k] is in the vector
		if(w>=s || operator[](w)>v[k]) // not there
			Add(v[k++]); // add v[k]
		else k++; // already there, next k
	}
	Sort();

	return *this;
}

template <class Item>
TVector<Item>& TVector<Item>::Intersection(TVector<Item>&v) { // intersects elements of two sets
	int k=0,w=0,z=0;
	while(k<v.Count()) {
		while(w<Count() && operator[](w)<v[k]) w++; // see if v[k] is in the vector
		if(w>=Count()) break;
		if(operator[](w)==v[k++]) // keep element, any case go for next k
			operator[](z++)=operator[](w++);
	}
	Count(z);

	return *this;
}

// bug found in 2007/03/26
template <class Item>
TVector<Item>& TVector<Item>::Difference(TVector<Item>&v) { // subtract the elements of v
	int k=0,w=0,z=0;
	while(k<v.Count()) { // process all elements of v
		while(w<Count() && operator[](w)<v[k])   // w - process all elements of this vector
			// not in v, keep element
			if(z!=w) operator[](z++)=operator[](w++);
			else { z++; w++; }
		if(w>=Count()) break;
		k++; // next element of v
		w++; // this w is not inserted, skip
	}
	// copy the rest of the elements, not in v
	while(w<Count())
		if(z!=w) operator[](z++)=operator[](w++);
		else { z++; w++; }

	// reset the size of the vector
	Count(z);

	return *this;
}

// O(N)
template <class Item>
bool TVector<Item>::Equal(TVector<Item>&v) { // return true if v is equal (assume sorted elements)
	if(count==v.Count()) {
		int k;
		for(k=0;k<count && operator[](k)==v[k];k++);
		return k==count;
	}
	return false;
}

// O(N)
template <class Item>
bool TVector<Item>::Contained(TVector<Item>&v) { // return true if it is contained in v or equal (assume sorted elements)
	if(count<=v.Count()) {
		int k,k2;
		for(k=0,k2=0;k<count && k2<v.Count();k++)
			while(k2<v.Count() && operator[](k)!=v[k2]) k2++;
		return k==count;
	}
	return false;
}


// O(N)
template <class Item>
TVector<Item>& TVector<Item>::Insert(TVector<Item>&v,int index) { // insert elements of v starting at index
	int k,z,w;
	if(index<0) index=Count();
	if((w=v.Count()) > 0) {
		z=Count();
		Count(Count()+w);
		if(index>z) index=z;
		// move all elements after index
		for(k=z-1;k>=index;k--)
			operator[](k+w)=operator[](k);
		// copy elements of vector into this one
		for(k=index;k<index+w;k++)
			operator[](k)=v.operator[](k-index);
	}
	return *this;
}

// O(N)
template <class Item>
void TVector<Item>::Insert(Item a,int index) { // insert an element a at index
	int k,z;
	if(index<0) index=Count();

	z=Count();
	Count(Count()+1);
	if(index>z) index=z;

	// move all elements after index
	for(k=z-1;k>=index;k--)
		operator[](k+1)=operator[](k);
	// copy element into this position
	operator[](index)=a;
}

// O(N)
template <class Item>
void TVector<Item>::Invert() { // invert the current order
	if(count>1)
		for(int k=count/2-1;k>=0;k--)
			Exch(k,count-1-k);
}

template <class Item>
int TVector<Item>::Distance(TVector<Item>&v,int type) {
	int result=0;
	if(type==0) { // 0 - exact match - O(N)
		result=abs(Count()-v.Count());
		for(int i=(Count()<v.Count()?Count():v.Count())-1;i>=0;i--)
			if(!((*this)[i]==v[i])) // use only the operator ==
				result++;
	} else if(type==1) { // 1 - deviation distance - O(N)
		for(int i=(Count()<v.Count()?Count():v.Count())-1;i>=0;i--)
			result+=abs((*this)[i]-v[i]);
	} else if(type==2) { // 2 - R-type distance - O(N^2)
		result=(Count()>v.Count()?Count():v.Count());
		for(int i=0;i<Count()-1;i++) {
			int j=v.Find((*this)[i]);
			if(j>=0 && j<v.Count()-1 && (*this)[i+1]==v[j+1])
				result--;
		}
	} else if(type==3) { // 3 - edit distance  - O(N^2)
/*		Base algorithm:
		m[i,j] = d(s1[1..i], s2[1..j])
		m[0,0] = 0
		m[i,0] = i,  i=1..|s1|
		m[0,j] = j,  j=1..|s2|
		m[i,j] = min(m[i-1,j-1] + if s1[i]=s2[j] then 0 else 1 fi,
					 m[i-1, j] + 1,
					 m[i, j-1] + 1 ),  i=1..|s1|, j=1..|s2|
*/
		int n1=Count()+1,n2=v.Count()+1;
		TVector<int> m(n1*n2);
		// m[0,0] = 0
		m[0+n1*0]=0;
		// m[i,0] = i,  i=1..|s1|
		for(int i=1;i<n1;i++)
			m[i+n1*0]=i;
		// m[0,j] = j,  j=1..|s2|
		for(int j=1;j<n2;j++)
			m[0+n1*j]=j;
		for(int i=1;i<n1;i++)
			for(int j=1;j<n2;j++) {
				// min:
				// m[i-1,j-1] + if s1[i]=s2[j] then 0 else 1 fi,
				m[i+n1*j]=m[i-1+n1*(j-1)];
				if(!((*this)[i-1]==v[j-1]))
					m[i+n1*j]++;
				// m[i-1, j] + 1
				if(m[i+n1*j]>m[i-1+n1*j]+1)
					m[i+n1*j]=m[i-1+n1*j]+1;
				// m[i, j-1] + 1
				if(m[i+n1*j]>m[i+n1*(j-1)]+1)
					m[i+n1*j]=m[i+n1*(j-1)]+1;
			}
		result=m[Count()+n1*v.Count()];
	}
	return result;
}

/* Test results in 2007/04/09

set seed 2
set 1 -1
set 2 1000000
set information 1
run

#1# Adding 1000000 random elements to vector A
(31) elements of char
(31) elements of __int16
(31) elements of __int32
(79) elements of __int64
(46) elements of float
(79) elements of double
#2# A.Sort(); 1000000 random elements
(93) elements of char
(157) elements of __int16
(156) elements of __int32
(219) elements of __int64
(250) elements of float
(265) elements of double
#3# Acessing/verifing if 1000000 elements of A are sorted
(0) elements of char
(16) elements of __int16
(0) elements of __int32
(15) elements of __int64
(0) elements of float
(16) elements of double
#4# A.RandomOrder(); 1000000 elements
(63) elements of char
(109) elements of __int16
(125) elements of __int32
(172) elements of __int64
(140) elements of float
(172) elements of double
#5# A.Invert(); 1000000 elements
(0) elements of char
(0) elements of __int16
(16) elements of __int32
(16) elements of __int64
(0) elements of float
(15) elements of double
#6# A.BeASet(); 1000000 elements (sort and remove duplicates)
(94) elements of char
(156) elements of __int16
(172) elements of __int32
(234) elements of __int64
(266) elements of float
(266) elements of double
Size of Sets A:
char 256;
 __int16 65536;
 __int32 999879;
 __int64 1000000;
 float 980581;
 double 999890
#7# B.operator=(A); assigning vectors
(0) elements of char
(0) elements of __int16
(31) elements of __int32
(31) elements of __int64
(16) elements of float
(15) elements of double
#8# B.Equal(A); comparing vectors
(0) elements of char
(0) elements of __int16
(16) elements of __int32
(16) elements of __int64
(0) elements of float
(15) elements of double
#9# A.Remove(0); set half of elements to 0 and then remove them.
(0) elements of char
(16) elements of __int16
(78) elements of __int32
(109) elements of __int64
(94) elements of float
(94) elements of double
#10# B.Difference(A); difference of sets
(0) elements of char
(16) elements of __int16
(15) elements of __int32
(16) elements of __int64
(15) elements of float
(32) elements of double
Size of sets:
char 159+97=256;
 __int16 39708+25828=65536;
__int32 606688+393191=999879;
 __int64 606696+393304=1000000;
 float 594633+385948=980581;
 double 606457+393433=999890
#11# B.Union(A); union of sets
(0) elements of char
(15) elements of __int16
(125) elements of __int32
(188) elements of __int64
(187) elements of float
(203) elements of double
#12# A.Contained(B); A contained in B
(0) elements of char
(0) elements of __int16
(16) elements of __int32
(31) elements of __int64
(32) elements of float
(15) elements of double
#13# A.Intersection(B); A intersection with B
(0) elements of char
(0) elements of __int16
(16) elements of __int32
(31) elements of __int64
(31) elements of float
(32) elements of double
#14# A.operator+=(B); adding vectors
(0) elements of char
(0) elements of __int16
(31) elements of __int32
(62) elements of __int64
(32) elements of float
(62) elements of double
Size of vectors:
char 415+256=671;
 __int16 105244+65536=170780;
__int32 1606567+999879=2606446;
 __int64 1606696+1000000=2606696;
 float 1575214+980581=2555795;
 double 1606347+999890=2606237
No errors found.Run end.


set seed 2
set 1 -1
set 2 10000000
set information 1
run

#1# Adding 10000000 random elements to vector A
(266) elements of char
(266) elements of __int16
(359) elements of __int32
(703) elements of __int64
(578) elements of float
(860) elements of double
#2# A.Sort(); 10000000 random elements
(984) elements of char
(1516) elements of __int16
(2000) elements of __int32
(2609) elements of __int64
(2891) elements of float
(3031) elements of double
#3# Acessing/verifing if 10000000 elements of A are sorted
(62) elements of char
(47) elements of __int16
(63) elements of __int32
(62) elements of __int64
(78) elements of float
(94) elements of double
#4# A.RandomOrder(); 10000000 elements
(1563) elements of char
(1687) elements of __int16
(1797) elements of __int32
(1938) elements of __int64
(1812) elements of float
(1922) elements of double
#5# A.Invert(); 10000000 elements
(16) elements of char
(31) elements of __int16
(62) elements of __int32
(125) elements of __int64
(47) elements of float
(125) elements of double
#6# A.BeASet(); 10000000 elements (sort and remove duplicates)
(1000) elements of char
(1547) elements of __int16
(2031) elements of __int32
(2688) elements of __int64
(3015) elements of float
(3110) elements of double
Size of Sets A:
char 256;
 __int16 65536;
 __int32 9988463;
 __int64 10000000;
 float 8309118;
 double 9988537
#7# B.operator=(A); assigning vectors
(15) elements of char
(0) elements of __int16
(172) elements of __int32
(266) elements of __int64
(125) elements of float
(250) elements of double
#8# B.Equal(A); comparing vectors
(0) elements of char
(0) elements of __int16
(78) elements of __int32
(125) elements of __int64
(63) elements of float
(109) elements of double
#9# A.Remove(0); set half of elements to 0 and then remove them.
(0) elements of char
(0) elements of __int16
(984) elements of __int32
(1032) elements of __int64
(843) elements of float
(1032) elements of double
#10# B.Difference(A); difference of sets
(0) elements of char
(15) elements of __int16
(141) elements of __int32
(172) elements of __int64
(156) elements of float
(203) elements of double
Size of sets:
char 153+103=256;
 __int16 39629+25907=65536;
__int32 6057416+3931047=9988463;
 __int64 6064739+3935261=10000000;
 float 5038930+3270188=8309118;
 double 6059269+3929268=9988537
#11# B.Union(A); union of sets
(0) elements of char
(0) elements of __int16
(1391) elements of __int32
(2078) elements of __int64
(1672) elements of float
(2297) elements of double
#12# A.Contained(B); A contained in B
(0) elements of char
(0) elements of __int16
(156) elements of __int32
(156) elements of __int64
(156) elements of float
(203) elements of double
#13# A.Intersection(B); A intersection with B
(0) elements of char
(0) elements of __int16
(219) elements of __int32
(203) elements of __int64
(219) elements of float
(266) elements of double
#14# A.operator+=(B); adding vectors
(0) elements of char
(0) elements of __int16
(125) elements of __int32
(218) elements of __int64
(79) elements of float
(218) elements of double
Size of vectors:
char 409+256=665;
 __int16 105165+65536=170701;
__int32 16045879+9988463=26034342;
 __int64 16064739+10000000=26064739;
 float 13348048+8309118=21657166;
 double 16047806+9988537=26036343
No errors found.Run end.



*/
#endif // !defined(AFX_TVECTOR_H__7E674C3E_074D_4F78_8839_D28D9BAD66FD__INCLUDED_)
