#include "Dados.h"

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <string.h>


using namespace std;

void Dados::setNome( string n )
{
    this->nome = n;
}

void Dados::setSalario( float s)
{
    this->salario = s;
}

void Dados::setId( int id)
{
    this->id = id;
}

string Dados::getNome()
{
    return this->nome;
}

float Dados::getSalario()
{
    return this->salario;
}

int Dados::getId()
{
    return this->id;
}
