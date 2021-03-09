#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"
#include <iostream>
using namespace std;


class Moto : public Vehiculo
{
    public:
        Moto(string color,string marca,int cilindrada);
        virtual ~Moto();
        void arrancar();
        void reposar();
        void parar();
    private:
        int m_cilindrada;
        string m_color;
        string m_marca;
};

#endif // MOTO_H
