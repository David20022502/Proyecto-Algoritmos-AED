#include <iostream>
#include <fstream>
#include "registro.h"
#include "docente.h"
#include "ingress.h"
#include <windows.h>
#include "interfaz.h"
using namespace std;
void ingresar()
{
    //aqui damos nombres alas estructuras creadas anteriormente en las listas correspondientes
    tlistaregistro listaregistro;
    tregistrar registrar;
    //aqui se cargan datos para que valide si el usuario ingresado sea el correcto
    cargarregistro(listaregistro, registrar);
    string usuario,nombrearchiv;
    string contraseña, nombredocente;
    bool ok = false;
    while (usuario != "x")
    {
        cuadro(2, 2, 117, 25);//impresion del cuadro grande
        system("color 05");
        cuadro(30, 4, 88, 22);//impresion del cuadro pequeño
        gotoxy(50, 10); cout << "SISTEMA DE INGRESO" << endl;
        gotoxy(50, 11); cout << endl;
        gotoxy(50, 12); cout << "Usuario: ";
        gotoxy(60, 12); cin >> usuario;
        //aqui se valide que si no quiere crear la cuenta solo pone x y no se guarda nada
        if (usuario != "x")
        {
            gotoxy(50, 13); cout << "Password: ";
            gotoxy(60, 13); cin >> contraseña;
            //aqui se valida si la contraseñaes la correcta segun el archivo
            for (int i = 0; i < listaregistro.contador; i++)
            {
                if (usuario == listaregistro.datosRegistro[i].usuario & contraseña == listaregistro.datosRegistro[i].contraseña)
                {
                    ok = true;
                    nombredocente = listaregistro.datosRegistro[i].nombre + " " + listaregistro.datosRegistro[i].apellido;
                    nombrearchiv = usuario + ".txt";
                    usuario = "x";
                }
            }
            if (ok == false)
            {
                cout << "usuario o contraseña incorrectos" << endl;
                system("pause");
                system("cls");
            }
        }
    }
    if (ok == true)
    {
        gotoxy(50, 13); cout << "bienvenido al sistema" << endl;
        gotoxy(45, 14); system("pause");
        system("cls");
        ingresodocente(nombrearchiv,nombredocente);
    }
}