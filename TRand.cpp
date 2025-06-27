// TRand.cpp: implementation of the TRand class.
//
//////////////////////////////////////////////////////////////////////

#include <time.h>
#include "TRand.h"


/* Period parameters */
#define N 624
#define M 397
//#define N 27
//#define M 7
#define MATRIX_A 0x9908b0df   /* constant vector a */
#define UPPER_MASK 0x80000000 /* most significant w-r bits */
#define LOWER_MASK 0x7fffffff /* least significant r bits */

/* Tempering parameters */
#define TEMPERING_MASK_B 0x9d2c5680
#define TEMPERING_MASK_C 0xefc60000
#define TEMPERING_SHIFT_U(y)  (y >> 11)
#define TEMPERING_SHIFT_S(y)  (y << 7)
#define TEMPERING_SHIFT_T(y)  (y << 15)
#define TEMPERING_SHIFT_L(y)  (y >> 18)

static unsigned int mt[N][2]; /* the array for the state vector  */
static int mti[2] = { N + 1, N + 1 }; /* mti==N+1 means mt[N] is not initialized */


//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

TRand::TRand()
{

}

TRand::~TRand()
{

}

void TRand::srand(unsigned int seed, int seq)
{
    /* setting initial seeds to mt[N] using         */
    /* the generator Line 25 of Table 1 in          */
    /* [KNUTH 1981, The Art of Computer Programming */
    /*    Vol. 2 (2nd Ed.), pp102]                  */

    seq &= 1;

    if (seed == 0)
        seed = (unsigned int)clock();

    mt[0][seq] = seed & 0xffffffff;
    for (mti[seq] = 1; mti[seq] < N; mti[seq]++)
        mt[mti[seq]][seq] = (69069 * mt[mti[seq] - 1][seq]) & 0xffffffff;
}

unsigned int TRand::rand(int seq)
{
    unsigned int y;
    static unsigned int mag01[2]={0x0, MATRIX_A};
    /* mag01[x] = x * MATRIX_A  for x=0,1 */
    seq &= 1;

    if (mti[seq] >= N) { /* generate N words at one time */
        int kk;

        if (mti[seq] == N+1)   /* if sgenrand() has not been called, */
            srand(0, seq); /* a default initial seed is used   */

        for (kk = 0; kk < N - M; kk++) {
            y = (mt[kk][seq] & UPPER_MASK) | (mt[kk + 1][seq] & LOWER_MASK);
            mt[kk][seq] = mt[kk + M][seq] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        for (; kk < N - 1; kk++) {
            y = (mt[kk][seq] & UPPER_MASK) | (mt[kk + 1][seq] & LOWER_MASK);
            mt[kk][seq] = mt[kk + (M - N)][seq] ^ (y >> 1) ^ mag01[y & 0x1];
        }
        y = (mt[N - 1][seq] & UPPER_MASK) | (mt[0][seq] & LOWER_MASK);
        mt[N-1][seq] = mt[M-1][seq] ^ (y >> 1) ^ mag01[y & 0x1];

        mti[seq] = 0;
    }

    y = mt[mti[seq]++][seq];
    y ^= TEMPERING_SHIFT_U(y);
    y ^= TEMPERING_SHIFT_S(y) & TEMPERING_MASK_B;
    y ^= TEMPERING_SHIFT_T(y) & TEMPERING_MASK_C;
    y ^= TEMPERING_SHIFT_L(y);

	return y;
}

#undef N 
#undef M 
#undef MATRIX_A
#undef UPPER_MASK
#undef LOWER_MASK
#undef TEMPERING_MASK_B 
#undef TEMPERING_MASK_C 
#undef TEMPERING_SHIFT_U
#undef TEMPERING_SHIFT_S
#undef TEMPERING_SHIFT_T
#undef TEMPERING_SHIFT_L
