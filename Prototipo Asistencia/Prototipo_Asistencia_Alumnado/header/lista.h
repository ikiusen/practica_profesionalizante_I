#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include <string>
using namespace std;

const int MAX = 100;

//Estructura de cada alumno individual
typedef struct{
    string nombre;
    string apellido;
    string fecha;
    string estado;

} tAlumno;
//Array de alumnos
typedef tAlumno tArray[MAX];

//Lista de alumnos
typedef struct{
    tArray elementos;
    int contador;
} tLista;

//Verifica y añade alumnos a la lista
void addAlumno(tLista &lista, bool &ok);

//Elimina un alumno a partir de su nombre y apellido
void eliminarAlumno(tLista &lista, string nombre, string apellido);

//Obtiene la pos del alumno ingresado
void buscarAlumno(tLista &lista, string nombre, string apellido);

//Muestra al alumno en la pos ingresada
void mostrarAlumnoPorPos(tLista &lista, int pos);

//Muestra toda la lista de alumnos
void mostrarAlumnos(tLista &lista);

//De todos los alumnos cuenta cuantos estan ausentes y cuantos presentes en un fecha determinada
void totalAlumunosAusentesPresentes(tLista &lista, string fecha);

bool operator>(tAlumno opIzq, tAlumno opDer);

bool operator<(tAlumno opIzq, tAlumno opDer);

void ordenarLista(tLista &lista);

void ordenarListaDesc(tLista &lista);

#endif // LISTA_H_INCLUDED


