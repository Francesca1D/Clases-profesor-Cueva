//
// Created by cueva.r on 2/06/2026.
//

#ifndef POLICOMANDAS_RESTAURANTE_H
#define POLICOMANDAS_RESTAURANTE_H
#include "DetalleComanda.h"

class Restaurante {
    private:
        DetalleComanda *comandas;
        void recorte(int);

    public:
        Restaurante();
        ~Restaurante();
        void carga();
        void imprime();
};

#endif //POLICOMANDAS_RESTAURANTE_H