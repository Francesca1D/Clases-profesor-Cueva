//
// Created by cffmg on 5/26/2026.
//

#ifndef CLASESHERENCIAS_PRODUCTO_H
#define CLASESHERENCIAS_PRODUCTO_H

#include <cstring>
#include <iostream>
#include <fstream>

using namespace std;

class Producto {
public:
    Producto();
    virtual ~Producto();
    void get_nombre(char *);
    void set_nombre(const char *);
    double get_precio() const;
    void set_precio(double precio);
    void leeproducto(ifstream &);

private:
    char *nombre;
    double precio;
};


#endif //CLASESHERENCIAS_PRODUCTO_H
