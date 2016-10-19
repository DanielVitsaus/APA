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

    this->i = tam/2; this->temp = 0;
    this->pai = 0; this->filho = 0;

    for (;;)
    {
        if (this->i > 0){
            this->i--;
            this->temp = vet[this->i];
        }
        else{
            tam--;
            if (tam == 0)
                break;
            this->temp = vet[tam];
            vet[tam] = vet[0];
        }

        this->pai = this->i;
        this->filho = this->i*2 + 1;

        while (this->filho < tam){
            if ((this->filho + 1 < tam)  &&  (vet[this->filho + 1] > vet[this->filho]))
                this->filho++;

            if (vet[this->filho] > this->temp){
                vet[this->pai] = vet[this->filho];
                this->pai = this->filho;
                this->filho = this->pai*2 + 1;
            }
            else
                break;
        }
        vet[this->pai] = this->temp;
    }

    this->end_time = chrono::system_clock::now();

}
