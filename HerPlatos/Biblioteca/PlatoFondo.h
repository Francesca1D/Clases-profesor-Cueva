//
// Created by cueva.r on 27/05/2026.
//

#ifndef HERPLATOS_PLATOFONDO_H
#define HERPLATOS_PLATOFONDO_H
#include "Producto.h"


class PlatoFondo: public Producto{
    private:
        int *proteina;

    public:
        int * get_proteina() const;
        void set_proteina(int *proteina);
        PlatoFondo();
        virtual ~PlatoFondo();
        void leeplatos(ifstream &arch);
};


#endif //HERPLATOS_PLATOFONDO_H