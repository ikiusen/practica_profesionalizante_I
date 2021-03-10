#include <iostream>
#include "Taller.h"
#include "Moto.h"
#include "Coche.h"
#include "Vehiculo.h"

using namespace std;

int main()
{
    Taller *t1 = new Taller(5);
    Vehiculo *v1;

    v1 = new Moto();
    t1->meter(v1);
    v1 = new Coche();
    t1->meter(v1);
    v1 = new Coche();
    t1->meter(v1);
    v1 = new Coche();
    t1->meter(v1);

    t1->repararVehiculo();

    //Si descomento la invocacion del delete, programar se termina de ejecutar con un estado de retorno raro
    //Si comento, el programa finaliza retornando 0. No se que puede ser.

    //delete t1;

}
