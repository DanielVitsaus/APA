#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

#include <iostream>
#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"
#include "Dados.h"
using namespace std;

class InsertonSort : public Ordenacao
{
    private:
        int pivo;

    public:
        InsertonSort(){ idAlgoritmo = 4; };
        void ordena(int * vet, int tam);
        void ordenaDados(Dados * dados, int tam);
};


#endif // INSERTSORT_H_INCLUDED
