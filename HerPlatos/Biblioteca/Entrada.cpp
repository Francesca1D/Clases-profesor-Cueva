//
// Created by cueva.r on 27/05/2026.
//

#include "Entrada.h"

Entrada::Entrada() {
    picante = false;
}


bool Entrada::is_picante() const {
    return picante;
}

void Entrada::set_picante(bool picante) {
    this->picante = picante;
}
