//
// Created by cffmg on 5/26/2026.
//

#ifndef CLASESHERENCIAS_COMANDA_H
#define CLASESHERENCIAS_COMANDA_H

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

class Comanda {
    private:
        int id;
        Bebida bebidas[200];
        PlatoFondo platos_fondo[200];
        Entrada *entradas;
        int cantidad_bebidas;
        int cantidad_platos;
        int hora_atencion;
        int hora_servicio;
        int tiempo_preparacion;
        double total;
    public:
        Comanda();
        virtual ~Comanda();
        int get_id() const;
        void set_id(int id);
        int get_cantidad_bebidas() const;
        void set_cantidad_bebidas(int cantidad_bebidas);
        int get_hora_atencion() const;
        void set_hora_atencion(int hora_atencion);
        int get_hora_servicio() const;
        void set_hora_servicio(int hora_servicio);
        int get_tiempo_preparacion() const;
        void set_tiempo_preparacion(int tiempo_preparacion);
        double get_total() const;
        void set_total(double total);
        int get_cantidad_platos() const;
        void set_cantidad_platos(int cantidad_platos);
        void leecomanda(char tipo,ifstream&);
};



#endif //CLASESHERENCIAS_COMANDA_H
