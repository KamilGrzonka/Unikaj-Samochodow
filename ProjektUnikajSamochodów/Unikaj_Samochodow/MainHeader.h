#pragma once
#ifndef MAINHEADER_H
#define MAINHEADER_H

#include <iostream>
#include<conio.h>
#include<dos.h>
#include <windows.h>
#include<time.h>

using namespace std;


#define SCREEN_WIDTH 90		
#define SCREEN_HEIGHT 26			
#define WIN_WIDTH 70
/**@param Auto dwuwymiarowa tablica odpowiedzialna za wyglad naszego samochodu*/
static const char Auto[4][4] = { ' ', '^', '^', ' ',
									'[', '*', '*', ']',
									' ', '*', '*', ' ',
									'[', '*', '*', ']', };
/**@param wrogY sluzy do okreslania pozycji wroga wzgledem osi y*/
static int wrogY[5];
/**@param wrogX sluzy do okreslania pozycji wroga wzgledem osi x*/
static int wrogX[5];
/**@param wrog_flaga sluzy do sprawnego zarzadzania przeciwnikami*/
static int wrog_flaga[3];

/**Funkcja gotoxy sluzy do przemieszczania sie po ekranie przy uzyciu wspolrzednych
@param x przypisujemy tej zmiennej wartosc pozycji kursora w osi x
@param y przypisujemy tej zmiennej wartosc pozycji kursora w osi y*/
void gotoxy(int x, int y);


/**Klasa dane sluzy do przechowywania paru danych uzywanych przez inne klasy, z tej funkcji dziedzicza wszystkie poziomy trudniosci
@param pozycja_auta pozycja poczatkowa naszego pojazdu
@param wynik poczatkowa wartosc naszego wyniku*/
class dane {
public:
	int pozycja_auta = WIN_WIDTH / 2;
	int wynik = 0;
};
/**Klasa glowne_funkcje zawiera w sobie wszystkie podstawowe funkcje i metody niezbedne do funkcjonowania interfejs jak i samej gry*/
class glowne_funkcje {
public:
	/**Funkcja tryby jest odpowiedzialna za wyswietlenie menu wyboru poziomu trudnosci i za przekierowanie nas do wybranego trybu*/
	void tryby();
	/**Funkcja instrukcja jest odpowiedzialna za wyswietlenie instrukcji*/
	void instrukcja();
	/**Funkcja ustaw_kursor jest odpowiedzialna za ustawienie kursora*/
	void ustaw_kursor(bool widoczny, DWORD rozmiar);
	/**Funkcja koniec_gry jest odpowiedzialna za wyswietlenie ekranu konca gry*/
	void koniec_gry();
	/**Funkcja menu jest odpowiedzialna za wyswietlenie menu*/
	void menu();
	
};


