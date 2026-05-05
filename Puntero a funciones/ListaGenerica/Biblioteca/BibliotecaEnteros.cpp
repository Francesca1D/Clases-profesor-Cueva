//
// Created by cueva.r on 28/04/2026.
//

#include "BibliotecaEnteros.h"
#include <iomanip>
#include <fstream>

using namespace std;

void*leenum(ifstream&arch) {
    int numero;
    arch >> numero;
    if (arch.eof())return nullptr;
    int *pnum=new int;
    *pnum=numero;
    void**aux=new void*[1];
    aux[0]=pnum;//practicar sin este nivel
    return aux;
}

int clasificaentero(void*dato) {
    void**ldato=(void**)(dato);
    int *ndato=(int*)ldato[0];
    if (*ndato<10)return 1;
    return 2;
}

void imprimenum(ofstream&arch,void*dato) {
    void**ldato=(void**)(dato);
    int *ndato;
    if (ldato!=nullptr) {
        ndato=(int*)ldato[0];
        arch <<setw(10)<< *ndato;
    }
}

int comparanum(const void*a,const void*b) {
    void**pa,**pb,**ppa,**ppb;
    int *vala,*valb;

    pa=(void**)a;
    pb=(void**)b;
    ppa=(void**)pa[0];
    ppb=(void**)pb[0];
    vala=(int*)ppa[0];
    valb=(int*)ppb[0];
    return *vala-*valb;
}
