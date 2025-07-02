#pragma once

/**
 * @file   TRand.h
 * @brief  Interface para geração de números aleatórios independentes do sistema operativo.
 *
 * O namespace TRand disponibiliza funções para gerar sequências
 * pseudo-aleatórias de forma portátil. Suporta até duas sequências
 * independentes, selecionadas pelo parâmetro @p seq (0 ou 1).
 */

 /**
  * @namespace TRand
  * @brief Agrupa funções para inicializar e obter valores pseudo-aleatórios.
  *
  * Funciona sem depender de implementações específicas do SO.
  * - srand(): inicializa a semente da sequência.
  * - rand():  retorna o próximo valor da sequência.
  */
namespace TRand
{
    /**
     * @brief Inicializa a semente da geração pseudo-aleatória.
     * @param seed Valor da semente; se for zero, usa o relógio do sistema.
     * @param seq  Índice da sequência (0 ou 1). Por omissão, 0.
     */
    void srand(unsigned int seed, int seq = 0);

    /**
     * @brief Retorna o próximo valor pseudo-aleatório.
     * @param seq Índice da sequência (0 ou 1). Por omissão, 0.
     * @return Valor pseudo-aleatório no intervalo [0, 2^32 − 1].
     */
    unsigned int rand(int seq = 0);
}
