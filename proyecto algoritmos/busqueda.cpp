#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "busqueda.h"
#include "docente.h"
using namespace std;
//funcion principal para utilizarlo de otras funciones
void busequedas(int &tam, string &nombrearchivo, float notass[])
{
    menubusqueda(tam, nombrearchivo, notass);
}
void menubusqueda(int &tam, string &nombrearchivo, float notass[])
{
    tlistaestudiante listaestudiante;
    testudiante estudiante;
    float notas;
    string nmbre;
    bool ingresa = false;
    int opc, opcion;
    //aqui se cargan todos los datos de lso estudiantes para poder hacer la busqueda de las notas
    cargarEstientes(listaestudiante, estudiante, nombrearchivo);
    do
    {
        cout << "---------------------------MENU DE BUSQUEDA -----------------------------" << endl;
        cout << "1. Algoritmo de busqueda lineal" << endl;//busqueda lineal
        cout << "2. Algoritmo de busqueda binaria" << endl;//busqueda binaria
        cout << "3.Algoritmo de busqueda interpolacion" << endl;//busqueda interpolacion
        cout << "4. Salir" << endl;
        cout << "Elija un opcion: ";
        cin >> opc;
        switch (opc)
        {
        case 1:
        {
            //damos la opcion de buscar por nombre o por la nota
            cout << "1. buscar por nota" << endl;
            cout << "2. buscar por nombre" << endl;
            cout << "opcion: ";
            cin >> opcion;
            //llamamos al funcion de buscar
            lineal(notas, nmbre, tam, opcion, listaestudiante);
            system("pause");
            system("cls");
            break;
        }
        case 2:
        {
            //llamamos ala funcion de la busqueda binaria
            binaria(notas, tam, listaestudiante, notass);
            system("pause");
            system("cls");
            break;
        }
        case 3:
        {
            //llamamos ala funcion de interpolacion 
            interpolacion(notas, tam, listaestudiante, notass);
            system("pause");
            system("cls");
            break;
        }
        case 4:
        {
            ingresa = true;
            break;
        }
        default:
            break;
        }
    } while (ingresa==false);


}
void lineal(float &notas, string &nmbre, int &tam, int &opcion, tlistaestudiante &listaestudiante)
{
    int x = -1;
    switch (opcion)
    {
    case 1:
    {
        //ingresamos la nota a buscar 
        cout << "ingrese la nota: ";
        cin >> notas;
        for (int i = 0; i < tam; i++)
        {
            //aqui con la nota buscamosla posicion en la que se encuentre la misma
            if (notas==listaestudiante.datosestudiante[i].nota1 || notas==listaestudiante.datosestudiante[i].nota2)
            {
                x = 0;
                cout << "--------------------------------------------------------------" << endl;
                cout << "nombre:       " << listaestudiante.datosestudiante[i].nombre << endl;
                cout << "Apellido:     " << listaestudiante.datosestudiante[i].apellido << endl;
                cout << "Correo:       " << listaestudiante.datosestudiante[i].correo << endl;
                cout << "Nota 1:       "  << listaestudiante.datosestudiante[i].nota1 << endl;
                cout << "Nota 2:       " << listaestudiante.datosestudiante[i].nota2 << endl;
                cout << "Promedio:     " << promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) << endl;
                cout << "--------------------------------------------------------------" << endl;
            }
        }
        if (x==-1)
        {
            cout << "Estudiante no encontrado" << endl;
        }
        break;
    }
    case 2:
    {
        //pedimos el nombre a buscar
        cout << "ingrese el nombre: ";
        cin >> nmbre;
        for (int i = 0; i < tam; i++)
        {
            //con el nombre buscamos la posicion en la que se encuentra y la imprimimos
            if (nmbre == listaestudiante.datosestudiante[i].nombre)
            {
                x = 0;
                cout << "--------------------------------------------------------------" << endl;
                cout << "nombre:       " << listaestudiante.datosestudiante[i].nombre << endl;
                cout << "Apellido:     " << listaestudiante.datosestudiante[i].apellido << endl;
                cout << "Correo:       " << listaestudiante.datosestudiante[i].correo << endl;
                cout << "Nota 1:       " << listaestudiante.datosestudiante[i].nota1 << endl;
                cout << "Nota 2:       " << listaestudiante.datosestudiante[i].nota2 << endl;
                cout << "Promedio:     " << promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2)  << endl;
                cout << "--------------------------------------------------------------" << endl;
            }
        }
        if (x == -1)
        {
            cout << "Estudiante no encontrado" << endl;
        }
        break;
    }
    default:
        cout << "opcion invalida" << endl;
        break;
    }
}
void binaria(float &notas, int &tam, tlistaestudiante& listaestudiante, float notass[])
{
    int  i, j, k,z;
    i = 0;
    j = tam;
    //ingresamos la nota a buscar
    cout << "ingrese la nota: ";
    cin >> notas;
        do {

            k = (i + j) / 2;
            if (notass[k] <= notas)
            {
                i = k + 1;
            }
            if (notass[k] >= notas)
            {
                j = k - 1;
            }


        } while (i <= j);
        if (notas == notass[k])
        {
            //aqui con la nota ya encontrada buscamos la posicion en la que se encuantra dicha nota
            for (int i = 0; i < listaestudiante.contador-1; i++)
            {
                if (promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) ==notass[k])
                {
                    z = i;
                }
            }
            //una vez con la posicion podemos imprimir todos los datos de esa posicion
            cout << "--------------------------------------------------------------" << endl;
            cout << "\tNota encontrada" << endl;
            cout << "nombre:      " << listaestudiante.datosestudiante[z].nombre << endl;
            cout << "Apellido:    " << listaestudiante.datosestudiante[z].apellido << endl;
            cout << "Correo:      " << listaestudiante.datosestudiante[z].correo << endl;
            cout << "Nota 1:      " << listaestudiante.datosestudiante[z].nota1 << endl;
            cout << "Nota 2:      " << listaestudiante.datosestudiante[z].nota2 << endl;
            cout << "Promedio:    " << promedio(listaestudiante.datosestudiante[z].nota1, listaestudiante.datosestudiante[z].nota2)  << endl;
            cout << "--------------------------------------------------------------" << endl;
        }
        else
        {
            cout << "nota no encontrada " << endl;

        }
 
}
void interpolacion(float& notas, int& tam, tlistaestudiante& listaestudiante, float notass[])
{
    int ultimo = tam-1;
    int x = tam,z;
    int medio,primero=0;
    float n;
    int contador = 0;
    //pedimos la nota a buscar
    cout << "ingrese la nota: ";
    cin >> notas;
    n = notas;
    //aqui empieza a buscar la nota dentro del arreglo
    while (notass[primero] != n && contador <x )
    {

        medio = primero + ((n - notass[primero]) * (ultimo - primero)) / (notass[ultimo] - notass[primero]);

        if (notass[medio] < n)
            ultimo = medio + 1;
        else if (notass[medio] > n)
            ultimo = medio - 1;
        else
            primero = medio;
        contador++;

        break;
    }
    
    if (notass[primero] == n)
    {
        //aqui buscamos la posicion en la que esta dicha nota 
        for (int i = 0; i < listaestudiante.contador - 1; i++)
        {
            if (promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) == notass[primero])
            {
                z = i;
            }
        }
        //imprimimos dicha posicion todos los datos
        cout << "--------------------------------------------------------------" << endl;
        cout << "\tNota encontrada" << endl;
        cout << "nombre:      " << listaestudiante.datosestudiante[z].nombre << endl;
        cout << "Apellido:    " << listaestudiante.datosestudiante[z].apellido << endl;
        cout << "Correo:      " << listaestudiante.datosestudiante[z].correo << endl;
        cout << "Nota 1:      " << listaestudiante.datosestudiante[z].nota1 << endl;
        cout << "Nota 2:      " << listaestudiante.datosestudiante[z].nota2 << endl;
        cout << "Promedio:    " << promedio(listaestudiante.datosestudiante[z].nota1, listaestudiante.datosestudiante[z].nota2) << endl;
        cout << "--------------------------------------------------------------" << endl;

    }
    else
    {
        cout << "nota no encontrada" << endl;
    }
}