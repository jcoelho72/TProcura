#pragma once
#include "../TProcura.h"
#include <vector>

/**
 * @class CTesteTVector
 * @brief Classe de teste para TVector, integrada na framework TProcura.
 *
 * Permite testar as funcionalidades do vetor din�mico (TVector), nomeadamente
 * opera��es sobre vetores de inteiros, e comparar resultados com a STL.
 *
 * @see TProcura, TVector
 */
class CTesteTVector : public TProcura
{
public:
    CTesteTVector() {}
    ~CTesteTVector() {}

    TVector<int> dadosA, dadosB;   ///< Vetores de teste para opera��es TVector.
    std::vector<int> stdA, stdB;   ///< Vetores equivalentes em STL para compara��o.

    /// Inicializa par�metros de teste.
    void ResetParametros();
    /// Inicializa dados e estado para teste.
    void Inicializar(void);
    /// Mostra informa��o de debug sobre o estado dos vetores.
    void Debug(bool completo = true) override;
    using TProcura::Debug; // Reexp�e as sobrecargas herdadas
    /// Executa o algoritmo de teste (a definir pelo utilizador).
    int ExecutaAlgoritmo();
    /// Calcula indicadores de teste.
    int64_t Indicador(int id);
};



