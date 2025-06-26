#pragma once
#include "..\TProcura.h"
class CTesteTVector :
    public TProcura
{
public:
    CTesteTVector() {}
    ~CTesteTVector() {}

    TVector<int> dadosA, dadosB;

    void ResetParametros();
    void Inicializar(void);
    void Debug(void);
    int ExecutaAlgoritmo();
};

