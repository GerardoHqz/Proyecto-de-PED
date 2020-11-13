#include <iostream>
#include <queue>
#include <string>
using namespace std;

struct Citas    //se ingresan los datos de las citas
{
    string NombrePaciente;
    int EdadPaciente;
    int DUI;
};

typedef struct Citas citas;

struct Cola     //registro de las colas de ancianos,adultos,nenes
{
    queue <citas> Ancianos;
    queue <citas> Adultos;
    queue <citas> Nenes;
};

typedef struct Cola cola;

cola UnaCita;

void AgendarCita();
void CancelarCita();
void Horarios();
void Informacion();



