
#include <windows.h>         // Plik nag³ówkowy Windows
#include <math.h>         // Plik nag³ówkowy dla operacji matematycznych    ( NOWE )
#include <stdio.h>         // Plik nag³ówkowy dla operacji wejœcia/wyjœcia    ( NOWE )
#include <stdarg.h>         // Nag³ówek dla zmiennych argumentów funkcji    ( NOWE )
#include <gl\gl.h>         // Plik nag³ówkowy biblioteki OpenGL
#include <gl\glu.h>         // Plik nag³ówkowy biblioteki GLu32
#include <gl/GLAUX.H>         // Plik nag³ówkowy biblioteki GLaux 
HDC        hDC = NULL;         // Kontekst urz¹dzenia
HGLRC        hRC = NULL;         // Kontekst renderuj¹cy
HWND        hWnd = NULL;         // Przechowuje uchwyt okna
HINSTANCE    hInstance;         // Przechowuje instancjê okna (ang. Instance)

GLuint    base;         // Base Display List For The Font Set
GLfloat    cnt1;         // Pierwszy licznik do poruszania i kolorowania tekstu
GLfloat    cnt2;         // Drugi licznik do poruszania i kolorowania tekstu 
bool    keys[256];         // Tablica u¿ywana do obs³ugi klawiatury
bool    active = TRUE;         // Zmienna aktywnoœci okna ustawiona wstêpnie na TRUE
bool    fullscreen = TRUE;         // Tryb pe³noekranowy wstêpnie ustawiony na TRUE 
LRESULT    CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);         // Deklaracja WndProc (wiêcej w tekstach o WinApi)

GLvoid BuildFont(GLvoid)         // Buduje nasz¹ bitmapow¹ czcionkê
{
	HFONT    font;         // Identyfikator czicionki windowsowej
	HFONT    oldfont;         // U¿yte dla Good House Keeping 
	base = glGenLists(96);         // Przechowuje 96 znaków        ( NOWE )

	font = CreateFont(-24,         // Wysokoœæ czcionki            ( NOWE )


		0,         // Œrednia szerokoœæ znaku

		0,         // K¹t pochylenia
		0,         // K¹t orientacji wzglêdem linii bazowej

		FW_BOLD,         // Waga czcionki

		FALSE,         // Kursywa
		FALSE,         // Podkreœlenie
		TRUE,         // Pogrubienie

		ANSI_CHARSET,         // Identyfikator zbioru znaków

		OUT_TT_PRECIS,         // Dok³adnoœæ prezentacji

		CLIP_DEFAULT_PRECIS,         // Dok³adnoœæ przyciêcia

		ANTIALIASED_QUALITY,         // Jakoœæ prezentacji

		FF_DONTCARE | DEFAULT_PITCH,         // Rodzina i podzia³ka czcionki

		"Courier New");         // Nazwa czcionki

	oldfont = (HFONT)SelectObject(hDC, font);         // Wybiera czcionkê jak¹ chcemy
	wglUseFontBitmaps(hDC, 32, 96, base);         // Buduje 96 znaków zaczynaj¹c od znaku 32
	SelectObject(hDC, oldfont);         // Wybiera czcionkê jak¹ chcemy
	DeleteObject(font);         // Kasuje czcionkê
}
//Nastêpny kod jest ca³kiem prosty.Kasujemy 96 list wyœwietlania zaczynaj¹c od pierwszej, okreœlonej w base.Lepiej jest samemu to zrobiæ ni¿ ³udziæ siê, ¿e windows to zrobi za nas : ).

GLvoid KillFont(GLvoid)         // Kasuje listy czcionki
{
	glDeleteLists(base, 96);         // Kasuje wszystkie 96 znaków        ( NOWE )
}

GLvoid glPrint(const char *fmt, ...)         // W³asna procedura GL "Print"
{

	char        text[256];         // Przechowuje stringa
	va_list        ap;         // WskaŸnik do listy argumentów

	if (fmt == NULL)         // Je¿eli nie ma tekstu
		return;         // nie robi nic

	va_start(ap, fmt);         // Przeszukje string w celu znalezienia zmiennych
	vsprintf_s(text, fmt, ap);         // Konwertuje symbole na aktualne numery
	va_end(ap);         // Rezultaty s¹ przechowywane w zmiennej text

	glPushAttrib(GL_LIST_BIT);         // Wrzucamy listê na stos        ( NOWE )
	glListBase(base - 32);         // Odejmuje pierwsze 32 znaki        ( NOWE )
	glCallLists(strlen(text), GL_UNSIGNED_BYTE, text);         // Rysuje nasz tekst      ( NOWE )
	glPopAttrib();         // Zdejmuje ze stosu nasz¹ listê    ( NOWE )
}


int InitGL(GLvoid)         // Ustawienia OpenGL
{
	glShadeModel(GL_SMOOTH);         // W³¹cza wyg³adzane cieniowanie (ang. Smooth Shading)
	glClearColor(0.0f, 0.0f, 0.0f, 0.5f);         // Czarne t³o
	glClearDepth(1.0f);         // Ustawienia bufora g³êbi
	glEnable(GL_DEPTH_TEST);         // W³¹cza testowanie g³êbi
	glDepthFunc(GL_LEQUAL);         // Typ testowania g³êbi
	glHint(GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST);         // £adna perspektywa 
	BuildFont();         // Buduje czcionkê 
	return TRUE;         // Inicjalizacja posz³a OK
}

int DrawGLScene(GLvoid)         // Tutaj rysujemy
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);         // Wyczyœæ ekran i bufor g³êbi
	glLoadIdentity();         // Zresetuj widok
	glTranslatef(0.0f, 0.0f, -1.0f);         // Przenosimy siê 1 jednostkê w ekran

	// Pulsuj¹ce kolory w zale¿noœci od pozycji tekstu
	glColor3f(1.0f*float(cos(cnt1)), 1.0f*float(sin(cnt2)), 1.0f - 0.5f*float(cos(cnt1 + cnt2)));

	// Pozycja tekstu na ekranie
	glRasterPos2f(-0.45f + 0.05f*float(cos(cnt1)), 0.35f*float(sin(cnt2)));

	glPrint("Active OpenGL Text With NeHe - %7.2f", cnt1);         // Wyœwietl tekst GL na ekranie


	cnt1 += 0.051f;         // Zwiêksza pierwszy licznik
	cnt2 += 0.005f;         // Zwiêksza drugi licznik
	return TRUE;         // Wszystko posz³o OK
}

//if(!UnregisterClass("OpenGL", hInstance))         // Jesteœmy zdolni do odrejestrowania klasy ?
//{
//	MessageBox(NULL, "Nie mo¿na odrejestrowaæ klasy!", "SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
//	hInstance = NULL;         // Ustawia instancjê na NULL
//}
//KillFont();         // Niszczy czcionkê