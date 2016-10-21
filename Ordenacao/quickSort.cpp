#include "quickSort.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <sys/time.h>
//#include <chrono>
//#include <ctime>

#include "util.h"


using namespace std;


void QuickSort::ordena(int* vet, int tam, int versao){

    register unsigned long long int instrucoes = 0;

    if (versao != 4){
        this->start_time = chrono::system_clock::now();
        this->quickSort(vet, 0, tam-1, versao, instrucoes);
        this->end_time = chrono::system_clock::now();
        this->numInstrucao = instrucoes;
    }
    else{
        this->start_time = chrono::system_clock::now();
        this->quickSortSimples(vet, 0, tam-1,instrucoes);
        this->end_time = chrono::system_clock::now();
    }

}

void QuickSort::swapQ(int* a, int* b) {

    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int QuickSort::partitionSimple(int* vet, int left, int right, register unsigned long long int &instrucoes) {
  int i, j;

  i = left;
  instrucoes += 4;
  for (j = left + 1; j <= right; ++j) {
    if (vet[j] < vet[left]) {
        ++i;
        swapQ(&vet[i], &vet[j]);
        instrucoes += 6;
    }
    instrucoes += 5;
  }
  swapQ(&vet[left], &vet[i]);
  instrucoes += 5;

  return i;
}

void QuickSort::quickSortSimples(int* vet, int left, int right, register unsigned long long int &instrucoes) {

    int r;
    instrucoes += 1;
    if (right > left) {
        instrucoes += 1;
        r = this->partitionSimple(vet, left, right, instrucoes);
        instrucoes += 1;
        this->quickSortSimples(vet, left, r - 1, instrucoes);
        instrucoes += 1;
        this->quickSortSimples(vet, r + 1, right, instrucoes);
    }
}


void QuickSort::quickSort(int* vet, int left, int right, int versao, register unsigned long long int &instrucoes) {

    int i = left, j = right;
    int tmp, pivot;

    instrucoes += 3;
    switch(versao){

        case 1:
            instrucoes += 3;
            if ( vet[left] > vet[left+1] ){ /*1 MÉTODO DE ESCOLHA DO PIVÔ*/
                pivot = vet[left];
                instrucoes += 2;
            }
            else {
                pivot = vet[left+1];
                instrucoes += 3;
            }
            break;

        case 2:
            instrucoes += 5;
            if ( vet[left] > vet[(left + right) / 2] ){ /*2 MÉTODO DE ESCOLHA DO PIVÔ*/
                pivot = vet[left];
                instrucoes += 2;
            }
            else{
                pivot = vet[(left + right) / 2];
                instrucoes += 4;
            }
            break;

        case 3:
            instrucoes += 3;
            int v1 =  xrandomRange(left, right);
            int v2 =  xrandomRange(left, right);
            if (v1 == v2 )
            {
                return;
            }
            instrucoes += 3;
            if ( vet[v1] > vet[v2] ){
                pivot = vet[v1];
                instrucoes += 2;
            }
            else{
                pivot = vet[v2];
                instrucoes += 2;
            }
            break;
    }

    instrucoes += 1;
    while (i <= j) {
        instrucoes += 1;
        while (vet[i] < pivot){
            instrucoes += 1;
            i++;
        }
        instrucoes += 1;
        while (vet[j] > pivot){
            instrucoes += 1;
            j--;
        }

        instrucoes += 1;
        if (i <= j) {
            tmp = vet[i];
            vet[i] = vet[j];
            vet[j] = tmp;
            i++;
            j--;
            instrucoes += 9;
        }
    }

    instrucoes += 1;
    if (left < j){
        quickSort(vet, left, j, versao, instrucoes);
    }
    instrucoes += 1;
    if (i < right){
        quickSort(vet, i, right, versao, instrucoes);
    }

}
