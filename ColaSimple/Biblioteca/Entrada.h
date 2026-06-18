//
// Created by cueva.r on 27/05/2026.
//

#ifndef HERPLATOS_ENTRADA_H
#define HERPLATOS_ENTRADA_H
#include "Producto.h"


class Entrada: public Producto {
    private:
        bool picante;
    public:
        Entrada();
        Entrada(const Entrada &orig);
        virtual ~Entrada();
        bool is_picante() const;
        void set_picante(bool picante);
        void lee(ifstream&);
        void operator=(Entrada&);
        char tiposoy();
        void imprimir(ofstream&);
        Producto *asignapoli() const;

};




#endif //HERPLATOS_ENTRADA_H
