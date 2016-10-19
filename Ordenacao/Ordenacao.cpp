#include "Ordenacao.h"


#include <time.h>
#include <sys/time.h>
#include <chrono>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

//void Ordenacao::ordena(int * vet, int tam){}


int Ordenacao::getNumInstrucao()
{
    return this->numInstrucao;
}

float Ordenacao::getTimeSpent()
{

    return ( ( (float) (chrono::duration_cast<chrono::nanoseconds> (this->end_time - this->start_time).count() ) ) / 1000000000 );
}


chrono::time_point<chrono::system_clock> Ordenacao::getStartTime()
{
    return this->start_time;
}

chrono::time_point<chrono::system_clock> Ordenacao::getEndTime()
{
    return this->end_time;
}

time_t Ordenacao::getDate()
{
    this->end_timeF = chrono::system_clock::to_time_t(this->end_time);
    return this->end_timeF;
}
