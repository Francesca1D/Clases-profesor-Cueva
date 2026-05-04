//
// Created by cueva.r on 7/04/2026.
//
#include <iostream>
#include <fstream>
#include <cstring>
#include <iomanip>

#include "Memoria.h"

#include "Conductores.h"
#include "Faltas.h"
#define INC 5

using namespace std;

//12270502,CUEVA FUENTES CINTHIA DELIA
//12443643,LEE SERRANO ROSARIO

void leeconductores(const char *nom,Conductores &conduc) {
    int buffdni[200],i=0;
    char *buffnom[200],c;

    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo de conductores";
        exit(1);
    }

    while (true) {
        arch >> buffdni[i] >> c;
        if (arch.eof()) break;
        buffnom[i] = leecadena(arch,100,'\n');
        i++;
    }
    conduc.dnis = new int[i+1];
    conduc.nombres = new char*[i];

    for (int j=0;j<i;j++) {
        conduc.dnis[j]=buffdni[j];
        conduc.nombres[j]=buffnom[j];
    }
    conduc.dnis[i]=0;
    conduc.cantidad=i;
}
//81485316,J5T-691,24/12/2020,128
//25518120,E1J-798,14/07/2020,118
void leefaltas(const char *nom,Faltas &falta) {
    int dni,indcond;
    char c,*placa,cad[100];
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout <<"No se puede abrir el archivo de conductores";
        exit(1);
    }
    falta.placas = new char**[falta.conductores.cantidad]{};
    falta.capacidades = new int[falta.conductores.cantidad]{};
    while (true) {
        arch >> dni >> c;
        if (arch.eof())break;
        indcond=buscardni(dni,falta.conductores.dnis);
        placa=leecadena(arch,10,',');
        cargaplaca(falta.placas[indcond],falta.capacidades[indcond],placa);
        arch.getline(cad,100,'\n');
    }

}
void cargaplaca(char **&arrplacas,int &capa,char*placa) {
    int numdat=0;
    if (arrplacas!=nullptr) {
        for (int i=0;arrplacas[i]!=nullptr;i++) {
            if (strcmp(placa,arrplacas[i])==0)return;
            numdat++;
        }
        numdat++;
    }
    if (capa==numdat)
        aumentarespacio(arrplacas,capa,numdat);
    arrplacas[numdat-1]=placa;
    arrplacas[numdat]=nullptr;
}

void aumentarespacio(char**&placas,int &capa,int&num) {
    char **aux;
    capa+=INC;
    if (num==0) {
        placas=new char*[capa]{};
        placas[0]=nullptr;
        num++;
    }
    else {
        aux=new char*[capa]{};
        for (int i=0;i<num;i++)
            aux[i]=placas[i];
        delete placas;
        placas=aux;
    }
}


int buscardni(int dni,int*dnis) {
    for (int i=0;dnis[i]!=0;i++)
        if (dnis[i]==dni)return i;
    return -1;
}

void imprimefaltas(const char *nom,Faltas falta) {
    ofstream arch(nom,ios::out);
    if (not arch) {
        cout <<"No se puede abrir el archivo de reportes";
        exit(1);
    }
    for (int i=0;falta.conductores.dnis[i]!=0;i++) {
        arch << left << setw(10)<<falta.conductores.dnis[i];
        arch << setw(40)<<falta.conductores.nombres[i];
        char**aux=falta.placas[i];
        if (aux!=nullptr)
            for (int j=0;aux[j]!=nullptr;j++)
                arch << setw(10)<<aux[j];
        arch <<endl;
    }
}


char* leecadena(ifstream &arch,int max,char deli) {
    char arr[max],*cad;
    arch.getline(arr,max,deli);
    cad = new char[strlen(arr)+1];
    strcpy(cad,arr);
    return cad;
}