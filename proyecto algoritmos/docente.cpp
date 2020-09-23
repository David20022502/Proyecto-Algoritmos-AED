#include <iostream>
#include <fstream>
#include <string>
#include  <iomanip>
#include "registro.h"
#include "ingress.h"
#include "docente.h"
#include "ordenamiento.h"
#include "interfaz.h"
#include <windows.h>
#include "busqueda.h"
using namespace std;
//creamos los prototipos a usar en todo el codigo
float notas[100];
void engeneral(tlistaestudiante& listaestudiante, testudiante& estudiante, string nombrear);
void ingresarnotas(tlistaestudiante& listaestudiante, testudiante& estudiante, string nombrear);
void deunestudiante(tlistaestudiante& listaestudiante, testudiante& estudiante, string nombrear);
void ordeanarnotasss(float notas[], tlistaestudiante& listaestudiante);
void buscarestudiante(float notas[], tlistaestudiante& listaestudiante, string& nombrearchi);
string materia="s";
void ingresodocente(string nombreArchiv, string nombredocente)
{
	tlistaregistro listaregistro;
	tregistrar registrar;
	tlistaestudiante listaestudiante;
	testudiante estudiante;
	string nombre_docente;
	int opc;
	bool ingresa = false, ver=true;
	do
	{
		//aqui cargamos todos los datos constatemente mientras estos son modificados o alguna cosa
		//cargarregistro(listaregistro, registrar);
		cuadro(2, 2, 117, 25);//impresion cuadro grande
		system("color 05");//cambiar color
		cuadro(30, 4, 88, 22);//impresion cuadro pequeño
		//aqui cargamos datos de los estudiantes
		cargarEstientes(listaestudiante, estudiante, nombreArchiv);
		if (materia=="s")
		{
			//aqui validamos si si el registro tiene una materia asignada i si no le pide una materia
			ver = false;
		}
		//aqui validamos con las datos ya cargados si dentro del archivo esta la materia ya ingresada
		cargarEstientes(listaestudiante, estudiante, nombreArchiv);
		gotoxy(32, 20); cout << "Docente: " << nombredocente<< endl;//aqui se imprime elnombre del docente cada vez que cambia de cuenta
		gotoxy(50, 10); cout << "   Sistema Calificaciones" << endl;
		gotoxy(50, 11); cout << " "<<endl;
		gotoxy(50, 12); cout << "1. Registrar estudiante" << endl;
		gotoxy(50, 13); cout << "2. Listado de estudiantes" << endl;
		gotoxy(50, 14); cout << "3. ingresar notas" << endl;
		gotoxy(50, 15); cout << "4. Ordenar notas" << endl;
		gotoxy(50, 16); cout << "5. buscar estudiante" << endl;
		gotoxy(50, 17); cout << "6. Cerrar sesion" << endl;
		gotoxy(50, 18); cout << "Opcion: ";
		gotoxy(58, 18); cin >> opc;
		switch (opc)
		{
		case 1:
		{
			system("cls");
			cout << "sistema " << endl;
			//llamamos a la funcion de registar estudiante
			registrarestudiante(nombreArchiv,ver);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "sistema " << endl;
			//llamamos al funcion de la base dde datos de los estudiantes
			listaestudiantess(listaestudiante);
			system("pause");
			system("cls");
			break;
		}
		case 3:
		{
			system("cls");
			cout << "sistema " << endl;
			//aqui llamamos a la funcionde ingrsar notas
			ingresarnotas(listaestudiante, estudiante, nombreArchiv);
			system("pause");
			system("cls");
			break;
		}
		case 4:
		{
			system("cls");
			cout << "sistema " << endl;
			//aqui ordenamos las notas
			ordeanarnotasss(notas, listaestudiante);
			system("pause");
			system("cls");
			break;
		}
		case 5:
		{
			system("cls");
			cout << "sistema " << endl;
			//aqui se busca alos estudiantes con esta funcion
			buscarestudiante(notas, listaestudiante, nombreArchiv);
			system("pause");
			system("cls");
			break;
		}
		case 6:
		{
			//para que se salga del bucle
			ingresa = true;
			break;
		}
		default:
			break;
		}

	} while (ingresa == false);
}
void cargarEstientes(tlistaestudiante& listaestudiante, testudiante& estudiante, string nombreArchiv)
{
	//aqui leemos todos los datos del archivo y lo pasamos alas listas correspondientes
	ifstream lectura;
	listaestudiante.contador = 0;
	char aux;
	lectura.open(nombreArchiv.c_str());
	if (lectura.is_open())
	{
		lectura >> materia;
		while (!(lectura.eof()))
		{
			lectura>> estudiante.nombre;
			lectura>> estudiante.apellido;
			lectura >> estudiante.correo;
			lectura >> estudiante.nota1;
			lectura >> estudiante.nota2;
			listaestudiante.datosestudiante[listaestudiante.contador] = estudiante;
			listaestudiante.contador++;
		}
	}
}
void registrarestudiante(string nombreArchiv, bool& ver)
{
	tlistaestudiante listaestudiante;
	listaestudiante.contador = 0;
	ofstream datos;
	testudiante estudiante;
	int x, contador1 = listaestudiante.contador;
	x = contador1;
	if (x == 0)
	{
		x = contador1 + 1;
	}
	if (ver==false)
	{
		//aqui se valida si al momento de crear una cuenta nueva tiene registrada una materia
		cout << "materia: ";
		cin >> materia;
	}
	if (listaestudiante.contador <= 50)
	{
		//aqui se piden todos los datos de los estudiantes
		estudiante.nombre = "s";
		cout << "INGRESE X PARA TERMINAR" << endl;
		while (estudiante.nombre != "x")
		{
			if (listaestudiante.contador <= 50)
			{
				cout << "datos del estudiante"<< endl;
				cout << "Nombre: ";
				cin>> estudiante.nombre;
				if (estudiante.nombre != "x")
				{
					cout << "Apellido: ";
					cin>> estudiante.apellido;
					cin.ignore();
					cout << "Correo: ";
					cin >> estudiante.correo;
					//aqui se pasan todos los datos que ingreso ala lista
					listaestudiante.datosestudiante[listaestudiante.contador] = estudiante;
					contador1 = listaestudiante.contador;
					listaestudiante.contador++;
					x++;
					//aqui se le llama a esta funcion para que los datos los almacene en un archivo
					registrarestudiantes(datos, listaestudiante, estudiante, contador1, nombreArchiv,ver);
				}
			}
			else
			{
				cout << "Registro lleno" << endl;
				estudiante.nombre = "x";
			}
		}
	}
	else
	{
		cout << "Rgistro lleno" << endl;
	}
}
void registrarestudiantes(ofstream& archivoestudainte, tlistaestudiante& listaestudiente, testudiante& estudiente, int& contador1, string nombrearch, bool& ver)
{
	//aqui se almacenan todos los datos ingresados 
	archivoestudainte.open(nombrearch.c_str(), ios::app);
	if (ver == false)
	{
		//aqui se ingresa la materia si auno se a lo a introducido
		archivoestudainte << materia << endl;
		ver = true;
	}
	if (archivoestudainte.is_open())
	{
		//aqui se alamcenan losdatos n el archivo
		archivoestudainte << listaestudiente.datosestudiante[contador1].nombre << endl;
		archivoestudainte << listaestudiente.datosestudiante[contador1].apellido << endl;
		archivoestudainte << listaestudiente.datosestudiante[contador1].correo << endl;
		archivoestudainte << 0 << endl;
		archivoestudainte << 0 << endl;
		archivoestudainte.close();
	}
	else
	{
		cout << "error al abrir" << endl;
	}
}
void listaestudiantess(tlistaestudiante& listaestudiante)
{
	double promediocurso=0;
	int t=0, aprobado=0, reprobado=0,suspenso=0;
	int x = 1;
	//aqui se imprimen todos los datos que tengan el usuario dpendiendo de la cuenta en la que este
	cout << "_____________________________________________________________________________" << endl;
	cout << "\t\t\tCOLEGIO MEJIA" << right << setw(40)<<"|" << endl;
	cout << "\t\tREPORTE DE CALIFICACIONES" <<right << setw(36)<< "|"<< endl;
	cout << right << setw(77)<< "|"<< endl;
	cout << "_____________________________________________________________________________" << endl;
	cout  <<"Anio Lectivo: 2020-2021" <<right << setw(54)<< "|"<< endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "Materia: " << materia << endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "N" << "|"<< right << setw(14) << "Estudiante" << "|"<< setw(14) << "Apellido" <<"|"<< setw(20) << "Correo" << "|"<< setw(7) << "nota1" <<"|"<< setw(7) << "nota 2" << "|"<<setw(7) << "total"<< "|"<< endl;
	for (int i = 0; i < listaestudiante.contador-1; i++)
	{
		cout << "_____________________________________________________________________________" << endl;
		cout << x <<"|"<<right << setw(14) << listaestudiante.datosestudiante[i].nombre << "|"
			<< setw(14) << listaestudiante.datosestudiante[i].apellido<< "|"
			<< setw(20) << listaestudiante.datosestudiante[i].correo << "|"
			<< setw(7) << listaestudiante.datosestudiante[i].nota1 << "|"
			<< setw(7) << listaestudiante.datosestudiante[i].nota2 << "|"
			<< setw(7) << promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) << "|"<< endl;
		notas[i] = promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) ;
		t++;
		//aqui se suman los promedios para sacar el promedio y tambien se validan los aprobados reprobados y ens uspenso
		promediocurso=promediocurso+ promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2);
		if (promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2)>=14 && promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) <=20)
		{
			aprobado++;
		}
		if (promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) >= 9 && promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) <14)
		{
			suspenso++;
		}
		if (promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) >= 1 && promedio(listaestudiante.datosestudiante[i].nota1, listaestudiante.datosestudiante[i].nota2) <9)
		{
			reprobado++;
		}
		x++;
	}
	//aqui se imprimen los resultados del curso
	cout << "_____________________________________________________________________________" << endl;
	cout << "RESUMEN: " << right <<setw(68)<< "|"<<endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "Promedio del curso: " << right<<setw(40) << promediocurso/t<<setw(17) <<"|"<<endl;
	cout << "_____________________________________________________________________________" << endl;
	cout << "          |" << right<<setw(40) << "Aprobado(14-20)"<< setw(22)<<"|"<< aprobado<< setw(3)<< "|"<<endl;
	cout << "          |" << "__________________________________________________________________"<< endl;
	cout << "  TOTAL   |" << right << setw(40) << "Suspenso(9-13)" << setw(22) << "|" << suspenso << setw(3) << "|"<< endl;
	cout << "          |" << "__________________________________________________________________" << endl;
	cout << "          |" << right << setw(40) << "Reprobado(1-8)" << setw(22) << "|" << reprobado <<setw(3)<<"|"<< endl;
	cout << "_____________________________________________________________________________" << endl;
}
double promedio(double a, double b)
{
	//aqui estamos utilizando una funcion recursiva para poder sacar la suma de las notas
	double resultad=0;
	if (a==0)
	{
		return b;
	}
	if (b==0)
	{
		return a;
	}
	else
	{
		return 1 + promedio(a, b - 1);
	}
}
void ingresarnotas(tlistaestudiante &listaestudiante, testudiante& estudiante, string nombrear)
{
	//aqui ingresamos las notas de dependiendo si se quiere de todos o solo de uno
	int opc;
	bool ingresa = false;
	do
	{
		cout << "1. En general" << endl;
		cout << "2. De un estudiante" << endl;
		cout << "3. atras" << endl;
		cout << "opcion: ";
		cin >> opc;
		switch (opc)
		{
		case 1:
		{
			system("cls");
			cout << "ingreso notas " << endl;
			engeneral(listaestudiante, estudiante, nombrear);
			system("pause");
			system("cls");
			break;
		}
		case 2:
		{
			system("cls");
			cout << "ingreso notas " << endl;
			deunestudiante(listaestudiante, estudiante, nombrear);
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
}
void engeneral(tlistaestudiante& listaestudiante, testudiante& estudiante, string nombrear)
{
	//esta funcion pide notas de todos los estudiantes y los almacen en aun archivo
	for (int i = 0; i < listaestudiante.contador-1; i++)
	{
		cout << "Nombre: "<<listaestudiante.datosestudiante[i].nombre << endl;
		cout << "Apellido: "<<listaestudiante.datosestudiante[i].apellido << endl;
		cout <<"Correo: "<< listaestudiante.datosestudiante[i].correo << endl;
		cout << "Nota 1: ";
		cin >> listaestudiante.datosestudiante[i].nota1;
		cout << "Nota 2: ";
		cin >> listaestudiante.datosestudiante[i].nota2;
	}
	ofstream ingresodatos;
	ingresodatos.open("auxiliar.txt", ios::app);
	ingresodatos << materia << endl;
	for (int i = 0; i < listaestudiante.contador-1; i++)
	{
		ingresodatos << listaestudiante.datosestudiante[i].nombre << endl;
		ingresodatos << listaestudiante.datosestudiante[i].apellido << endl;
		ingresodatos << listaestudiante.datosestudiante[i].correo << endl;
		ingresodatos << listaestudiante.datosestudiante[i].nota1 << endl;
		ingresodatos << listaestudiante.datosestudiante[i].nota2 << endl;
	}
	ingresodatos.close();
	//aqui se lo almacena en el archivo auxiliar que tenemos en el anteriory eliminamos el archivo sin las notas y el nuevo lo renombramos
	remove(nombrear.c_str());
	rename("auxiliar.txt", nombrear.c_str());
}
void deunestudiante(tlistaestudiante& listaestudiante, testudiante& estudiante, string nombrear)
{
	int x = -1;
	string nombreestud;
	listaestudiantess(listaestudiante);
	cout << "nombre del estudiante: ";
	cin >> nombreestud;
	for (int i = 0; i < listaestudiante.contador - 1; i++)
	{
		//aqui primero buscamos la posicion del estudiante para cambiar la nota
		if (nombreestud == listaestudiante.datosestudiante[i].nombre)
		{
			x = i;
		}
	}
	if (x != -1)
	{
		//aqui aparece los datos del estudiante y la opcion de ingresar nuevas notas
		cout << "Nombre: "<<listaestudiante.datosestudiante[x].nombre << endl;
		cout << "Apellido: "<<listaestudiante.datosestudiante[x].apellido << endl;
		cout << "Correo: "<<listaestudiante.datosestudiante[x].correo << endl;
		cout << "Nota 1: ";
		cin >> listaestudiante.datosestudiante[x].nota1;
		cout << "Nota 2: ";
		cin >> listaestudiante.datosestudiante[x].nota2;

		ofstream ingresodatoss;
		ingresodatoss.open("auxi.txt", ios::app);
		ingresodatoss << materia << endl;
		for (int i = 0; i < listaestudiante.contador - 1; i++)
		{
			//aqui se almacena en el archivo los datos con las notas
			ingresodatoss << listaestudiante.datosestudiante[i].nombre << endl;
			ingresodatoss << listaestudiante.datosestudiante[i].apellido << endl;
			ingresodatoss << listaestudiante.datosestudiante[i].correo << endl;
			ingresodatoss << listaestudiante.datosestudiante[i].nota1 << endl;
			ingresodatoss << listaestudiante.datosestudiante[i].nota2 << endl;
		}

		ingresodatoss.close();
		//aqui se lo almacena en el archivo auxiliar que tenemos en el anteriory eliminamos el archivo sin las notas y el nuevo lo renombramos
		remove(nombrear.c_str());
		rename("auxi.txt", nombrear.c_str());


	}
	else
	{
		cout << "estudiante no encontrado" << endl;
	}
}
void ordeanarnotasss(float notas[], tlistaestudiante& listaestudiante)
{
	//aqui llamamos als funciones de ordenar notas
	int tam=listaestudiante.contador-1;
	ordenacionn(notas, tam);
}
void buscarestudiante(float notas[],tlistaestudiante& listaestudiante, string &nombrearchi)
{
	//aqui se le llama a la funcion de buscar estudiantes
	int tamm = listaestudiante.contador - 1;
	busequedas(tamm, nombrearchi, notas);
}