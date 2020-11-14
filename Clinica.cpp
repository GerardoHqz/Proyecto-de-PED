#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
using namespace std;

struct Citas //se ingresan los datos de las citas
{
    string NombrePaciente;
    int EdadPaciente;
    int DUI;
    int horario;
    int fecha;
    string doctor;
};
typedef struct Citas citas;

queue<citas> Ancianos;
queue<citas> Adultos;
queue<citas> Nenes;
citas InformacionPersonal;

void AgendarCita();
void CancelarCita();
void Horarios();
void Informacion();

int main()
{

    bool status = true;
    int opcion;

    do
    {
        system("cls");
        cout << "CLINICA ***\n";
        cout << "\n***MENU***\n";
        cout << "1. Agendar una cita\n";
        cout << "2. Cancelar una cita\n";
        cout << "3. Horarios\n";
        cout << "4. Informacion\n";
        cout << "5. Salir \n";
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            AgendarCita();
            system("pause");
            break;

        default:
            break;
        }

    } while (status);

    return 0;
}

void AgendarCita()
{
    bool status = true, status2 = true;
    int opcion, opcion2;
    cout << "\nIngrese sus datos personales\n";
    cout << "\nNota: En caso de que sea menor de edad, ingrese el DUI de su representante\n";
    cin.ignore();
    cout << "\nNommbre completo: ";
    getline(cin, InformacionPersonal.NombrePaciente);
    cout << "Edad: ";
    cin >> InformacionPersonal.EdadPaciente;
    cout << "DUI: ";
    cin >> InformacionPersonal.DUI;

    if (InformacionPersonal.EdadPaciente > 60)
    {
        do
        {
            cout << "\nConsultas de lunes a sabados";
            cout << "\nFechas disponibles del 2 al 23 de diciembre\n";
            cout << "\nDigite la fecha: ";cin >> opcion2;
            status2 = false;





        } while (status2);

        do
        {
            system("cls");
            cout << "\nConsultas de lunes a sabados";
            cout << "\nFechas disponibles del 2 al 23 de diciembre\n";
            cout << "\nDigite la fecha: "; cin>>opcion2;

            cout << "\n                          ***HORARIOS***";
            cout << "\nUsted al ser una persona de tercera edad dispone de los siguientes horarios: \n";
            cout << "1) 6:00 am - 6:30 am       2) 6:30 am - 7:00 am\n";
            cout << "3) 7:00 am - 7:30 am       4) 7:30 am - 8:00 am\n";
            cout << "5) 8:00 am - 8:30 am       6) 8:30 am - 9:00 am\n";
            cout << "7) 9:00 am - 9:30 am\n";
            cout << "\nEscoja un horario: ";
            cin >> opcion;

            switch (opcion)
            {
            case 1:
                if (InformacionPersonal.horario != 1 )
                {
                    InformacionPersonal.horario = 1;
                    status = false;
                }
                else
                {
                    cout << "\nEste horario no esta disponible, por favor ingrese otro horario.\n";
                }
                system("pause");
                break;

            case 2:
                if (InformacionPersonal.horario != 2)
                {
                    InformacionPersonal.horario = 2;
                    status = false;
                }
                else
                {
                    cout << "\nEste horario no esta disponible, por favor ingrese otro horario.\n";
                }
                system("pause");
                break;

            case 3:
                if (InformacionPersonal.horario != 3)
                {
                    InformacionPersonal.horario = 3;
                    status = false;
                }
                else
                {
                    cout << "\nEste horario no esta disponible, por favor ingrese otro horario.\n";
                }
                system("pause");
                break;

            case 4:
                if (InformacionPersonal.horario != 4)
                {
                    InformacionPersonal.horario = 4;
                    status = false;
                }
                else
                {
                    cout << "\nEste horario no esta disponible, por favor ingrese otro horario.\n";
                }
                system("pause");
                break;

            case 5:
                if (InformacionPersonal.horario != 5)
                {
                    InformacionPersonal.horario = 5;
                    status = false;
                }
                else
                {
                    cout << "\nEste horario no esta disponible, por favor ingrese otro horario.\n";
                }
                system("pause");
                break;

            case 6:
                if (InformacionPersonal.horario != 6)
                {
                    InformacionPersonal.horario = 6;
                    status = false;
                }
                else
                {
                    cout << "\nEste horario no esta disponible, por favor ingrese otro horario.\n";
                }
                system("pause");
                break;

            case 7:
                if (InformacionPersonal.horario != 7)
                {
                    InformacionPersonal.horario = 7;
                    status = false;
                }
                else
                {
                    cout << "\nEste horario no esta disponible, por favor ingrese otro horario.\n";
                }
                system("pause");
                break;

            default:
                cout << "\nOpcion no valida\n";
                system("pause");
                break;
            }

        } while(status);

        

        Ancianos.push(InformacionPersonal);
    }
}