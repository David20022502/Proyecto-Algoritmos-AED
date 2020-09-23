#ifndef ordenamiento_h
#define ordenamiento_H
/*
#include <iostream>
#include <fstream>
#include <ctime>
#include "docente.h"
using namespace std;
//int mitad(int arr[], int pinicial, int pfinal);
int mitad(double arr[], int pinicial, int pfinal);
//void ordenar(int arr[], int pinicial, int pfinal);
void ordenar(double arr[], int pinicial, int pfinal);
int quiksort(double A[], int tam);
////
int mergesort(double numeros[], int tam);
void divicion(double a[], int inicial, int final);
void unir(double a[], int pinicial, int pfinal, int medio);
///
void ordenarlos(int arr[], int tam);
void ingresar(int arr[], int tam);
void imprimir(int arr[], int tam);
int heapsort();
///
void burbuja();
void ordenacion();*/
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
using namespace std;

#include <iomanip>


using namespace std;

//constate de arrreglo
const int MAX = 10;



//prototipos
int menu();
void escribir(float a[], int n, char cadena1[]);//crear archivo

void burbuja(float a[], int n);//metodo burbuja
void algoritmoSeleccion(float a[], int n);//metodo seleccion
void imprimirNotas(float a[], int n);//Imprimir en pantalla
void algoritmoInsercion(float a[], int n);//metodo Insercion

int mitad(float arr[], int pinicial, int pfinal);//Ordenamiento Quicksort
void ordenar(float arr[], int pinicial, int pfinal);//Ordenamiento Quicksort

//void dividir(float a[], int inicial, int final);//ordenamiento Mergesort
//void Fusionar(float a[], int pinicial, int pfinal, int medio);//ordenamiento Mergesort

void HeapSort(float a[], int n);//Ordenamiento Heapsort
int ordenacionn(float notas[], int n);
#endif 
