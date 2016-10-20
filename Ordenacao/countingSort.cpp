#include "countingSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <string.h>


using namespace std;


void CountingSort::ordena(int * vet, int tam)
{
    this->start_time = chrono::system_clock::now();

    register int instrucoes = 0;

    instrucoes += 2;
    this->vetAXU = new int[tam + 1];
    instrucoes += 1;
    this->vetOrdenado = new int[tam];

    // aloca memoria e inicializa os vetores com 0
    instrucoes += (3 + tam);
    memset(this->vetAXU, 0, sizeof(int) * (tam + 1) );
    instrucoes += (2 + tam );
    memset(this->vetOrdenado, 0, sizeof(int) * tam);

    //conta os valores armazenados no vetor que sera ordenado
    instrucoes += 2;
    for (int i = 0; i < tam; i++){
        instrucoes += 2;
        this->vetAXU[vet[i]]++;
        instrucoes += 2;
    }

    instrucoes += 3;
    for (int i = 1; i < (tam + 1); i++){
        instrucoes += 6;
        this->vetAXU[i] += this->vetAXU[i - 1];
        instrucoes += 2;
    }

    instrucoes += 2;
    for (int i = 0; i < tam; i++){
        instrucoes += 6;
        this->vetOrdenado[this->vetAXU[ vet[i] ] - 1] = vet[i];
        instrucoes += 3;
        this->vetAXU[vet[i]]--;
        instrucoes += 2;
    }

    instrucoes += 2;
    for (int i = 0; i < tam; i++){
        instrucoes += 3;
        vet[i] = this->vetOrdenado[i];
        instrucoes += 2;
    }

    this->end_time = chrono::system_clock::now();

    free(this->vetAXU);
    free(this->vetOrdenado);

    this->numInstrucao = instrucoes;

}


