//
// Created by cueva.r on 22/04/2026.
//
#include <fstream>
#include <iostream>
#include "BibliotecaGenerica.h"

using namespace std;

void generaLista(void *&lista) {
    void **dupla=new void*[2];
    void **inicio1=new void*[2]{};
    void **inicio2=new void*[2]{};
    dupla[0]=inicio1;
    dupla[1]=inicio2;
    inicio1[1]=inicio2;
    lista=dupla;
}

void creaLista(void *&lista,void*(*lee)(ifstream&),
    int(*clasifica)(void*),const char*nom) {
    void *dato;
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo"<<endl;
        exit(1);
    }
    generaLista(lista);
    while (true) {
        dato = lee(arch);
        if (dato==nullptr)break;
        insertaLista(lista,dato,clasifica);
    }
}
void insertaLista(void*&lista,void*dato,int(*clasifica)(void*)) {
    void**prec,**nuevo,**pant=nullptr;
    void **llista=(void**)lista;
    int posi=clasifica(dato);
    if (posi==1)prec=(void**)llista[0];
    else
        prec=(void**)llista[1];
    if (prec[0]==nullptr)prec[0]=dato;
    else {
        nuevo=new void*[2]{};
        nuevo[0]=dato;
        if (posi==2) {
            while (prec) {
                pant=prec;
                prec=(void**)prec[1];
            }
            pant[1]=nuevo;
        }
        else {
            while (true) {
                pant=prec;
                prec=(void**)prec[1];
                if (prec[0]==nullptr or clasifica(prec[0])==2)break;
            }
            pant[1]=nuevo;
            nuevo[1]=prec;
        }
    }
}

void imprimeLista(void*lista,void(*imprime)(ofstream&,void*),
    const char*nom) {
    void **llista=(void**)lista;
    void **prec=(void**)llista[0];

    ofstream repo(nom,ios::out);
    if (not repo) {
        cout << "No se puede abrir el archivo" << endl;
        exit(1);
    }
    while (prec) {
        imprime(repo,prec[0]);
        prec=(void**)prec[1];
    }
}

void cargayordena(void*(*lee)(ifstream&),void(*imprime)(ofstream&,void*),
    int (*compara)(const void*,const void*),const char*nom, const char*nrep) {
    int i=0;
    void*arreglo[300]{};
    ifstream arch(nom,ios::in);
    if (not arch) {
        cout << "No se puede abrir el archivo"<<endl;
        exit(1);
    }
    while (true) {
        arreglo[i]=lee(arch);
        if (arreglo[i]==nullptr)break;
        i++;
    }
    qsort(arreglo,i,sizeof(void*),compara);

    ofstream repo(nrep,ios::out);
    if (not repo) {
        cout << "No se puede abrir el archivo" << endl;
        exit(1);
    }
    for (int j=0;j<i;j++)
        imprime(repo,arreglo[j]);

}

