#include "Klasy.h"
#include "stdafx.h"
#include "iostream"
#include <string>
#include <fstream>
#include <sstream>

using namespace std;
Postac::~Postac(){}
Kobieta::~Kobieta(){}
Mezczyzna::~Mezczyzna(){}
Kobieta::Kobieta(){}
Mezczyzna::Mezczyzna(){}
Miejsce::~Miejsce(){}

void Postac::mow()
{
}
void Postac::spotyka()
{
}
void Postac::biegnie()
{
}
void Postac::idz(string miej)
{}


Narrator::Narrator(){
	cout << "Starzec usiadł przy stole i nabijajac fajke, przygotowywal sie do rozpoczecia opowiesci..." << endl;
	getchar();
}

Mezczyzna::Mezczyzna(string nazwaa, string opiss, string wygladd)
{
	nazwa = nazwaa;
	opis = opiss;
	wyglad = wygladd;
	cout << nazwa << " - "<< opis << "\n" << wyglad << endl;
	getchar();
}
Kobieta::Kobieta(string nazwaa, string opiss, string wygladd)
{
	nazwa = nazwaa;
	opis = opiss;
	wyglad = wygladd;
	cout << nazwa << " - " << opis << "\n" << wyglad << endl;
	getchar();
}

Miejsce::Miejsce(){}

void Mezczyzna::idz(string miej)
{

	liczDial += 1;
	if (liczDial % 2 == 0)
	{
		cout << nazwa << " wyruszył do " << miej << endl;
	}
	else
	{
		cout << nazwa << " poszedł do " << miej << endl;
	}
}

void Kobieta::idz(string miej)
{
	liczDial += 1;
	if (liczDial % 2 == 0)
	{
		cout << nazwa << " wyruszyła do " << miej << endl;
	}
	else
	{
		cout << nazwa << " poszła do " << miej << endl;
	}

}

void Postac::czynnosc(string czyn)
{
	cout << nazwa << " " << czyn << endl;
	
}
void Postac::czynnosc_os(string czyn, string naz)
{
	cout << nazwa << " " << czyn << " " << naz << endl;
}

void Narrator::opowiadanie(string Tab1[])
{
	int licznikNarr = 0;
	int l=0;

	int i = 0;
	cout << "Oto postacie, którę będą brały udział w mojej opowieści - rzekł " << endl;
	getchar();

	Mezczyzna postacie1[20];		// liczba postaci max
	Kobieta postacie2[20];
	Miejsce miejsca[20];		// liczba miejsc max
	while (Tab1[licznikNarr] != "M---")
	{
		postacie1[i] = Mezczyzna(Tab1[licznikNarr], Tab1[licznikNarr++], Tab1[licznikNarr++]);
		licznikNarr++;
		i++; l++;
	}
	licznikNarr++;

	while (Tab1[licznikNarr] != "Z---")
	{
		postacie2[i] = Kobieta(Tab1[licznikNarr], Tab1[licznikNarr++], Tab1[licznikNarr++]);
		licznikNarr++;
		i++;
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

	
	

	for (;;)
	{
		licznikNarr += 2;
		string x = Tab1[licznikNarr];
		
		if (x == "idz")
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
		}
		else if (x == "spotyka")
		{
		}
		else if (x == "biegnie")
		{
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
			else { imie=postacie2[q].nazwa; }

			if (z < l){ postacie1[z].czynnosc_os(y, imie); }
			else { postacie2[z].czynnosc_os(y, imie ); }		

			getchar();
		}
		
				
	}


}

