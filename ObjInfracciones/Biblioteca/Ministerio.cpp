//
// Created by cueva.r on 12/05/2026.
//
#include <iostream>
#include <fstream>
#include "Ministerio.h"

using namespace std;

Ministerio::Ministerio() {
    infracciones=nullptr;
    numInf=0;
    numEmpresas=0;
}
Ministerio::~Ministerio() {
    if (infracciones!=nullptr)
        delete []infracciones;
}

void Ministerio::operator <(const char*nom) {
    Infraccion buffer[200];
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch >> buffer[i];
        if (arch.eof())break;
        i++;
    }
    infracciones=new Infraccion[i+1];
    for (int j=0;j<i;j++) {
        infracciones[j]=buffer[j];
    }
    numInf=i;
}

void Ministerio::operator <=(const char*nom) {
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo "<<nom<<endl;
        exit(1);
    }
    int i=0;
    while (true) {
        arch >> empresas[i];
        if (arch.eof())break;
        i++;
    }
}

void Ministerio::carga() {
    Multa aux;
    aux.set_codigo_infraccion(9999);
    aux.set_placa("ZZZ-666");
    aux.set_multa(600);
    empresas[0]+=aux;
    cout <<"Repite";
}