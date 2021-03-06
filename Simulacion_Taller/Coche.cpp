#include "Coche.h"

Coche::Coche()
{
    //ctor
}

Coche::~Coche()
{
    delete this;//dtor
}
void Coche::arrancar()
{
    cout << "El coche arranca.. " << endl;
}
void Coche::parar()
{
    cout << "Se para el coche.. " << endl;
}
void Coche::reposar()
{
    cout << "El auto reposa.. " << endl;
}
