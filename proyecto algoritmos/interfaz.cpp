#include <iostream>
#include <string.h>
#include <windows.h>
#include <conio.h>
using namespace std;
//se cran funciones para poder ser utilizadas en las creacion de los cuadros internos y externos del programa
void gotoxy(int x, int y);
void cuadro(int x1, int y1, int x2, int y2);
//aqui cambios los colores alas letras 
void txtparpa(string texto) 
{
	bool estado = 0;
	int contar = 0;
	do {
		if (contar = 5) {
			system("cls");
			system("color 01");
			gotoxy(50, 10); cout << texto;
			if (contar = 10) {
				system("cls");
				system("color 04");
				gotoxy(50, 10); cout << texto;
				if (contar = 15) {
					system("cls");
					system("color 06");
					gotoxy(50, 10); cout << texto;
					if (contar = 20) {
						system("cls");
						system("color 05");
						gotoxy(50, 10); cout << texto;
					}
				}
			}
		}

		contar++;
	} while (estado = true);
}
//se crea esta funcion para poder centrar losmenus en la consola
void gotoxy(int x, int y) {
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

//FUNCION PARA DIBUJAR CUADRO:
// e crea esta funcion para dibujar loscuadros en la cosola
void cuadro(int x1, int y1, int x2, int y2)
{
	int i;
	for (i = x1; i < x2; i++) {
		gotoxy(i, y1); printf("�"); //linea horizontal superior
		gotoxy(i, y2); printf("�"); //linea horizontal inferior
	}
	for (i = y1; i < y2; i++) {
		gotoxy(x1, i); printf("�"); //linea vertical izquierda
		gotoxy(x2, i); printf("�"); //linea vertical derecha
	}
	gotoxy(x1, y1); printf("�"); //Esquinas del cuadro
	gotoxy(x1, y2); printf("�");
	gotoxy(x2, y1); printf("�");
	gotoxy(x2, y2); printf("�");
}
/*
void txtparpa(string texto) {
	bool estado = true;
	int contar = 0;
	do {
		if (contar = 5) {
			system("cls");
			system("color 01");
			cout << texto;
		}
		if (contar = 10) {
			system("cls");
			system("color 04");
			cout << texto;
		}
		if (contar = 15) {
			system("cls");
			system("color 06");
			cout << texto;
		}
		if (contar = 20) {
			system("cls");
			system("color 05");
			cout << texto;

		}
		contar++;
	} while (estado = true);
}*/