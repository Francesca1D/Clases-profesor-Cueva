/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Nodo.cpp
 * Author: cueva.r
 * 
 * Created on 10 de junio de 2025, 11:43 AM
 */

#include "Nodo.h"
#include "generico.h"
#include "marca.h"

Nodo::Nodo() {
    med=nullptr;
    izq=nullptr;
    der=nullptr;
}

Nodo::Nodo(const Nodo& orig) {
}

Nodo::~Nodo() {
}

void Nodo::asignamemoria(int tipo){
    if(tipo==0)
        med = new generico;
    else
        med = new marca;
}

void Nodo::leemedicamento(ifstream&arch){
    med->lee(arch);
}

bool Nodo::compara(Nodo& nuevo){
    
    if(med->getCodigo()>nuevo.med->getCodigo())
        return true;
    return false;
}
