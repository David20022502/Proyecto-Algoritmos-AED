#include <iostream>
#include <fstream>
#include <string>
#include "registro.h"
#include "docente.h"
using namespace std;
void registrarse()
{
    //damos nombres alas estructuras creadas en las listas correspondientes
    string validcontrase;
    ofstream registroDocente;
    tregistrar registrar;
    bool ok = true;
    int a=0,p = -1,i=0;
    string nombearchivoo;
    tlistaregistro listaregistro;
    //se carga los registros para validar si el usuario se repite o no
    cargarregistro(listaregistro, registrar);
    registroDocente.open("usuarios.txt", ios::app);
    cin.ignore();
    cout << "Nombres: ";
    cin>> registrar.nombre;
    cout << "Apellido: ";
    cin>> registrar.apellido;
    while (ok==true)
    {
        //aqui se valida si el usuario ingresado no se repita
        cout << "Usuario: ";
        cin >> registrar.usuario;
        for ( i = 0; i < listaregistro.contador-1; i++)
        {
            if (registrar.usuario == listaregistro.datosRegistro[i].usuario)
            {
                cout << "nombre de usuario no disponible" << endl;
                a = i;
            }
        }
        if (registrar.usuario == listaregistro.datosRegistro[a].usuario)
        {
            p = 0;
        }
        else
        {
            p = -1;
        }
        if (p==-1)
        {
            ok = false;
        }
    }
    cout << "Contraseña: ";
    cin >> registrar.contraseña;
    cout << "Verificar Contraseña: ";
    //aqui validmos si las dos contraseñas son iguales
    cin >> validcontrase;
    while (validcontrase != registrar.contraseña)
    {
        cout << "las contraseñas ingresadasno son correctas" << endl;
        cout << "verificar contraseña: ";
        cin >> validcontrase;
    }
    //aqui se guardan todos los datos ingresados
    registroDocente << registrar.nombre << endl;
    registroDocente << registrar.apellido << endl;
    registroDocente << registrar.usuario << endl;
    registroDocente << registrar.contraseña << endl;
    registroDocente.close();
    nombearchivoo = registrar.usuario + ".txt";
    cout << "Cuenta Creada Exitosamente" << endl;
    system("pause");
    system("cls");
    cout << "bienvenido al sistema" << endl;
    string nombredocente=registrar.nombre+" "+registrar.apellido;
    ingresodocente(nombearchivoo, nombredocente);
    
}
void cargarregistro(tlistaregistro& listaregistro, tregistrar& registrar)
{
    //aqui se cargan todos los usuarios y contraseña que hay en el archivo para validar que no se repitan
    ifstream lectura;
    listaregistro.contador = 0;
    char aux;
    lectura.open("usuarios.txt");
    if (lectura.is_open())
    {
        while (!(lectura.eof()))
        {
            lectura>> registrar.nombre;
            lectura>> registrar.apellido;
            lectura >> registrar.usuario;
            lectura >> registrar.contraseña;
            listaregistro.datosRegistro[listaregistro.contador] = registrar;
            listaregistro.contador++;
        }
    }
}
