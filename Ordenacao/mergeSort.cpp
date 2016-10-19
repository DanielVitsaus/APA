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


void MergeSort::ordena(int* vet, int tam, int versao){

    switch(versao){

        case 1:
            this->start_time = chrono::system_clock::now();
            this->mergeSortSimples(vet, tam);
            this->end_time = chrono::system_clock::now();
            break;

        case 2:
            this->start_time = chrono::system_clock::now();
            //this->mergeSortSimples(vet, tam);
            this->end_time = chrono::system_clock::now();
            break;

        case 3:
            this->start_time = chrono::system_clock::now();
            //this->mergeSortSimples(vet, tam);
            this->end_time = chrono::system_clock::now();
            break;

        default:
            cout << "Escolha uma das três opções:\n  1 , 2 ou 3 !\n " << endl;
    }

}


void MergeSort::mergeSimple(int* vet, int tam){

    int middle = 0, i = 0, j = 0, k = 0;
    int* temp;

    temp = (int*) malloc(tam * sizeof(int));

    if (temp == NULL){
        exit(1);
    }

    middle = 0;
    middle = tam / 2;
    i = 0; k  = 0;  j = middle;

    while ( ( i < middle ) && ( j < tam ) ){

        if ( vet[i] < vet[j] ){
            temp[k] = vet[i];
            i += 1;
        }
        else{
            temp[k] = vet[j];
            j += 1;
        }
        k += 1;
    }
    if (i == middle){
        while(j < tam){

            temp[k] = vet[j];
            j += 1;
            k += 1;
        }
    }
    else{
        while(i < middle){

            temp[k] = vet[i];
            i += 1;
            k += 1;
        }
    }

    for (int i = 0; i < tam; i++){
        vet[i] = temp[i];
    }

    free(temp);
}


void MergeSort::mergeSortSimples(int* vet, int tam){

    int middle;
    if ( tam > 1){
        middle = tam / 2;
        this->mergeSortSimples(vet, middle);
        this->mergeSortSimples(vet + middle, tam - middle);
        this->mergeSimple(vet, tam);
    }

}



























