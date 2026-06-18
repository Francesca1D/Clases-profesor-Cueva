
/* 
 * File:   medicamento.cpp
 * Author: cueva.r
 * 
 * Created on 3 de junio de 2025, 11:15 AM
 */
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "medicamento.h"

using namespace std;

medicamento::medicamento() {
    codigo=0;
    nombre=nullptr;
    precio=0;
    stock=0;
    
}
void medicamento::setPrecio(double precio) {
    this->precio = precio;
}

double medicamento::getPrecio() const {
    return precio;
}


void medicamento::setNombre(char* cad) {
    if(cad==nullptr)return;
    if(nombre!=nullptr) delete nombre;
    nombre = new char[strlen(cad)+1];
    strcpy(nombre,cad);
}

void medicamento::getNombre(char *cad) const {
    if(nombre!=nullptr) strcpy(cad,nombre);
}

void medicamento::setCodigo(int codigo) {
    this->codigo = codigo;
}

int medicamento::getCodigo() const {
    return codigo;
}

medicamento::medicamento(const medicamento& orig) {
}

medicamento::~medicamento() {
}
void medicamento::setStock(int stock) {
    this->stock = stock;
}

int medicamento::getStock() const {
    return stock;
}
/*
 30007,DICLOFENACO SODICO 1MG GTS 5 ML,500,0.85,USA
 */
void medicamento::lee(ifstream&arch){
    char cad[100],c;
    arch >> codigo;
    arch.get();
    arch.getline(cad,100,',');
    setNombre(cad);
    arch>>stock >>c >>precio>>c ;
}


void medicamento::imprime(ofstream&arch){
    arch <<setw(10)<< codigo <<setw(50)<< nombre;
    arch <<setw(10)<< stock <<setprecision(2)<<fixed <<setw(10)<<precio; 

}