#include "selectionSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;


void SelectionSort::ordena(int * vet, int tam)
{
    int imv = 0;

    this->start_time = chrono::system_clock::now();

    for(int i = 0; i < (tam - 1); i++){
        imv = i;
        for (int j = (i + 1); j < tam; j++){
            if (vet[j] < vet[imv]){
                imv = j;
            }
        }
        if (imv != i){
            swap(vet[i], vet[imv]);
        }
    }

    this->end_time = chrono::system_clock::now();

}


int SelectionSort::getNumInstrucao()
{
    return this->numInstrucao;
}

float SelectionSort::getTimeSpent()
{
    return (float) (chrono::duration_cast<chrono::nanoseconds> (this->end_time - this->start_time).count() );
}


chrono::time_point<chrono::system_clock> SelectionSort::getStartTime()
{
    return this->start_time;
}

chrono::time_point<chrono::system_clock> SelectionSort::getEndTime()
{
    return this->end_time;
}

time_t SelectionSort::getDate()
{
    this->end_timeF = chrono::system_clock::to_time_t(this->end_time);
    return this->end_timeF;
}

