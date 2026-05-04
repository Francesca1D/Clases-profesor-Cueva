#include "MiBiblioteca/PunterosGenericos.h"


int main() {
    void *streamers,*comentarios;
    cargastreamers(streamers);
    cargacomentarios(comentarios);
    actualizacomentarios(streamers,comentarios);
    imprimestreamers(streamers);

    return 0;
}