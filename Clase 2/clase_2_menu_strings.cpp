#include <iostream>
#include <string>
using namespace std;

struct FileData
{
    string name;// Nombre del archivo
    long size;// El tama�o en bytes
};

int numberOfFiles=0;// N�mero de archivos que ya tenemos
int i;// Para bucles
int option;// La option del menu que elija el usuario

string tempText;// Para pedir datos al usuario
int tempNumber;

int main()
{
    //FileData* files = new FileData[1000];
    FileData files[1000];

    do
    {
        // Menu principal
        cout << endl;
        cout << "Escoja una opci�n:" << endl;
        cout << "1.- A�adir datos de un nuevo archivo" << endl;
        cout << "2.- Mostrar los nombres de todos los archivos" << endl;
        cout << "3.- Mostrar archivos que sean de mas de un cierto tama�o" << endl;
        cout << "4.- Ver datos de un archivo" << endl;
        cout << "5.- Salir" << endl;

        cin >> option;

        // Hacemos una cosa u otra seg�n la opci�n escogida
        switch(option)
        {
            case 1: // A�adir un dato nuevo
                if (numberOfFiles < 1000)   // Si queda hueco
                {
                    cout << "Introduce el nombre del archivo: ";
                    cin.ignore();
                    getline(cin,files[numberOfFiles].name);
                    cout << "Introduce el tama�o en KB: ";
                    cin >> files[numberOfFiles].size;
                    numberOfFiles++;  // Y tenemos una ficha m�s
                }
                else   // Si no hay hueco para m�s archivos, avisamos
                    cout << "�M�ximo de archivos alcanzado (1000)!" << endl;
                break;

            case 2: // Mostrar todos
                for (i=0; i<numberOfFiles; i++)
                    cout << "Nombre: " << files[i].name
                        << "; Tama�o: " << files[i].size
                        << "Kb" << endl;
                break;

            case 3: // Mostrar seg�n el tama�o
                cout << "�A partir de que tama�o quieres que te muestre? ";
                cin >> tempNumber;
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].size >= tempNumber)
                        cout << "Nombre: " << files[i].name
                            << "; Tama�o: " << files[i].size
                            << " Kb" << endl;
                break;

            case 4: // Ver todos los datos (pocos) de un archivo
                cout << "�De qu� archivo quieres ver todos los datos?";
                cin.ignore();
                getline(cin,tempText);
                for (i=0; i<numberOfFiles; i++)
                    if (files[i].name == tempText)
                        cout << "Nombre: " << files[i].name
                            << "; Tama�o: " << files[i].size
                            << " Kb" << endl;
                break;

            case 5: // Salir: avisamos de que salimos
                cout << "Fin del programa" << endl;
                break;

            default: // Otra opci�n: no v�lida
                cout << "�Opci�n desconocida!" << endl;
                break;
        }
    } while (option != 5);// Si la opci�n es 5, terminamos

    return 0;
}
