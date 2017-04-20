#include "heapSort.h"


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

    register unsigned long long int instrucoes = 0;

    instrucoes += 5;
    this->i = tam/2; this->temp = 0;
    this->pai = 0; this->filho = 0;

    for (;;)
    {
        instrucoes += 1;
        if (this->i > 0){
            this->i--;
            this->temp = vet[this->i];
            instrucoes += 3;
        }
        else{
            tam--;
            if (tam == 0)
                break;
            this->temp = vet[tam];
            vet[tam] = vet[0];
            instrucoes += 7;
        }

        instrucoes += 4;
        this->pai = this->i;
        this->filho = (this->i*2) + 1;

        instrucoes += 1;
        while (this->filho < tam){

            instrucoes += 7;
            if ((this->filho + 1 < tam)  &&  (vet[this->filho + 1] > vet[this->filho])){
                this->filho++;
                instrucoes += 1;
            }

            instrucoes += 2;
            if (vet[this->filho] > this->temp){
                vet[this->pai] = vet[this->filho];
                this->pai = this->filho;
                this->filho = (this->pai*2) + 1;
                instrucoes += 7;
            }
            else
                break;

            instrucoes += 1;
        }
        instrucoes += 2;
        vet[this->pai] = this->temp;
    }

    this->end_time = chrono::system_clock::now();

    this->numInstrucao = instrucoes;

}
