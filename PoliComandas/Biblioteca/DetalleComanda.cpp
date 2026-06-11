//
// Created by cueva.r on 2/06/2026.
//

#include "DetalleComanda.h"

#include "Bebida.h"
#include "Entrada.h"
#include "PlatoFondo.h"

DetalleComanda::DetalleComanda() {
    id = 0;
    pedido = nullptr;
}
DetalleComanda::~DetalleComanda() {
    if (pedido!=nullptr) {
        delete pedido;
    }
}
int DetalleComanda::get_id() const {
    return id;
}
void DetalleComanda::set_id(int id) {
    this->id = id;
}
//738,P,Pollo a la Brasa,15,1
//738,P,Hamburguesa,8.5,2

void DetalleComanda::leecomandas(ifstream &arch) {
    char tipo,c;
    arch >> id;
    if (arch.eof())return;
    arch>>c>>tipo>>c;
    if (tipo=='E')
        pedido=new Entrada;
    if (tipo=='P')
        pedido =  new PlatoFondo;
    if (tipo=='B')
        pedido = new Bebida;
    pedido->lee(arch);
}
void DetalleComanda::operator=(DetalleComanda &orig) {
    id=orig.id;
    char tipo=orig.pedido->tiposoy();
    if (tipo=='E') {
        pedido=new Entrada;
    }
    if (tipo=='P')
        pedido =  new PlatoFondo;
    if (tipo=='B')
        pedido = new Bebida;

}

char DetalleComanda::tipo() {
    return pedido->tiposoy();
}

void DetalleComanda::imprimecomandas(ofstream &arch) {
    pedido->imprimir(arch);
}
