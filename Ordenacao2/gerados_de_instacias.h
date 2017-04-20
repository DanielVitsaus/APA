#ifndef GERADOS_DE_INSTACIAS_H_INCLUDED
#define GERADOS_DE_INSTACIAS_H_INCLUDED


#include <vector>
#include <iostream>
#include <fstream>
#include "util.h"


using namespace std;

class GeraInstacias{

    private:
    ofstream arquivoGravacao;
        vector<int> valores;

    public:
        void ordenCrescente(int tam);
        void ordenDecrecente(int tam);
        void comRepeticao(int tam);
        void semRepeticao(int tam);

}

#endif // GERADOS_DE_INSTACIAS_H_INCLUDED
