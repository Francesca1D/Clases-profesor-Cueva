//
// Created by cueva.r on 29/04/2026.
//
#include <fstream>
#include <iomanip>
#include <cstring>
#include <iostream>
#include "BibliotecaRegistros.h"


using namespace std;
// 53374153,R2T-476,5/09/2019,101,SERRANO IBEROS FRANCISCO
// 19568447,O7W-705,9/05/2019,102,VEGA SORIA HENRRY

void* leeregistro(ifstream&arch) {
    int codigo,*pcodigo,dd,mm,aa;
    char *placa,c,*nombre;
    arch >> codigo;
    if (arch.eof())return nullptr;
    pcodigo=new int;
    *pcodigo=codigo;
    arch.get();
    placa=leecadena(arch,10,',');
    arch>>dd>>c>>mm>>c>>aa>>c;
    int *pfecha=new int;
    *pfecha=aa*10000+mm*100+dd;
    int *ptipo=new int;
    arch >> *ptipo >>c;
    nombre=leecadena(arch,100,'\n');
    void**reg=new void*[5];
    reg[0]=pfecha;
    reg[1]=pcodigo;
    reg[2]=nombre;
    reg[3]=ptipo;
    reg[4]=placa;

    return reg;
}

int clasificaregistro(void*dato) {
    void**reg=(void**)dato;
    int *nfalta;
    nfalta=(int*)reg[3];
    if (*nfalta/100==1)
        return 1;
    return 2;

}
void imprimeregistro(ofstream &arch,void*dato) {
    void**reg=(void**)dato;
    int *pfecha,*pcodigo,*pfalta;
    char *nombre;

    pfecha=(int*)reg[0];
    pcodigo=(int*)reg[1];
    nombre=(char*)reg[2];
    pfalta=(int*)reg[3];

    arch<<setw(10)<<*pfecha << setw(10)<<*pcodigo;
    arch<<setw(40)<<nombre<<setw(10)<<*pfalta<<endl;
}

int comparareg(const void*a,const void*b) {
    void**pa,**pb,**ppa,**ppb;
    int *vala,*valb;
    pa=(void**)a;
    pb=(void**)b;
    ppa=(void**)pa[0];
    ppb=(void**)pb[0];
    vala=(int*)ppa[1];
    valb=(int*)ppb[1];
    return *vala-*valb;
}

char* leecadena(ifstream &arch,int max,char deli) {
    char arr[max],*cad;
    arch.getline(arr,max,deli);
    cad = new char[strlen(arr)+1];
    strcpy(cad,arr);
    return cad;
}