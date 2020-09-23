#ifndef docente_h
#define docente_h
#include <iostream>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct
{
	string nombre;
	string apellido;
	string correo;
	double nota1;
	double nota2;
}testudiante;
typedef struct
{
	int contador;
	testudiante datosestudiante[50];
}tlistaestudiante;
void cargarEstientes(tlistaestudiante& listaestudiante, testudiante& estudiante, string nombreArchiv);
void registrarestudiante(string nombreArchiv, bool &ver);
void registrarestudiantes(ofstream& archivoestudainte, tlistaestudiante& listaestudiente, testudiante& estudiente, int& contador1, string nombrearch, bool & ver);
void ingresodocente(string nombreArchiv, string nombredocente);
void listaestudiantess(tlistaestudiante& listaestudiante);
double promedio(double a, double b);
#endif
