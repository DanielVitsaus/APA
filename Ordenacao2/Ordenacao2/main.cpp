#include <iostream>
#include <math.h>
#include <ctime>
#include <time.h>
#include <chrono>
#include <random>

#include "util.h"
#include "GeraInstancias.h"
#include "LeituraGravacao.h"
#include "insertionSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "heapSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;

void geraInstancias();

#define UART_TXBUF ((volatile uint32_t*) 0xfffe0004)

int main()
{
    int *v = NULL;
    vector<string> arquivos;
    LeituraGravacao* legrava = new LeituraGravacao();
    arquivos = legrava->listaArquivos();

    Ordenacao* ordenacao ;

    BubbleSort* bubbleSort = new BubbleSort();
    HeapSort* heap = new HeapSort();
    InsertonSort* insertSort = new InsertonSort();
    MergeSort* mergeSort = new MergeSort();
    QuickSort* quick = new QuickSort();
    SelectionSort* selection = new SelectionSort();



    cout << "\n************ Utilizando o algoritmo HeapSort! ************\n" << endl;
    for (int i = (int)arquivos.size() -1 ; i >= 0; i--){

        v = legrava->lerArquivo(arquivos[i]);

        heap->setNomeAlgoritmo("HeapSort");
        heap->setNomeInstancia(legrava->getNomeInstacia());
        heap->setTamanhoInstancia(legrava->getTamanhaoArquivo());
        heap->setTipoInstancia(legrava->getTipoInstacia());
        ordenacao = heap;
        cout << "Ordenado..." << endl;
        ((HeapSort*)ordenacao)->ordena( v, legrava->getTamanhaoArquivo());
        cout << "Oerdenação concluida! \n\n "  << endl;

        cout << "Gerando arquivo..." << endl;
        legrava->gravaInfo(ordenacao);
        cout << "Arquivo gerado! \n" << endl;
    }
    free(heap);



    cout << "\n************ Utilizando o algoritmo MergeSort ! ************\n" << endl;
    for (int i = (int)arquivos.size() -1 ; i >= 0; i--){

        v = legrava->lerArquivo(arquivos[i]);

        mergeSort->setNomeAlgoritmo("MergeSort_MA");
        mergeSort->setNomeInstancia(legrava->getNomeInstacia());
        mergeSort->setTamanhoInstancia(legrava->getTamanhaoArquivo());
        mergeSort->setTipoInstancia(legrava->getTipoInstacia());
        ordenacao = mergeSort;
        cout << "Ordenado..." << endl;
        ((MergeSort*)ordenacao)->ordena( v, legrava->getTamanhaoArquivo() );
        cout << "Oerdenação concluida! \n\n "  << endl;

        cout << "Gerando arquivo..." << endl;
        legrava->gravaInfo(ordenacao);
        cout << "Arquivo gerado! \n" << endl;
    }


    cout << "\n************ Utilizando o algoritmo QuickSort ! ************\n" << endl;
    for (int i = (int)arquivos.size() -1 ; i >= 0; i--){

        v = legrava->lerArquivo(arquivos[i]);

        quick->setNomeAlgoritmo("QuickSort"); // o maior entre dois elementos de posições aleatórias
        quick->setNomeInstancia(legrava->getNomeInstacia());
        quick->setTamanhoInstancia(legrava->getTamanhaoArquivo());
        quick->setTipoInstancia(legrava->getTipoInstacia());
        ordenacao = quick;
        cout << "Ordenado..." << endl;
        ((QuickSort*)ordenacao)->ordena( v, legrava->getTamanhaoArquivo());
        cout << "Oerdenação concluida! \n\n "  << endl;

        cout << "Gerando arquivo..." << endl;
        legrava->gravaInfo(ordenacao);
        cout << "Arquivo gerado! \n" << endl;


    }


    cout << "\n************ Utilizando o algoritmo SelectionSort! ************\n" << endl;
    for (int i = (int)arquivos.size() -1 ; i >= 0; i--){

        v = legrava->lerArquivo(arquivos[i]);

        selection->setNomeAlgoritmo("SelectionSort");
        selection->setNomeInstancia(legrava->getNomeInstacia());
        selection->setTamanhoInstancia(legrava->getTamanhaoArquivo());
        selection->setTipoInstancia(legrava->getTipoInstacia());
        ordenacao = selection;
        cout << "Ordenado..." << endl;
        ((SelectionSort*)ordenacao)->ordena( v, legrava->getTamanhaoArquivo());
        cout << "Oerdenação concluida! \n\n "  << endl;

        cout << "Gerando arquivo..." << endl;
        legrava->gravaInfo(ordenacao);
        cout << "Arquivo gerado! \n" << endl;
    }
    free(selection);


    cout << "\n************ Utilizando o algoritmo BubbleSort! ************\n" << endl;
    for (int i = (int)arquivos.size() -1 ; i >= 0; i--){

        v = legrava->lerArquivo(arquivos[i]);

        bubbleSort->setNomeAlgoritmo("BubbleSort");
        bubbleSort->setNomeInstancia(legrava->getNomeInstacia());
        bubbleSort->setTamanhoInstancia(legrava->getTamanhaoArquivo());
        bubbleSort->setTipoInstancia(legrava->getTipoInstacia());
        ordenacao = bubbleSort;
        cout << "Ordenado..." << endl;
        ((BubbleSort*)ordenacao)->ordena( v, legrava->getTamanhaoArquivo());
        cout << "Oerdenação concluida! \n\n "  << endl;

        cout << "Gerando arquivo..." << endl;
        legrava->gravaInfo(ordenacao);
        cout << "Arquivo gerado! \n" << endl;
    }

    free(bubbleSort);


    cout << "\n************ Utilizando o algoritmo InsertonSort! ************\n" << endl;
    for (int i = (int)arquivos.size() -1 ; i >= 0; i--){

        v = legrava->lerArquivo(arquivos[i]);

        insertSort->setNomeAlgoritmo("InsertonSort");
        insertSort->setNomeInstancia(legrava->getNomeInstacia());
        insertSort->setTamanhoInstancia(legrava->getTamanhaoArquivo());
        insertSort->setTipoInstancia(legrava->getTipoInstacia());
        ordenacao = insertSort;
        cout << "Ordenado..." << endl;
        ((InsertonSort*)ordenacao)->ordena( v, legrava->getTamanhaoArquivo());
        cout << "Oerdenação concluida! \n\n "  << endl;

        cout << "Gerando arquivo..." << endl;
        legrava->gravaInfo(ordenacao);
        cout << "Arquivo gerado! \n" << endl;
    }
    free(insertSort);


    free(v);
    free(legrava);
    arquivos.clear();


    return 0;
}

void geraInstancias()
{
    GeraInstancias *gera = new GeraInstancias();

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
