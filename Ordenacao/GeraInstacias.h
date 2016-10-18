#ifndef GERAINSTACIAS_H_INCLUDED
#define GERAINSTACIAS_H_INCLUDED

#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

class GeraInstacias
{

    private:
        ofstream arquivoGravacao;
        vector<int> valores;

    public:
        GeraInstacias();
        void ordenCrescente(int tam);
        void ordenDecrecente(int tam);
        void comRepeticao(int tam);
        void semRepeticao(int tam);

};

#endif // GERAINSTACIAS_H_INCLUDED
