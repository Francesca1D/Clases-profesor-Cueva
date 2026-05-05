//
// Created by cueva.r on 28/04/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAENTEROS_H
#define LISTAGENERICA_BIBLIOTECAENTEROS_H
#include <fstream>
using namespace std;
    void*leenum(ifstream&arch);
    int clasificaentero(void*dato);
    void imprimenum(ofstream&arch,void*dato);
    int comparanum(const void*a,const void*b);
#endif //LISTAGENERICA_BIBLIOTECAENTEROS_H