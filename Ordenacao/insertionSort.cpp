#include "insertionSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>

using namespace std;


void InsertonSort::ordena(int * vet, int tam)
{
    int j = 0;

    this->start_time = chrono::system_clock::now();

    for(int i = 0; i < tam; i++){
        this->pivo = vet[i];
        j = i -1;
        while(j >= 0 && vet[j] > this->pivo){
            vet[j+1] = vet[j];
            j = j - 1;
        }
        vet[j+1] = this->pivo;
    }

    this->end_time = chrono::system_clock::now();

}


int InsertonSort::getNumInstrucao()
{
    return this->numInstrucao;
}

float InsertonSort::getTimeSpent()
{
    //return (float) (1000 * (this->getTimeEnd().tv_sec - this->getTimeBegin().tv_sec) + (this->getTimeEnd().tv_usec - this->getTimeBegin().tv_usec) / 1000);
    return (float) (chrono::duration_cast<chrono::nanoseconds> (this->end_time - this->start_time).count() );
}


chrono::time_point<chrono::system_clock> InsertonSort::getStartTime()
{
    return this->start_time;
}

chrono::time_point<chrono::system_clock> InsertonSort::getEndTime()
{
    return this->end_time;
}

time_t InsertonSort::getDate()
{
    this->end_timeF = chrono::system_clock::to_time_t(this->end_time);
    return this->end_timeF;
}

