#include "radixSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <string.h>


using namespace std;


void RadixSort::ordena(int * vet, int tam)
{
    this->start_time = chrono::system_clock::now();
    register unsigned long long int instrucoes = 0;

    instrucoes += 4;
    this->exp = 1;
    this->maiorV = vet[0];

    this->vetOrdenado = new int[tam];

    // aloca memoria e inicializa os vetores com 0
    instrucoes += (tam +1);
    memset(this->vetOrdenado, 0, sizeof(int) * tam);

    instrucoes += 2;
    for(int i = 0; i < tam; i++){
        instrucoes += 3;
        if (vet[i] > this->maiorV){
            this->maiorV = vet[i];
            instrucoes += 3;
        }
        instrucoes += 2;
    }

    instrucoes += 2;
    while( (this->maiorV/this->exp) > 0){

        instrucoes += 12;
        this->digitos = new int[10];
        memset(this->digitos, 0, sizeof(int) * 10);

        instrucoes += 2;
        for (int i = 0; i < tam; i++){
            this->digitos[ ( vet[i] / this->exp ) % 10 ]++;
            instrucoes += 7;
        }

        instrucoes += 2;
        for (int i = 1; i < 10; i++){
            this->digitos[i] += this->digitos[i - 1];
            instrucoes += 7;
        }

        instrucoes += 2;
        for (int i = tam - 1; i >= 0; i--){
            this->vetOrdenado[ --this->digitos[ ( vet[i] / this->exp ) % 10 ] ] = vet[i];
            instrucoes += 9;
        }

        instrucoes += 2;
        for(int i = 0; i < tam; i++){
            vet[i] = this->vetOrdenado[i];
            instrucoes += 5;
        }
        instrucoes += 2;
        this->exp *= 10;
        free(this->digitos);
        instrucoes += 2;
    }

    this->end_time = chrono::system_clock::now();
    free(this->vetOrdenado);

    this->numInstrucao = instrucoes;

}
