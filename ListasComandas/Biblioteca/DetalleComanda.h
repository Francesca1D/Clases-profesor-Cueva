//
// Created by cueva.r on 2/06/2026.
//

#ifndef POLICOMANDAS_DETALLECOMANDA_H
#define POLICOMANDAS_DETALLECOMANDA_H
#include "Producto.h"


class DetalleComanda {
    private:
        int id;
        Producto *pedido;
    public:
        int get_id() const;
        void set_id(int id);
        DetalleComanda();
        virtual ~DetalleComanda();
        DetalleComanda(DetalleComanda &orig);
        void leecomandas(ifstream &);
        void imprimecomandas(ofstream &);
        void operator=(DetalleComanda&);
        char tipo();
};


#endif //POLICOMANDAS_DETALLECOMANDA_H