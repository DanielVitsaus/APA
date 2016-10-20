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

    int* temp;
    register int instrucoes = 0;

    switch(versao){

        case 1:
            this->start_time = chrono::system_clock::now();
            this->setIDAlgoritmo(5);
            this->mergeSortSimples(vet, tam, NULL, instrucoes);
            this->numInstrucao = instrucoes;

            this->end_time = chrono::system_clock::now();
            break;

        case 2:
            this->start_time = chrono::system_clock::now();
            this->setIDAlgoritmo(6);
            instrucoes += 2;
            temp = (int*) malloc(tam * sizeof(int));
            instrucoes += 1;
            if (temp != NULL){
                this->mergeSortSimples(vet, tam, temp, instrucoes);
            }else{
                cout << "\nNão deu cara!\n" << endl;
            }
            this->numInstrucao = instrucoes;

            this->end_time = chrono::system_clock::now();
            free(temp);
            break;
        /*
        case 3:
            this->start_time = chrono::system_clock::now();
            //this->mergeSortSimples(vet, tam);
            this->end_time = chrono::system_clock::now();
            break;
        */

        default:
            cout << "Escolha uma das três opções:\n  1 , 2 ou 3 !\n " << endl;
    }

}


void MergeSort::mergeSimple(int* vet, int tam, int* tem, register int &instrucoes){

    instrucoes += 4;
    int middle = 0, i = 0, j = 0, k = 0;
    int* temp;

    instrucoes += 1;
    if (tem == NULL){
        instrucoes += 2;
        temp = (int*) malloc(tam * sizeof(int));
    }
    else{
        instrucoes += 1;
        temp = tem;
    }

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


void MergeSort::mergeSortSimples(int* vet, int tam, int* tem, register int &instrucoes){

    int middle;
    instrucoes += 1;
    int* temp = NULL;
    instrucoes += 1;
    if ( tam > 1){
        instrucoes += 3;
        middle = tam / 2;
        if (tem != NULL){
            instrucoes += 2;
            temp = (int*) malloc(tam * sizeof(int));
        }
        this->mergeSortSimples(vet, middle, temp, instrucoes);
        this->mergeSortSimples(vet + middle, tam - middle, temp, instrucoes);
        this->mergeSimple(vet, tam, temp, instrucoes);
    }

}



























