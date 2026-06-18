//
// Created by cueva on 5/26/2026.
//
#include <cstring>
#include <iomanip>
#include "Bebida.h"

using namespace std;

Bebida::Bebida() {
    tamano = nullptr;
}

Bebida::~Bebida() {
    if (tamano != nullptr) delete tamano;
}

Bebida::Bebida(const Bebida &orig):Producto(orig) {

    if (orig.tamano!=nullptr){
        tamano = new char[strlen(orig.tamano) + 1];
        strcpy(tamano, orig.tamano);
    }
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
void Bebida::lee(ifstream &arch) {
    char cad[50];
    Producto::lee(arch);
    arch.getline(cad,50);
    set_tamano(cad);
}

char Bebida::tiposoy() {
   return 'B';
}

void Bebida::imprimir(ofstream &arch) {
    Producto::imprimir(arch);
    arch <<setw(10)<<tamano <<endl;

}

Producto *Bebida::asignapoli() const {
    return new Bebida(*this);
}