#include "Coche.h"

Coche::Coche()
{

}

Coche::Coche(string color,string marca,int motor)
{
    m_motor = motor;
    m_color = color;
    m_marca = marca;
    //ctor
}

Coche::~Coche()
{

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
