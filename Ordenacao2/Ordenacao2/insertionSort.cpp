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
    this->start_time = chrono::system_clock::now();

    register unsigned long long int instrucoes = 0;

    instrucoes += 1;
    int j = 0;

    instrucoes += 2;
    for(int i = 0; i < tam; i++){

        this->pivo = vet[i];
        j = i -1;
        instrucoes += 8;
        while(j >= 0 && vet[j] > this->pivo){
            vet[j+1] = vet[j];
            j = j - 1;
           instrucoes += 6;
        }
        instrucoes += 3;
        vet[j+1] = this->pivo;
        instrucoes += 2;
    }

    this->numInstrucao = instrucoes;
    instrucoes = 0;
    this->end_time = chrono::system_clock::now();

}


