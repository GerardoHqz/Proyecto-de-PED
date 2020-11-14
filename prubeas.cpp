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
            break;

        case 5:
            status = false;
            break;

        default:
            break;
        }

    } while (status);

    return 0;
}

void AgendarCita()
{
    queue<citas>clone = Ancianos;
    bool status = true, status2 = true, band = true;
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

    cin.ignore();
    cout<<"\nDoctores disponibles:\n";
    cout<<"\nDr.Dueñas Medico General -------- $12";
    cout<<"\nDra.Vega Pediatra --------------- $25";
    cout<<"\nDra.Santiago Dermatologa -------- $25";
    cout<<"\nDr.Henriquez Endoclinologo ------ $25";
    cout<<"\nDra.Escobar Cardiologa ---------- $25\n";
    cout<<"\nEscriba el nombre de la especialidad que desea: "; getline(cin,InformacionPersonal.doctor);

    do{
        system("cls");
        cout<<"\n             ****HORARIOS***";
        cout<<"\nConsultas de lunes a sabados";
        cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
        cout<<"\nDigite la fecha que desea: "; cin>>opcion;
        cout<<"\nUsted al ser una persona de tercera edad dispone de los siguientes horarios: \n";
        cout << "1) 6:00 am - 6:30 am       2) 6:30 am - 7:00 am\n";
        cout << "3) 7:00 am - 7:30 am       4) 7:30 am - 8:00 am\n";
        cout << "5) 8:00 am - 8:30 am       6) 8:30 am - 9:00 am\n";
        cout << "7) 9:00 am - 9:30 am\n";
        cout << "\nEscoja un horario: "; cin >> opcion2;

        for(int i=0; i<clone.size();i++){
            if(opcion == clone.front().fecha){
                for(int j=0; j<clone.size(); j++){
                    if(opcion2 == clone.front().horario){
                        band = false;
                    }
                }
            }
            clone.pop();
        }

        if(band == true){
            InformacionPersonal.fecha = opcion;
            InformacionPersonal.horario = opcion2;
            status = false;
        }
        else{
            cout<<"\nEste horario ya esta ocupado, por favor pruebe a otra  hora u otro dia\n";
        }



    }while(status);
}