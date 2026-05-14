//
// Created by cueva.r on 6/05/2026.
//

#ifndef OBJINFRACCIONES_EMPRESA_H
#define OBJINFRACCIONES_EMPRESA_H
#include "Multa.h"
#include <fstream>
using namespace std;

class Empresa {
public:
    Empresa();
    virtual ~Empresa();
    int get_dni() const;
    void set_dni(int dni);
    int get_num_placas() const;
    void set_num_placas(int num_placas);
    int get_num_multas() const;
    void set_num_multas(int num_multas);
    void get_nombre(char* cad);
    void set_nombre(const char* cad) ;
    void leeplacas(ifstream&);
    void operator+=(Multa&);
private:
        int dni;
        char *nombre;
        char *placas[10];
        int numPlacas;
        Multa multas[100];
        int numMultas;
        void setPlacaI(const char*,int);
        void getPlacaI(char*,int);
};
void operator>>(ifstream&,Empresa &);

#endif //OBJINFRACCIONES_EMPRESA_H