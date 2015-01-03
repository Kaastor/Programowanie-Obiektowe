#include "Narrator.h"
#include "Postac.h"
#include "Mezczyzna.h"
#include "Kobieta.h"
#include "Miejsce.h"
#include "stdafx.h"
#include "iostream"
#include <string>
#include <fstream>
#include <sstream>
#include "windows.h"
#pragma comment(lib, "winmm.lib")
string PlikDialogi[20][200];
using namespace std;

Narrator::Narrator(){
	cout << "Starzec usiadł przy stole i nabijajac fajke, przygotowywal sie do rozpoczecia opowiesci..." << endl;
	getchar();
}


Narrator::~Narrator()
{
}

void PobierzDialogi(Mezczyzna postacie1[], Kobieta postacie2[], int x, int g)
{
	int i = 0, j = 0;

	for (i = 0; i < g; i++)
	{
		if (i == g) {
			break;
		}
		else if (i < x)
		{
			fstream plik1;
			string nazwa = postacie1[i].nazwa + ".txt";
			plik1.open(nazwa);

			string linia;

			while (getline(plik1, linia))
			{
				PlikDialogi[i][j] = linia;
				j++;
			}
			plik1.close();
			j = 0;
		}
		else
		{
			fstream plik1;
			string nazwa = postacie2[i].nazwa + ".txt";
			plik1.open(nazwa);

			string linia;

			while (getline(plik1, linia))
			{
				PlikDialogi[i][j] = linia;
				j++;
			}
			plik1.close();
			j = 0;

		}
	}
}

void Narrator::opowiadanie(string Tab1[])
{
	int licznikNarr = 0;
	int l = 0, g = 0;

	int i = 0;
	cout << "Oto postacie, którę będš brały udział w mojej opowieci - rzekł " << endl;
	getchar();

	Mezczyzna postacie1[20];		// liczba postaci max
	Kobieta postacie2[20];
	Miejsce miejsca[20];		// liczba miejsc max
	while (Tab1[licznikNarr] != "M---")
	{
		postacie1[i] = Mezczyzna(Tab1[licznikNarr], Tab1[licznikNarr++], Tab1[licznikNarr++]);
		postacie1[i].liczDialog = 0;
		licznikNarr++;
		i++; l++; g++;
	}
	licznikNarr++;

	while (Tab1[licznikNarr] != "Z---")
	{
		postacie2[i] = Kobieta(Tab1[licznikNarr], Tab1[licznikNarr++], Tab1[licznikNarr++]);
		postacie2[i].liczDialog = 0;
		licznikNarr++;
		i++; g++;
	}
	licznikNarr++;
	i = 0;
	while (Tab1[licznikNarr] != "Miejsca---")
	{
		miejsca[i] = Miejsce();
		miejsca[i].nazwa = Tab1[licznikNarr];
		licznikNarr++;
		miejsca[i].opis = Tab1[licznikNarr];
		licznikNarr++;
		i++;
	}
	cout << "Cała historia rozpoczyna się w " << miejsca[0].nazwa << ", jest to " << miejsca[0].opis << "\n" << endl;

	cout << "A oto przebieg wydarzeń...\n\n " << endl;

	PobierzDialogi(postacie1, postacie2, l, g);

	for (;;)
	{
		licznikNarr += 2;
		string x = Tab1[licznikNarr];
		if (x == ""){ cout << " \t*********KONIEC*********\n\n" << endl; exit(0); }

		else if (x == "idz")
		{
			licznikNarr++;
			int z = atoi(Tab1[licznikNarr].c_str());

			licznikNarr++;
			int y = atoi(Tab1[licznikNarr].c_str());

			string miejsce = miejsca[y].nazwa;
			if (z < l){ postacie1[z].idz(miejsce); }
			else { postacie2[z].idz(miejsce); }

			getchar();
		}
		else if (x == "mow")
		{
			licznikNarr++;
			int z = atoi(Tab1[licznikNarr].c_str());
			if (z < l)
			{
				string kwestia = PlikDialogi[z][postacie1[z].liczDialog];
				postacie1[z].mow(kwestia); postacie1[z].liczDialog++;
			}
			else
			{
				string kwestia = PlikDialogi[z][postacie2[z].liczDialog];
				postacie2[z].mow(kwestia); postacie2[z].liczDialog++;
			}
			getchar();
		}
		else if (x == "spotyka")
		{
			licznikNarr++;
			int z = atoi(Tab1[licznikNarr].c_str());
			licznikNarr++;
			int y = atoi(Tab1[licznikNarr].c_str());
			licznikNarr++;
			int t = atoi(Tab1[licznikNarr].c_str());
			string kogo;
			if (y < l){ kogo = postacie1[y].nazwa; }
			else { kogo = postacie2[y].nazwa; }

			string miejsce = miejsca[t].nazwa;

			if (z < l)
			{
				postacie1[z].spotyka(kogo, miejsce);
			}
			else
			{
				postacie2[z].spotyka(kogo, miejsce);
			}
			getchar();
		}
		else if (x == "biegnie")
		{
			licznikNarr++;
			int z = atoi(Tab1[licznikNarr].c_str());

			licznikNarr++;
			int y = atoi(Tab1[licznikNarr].c_str());

			string miejsce = miejsca[y].nazwa;
			if (z < l){ postacie1[z].biegnie(miejsce); }
			else { postacie2[z].biegnie(miejsce); }

			getchar();
		}
		else if (x == "czynnosc")
		{
			licznikNarr++;
			int z = atoi(Tab1[licznikNarr].c_str());
			licznikNarr++;
			string y = Tab1[licznikNarr];
			if (z < l){ postacie1[z].czynnosc(y); }
			else { postacie2[z].czynnosc(y); }

			getchar();
		}
		else if (x == "czynnosc_os")
		{
			licznikNarr++;
			int z = atoi(Tab1[licznikNarr].c_str());
			licznikNarr++;
			string y = Tab1[licznikNarr];
			licznikNarr++;
			int q = atoi(Tab1[licznikNarr].c_str());
			string imie;
			if (q < l){ imie = postacie1[q].nazwa; }
			else { imie = postacie2[q].nazwa; }

			if (z < l){ postacie1[z].czynnosc_os(y, imie); }
			else { postacie2[z].czynnosc_os(y, imie); }

			getchar();
		}
		else if (x == "zabija")
		{
			licznikNarr++;
			int z = atoi(Tab1[licznikNarr].c_str());
			licznikNarr++;
			int y = atoi(Tab1[licznikNarr].c_str());

			string k;

			if (y < l){ k = postacie1[y].nazwa; }
			else { k = postacie2[y].nazwa; }

			if (z < l){ postacie1[z].zabija(k); }
			else { postacie2[z].zabija(k); }

			getchar();
		}

	}
}
