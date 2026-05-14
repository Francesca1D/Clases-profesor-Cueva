//
// Created by cueva.r on 6/05/2026.
//
#include <iostream>
#include <cstring>
#include "Empresa.h"

using namespace std;

Empresa::Empresa() {
    dni=0;
    nombre=nullptr;
    numPlacas=0;
    numMultas=0;
    for (int i=0;i<10;i++)
        placas[i]=nullptr;
}
Empresa::~Empresa() {
    delete nombre;
    for (int i=0;i<10;i++)
        if (placas[i]!=nullptr)
            delete placas[i];
}


int Empresa::get_dni() const {
    return dni;
}

void Empresa::set_dni(int dni) {
    this->dni = dni;
}

int Empresa::get_num_placas() const {
    return numPlacas;
}

void Empresa::set_num_placas(int num_placas) {
    numPlacas = num_placas;
}

int Empresa::get_num_multas() const {
    return numMultas;
}

void Empresa::set_num_multas(int num_multas) {
    numMultas = num_multas;
}

void Empresa::get_nombre(char* cad) {
    if (this->nombre==nullptr)cad[0]=0;
    else
        strcpy(cad,this->nombre);
}

void Empresa::set_nombre(const char* cad) {
    if (this->nombre!=nullptr)
        delete this->nombre;
    this->nombre=new char[strlen(cad)+1];
    strcpy(this->nombre,cad);
}

void operator>>(ifstream &arch, Empresa &obj) {
    int dni;
    char cad[200];
    arch >> dni;
    if (arch.eof())return;
    arch.get();
    obj.set_dni(dni);
    arch.getline(cad,200,',');
    obj.set_nombre(cad);
    obj.leeplacas(arch);
}

void Empresa::leeplacas(ifstream &arch) {
    char cad[10];
    while (true) {
        arch.get(cad,9);
        setPlacaI(cad,numPlacas);
        numPlacas++;
        if (arch.get()=='\n')break;
    }
}

void Empresa::setPlacaI(const char *placa, int i) {
    if (placas[i]!=nullptr)delete placas[i];
    placas[i]=new char[strlen(placa)+1];
    strcpy(placas[i],placa);
}

void Empresa::getPlacaI(char* placa,int i) {
    if (placas[i]==nullptr)placa[0]=0;
    else
        strcpy(placa,placas[i]);
}

void Empresa::operator+=(Multa &obj) {
    multas[numMultas]=obj;
    numMultas++;
}
