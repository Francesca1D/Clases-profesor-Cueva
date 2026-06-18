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

void Cola::encola(Nodo* nuevo) {
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

Nodo* Cola::desencola() {
    Nodo *aux;
     if (cabeza!=nullptr) {
        aux=cabeza;
        cabeza=cabeza->sig;
        aux->sig=nullptr;
    }
    longitud--;
    return aux;
}

void Cola::cargacola(ifstream &arch) {
    while (true) {
        Nodo *nuevo;
        nuevo=new Nodo();
        nuevo->carganodo(arch);
        if (arch.eof()) break;
        encola(nuevo);
    }

}

void Cola::imprimecola(ofstream &arch) {
    Nodo *aux;
    int n=longitud;
    for (int i=0;i<n;i++) {
        aux=desencola();
        aux->imprimenodo(arch);
    }

}
