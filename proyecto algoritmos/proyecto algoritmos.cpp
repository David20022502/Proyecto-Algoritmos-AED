#include <iostream>
#include <fstream>
#include "ingress.h"
#include <ctime>
#include "registro.h"
#include "docente.h"
#include "ordenamiento.h"
#include "interfaz.h"
using namespace std;
int main()
{
    string usuari, contras;
    bool ingresa = false;
    int opc;
    do
    {
        cuadro(2, 2, 117, 25);//imprimimos el cuadro grande
        system("color 03");
        cuadro(30, 4, 88, 22);//imprimimos el cuadro pequeños
        //impresion del menu, el gotosy funciona para centrarle al menu
        gotoxy(45, 10); cout << "Sistema de Gestion de Notas" << endl;
        gotoxy(50, 12); cout << "1. Registrarse"<< endl;
        gotoxy(50, 13); cout << "2. Ingresar" << endl;
        gotoxy(50, 14); cout << "3. Salir" << endl;
        gotoxy(50, 15); cout << "opcion: ";
        gotoxy(60, 15); cin >> opc;
        switch (opc)
        {
        case 1:
        {
            system("cls");
            //llamamos al funcion registrarse
            cout << "sistema de registro" << endl;
            registrarse();
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            system("cls");
            //llamamos ala funcion de ingresar
            ingresar();
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            ingresa = true;
            break;
        }


        default:

            break;
        }


    } while (ingresa==false);
    return 0;
}
