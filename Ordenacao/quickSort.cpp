#include "quickSort.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>

#include <stack>
#include <set>

#include "util.h"


using namespace std;


void QuickSort::ordena(int* vet, int tam, int versao){

    register unsigned long long int instrucoes = 0;

    this->start_time = chrono::system_clock::now();
    this->quickSort(vet, 0, tam - 1, versao , instrucoes);
    this->end_time = chrono::system_clock::now();
    this->numInstrucao = instrucoes;

}

void QuickSort::swapQ(int &a, int &b) {

    int tmp;
    tmp = a;
    a = b;
    b = tmp;
}


int QuickSort::particiona(int* vet, int left, int right, int versao, register unsigned long long int &instrucoes) {

    int pivo = left;

    instrucoes += 1;
    switch(versao){

        case 1:
        {
            instrucoes += 3;
            if ( vet[left] > vet[left+1] ){
                pivo = left;
                instrucoes += 1;
            }
            else {
                pivo = left+1;
                instrucoes += 2;
            }
            break;
        }
        case 2:
        {
            instrucoes += 5;
            if ( vet[left] > vet[(left + right) / 2] ){
                pivo = left;
                instrucoes += 1;
            }
            else{
                pivo = (left + right) / 2;
                instrucoes += 3;
            }
            break;
        }
        case 3:
        {
            instrucoes += 3;
            int v1 =  xrandomRange(left, right);
            int v2 =  xrandomRange(left, right);
            if (v1 == v2 )
            {
                return -1;
            }
            instrucoes += 3;
            if ( vet[v1] > vet[v2] ){
                pivo = v1;
                instrucoes += 1;
            }
            else{
                pivo = v2;
                instrucoes += 21;
            }
            break;
        }
        case 4:
        {
            pivo = left;
            instrucoes += 1;
            break;
        }
    }

    swapQ(vet[pivo], vet[right]); pivo = right;

    int i = left - 1, j = right;

    instrucoes += 10;
    while(true) {

        instrucoes += 7;
        while(i < j && vet[++i] < vet[pivo]); if(i >= j) break;
        instrucoes += 7;
        while(j > i && vet[--j] > vet[pivo]); if(j <= i) break;

        swapQ(vet[i], vet[j]);
        instrucoes += 5;
    }
    swapQ(vet[i], vet[pivo]);
    instrucoes += 5;
    return i;

}

void QuickSort::quickSort(int* vet, int left, int right, int versao, register unsigned long long int &instrucoes) {

    std::stack<int> st(std::deque<int>( (right - left) + 1) );
    st.push(right);
    st.push(left);

    instrucoes += 5;
    while(!st.empty()) {
        int s = st.top(); st.pop();
        int t = st.top(); st.pop();
        instrucoes += 5;
        if(s < t) {
            int p = this->particiona(vet, s, t, versao, instrucoes);
            instrucoes += 2;
            if (p != -1 ){
                st.push(t); st.push(p + 1);
                st.push(p - 1); st.push(s);
                instrucoes += 6;
            }
        }
    }

    this->numInstrucao = instrucoes;
}
