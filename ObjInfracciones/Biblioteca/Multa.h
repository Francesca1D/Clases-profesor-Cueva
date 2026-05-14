//
// Created by cueva.r on 6/05/2026.
//

#ifndef OBJINFRACCIONES_MULTA_H
#define OBJINFRACCIONES_MULTA_H
#include <fstream>

using namespace std;

class Multa {

private:
    char*placa;
    int fechaDeInfraccion;
    int fechaDePago;
    int codigoInfraccion;
    double multa;

public:
    Multa();
    virtual ~Multa();
    Multa(Multa&); //yo soy el copia
    int get_fecha_de_infraccion() const;
    void set_fecha_de_infraccion(int fecha_de_infraccion);
    int get_fecha_de_pago() const;
    void set_fecha_de_pago(int fecha_de_pago);
    int get_codigo_infraccion() const;
    void set_codigo_infraccion(int codigo_infraccion);
    double get_multa() const;
    void set_multa(double multa);
    void get_placa(char* cad);
    void set_placa(const char* cad);
    void operator=(Multa&);
};
void operator>>(ifstream&,Multa&);

#endif //OBJINFRACCIONES_MULTA_H