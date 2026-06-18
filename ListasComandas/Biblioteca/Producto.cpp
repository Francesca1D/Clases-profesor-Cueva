//
// Created by Cueva on 5/26/2026.
//
#include <iomanip>
#include "Producto.h"

using namespace std;

Producto::Producto() {
    nombre = nullptr;
    precio = 0;
}

Producto::~Producto() {
    if (nombre != nullptr)
        delete nombre;
}

Producto::Producto(const Producto &orig){
    precio = orig.precio;

    if (orig.nombre!=nullptr){
        nombre = new char[strlen(orig.nombre)+1];
        strcpy(nombre, orig.nombre);
    }
}

void Producto::get_nombre(char *cad) {
    if (nombre == nullptr) cad[0] = '\0';
    else strcpy(cad, nombre);
}

void Producto::set_nombre(const char *cad) {
    if (nombre != nullptr) delete nombre;
    nombre = new char[strlen(cad) + 1];
    strcpy(nombre, cad);
}

double Producto::get_precio() const {
    return precio;
}

void Producto::set_precio(double precio) {
    this->precio = precio;
}
//Cafe,2,grande
void Producto::lee(ifstream &arch) {
  char cad[50],c;
  arch.getline(cad, 50,',');
  set_nombre(cad);
  arch >> precio >> c;
}

void Producto::imprimir(ofstream &arch) {
    arch <<setw(40)<< nombre <<setw(10)<<precio;
}
