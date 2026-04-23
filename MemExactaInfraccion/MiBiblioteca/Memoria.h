//
// Created by cueva.r on 7/04/2026.
//

#ifndef MEMEXACTAINFRACCION_MEMORIA_H
#define MEMEXACTAINFRACCION_MEMORIA_H
#include <fstream>
#include "Conductores.h"
#include "Faltas.h"

using namespace  std;

    char* leecadena(ifstream &arch,int max,char deli);
    void leeconductores(const char *nom,Conductores &conduc);
    void leefaltas(const char *nom,Faltas &falta);
    int buscardni(int dni,int*dnis);
    void cargaplaca(char **&arrplacas,int &capa,char*placa);
    void aumentarespacio(char**&placas,int &capa,int&num);
    void imprimefaltas(const char *nom,Faltas falta);
#endif //MEMEXACTAINFRACCION_MEMORIA_H