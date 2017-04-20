#ifndef DADOS_H_INCLUDED
#define DADOS_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;


class Dados
{
    public:
        string nome;
        float salario;
        int id;

        void setNome( string n );
        void setSalario( float s);
        void setId( int id);

        string getNome();
        float getSalario();
        int getId();

};

#endif // DADOS_H_INCLUDED
