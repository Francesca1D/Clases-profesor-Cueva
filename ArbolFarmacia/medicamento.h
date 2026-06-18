

/* 
 * File:   medicamento.h
 * Author: cueva.r
 *
 * Created on 3 de junio de 2025, 11:15 AM
 */

#ifndef MEDICAMENTO_H
#define MEDICAMENTO_H

#include <fstream>
using namespace std;

class medicamento {
public:
    medicamento();
    medicamento(const medicamento& orig);
    virtual ~medicamento();

    void setPrecio(double precio);
    double getPrecio() const;
    void setNombre(char* );
    void getNombre(char* ) const;
    void setCodigo(int codigo);
    int getCodigo() const;
    void setStock(int stock);
    int getStock() const;

    virtual void lee(ifstream&);
    virtual void imprime(ofstream&);
    
private:
    int codigo;
    char*nombre;
    int stock;
    double precio;
};

#endif /* MEDICAMENTO_H */

