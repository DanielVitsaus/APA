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

    register int instrucoes = 0;

    do{
        instrucoes += 1;
        this->troca = false;
        instrucoes += 2;
        for (int i = 0; i < tam - 1; i++){
            instrucoes += 4;
            if (vet[i] > vet[i + 1]){
                swapB(&vet[i], &vet[i + 1]);
                instrucoes += 8;
                this->troca = true;
            }
            instrucoes += 2;
        }
        instrucoes += 1;
    }while(this->troca);

    this->numInstrucao = instrucoes;
    this->end_time = chrono::system_clock::now();

}

void BubbleSort::swapB(int* a, int* b) {

    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
