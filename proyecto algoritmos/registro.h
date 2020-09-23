#ifndef registro_h
#define registro_h
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
typedef struct
{
    string nombre;
    string apellido;
    string usuario;
    string contraseña;
}tregistrar;
typedef struct
{
    int contador;
    tregistrar datosRegistro[100];
}tlistaregistro;
void registrarse();
void cargarregistro(tlistaregistro& listaregistro, tregistrar& registrar);
#endif 