class baza {
public:
	/*static void rysuj_wroga(int ind);
	static void usun_wroga(int ind);
	static void resetuj_wroga(int ind);										//smieci, nie patrzec
	static void rysuj_granice();
	static int kolizja();
	static void rysuj_auto();
	static void usun_auto();
	static void generuj_wroga(int ind);
	static void aktualizuj_wynik();*/

};
/**Klasa poziom_latwy przechowuje w sobie wszystkie funckje zwi¹zane z poprawnym dzialaniem poziomu latwego. Klasa ta dziedziczy zarowno z klasy dane jak i z klasy glowne_funkcje */
class poziom_latwy : dane
,public glowne_funkcje{
	public:
		/**Funckja latwy jest odpowiedzialna za wywolywanie wczesniej zdefiniowanych funkcji w celu poprawnego dzialania programu*/
		void latwy();
		/**Funkcja rysuj_wroga jest odpowiedzlna za wygenerowanie nadciagajacych przeciwnikow*/
		void rysuj_wroga(int ind);
		/**Funkcja usun_wroga jest odpowiedzlna za usuwanie wczesniej narasowanych wrogow, bez tej funkcji zamiast przemieszczjacych sie samochodow otrzymalibysmy dlugie sznury aut, ktore z czasem zamazalyby caly ekran*/
		void usun_wroga(int ind);
		/**Funkcja resetuj wroga jest odpowiedzialna za zresetowanie wroga, to znaczy przeniesienie go na poczatek trasy jesli ten juz dojechal do konca*/
		void resetuj_wroga(int ind);
		/**Funkcja rysuj granice jest odpowiedzialna za narysowanie granicy wyznaczajacej pole gry*/
		void rysuj_granice();
		/**@param kolizja sluzy do okreslenia czy nastapila kolizja naszego samochodu z samochodem przeciwnika
		@return 1 kolizja nastapila, gra sie konczy
		@return 0 stan domyslny, kolizji nie ma, mozna grac dalej*/
		int kolizja();
		/**Funkcja rysuj_auto jest odpowiedzialna za wygenreowanie naszego samochodu*/
		void rysuj_auto();
		/**Funkcja usun_auto jest odpowiedzialna za usuniecie wczesniej wygenerowanego obrazu naszego samochodu, co jest niezbedne dla dzialania ruchu. Bez tego nasze auto zostawialoby slad, ktory wprowadzalby uzytkownika w blad*/
		void usun_auto();
		/**Funkcja generuj_wroga jest odpowiedzialna za wygenerowanie sie wroga w losowym miejscu osi x*/
		void generuj_wroga(int ind);
		/**Funkcja aktualizuj_wynik jest odpowiedzialna za aktualizowanie wyniku gracza*/
		void aktualizuj_wynik();  
		
};
/**Klasa poziom_sredni przechowuje w sobie wszystkie funckje zwi¹zane z poprawnym dzialaniem poziomu sredniego. Klasa ta dziedziczy zarowno z klasy dane jak i z klasy glowne_funkcje */
class poziom_sredni : dane
,public glowne_funkcje{
	public:
		/**Funckja sredni jest odpowiedzialna za wywolywanie wczesniej zdefiniowanych funkcji w celu poprawnego dzialania programu*/
		void sredni();
		void rysuj_wroga(int ind);
		void usun_wroga(int ind);
		void resetuj_wroga(int ind);
		void rysuj_granice();
		int kolizja();
		void rysuj_auto();
		void usun_auto();
		void generuj_wroga(int ind);
		void aktualizuj_wynik();

};
/**Klasa poziom_trudny przechowuje w sobie wszystkie funckje zwi¹zane z poprawnym dzialaniem poziomu trudnego. Klasa ta dziedziczy zarowno z klasy dane jak i z klasy glowne_funkcje */
class poziom_trudny : dane
,public glowne_funkcje{
	public:
		/**Funckja trudny jest odpowiedzialna za wywolywanie wczesniej zdefiniowanych funkcji w celu poprawnego dzialania programu*/
		void trudny();
		void rysuj_wroga(int ind);
		void usun_wroga(int ind);
		void resetuj_wroga(int ind);
		void rysuj_granice();
		int kolizja();
		void rysuj_auto();
		void usun_auto();
		void generuj_wroga(int ind);
		void aktualizuj_wynik();

};
/**Klasa poziom_bardzotrudny przechowuje w sobie wszystkie funckje zwi¹zane z poprawnym dzialaniem poziomu bardzo trudnego. Klasa ta dziedziczy zarowno z klasy dane jak i z klasy glowne_funkcje */
class poziom_bardzotrudny : dane
,public glowne_funkcje{
	public:
		/**Funckja trudny jest odpowiedzialna za wywolywanie wczesniej zdefiniowanych funkcji w celu poprawnego dzialania programu*/
		 void bardzotrudny();
		 void rysuj_wroga(int ind);
		 void usun_wroga(int ind);
		 void resetuj_wroga(int ind);
		 void rysuj_granice();
		 int kolizja();
		 void rysuj_auto();
		 void usun_auto();
		 void generuj_wroga(int ind);
		 void aktualizuj_wynik();

};
#endif 

