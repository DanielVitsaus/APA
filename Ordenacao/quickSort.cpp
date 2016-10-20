#include "quickSort.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//#include <time.h>
#include <sys/time.h>
//#include <chrono>
//#include <ctime>


using namespace std;


void QuickSort::ordena(int* vet, int tam, int versao){


    switch(versao){

        case 1:
            this->start_time = chrono::system_clock::now();
            this->setIDAlgoritmo(7);
            this->quickSortSimples(vet, 0, tam-1);
            this->end_time = chrono::system_clock::now();
            break;

        case 2:
            this->start_time = chrono::system_clock::now();
            this->setIDAlgoritmo(8);
            //this->mergeSortSimples(vet, tam);
            this->end_time = chrono::system_clock::now();
            break;

        case 3:
            this->start_time = chrono::system_clock::now();
            this->setIDAlgoritmo(9);
            //this->mergeSortSimples(vet, tam);
            this->end_time = chrono::system_clock::now();
            break;

        case 4:
            this->start_time = chrono::system_clock::now();
            this->setIDAlgoritmo(12);
            //this->mergeSortSimples(vet, tam);
            this->end_time = chrono::system_clock::now();
            break;

        default:
            cout << "Escolha uma das três opções:\n  1 , 2 ou 3 !\n " << endl;
    }

}

void QuickSort::swapQ(int* a, int* b) {

    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}

int QuickSort::partitionSimple(int* vet, int left, int right) {
  int i, j;

  i = left;
  for (j = left + 1; j <= right; ++j) {
    if (vet[j] < vet[left]) {
      ++i;
      swapQ(&vet[i], &vet[j]);
    }
  }
  swapQ(&vet[left], &vet[i]);

  return i;
}

void QuickSort::quickSortSimples(int* vet, int left, int right) {

    int r;
    if (right > left) {
        r = this->partitionSimple(vet, left, right);
        this->quickSortSimples(vet, left, r - 1);
        this->quickSortSimples(vet, r + 1, right);
    }
}
