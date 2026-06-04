//
// Created by cffmg on 5/26/2026.
//
#include <fstream>
#include <iostream>
#include "Restaurante.h"

using namespace std;

Restaurante::Restaurante() {
    cant_comandas=0;
}

int Restaurante::get_cant_comandas() const {
    return cant_comandas;
}

void Restaurante::set_cant_comandas(int cant_comandas) {
    this->cant_comandas = cant_comandas;
}
//972,23:34,00:32
//648,18:12,19:32
void Restaurante::cargar_comandas() {
    int id,ha,ma,hs,ms;
    char c;
    ifstream arch("atenciones.csv",ios::in);
    if (not arch) {
        cout<< "No se puede abrir atenciones.csv"<< endl;
        exit(1);
    }
    while (true) {
        arch >> id;
        if (arch.eof()) break;
        comandas[cant_comandas].set_id(id);
        arch >> c >>ha>>c>>ma>>c>>hs>>c>>ms;
        comandas[cant_comandas].set_hora_atencion(ha*60+ma);
        comandas[cant_comandas].set_hora_servicio(hs*60+ms);
        buscayasigna(id);
        cant_comandas++;
    }
}
void Restaurante::buscayasigna(int pid) {
    int idcom;
    char c,cad[100],tipo;
    ifstream arch("comandas.csv",ios::in);
    if (not arch) {
        cout<< "No se puede abrir comandas.csv"<< endl;
        exit(1);
    }
    while (true) {
        arch >> idcom;
        if (arch.eof())break;
        if (pid==idcom) {
            arch>>c>>tipo>>c;
            comandas[cant_comandas].leecomanda(tipo,arch);
        }
        else
            arch.getline(cad,100);
    }


}