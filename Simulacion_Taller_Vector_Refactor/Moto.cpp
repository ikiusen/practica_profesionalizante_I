#include "Moto.h"

Moto::Moto(string color,string marca,int cilindrada)
{
    m_color = color;
    m_marca = marca;
    m_cilindrada = cilindrada;
    //ctor
}

Moto::~Moto()
{

}

void Moto::arrancar()
{
    cout << "La moto comienza a arrancar..." << endl;
}
void Moto::parar()
{
    cout << "La moto se para.." << endl;
}
void Moto::reposar()
{
    cout << "La moto reposa.." << endl;
}
