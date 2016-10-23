#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

//#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

class QuickSort  : public Ordenacao
{
    private:
        void swapQ(int &a, int &b);

        int particiona(int* v, int first, int last, int versao, register unsigned long long int &instrucoes);
        void quickSort(int* v, int first, int last, int versao, register unsigned long long int &instrucoes);

    public:
        void ordena(int * vet, int tam, int versao);



};

#endif // QUICKSORT_H_INCLUDED
