//
// Created by cueva.r on 27/05/2026.
//

#include "PlatoFondo.h"

PlatoFondo::PlatoFondo() {
    proteina = nullptr;
}
PlatoFondo::~PlatoFondo() {
    if (proteina != nullptr)
        delete proteina;
}
// 981,P,Strogonoff,25.75,0,1,0,0
void PlatoFondo::leeplatos(ifstream &arch) {
    int c0,c1,c2,c3;
    char c;
    leeproducto(arch);
    arch >> c0 >> c>>c1>>c>>c2>>c>>c3;
    proteina= new int[4];
    proteina[0] = c0;
    proteina[1] = c1;
    proteina[2] = c2;
    proteina[3] = c3;

}



int * PlatoFondo::get_proteina() const {
    return proteina;
}

void PlatoFondo::set_proteina(int *proteina) {
    this->proteina = proteina;
}
