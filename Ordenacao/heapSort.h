#ifndef HEAPSORT_H_INCLUDED
#define HEAPSORT_H_INCLUDED

#include <time.h>
#include <chrono>
#include <ctime>

using namespace std;

class HeapSort
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

#endif // HEAPSORT_H_INCLUDED
