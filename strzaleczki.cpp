#include "procedurki.h"
#include <GL/freeglut.h>

using namespace std;

void strzalki(int key, int x, int y) {
	if (pauza == 0){
		if (klawisz_spacja == false){
			switch (kloc)
			{
			case 1:
			{
					  if (key == GLUT_KEY_RIGHT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 8] == 1 || macierz[(int)-igrek + 8][(int)iks + 8] == 1){
							 /* printf("RIGHT\nigrek = %d\niks = %d\n", igrek, iks);
							  printf("1 = %d\n", macierz[(int)-igrek + 8][(int)iks + 8]);
							  printf("2 = %d\n\n", macierz[(int)-igrek + 9][(int)iks + 8]);*/
						  }
						  if (macierz[(int)-igrek + 9][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0){
							  iks += rozmiar;
						  }
					  }
					  if (key == GLUT_KEY_LEFT){
						  klawisz = true;
						 /* printf("LEFT\nigrek = %d\niks = %d\n", igrek, iks);
						  printf("1 = %d\n", macierz[(int)-igrek + 8][(int)iks + 5]);
						  printf("2 = %d\n\n", macierz[(int)-igrek + 9][(int)iks + 5]);*/
						  if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0)
							  iks -= rozmiar;
					  }
					  if (key == GLUT_KEY_DOWN){
						  klawisz = true;

						  // cout << "klawisz = " << klawisz << endl;
						  if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9 + 1][(int)iks + 7])
						  {
							  igrek -= rozmiar;
							  Wynik.points++;
						  }
					  }


					  break; }
			case 2:
			{
					  if (key == GLUT_KEY_UP){
						  klawisz = true;

						  if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 9][(int)iks + 8] == 1 && macierz[(int)-igrek + 8][(int)iks + 5] == 0)
						  {
							  iks -= rozmiar;
							  kloc = 22;
						  }
						  else if (macierz[(int)-igrek + 9][(int)iks + 7] == 1 && macierz[(int)-igrek + 8][(int)iks + 8] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0)
						  {
							  igrek += rozmiar;
							  kloc = 22;
						  }
						  else if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 9][(int)iks + 8] == 0)
							  kloc = 22;
						  else if (macierz[(int)-igrek + 6][(int)iks + 5] == 0 && macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 10][(int)iks + 6] == 1 && macierz[(int)-igrek + 9][(int)iks + 7] == 1)
						  {
							  igrek += 2 * rozmiar;
							  iks -= rozmiar;
							  kloc = 22;
						  }
					  }
					  if (key == GLUT_KEY_RIGHT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0 && macierz[(int)-igrek + 7][(int)iks + 8] == 0)
							  iks += rozmiar;
					  }
					  if (key == GLUT_KEY_LEFT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0)
							  iks -= rozmiar;
					  }
					  if (key == GLUT_KEY_DOWN)
					  if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7])
					  {
						  igrek -= rozmiar;
						  Wynik.points++;
					  }


					  break; }
			case 22:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 7][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 1)
							   iks += rozmiar;
						   if (macierz[(int)-igrek + 10][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 1)
							   igrek -= rozmiar;
						   kloc = 2;
					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 9] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   if (!macierz[(int)-igrek + 9 + 1][(int)iks + 7] && !macierz[(int)-igrek + 9 + 1][(int)iks + 8] && !macierz[(int)-igrek + 9][(int)iks + 6])
					   {
						   Wynik.points++;
						   igrek -= rozmiar;
					   }

					   break; }

			case 3:
			{
					  if (key == GLUT_KEY_UP){
						  klawisz = true;

						  if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 4] == 1 && macierz[(int)-igrek + 8][(int)iks + 7] == 0)
						  {
							  iks += rozmiar;
							  kloc = 32;
						  }
						  else if (macierz[(int)-igrek + 9][(int)iks + 5] == 1 && macierz[(int)-igrek + 8][(int)iks + 4] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0)
						  {
							  igrek += rozmiar;
							  kloc = 32;
						  }
						  else if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 4] == 0)
							  kloc = 32;
						  else if (macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 6][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 10][(int)iks + 6] == 1 && macierz[(int)-igrek + 9][(int)iks + 5] == 1)
						  {
							  igrek += 2 * rozmiar;
							  iks += rozmiar;
							  kloc = 32;
						  }
					  }
					  if (key == GLUT_KEY_RIGHT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0)
							  iks += rozmiar;
					  }
					  if (key == GLUT_KEY_LEFT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0 && macierz[(int)-igrek + 7][(int)iks + 4] == 0)
							  iks -= rozmiar;
					  }
					  if (key == GLUT_KEY_DOWN)
					  if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5])
					  {
						  Wynik.points++;
						  igrek -= rozmiar;
					  }

					  break; }

			case 32:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 8][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 1)
							   iks += rozmiar;
						   if (macierz[(int)-igrek + 10][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 1)
							   igrek -= rozmiar;
						   kloc = 3;
					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 3] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   if (!macierz[(int)-igrek + 9 + 1][(int)iks + 5] && !macierz[(int)-igrek + 9 + 1][(int)iks + 4] && !macierz[(int)-igrek + 9][(int)iks + 6])
					   {
						   igrek -= rozmiar;
						   Wynik.points++;
					   }

					   break; }
			case 4:
			{
					  if (key == GLUT_KEY_UP){
						  klawisz = true;

						  if (macierz[(int)-igrek + 8][(int)iks + 5] == 1 && macierz[(int)-igrek + 8][(int)iks + 9] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
						  {
							  iks += rozmiar;
							  kloc = 42;
						  }
						  else if (macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
							  kloc = 42;
						  else if ((macierz[(int)-igrek + 8][(int)iks + 5] == 1 || macierz[(int)-igrek + 8][(int)iks + 8] == 1 || macierz[(int)-igrek + 8][(int)iks + 7] == 1) && macierz[(int)-igrek + 7][(int)iks + 8] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 0)
						  {
							  igrek += rozmiar;
							  kloc = 42;
						  }
					  }
					  if (key == GLUT_KEY_RIGHT){
						  klawisz = true;
						  printf("igrek = %d", igrek);
						  if (macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 9][(int)iks + 7] == 0 /*&& iks == 3*/ && igrek >= 7)
							  iks += rozmiar;
						  else if (macierz[(int)-igrek + 6][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 9][(int)iks + 7] == 0)
							  iks += rozmiar;
					  }
					  if (key == GLUT_KEY_LEFT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 0 && igrek >= 7)
							  iks -= rozmiar;
						  else if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 0 && macierz[(int)-igrek + 6][(int)iks + 5] == 0)
							  iks -= rozmiar;
					  }
					  if (key == GLUT_KEY_DOWN)
					  if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6])
					  {
						  igrek -= rozmiar;
						  Wynik.points++;
					  }
					  
					  break; }
			case 42:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if ((( macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0) || igrek >= 7) && macierz[(int)-igrek + 9][(int)iks + 6] == 0)
							   kloc = 4;
						   else if (macierz[(int)-igrek + 5][(int)iks + 6] == 0 && macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 1)
						   {
							   igrek += rozmiar;
							   kloc = 4;
						   }
					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 8][(int)iks + 9] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 8][(int)iks + 4] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7] && !macierz[(int)-igrek + 9][(int)iks + 8])
						   {
							   igrek -= rozmiar;
							   Wynik.points++;
						   }
					   }


					   break;
			}
			case 5:
			{
					  if (key == GLUT_KEY_UP){
						  klawisz = true;

						  if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0)
							  kloc = 51;
						  else if (macierz[(int)-igrek + 7][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 7] == 1 && macierz[(int)-igrek + 8][(int)iks + 7] == 0)
						  {
							  igrek += rozmiar;
							  kloc = 51;
						  }
						  else if (macierz[(int)-igrek + 8][(int)iks + 4] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 1)
						  {
							  iks -= rozmiar;
							  kloc = 51;
						  }
						  else if (macierz[(int)-igrek + 8][(int)iks + 5] == 1 && macierz[(int)-igrek + 7][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
						  {
							  igrek += rozmiar;
							  iks += rozmiar;
							  kloc = 51;
						  }
					  }

					  if (key == GLUT_KEY_RIGHT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 8] == 0)
							  iks += rozmiar;
					  }
					  if (key == GLUT_KEY_LEFT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 0)
							  iks -= rozmiar;
					  }
					  if (key == GLUT_KEY_DOWN)
					  {
						  klawisz = true;
						  if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 8][(int)iks + 7])
						  {
							  igrek -= rozmiar;
							  Wynik.points++;
						  }

					  }

					  break; }

			case 51:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 0)
							   kloc = 52;
						   else if (macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 1)
						   {
							   igrek += rozmiar;
							   kloc = 52;
						   }
						   else if (macierz[(int)-igrek + 7][(int)iks + 7] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 1)
						   {
							   iks += rozmiar;
							   kloc = 52;
						   }
					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 10][(int)iks + 7])
						   {
							   igrek -= rozmiar;
							   Wynik.points++;
						   }
					   }
					   break; }
			case 52:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 7][(int)iks + 5])
							   kloc = 53;
						   else if (macierz[(int)-igrek + 8][(int)iks + 5] == 1 && macierz[(int)-igrek + 8][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0)
						   {
							   iks += rozmiar;
							   kloc = 53;
						   }
						   else if (macierz[(int)-igrek + 7][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 7] == 0)
						   {
							   igrek -= rozmiar;
							   kloc = 53;
						   }
						   else if (macierz[(int)-igrek + 7][(int)iks + 4] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 1)
						   {
							   iks -= rozmiar;
							   kloc = 53;
						   }

					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 4] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 10][(int)iks + 5] && !macierz[(int)-igrek + 10][(int)iks + 6])
						   {
							   igrek -= rozmiar;
							   Wynik.points++;
						   }
					   }

					   break; }
			case 53:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 0)
							   kloc = 5;
						   else if (macierz[(int)-igrek + 7][(int)iks + 7] == 1 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 0)
						   {
							   iks -= rozmiar;
							   kloc = 5;
						   }
						   else if (macierz[(int)-igrek + 7][(int)iks + 6] == 1 && macierz[(int)-igrek + 10][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 0)
						   {
							   iks -= rozmiar;
							   igrek -= rozmiar;
							   kloc = 5;
						   }
						   else if (macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 6][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 1)
						   {
							   igrek += rozmiar;
							   kloc = 5;
						   }

					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 8][(int)iks + 8] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 7][(int)iks + 4] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {

						   klawisz = true;
						   if (!macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7] && !macierz[(int)-igrek + 9][(int)iks + 8])
						   {
							   igrek -= rozmiar;
							   Wynik.points++;
						   }
					   }
					   break; }

			case 6:
			{
					  if (key == GLUT_KEY_UP){
						  klawisz = true;

						  if (macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 0)
							  kloc = 61;
						  else if ((macierz[(int)-igrek + 8][(int)iks + 7] == 1 || macierz[(int)-igrek + 7][(int)iks + 7] == 1) && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0)
						  {
							  iks -= rozmiar;
							  kloc = 61;
						  }
						  else if (macierz[(int)-igrek + 9][(int)iks + 4] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 0 && (macierz[(int)-igrek + 8][(int)iks + 5] == 1 || macierz[(int)-igrek + 8][(int)iks + 4] == 1))
						  {
							  igrek -= rozmiar;
							  iks -= rozmiar;
							  kloc = 61;
						  }
					  }
					  if (key == GLUT_KEY_RIGHT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 0)
							  iks += rozmiar;
					  }
					  if (key == GLUT_KEY_LEFT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 7][(int)iks + 4] == 0)
							  iks -= rozmiar;
					  }
					  if (key == GLUT_KEY_DOWN)
					  {
						  klawisz = true;
						  if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 8][(int)iks + 5])
						  {
							  igrek -= rozmiar;
							  Wynik.points++;
						  }
					  }

					  break; }

			case 61:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 7] == 0)
							   kloc = 62;
						   else if (macierz[(int)-igrek + 6][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 1)
						   {
							   iks += rozmiar;
							   kloc = 62;
						   }
						   else if (macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && (macierz[(int)-igrek + 9][(int)iks + 6] == 1 || macierz[(int)-igrek + 9][(int)iks + 7] == 1))
						   {
							   igrek += rozmiar;
							   kloc = 62;
						   }
					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 8] == 0 && macierz[(int)-igrek + 7][(int)iks + 8] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {

						   klawisz = true;
						   if (!macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7])
						   {
							   Wynik.points++;
							   igrek -= rozmiar;
						   }
					   }
					   break; }
			case 62:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if ((macierz[(int)-igrek + 9][(int)iks + 5] == 0) && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0)
							   kloc = 63;
						   else if (macierz[(int)-igrek + 7][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 1)
						   {
							   igrek += rozmiar;
							   kloc = 63;
						   }
						   else if ((macierz[(int)-igrek + 8][(int)iks + 5] == 1 || macierz[(int)-igrek + 9][(int)iks + 5] == 1) && macierz[(int)-igrek + 8][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0)
						   {
							   iks += rozmiar;
							   kloc = 63;
						   }
						   else if (macierz[(int)-igrek + 7][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 1 && macierz[(int)-igrek + 7][(int)iks + 7] == 0)
						   {
							   iks += rozmiar;
							   igrek += rozmiar;
							   kloc = 63;
						   }
					   }

					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 8] == 0 && macierz[(int)-igrek + 8][(int)iks + 7] == 0 && macierz[(int)-igrek + 7][(int)iks + 7] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 5] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 10][(int)iks + 6] && !macierz[(int)-igrek + 10][(int)iks + 7])
						   {
							   Wynik.points++;
							   igrek -= rozmiar;
						   }
					   }

					   break; }
			case 63:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 5] == 0)
							   kloc = 6;
						   else if (macierz[(int)-igrek + 6][(int)iks + 5] == 0 && macierz[(int)-igrek + 6][(int)iks + 6] == 0 && macierz[(int)-igrek + 7][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 1)
						   {
							   igrek += rozmiar;
							   kloc = 6;
						   }
						   else if (macierz[(int)-igrek + 10][(int)iks + 6] == 0 && macierz[(int)-igrek + 9][(int)iks + 6] == 0 && (macierz[(int)-igrek + 7][(int)iks + 5] == 1 || macierz[(int)-igrek + 7][(int)iks + 6] == 1))
						   {
							   igrek -= rozmiar;
							   kloc = 6;
						   }
					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 6] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 8][(int)iks + 4] == 0 && macierz[(int)-igrek + 9][(int)iks + 4] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7] && !macierz[(int)-igrek + 10][(int)iks + 5])
						   {
							   Wynik.points++;
							   igrek -= rozmiar;
						   }
					   }


					   break; }
			case 7:
			{
					  if (key == GLUT_KEY_UP){
						  klawisz = true;
						  if (macierz[(int)-igrek + 7][(int)iks + 6] == 0 || igrek == 7)
							  kloc = 71;
					  }

					  if (key == GLUT_KEY_RIGHT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
							  iks += rozmiar;
					  }
					  if (key == GLUT_KEY_LEFT){
						  klawisz = true;
						  if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0)
							  iks -= rozmiar;
					  }
					  if (key == GLUT_KEY_DOWN)
					  {

						  klawisz = true;
						  if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 7])
						  {
							  Wynik.points++;
							  igrek -= rozmiar;
						  }
					  }

					  break; }

			case 71:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;

						   if (macierz[(int)-igrek + 8][(int)iks + 7] == 0)
							   kloc = 72;
						   else if (macierz[(int)-igrek + 9][(int)iks + 4] == 0 && macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 1 && macierz[(int)-igrek + 8][(int)iks + 7] == 1)
						   {
							   iks -= rozmiar;
							   igrek -= rozmiar;
							   kloc = 72;
						   }
					   }
					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && (macierz[(int)-igrek + 7][(int)iks + 7] == 0 || igrek == 7) && macierz[(int)-igrek + 8][(int)iks + 7] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if ((macierz[(int)-igrek + 7][(int)iks + 5] == 0 || igrek == 7) && macierz[(int)-igrek + 9][(int)iks + 5] == 0 && macierz[(int)-igrek + 8][(int)iks + 4] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5])
						   {
							   Wynik.points++;
							   igrek -= rozmiar;
						   }
					   }

					   break; }


			case 72:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 6] == 0)
							   kloc = 73;
					   }

					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 8][(int)iks + 8] == 0 && (macierz[(int)-igrek + 7][(int)iks + 7] == 0 || igrek == 7))
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 8][(int)iks + 4] == 0 && (macierz[(int)-igrek + 7][(int)iks + 5] == 0 || igrek == 7))
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 9][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 5] && !macierz[(int)-igrek + 9][(int)iks + 7])
						   {
							   Wynik.points++;
							   igrek -= rozmiar;
						   }
					   }

					   break; }


			case 73:
			{
					   if (key == GLUT_KEY_UP){
						   klawisz = true;
						   if (macierz[(int)-igrek + 8][(int)iks + 5] == 0)
							   kloc = 7;
					   }

					   if (key == GLUT_KEY_RIGHT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 7] == 0 && (macierz[(int)-igrek + 7][(int)iks + 7] == 0 || igrek == 7) && macierz[(int)-igrek + 8][(int)iks + 8] == 0)
							   iks += rozmiar;
					   }
					   if (key == GLUT_KEY_LEFT){
						   klawisz = true;
						   if (macierz[(int)-igrek + 9][(int)iks + 5] == 0 && (macierz[(int)-igrek + 7][(int)iks + 5] == 0 || igrek == 7) && macierz[(int)-igrek + 8][(int)iks + 5] == 0)
							   iks -= rozmiar;
					   }
					   if (key == GLUT_KEY_DOWN)
					   {
						   klawisz = true;
						   if (!macierz[(int)-igrek + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek + 9][(int)iks + 7])
						   {
							   Wynik.points++;
							   igrek -= rozmiar;
						   }
					   }
					   break; }
			}
		}

	}
}
