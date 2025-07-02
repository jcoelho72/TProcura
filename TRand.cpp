// TRand.cpp: implementação do namespace TRand para geração de números aleatórios.
//
#include <ctime>
#include "TRand.h"

namespace {
    // parâmetros do período
    constexpr int N = 624;
    constexpr int M = 397;

    // constantes para tempering
    constexpr unsigned MATRIX_A = 0x9908b0dfu;
    constexpr unsigned UPPER_MASK = 0x80000000u;
    constexpr unsigned LOWER_MASK = 0x7fffffffu;
    constexpr unsigned TEMPERING_MASK_B = 0x9d2c5680u;
    constexpr unsigned TEMPERING_MASK_C = 0xefc60000u;

    // shifts de tempering
    inline unsigned TEMPER_U(unsigned y) { return y >> 11; }
    inline unsigned TEMPER_S(unsigned y) { return y << 7; }
    inline unsigned TEMPER_T(unsigned y) { return y << 15; }
    inline unsigned TEMPER_L(unsigned y) { return y >> 18; }

    // estado interno: duas sequências independentes
    static unsigned mt[N][2];
    static int      mti[2] = { N + 1, N + 1 };

    // auxiliar para mag01[x] = x * MATRIX_A
    static unsigned mag01[2] = { 0u, MATRIX_A };
}

namespace TRand {

    void srand(unsigned int seed, int seq /*=0*/)
    {
        seq &= 1;
        if (seed == 0)
            seed = static_cast<unsigned int>(std::clock());

        mt[0][seq] = seed;
        for (mti[seq] = 1; mti[seq] < N; ++mti[seq]) {
            mt[mti[seq]][seq] = (69069u * mt[mti[seq] - 1][seq]) & 0xffffffffu;
        }
    }

    unsigned int rand(int seq /*=0*/)
    {
        unsigned int y;
        seq &= 1;

        if (mti[seq] >= N) {
            // gera N palavras de uma vez
            if (mti[seq] == N + 1) {
                // seed padrão
                srand(0, seq);
            }

            for (int kk = 0; kk < N - M; ++kk) {
                y = (mt[kk][seq] & UPPER_MASK) | (mt[kk + 1][seq] & LOWER_MASK);
                mt[kk][seq] = mt[kk + M][seq] ^ (y >> 1) ^ mag01[y & 0x1];
            }
            for (int kk = N - M; kk < N - 1; ++kk) {
                y = (mt[kk][seq] & UPPER_MASK) | (mt[kk + 1][seq] & LOWER_MASK);
                mt[kk][seq] = mt[kk + (M - N)][seq] ^ (y >> 1) ^ mag01[y & 0x1];
            }
            y = (mt[N - 1][seq] & UPPER_MASK) | (mt[0][seq] & LOWER_MASK);
            mt[N - 1][seq] = mt[M - 1][seq] ^ (y >> 1) ^ mag01[y & 0x1];

            mti[seq] = 0;
        }

        y = mt[mti[seq]++][seq];
        y ^= TEMPER_U(y);
        y ^= TEMPER_S(y) & TEMPERING_MASK_B;
        y ^= TEMPER_T(y) & TEMPERING_MASK_C;
        y ^= TEMPER_L(y);

        return y;
    }

} // namespace TRand

