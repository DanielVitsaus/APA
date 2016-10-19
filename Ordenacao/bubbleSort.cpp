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

