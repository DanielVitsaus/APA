#ifndef LEITURAGRAVACAO_H_INCLUDED
#define LEITURAGRAVACAO_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdlib>

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
        int* lerArquivo(char *ar);
        vector<char*> listaArquivos();
        void grava(int* vet, int tam);
        //void gravaArquivoResultado(char* nomArquivo, string reslutado);
        //void gravaArquivo(Grafo *g, char* nomArquivo,int nVertice, int nAresta, float grauMedio);

};


#endif // LEITURAGRAVACAO_H_INCLUDED
