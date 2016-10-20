#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

//extern volatile uint32_t numInstrucao1;
//#define numInstrucao1 ((volatile uint32_t*) 0xfffe0004)

class Ordenacao
{

    protected:
        chrono::time_point<chrono::system_clock> start_time;
        chrono::time_point<chrono::system_clock> end_time;
        time_t end_timeF;
        int idAlgoritmo;
        int numInstrucao;
        int tamanhoInstancia;
        char* nomeInstancia;
        char* tipoInstancia;
        char* nomeAlgoritmo;

    public:
        //void ordena(int * vet, int tam);
        //void contaInstricao(int num){ numInstrucao1 += num; numInstrucao = numInstrucao1;};
        chrono::time_point<chrono::system_clock> getStartTime();
        chrono::time_point<chrono::system_clock> getEndTime();
        time_t getDate();
        int getIDAlgoritmo(){ return idAlgoritmo; };
        int getNumInstrucao();
        float getRunTime();
        void setNomeInstancia(char* nome){ nomeInstancia = nome; };
        void setTipoInstancia(char* tipo){ tipoInstancia = tipo; };
        void setNomeAlgoritmo(char* nome){ nomeAlgoritmo = nome; };
        void setTamanhoInstancia(int tam){ tamanhoInstancia = tam; };
        int getTamanhoInstancia() { return tamanhoInstancia; };
        char* getNomeInstancia(){ return nomeInstancia; };
        char* getTipoInstancia(){ return tipoInstancia; };
        char* getNomeAlgoritmo(){ return nomeAlgoritmo; };

};

#endif // ORDENACAO_H_INCLUDED
