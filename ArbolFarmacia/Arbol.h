
/* 
 * File:   Arbol.h
 * Author: cueva.r
 *
 * Created on 10 de junio de 2025, 11:46 AM
 */

#ifndef ARBOL_H
#define ARBOL_H

#include "Nodo.h"


class Arbol {
public:
    Arbol();
    Arbol(const Arbol& orig);
    virtual ~Arbol();
    void inserta(ifstream &arch);
    void imprimereporte(ofstream &);
private:
    void enorden(ofstream &arch,Nodo*&);
    Nodo *raiz;
};

#endif /* ARBOL_H */

