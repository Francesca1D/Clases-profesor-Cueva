//
// Created by cueva.r on 27/05/2026.
//

#ifndef HERPLATOS_PLATOFONDO_H
#define HERPLATOS_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo: public Producto{
    private:
        int proteina;
    public:
        PlatoFondo();
        PlatoFondo(const PlatoFondo &orig);
        virtual ~PlatoFondo();
        int  get_proteina() const;
        void set_proteina(int proteina);
        void lee(ifstream &arch);
        char tiposoy();
        void imprimir(ofstream &arch);
        Producto *asignapoli() const;

};


#endif //HERPLATOS_PLATOFONDO_H