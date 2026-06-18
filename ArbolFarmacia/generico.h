/* 
 * File:   generico.h
 * Author: cueva.r
 *
 * Created on 11 de junio de 2025, 10:10 AM
 */

#ifndef GENERICO_H
#define GENERICO_H

#include "medicamento.h"


class generico:public medicamento {
public:
    generico();
    generico(const generico& orig);
    virtual ~generico();
    void SetPais(char* pais);
    void GetPais(char *) const;
    void lee(ifstream&);
    void imprime(ofstream&);
private:
    char*pais;
    
};

#endif /* GENERICO_H */

