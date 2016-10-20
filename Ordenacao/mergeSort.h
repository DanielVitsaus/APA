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

        void mergeSortSimples(int* vet, int tam, int* temp, register int &instrucoes);
        void mergeSimple(int* vet, int tam, int* tem, register int &instrucoes);

        //void mergeSortAlocacao(int * vet, int tam);

        //void mergeSortParametroAd(int * vet, int tam);

        void setIDAlgoritmo(int num){ idAlgoritmo = num; };


    public:
        void ordena(int * vet, int tam, int versao);


};

#endif // MERGESORT_H_INCLUDED
