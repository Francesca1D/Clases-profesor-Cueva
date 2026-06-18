/* 
 * File:   generico.cpp
 * Author: cueva.r
 * 
 * Created on 11 de junio de 2025, 10:10 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "generico.h"

using namespace std;

generico::generico() {
    pais=nullptr;
}


generico::generico(const generico& orig) {
}

generico::~generico() {
}


void generico::SetPais(char* cad) {
    if(cad==nullptr)return;
    if(pais!=nullptr) delete pais;
    pais = new char[strlen(cad)+1];
    strcpy(pais,cad);
}

void generico::GetPais(char *cad) const {
    if(pais!=nullptr) strcpy(cad,pais);
}
/*
 0,53084,MINOCICLINA 100MG 10T,650,0.85,PERU
 */
void generico::lee(ifstream&arch){
    char cad[100];
    medicamento::lee(arch);
    arch.getline(cad,100);
    SetPais(cad);
}

void generico::imprime(ofstream&arch){
    medicamento::imprime(arch);
    arch << setw(40)<< pais <<endl;    
}