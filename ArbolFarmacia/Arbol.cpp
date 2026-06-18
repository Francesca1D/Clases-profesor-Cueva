/* 
 * File:   Arbol.cpp
 * Author: cueva.r
 * 
 * Created on 10 de junio de 2025, 11:46 AM
 */

#include "Arbol.h"

Arbol::Arbol() {
    raiz = nullptr;
}

Arbol::Arbol(const Arbol& orig) {
}

Arbol::~Arbol() {
}
/*
 0,30007,DICLOFENACO SODICO 1MG GTS 5 ML,500,0.85,USA
 */
void Arbol::inserta(ifstream &arch){
    Nodo*nuevo,*rec;
    int tipo;
    
    arch >> tipo;
    if(arch.eof()) return;
    arch.get();
    nuevo=new Nodo;
    nuevo->asignamemoria(tipo);
    nuevo->leemedicamento(arch);
    rec = raiz;
    
    while(rec){
        if(rec->compara(*nuevo)){
            if(rec->izq==nullptr){
                rec->izq=nuevo;
                break;
            }
            else
                rec=rec->izq;
        }
        else{
            if(rec->der==nullptr){
                rec->der = nuevo;
                break;
            }
            else
                rec=rec->der;
        }
    }
    if(rec==nullptr) raiz=nuevo;
}

void Arbol::imprimereporte(ofstream&arch){
    enorden(arch,raiz);
}

void Arbol::enorden(ofstream& arch,Nodo *&rec){
    if(rec==nullptr) return;
    enorden(arch,rec->izq);
    rec->med->imprime(arch);
    enorden(arch,rec->der);
    
}