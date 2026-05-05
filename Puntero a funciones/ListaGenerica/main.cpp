#include "Biblioteca/BibliotecaGenerica.h"
#include "Biblioteca/BibliotecaRegistros.h"
#include "Biblioteca/BibliotecaEnteros.h"

int main() {
    void*lista;
    creaLista(lista,leenum,clasificaentero,"numeros.txt");
    imprimeLista(lista,imprimenum,"Repnum.txt");

    creaLista(lista,leeregistro,clasificaregistro,"RegistrodeFaltas1.csv");
    imprimeLista(lista,imprimeregistro,"RepFaltas.txt");

    cargayordena(leenum,imprimenum,comparanum,"numeros.txt","repnumord.txt");
    cargayordena(leeregistro,imprimeregistro,comparareg,"RegistrodeFaltas1.csv","repregord.txt");

    return 0;


}