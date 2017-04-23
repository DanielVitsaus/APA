#ifndef BUBBLESORT_H_INCLUDED
#define BUBBLESORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"
#include "Dados.h"
using namespace std;

class BubbleSort  : public Ordenacao
{
    private:
        bool troca;

        void swapB(int* a, int* b);

    public:
        BubbleSort(){ idAlgoritmo = 1; };
        void ordena(int * vet, int tam);
        void ordenaDados(Dados * dados, int tam);

};

#endif // BUBBLESORT_H_INCLUDED
