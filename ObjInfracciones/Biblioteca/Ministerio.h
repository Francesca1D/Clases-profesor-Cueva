//
// Created by cueva.r on 12/05/2026.
//

#ifndef OBJINFRACCIONES_MINISTERIO_H
#define OBJINFRACCIONES_MINISTERIO_H
#include "Infraccion.h"
#include "Empresa.h"

class Ministerio {
    public:
        Ministerio();
        virtual ~Ministerio();
        void operator <(const char*);
        void operator <=(const char*);
        void carga();
    private:
        Infraccion *infracciones;
        int numInf;
        Empresa empresas[50];
        int numEmpresas;

};





#endif //OBJINFRACCIONES_MINISTERIO_H