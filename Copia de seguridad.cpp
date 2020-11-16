#include <iostream>
#include <queue>
#include <string>
#include <stdlib.h>
#include <windows.h>
using namespace std;

struct Citas //se ingresan los datos de las citas
{
    string NombrePaciente;
    int EdadPaciente;
    string DUI;
    int horario;
    int horarioAdulto;
    int horarioNenes;
    int pago;
    int fecha;
    string doctor;
};
typedef struct Citas citas;

queue<citas> Ancianos;
queue<citas> Adultos;
queue<citas> Nenes;
citas InformacionPersonal;

void AgendarCita();
void PagarCita();
void CancelarCita();
void Horarios();
void Informacion();

int main()
{

    bool status = true;
    int opcion;

    do
    {
        system("color 0f");
        system("cls");
        cout << "CLINICA La Fachada\n";
        cout << "\n***MENU***\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
        cout << "1. Agendar una cita\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
        cout << "2. Pagar cita\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
        cout << "3. Cancelar una cita\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
        cout << "4. Horarios\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout << "5. Informacion\n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),12);
        cout << "6. Salir \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),15);
        cout << "Elija una opcion: ";
        cin >> opcion;

        switch (opcion)
        {
        case 1:
            AgendarCita();
            break;

        case 2:
            PagarCita();
            break;
        
        case 3:
            CancelarCita();
            break;
        
        case 4:
            Horarios();
            break;

        case 5:
            Informacion();
            break;

        case 6:
            status = false;
            cout<<"\nClinica La Fachada te desea un buen dia\n";
            break;

        default:
            cout<<"\nOpcion no valida\n";
            break;
        }

    } while (status);

    return 0;
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de Agendar La Cita

void AgendarCita()
{
    queue<citas>clone = Ancianos;
    queue<citas>clone2 = Adultos;
    queue<citas>clone3 = Nenes;

    bool status = true, status2 = true, band = true;
    int opcion, opcion2;
    int opcion3, opcion4;
    int opcion5, opcion6;

    system("cls");
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),9);
    cout << "\nIngrese sus datos personales\n";
    cout << "\nNota: En caso de que sea menor de edad, ingrese el DUI de su representante\n";
    cin.ignore();
    cout << "\nNombre completo: ";
    getline(cin, InformacionPersonal.NombrePaciente);
    cout << "Edad: ";
    cin >> InformacionPersonal.EdadPaciente;
    cin.ignore();
    cout << "DUI: ";
    getline(cin,InformacionPersonal.DUI);

    cout<<"\nDoctores disponibles:\n";
    cout<<"\nDr.Duenas Medico General (G)-------- $12";
    cout<<"\nDra.Vega Pediatra (P)--------------- $25";
    cout<<"\nDra.Santiago Dermatologa (D)-------- $25";
    cout<<"\nDr.Henriquez Endoclinologo (E)------ $25";
    cout<<"\nDra.Escobar Cardiologa (C)---------- $25\n";
    cout<<"\nPor favor escriba la letra que corresponde a cada doctor";
    cout<<"\nEscriba el nombre de la especialidad que desea: "; getline(cin,InformacionPersonal.doctor);
    system("pause");
