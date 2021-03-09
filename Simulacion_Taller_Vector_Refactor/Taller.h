#ifndef TALLER_H
#define TALLER_H

#include "Vehiculo.h"
#include <iostream>
#include <vector>
using namespace std;

class Taller
{
    public:
        Taller();
        Taller(int cantidad);
        virtual ~Taller();
        void meter(Vehiculo *v1);
        void repararVehiculo();
        void getCantidadActualDeVehiculos();

    private:
        int max_vehiculos;
        int cant_vehiculos;
        vector<Vehiculo*> vehiculos;
};

#endif // TALLER_H
