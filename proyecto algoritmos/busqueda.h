#ifndef busqueda_h
#define busqueda_h
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include "docente.h"
using namespace std;
void menubusqueda(int &tam, string &nombrearchivo, float notass[]);
void lineal(float &notas, string &nmbre, int &tam, int &opcion, tlistaestudiante& listaestudiante);
void binaria(float &notas, int &tam, tlistaestudiante& listaestudiante, float notass[]);
void interpolacion(float& notas, int& tam, tlistaestudiante& listaestudiante, float notass[]);
void busequedas(int &tam, string &nombrearchivo, float notass[]);
#endif