//-----------------------------------ANCIANOS---------------------------------//
    if(InformacionPersonal.EdadPaciente >= 60 && InformacionPersonal.EdadPaciente < 115){
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

            if(InformacionPersonal.doctor == "G" || InformacionPersonal.doctor == "g"){
                InformacionPersonal.pago = 12;
                InformacionPersonal.doctor = "Dr.Paolo Duenas -Medico General-";
                for(int i=0; i<clone.size();i++){
                    if(opcion == clone.front().fecha){
                        for(int j=0; j<clone.size(); j++){
                            if(opcion2 == clone.front().horario){
                                band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "p" || InformacionPersonal.doctor == "P"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone.size();i++){
                    if(opcion == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion2 == clone.front().horario){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "d" || InformacionPersonal.doctor == "D"){
                InformacionPersonal.pago = 25;    
                for(int i=0; i<clone.size();i++){
                    if(opcion == clone.front().fecha){
                        for(int j=0; j<clone.size(); j++){
                            if(opcion2 == clone.front().horario){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "e" || InformacionPersonal.doctor == "E"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone.size();i++){
                    if(opcion == clone.front().fecha){
                     for(int j=0; j<clone.size(); j++){
                            if(opcion2 == clone.front().horario){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "c" || InformacionPersonal.doctor == "C"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone.size();i++){
                    if(opcion == clone.front().fecha){
                    for(int j=0; j<clone.size(); j++){
                            if(opcion2 == clone.front().horario){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone.pop();
                    }
                }
            }
            

            if(band == true){
                InformacionPersonal.fecha = opcion;
                InformacionPersonal.horario = opcion2;
                status = false;
                cout<<"\nCita registrada con exito!, te esperamos\n";
            }
            else{
                cout<<"\nEste horario ya esta ocupado, por favor ingrese a otra  hora u otro dia\n";
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

            if(InformacionPersonal.doctor == "g" || InformacionPersonal.doctor == "G"){
                InformacionPersonal.pago = 12;
                for(int i=0; i<clone2.size();i++){
                    if(opcion3 == clone2.front().fecha){
                     for(int j=0; j<clone2.size(); j++){
                            if(opcion4 == clone2.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone2.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "p" || InformacionPersonal.doctor == "P"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone2.size();i++){
                    if(opcion3 == clone2.front().fecha){
                     for(int j=0; j<clone2.size(); j++){
                            if(opcion4 == clone2.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone2.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "d" || InformacionPersonal.doctor == "D"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone2.size();i++){
                    if(opcion3 == clone2.front().fecha){
                        for(int j=0; j<clone2.size(); j++){
                            if(opcion4 == clone2.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone2.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "e" || InformacionPersonal.doctor == "E"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone2.size();i++){
                    if(opcion3 == clone2.front().fecha){
                     for(int j=0; j<clone2.size(); j++){
                            if(opcion4 == clone2.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone2.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "c" || InformacionPersonal.doctor == "C"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone2.size();i++){
                    if(opcion3 == clone2.front().fecha){
                     for(int j=0; j<clone2.size(); j++){
                            if(opcion4 == clone2.front().horarioAdulto){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone2.pop();
                    }
                }
            }
            

            if(band == true){
                InformacionPersonal.fecha = opcion3;
                InformacionPersonal.horarioAdulto = opcion4;
                status = false;
                cout<<"\nCita registrada con exito!, te esperamos\n";
            }
            else{
                cout<<"\nEste horario ya esta ocupado, por favor ingrese a otra  hora u otro dia\n";
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
            cout<<"\nUsted al ser una persona menor de edad dispone de los siguientes horarios: \n";
            cout << "1) 9:30 pm - 10:00 pm       2) 10:00 pm - 10:30 pm\n";
            cout << "3) 10:30 pm - 11:00 pm      4) 11:00 pm - 11:30 pm\n";
            cout << "5) 11:30 pm - 12:00 pm      6) 12:00 pm - 12:30 pm\n";
            cout << "\nEscoja un horario: "; cin >> opcion6;

            if(InformacionPersonal.doctor == "g" || InformacionPersonal.doctor == "G"){
                InformacionPersonal.pago = 12;
                for(int i=0; i<clone3.size();i++){
                    if(opcion5 == clone3.front().fecha){
                     for(int j=0; j<clone3.size(); j++){
                            if(opcion6 == clone3.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone3.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "p" || InformacionPersonal.doctor == "P"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone3.size();i++){
                    if(opcion5 == clone3.front().fecha){
                     for(int j=0; j<clone3.size(); j++){
                            if(opcion6 == clone3.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone3.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "d" || InformacionPersonal.doctor == "D"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone3.size();i++){
                    if(opcion5 == clone3.front().fecha){
                        for(int j=0; j<clone3.size(); j++){
                            if(opcion6 == clone3.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone3.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "e" || InformacionPersonal.doctor == "E"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone3.size();i++){
                    if(opcion5 == clone3.front().fecha){
                     for(int j=0; j<clone3.size(); j++){
                            if(opcion6 == clone3.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone3.pop();
                    }
                }
            }

            if(InformacionPersonal.doctor == "c" || InformacionPersonal.doctor == "C"){
                InformacionPersonal.pago = 25;
                for(int i=0; i<clone3.size();i++){
                    if(opcion5 == clone3.front().fecha){
                     for(int j=0; j<clone3.size(); j++){
                            if(opcion6 == clone3.front().horarioNenes){
                            band = false;
                            }
                        }
                    }
                    if(!band){
                        break;
                    }
                    else{
                        clone3.pop();
                    }
                }
            }
            
            if(band == true){
                InformacionPersonal.fecha = opcion5;
                InformacionPersonal.horarioNenes = opcion6;
                status = false;
                cout<<"\nCita registrada con exito!, prosiga a la opcion de pgar cita.\n";
            }
            else{    
                cout<<"\nEste horario ya esta ocupado, por favor ingrese a otra  hora u otro dia\n";
            }
            system("pause");

        }while(status);

        Nenes.push(InformacionPersonal);
    }

}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de Pagar la cita.

void PagarCita(){
    queue<citas>clone = Ancianos;
    queue<citas>clone2 = Adultos;
    queue<citas>clone3 = Nenes;
    citas auxiliar ;

    bool found = false, band = false, band2 = false, band3 = false, status = true;
    int pago;
    string ElementoBuscar;
    string Tarjeta;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),10);
    cout<<"\n**Pago de cita**\n";
    cin.ignore();
    cout<<"Digite su DUI: "; getline(cin,ElementoBuscar);

    while (!clone.empty()) {
        if (clone.front().DUI == ElementoBuscar){
            band = true;
            found = true;
            auxiliar.NombrePaciente = clone.front().NombrePaciente;
            auxiliar.doctor = clone.front().doctor;
            auxiliar.fecha = clone.front().fecha;
            auxiliar.pago = clone.front().pago;
            clone.pop();
        }
        else{
            clone.pop();
        }

    }

    while (!clone2.empty()) {
        if (clone2.front().DUI == ElementoBuscar){
            band2 = true;
            found = true;
            auxiliar.NombrePaciente = clone2.front().NombrePaciente;
            auxiliar.doctor = clone2.front().doctor;
            auxiliar.fecha = clone2.front().fecha;
            auxiliar.pago = clone2.front().pago;
            clone2.pop();
        }
        else{
            clone2.pop();
        }
    }

    while (!clone3.empty()) {
        if (clone3.front().DUI == ElementoBuscar){
            band3 = true;
            found = true;
            auxiliar.NombrePaciente = clone3.front().NombrePaciente;
            auxiliar.doctor = clone3.front().doctor;
            auxiliar.fecha = clone3.front().fecha;
            auxiliar.pago = clone3.front().pago;
            clone3.pop();
        }
        else{
          clone3.pop();
        }
    }

    if (found == false) {
      cout << "\nNo se encontró una cita registrada con este DUI\n" << endl;
    }
    else{
      if(band == true){
        cout<<"\n**DATOS DE LA CITA**\n";
        cout<<"\nNombre: "<<auxiliar.NombrePaciente;
        cout<<"\nDoctor: "<<auxiliar.doctor; 
        cout<<"\nDia: "<<auxiliar.fecha;
        cout<<"\nTotal: $"<<auxiliar.pago;
      }
      else if(band2 == true){
        cout<<"\n**DATOS DE LA CITA**\n";
        cout<<"\nNombre: "<<auxiliar.NombrePaciente;
        cout<<"\nDoctor: "<<auxiliar.doctor; 
        cout<<"\nDia: "<<auxiliar.fecha;
        cout<<"\nTotal: $"<<auxiliar.pago;
      }
      else if(band3 == true){
        cout<<"\n**DATOS DE LA CITA**\n";
        cout<<"\nNombre: "<<auxiliar.NombrePaciente;
        cout<<"\nDoctor: "<<auxiliar.doctor; 
        cout<<"\nDia: "<<auxiliar.fecha;
        cout<<"\nTotal: $"<<auxiliar.pago;
      }    
      cout<<"\nIngrese su tarjeta de debito o credito: "; getline(cin,Tarjeta);
      cout<<"\nProcesando pago.....\n";
      cout<<"\nPago realizado con exito!\n";
    }  
    system("pause"); 
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de mostrar los horarios.

void Horarios(){
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),13);
    system("cls");
    cout<< "***************HORARIOS***************\n";
     cout<<"\nConsultas de lunes a sabados";
      cout<<"\nFechas disponibles a partir del 2 al 23 de diciembre";
      cout<<"\nContamos con los siguientes horarios para que tenga la mejor atencion:";
         cout<< "\n-----Adultos  de la tercera Edad-----\n";
    
            cout << "\n1) 6:00 am - 6:30 am       2) 6:30 am - 7:00 am\n";
            cout << "3) 7:00 am - 7:30 am       4) 7:30 am - 8:00 am\n";
            cout << "5) 8:00 am - 8:30 am       6) 8:30 am - 9:00 am\n";
            cout << "7) 9:00 am - 9:30 am\n";
            
         cout<<"\n-----Menores de Edad -----\n" ;
         
           cout << "\n1) 9:30 pm - 10:00 pm       2) 10:00 pm - 10:30 pm\n";
            cout << "3) 10:30 pm - 11:00 pm      4) 11:00 pm - 11:30 pm\n";
            cout << "5) 11:30 pm - 12:00 pm      6) 12:00 pm - 12:30 pm\n";
            
         cout<<"\n-----Adultos-----\n"; 

            cout << "\n1) 1:30 pm - 2:00 pm       2) 2:00 pm - 2:30 pm\n";
            cout << "3) 2:30 pm - 3:00 pm       4) 3:00 pm - 3:30 pm\n";
            cout << "5) 3:30 pm - 4:00 pm       6) 4:00 pm - 4:30 pm\n";
            cout << "7) 4:30 pm - 5:00 pm\n";
            
    system("pause");        
}

//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de Cancelar la cita pre agendada.

void CancelarCita(){
    queue<citas>clone = Ancianos;
    queue<citas>clone2 = Adultos;
    queue<citas>clone3 = Nenes;
    citas auxiliar ;

    bool found = false, band = false, band2 = false, band3 = false, status = true;
    int pago;
    string ElementoBuscar;
    string Tarjeta;

    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),11);
    cout<<"\n**Cancelar cita agendada**\n";
    cin.ignore();
    cout<<"Digite su DUI: "; getline(cin,ElementoBuscar);

    while (!clone.empty()) {
        if (clone.front().DUI == ElementoBuscar){
            band = true;
            found = true;
            auxiliar.NombrePaciente = clone.front().NombrePaciente;
            auxiliar.doctor = clone.front().doctor;
            auxiliar.fecha = clone.front().fecha;
            auxiliar.pago = clone.front().pago;
            clone.pop();
            while (!Ancianos.empty()){
                Ancianos.pop();
            }
        }
        else{
            clone.pop();
        }

    }

    while (!clone2.empty()) {
        if (clone2.front().DUI == ElementoBuscar){
            band2 = true;
            found = true;
            auxiliar.NombrePaciente = clone2.front().NombrePaciente;
            auxiliar.doctor = clone2.front().doctor;
            auxiliar.fecha = clone2.front().fecha;
            auxiliar.pago = clone2.front().pago;
            clone2.pop();
            while (!Adultos.empty()){
                Adultos.pop();
            }
        }
        else{
            clone2.pop();
        }
    }

    while (!clone3.empty()) {
        if (clone3.front().DUI == ElementoBuscar){
            band3 = true;
            found = true;
            auxiliar.NombrePaciente = clone3.front().NombrePaciente;
            auxiliar.doctor = clone3.front().doctor;
            auxiliar.fecha = clone3.front().fecha;
            auxiliar.pago = clone3.front().pago;
            clone3.pop();
            while (!Nenes.empty()){
                Nenes.pop();
            }
        }
        else{
          clone3.pop();
        }
    }

    if (found == false) {
      cout << "\nNo se encontro una cita registrada con este DUI\n" << endl;
    }
    else{
      if(band == true){
        cout<<"\n**DATOS DE LA CITA**\n";
        cout<<"\nNombre: "<<auxiliar.NombrePaciente;
        cout<<"\nDoctor: "<<auxiliar.doctor; 
        cout<<"\nDia: "<<auxiliar.fecha;
        cout<<"\nTotal: $"<<auxiliar.pago;
      }
      else if(band2 == true){
        cout<<"\n**DATOS DE LA CITA**\n";
        cout<<"\nNombre: "<<auxiliar.NombrePaciente;
        cout<<"\nDoctor: "<<auxiliar.doctor; 
        cout<<"\nDia: "<<auxiliar.fecha;
        cout<<"\nTotal: $"<<auxiliar.pago;
      }
      else if(band3 == true){
        cout<<"\n**DATOS DE LA CITA**\n";
        cout<<"\nNombre: "<<auxiliar.NombrePaciente;
        cout<<"\nDoctor: "<<auxiliar.doctor; 
        cout<<"\nDia: "<<auxiliar.fecha;
        cout<<"\nTotal: $"<<auxiliar.pago;
      }    
      cout<<"\nLa cita agendada a nombre de " <<auxiliar.NombrePaciente;
      cout<<" sera cancelada.\n\n";
      cout<<"\nCancelando cita agendada.....\n";
      cout<<"\nCita Cancelada, gracias.\n\n";
    }
    system("pause");
}


//<><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><><>><><><><><><><><><><><><><><><><><><><><><><><><><><><>//
//Funcion encargada de mostrar la informacion del negocio.
void Informacion(){
    
    bool status = true;
    int opcion;
    SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
    do
    {
        system("cls");
        cout << "\n---------INFORMACION---------\n";
        cout << " Bienvenidos a la Clinica La Fachada";
        cout << "\n Nos complace atenderte de lunes a sabados los dias restantes del 2020  B)"; 
        cout << "\n No hay precio para tu salud :)\n";
        cout << "\n-----------MENU DE INFORMACION-----------\n";
        cout << " 1. Acerca de la  clinica \n";
        cout << " 2. Acerca del Personal \n";
        cout << " 3. Mision \n";
        cout << " 4. Vision \n";
        cout << " 5. Valores Institucionales \n";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),4);
        cout << " 6. Salir \n ";
        SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE),6);
        cout << "Elija una opcion:  "; cin>>opcion;

        switch(opcion)
        {
        case 1:
            cout <<"\n --------------------------------Clinica La Fachada----------------------------------- \n";
            cout <<" Clinica La Fachada, fundada en Noviembre del 2020 por los excelentes doctores de origen\n";
            cout <<" Aleman ,Italiano, Ruso y Coreano. La clinica nace con el fin de apoyar a la poblacion, \n";
            cout <<" promoviendo el bienestar social a traves de la salud.\n\n";
            system("pause");
            break;
        case 2:
            cout <<"\n -------------------------------- Profesionales -------------------------------------- \n";
            cout << " Nuestros medicos que estan al tanto de tu salud son profecionales graduados y con doctorados\n"; 
            cout << " de las Universidades y mas TOP del mundo\n\n";
            cout << " *Dr.Duenas--Medico General--\n";
            cout << " Graduado de Harvard en medicina general, con doctorado en Oxford, siempre al tanto de tu salud\n\n";
            cout << " *Dra.Vega--Pediatra--\n";
            cout << " Graduada de Stanford en pediatria, con maestria y doctorado del TEC de monterrey, vela por la salud de tus crias\n\n";
            cout << " *Dra.Santiago--Dermatologa--\n";
            cout << " Doctorada en Dermatologia de Cambridge, busca siempre el bien de tu piel para que se vea sexy y limpia\n\n";
            cout << " *Dr.Henriquez--Endoclinologo--\n";
            cout << " Graduado de Massachusetts Institute of Technology (MIT) de Endocrinologia avanzada, busca el bien de tu cuerpo\n\n";
            cout << " *Dra.Escobar--Cardiologa--\n";
            cout << " Doctorada de Trinity College Dublin de Cardiologia, casada con el apuesto Dr.Henriquez, siempre al tanto su salud\n\n";
            cout << " *Antonio--Conserje--\n";
            cout << " El es el conserje, grande antonio.\n\n";
            
            system("pause");
            break;
        case 3:
            cout << "\n--------------------------------------------MISION----------------------------------------";
            cout << "\n Brindar servicios de salud primaria y promover la educacion con la calidad y calidez en funcion social\n\n";
            system("pause");
            break;
        case 4:
            cout << "\n--------------------------------------------VISION----------------------------------------";
            cout << "\n Impulsar el desarrollo humano a traves de la salud en medio de una pandemia mundial\n\n";
            system("pause");
            break;
        case 5:
            cout << "\n--------------------------------------VALORES INSTITUCIONALES-------------------------------\n";
            cout << "INTEGRIDAD: Transparencia en todo lo que hacemos\n";
            cout << "CALIDEZ: Trato amable con empatia\n";
            cout << "PROFESIONALISMO: Trabajo con responsabilidad y confianza\n";
            cout << "ETICA PROFESIONAL: Confidencialidad en el servicio\n";
            cout << "TRABAJO EN EQUIPO: Unidos somos mas efectivos\n";
            cout << "EQUIDAD: Trato justo y digno para todos\n";
            system("pause");
            break;
        case 6:
            status = false;
            system("pause");
            break;
        default:
            cout << "\nOpcion no valida\n";
            system("pause");
            break;
        }
    } while (status);

}