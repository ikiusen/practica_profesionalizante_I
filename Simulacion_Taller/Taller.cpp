#include "Taller.h"

Taller::Taller()
{
    cant_vehiculos = 0;
    max_vehiculos = 5;
    //ctor
}
Taller::Taller(int val)
{
    cant_vehiculos = 0;
    max_vehiculos = val;
}

Taller::~Taller()
{
    delete this;
    delete []listaVehiculos;
    }

void Taller::meter(Vehiculo *v1)
{
    if(cant_vehiculos == max_vehiculos)
    {
        cout << "Taller lleno!" << endl;
    } else {
        listaVehiculos[cant_vehiculos] = v1;
        cant_vehiculos++;
    }
}

void Taller::repararVehiculo()
{
    cout << "Reparando vehiculo.... " << endl;

    for(int i = 0; i < cant_vehiculos; i++)
    {
        listaVehiculos[i]->arrancar();
    }

    cout << "Reparacion completada! " << endl;
    cout << " " << endl;

}
