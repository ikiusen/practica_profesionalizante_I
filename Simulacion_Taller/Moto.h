#ifndef MOTO_H
#define MOTO_H

#include "Vehiculo.h"
#include <iostream>
using namespace std;


class Moto : public Vehiculo
{
    public:
        Moto();
        virtual ~Moto();
        void arrancar();
        void reposar();
        void parar();
    private:
        int cilindrada;
};

#endif // MOTO_H
