#ifndef RADIXSORT_H_INCLUDED
#define RADIXSORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

class RadixSort : public Ordenacao
{
    private:
        int* vetOrdenado;
        int* digitos;
        int maiorV;
        int exp;

    public:
        void ordena(int* vet, int tam);
};


#endif // RADIXSORT_H_INCLUDED
