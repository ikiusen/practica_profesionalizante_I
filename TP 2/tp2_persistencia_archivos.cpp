#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct FileData
{
    string name;// Nombre del archivo
    long size;// El tama�o en bytes
};

int numberOfFiles;// N�mero de archivos que ya tenemos
int i;// Para bucles
int option;// La option del menu que elija el usuario

string tempText;// Para pedir datos al usuario
int tempNumber;
int main()
{
    //FileData* files = new FileData[1000];
    FileData files[1000];
    cout << "Si es la primera vez corriendo el codigo y no existe el archivo, ingrese 0" << endl;
    cout << "Cuantos registros ingres� la ultima vez" << endl; //El programa debe saber cuantos registros se tienen en total
    cin >> numberOfFiles;
    if(numberOfFiles > 0)
    {
        ifstream entrada("archivo.dat",ios::in| ios::binary); //Se lee el archivo binario
        if(!entrada) //En caso de no poder abrirse el archivo, se retorna error
        {
            cout << "Error al abrir el archivo" << endl;
            return 1;
        }
        for(i=0;i < numberOfFiles;i++ ) //Se leen todos los registros en el vector files
        {
            entrada.read((char*) &files[i], sizeof(FileData));
        }
        entrada.close(); //Se cierra el archivo
        if(!entrada.good()) //Si hubo un error para abrir el archivo, tira error
        {
            cout << "Ocurrio un error al leer el archivo" << endl;
            return 1;
        }
    }

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
                    cin.ignore(); //
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

            case 5:// Salir: avisamos de que salimos y automaticamente guarda todos los registros que existan
                {
                ofstream salida ("archivo.dat", ios::out | ios::binary); //Se abre el archivo para escritura
                    if(!salida) {
                        cout << "No se pudo abrir el archivo";
                        return 1;
                    }
                    for (i=0; i<numberOfFiles; i++)
                    {
                        salida.write((char*)&files[i],sizeof(FileData));
                    }
                    salida.close();
                    if(!salida.good())
                    {
                        cout<<"Hubo un problema en la escritura" << endl;
                        return 1;
                    }
                cout << "Fin del programa" << endl;
                break;
                }

            default: // Otra opci�n: no v�lida
                cout << "�Opci�n desconocida!" << endl;
                break;
        }
    } while (option != 5);// Si la opci�n es 5, terminamos

    return 0;
}
