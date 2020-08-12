// Escrito 07/08/2020 - Cabrera Thiago Francisco

#include <iostream>
#include <string>

using namespace std;

struct Song
{
    string title;
    string artist; //Artista podria ser una estructura (nombre, apellido, etc)
    int duration;
    int file_size;
};

int main()
{

    Song song;

    //Pregunto al usuario para que cargue los datos

    cout << "Ingrese el nombre de la cancion" << endl;
    getline(cin, song.title); //Uso getline para tomar toda la linea en caso de nombres que lleven espacios
    cout << "Ingrese el nombre del artista" << endl;
    getline(cin, song.artist);
    cout << "Ingrese la duracion de la cancion (en seg)" << endl;
    cin >> song.duration;
    cout << "Ingrese el tamaño del archivo en KB" << endl;
    cin >> song.file_size;

    //Muestro los datos

    cout << "Nombre de la cancion: " << song.title << endl;
    cout << "Nombre del artista: " << song.artist << endl;
    cout << "Duracion de la cancion: " << song.duration <<" seg" << endl;
    cout << "Tamaño del archivo: " << song.file_size << " KB" << endl;

    return 0;
}
