#include <iostream>
#include "Taller.h"
#include "Moto.h"
#include "Coche.h"
#include "Vehiculo.h"

using namespace std;

int main()
{
    Taller* t1 = new Taller(4);

    Vehiculo *v1;

    v1 = new Coche("Rojo","Ford",1);
    t1->meter(v1);
    v1 = new Moto("Verde","Yamaha",150);
    t1->meter(v1);
    v1 = new Coche("Rojo","Peugeout",1);
    t1->meter(v1);
    v1 = new Moto("Rojo","Kawazaki",250);
    t1->meter(v1);
    v1 = new Coche("Negro","Ford",1);
    t1->meter(v1);

    t1->repararVehiculo();

    delete v1;

}
