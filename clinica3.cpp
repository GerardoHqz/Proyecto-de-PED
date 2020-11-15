
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
    int horarioAdulto;
    int horarioNenes;
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
    queue<citas>clone2 = Adultos;
    queue<citas>clone3 = Nenes;

    bool status = true, status2 = true, band = true;
    int opcion, opcion2;
    int opcion3, opcion4;
    int opcion5, opcion6;
    cout << "\nIngrese sus datos personales\n";
    cout << "\nNota: En caso de que sea menor de edad, ingrese el DUI de su representante\n";
    cin.ignore();
    cout << "\nNombre completo: ";
    getline(cin, InformacionPersonal.NombrePaciente);
    cout << "Edad: ";
    cin >> InformacionPersonal.EdadPaciente;
    cout << "DUI: ";
    cin >> InformacionPersonal.DUI;

    cin.ignore();
    cout<<"\nDoctores disponibles:\n";
    cout<<"\nDr.Duenas Medico General (G)-------- $12";
    cout<<"\nDra.Vega Pediatra (P)--------------- $25";
    cout<<"\nDra.Santiago Dermatologa (D)-------- $25";
    cout<<"\nDr.Henriquez Endoclinologo (E)------ $25";
    cout<<"\nDra.Escobar Cardiologa (C)---------- $25\n";
    cout<<"\nPor favor escriba la letra que corresponde a cada doctor";
    cout<<"\nEscriba el nombre de la especialidad que desea: "; getline(cin,InformacionPersonal.doctor);

//-----------------------------------ANCIANOS---------------------------------//
    if(InformacionPersonal.EdadPaciente >= 60){
        do{
            band = true;
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

            if(InformacionPersonal.doctor == "Medico general" || InformacionPersonal.doctor == "medico general"){
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
            }

            if(InformacionPersonal.doctor == "pediatra" || InformacionPersonal.doctor == "Pediatra"){
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
            }

            if(InformacionPersonal.doctor == "dermatologa" || InformacionPersonal.doctor == "Dermatologa"){
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
            }

            if(InformacionPersonal.doctor == "endoclinologo" || InformacionPersonal.doctor == "Endoclinologo"){
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
            }

            if(InformacionPersonal.doctor == "cardiloga" || InformacionPersonal.doctor == "Cardiologa"){
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
            }
            

        if(band == true){
            InformacionPersonal.fecha = opcion;
            InformacionPersonal.horario = opcion2;
            status = false;
        }
        else{
            cout<<"\nEste horario ya esta ocupado, por favor pruebe a otra  hora u otro dia\n";
        }
        system("pause");

        }while(status);

        Ancianos.push(InformacionPersonal);
    }

//-----------------------------------ADULTOS---------------------------------//
    
    if(InformacionPersonal.EdadPaciente > 17 && InformacionPersonal.EdadPaciente < 60 ){
        do{
            band = true;
            system("cls");
            cout<<"\n             ****HORARIOS***";
            cout<<"\nConsultas de lunes a sabados";
            cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
            cout<<"\nDigite la fecha que desea: "; cin>>opcion3;
            cout<<"\nUsted al ser una persona adulta dispone de los siguientes horarios: \n";
            cout << "1) 1:30 pm - 2:00 pm       2) 2:00 pm - 2:30 pm\n";
            cout << "3) 2:30 pm - 3:00 pm       4) 3:00 pm - 3:30 pm\n";
            cout << "5) 3:30 pm - 4:00 pm       6) 4:00 pm - 4:30 pm\n";
            cout << "7) 4:30 pm - 5:00 pm\n";
            cout << "\nEscoja un horario: "; cin >> opcion4;

            if(InformacionPersonal.doctor == "Medico general" || InformacionPersonal.doctor == "medico general"){
                for(int i=0; i<clone.size();i++){
                    if(opcion3 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion4 == clone.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "pediatra" || InformacionPersonal.doctor == "Pediatra"){
                for(int i=0; i<clone.size();i++){
                    if(opcion3 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion4 == clone.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "dermatologa" || InformacionPersonal.doctor == "Dermatologa"){
                for(int i=0; i<clone.size();i++){
                    if(opcion3 == clone.front().fecha){
                        for(int j=0; j<clone.size(); j++){
                            if(opcion4 == clone.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "endoclinologo" || InformacionPersonal.doctor == "Endoclinologo"){
                for(int i=0; i<clone.size();i++){
                    if(opcion3 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion4 == clone.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "cardiloga" || InformacionPersonal.doctor == "Cardiologa"){
                for(int i=0; i<clone.size();i++){
                    if(opcion3 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion4 == clone.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }
            

        if(band == true){
            InformacionPersonal.fecha = opcion3;
            InformacionPersonal.horarioAdulto = opcion4;
            status = false;
        }
        else{
            cout<<"\nEste horario ya esta ocupado, por favor pruebe a otra  hora u otro dia\n";
        }
        system("pause");

        }while(status);

        Adultos.push(InformacionPersonal);
    }

    //------------------------------NENES----------------------------------//
    if(InformacionPersonal.EdadPaciente > 1 && InformacionPersonal.EdadPaciente < 18 ){
        do{
            band = true;
            system("cls");
            cout<<"\n             ****HORARIOS***";
            cout<<"\nConsultas de lunes a sabados";
            cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
            cout<<"\nDigite la fecha que desea: "; cin>>opcion5;
            cout<<"\nUsted al ser una persona adulta dispone de los siguientes horarios: \n";
            cout << "1) 9:30 pm - 10:00 pm       2) 10:00 pm - 10:30 pm\n";
            cout << "3) 10:30 pm - 11:00 pm      4) 11:00 pm - 11:30 pm\n";
            cout << "5) 11:30 pm - 12:00 pm      6) 12:00 pm - 12:30 pm\n";
            cout << "\nEscoja un horario: "; cin >> opcion6;

            if(InformacionPersonal.doctor == "Medico general" || InformacionPersonal.doctor == "medico general"){
                for(int i=0; i<clone.size();i++){
                    if(opcion5 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion6 == clone.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "pediatra" || InformacionPersonal.doctor == "Pediatra"){
                for(int i=0; i<clone.size();i++){
                    if(opcion5 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion6 == clone.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "dermatologa" || InformacionPersonal.doctor == "Dermatologa"){
                for(int i=0; i<clone.size();i++){
                    if(opcion5 == clone.front().fecha){
                        for(int j=0; j<clone.size(); j++){
                            if(opcion6 == clone.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "endoclinologo" || InformacionPersonal.doctor == "Endoclinologo"){
                for(int i=0; i<clone.size();i++){
                    if(opcion5 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion6 == clone.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }

            if(InformacionPersonal.doctor == "cardiloga" || InformacionPersonal.doctor == "Cardiologa"){
                for(int i=0; i<clone.size();i++){
                    if(opcion5 == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion6 == clone.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                clone.pop();
                }
            }
            

        if(band == true){
            InformacionPersonal.fecha = opcion5;
            InformacionPersonal.horarioNenes = opcion6;
            status = false;
        }
        else{
            cout<<"\nEste horario ya esta ocupado, por favor pruebe a otra  hora u otro dia\n";
        }
        system("pause");

        }while(status);

        Nenes.push(InformacionPersonal);
    }

}