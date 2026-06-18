/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   almacen.h
 * Author: cueva.r
 *
 * Created on 11 de junio de 2025, 10:33 AM
 */

#ifndef ALMACEN_H
#define ALMACEN_H
#include <fstream>
#include "Arbol.h"

using namespace std;

class almacen {
public:
    almacen();
    almacen(const almacen& orig);
    virtual ~almacen();
    void carga();
    void imprime();
    
private:
    Arbol arbolalma;
    
};

#endif /* ALMACEN_H */

