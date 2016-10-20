#ifndef INSERTIONSORT_H_INCLUDED
#define INSERTIONSORT_H_INCLUDED

#include <iostream>
#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

class InsertonSort : public Ordenacao
{
    private:
        int pivo;

    public:
        void ordena(int * vet, int tam);
};


#endif // INSERTSORT_H_INCLUDED
