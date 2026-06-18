//
// Created by cueva.r on 9/06/2026.
//

#include "Cola.h"

Cola::Cola() {
    longitud = 0;
    cabeza=nullptr;
    cola=nullptr;
}


int Cola::get_longitud() const {
    return longitud;
}

void Cola::set_longitud(int longitud) {
    this->longitud = longitud;
}

void Cola::encola(DetalleComanda &dato) {
    Nodo*nuevo;
    nuevo=new Nodo;
    nuevo->dato=dato;
    if (cabeza==nullptr) {
        cola=nuevo;
        cabeza=nuevo;
    }
    else {
        cola->sig = nuevo;
        cola = nuevo;
    }
    longitud++;
}

void Cola::desencola(DetalleComanda& det) {
    Nodo *aux;
    if (cabeza!=nullptr) {
        aux=cabeza;
        cabeza=cabeza->sig;
        aux->sig=nullptr;
    }
    longitud--;
    det=aux->dato;
}