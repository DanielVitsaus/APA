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


