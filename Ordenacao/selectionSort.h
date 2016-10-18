#ifndef SELECTIONSORT_H_INCLUDED
#define SELECTIONSORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>

using namespace std;

class SelectionSort
{
    private:
        chrono::time_point<chrono::system_clock> start_time;
        chrono::time_point<chrono::system_clock> end_time;
        time_t end_timeF;
        int numInstrucao;

    public:
        void ordena(int * vet, int tam);
        chrono::time_point<chrono::system_clock> getStartTime();
        chrono::time_point<chrono::system_clock> getEndTime();
        time_t getDate();
        int getNumInstrucao();
        float getTimeSpent();

};

#endif // SELECTIONSORT_H_INCLUDED
