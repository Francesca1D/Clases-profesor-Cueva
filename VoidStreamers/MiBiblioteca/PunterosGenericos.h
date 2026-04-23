//
// Created by cueva.r on 14/04/2026.
//

#ifndef VOIDSTREAMERS_PUNTEROSGENERICOS_H
#define VOIDSTREAMERS_PUNTEROSGENERICOS_H
#include <fstream>
using namespace  std;

    void *leestreamer(ifstream &arch);
    char* leecadena(ifstream &arch,int max,char deli);
    void imprimestreamers(void *streamers);
    void cargastreamers(void *&streamers);
    void imprimeregistro(ofstream&arch,void *reg);
    void *leecomentarios(ifstream &arch);
    void cargacomentarios(void *&comentarios);
    void buscacomentarios(char*cuenta,void*comentarios,void*) ;
    int cuentamemoria(void*lista);
    void actualizacomentarios(void *streamers,void*comentarios);
    void imprimecomentarios(void *comentarios,
        ofstream&arch);
    void recorte1(void *streamers);
    void recorte2(void *&lcomenterios);
#endif //VOIDSTREAMERS_PUNTEROSGENERICOS_H