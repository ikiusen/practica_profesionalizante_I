#ifndef COCHE_H
#define COCHE_H

#include "Vehiculo.h"

#include <iostream>
using namespace std;


class Coche : public Vehiculo
{
    public:
        Coche();
        virtual ~Coche();
        void arrancar();
        void reposar();
        void parar();
    private:
        int motor;
};

#endif // COCHE_H
