#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "ordenamiento.h"
using namespace std;

#include <iomanip>


using namespace std;
//funcion principal el cual se llama de la lista docente
int ordenacionn(float notas[],int n)
{

    //asignamos notas
    /*for(int i=0;i<MAX;i++){
        notas[i]= 1 + rand()%20;
    }*/

    // Array de pruebas

    int opcion;
    do {
        opcion = menu();
        switch (opcion) {
        case 1: {
            burbuja(notas, n);
            imprimirNotas(notas, n);
            char tipoBusqueda[10] = "Burbuja";//
            escribir(notas, n, tipoBusqueda);//crear archivo
        }
              break;

        case 2: {
            algoritmoSeleccion(notas, n);
            imprimirNotas(notas, n);
            char tipoBusqueda[10] = "Seleccion";
            escribir(notas, n, tipoBusqueda);
        }
              break;

        case 3: {
            algoritmoInsercion(notas, n);
            imprimirNotas(notas, n);
            char tipoBusqueda[10] = "Insercion";
            escribir(notas, n, tipoBusqueda);  }
              break;

        case 4: {
            ordenar(notas, 0, n - 1);
            imprimirNotas(notas, n);
            char tipoBusqueda[10] = "Quicksort";
            escribir(notas, n, tipoBusqueda);
        }
              break;

        case 5: {
            //dividir(notas, 0, n - 1);
            imprimirNotas(notas, n);
            char tipoBusqueda[10] = "Mergesort";
            escribir(notas, n, tipoBusqueda);
        }
              break;

        case 6: {
            HeapSort(notas, n - 1);
            imprimirNotas(notas, n);
            char tipoBusqueda[10] = "Heapsort";
            escribir(notas, n, tipoBusqueda);
        }
              break;
        }
    } while (opcion != 0);




    /*for(int i=0;i<MAX;i++){
        notas[i]= 1 + rand()%20;
    }

    cout<<"notas"<<endl;
    for(int i=0;i<MAX;i++){
        cout<<notas[i]<<endl;
    }*/

    return 0;
}

int menu() {

    int op;

    do {
        cout << "---------------------------MENU PRINCIPAL-----------------------------" << endl;
        cout << "----------------------------- Ordenar ----------------------------------" << endl;
        cout << "1.Algoritmo de ordenamiento burbuja" << endl;
        cout << "2.Algoritmo de ordenamiento seleccion" << endl;
        cout << "3.Algoritmo de ordenamiento insercion" << endl;
        cout << "4.Algoritmo de ordenamiento ordenamiento Rápido (Quicksort)" << endl;
        cout << "5.Algoritmo de ordenamiento mergesort" << endl;
        cout << "6.Algoritmo de ordenamiento heapsort" << endl;
        cout << "0.salir" << endl;
        cout << "Elija un opcion" << endl;
        cin >> op;
        if ((op < 0) || (op > 6)) {
            cout << "Elija una opcion correcta";
        }

    } while ((op < 0) || (op > 6));
    return op;
}

//Impimir Notas
void imprimirNotas(float a[], int n) {

    cout << "*******************" << endl;

    cout << "Notas :" << endl;
    for (int i = 0; i < n; i++) {
        cout << a[i] << endl;
    }
    cout << "*******************" << endl;
}

//ordenamiento Burbuja
void burbuja(float a[], int n) {
    int iult = n - 1;
    bool cambio = true;
    while (cambio) {
        cambio = false;
        for (int i = 0; i < iult; i++) {
            if (a[i] > a[i + 1]) {
                // intercambiar
                int aux = a[i];
                a[i] = a[i + 1];
                a[i + 1] = aux;
                cambio = true;
            }
        }
        iult--;
    }
}

//ordenamiento Seleccion
void algoritmoSeleccion(float a[], int n) {
    int i, j, aux, min;
    for (i = 0; i < n; i++) {//recorrer arreglo
        min = i;
        for (j = i + 1; j < n; j++) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        aux = a[i];
        a[i] = a[min];
        a[min] = aux;
    }
}

