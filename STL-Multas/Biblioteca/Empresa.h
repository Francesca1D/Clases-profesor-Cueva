//
// Created by cueva.r on 17/06/2026.
//

#ifndef STL_MULTAS_EMPRESA_H
#define STL_MULTAS_EMPRESA_H
#include <string>
#include <vector>
#include <map>

#include "Multa.h"
#include "Vehiculo.h"

using namespace std;

class Empresa {
    private:
        int dni;
        string nombre;
        string distrito;
        map<string,Vehiculo> vehiculos;
        vector<Multa>multasRecibidas;
    public:
        Empresa();
        int get_dni() const;
        void set_dni(int dni);
        string get_nombre() const;
        void set_nombre(const string &nombre);
        string get_distrito() const;
        void set_distrito(const string &distrito);
};


#endif //STL_MULTAS_EMPRESA_H