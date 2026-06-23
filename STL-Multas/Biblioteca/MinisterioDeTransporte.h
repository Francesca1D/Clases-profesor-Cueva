//
// Created by cueva.r on 17/06/2026.
//

#ifndef STL_MULTAS_MINISTERIODETRANSPORTE_H
#define STL_MULTAS_MINISTERIODETRANSPORTE_H
#include <list>

#include "Empresa.h"
#include "Infraccion.h"

using namespace std;

class MinisterioDeTransporte {
    private:
        list<Infraccion>tablaInfracciones;
        list<Empresa>listaEmpresas;
    public:
        MinisterioDeTransporte();

};


#endif //STL_MULTAS_MINISTERIODETRANSPORTE_H