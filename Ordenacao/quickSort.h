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
        void quickSortSimples(int* vet, int left, int right, register unsigned long long int &instrucoes);
        int partitionSimple(int* vet, int left, int right , register unsigned long long int &instrucoes);

        void quickSort(int* vet, int left, int right, int versao, register unsigned long long int &instrucoes);

        //void mergeSortParametroAd(int * vet, int tam);

        void setIDAlgoritmo(int num){ idAlgoritmo = num; };

    public:
        void ordena(int * vet, int tam, int versao);



};

#endif // QUICKSORT_H_INCLUDED
