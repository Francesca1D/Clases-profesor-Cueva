#include "MiBiblioteca/Memoria.h"
#include "MiBiblioteca/Faltas.h"

int main() {
    Faltas falta;
    leeconductores("Conductores.csv",falta.conductores);
    leefaltas("Faltas.csv",falta);
    imprimefaltas("Reportes.txt",falta);

    return 0;
}