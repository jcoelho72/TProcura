// TRand.h: interface for the TRand class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_TRAND_H__9FDE1FBE_24F4_4324_A740_DD79F3648BBA__INCLUDED_)
#define AFX_TRAND_H__9FDE1FBE_24F4_4324_A740_DD79F3648BBA__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class TRand
{
public:
	// seq 0 ou 1, para permitir duas sequências aleatórias independentes
	static unsigned int rand(int seq = 0); 
	static void srand(unsigned int seed, int seq = 0);
	TRand();
	virtual ~TRand();

};

#endif // !defined(AFX_TRAND_H__9FDE1FBE_24F4_4324_A740_DD79F3648BBA__INCLUDED_)
