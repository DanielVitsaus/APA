#ifndef COUNTINGSORT_H_INCLUDED
#define COUNTINGSORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

class CountingSort : public Ordenacao
{
    private:
        int* vetAXU;
        int* vetOrdenado;

    public:
        CountingSort(){ idAlgoritmo = 2; };
        void ordena(int* vet, int tam);

};


#endif // COUNTINGSORT_H_INCLUDED
