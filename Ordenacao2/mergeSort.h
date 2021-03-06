#ifndef MERGESORT_H_INCLUDED
#define MERGESORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"
#include "Dados.h"
using namespace std;

class MergeSort  : public Ordenacao
{
    private:

        void mergeSort(int* vet, int tam, register unsigned long long int &instrucoes);
        void mergeS(int* vet, int tam, register unsigned long long int &instrucoes);

        void setIDAlgoritmo(int num){ idAlgoritmo = num; };

        void mergeSortDados(Dados* dados, int tam, register unsigned long long int &instrucoes);
        void mergeSDados(Dados* dados, int tam, register unsigned long long int &instrucoes);
    public:
        void ordena(int * vet, int tam);
        void ordenaDados(Dados * dados, int tam);


};

#endif // MERGESORT_H_INCLUDED
