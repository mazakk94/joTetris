#include "procedurki.h"
#include <GL/freeglut.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

void rysuj(double x, double y)
{
	glVertex3d(x, y, -6);
}

void rysuj_kontur(Kwadrat square, double move_x, double move_y)
{
	glPushMatrix();
		glTranslated(1 + iks + move_x, 1 + igrek2 + move_y, -6);
		glBegin(GL_LINE_LOOP);
		glColor3d(0, 0, 0);
		rysuj(square.a_pg.x, square.a_pg.y);
		rysuj(square.b_lg.x, square.b_lg.y); 
		rysuj(square.c_ld.x, square.c_ld.y); 
		rysuj(square.d_pd.x, square.d_pd.y); 
		glEnd();
	glPopMatrix();
}

void Tekst(const char *text, int length, int x, int y)
{
	glMatrixMode(GL_PROJECTION);
	double * matrix = new double[16];
	glGetDoublev(GL_PROJECTION_MATRIX, matrix);
	glLoadIdentity();
	glOrtho(0, 800, 0, 600, -5, 5);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glPushMatrix();
		glLoadIdentity();
		glRasterPos2i(x, y);
		for (int i = 0; i < length; i++)
			//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, (int)text[i]);
	glPopMatrix();
	glMatrixMode(GL_PROJECTION);
	glLoadMatrixd(matrix);
	glMatrixMode(GL_MODELVIEW);
}

void kolor(int klocek){
	if (klocek == 1) // ŻÓŁTY
		glColor3d(1, 1, 0);
	else if (klocek == 2 || klocek == 22) //CZERWONY
		glColor3d(1, 0, 0);
	else if (klocek == 3 || klocek == 32) //ZIELONY
		glColor3d(0, 1, 0);
	else if (klocek == 4 || klocek == 42) //JASNONIEBIESKI 
		glColor3d(0, 1, 1);
	else if (klocek == 5 || klocek == 51 || klocek == 52 || klocek == 53) //NIEBIESKI
		glColor3d(0, 0, 1);
	else if (klocek == 6 || klocek == 61 || klocek == 62 || klocek == 63) //POMARANCZOWY
		glColor3d(1, 0.5, 0);
	else if (klocek == 7 || klocek == 71 || klocek == 72 || klocek == 73) //FIOLETOWY
		glColor3d(1, 0, 1);
}

void rysuj_kwadrat(Kwadrat square, double move_x, double move_y, short n)
{
	glPushMatrix();
		if (n == 0) glTranslated(1 + iks + move_x, 1 + igrek + move_y, -6);
		else glTranslated(move_x, move_y, -6);
		glBegin(GL_POLYGON);
		if (n == 2) kolor(hold);
		else if (n == 1) kolor(nastepny);
		else kolor(kloc);
		rysuj(square.a_pg.x, square.a_pg.y); // prawy gorny
		rysuj(square.b_lg.x, square.b_lg.y); //lewy gorny
		rysuj(square.c_ld.x, square.c_ld.y); // lewy dolny
		rysuj(square.d_pd.x, square.d_pd.y); // prawy dolny
		glEnd();
	glPopMatrix();
}

void rysuj_holda()
{
	switch (hold)
	{
	case 1:
		kwadrat(-19, 13, -40);
		break;
	case 2:
		prawoskretny(-19, 12, -40);
		break;
	case 3:
		lewoskretny(-17, 12, -40);
		break;
	case 42:
		dlugas(-18, 11, -40);
		break;
	case 4:
		dlugas(-18, 11, -40);
		break;
	case 5:
		trzyprawy(-19, 12, -40);
		break;
	case 6:
		trzylewy(-17, 12, -40);
		break;
	case 7:
		uniwersal(-18, 13, -40);
		break;

	}
}

