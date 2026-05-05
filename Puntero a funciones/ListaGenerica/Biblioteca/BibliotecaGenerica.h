//
// Created by cueva.r on 22/04/2026.
//

#ifndef LISTAGENERICA_BIBLIOTECAGENERICA_H
#define LISTAGENERICA_BIBLIOTECAGENERICA_H
#include <fstream>
using namespace std;
    void generaLista(void *&lista);
    void creaLista(void *&lista,void*(*lee)(ifstream&),
        int(*clasifica)(void*),const char*nom);
    void insertaLista(void*&lista,void*dato,int(*clasifica)(void*));
    void imprimeLista(void*lista,void(*imprime)(ofstream&,void*),const char*nom);
    void cargayordena(void*(*lee)(ifstream&),void(*imprime)(ofstream&,void*),
        int (*compara)(const void*,const void*),const char*nom, const char*nrep);
#endif //LISTAGENERICA_BIBLIOTECAGENERICA_H