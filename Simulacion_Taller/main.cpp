#include <iostream>
#include "Taller.h"
#include "Moto.h"
#include "Coche.h"
#include "Vehiculo.h"

using namespace std;

int main()
{
    Taller t1;

    Vehiculo *v1;

    v1 = new Coche();
    t1.meter(v1);
    v1 = new Moto();
    t1.meter(v1);
    v1 = new Coche();
    t1.meter(v1);
    v1 = new Moto();
    t1.meter(v1);
    v1 = new Coche();
    t1.meter(v1);
    v1 = new Coche();
    t1.meter(v1);
    v1 = new Coche();
    t1.meter(v1);
    v1 = new Coche();
    t1.meter(v1);

    t1.repararVehiculo();

    delete v1;

}
