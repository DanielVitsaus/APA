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
        void ordena(int* vet, int tam);

};


#endif // COUNTINGSORT_H_INCLUDED
