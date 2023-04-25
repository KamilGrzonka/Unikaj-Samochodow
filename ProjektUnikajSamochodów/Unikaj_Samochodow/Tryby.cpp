#include <iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include<time.h>

#include "MainHeader.h"

using namespace std;

void glowne_funkcje:: tryby() {
	poziom_latwy pl;
	poziom_sredni ps;
	poziom_trudny pt;
	poziom_bardzotrudny pbt;

	ustaw_kursor(0, 0);
	srand((unsigned)time(NULL));

	while (1) {
		system("cls");
		system("color B");
		gotoxy(45, 5); cout << " ---------------------------- ";
		gotoxy(45, 6); cout << " |     Unikaj Samochodow    | ";
		gotoxy(45, 7); cout << " ---------------------------- ";
		gotoxy(45, 9); cout << " 	Poziom Latwy              ";
		gotoxy(45, 10); cout << " 	Poziom Sredni              ";
		gotoxy(45, 11); cout << " 	Poziom Trudny	           ";
		gotoxy(45, 12); cout << " 	Poziom Bardzo Trudny	   ";
		gotoxy(45, 13); cout << " 	Powrot      	           ";
		gotoxy(45, 15); cout << ">>> WYBOR:		               ";
		char op = _getch();

		switch (op) {
		case '1':
			pl.latwy();
			break;
		case '2':
			ps.sredni();
			break;
		case '3':
			pt.trudny();
			break;
		case '4':
			pbt.bardzotrudny();
			break;
		case '5':
			menu();
			break;
		default:
			cout << "Blad! Sprobuj ponowownie";
			break;
		}
	}
}