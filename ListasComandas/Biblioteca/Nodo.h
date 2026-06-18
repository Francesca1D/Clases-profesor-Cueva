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
        friend class Cola;
};


#endif //POLICOMANDAS_NODO_H