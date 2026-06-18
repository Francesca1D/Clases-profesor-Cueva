//
// Created by cueva.r on 9/06/2026.
//

#ifndef POLICOMANDAS_COLA_H
#define POLICOMANDAS_COLA_H
#include "Nodo.h"


class Cola {
    private:
        int longitud;
        Nodo *cabeza;
        Nodo *cola;
    public:
        Cola();
        int get_longitud() const;
        void set_longitud(int longitud);
        void encola(DetalleComanda &);
        void desencola(DetalleComanda&);
};


#endif //POLICOMANDAS_COLA_H