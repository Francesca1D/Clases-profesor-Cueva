//
// Created by cueva.r on 6/05/2026.
//

#ifndef OBJINFRACCIONES_INFRACCION_H
#define OBJINFRACCIONES_INFRACCION_H
#include <fstream>

using namespace std;

class Infraccion {
private:
        int codigo;
        char* descripcion;
        char* gravedad;
        double multa;

public:
        Infraccion();
        virtual ~Infraccion();
        void get_descripcion(char*);
        void set_descripcion(const char*);
        int get_codigo() const;
        void set_codigo(int codigo);
        double get_multa() const;
        void set_multa(double multa);
        void set_gravedad(const char* cad);
        void get_gravedad(char* cad);
        void operator=(Infraccion&);
};
void operator>>(ifstream&,Infraccion&);
void operator<<(ofstream&,Infraccion&);
#endif //OBJINFRACCIONES_INFRACCION_H
