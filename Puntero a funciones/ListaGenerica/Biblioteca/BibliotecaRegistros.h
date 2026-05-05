//
// Created by cueva.r on 29/04/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAREGISTROS_H
#define LISTAGENERICA_BIBLIOTECAREGISTROS_H
#include <fstream>
using namespace std;
    void* leeregistro(ifstream&arch);
    int clasificaregistro(void*dato);
    char* leecadena(ifstream &arch,int max,char deli);
    void imprimeregistro(ofstream &arch,void*dato);
    int comparareg(const void*a,const void*b);
#endif //LISTAGENERICA_BIBLIOTECAREGISTROS_H