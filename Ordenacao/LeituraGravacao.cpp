#include "LeituraGravacao.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <dirent.h>
#include <sstream>
#include <iomanip>

#include "insertionSort.h"
#include "bubbleSort.h"
#include "selectionSort.h"
#include "heapSort.h"
#include "countingSort.h"
#include "radixSort.h"
#include "mergeSort.h"
#include "quickSort.h"

using namespace std;


vector<string> LeituraGravacao::listaArquivos(){

    DIR *dir = 0;
    struct dirent *entrada = 0;
    unsigned char isFile = 0x8;

    //vector<char*> diretorios;
    vector<string> diretorios;

    dir = opendir ("Instancias");

    if (dir == 0) {
        cerr << "Nao foi possivel abrir diretorio." << endl;
        exit (1);
    }
    //Iterar sobre o diretorio
    //int i = 0;
    while (true){
        entrada = readdir(dir);
        if(entrada == NULL){
            break;
        }
        if (entrada->d_type == isFile){
            diretorios.push_back(entrada->d_name);
            //cout << diretorios2[i]<< endl;
            //i++;
        }

    }

    closedir (dir);

    return diretorios;

}


int* LeituraGravacao::lerArquivo(string ar)
{
    char diretorio[100] = "Instancias//";
    //string Result = "instancia_10_CR.txt";
    strcat(diretorio,ar.c_str());
    this->arquivoLeitura.open(diretorio,ios::binary);

    int valor = 0, i = 0;
    char buff[30];

    if (!this->arquivoLeitura.is_open())
    {
        cout << "Arquivo nao encontrado ou danificado" << endl;
        exit(0);
    }

    cout << "Lendo o arquivo " << ar << " ... " << endl;

    // Le nome da instacia
    this->arquivoLeitura.getline(buff,30);
    sscanf(buff , "%s" , this->nomeInstacia);

    //le o tipo da instacia
    this->arquivoLeitura.getline(buff,30);
    sscanf(buff , "%s" , this->tipoInstacia);

    // Le o tamanha da isntacia
    this->arquivoLeitura.getline(buff,30);
    sscanf(buff, "%d", &this->tamanhoArquivo);

    this->arquivoLeitura.getline(buff,20);

    // aloca memoria pra o vetor
    this->vetor = new int[this->getTamanhaoArquivo()];
    memset( this->vetor, 0, sizeof(int) * this->getTamanhaoArquivo() );

    while( (!this->arquivoLeitura.eof()) && (i < this->getTamanhaoArquivo()) )
    {
        this->arquivoLeitura.getline(buff,16);
        sscanf(buff, "%d", &valor);
        this->vetor[i] = valor;
        i++;
    }
    this->arquivoLeitura.close();
    cout << "\nO arquivo foi " << ar << " lido com sucesso!\n" << endl;
    return this->vetor;
}

void LeituraGravacao::gravaVetor(int* vet, int tam, string nome){

    char diretorio[100] = "Resultados//";
    nome += ".txt";
    strcat(diretorio,nome.c_str());
    this->arquivoGravacao.open(diretorio, ios::trunc);

    for(int i = 0; i < tam; i++){
        this->arquivoGravacao << vet[i] << endl;
    }
    this->arquivoGravacao.close();
}


void LeituraGravacao::gravaInfo(Ordenacao* algoritmo){

    char diretorio[100] = "Resultados//";
    char diretorio2[100] = "Resultados//";
    string nome;
    time_t date;

//---------- Grava um arquivo com o nome do algotmo --------------------------------------------------------------------------------------
    nome = algoritmo->getNomeAlgoritmo();
    date = algoritmo->getDate();
    nome += ".txt";
    strcat(diretorio,nome.c_str());

    this->arquivoGravacao.open(diretorio, ios::app);

    this->arquivoGravacao << "Nome da instancia -> " << algoritmo->getNomeInstancia() << "\n   "
                          << "Tamanho -> " << algoritmo->getTamanhoInstancia() << "\n   "
                          << "Tipo -> " << algoritmo->getTipoInstancia() << "\n   "
                          << "Tempo de execução -> "<< fixed << setprecision(8) << algoritmo->getRunTime() << "\n   "
                          << "Numero de instruções -> " << algoritmo->getNumInstrucao() << "\n   "
                          << "Data da execução -> " << ctime(&date)
                          << "---------------------------------------------------------------------------------------------------" <<endl;

    this->arquivoGravacao.close();
//-------------------------------------------------------------------------------------------------------------------------------------------

//---------- Grava um arquivo com o nome da instancia --------------------------------------------------------------------------------------
    nome = algoritmo->getNomeInstancia();
    date = algoritmo->getDate();
    nome += ".txt";
    strcat(diretorio2,nome.c_str());

    this->arquivoGravacao.open(diretorio2, ios::app);

    this->arquivoGravacao  << "Algoritmo -> " << algoritmo->getNomeAlgoritmo() << "\n   "
                          << "Tamanho -> " << algoritmo->getTamanhoInstancia() << "\n   "
                          << "Tipo -> " << algoritmo->getTipoInstancia() << "\n   "
                          << "Tempo de execução -> "<< fixed << setprecision(8) << algoritmo->getRunTime() << "\n   "
                          << "Numero de instruções -> " << algoritmo->getNumInstrucao() << "\n   "
                          << "Data da execução -> " << ctime(&date)
                          << "---------------------------------------------------------------------------------------------------" <<endl;

    this->arquivoGravacao.close();
//-------------------------------------------------------------------------------------------------------------------------------------------
}