//ordenamiento Insercion
void algoritmoInsercion(float a[], int n)
{
    int aux;

    for (int i = 0; i < n; i++)
    {
        aux = a[i];
        int p = i;
        while (p > 0)
        {
            if (a[p - 1] > aux)
            {
                a[p] = a[p - 1];
                a[p - 1] = aux;
            }
            p--;
        }

    }

}

//Ordenamiento Quicksort
int mitad(float arr[], int pinicial, int pfinal)
{
    return arr[(pinicial + pfinal) / 2];
}

void ordenar(float arr[], int pinicial, int pfinal)
{

    int i = pinicial;
    int j = pfinal;
    int temp;
    int piv = mitad(arr, pinicial, pfinal);

    do
    {
        while (arr[i] < piv)
        {
            i++;
        }
        while (arr[j] > piv)
        {
            j--;
        }

        if (i <= j)
        {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    } while (i <= j);

    if (pinicial < j)
        ordenar(arr, pinicial, j);
    if (i < pfinal)
        ordenar(arr, i, pfinal);
}

//ordenamiento Mergesort
/*
void dividir(float a[], int inicial, int final)
{
    int mitad;
    if (inicial < final)
    {
        mitad = (inicial + final) / 2;

        dividir(a, inicial, mitad);
        dividir(a, mitad + 1, final);
        Fusionar(a, inicial, final, mitad);
    }
}


void Fusionar(float a[], int pinicial, int pfinal, int medio)
{

    int i, j, k, temp[pfinal - pinicial + 1];
    i = pinicial;
    k = 0;
    j = medio + 1;

    while (i <= medio && j <= pfinal)
    {
        if (a[i] < a[j])
        {
            temp[k] = a[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = a[j];
            k++;
            j++;
        }
    }

    while (i <= medio)
    {
        temp[k] = a[i];
        k++;
        i++;
    }

    while (j <= pfinal)
    {
        temp[k] = a[j];
        k++;
        j++;
    }

    for (i = pinicial; i <= pfinal; i++)
    {
        a[i] = temp[i - pinicial];
    }

}
*/
//Ordenamiento Heapsort
void HeapSort(float b[], int n)
{
    int valor, temp, a;

    for (int i = n; i >=0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            valor = b[j];
            a = j / 2;
            while (a > 0 && b[a] < valor)
            {
                b[j] = b[a];
                j = a;
                a = a / 2;
            }
            b[j] = valor;
        }
        temp = b[1];
        b[1] = b[i];
        b[i] = temp;
    }

}


//Crear archivo.
void escribir(float a[], int n, char cadena1[]) {
    ofstream archivo;
    archivo.open("Ordenamiento.txt", ios::out);

    if (archivo.fail())
    {
        cout << "No se puede abrir el archivo";
        exit(1);
    }
    archivo << setw(50) << setfill('_') << '\n' << setfill(' ');
    archivo << "|" << setw(32) << "COLEGIO MEJIA" << setw(16) << "|" << endl;
    archivo << "|" << setw(37) << "REPORTE DE CALIFICACIONES" << setw(11) << "|" << endl;
    archivo << setw(50) << setfill('-') << '\n' << setfill(' ');
    archivo << "|" << setw(3) << "Calificaciones Ordenadas " << setw(23) << "|" << endl;
    archivo << "|" << setw(3) << "ALGORITMO: " << cadena1 << setw(30) << "|" << endl;
    archivo << setw(50) << setfill('-') << '\n' << setfill(' ');
    archivo << "|" << setw(3) << "N°:";
    for (int i = 0; i < n; i++)
    {
        archivo << "|" << a[i] << "|-";
    }
    archivo << setw(5) << "|" << endl;
    archivo << "|" << setw(48) << "|" << endl;
    archivo << "|" << setw(36) << "_____________________" << setw(12) << "|" << endl;
    archivo << "|" << setw(33) << "Byron Loarte" << setw(15) << "|" << endl;
    archivo << "|" << setw(32) << "1717653222" << setw(16) << "|" << endl;
    archivo << setw(50) << setfill('-') << '\n' << setfill(' ');

    archivo.close();
}
