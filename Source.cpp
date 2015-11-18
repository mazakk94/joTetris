#include <GL/freeglut.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include <stdexcept>
#include "procedurki.h"
#include <fstream>


using namespace std;

Info Wynik =
{
	0,
	0,
	0
};

int iks = -1;
int igrek = 5;
int igrek2 = 5;
bool pauza = 1;
bool menu = 1;
bool _spadnienty = 0;
Kwadrat Square =
{
	{
		1, //a.x
		1 //a.y
	},
	{
		-1, //b.x
		1 //b.y
	},
	{
		-1, //c.x
		-1 //c.y
	},
	{
		1, //d.x
		-1 // d.y
	}
};

short tajmer = 5;
bool lost = 0;
bool macierz[25][12] = { 0 };
float przesuniecie_x = 0;
float przesuniecie_y = 0;
int value = 200;
short int ile_linii = 0;

short kloc = 1;
short nastepny = 1;
short hold = 0;
bool spadl = 0;
bool zero = 0;
bool mozna = 1;
short i;

bool klawisz = true;
bool klawisz_spacja = false;
bool nowa = 0;
bool wczytane = 0;

string IntToStr(int n)
{
	ostringstream result;
	result << n;
	return result.str();
}


static void resize(int width, int height)
{
	const float ar = (float)width / (float)height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
//	glFrustum(-ar, ar, -1.0, 1.0, 0.5, 100.0);
	glFrustum(-ar, ar, -1.0, 1.0, 0.4, 100.0);
	//gora dol prawo lewo rozmiar

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

static void idle(void)
{
	glutPostRedisplay();
}


void czy_przegrana()
{ //    macierz[y][x]
	for (i = 5; i <= 6 ; i++)
	if (macierz[2][i] == 1){
		lost = 1;
		//printf("przegrales !");
	}
}
int tab[10] = { 0 };

int j = 0;
int hajskory = 1;
void wykonajOperacje(int liczba1)
{
	if (liczba1 != 0){
		Print(IntToStr(liczba1), 100, 300 - j, 0, 0, 0);
		tab[hajskory - 1] = liczba1;
		Print(IntToStr(hajskory), 70, 300 - j, 0, 0, 0);
		Print(":", 87, 300 - j, 0, 0, 0);
	}
}


bool wczytajPlik(string nazwaPliku)
{
	fstream plik;
	plik.open(nazwaPliku.c_str());
	if (!plik.good())
		return false;

	while (hajskory <= 10)
	{
		int a;
		plik >> a;
		if (plik.good()){
			wykonajOperacje(a);
			j += 20;
			hajskory++;
		}
		else
			break;
	}
	return true;
}







static void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_LIGHTING);
	// string napis, short x, short y, GLfloat a, GLfloat b, GLfloat c)

	//kloc = rand() % 7 + 1;
	if (menu == 1){
		if (wczytane == 0)
		{
			j = 0;
			hajskory = 1;
			displej_menu();
			if (!wczytajPlik("highscores.txt")){
					cout << "Nie udalo sie otworzyc pliku!" << endl;
			}
		}
	}
	else
	{
		czy_przegrana();
		if (pauza == 1 && lost == 0){
			displej_pauza();
		}
		else if (lost == 0)
			displej();
		else if (lost == 1){
			displej_przegrana();
			
			fstream plik("highscores.txt", ios::out | ios::trunc);
			if (plik)
			{
				tab[hajskory-1] = Wynik.points;
				bubblez_ros(tab);
				for (i = 0; tab[i] != 0; i++)
					plik << tab[i] << endl;
			}
			plik.close();
		}
	}

	glutSwapBuffers();
}






//void mysz(int button, int state, int x, int y)
//{
//
//	//cout << "button = " << button << "\t";
//	//cout << "state = " << state << "\t";
//	//cout << "x = " << x << "\t";
//	//cout << "y = " << y << "\t";
//
//	double xx = (x / 320.0 - 1.0) * 4.0;
//	double yy = (y / 240.0 - 1.0) * -3;
//	if (state == 0)
//	{
//		if (
//			(xx > iks - rozmiar)
//			&& (xx< iks + rozmiar)
//			&& (yy > igrek - rozmiar)
//			&& (yy < igrek + rozmiar)
//			)
//		{
//			punkt++;
//			cout << punkt << endl;
//			iks = (rand() % 640 / 320.0 - 1.0) * 4.0;
//			igrek = (rand() % 480 / 240.0 - 1.0) * -3;
//			value-=200;
//			if (value < 1)
//				value = 100;
//			//iks = (rand() % 640 / 320.0 - 1.0) * 4.0;
//			//igrek = (rand() % 480 / 240.0 - 1.0) * -3;
//
//		}
//		/*else
//			cout << "FALSE" << "\t";*/
//	}
//
//	//przesuniecie_x = xx;
//	//przesuniecie_y = yy;
//	//cout << "xx = " << xx << "\t";
//	//cout << "yy = " << yy << "\t";
//
//	//cout << "x_1 = " << iks << "\t";
//	//cout << "y_1 = " << igrek << "\t";
//
//
//	//losuje po wykonanym kliknieciu
//	//if (state == 0)
//	//{
//	//	iks = (rand() % 640 / 320.0 - 1.0) * 4.0;
//	//	igrek = (rand() % 480 / 240.0 - 1.0) * -3;
//	//}
////	cout << "x_2 = " << iks << "\t";
////	cout << "y_2 = " << igrek << endl << endl;
//
//
//}



int main(int argc, char *argv[])
{
	srand((unsigned)time(NULL));

	for (int i = 0; i < 25; i++)
	{
		macierz[i][0] = true;
		macierz[i][11] = true;
	}

	for (int i = 0; i < 12; i++)
	{
		macierz[24][i] = true;
	}

	


	for (int i = 0; i < 25; i++)
	{
		for (int j = 0; j < 12; j++)
		{
			cout << macierz[i][j] <<" ";
		}
		cout << endl;
	}


	kloc = 7;// rand() % 7 + 1;
	nastepny = rand() % 7 + 1;

	glutInitWindowSize(640, 640);
	glutInitWindowPosition(20, 20);
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH | GLUT_MULTISAMPLE);

	glutCreateWindow("OpenGLUT Shapes");




	glutReshapeFunc(resize);
	glutDisplayFunc(display);
	glutIdleFunc(idle);
	glutKeyboardFunc(keyb);
	glutSpecialFunc(strzalki);
	//glutMouseFunc(mysz);

	glutTimerFunc(value, spadanie, 0);

	glutSetOption(GLUT_ACTION_ON_WINDOW_CLOSE, GLUT_ACTION_CONTINUE_EXECUTION);

	glClearColor(1, 1, 1, 1);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glEnable(GL_COLOR_MATERIAL);

	glutMainLoop();

	return EXIT_SUCCESS;
}