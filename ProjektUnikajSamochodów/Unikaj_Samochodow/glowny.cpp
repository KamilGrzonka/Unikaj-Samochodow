#include <iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include<time.h>

#include "MainHeader.h"

using namespace std;

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Pozycja_Kursora;

void glowne_funkcje::menu() {
	ustaw_kursor(0, 0);
	srand((unsigned)time(NULL));
	while (1) {												//zmieniono do while na while, jesli pojawia sie problemy zmienic z powrotem
		system("cls");
		system("color B");									//kolor jasny niebieski
		gotoxy(45, 5); cout  << " ---------------------------- ";
		gotoxy(45, 6); cout  << " |     Unikaj Samochodow    | ";
		gotoxy(45, 7); cout  << " ---------------------------- ";
		gotoxy(45, 9); cout  << " 	GRAJ      	               ";
		gotoxy(45, 10); cout << " 	INSTRUKCJA	               ";
		gotoxy(45, 11); cout << " 	WYJDZ			           ";
		gotoxy(45, 13); cout << ">>> WYBOR:		               ";
		char op = _getch();

		switch (op) {
		case '1':
			tryby();
			break;

		case '2':
			instrukcja();
			break;

		case '3':
			exit(0);
			break;

		default:
			cout << "Blad! Sprobuj ponowownie";
			break;
		}

	}
}

void gotoxy(int x, int y) {
	Pozycja_Kursora.X = x;
	Pozycja_Kursora.Y = y;
	SetConsoleCursorPosition(console, Pozycja_Kursora);
}

void glowne_funkcje::ustaw_kursor(bool widoczny, DWORD rozmiar) {
	if(rozmiar == 0){
		rozmiar = 20;
	}
	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible= widoczny;
	lpCursor.dwSize = rozmiar;
	SetConsoleCursorInfo(console, &lpCursor);
}

void glowne_funkcje::koniec_gry() {
	system("cls");
	gotoxy(55, 13); cout << "Koniec Gry";
	_getch();
}

void glowne_funkcje::instrukcja() {
	system("cls");
	gotoxy(45, 5); cout << " ---------------------------- ";
	gotoxy(45, 6); cout << " |     Unikaj Samochodow    |";
	gotoxy(45, 7); cout << " ---------------------------- ";
	gotoxy(25, 9); cout << "Unikaj nadjezdzajacych samochodow poruszajac sie w lewo (A) i w prawo (B)" << endl;
	gotoxy(40, 12); cout << "Nacisnij dowolny przycisk by kontynuowac";
	_getch();
}