//
// Created by cueva.r on 27/05/2026.
//

#include "Entrada.h"

Entrada::Entrada() {
    picante = false;
}
Entrada::~Entrada() {
}


bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}
// 841,E,Nachos,5,sin picante
void Entrada::lee(ifstream& arch) {
    char cad[50];
    Producto::lee(arch);
    arch.getline(cad, 50);
    if (strcmp(cad, "picante")==0)
        picante = true;
}

void Entrada::operator=(Entrada& obj) {
    char cad[50];

    picante = obj.picante;
    set_precio(obj.get_precio());
    obj.get_nombre(cad);
    set_nombre(cad);
}

char Entrada::tiposoy() {
    return 'E';
}

void Entrada::imprimir(ofstream& arch) {
    Producto::imprimir(arch);
    if (picante)
        arch<<" picante"<<endl;
    else
        arch<<" sin picante"<<endl;

}