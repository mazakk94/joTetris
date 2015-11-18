#include "procedurki.h"
#include <GL/freeglut.h>


void keyb(unsigned char key, int x, int y)
{

	if (key == 27){ //ESC
		//zapisz_wynik;
		exit('0');
	}

	if (menu == 1)
	{
		if (key == 13) //ENTER
		{
			if (pauza == 1)
				pauza = 0;
			displej_menu();
			menu = 0;
		}

	}
	else
	{
	
		if (key == '0' && pauza == 0)
			if (mozna)
				zero = 1;
		if (key == 'p' || key == 'P'){
			if (pauza) pauza = false;
				else pauza = true;
			}
		if (key == ' ' && pauza == 0)
		{
			klawisz = true;
			klawisz_spacja = true;
			switch (kloc)
			{
			case 1:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9 + 1][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 2:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 22:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 7] && !macierz[(int)-igrek + 9 + 1][(int)iks + 8] && !macierz[(int)-igrek + 9][(int)iks + 6]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 3:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 32:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 5] && !macierz[(int)-igrek + 9 + 1][(int)iks + 4] && !macierz[(int)-igrek + 9][(int)iks + 6]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 4:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 42:
				while (!macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7] && !macierz[(int)-igrek + 9][(int)iks + 8]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 5:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 8][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 51:
				while (!macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 10][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 52:
				while (!macierz[(int)-igrek + 10][(int)iks + 5] && !macierz[(int)-igrek + 10][(int)iks + 6]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 53:
				while (!macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7] && !macierz[(int)-igrek + 9][(int)iks + 5]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 6:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 8][(int)iks + 5]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 61:
				while (!macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 62:
				while (!macierz[(int)-igrek + 10][(int)iks + 6] && !macierz[(int)-igrek + 10][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 63:
				while (!macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7] && !macierz[(int)-igrek + 10][(int)iks + 5]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 7:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 71:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 72:
				while (!macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			case 73:
				while (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7]){
					igrek -= rozmiar;
					Wynik.points += 2;
				}
				break;
			}
		}
	}
}