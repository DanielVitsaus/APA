#ifndef QUICKSORT_H_INCLUDED
#define QUICKSORT_H_INCLUDED

//#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"
#include "Dados.h"
using namespace std;

class QuickSort  : public Ordenacao
{
    private:
        void swapQ(int &a, int &b);

        int particiona(int* v, int first, int last, int versao, register unsigned long long int &instrucoes);
        void quickSort(int* v, int comeco, int fim, register unsigned long long int &instrucoes);
        void quickSort_I(int* v, int first, int last, int versao, register unsigned long long int &instrucoes);

        int particionaDados(Dados* dados, int first, int last, int versao, register unsigned long long int &instrucoes);
        void quickSortDados(Dados* dados, int comeco, int fim, register unsigned long long int &instrucoes);
        void quickSort_IDados(Dados* dados, int first, int last, int versao, register unsigned long long int &instrucoes);

    public:
        void ordena(int * vet, int tam);
        void ordenaDados(Dados * dados, int tam);



};

#endif // QUICKSORT_H_INCLUDED
