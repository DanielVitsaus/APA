#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

class MergeSort  : public Ordenacao
{
    private:

        void mergeSortSimples(int* vet, int tam, int* temp, register unsigned long long int &instrucoes);
        void mergeSimple(int* vet, int tam, int* tem, register unsigned long long int &instrucoes);

        void setIDAlgoritmo(int num){ idAlgoritmo = num; };


    public:
        void ordena(int * vet, int tam, int versao);


};

#endif // MERGESORT_H_INCLUDED
