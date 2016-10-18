#include "heapSort.h"

//#include <vector>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void HeapSort::ordena(int * vet, int tam)
{
    this->start_time = chrono::system_clock::now();

    int i = tam/2, pai, filho;
    int temp;

    for (;;)
    {
        if (i > 0){
            i--;
            temp = vet[i];
        }
        else{
            tam--;
            if (tam == 0)
                return;
            temp = vet[tam];
            vet[tam] = vet[0];
        }

        pai = i;
        filho = i*2 + 1;

        while (filho < tam){
            if ((filho + 1 < tam)  &&  (vet[filho + 1] > vet[filho]))
                filho++;

            if (vet[filho] > temp){
                vet[pai] = vet[filho];
                pai = filho;
                filho = pai*2 + 1;
            }
            else
                break;
        }
        vet[pai] = temp;
    }

    this->end_time = chrono::system_clock::now();

}


int HeapSort::getNumInstrucao()
{
    return this->numInstrucao;
}

float HeapSort::getTimeSpent()
{
    //return (float) (1000 * (this->getTimeEnd().tv_sec - this->getTimeBegin().tv_sec) + (this->getTimeEnd().tv_usec - this->getTimeBegin().tv_usec) / 1000);
    return (float) (chrono::duration_cast<chrono::nanoseconds> (this->end_time - this->start_time).count() );
}


chrono::time_point<chrono::system_clock> HeapSort::getStartTime()
{
    return this->start_time;
}

chrono::time_point<chrono::system_clock> HeapSort::getEndTime()
{
    return this->end_time;
}

time_t HeapSort::getDate()
{
    this->end_timeF = chrono::system_clock::to_time_t(this->end_time);
    return this->end_timeF;
}

