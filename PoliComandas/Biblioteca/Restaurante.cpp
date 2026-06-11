//
// Created by cueva.r on 2/06/2026.
//

#include "Restaurante.h"

Restaurante::Restaurante() {
    comandas=nullptr;
}

Restaurante::~Restaurante() {
    if (comandas!=nullptr)
        delete []comandas;
}

void Restaurante::carga() {
    // genero un buffer temporal
    comandas = new DetalleComanda[200];
    ifstream arch("comandas2.csv", ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo de comandas";
        exit(1);
    }
    int i=0;
    while (true) {
        comandas[i].leecomandas(arch);
        if (arch.eof())break;
        i++;
    }
   // recorte(i);
}
void Restaurante::imprime() {
    ofstream arch("reporte.txt", ios::out);
    if (not arch) {
        cout <<"No se puede abrir el archivo de reporte.txt";
        exit(1);
    }
    for (int i=0;comandas[i].get_id()!=0;i++) {
        arch<<left<<comandas[i].tipo()<<" ";
        comandas[i].imprimecomandas(arch);
    }

}


void Restaurante::recorte(int n) {
    DetalleComanda *aux=new DetalleComanda[n+1];

    for (int i=0;i<n;i++)
        aux[i]=comandas[i];


}
