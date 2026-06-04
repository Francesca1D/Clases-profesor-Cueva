//
// Created by cueva on 5/26/2026.
//
#include <cstring>
#include "Bebida.h"

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if (tamano != nullptr) delete tamano;
}

void Bebida::get_tamano(char *cad) {
    if (tamano == nullptr) cad[0] = '\0';
    else strcpy(cad, tamano);
}

void Bebida::set_tamano(const char *cad) {
    if (tamano != nullptr) delete tamano;
    tamano = new char[strlen(cad)+1];
    strcpy(tamano,cad);
}
//Cafe,2,grande
void Bebida::leebebidas(ifstream &arch) {
    char cad[50];
    leeproducto(arch);
    arch.getline(cad,50);
    set_tamano(cad);
}
