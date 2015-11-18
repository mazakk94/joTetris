#include <string>
#include <GL/freeglut.h>

using namespace std;

#ifndef procedurki

//#define procedurki

#define rozmiar  1 

struct Wspolrzedne
{
	double x;
	double y;
};

struct Kwadrat
{
	Wspolrzedne a_pg; //prawy gorny
	Wspolrzedne b_lg; //lewy gorny 
	Wspolrzedne c_ld; //lewy dolny 
	Wspolrzedne d_pd; //prawy dolny
};

extern Kwadrat Square;
extern int iks;
extern int igrek;
extern int igrek2;
extern short kloc;
extern short hold;
extern short nastepny;
extern bool klawisz;
extern bool macierz[25][12];
extern bool klawisz_spacja;


struct Info
{
	int level;
	long long points;
	int lines;
};
extern Info Wynik;
extern bool spadl;
extern short ile_linii;
extern bool mozna;
extern short tajmer;
extern int value;
extern bool zero;
extern bool pauza;
extern bool menu;
extern bool _spadnienty;

string IntToStr(int n);

void rysuj(double x, double y);
void rysuj_kontur(Kwadrat square, double move_x, double move_y);
void Tekst(const char *text, int length, int x, int y);
void kolor(int klocek);
void rysuj_kwadrat(Kwadrat square, double move_x, double move_y, short n);
void rysuj_holda();
void losujkloca();
void rysuj_nastepnego();
void sciana(double zmienna);
void ramka(double przesuniecie_y, int dlugosc, int iks);
void rysuj_ziemie();
void Print(string napis, short x, short y, GLfloat a, GLfloat b, GLfloat c);
void aktualizuj();
void displej();
void strzalki(int key, int x, int y);
void spadanie(int X);
void spadnienty(int X);
void keyb(unsigned char key, int x, int y);
void displej_pauza();
void displej_menu();
void displej_przegrana();
void bubblez_ros(int a[]);

	void kwadrat(double xx, double yy, double y2);
	void prawoskretny(double xx, double yy, double y2);
	void prawoskretny2(double xx, double yy, double y2);
	void lewoskretny(double xx, double yy, double y2);
	void lewoskretny2(double xx, double yy, double y2);
	void dlugas(double xx, double yy, double y2);
	void dlugas2(double xx, double yy, double y2);
	void trzyprawy(double xx, double yy, double y2);
	void trzyprawy1(double xx, double yy, double y2);
	void trzyprawy2(double xx, double yy, double y2);
	void trzyprawy3(double xx, double yy, double y2);
	void trzylewy(double xx, double yy, double y2);
	void trzylewy1(double xx, double yy, double y2);
	void trzylewy2(double xx, double yy, double y2);
	void trzylewy3(double xx, double yy, double y2);
	void uniwersal(double xx, double yy, double y2);
	void uniwersal1(double xx, double yy, double y2);
	void uniwersal2(double xx, double yy, double y2);
	void uniwersal3(double xx, double yy, double y2);

#endif