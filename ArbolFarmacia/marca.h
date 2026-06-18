/* 
 * File:   marca.h
 * Author: cueva.r
 *
 * Created on 11 de junio de 2025, 10:17 AM
 */

#ifndef MARCA_H
#define MARCA_H

#include "medicamento.h"


class marca: public medicamento {
public:
    marca();
    marca(const marca& orig);
    virtual ~marca();
    void SetLaboratorio(char* );
    void GetLaboratorio(char *) const;
    void SetLote(int lote);
    int GetLote() const;
    void lee(ifstream&);
    void imprime(ofstream&);
private:
    int lote;
    char*laboratorio;
};

#endif /* MARCA_H */

