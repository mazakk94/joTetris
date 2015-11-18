
#include <windows.h>         // Plik nag��wkowy Windows
#include <math.h>         // Plik nag��wkowy dla operacji matematycznych    ( NOWE )
#include <stdio.h>         // Plik nag��wkowy dla operacji wej�cia/wyj�cia    ( NOWE )
#include <stdarg.h>         // Nag��wek dla zmiennych argument�w funkcji    ( NOWE )
#include <gl\gl.h>         // Plik nag��wkowy biblioteki OpenGL
#include <gl\glu.h>         // Plik nag��wkowy biblioteki GLu32
#include <gl/GLAUX.H>         // Plik nag��wkowy biblioteki GLaux 
HDC        hDC = NULL;         // Kontekst urz�dzenia
HGLRC        hRC = NULL;         // Kontekst renderuj�cy
HWND        hWnd = NULL;         // Przechowuje uchwyt okna
HINSTANCE    hInstance;         // Przechowuje instancj� okna (ang. Instance)

GLuint    base;         // Base Display List For The Font Set
GLfloat    cnt1;         // Pierwszy licznik do poruszania i kolorowania tekstu
GLfloat    cnt2;         // Drugi licznik do poruszania i kolorowania tekstu 
bool    keys[256];         // Tablica u�ywana do obs�ugi klawiatury
bool    active = TRUE;         // Zmienna aktywno�ci okna ustawiona wst�pnie na TRUE
bool    fullscreen = TRUE;         // Tryb pe�noekranowy wst�pnie ustawiony na TRUE 
LRESULT    CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);         // Deklaracja WndProc (wi�cej w tekstach o WinApi)

GLvoid BuildFont(GLvoid)         // Buduje nasz� bitmapow� czcionk�
{
	HFONT    font;         // Identyfikator czicionki windowsowej
	HFONT    oldfont;         // U�yte dla Good House Keeping 
	base = glGenLists(96);         // Przechowuje 96 znak�w        ( NOWE )

	font = CreateFont(-24,         // Wysoko�� czcionki            ( NOWE )


		0,         // �rednia szeroko�� znaku

		0,         // K�t pochylenia
		0,         // K�t orientacji wzgl�dem linii bazowej

		FW_BOLD,         // Waga czcionki

		FALSE,         // Kursywa
		FALSE,         // Podkre�lenie
		TRUE,         // Pogrubienie

		ANSI_CHARSET,         // Identyfikator zbioru znak�w

		OUT_TT_PRECIS,         // Dok�adno�� prezentacji

		CLIP_DEFAULT_PRECIS,         // Dok�adno�� przyci�cia

		ANTIALIASED_QUALITY,         // Jako�� prezentacji

		FF_DONTCARE | DEFAULT_PITCH,         // Rodzina i podzia�ka czcionki

		"Courier New");         // Nazwa czcionki

	oldfont = (HFONT)SelectObject(hDC, font);         // Wybiera czcionk� jak� chcemy
	wglUseFontBitmaps(hDC, 32, 96, base);         // Buduje 96 znak�w zaczynaj�c od znaku 32
	SelectObject(hDC, oldfont);         // Wybiera czcionk� jak� chcemy
	DeleteObject(font);         // Kasuje czcionk�
}
//Nast�pny kod jest ca�kiem prosty.Kasujemy 96 list wy�wietlania zaczynaj�c od pierwszej, okre�lonej w base.Lepiej jest samemu to zrobi� ni� �udzi� si�, �e windows to zrobi za nas : ).

GLvoid KillFont(GLvoid)         // Kasuje listy czcionki
{
	glDeleteLists(base, 96);         // Kasuje wszystkie 96 znak�w        ( NOWE )
}

GLvoid glPrint(const char *fmt, ...)         // W�asna procedura GL "Print"
{

	char        text[256];         // Przechowuje stringa
	va_list        ap;         // Wska�nik do listy argument�w

	if (fmt == NULL)         // Je�eli nie ma tekstu
		return;         // nie robi nic

	va_start(ap, fmt);         // Przeszukje string w celu znalezienia zmiennych
	vsprintf_s(text, fmt, ap);         // Konwertuje symbole na aktualne numery
	va_end(ap);         // Rezultaty s� przechowywane w zmiennej text

	glPushAttrib(GL_LIST_BIT);         // Wrzucamy list� na stos        ( NOWE )
	glListBase(base - 32);         // Odejmuje pierwsze 32 znaki        ( NOWE )
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);         // Rysuje nasz tekst      ( NOWE )
	glPopAttrib();         // Zdejmuje ze stosu nasz� list�    ( NOWE )
}


int InitGL(GLvoid)         // Ustawienia OpenGL
{
	glShadeModel(GL_SMOOTH);         // W��cza wyg�adzane cieniowanie (ang. Smooth Shading)
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);         // Czarne t�o
	glClearDepth(1.0f);         // Ustawienia bufora g��bi
	glEnable(GL_DEPTH_TEST);         // W��cza testowanie g��bi
	glDepthFunc(GL_LEQUAL);         // Typ testowania g��bi
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);         // �adna perspektywa 
	BuildFont();         // Buduje czcionk� 
	return TRUE;         // Inicjalizacja posz�a OK
}

int DrawGLScene(GLvoid)         // Tutaj rysujemy
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Wyczy�� ekran i bufor g��bi
	glLoadIdentity();         // Zresetuj widok
	glTranslatef(0.0f, 0.0f, -1.0f);         // Przenosimy si� 1 jednostk� w ekran

	// Pulsuj�ce kolory w zale�no�ci od pozycji tekstu
	glColor3f(1.0f*float(cos(cnt1)), 1.0f*float(sin(cnt2)), 1.0f - 0.5f*float(cos(cnt1 + cnt2)));

	// Pozycja tekstu na ekranie
	glRasterPos2f(-0.45f + 0.05f*float(cos(cnt1)), 0.35f*float(sin(cnt2)));

	glPrint("Active OpenGL Text With NeHe - %7.2f", cnt1);         // Wy�wietl tekst GL na ekranie


	cnt1 += 0.051f;         // Zwi�ksza pierwszy licznik
	cnt2 += 0.005f;         // Zwi�ksza drugi licznik
	return TRUE;         // Wszystko posz�o OK
}

//if(!UnregisterClass("OpenGL", hInstance))         // Jeste�my zdolni do odrejestrowania klasy ?
//{
//	MessageBox(NULL, "Nie mo�na odrejestrowa� klasy!", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
//	hInstance = NULL;         // Ustawia instancj� na NULL
//}
//KillFont();         // Niszczy czcionk