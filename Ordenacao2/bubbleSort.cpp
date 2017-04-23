#include "bubbleSort.h"

#include <vector>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;
//vet
void BubbleSort::ordenaDados(Dados * dados, int tam)
{
    this->start_time = chrono::system_clock::now();
    int aux[2];
    register unsigned long long int instrucoes = 0;
    do{
        this->troca = false;
        instrucoes += 2;
        for (int i = 0; i < tam - 1; i++){
            instrucoes += 1;
            if (dados[i].getSalario() > dados[i + 1].getSalario()){
                aux[0] = dados[i].getId();
                aux[1] = dados[i].getSalario();
                dados[i].setId(dados[i + 1].getId());
                dados[i].setSalario(dados[i + 1].getSalario());
                dados[i + 1].setId(aux[0]);
                dados[i + 1].setSalario(aux[1]);
                this->troca = true;
                instrucoes += 8;
            }
        }
        instrucoes += 1;
    }while(this->troca);
    instrucoes += 1;
    this->numInstrucao = instrucoes;
    this->end_time = chrono::system_clock::now();

}

void BubbleSort::ordena(int * vet, int tam)
{
    this->start_time = chrono::system_clock::now();

    register unsigned long long int instrucoes = 0;

    do{
        instrucoes += 1;
        this->troca = false;
        instrucoes += 2;
        for (int i = 0; i < tam - 1; i++){
            instrucoes += 4;
            if (vet[i] > vet[i + 1]){
                swapB(&vet[i], &vet[i + 1]);
                instrucoes += 8;
                this->troca = true;
            }
            instrucoes += 2;
        }
        instrucoes += 1;
    }while(this->troca);

    this->numInstrucao = instrucoes;
    this->end_time = chrono::system_clock::now();

}

void BubbleSort::swapB(int* a, int* b) {

    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
