#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include "Ordenacao.h"

using namespace std;

class HeapSort : public Ordenacao
{
    private:
        int i, pai, filho, temp;


    public:
        void ordena(int * vet, int tam);


};

#endif // HEAPSORT_H_INCLUDED
