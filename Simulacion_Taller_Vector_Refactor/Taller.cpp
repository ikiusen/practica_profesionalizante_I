#include "Taller.h"

Taller::Taller()
{
    cant_vehiculos = 0;
    max_vehiculos = 5;
    //ctor
}
Taller::Taller(int cantidad)
{
    cant_vehiculos = 0;
    max_vehiculos = cantidad;
}

Taller::~Taller()
{
}

void Taller::meter(Vehiculo* v1)
{
        vehiculos.push_back(v1);
}

void Taller::repararVehiculo()
{
    cout << "Reparando vehiculo.... " << endl;

    for(int i = 0; i < vehiculos.size(); i++)
    {
        vehiculos[i]->arrancar();
    }

    cout << "Reparacion completada! " << endl;
    cout << " " << endl;

}
