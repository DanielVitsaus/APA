#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

class BubbleSort  : public Ordenacao
{
    private:
        bool troca;

        void swapB(int* a, int* b);

    public:
        BubbleSort(){ idAlgoritmo = 1; };
        void ordena(int * vet, int tam);

};

#endif // BUBBLESORT_H_INCLUDED