void losujkloca()
{
	if (klawisz == true)
	{
		klawisz = false;
		igrek2 = igrek;
	}
	switch (kloc)
	{
	case 1:
		while (macierz[(int)-igrek2 + 10][(int)iks + 6] == 0 && macierz[(int)-igrek2 + 10][(int)iks + 7] == 0)
			igrek2 -= rozmiar;
		kwadrat(iks, igrek, igrek2);
		break;
	case 2:
		while (!macierz[(int)-igrek2 + 10][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 7])
			igrek2 -= rozmiar;
		prawoskretny(iks, igrek, igrek2);
		break;
	case 22:
		while (!macierz[(int)-igrek2 + 9][(int)iks + 6] && !macierz[(int)-igrek2 + 10][(int)iks + 8] && !macierz[(int)-igrek2 + 10][(int)iks + 7])
			igrek2 -= rozmiar;
		prawoskretny2(iks, igrek, igrek2);
		break;
	case 3:
		while (!macierz[(int)-igrek2 + 10][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 5])
			igrek2 -= rozmiar;
		lewoskretny(iks, igrek, igrek2);
		break;
	case 32:
		while (!macierz[(int)-igrek2 + 10][(int)iks + 5] && !macierz[(int)-igrek2 + 10][(int)iks + 4] && !macierz[(int)-igrek2 + 9][(int)iks + 6])
			igrek2 -= rozmiar;
		lewoskretny2(iks, igrek, igrek2);
		break;
	case 4:
		while (!macierz[(int)-igrek2 + 9 + 1][(int)iks + 6])
			igrek2 -= rozmiar;
		dlugas(iks, igrek, igrek2);
		break;
	case 42:
		while (!macierz[(int)-igrek2 + 9][(int)iks + 5] && !macierz[(int)-igrek2 + 9][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 7] && !macierz[(int)-igrek2 + 9][(int)iks + 8])
			igrek2 -= rozmiar;
		dlugas2(iks, igrek, igrek2);
		break;
	case 5:
		while (!macierz[(int)-igrek2 + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek2 + 8][(int)iks + 7])
			igrek2 -= rozmiar;

		trzyprawy(iks, igrek, igrek2);
		break;
	case 51:
		while (!macierz[(int)-igrek2 + 9][(int)iks + 5] && !macierz[(int)-igrek2 + 9][(int)iks + 6] && !macierz[(int)-igrek2 + 10][(int)iks + 7])
			igrek2 -= rozmiar;
		trzyprawy1(iks, igrek, igrek2);
		break;
	case 52:
		while (!macierz[(int)-igrek2 + 10][(int)iks + 5] && !macierz[(int)-igrek2 + 10][(int)iks + 6])
			igrek2 -= rozmiar;
		trzyprawy2(iks, igrek, igrek2);
		break;
	case 53:
		while (!macierz[(int)-igrek2 + 9][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 7] && !macierz[(int)-igrek2 + 9][(int)iks + 5])
			igrek2 -= rozmiar;
		trzyprawy3(iks, igrek, igrek2);
		break;
	case 6:
		while (!macierz[(int)-igrek2 + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek2 + 8][(int)iks + 5])
			igrek2 -= rozmiar;
		trzylewy(iks, igrek, igrek2);
		break;
	case 61:
		while (!macierz[(int)-igrek2 + 9][(int)iks + 5] && !macierz[(int)-igrek2 + 9][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 7])
			igrek2 -= rozmiar;
		trzylewy1(iks, igrek, igrek2);
		break;
	case 62:
		while (!macierz[(int)-igrek2 + 10][(int)iks + 6] && !macierz[(int)-igrek2 + 10][(int)iks + 7])
			igrek2 -= rozmiar;
		trzylewy2(iks, igrek, igrek2);
		break;
	case 63:
		while (!macierz[(int)-igrek2 + 9][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 7] && !macierz[(int)-igrek2 + 10][(int)iks + 5])
			igrek2 -= rozmiar;
		trzylewy3(iks, igrek, igrek2);
		break;
	case 7:
		while (!macierz[(int)-igrek2 + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 5] && !macierz[(int)-igrek2 + 9][(int)iks + 7])
			igrek2 -= rozmiar;
		uniwersal(iks, igrek, igrek2);
		break;
	case 71:
		while (!macierz[(int)-igrek2 + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 5])
			igrek2 -= rozmiar;
		uniwersal1(iks, igrek, igrek2);
		break;
	case 72:
		while (!macierz[(int)-igrek2 + 9][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 5] && !macierz[(int)-igrek2 + 9][(int)iks + 7])
			igrek2 -= rozmiar;
		uniwersal2(iks, igrek, igrek2);
		break;
	case 73:
		while (!macierz[(int)-igrek2 + 9 + 1][(int)iks + 6] && !macierz[(int)-igrek2 + 9][(int)iks + 7])
			igrek2 -= rozmiar;
		uniwersal3(iks, igrek, igrek2);
		break;
	}
}

void rysuj_nastepnego()
{
	int iks = 17;
	int igrek = -4;
	switch (nastepny)
	{
	case 1:
		kwadrat(iks, igrek + 1, -50);
		break;
	case 2:
		prawoskretny(iks, igrek, -50);
		break;
	case 3:
		lewoskretny(iks + 2, igrek, -50);
		break;
	case 4:
		dlugas(iks + 1, igrek - 1, -50);
		break;
	case 5:
		trzyprawy(iks, igrek, -50);
		break;
	case 6:
		trzylewy(iks + 2, igrek, -50);
		break;
	case 7:
		uniwersal(iks + 1, igrek + 1, -50);
		break;
	}
}

