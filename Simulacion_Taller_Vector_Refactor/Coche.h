#ifndef COCHE_H
#define COCHE_H

#include "Vehiculo.h"

#include <iostream>
#include <string>
using namespace std;


class Coche : public Vehiculo
{
    public:
        Coche();
        Coche(string color, string marca,int motor);
        virtual ~Coche();
        void arrancar();
        void reposar();
        void parar();
    private:
        int m_motor;
        string m_color;
        string m_marca;
};

#endif // COCHE_H
