#include <iostream>
#include <math.h>
#include <ctime>
#include <time.h>
#include <chrono>
#include <random>

#include "util.h"
#include "GeraInstacias.h"
#include "LeituraGravacao.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "heapSort.h"
#include "countingSort.h"
#include "radixSort.h"

using namespace std;

void geraInstacias();


int main()
{
    //geraInstacias();

    LeituraGravacao* legrava = new LeituraGravacao();

    RadixSort* in = new RadixSort();

    char ar[30] = "instancia_100_CR.txt";
    int *v = NULL;
    v = legrava->lerArquivo(ar);

    v = in->ordena(v, legrava->getTamanhaoArquivo());
    //in->ordena(v, legrava->getTamanhaoArquivo());

    if (legrava->getTamanhaoArquivo() < 10000){

        for(int i = 0; i < legrava->getTamanhaoArquivo(); i++){
            cout << v[i] << endl;
        }
    }

    printf ("\nTempo de execulção ->  %f\n", in->getTimeSpent() / 1000000000);
    time_t te = in->getDate();
    cout << "\nData da execulção -> " << ctime(&te) << endl;
    cout << "\nTipo da instacia -> " << legrava->getTipoInstacia() << endl;

    free(v);
    free(legrava);
    free(in);

    return 0;
}

void geraInstacias()
{
    GeraInstacias *gera = new GeraInstacias();

    cout << "Gerando instacais de tamanho 10:" << endl;
    cout << " -> Com repeticao..." << endl;
    gera->comRepeticao( (int) pow(10, 1) );
    cout << " -> Ordem Crescente..." << endl;
    gera->ordenCrescente( (int) pow(10, 1) );
    cout << " -> Oerdem decrescente..." << endl;
    gera->ordenDecrecente( (int) pow(10, 1) );
    cout << " -> Sem repeticao..." << endl;
    gera->semRepeticao( (int) pow(10, 1) );


    cout << "\nGerando instacais de tamanho 10^2:" << endl;
    cout << " -> Com repeticao..." << endl;
    gera->comRepeticao( (int) pow(10, 2) );
    cout << " -> Ordem Crescente..." << endl;
    gera->ordenCrescente( (int) pow(10, 2) );
    cout << " -> Ordem Decrescente..." << endl;
    gera->ordenDecrecente( (int) pow(10, 2) );
    cout << " -> Sem repeticao..." << endl;
    gera->semRepeticao( (int) pow(10, 2) );


    cout << "\nGerando instacais de tamanho 10^3:" << endl;
    cout << " -> Com repeticao..." << endl;
    gera->comRepeticao( (int) pow(10, 3) );
    cout << " -> Ordem Crescente..." << endl;
    gera->ordenCrescente( (int) pow(10, 3) );
    cout << " -> Ordem Decrescente..." << endl;
    gera->ordenDecrecente( (int) pow(10, 3) );
    cout << " -> Sem repeticao..." << endl;
    gera->semRepeticao( (int) pow(10, 3) );

    cout << "\nGerando instacais de tamanho 10^5:" << endl;
    cout << " -> Com repeticao..." << endl;
    gera->comRepeticao( (int) pow(10, 5) );
    cout << " -> Ordem Crescente..." << endl;
    gera->ordenCrescente( (int) pow(10, 5) );
    cout << " -> Ordem Decrescente..." << endl;
    gera->ordenDecrecente( (int) pow(10, 5) );
    cout << " -> Sem repeticao..." << endl;
    gera->semRepeticao( (int) pow(10, 5) );


    cout << "\nGerando instacais de tamanho 10^7:" << endl;
    cout << " -> Com repeticao..." << endl;
    gera->comRepeticao( (int) pow(10, 7) );
    cout << " -> Ordem Crescente..." << endl;
    gera->ordenCrescente( (int) pow(10, 7) );
    cout << " -> Ordem Decrescente..." << endl;
    gera->ordenDecrecente( (int) pow(10, 7) );
    cout << " -> Sem repeticao..." << endl;
    gera->semRepeticao( (int) pow(10, 7) );


    cout << "\nGerando instacais de tamanho 10^8:" << endl;
    cout << " -> Com repeticao..." << endl;
    gera->comRepeticao( (int) pow(10, 8) );
    cout << " -> Ordem Crescente..." << endl;
    gera->ordenCrescente( (int) pow(10, 8) );
    cout << " -> Ordem Decrescente..." << endl;
    gera->ordenDecrecente( (int) pow(10, 8) );
    cout << " -> Sem repeticao..." << endl;
    gera->semRepeticao( (int) pow(10, 8) );

}
