#ifndef LEITURAGRAVACAO_H_INCLUDED
#define LEITURAGRAVACAO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string.h>
#include <cstdlib>
#include "Dados.h"
#include "Ordenacao.h"

using namespace std;

class LeituraGravacao
{
    private:
        ifstream arquivoLeitura;
        ofstream arquivoGravacao;
        int tamanhoArquivo;
        int * vetor;
        char nomeInstacia[30];
        char tipoInstacia[30];

    public:
        char* getTipoInstacia(){ return tipoInstacia; };
        char* getNomeInstacia(){ return nomeInstacia; };
        int getTamanhaoArquivo(){ return tamanhoArquivo; };
        void lerDados(string ar,Dados *dados);
        int* lerArquivo(string ar);
        vector<string> listaArquivos();
        void gravaVetor(int* vet, int tam, string nome);
        void gravaInfo(Ordenacao* algoritmo);
};


#endif // LEITURAGRAVACAO_H_INCLUDED
