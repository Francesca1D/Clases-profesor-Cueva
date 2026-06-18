//
// Created by cueva.r on 9/06/2026.
//

#ifndef POLICOMANDAS_NODO_H
#define POLICOMANDAS_NODO_H
#include "DetalleComanda.h"


class Nodo {
    private:
        DetalleComanda dato;
        Nodo* sig;
    public:
        Nodo();
        void carganodo(ifstream &arch);
        void imprimenodo(ofstream &arch);
        friend class Cola;
};


#endif //POLICOMANDAS_NODO_H