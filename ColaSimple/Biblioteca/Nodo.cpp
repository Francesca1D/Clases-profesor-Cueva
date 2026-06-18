//
// Created by cueva.r on 9/06/2026.
//

#include "Nodo.h"

Nodo::Nodo() {
    sig = nullptr;
}

void Nodo::carganodo(ifstream &arch) {
    dato.leecomandas(arch);
}

void Nodo::imprimenodo(ofstream &arch) {
    dato.imprimecomandas(arch);
}
