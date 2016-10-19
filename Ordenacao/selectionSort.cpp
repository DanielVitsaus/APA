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
    this->imv = 0;

    this->start_time = chrono::system_clock::now();

    for(int i = 0; i < (tam - 1); i++){
        this->imv = i;
        for (int j = (i + 1); j < tam; j++){
            if (vet[j] < vet[this->imv]){
                this->imv = j;
            }
        }
        if (this->imv != i){
            swap(vet[i], vet[this->imv]);
        }
    }

    this->end_time = chrono::system_clock::now();

}
