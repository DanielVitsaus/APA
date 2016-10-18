#include "util.h"
#include "GeraInstacias.h"

#include <iostream>
#include <fstream>
#include <string.h>
#include <sstream>
#include <random>

using namespace std;

GeraInstacias::GeraInstacias()
{
    random_device r;
    seed_seq seed2{ ((unsigned int)( time((time_t *)NULL) )) * r(),
                    ((unsigned int)( time((time_t *)NULL) )) * r(),
                    ((unsigned int)( time((time_t *)NULL) )) * r(),
                    ((unsigned int)( time((time_t *)NULL) )) * r() };
                    /*
                    ((unsigned int)( time((time_t *)NULL) )) * r(),
                    ((unsigned int)( time((time_t *)NULL) )) * r(),
                    ((unsigned int)( time((time_t *)NULL) )) * r(),
                    ((unsigned int)( time((time_t *)NULL) )) * r() };
                    */

    mt19937_64 gen( seed2 );

    setSeed(gen());
}

void GeraInstacias::ordenCrescente(int tam){


    char diretorio[100] = "Instancias//instancia_";
    string Result;
    stringstream convert;
    convert << tam;
    Result = convert.str();

    strcat(diretorio, Result.c_str());
    strcat(diretorio, "_OC.txt");

    this->arquivoGravacao.open(diretorio, ios::out);

    this->arquivoGravacao << "intancia_"+Result+"_OC" << endl;
    this->arquivoGravacao << "ORDENAÇÃO_CRESCENTE" << endl;
    this->arquivoGravacao << tam;
    this->arquivoGravacao << endl;
    this->arquivoGravacao << endl;

    for (int i = 1; i <= tam; i++){

        this->arquivoGravacao << i;
        this->arquivoGravacao << endl;
    }

    this->arquivoGravacao.close();


}


void GeraInstacias::ordenDecrecente(int tam){

    char diretorio[100] = "Instancias//instancia_";
    string Result;
    stringstream convert;
    convert << tam;
    Result = convert.str();

    strcat(diretorio, Result.c_str());
    strcat(diretorio, "_OD.txt");

    this->arquivoGravacao.open(diretorio, ios::out);

    this->arquivoGravacao << "intancia_"+Result+"_OD" << endl;
    this->arquivoGravacao << "ORDENAÇÃO_DECRESCENTE" << endl;
    this->arquivoGravacao << tam;
    this->arquivoGravacao << endl;
    this->arquivoGravacao << endl;

    for (int i = tam; i > 0; i--){

        this->arquivoGravacao << i;
        this->arquivoGravacao << endl;
    }

    this->arquivoGravacao.close();

}


void GeraInstacias::comRepeticao(int tam){

    //random_device r;

    //seed_seq seed2{r(), r(), r(), r(), r(), r(), r(), r()};
    //cout << r() << endl;
    //cout << (unsigned int)( time((time_t *)NULL)  ) << endl;
    //cout << (unsigned int)( time((time_t *)NULL) * r() ) <<"\n" << endl;

    //mt19937_64 gen( (unsigned int)( time((time_t *)NULL)  )  );

    //setSeed(gen());

    char diretorio[100] = "Instancias//instancia_";
    string Result;
    stringstream convert;
    convert << tam;
    Result = convert.str();

    strcat(diretorio, Result.c_str());
    strcat(diretorio, "_CR.txt");

    this->arquivoGravacao.open(diretorio, ios::out);

    this->arquivoGravacao << "intancia_"+Result+"_CR" << endl;
    this->arquivoGravacao << "COM_REPETIÇÃO" << endl;
    this->arquivoGravacao << tam;
    this->arquivoGravacao << endl;
    this->arquivoGravacao << endl;

    for (int i = 0; i < tam; i++){

        this->arquivoGravacao << xrandomRange(1, tam);
        this->arquivoGravacao << endl;
    }

    this->arquivoGravacao.close();

}


void GeraInstacias::semRepeticao(int tam){

    char diretorio[100] = "Instancias//instancia_";
    string Result;
    stringstream convert;
    convert << tam;
    Result = convert.str();

    strcat(diretorio, Result.c_str());
    strcat(diretorio, "_SR.txt");

    int * valores =  new int[tam];

    memset(valores, 0, sizeof(int) * tam);

    for (int i = 0; i < tam; i++){
        valores[i] = i + 1;
    }

    for (int i = 0; i < tam; i++){
        swap(valores[i], valores[xrandomRange(0, tam-1)]);
    }

    this->arquivoGravacao.open(diretorio, ios::out);

    this->arquivoGravacao << "intancia_"+Result+"_SC" << endl;
    this->arquivoGravacao << "SEM_REPETIÇÃO" << endl;
    this->arquivoGravacao << tam;
    this->arquivoGravacao << endl;
    this->arquivoGravacao << endl;

    for (int i = 0; i < tam; i++){

        this->arquivoGravacao << valores[i];
        this->arquivoGravacao << endl;
    }

    free(valores);
    this->arquivoGravacao.close();

}
