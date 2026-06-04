//
// Created by cffmg on 5/26/2026.
//

#ifndef CLASESHERENCIAS_RESTAURANTE_H
#define CLASESHERENCIAS_RESTAURANTE_H
#include "Comanda.h"

class Restaurante {
        private:
                Comanda comandas[100];
                int cant_comandas;
        public:
            Restaurante();
            int get_cant_comandas() const;
            void set_cant_comandas(int cant_comandas);
            void cargar_comandas();
            void buscayasigna(int );
};



#endif //CLASESHERENCIAS_RESTAURANTE_H