void sciana(double zmienna)
{
	glPushMatrix();
	glBegin(GL_POLYGON);
	glColor3d(0, 0, 0);
	rysuj(6 + zmienna, 10); //prawy gorny
	rysuj(5 + zmienna, 10); //lewy gorny
	rysuj(5 + zmienna, -14); // lewy dolny
	rysuj(6 + zmienna, -14); //prawy dolny
	glEnd();
	glPopMatrix();
}

void ramka(double przesuniecie_y, int dlugosc, int iks)
{
	glPushMatrix(); //RAMKI
	glBegin(GL_LINE_LOOP);
	glColor3d(0, 0, 0);
	rysuj(iks + 4, 10 - przesuniecie_y); //prawy gorny
	rysuj(iks, 10 - przesuniecie_y); //lewy gorny
	rysuj(iks, 10 - dlugosc - przesuniecie_y); // lewy dolny
	rysuj(iks + 4, 10 - dlugosc - przesuniecie_y); //prawy dolny
	glEnd();
	glPopMatrix();
}

void rysuj_ziemie()
{
	glPushMatrix();  //     ZIEMIA
	glBegin(GL_POLYGON);
	glColor3d(0, 0, 0);
	rysuj(6.0, -14); //prawy gorny	
	rysuj(-6, -14); //lewy gorny		
	rysuj(-6, -15); // lewy dolny
	rysuj(6.0, -15); // prawy dolny
	glEnd();
	glPopMatrix();
}

void Print(string napis, short x, short y, GLfloat a, GLfloat b, GLfloat c)
{
	glColor3f(a, b, c);
	Tekst(napis.data(), napis.size(), x, y);
}

void aktualizuj()
{
	for (int i = 1; i < 24; i++)
	for (int j = 1; j < 11; j++)
	if (macierz[i][j] == 1)
	{
		glPushMatrix();
		glBegin(GL_QUADS);
		glColor3d(0.5, 0.5, 0.5);
		rysuj(j + 1 - 6, -i + 9 + 1); //prawy gorny
		rysuj(j - 6, -i + 9 + 1); //lewy gorny
		rysuj(j - 6, -i + 9); // lewy dolny
		rysuj(j - 6 + 1, -i + 9); // prawy dolny
		glEnd();
		glPopMatrix();
	}
}

void displej()
{
	aktualizuj();
	sciana(0); //prawa
	rysuj_ziemie();
	sciana(-11); //lewa
	ramka(1, 1, 7); // (przesuniecie y, dlugosc y, iks(7 dla prawej, X dla lewej) )
	Print("POINTS", 595, 481, 1, 0.5, 0);
	Print(IntToStr(Wynik.points), 600, 463, 1, 0.5, 0);
	Print("HOLD", 130, 481, 1, 0, 0);
	Print("LEVEL", 600, 442, 0, 1, 0);
	Print(IntToStr(Wynik.level), 610, 424, 0, 1, 0);
	Print("LINES", 600, 381, 0, 0, 1);
	Print(IntToStr(Wynik.lines), 610, 363, 0, 0, 1);
	Print("NEXT", 610, 321, 1, 0, 1);

	ramka(1, 4, -11);
	ramka(3, 1, 7);
	ramka(6, 1, 7);
	ramka(9, 4, 7);

	losujkloca();
	rysuj_holda();
	rysuj_nastepnego();
}

void displej_pauza()
{

	Print("POINTS", 595, 481, 1, 0.5, 0);
	Print(IntToStr(Wynik.points), 600, 463, 1, 0.5, 0);
	Print("HOLD", 130, 481, 1, 0, 0);
	Print("LEVEL", 600, 442, 0, 1, 0);
	Print(IntToStr(Wynik.level), 610, 424, 0, 1, 0);
	Print("LINES", 600, 381, 0, 0, 1);
	Print(IntToStr(Wynik.lines), 610, 363, 0, 0, 1);
	Print("NEXT", 610, 321, 1, 0, 1);

	Print("GAME PAUSED", 310, 417, 1, 0, 0);
	Print("Control Keys:", 325, 387, 0, 0, 0);
	Print("Left arrow - Move left", 270, 367, 0, 1, 0);
	Print("Right arrow - Move right", 270, 347, 0, 1, 1);
	Print("Up arrow - Rotate", 270, 327, 1, 0.5, 0);
	Print("Down arrow - Soft drop &", 270, 307, 0, 0, 1);
	Print("+1 Points", 420, 287, 0, 0, 1);
	Print("Space - Hard drop &", 270, 267, 1, 0, 0);
	Print("+2 Points for each tile", 300, 247, 1, 0, 0);
	Print("P - Return to game", 270, 227, 1, 0, 1);
	Print("Esc - Quit game", 270, 207, 1, 0.7, 0);
	sciana(0); //prawa
	rysuj_ziemie();
	sciana(-11); //lewa

	ramka(1, 1, 7); // (przesuniecie y, dlugosc y, iks(7 dla prawej, X dla lewej) )
	ramka(1, 4, -11);
	ramka(3, 1, 7);
	ramka(6, 1, 7);
	ramka(9, 4, 7);

	rysuj_holda();
	rysuj_nastepnego();
}

