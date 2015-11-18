#include <fstream>
#include <iostream>
#include <string>

using namespace std;
int i = 0;
void wykonajOperacje( int liczba1)
int hajskory = 1;
{
    if( liczba1 != 0 )
        cout << "hajskory: " << liczba1 << endl;
        //Print(IntToStr(liczba1), 300, 300+i, 0,0,0);
}

bool wczytajPlik( string nazwaPliku )
{
    ifstream plik;
    plik.open( nazwaPliku.c_str() );
    if( !plik.good() )
         return false;

    while( hajskory <=20 )
    {
        int a;
        plik >> a;
        if( plik.good() )
             wykonajOperacje(a);
             i+=20;
        else
             break;
    }
    return true;
}

int main()
{
    if( !wczytajPlik( "highscores.txt" ) )
         cout << "Nie udalo sie otworzyc pliku!" << endl;

    return 0;
}
