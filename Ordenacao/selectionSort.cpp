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
    register int instrucoes = 0;

    instrucoes += 1;
    this->imv = 0;

    this->start_time = chrono::system_clock::now();

    instrucoes += 3;
    for(int i = 0; i < (tam - 1); i++){
        this->imv = i;
        for (int j = (i + 1); j < tam; j++){
            instrucoes += 3;
            if (vet[j] < vet[this->imv]){
                this->imv = j;
                instrucoes += 1;
            }
        }
        if (this->imv != i){
            instrucoes += 5;
            swap(vet[i], vet[this->imv]);
        }
        instrucoes += 8;
    }

    this->end_time = chrono::system_clock::now();

}
