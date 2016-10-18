#include "countingSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <string.h>


using namespace std;


int* CountingSort::ordena(int * vet, int tam)
{
    this->start_time = chrono::system_clock::now();

    this->vetAXU = new int[tam + 1];
    this->vetOrdenado = new int[tam];

    // aloca memoria e inicializa os vetores com 0
    memset(this->vetAXU, 0, sizeof(int) * (tam + 1) );
    memset(this->vetOrdenado, 0, sizeof(int) * tam);

    //conta os valores armazenados no vetor que sera ordenado
    for (int i = 0; i < tam; i++){
        this->vetAXU[vet[i]]++;
    }

    for (int i = 1; i < (tam + 1); i++){
        this->vetAXU[i] += this->vetAXU[i - 1];
    }

    for (int i = 0; i < tam; i++){
        this->vetOrdenado[this->vetAXU[ vet[i] ] - 1] = vet[i];
        this->vetAXU[vet[i]]--;
    }


    this->end_time = chrono::system_clock::now();

    free(this->vetAXU);

    return this->vetOrdenado;

}


int CountingSort::getNumInstrucao()
{
    return this->numInstrucao;
}

float CountingSort::getTimeSpent()
{
    //return (float) (1000 * (this->getTimeEnd().tv_sec - this->getTimeBegin().tv_sec) + (this->getTimeEnd().tv_usec - this->getTimeBegin().tv_usec) / 1000);
    return (float) (chrono::duration_cast<chrono::nanoseconds> (this->end_time - this->start_time).count() );
}


chrono::time_point<chrono::system_clock> CountingSort::getStartTime()
{
    return this->start_time;
}

chrono::time_point<chrono::system_clock> CountingSort::getEndTime()
{
    return this->end_time;
}

time_t CountingSort::getDate()
{
    this->end_timeF = chrono::system_clock::to_time_t(this->end_time);
    return this->end_timeF;
}

