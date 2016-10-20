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
        void swapQ(int* a, int* b);
        void quickSortSimples(int* vet, int left, int right);
        int partitionSimple(int* vet, int left, int right);

        //void mergeSortAlocacao(int * vet, int tam);

        //void mergeSortParametroAd(int * vet, int tam);

        void setIDAlgoritmo(int num){ idAlgoritmo = num; };

    public:
        void ordena(int * vet, int tam, int versao);


};

#endif // QUICKSORT_H_INCLUDED
