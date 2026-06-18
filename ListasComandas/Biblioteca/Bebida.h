//
// Created by cffmg on 5/26/2026.
//

#ifndef CLASESHERENCIAS_BEBIDA_H
#define CLASESHERENCIAS_BEBIDA_H

#include "Producto.h"

class Bebida: public Producto {
public:
    Bebida();
    virtual ~Bebida();
    Bebida(const Bebida &);
    void get_tamano(char *);
    void set_tamano(const char *);
    void lee(ifstream &);
    char tiposoy();
    void imprimir(ofstream &);
    Producto *asignapoli() const;
private:
    char *tamano;
};



#endif //CLASESHERENCIAS_BEBIDA_H
