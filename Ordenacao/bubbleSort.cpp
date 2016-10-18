#include "bubbleSort.h"

#include <vector>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void BubbleSort::ordena(int * vet, int tam)
{
    this->start_time = chrono::system_clock::now();

    do{
        this->troca = false;
        for (int i = 0; i < tam - 1; i++){
            if (vet[i] > vet[i + 1]){
                swap(vet[i], vet[i + 1]);
                this->troca = true;
            }
        }

    }while(this->troca);

    this->end_time = chrono::system_clock::now();

}


int BubbleSort::getNumInstrucao()
{
    return this->numInstrucao;
}

float BubbleSort::getTimeSpent()
{
    return (float) (chrono::duration_cast<chrono::nanoseconds> (this->end_time - this->start_time).count() );
}


chrono::time_point<chrono::system_clock> BubbleSort::getStartTime()
{
    return this->start_time;
}

chrono::time_point<chrono::system_clock> BubbleSort::getEndTime()
{
    return this->end_time;
}

time_t BubbleSort::getDate()
{
    this->end_timeF = chrono::system_clock::to_time_t(this->end_time);
    return this->end_timeF;
}
