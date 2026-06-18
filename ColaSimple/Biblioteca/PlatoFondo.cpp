//
// Created by cueva.r on 27/05/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina = 0;
}
PlatoFondo::~PlatoFondo() {

}

PlatoFondo::PlatoFondo(const PlatoFondo &orig):Producto(orig) {
    proteina = orig.proteina;
}


void PlatoFondo::lee(ifstream &arch) {
    int num;
    Producto::lee(arch);
    arch >> proteina;
}

char PlatoFondo::tiposoy() {
    return 'P';
}


int  PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int proteina) {
    this->proteina = proteina;
}

void PlatoFondo::imprimir(ofstream &arch) {
    Producto::imprimir(arch);
    if (proteina == 1)
        arch<<" pollo"<<endl;
    if (proteina == 2)
        arch<<" carne"<<endl;
    if (proteina == 3)
        arch<<" pescado"<<endl;
    if (proteina == 4)
        arch<<" mix de carnes"<<endl;
}

Producto *PlatoFondo::asignapoli() const {
    return new PlatoFondo(*this);
}