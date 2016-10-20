#ifndef GERAINSTACIAS_H_INCLUDED
#define GERAINSTACIAS_H_INCLUDED

#include <vector>
#include <iostream>
#include <fstream>


using namespace std;

class GeraInstancias
{

    private:
        ofstream arquivoGravacao;
        vector<int> valores;

    public:
        GeraInstancias();
        void ordenCrescente(int tam);
        void ordenDecrecente(int tam);
        void comRepeticao(int tam);
        void semRepeticao(int tam);

};

#endif // GERAINSTACIAS_H_INCLUDED
