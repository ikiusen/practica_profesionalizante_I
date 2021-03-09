#ifndef VEHICULO_H
#define VEHICULO_H

#include <string>
using namespace std;

class Vehiculo
{
    public:
        virtual ~Vehiculo();
        virtual void arrancar()=0;
        virtual void reposar()=0;
        virtual void parar()=0;
};

#endif // VEHICULO_H