void displej_menu()
{
	sciana(0); //prawa
	rysuj_ziemie();
	sciana(-11); //lewa

	Print("POINTS", 595, 481, 1, 0.5, 0);
	Print(IntToStr(Wynik.points), 600, 463, 1, 0.5, 0);
	Print("HOLD", 130, 481, 1, 0, 0);
	Print("LEVEL", 600, 442, 0, 1, 0);
	Print(IntToStr(Wynik.level), 610, 424, 0, 1, 0);
	Print("LINES", 600, 381, 0, 0, 1);
	Print(IntToStr(Wynik.lines), 610, 363, 0, 0, 1);
	Print("NEXT", 610, 321, 1, 0, 1);

	ramka(1, 1, 7); // (przesuniecie y, dlugosc y, iks(7 dla prawej, X dla lewej) )
	ramka(1, 4, -11);
	ramka(3, 1, 7);
	ramka(6, 1, 7);
	ramka(9, 4, 7);
	Print("TO START", 270, 450, 1, 0.5, 0);
	Print("jo", 395, 450, 1, 0, 0);
	Print("Tetris", 408, 450, 1, 0, 0);
	Print("PRESS [ENTER]", 270, 430, 1, 0.5, 0);
	Print("Highscores:", 80, 320, 0, 0, 1);

	Print("Control Keys:", 325, 387, 0, 0, 0);
	Print("Left arrow - Move left", 270, 367, 0, 1, 0);
	Print("Right arrow - Move right", 270, 347, 0, 1, 1);
	Print("Up arrow - Rotate", 270, 327, 1, 0.5, 0);
	Print("Down arrow - Soft drop &", 270, 307, 0, 0, 1);
	Print("+1 Points", 420, 287, 0, 0, 1);
	Print("Space - Hard drop &", 270, 267, 1, 0, 0);
	Print("+2 Points for each tile", 300, 247, 1, 0, 0);
	Print("P - Return to game", 270, 227, 1, 0, 1);
	Print("Esc - Quit game", 270, 207, 1, 0.7, 0);
}

void displej_przegrana()
{
	sciana(0); //prawa
	rysuj_ziemie();
	sciana(-11); //lewa

	Print("POINTS", 595, 481, 1, 0.5, 0);
	Print(IntToStr(Wynik.points), 600, 463, 1, 0.5, 0);
	Print("HOLD", 130, 481, 1, 0, 0);
	Print("LEVEL", 600, 442, 0, 1, 0);
	Print(IntToStr(Wynik.level), 610, 424, 0, 1, 0);
	Print("LINES", 600, 381, 0, 0, 1);
	Print(IntToStr(Wynik.lines), 610, 363, 0, 0, 1);
	Print("NEXT", 610, 321, 1, 0, 1);

	ramka(1, 1, 7); // (przesuniecie y, dlugosc y, iks(7 dla prawej, X dla lewej) )
	ramka(1, 4, -11);
	ramka(3, 1, 7);
	ramka(6, 1, 7);
	ramka(9, 4, 7);
	Print("PRZEGRALES !", 300, 427, 1, 0.5, 0);
	Print("Twoj wynik to: ", 300, 407, 1, 0.5, 0);
	Print("Aby wyjsc z gry", 300, 347, 1, 0.3, 0);
	Print("nacisnij [ESC]", 300, 327, 1, 0.5, 0);
	Print(IntToStr(Wynik.points), 300, 387, 1, 0.5, 0);
}

void bubblez_ros(int a[]) //sortuj rosnąco
{
	bool flaga;
	do
	{
		flaga = false;
		for (int i = 0; a[i + 1] != 0; i++)
		{
			if (a[i]<a[i + 1]){
				swap(a[i], a[i + 1]);
				flaga = true;
			}
		}
	} while (flaga);
}