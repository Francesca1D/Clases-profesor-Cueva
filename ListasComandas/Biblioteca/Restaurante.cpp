//
// Created by cueva.r on 2/06/2026.
//

#include "Restaurante.h"

Restaurante::Restaurante() {

}

Restaurante::~Restaurante() {

}

void Restaurante::carga() {
    ifstream arch("comandas2.csv", ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo de comandas";
        exit(1);
    }
    DetalleComanda aux;
    while (true) {
        aux.leecomandas(arch);
        if (arch.eof())break;
        Ccomanda.encola(aux);
    }
}
void Restaurante::atiende() {
    ofstream arch("reporte.txt", ios::out);
    if (not arch) {
        cout <<"No se puede abrir el archivo de reporte.txt";
        exit(1);
    }
    int n=Ccomanda.get_longitud();
    DetalleComanda aux;
    for (int i=1;i<n;i++) {
        Ccomanda.desencola(aux);
        aux.imprimecomandas(arch);
    }

}


