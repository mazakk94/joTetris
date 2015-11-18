#include "procedurki.h"
#include <GL/freeglut.h>

using namespace std;

void spadnienty(int X)
{
	glutTimerFunc(value, spadanie, 0);
	_spadnienty = 0;
}

void spadanie(int X)
{
	////cout << "igrek = " << (int)-igrek + 9 << endl;
	////cout << "iks = " << (int)iks + 6 << endl << endl;
	spadl = 0;
	_spadnienty = 0;


	switch (kloc)
	{
	case 1:
	{
			  if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 9 + 1][(int)iks + 7])
			  {
				 // _spadnienty = 1;
				  //glutTimerFunc(1000, spadanie, 0);
				  spadl = 1;
				  klawisz_spacja = false;

				  _spadnienty = 1;
				  ////cout << "1" << endl;
				  macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //LEWY DOLNY
				  macierz[(int)-igrek + 8 + 1][(int)iks + 6 + 1] = 1; //PRAWY DOLNY
				  macierz[(int)-igrek + 8][(int)iks + 6 + 1] = 1; //PRAWY GORNY
				  macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY GORNY
			  }
			  else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			  {
				  if (tajmer == 5 && pauza == 0)
					  igrek -= 1;
				  tajmer = tajmer % 5 + 1;
				//  if (_spadnienty == 0)
					glutTimerFunc(value, spadanie, 0);

			  }
			  break;

	}
	case 2:
	{
			  if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 7])
			  {
				  spadl = 1;
				  klawisz_spacja = false;
				  //cout << "2" << endl;
				  macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //LEWY DOLNY1    XXX
				  macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY2
				  macierz[(int)-igrek + 8][(int)iks + 6 + 1] = 1; //PRAWY DOLNY
				  macierz[(int)-igrek + 8 - 1][(int)iks + 6 + 1] = 1; //PRAWY GORNY
			  }
			  else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			  {
				  if (tajmer == 5 && pauza == 0)
					  igrek -= 1;
				  tajmer = tajmer % 5 + 1;
				  glutTimerFunc(value, spadanie, 0);
			  }
			  break;
	}

	case 22:
	{
			   if (macierz[(int)-igrek + 9 + 1][(int)iks + 8] || macierz[(int)-igrek + 9 + 1][(int)iks + 7] || macierz[(int)-igrek + 9][(int)iks + 6])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //   //cout << "2" << endl;
				   macierz[(int)-igrek + 8 + 1][(int)iks + 7] = 1; //LEWY DOLNY    XXX
				   macierz[(int)-igrek + 8 + 1][(int)iks + 8] = 1; //PRAWY DOLNY
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY GORNY
				   macierz[(int)-igrek + 8][(int)iks + 6 + 1] = 1; //PRAWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 3:
	{
			  if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 5])
			  {
				  spadl = 1;
				  klawisz_spacja = false;

				  //cout << "3" << endl;
				  macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //PRAWY DOLNY1	XXX
				  macierz[(int)-igrek + 8][(int)iks + 6] = 1; //PRAWY GÓRNY
				  macierz[(int)-igrek + 8][(int)iks + 6 - 1] = 1; //LEWY DOLNY
				  macierz[(int)-igrek + 8 - 1][(int)iks + 6 - 1] = 1; //LEWY GORNY
			  }
			  else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			  {
				  if (tajmer == 5 && pauza == 0)
					  igrek -= 1;
				  tajmer = tajmer % 5 + 1;
				  glutTimerFunc(value, spadanie, 0);
			  }
			  break;
	}

	case 32:
	{
			   if (macierz[(int)-igrek + 9][(int)iks + 6] || macierz[(int)-igrek + 9 + 1][(int)iks + 5] || macierz[(int)-igrek + 9 + 1][(int)iks + 4])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "2" << endl;
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY    XXX
				   macierz[(int)-igrek + 8 + 1][(int)iks + 5] = 1; //PRAWY DOLNY
				   macierz[(int)-igrek + 8][(int)iks + 5] = 1; //LEWY GORNY
				   macierz[(int)-igrek + 8 + 1][(int)iks + 4] = 1; //PRAWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}

	case 4:
	{
			  if (macierz[(int)-igrek + 9 + 1][(int)iks + 6])
			  {
				  spadl = 1;
				  klawisz_spacja = false;

				  //cout << "4" << endl;
				  macierz[(int)-igrek + 9][(int)iks + 6] = 1; //DOLNY1
				  macierz[(int)-igrek + 9 - 1][(int)iks + 6] = 1; //DOLNY2
				  macierz[(int)-igrek + 9 - 2][(int)iks + 6] = 1; //DOLNY3
				  macierz[(int)-igrek + 9 - 3][(int)iks + 6] = 1; //GÓRNY
			  }
			  else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			  {
				  if (tajmer == 5 && pauza == 0)
					  igrek -= 1;
				  tajmer = tajmer % 5 + 1;
				  glutTimerFunc(value, spadanie, 0);
			  }
			  break;
	}

	case 42:
	{
			   if (macierz[(int)-igrek + 9][(int)iks + 5] || macierz[(int)-igrek + 9][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 7] || macierz[(int)-igrek + 9][(int)iks + 8])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "4" << endl;
				   macierz[(int)-igrek + 8][(int)iks + 5] = 1; //DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //DOLNY2
				   macierz[(int)-igrek + 8][(int)iks + 7] = 1; //DOLNY3
				   macierz[(int)-igrek + 8][(int)iks + 8] = 1; //GÓRNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 5:
	{
			  if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 8][(int)iks + 7])
			  {
				  spadl = 1;
				  klawisz_spacja = false;

				  //cout << "5" << endl;
				  macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //LEWY DOLNY1
				  macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY2
				  macierz[(int)-igrek + 8 - 1][(int)iks + 7] = 1; //PRAWY GORNY
				  macierz[(int)-igrek + 8 - 1][(int)iks + 6] = 1; //LEWY GORNY
			  }
			  else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			  {
				  if (tajmer == 5 && pauza == 0)
					  igrek -= 1;
				  tajmer = tajmer % 5 + 1;
				  glutTimerFunc(value, spadanie, 0);
			  }
			  break;
	}

	case 51:
	{
			   if (macierz[(int)-igrek + 9][(int)iks + 6] || macierz[(int)-igrek + 10][(int)iks + 7] || macierz[(int)-igrek + 9][(int)iks + 5])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "5" << endl;
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 5] = 1; //LEWY DOLNY2
				   macierz[(int)-igrek + 8][(int)iks + 7] = 1; //PRAWY GORNY
				   macierz[(int)-igrek + 9][(int)iks + 7] = 1; //LEWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}

	case 52:
	{
			   if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 10][(int)iks + 5])

			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "5" << endl;
				   macierz[(int)-igrek + 9][(int)iks + 6] = 1; //LEWY DOLNY1
				   macierz[(int)-igrek + 9][(int)iks + 5] = 1; //LEWY DOLNY2
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //PRAWY GORNY
				   macierz[(int)-igrek + 7][(int)iks + 6] = 1; //LEWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 53:
	{
			   if (macierz[(int)-igrek + 9][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 7] || macierz[(int)-igrek + 9][(int)iks + 5])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "5" << endl;
				   macierz[(int)-igrek + 8][(int)iks + 5] = 1; //LEWY DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY2
				   macierz[(int)-igrek + 8][(int)iks + 7] = 1; //PRAWY GORNY
				   macierz[(int)-igrek + 7][(int)iks + 5] = 1; //LEWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 6:
	{
			  if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 8][(int)iks + 5])
			  {
				  spadl = 1;
				  klawisz_spacja = false;

				  //cout << "6" << endl;
				  macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //LEWY DOLNY1
				  macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY2
				  macierz[(int)-igrek + 8 - 1][(int)iks + 6] = 1; //PRAWY GORNY
				  macierz[(int)-igrek + 8 - 1][(int)iks + 6 - 1] = 1; //LEWY GORNY
			  }
			  else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			  {
				  if (tajmer == 5 && pauza == 0)
					  igrek -= 1;
				  tajmer = tajmer % 5 + 1;
				  glutTimerFunc(value, spadanie, 0);
			  }
			  break;
	}

	case 61:
	{
			   if (macierz[(int)-igrek + 9][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 7] || macierz[(int)-igrek + 9][(int)iks + 5])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "6" << endl;
				   macierz[(int)-igrek + 8][(int)iks + 5] = 1; //LEWY DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY2
				   macierz[(int)-igrek + 8][(int)iks + 7] = 1; //PRAWY GORNY
				   macierz[(int)-igrek + 7][(int)iks + 7] = 1; //LEWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}

	case 62:
	{
			   if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 10][(int)iks + 7])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "6" << endl;
				   macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //LEWY DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //LEWY DOLNY2
				   macierz[(int)-igrek + 9][(int)iks + 7] = 1; //PRAWY GORNY
				   macierz[(int)-igrek + 7][(int)iks + 6] = 1; //LEWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 63:
	{
			   if (macierz[(int)-igrek + 9 + 1][(int)iks + 5] || macierz[(int)-igrek + 9][(int)iks + 7] || macierz[(int)-igrek + 9][(int)iks + 6])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "6" << endl;
				   macierz[(int)-igrek + 8 + 1][(int)iks + 5] = 1; //LEWY DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 5] = 1; //LEWY DOLNY2
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //PRAWY GORNY
				   macierz[(int)-igrek + 8][(int)iks + 7] = 1; //LEWY GORNY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 7:
	{
			  if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 5] || macierz[(int)-igrek + 9][(int)iks + 7])
			  {
				  spadl = 1;
				  klawisz_spacja = false;

				  //cout << "7" << endl;
				  macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //DOLNY1
				  macierz[(int)-igrek + 8][(int)iks + 6 - 1] = 1; //GORNY LEWY
				  macierz[(int)-igrek + 8][(int)iks + 6] = 1; //GORNY
				  macierz[(int)-igrek + 8][(int)iks + 6 + 1] = 1; //GÓRNY PRAWY
			  }
			  else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			  {
				  if (tajmer == 5 && pauza == 0)
					  igrek -= 1;
				  tajmer = tajmer % 5 + 1;
				  glutTimerFunc(value, spadanie, 0);
			  }
			  break;
	}
	case 71:
	{
			   if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 5])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "7" << endl;
				   macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 6 - 1] = 1; //GORNY LEWY
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //GORNY
				   macierz[(int)-igrek + 7][(int)iks + 6] = 1; //GÓRNY PRAWY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 72:
	{
			   if (macierz[(int)-igrek + 9][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 5] || macierz[(int)-igrek + 9][(int)iks + 7])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "7" << endl;
				   macierz[(int)-igrek + 6 + 1][(int)iks + 6] = 1; //DOLNY1
				   macierz[(int)-igrek + 8][(int)iks + 6 - 1] = 1; //GORNY LEWY
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //GORNY
				   macierz[(int)-igrek + 8][(int)iks + 6 + 1] = 1; //GÓRNY PRAWY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0) if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	case 73:
	{
			   if (macierz[(int)-igrek + 9 + 1][(int)iks + 6] || macierz[(int)-igrek + 9][(int)iks + 7])
			   {
				   spadl = 1;
				   klawisz_spacja = false;

				   //cout << "7" << endl;
				   macierz[(int)-igrek + 8 + 1][(int)iks + 6] = 1; //DOLNY1
				   macierz[(int)-igrek + 8 - 1][(int)iks + 6] = 1; //GORNY LEWY
				   macierz[(int)-igrek + 8][(int)iks + 6] = 1; //GORNY
				   macierz[(int)-igrek + 8][(int)iks + 6 + 1] = 1; //GÓRNY PRAWY
			   }
			   else if (spadl == 0 && zero == 0 && klawisz_spacja == 0)
			   {
				   if (tajmer == 5 && pauza == 0)
					   igrek -= 1;
				   tajmer = tajmer % 5 + 1;
				   glutTimerFunc(value, spadanie, 0);
			   }
			   break;
	}
	}
	////cout << "igrek = " << (int)igrek + 31 << endl << "iks = " << (int)iks + 6 << endl;

	////cout << "igrek = " << igrek << endl; //<< "iks = " << (int)iks + 6 << endl;
	////cout << "igrek2 = " << igrek2 << endl << endl;


	if (/*_spadnienty == 0 &&*/ (spadl || zero))
	{
		klawisz = true;

		for (int i = 1; i <= 4; i++)
		{

			for (int k = 0; k < 4; k++)
			{
				bool a = true;
				for (int j = 1; j < 12; j++)
				{
					if (kloc == 42 || kloc == 53 || kloc == 72 || kloc == 61)
					{
						a = a && macierz[(int)-igrek + 8 - k][j];
						//	//cout << "j = " << j << "\t" << "a = " << a << endl;
					}
					else
						a = a && macierz[(int)-igrek + 9 - k][j];
				}

				if (a)
				{
					printf("LINIA\n");
					ile_linii++;
					//cout << "lines = " << Wynik.lines << endl;
					for (int i = 0; i < 25; i++)
					{
						if (k == 3)
						{
							for (int j = 0; j < 12; j++)
								printf("%d ", macierz[i][j]);
							printf("\n");
						}
					}
					if (kloc == 42 || kloc == 53 || kloc == 72 || kloc == 61)
					{
						for (int i = -igrek + 8; i > 3; i--)
						for (int j = 1; j < 11; j++)
							macierz[i - k][j] = macierz[i - k - 1][j];
					}
					else
					for (int i = -igrek + 9; i > 3; i--)
					for (int j = 1; j < 11; j++)
						macierz[i - k][j] = macierz[i - k - 1][j];
				}
			}
		}
		Wynik.lines = Wynik.lines + ile_linii;
		Wynik.level = Wynik.lines / 10 + 1;
		if (Wynik.level>20)
			Wynik.level = 20;
		value = -10 * Wynik.level + 210;

		switch (ile_linii){
		case 1:
			Wynik.points += Wynik.level * 100;
			break;
		case 2:
			Wynik.points += Wynik.level * 3 * 100;
			break;
		case 3:
			Wynik.points += Wynik.level * 5 * 100;
			break;
		case 4:
			Wynik.points += Wynik.level * 8 * 100;
		}

		//if (spadl){
		//	//cout << "value = " << value << endl;
		//	//cout << "level = " << Wynik.level << endl;
		//	//cout << "lines = " << Wynik.lines << endl;
		//	//cout << "points = " << Wynik.points << endl << endl;
		//}



		printf("\n\n");
		for (int i = 0; i < 25; i++)
		{
			for (int j = 0; j < 12; j++)
				printf("%d ", macierz[i][j]);
			printf("\n");
		}

		if (spadl == 1)
		{
			kloc = nastepny;
			do
			nastepny = rand() % 7 + 1;
			while (nastepny == kloc);
		}
		else if (hold == 0 && spadl == 0 && zero == 1)
		{
			if (kloc > 10)// && kloc != 42)
				kloc /= 10;
			hold = kloc;
			zero = 0;
			mozna = 0;
			kloc = nastepny;
			do
				nastepny = rand() % 7 + 1;
			while (nastepny == kloc);
		}
		else if (hold != 0 && spadl == 0 && zero == 1)
		{
			zero = 0;
			if (kloc > 10)// && kloc != 42)
				kloc /= 10;
			swap(kloc, hold);
			mozna = 0;
		}


		//cout << "AFTER: " << endl;
		//cout << "hold = " << hold << endl;
		//cout << "kloc = " << kloc << endl;
		//cout << "nastepny: " << nastepny << endl;
		//cout << "spadl = " << spadl << endl << endl;


		ile_linii = 0; // ZACZYNAMY OD GÓRY
		iks = -1;
		igrek = 5;

		// USTAWIAMY ODPOWIEDNIO OD GÓRY KLOCEK
		if (kloc == 4)
			kloc = 42;
		if (kloc != 2 && kloc != 3 && kloc != 5 && kloc != 6)
			igrek += 1;
		//else igrek += 1;

		if (spadl)
			mozna = 1;

		losujkloca();
		rysuj_nastepnego();
		rysuj_holda();
		spadl = 0;
		klawisz_spacja = 0;
		//if (_spadnienty == 0)
		//	glutTimerFunc(3000, spadanie, 0);
		//else
			glutTimerFunc(value, spadanie, 0);
	}

}

