#include "selectionSort.h"

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <vector>
#include <chrono>
#include <ctime>

using namespace std;


void SelectionSort::ordena(int * vet, int tam)
{
    register unsigned long long int instrucoes = 0;

    instrucoes += 1;
    this->imv = 0;

    this->start_time = chrono::system_clock::now();

    instrucoes += 3;
    for(int i = 0; i < (tam - 1); i++){
        this->imv = i;
        for (int j = (i + 1); j < tam; j++){
            instrucoes += 3;
            if (vet[j] < vet[this->imv]){
                this->imv = j;
                instrucoes += 1;
            }
        }
        if (this->imv != i){
            instrucoes += 5;
            swap(vet[i], vet[this->imv]);
        }
        instrucoes += 8;
    }
    this->numInstrucao = instrucoes;
    this->end_time = chrono::system_clock::now();

}
//vet
void SelectionSort::ordenaDados(Dados * dados, int tam)
{
    register unsigned long long int instrucoes = 0;
    int aux[2];
    instrucoes += 1;
    this->imv = 0;

    this->start_time = chrono::system_clock::now();

    instrucoes += 2;
    for(int i = 0; i < (tam - 1); i++){
        this->imv = i;
        instrucoes += 3;
        for (int j = (i + 1); j < tam; j++){
            instrucoes += 2;
            if (dados[j].getSalario() < dados[this->imv].getSalario()){
                this->imv = j;
                instrucoes += 2;
            }
        }
        if (this->imv != i){
            aux[0] = dados[i].getId();
			aux[1] = dados[i].getSalario();
			dados[i].setId(dados[this->imv].getId());
            dados[i].setSalario(dados[this->imv].getSalario());
            dados[this->imv].setId(aux[0]);
            dados[this->imv].setSalario(aux[1]);
            instrucoes += 7;
        }
    }
    this->numInstrucao = instrucoes;
    this->end_time = chrono::system_clock::now();

}
