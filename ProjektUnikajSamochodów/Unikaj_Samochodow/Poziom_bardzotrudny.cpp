#include <iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include<time.h>

#include "MainHeader.h"

using namespace std;

glowne_funkcje gf4;

void poziom_bardzotrudny::generuj_wroga(int ind) {
	wrogX[ind] = 17 + rand() % (33);
}

void poziom_bardzotrudny::rysuj_wroga(int ind) {
	if (wrog_flaga[ind] == 1) {
		gotoxy(wrogX[ind], wrogY[ind]);   cout << "|  |";
		gotoxy(wrogX[ind], wrogY[ind]);   cout << "[**]";
		gotoxy(wrogX[ind], wrogY[ind] + 1); cout << " ** ";
		gotoxy(wrogX[ind], wrogY[ind] + 2); cout << "[**]";
		gotoxy(wrogX[ind], wrogY[ind] + 3); cout << " vv ";
	}
}

void poziom_bardzotrudny::usun_wroga(int ind) {
	if (wrog_flaga[ind] == 1) {
		gotoxy(wrogX[ind], wrogY[ind]);   cout << "    ";
		gotoxy(wrogX[ind], wrogY[ind]);   cout << "    ";
		gotoxy(wrogX[ind], wrogY[ind] + 1); cout << "    ";
		gotoxy(wrogX[ind], wrogY[ind] + 2); cout << "    ";
		gotoxy(wrogX[ind], wrogY[ind] + 3); cout << "    ";
	}
}

void poziom_bardzotrudny::resetuj_wroga(int ind) {
	usun_wroga(ind);
	wrogY[ind] = 1;
	generuj_wroga(ind);
}

void poziom_bardzotrudny::rysuj_granice() {
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		for (int j = 0; j < 17; j++) {
			gotoxy(0 + j, i); cout << "�";
			gotoxy(WIN_WIDTH - j, i); cout << "�";
		}
	}
	for (int i = 0; i < SCREEN_HEIGHT; i++) {
		gotoxy(SCREEN_WIDTH, i); cout << "�";
	}
}

int poziom_bardzotrudny::kolizja() {
	if ((wrogY[0]) + 4 >= 23) {
		if (wrogX[0] + 4 - pozycja_auta >= 0 && wrogX[0] + 4 - pozycja_auta < 9) {
			return 1;
		}
	}
	return 0;
}

void poziom_bardzotrudny::rysuj_auto() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(j + pozycja_auta, i + 22); cout << Auto[i][j];
		}
	}
}

void poziom_bardzotrudny::usun_auto() {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			gotoxy(j + pozycja_auta, i + 22); cout << " ";
		}
	}
}

void poziom_bardzotrudny::aktualizuj_wynik() {
	gotoxy(WIN_WIDTH + 7, 5); cout << "Wynik: " << wynik << endl;
}

void poziom_bardzotrudny::bardzotrudny() {
	system("color c");						//kolor jasny czerwony
	pozycja_auta = -1 + WIN_WIDTH / 2;
	wynik = 0;
	wrog_flaga[0] = 1;
	wrog_flaga[1] = 0;
	wrog_flaga[2] = 0;
	wrogX[0] = wrogY[1] = 1;

	system("cls");
	rysuj_granice();
	aktualizuj_wynik();
	generuj_wroga(0);
	generuj_wroga(1);
	generuj_wroga(2);

	gotoxy(WIN_WIDTH + 2, 2); cout << "UNIKAJ SAMOCHODOW";
	gotoxy(WIN_WIDTH + 6, 4); cout << "---------";
	gotoxy(WIN_WIDTH + 4, 12); cout << "STREROWANIE:";
	gotoxy(WIN_WIDTH + 7, 13); cout << "---------";
	gotoxy(WIN_WIDTH + 2, 14); cout << "A - Lewo";
	gotoxy(WIN_WIDTH + 2, 15); cout << "D - Prawo";
	gotoxy(WIN_WIDTH + 2, 16); cout << "E - Wyjscie";

	gotoxy(20, 5); cout << "Nacisnij przycisk aby zaczac";
	_getch();
	gotoxy(20, 5); cout << "                            ";

	while (1) {
		if (_kbhit()) {
			char p = _getch();					//zmienna pomocnicza p
			if (p == 'a' || p == 'A') {
				//Ruch w lewo
				if (pozycja_auta > 18)
					pozycja_auta -= 4;
			}
			if (p == 'd' || p == 'D') {
				//Ruch w lewo
				if (pozycja_auta < 50)
					pozycja_auta += 4;
			}
			if (p == 'e' || p == 'E') {
				//Wyjdz
				menu();
				break;
			}
			if (p == 27) {
				break;
			}
		}
		rysuj_auto();
		rysuj_wroga(0);
		rysuj_wroga(1);
		rysuj_wroga(2);
		if (kolizja() == 1) {
			koniec_gry();
			return;
		}
		Sleep(50);
		usun_auto();
		usun_wroga(0);
		usun_wroga(1);
		usun_wroga(2);

		if (wrogY[0] == 10)
			if (wrog_flaga[1] == 0)
				wrog_flaga[1] = 1;
		if (wrogY[1] == 10)
			if (wrog_flaga[2] == 0)
				wrog_flaga[2] = 1;
		//predkosc wrogow
		if (wrog_flaga[0] == 1)
			wrogY[0] += 3;
		if (wrog_flaga[1] == 1)
			wrogY[1] += 3;
		if (wrog_flaga[2] == 1)
			wrogY[2] += 3;

		if (wrogY[0] > SCREEN_HEIGHT - 4) {
			resetuj_wroga(0);
			wynik++;
			aktualizuj_wynik();
		}

		if (wrogY[1] > SCREEN_HEIGHT - 4) {
			resetuj_wroga(1);
			wynik++;
			aktualizuj_wynik();
		}

		if (wrogY[2] > SCREEN_HEIGHT - 4) {
			resetuj_wroga(2);
			wynik++;
			aktualizuj_wynik();
		}

		if (wynik == 25) {
			gotoxy(WIN_WIDTH + 7, 7); cout << "wow" << endl;
		}
		if (wynik == 30) {
			gotoxy(WIN_WIDTH + 7, 7); cout << "    " << endl;
		}

		if (wynik == 35) {
			gotoxy(WIN_WIDTH + 4, 7); cout << "przyznaj sie" << endl;
			gotoxy(WIN_WIDTH + 4, 8); cout << "ze oszukujesz" << endl;
		}

		if (wynik == 40) {
			gotoxy(WIN_WIDTH + 4, 7); cout << "            " << endl;
			gotoxy(WIN_WIDTH + 4, 8); cout << "             " << endl;
		}

		if (wynik == 55) {
			gotoxy(WIN_WIDTH + 1, 7); cout << "albo jestes tak" << endl;
			gotoxy(WIN_WIDTH + 1, 8); cout << "dobry albo grzebales" << endl;
			gotoxy(WIN_WIDTH + 1, 9); cout << "w moim porgramie :/" << endl;
		}

		if (wynik == 70) {
			gotoxy(WIN_WIDTH + 1, 7); cout << "               " << endl;
			gotoxy(WIN_WIDTH + 1, 8); cout << "                   �" << endl;
			gotoxy(WIN_WIDTH + 1, 9); cout << "                   " << endl;
		}
	}
}