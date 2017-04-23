#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"
#include "Dados.h"

using namespace std;

class SelectionSort : public Ordenacao
{
    private:
        int imv;

    public:
        SelectionSort(){ idAlgoritmo = 11; };
        void ordena(int * vet, int tam);
        void ordenaDados(Dados * dados, int tam);

};

#endif // SELECTIONSORT_H_INCLUDED
