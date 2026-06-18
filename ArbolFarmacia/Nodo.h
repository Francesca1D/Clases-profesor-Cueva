
/* 
 * File:   Nodo.h
 * Author: cueva.r
 *
 * Created on 10 de junio de 2025, 11:43 AM
 */

#ifndef NODO_H
#define NODO_H

#include "medicamento.h"


class Nodo {
public:
    Nodo();
    Nodo(const Nodo& orig);
    virtual ~Nodo();

    void asignamemoria(int);
    void leemedicamento(ifstream&);
    bool compara(Nodo &);
    friend class Arbol;
private:
    medicamento *med;
    Nodo*izq;
    Nodo*der;

};

#endif /* NODO_H */

