/* 
 * File:   almacen.cpp
 * Author: cueva.r
 * 
 * Created on 11 de junio de 2025, 10:33 AM
 */
#include <iostream>
#include <iomanip>
#include <cstring>
#include <fstream>
#include "almacen.h"

using namespace std;


almacen::almacen() {
}

almacen::almacen(const almacen& orig) {
}

almacen::~almacen() {
}

void almacen::carga(){
    ifstream arch("medicamentos.csv",ios::in);
    if(!arch){
        cout <<"No se puede abrir el archivo de medicamentos";
        exit(1);
    }
    while(1){
        arbolalma.inserta(arch);
        if(arch.eof())break;
    }
    
}


void almacen::imprime(){
    ofstream arch("reporte.txt",ios::out);
    if(!arch){
        cout <<"No se puede abrir el archivo de reporte";
        exit(1);
    }    
    arbolalma.imprimereporte(arch);
    
 
}