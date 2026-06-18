//
// Created by cueva.r on 2/06/2026.
//

#ifndef POLICOMANDAS_RESTAURANTE_H
#define POLICOMANDAS_RESTAURANTE_H
#include "Cola.h"
#include "DetalleComanda.h"

class Restaurante {
    private:
        Cola Ccomanda;
    public:
        Restaurante();
        ~Restaurante();
        void carga();
        void atiende();
};

#endif //POLICOMANDAS_RESTAURANTE_H