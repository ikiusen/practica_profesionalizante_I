#ifndef TALLER_H
#define TALLER_H

#include "Vehiculo.h"
#include <iostream>
using namespace std;

class Taller
{
    public:
        Taller();
        Taller(int val);
        virtual ~Taller();
        void meter(Vehiculo *v1);
        void repararVehiculo();
    private:
        int max_vehiculos;
        int cant_vehiculos;
        Vehiculo *listaVehiculos[5];
};

#endif // TALLER_H
