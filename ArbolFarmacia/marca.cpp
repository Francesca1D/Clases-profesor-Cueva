/* 
 * File:   marca.cpp
 * Author: cueva.r
 * 
 * Created on 11 de junio de 2025, 10:17 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "marca.h"
#include "medicamento.h"

using namespace std;


marca::marca() {
    lote=0;
    laboratorio=nullptr;
}

marca::marca(const marca& orig) {
}

marca::~marca() {
}
void marca::SetLaboratorio(char* cad) {
    if(cad==nullptr)return;
    if(laboratorio!=nullptr) delete laboratorio;
    laboratorio = new char[strlen(cad)+1];
    strcpy(laboratorio,cad);
}

void marca::GetLaboratorio(char *cad) const {
    if(laboratorio!=nullptr) strcpy(cad,laboratorio);
}


void marca::SetLote(int lote) {
    this->lote = lote;
}

int marca::GetLote() const {
    return lote;
}
/*
 1,26754,SILDENAFIL 50MG C/1-TAB,3180,68,LABORATORIO ASTRAZENECA,1630
*/
void marca::lee(ifstream&arch){
    char cad[100];
    medicamento::lee(arch);
    arch.getline(cad,100,',');
    SetLaboratorio(cad);
    arch>>lote;
}

void marca::imprime(ofstream& arch){
    medicamento::imprime(arch);
    arch << setw(50)<< laboratorio << setw(10)<<lote<<endl;
}
