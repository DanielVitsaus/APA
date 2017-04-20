#include "mergeSort.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <string.h>


using namespace std;


void MergeSort::ordena(int* vet, int tam){

    register unsigned long long int instrucoes = 0;

    this->start_time = chrono::system_clock::now();

    this->mergeSort(vet, tam, instrucoes);
    this->numInstrucao = instrucoes;

    this->end_time = chrono::system_clock::now();
}


void MergeSort::mergeS(int* vet, int tam, register unsigned long long int &instrucoes){

    int middle, i, j, k;
    int* temp;

    instrucoes += 2;
    temp = (int*) malloc(tam * sizeof(int));

    instrucoes += 1;
    if (temp == NULL){
        exit(1);
    }

    instrucoes += 6;
    middle = 0;
    middle = tam / 2;
    i = 0; k  = 0;  j = middle;

    instrucoes += 3;
    while ( ( i < middle ) && ( j < tam ) ){

        instrucoes += 3;
        if ( vet[i] < vet[j] ){
            temp[k] = vet[i];
            i++;
            instrucoes += 4;
        }
        else{
            temp[k] = vet[j];
            j++;
            instrucoes += 4;
        }
        k++;
        instrucoes += 4;
    }

    instrucoes += 1;
    if (i == middle){
        instrucoes += 1;
        while(j < tam){
            temp[k] = vet[j];
            j++;
            k++;
            instrucoes += 5;
        }
    }
    else{
        instrucoes += 1;
        while(i < middle){
            temp[k] = vet[i];
            i++;
            k++;
            instrucoes += 5;
        }
    }

    instrucoes += 2;
    for (int i = 0; i < tam; i++){
        vet[i] = temp[i];
        instrucoes += 5;
    }

    free(temp);
}


void MergeSort::mergeSort(int* vet, int tam, register unsigned long long int &instrucoes){

    int middle;
    instrucoes += 1;
    if ( tam > 1){
        instrucoes += 3;
        middle = tam / 2;
        this->mergeSort(vet, middle, instrucoes);
        this->mergeSort(vet + middle, tam - middle, instrucoes);
        this->mergeS(vet, tam, instrucoes);
    }

}



























