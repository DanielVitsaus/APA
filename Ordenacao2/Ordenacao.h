#ifndef ORDENACAO_H_INCLUDED
#define ORDENACAO_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


class Ordenacao
{

    protected:
        chrono::time_point<chrono::system_clock> start_time;
        chrono::time_point<chrono::system_clock> end_time;
        time_t end_timeF;
        int idAlgoritmo;
        long long int numInstrucao;
        int tamanhoInstancia;
        string nomeInstancia;
        char* tipoInstancia;
        string nomeAlgoritmo;

    public:
        chrono::time_point<chrono::system_clock> getStartTime();
        chrono::time_point<chrono::system_clock> getEndTime();
        time_t getDate();
        int getIDAlgoritmo(){ return idAlgoritmo; };
        unsigned long long int getNumInstrucao();
        float getRunTime();
        void setNomeInstancia(string nome){ nomeInstancia = nome; };
        void setTipoInstancia(char* tipo){ tipoInstancia = tipo; };
        void setNomeAlgoritmo(string nome){ nomeAlgoritmo = nome; };
        void setTamanhoInstancia(int tam){ tamanhoInstancia = tam; };
        int getTamanhoInstancia() { return tamanhoInstancia; };
        string getNomeInstancia(){ return nomeInstancia; };
        char* getTipoInstancia(){ return tipoInstancia; };
        string getNomeAlgoritmo(){ return nomeAlgoritmo; };

};

#endif // ORDENACAO_H_INCLUDED
