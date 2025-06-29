#pragma once
#include "../TProcura.h"
#include <vector>

class CTesteTVector :
    public TProcura
{
public:
    CTesteTVector() {}
    ~CTesteTVector() {}

    TVector<int> dadosA, dadosB;

    // espelhos em STL
    std::vector<int> stdA, stdB;

    void ResetParametros();
    void Inicializar(void);
    void Debug(void);
    int ExecutaAlgoritmo();
    int Indicador(int id);

};

