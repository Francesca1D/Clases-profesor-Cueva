//
// Created by cueva.r on 6/05/2026.
//
#include <iostream>
#include <cstring>
#include <iomanip>
#include "Infraccion.h"

using namespace std;

Infraccion::Infraccion() {
    codigo = 0;
    descripcion=nullptr;
    gravedad=nullptr;
    multa=0;

}
Infraccion::~Infraccion() {
    delete descripcion;
    delete gravedad;

}

void Infraccion::get_descripcion(char* cad) {
    if (this->descripcion==nullptr)cad[0]=0;
    else
        strcpy(cad,this->descripcion);
}

void Infraccion::set_descripcion(const char* cad) {
    if (this->descripcion!=nullptr)
        delete this->descripcion;
    this->descripcion=new char[strlen(cad)+1];
    strcpy(this->descripcion,cad);
}

void Infraccion::get_gravedad(char* cad) {
    if (this->gravedad==nullptr)cad[0]=0;
    else
        strcpy(cad,this->gravedad);
}

void Infraccion::set_gravedad(const char* cad) {
    if (this->gravedad!=nullptr)
        delete this->gravedad;
    this->gravedad=new char[strlen(cad)+1];
    strcpy(this->gravedad,cad);
}

int Infraccion::get_codigo() const {
    return codigo;
}

void Infraccion::set_codigo(int codigo) {
    this->codigo = codigo;
}

double Infraccion::get_multa() const {
    return multa;
}

void Infraccion::set_multa(double multa) {
    this->multa = multa;
}

void Infraccion::operator=(Infraccion &obj) {
    char cad[200];
    this->codigo=obj.codigo;
    obj.get_descripcion(cad);
    set_descripcion(cad);
    obj.get_gravedad(cad);
    set_gravedad(cad);
    multa=obj.multa;
}

void operator>>(ifstream &arch, Infraccion &obj) {
    int codigo;
    double multa;
    char cad[300];
    arch >> codigo;
    if (arch.eof()) return;
    arch.get();
    arch >> multa;
    arch.get();
    arch.getline(cad,20,',');
    obj.set_gravedad(cad);
    arch.getline(cad,200,'\n');
    obj.set_descripcion(cad);
    obj.set_codigo(codigo);
    obj.set_multa(multa);
}
void operator<<(ofstream &arch, Infraccion &obj) {
    char cad[200];
    arch <<setw(10)<< obj.get_codigo();
    arch <<setw(10)<<setprecision(2)<<fixed<< obj.get_multa();
    obj.get_gravedad(cad);
    arch <<setw(20) <<cad;
    obj.get_descripcion(cad);
    arch <<setw(100)<<cad<<endl;
}
