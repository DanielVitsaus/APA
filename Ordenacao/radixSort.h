#ifndef RADIXSORT_H_INCLUDED
#define RADIXSORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>

using namespace std;

class RadixSort
{
    private:
        chrono::time_point<chrono::system_clock> start_time;
        chrono::time_point<chrono::system_clock> end_time;
        time_t end_timeF;
        int* vetOrdenado;
        int* digitos;
        int maiorV;
        int exp;
        int numInstrucao;

    public:
        int* ordena(int* vet, int tam);
        chrono::time_point<chrono::system_clock> getStartTime();
        chrono::time_point<chrono::system_clock> getEndTime();
        time_t getDate();
        int getNumInstrucao();
        float getTimeSpent();
};


#endif // RADIXSORT_H_INCLUDED
