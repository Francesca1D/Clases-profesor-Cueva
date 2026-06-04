//
// Created by cffmg on 5/26/2026.
//

#include "Comanda.h"

Comanda::Comanda() {
    id=0;
    cantidad_bebidas=0;
    hora_atencion=0;
    hora_servicio=0;
    tiempo_preparacion=0;
    total=0;
    entradas = nullptr;
}
Comanda::~Comanda() {
    delete[] entradas;
}


int Comanda::get_cantidad_platos() const {
    return cantidad_platos;
}

void Comanda::set_cantidad_platos(int cantidad_platos) {
    this->cantidad_platos = cantidad_platos;
}



int Comanda::get_id() const {
    return id;
}

void Comanda::set_id(int id) {
    this->id = id;
}

int Comanda::get_cantidad_bebidas() const {
    return cantidad_bebidas;
}

void Comanda::set_cantidad_bebidas(int cantidad_bebidas) {
    this->cantidad_bebidas = cantidad_bebidas;
}

int Comanda::get_hora_atencion() const {
    return hora_atencion;
}

void Comanda::set_hora_atencion(int hora_atencion) {
    this->hora_atencion = hora_atencion;
}

int Comanda::get_hora_servicio() const {
    return hora_servicio;
}

void Comanda::set_hora_servicio(int hora_servicio) {
    this->hora_servicio = hora_servicio;
}

int Comanda::get_tiempo_preparacion() const {
    return tiempo_preparacion;
}

void Comanda::set_tiempo_preparacion(int tiempo_preparacion) {
    this->tiempo_preparacion = tiempo_preparacion;
}

double Comanda::get_total() const {
    return total;
}

void Comanda::set_total(double total) {
    this->total = total;
}

void Comanda::leecomanda(char tipo, ifstream &arch) {
    if (tipo =='B') {
        bebidas[cantidad_bebidas].leebebidas(arch);
        cantidad_bebidas++;
    }
    if (tipo =='P') {
        platos_fondo[cantidad_platos].leeplatos(arch);
        cantidad_platos++;
    }
    if (tipo =='E') {
        ///????? como hago??, lo vemos el viernes!!!!!
    }

}

