#pragma once
#include "../TProcura.h"
#include <vector>

/**
 * @class CTesteTVector
 * @brief Classe de teste para TVector, integrada na framework TProcura.
 *
 * Permite testar as funcionalidades do vetor dinâmico (TVector), nomeadamente
 * operações sobre vetores de inteiros, e comparar resultados com a STL.
 *
 * @see TProcura, TVector
 */
class CTesteTVector : public TProcura
{
public:
    CTesteTVector() {}
    ~CTesteTVector() {}

    TVector<int> dadosA, dadosB;   ///< Vetores de teste para operações TVector.
    std::vector<int> stdA, stdB;   ///< Vetores equivalentes em STL para comparação.

    /// Inicializa parâmetros de teste.
    void ResetParametros();
    /// Inicializa dados e estado para teste.
    void Inicializar(void);
    /// Mostra informação de debug sobre o estado dos vetores.
    void Debug(bool completo = true) override;
    using TProcura::Debug; // Reexpõe as sobrecargas herdadas
    /// Executa o algoritmo de teste (a definir pelo utilizador).
    int ExecutaAlgoritmo();
    /// Calcula indicadores de teste.
    int64_t Indicador(int id);
};



