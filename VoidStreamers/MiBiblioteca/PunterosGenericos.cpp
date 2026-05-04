//
// Created by cueva.r on 14/04/2026.
//
#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>
#include "PunterosGenericos.h"

#include <charconv>

using namespace std;

void cargastreamers(void *&streamers) {
    void *buffer[300],**lstreamers;
    int i=0;
    ifstream arch("entrada/streamers.csv",ios::in);
    if(not arch.is_open()) {
        cout << "No se puede leer los streamers";
        exit(1);
    }
    while (true) {
        buffer[i]=leestreamer(arch);
        if (buffer[i]==nullptr) break;
        i++;
    }
    lstreamers = new void*[i+1];
    for (int j=0;j<=i;j++) {
        lstreamers[j]=buffer[j];
    }
    streamers = lstreamers;
}
void cargacomentarios(void *&comentarios) {
    void *buffer[300],**lcomentarios;
    int i=0;
    ifstream arch("entrada/comentarios.csv",ios::in);
    if(not arch.is_open()) {
        cout << "No se puede leer los comentarios";
        exit(1);
    }
    while (true) {
        buffer[i]=leecomentarios(arch);
        if (buffer[i]==nullptr) break;
        i++;
    }
    lcomentarios = new void*[i+1];
    for (int j=0;j<=i;j++) {
        lcomentarios[j]=buffer[j];
    }
    comentarios = lcomentarios;
}
/*
ab7f2910,Can someone please help me understand [Castro_1021 loltyler1]
e2b1002c,Wow there are [xQcOW summit1g]
 */
void *leecomentarios(ifstream &arch) {
    char*codigo,*comentario,c,*emisor,*receptor;
    void **reg;

    codigo=leecadena(arch,20,',');
    if (arch.eof())return nullptr;
    comentario=leecadena(arch,100,'[');
    emisor=leecadena(arch,20,' ');
    receptor=leecadena(arch,20,']');
    arch.get();
    reg = new void*[4];
    reg[0]=codigo;
    reg[1]=emisor;
    reg[2]=receptor;
    reg[3]=comentario;
    return reg;
}

/*
xQcOW,6196161750,27716,3246298,QA1080
summit1g,6091677300,25610,5310163,MK1092
*/
void *leestreamer(ifstream &arch) {
    char*cuenta,*cat,c;
    long long numlong,*numespe;
    void **reg;
    int num;

    cuenta=leecadena(arch,20,',');
    if (arch.eof())return nullptr;
    numespe=new long long;
    arch >> numlong >> c >>num>>c >> *numespe>>c;
    cat=leecadena(arch,10,'\n');
    reg = new void*[4];
    reg[0]=cuenta;
    reg[1]=numespe;
    reg[2]=cat;
    reg[3]=nullptr;

    return reg;
}

void actualizacomentarios(void *streamers,void*comentarios) {
    void**lstreamers=(void**)streamers;
    for (int i=0;lstreamers[i]!=nullptr;i++) {
        void**lreg=(void**)lstreamers[i];
        char*cuenta =(char*)lreg[0];
        if (lreg[3]==nullptr)
            lreg[3]=new void*[100]{};
        buscacomentarios(cuenta,comentarios,lreg[3]);
        recorte2(lreg[3]);
    }
   // recorte1(streamers);
}

void recorte2(void *&lcomenterios) {
        void **lista=(void**)lcomenterios;
        int n=cuentamemoria(lista);
        void**aux=new void*[n+1]{};
        for (int j=0;j<n;j++)
            aux[j]=lista[j];
        delete lista;
        lcomenterios=aux;
}

void recorte1(void *streamers) {
    void**lstreamers=(void**)streamers;
    for (int i=0;lstreamers[i]!=nullptr;i++) {
        void**lreg=(void**)lstreamers[i];
        void **lista=(void**)lreg[3];
        int n=cuentamemoria(lista);
        void**aux=new void*[n+1]{};
        for (int j=0;j<n;j++)
            aux[j]=lista[j];
        delete lista;
        lreg[3]=aux;
    }
}

int cuentamemoria(void*lista) {
    int i;
    void **llista=(void**)lista;
    for (i=0;llista[i]!=nullptr;i++);
    return i;
}

void buscacomentarios(char*cuenta,void*comentarios,void *lista) {
    void **llista=(void**)lista;
    void**lcomentarios=(void**)comentarios;
    for (int i=0;lcomentarios[i]!=nullptr;i++) {
        void**lregcom=(void**)lcomentarios[i];
        char*emisor=(char*)lregcom[1];
        if (strcmp(cuenta,emisor)==0) {
            void**dupla=new void*[2];
            dupla[0]=lregcom[2];
            dupla[1]=lregcom[3];
            int n=cuentamemoria(llista);
            llista[n]=dupla;
        }
    }
}


void imprimestreamers(void *streamers) {
    void **lstreamers=(void**)streamers;
    ofstream arch("salida/reporte.txt",ios::out);
    if(not arch.is_open()) {
        cout << "No se puede leer el reporte";
        exit(1);
    }
    for (int i=0;lstreamers[i]!=nullptr;i++) {
        imprimeregistro(arch,lstreamers[i]);
    }
}

void imprimeregistro(ofstream&arch,void *reg) {
    void **lreg=(void**)reg;
    char *cuenta=(char*)lreg[0];
    long long *seguidores = (long long*)lreg[1];
    char *categoria=(char*)lreg[2];
    arch <<left<<setw(20)<<cuenta<<setw(20)<<*seguidores<<setw(10)<<categoria<<endl;
    if (lreg[3]!=nullptr)
        imprimecomentarios(lreg[3],arch);
    arch <<endl;
}

void imprimecomentarios(void *comentarios,
    ofstream&arch) {
    void**lcomentarios=(void**)comentarios;
    for (int i=0;lcomentarios[i]!=nullptr;i++) {
        void **reg=(void**)lcomentarios[i];
        char *receptor=(char*)reg[0];
        char *texto=(char*)reg[1];
        arch <<setw(20)<<receptor<<setw(100)<<texto<<endl;
    }

}

char* leecadena(ifstream &arch,int max,char deli) {
    char arr[max],*cad;
    arch.getline(arr,max,deli);
    cad = new char[strlen(arr)+1];
    strcpy(cad,arr);
    return cad;
}