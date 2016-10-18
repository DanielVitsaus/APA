#include "radixSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <string.h>


using namespace std;


int* RadixSort::ordena(int * vet, int tam)
{
    this->start_time = chrono::system_clock::now();

    this->exp = 1;
    this->maiorV = vet[0];

    this->vetOrdenado = new int[tam];

    // aloca memoria e inicializa os vetores com 0
    memset(this->vetOrdenado, 0, sizeof(int) * tam);

    for(int i = 0; i < tam; i++){
        if (vet[i] > this->maiorV){
            this->maiorV = vet[i];
        }
    }

    while( (this->maiorV/this->exp) > 0){

        this->digitos = new int[10];
        memset(this->digitos, 0, sizeof(int) * 10);

        //conta os valores armazenados no vetor que sera ordenado
        for (int i = 0; i < tam; i++){
            this->digitos[ ( vet[i] / this->exp ) % 10 ]++;
        }

        for (int i = 1; i < 10; i++){
            this->digitos[i] += this->digitos[i - 1];
        }

        for (int i = tam - 1; i >= 0; i--){
            this->vetOrdenado[ --this->digitos[ ( vet[i] / this->exp ) % 10 ] ] = vet[i];
        }

        for(int i = 0; i < tam; i++){
            vet[i] = this->vetOrdenado[i];
        }

        this->exp *= 10;
        free(this->digitos);
    }

    this->end_time = chrono::system_clock::now();

    return this->vetOrdenado;

}


int RadixSort::getNumInstrucao()
{
    return this->numInstrucao;
}

float RadixSort::getTimeSpent()
{
    //return (float) (1000 * (this->getTimeEnd().tv_sec - this->getTimeBegin().tv_sec) + (this->getTimeEnd().tv_usec - this->getTimeBegin().tv_usec) / 1000);
    return (float) (chrono::duration_cast<chrono::nanoseconds> (this->end_time - this->start_time).count() );
}


chrono::time_point<chrono::system_clock> RadixSort::getStartTime()
{
    return this->start_time;
}

chrono::time_point<chrono::system_clock> RadixSort::getEndTime()
{
    return this->end_time;
}

time_t RadixSort::getDate()
{
    this->end_timeF = chrono::system_clock::to_time_t(this->end_time);
    return this->end_timeF;
}

