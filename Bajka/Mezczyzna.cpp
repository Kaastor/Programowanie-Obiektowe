#include "Mezczyzna.h"


Mezczyzna::Mezczyzna()
{
}


Mezczyzna::~Mezczyzna()
{
}

Mezczyzna::Mezczyzna(string nazwaa, string opiss, string wygladd)
{
	nazwa = nazwaa;
	opis = opiss;
	wyglad = wygladd;
	cout << nazwa << " - " << opis << "\n" << wyglad << endl;
	getchar();
}

void Mezczyzna::idz(string miej)
{
	sndPlaySound(L"dzwieki/kroki.wav", SND_ASYNC);
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

void Mezczyzna::mow(string kwest)
{
	sndPlaySound(L"dzwieki/mantalk.wav", SND_ASYNC);
	if (liczDialog % 2 == 0)
	{
		cout << kwest << " " << "- powiedział " << nazwa << endl;
	}
	else if (liczDialog % 3 == 0)
	{
		cout << kwest << " " << "- rzekł " << nazwa << endl;
	}
	else
	{
		cout << kwest << " " << "- odparł " << nazwa << endl;
	}

}

void Mezczyzna::zabija(string kog)
{
	sndPlaySound(L"dzwieki/kill.wav", SND_ASYNC);
	cout << nazwa << " zabił " << kog << endl;
}

void Mezczyzna::biegnie(string miej)
{
	sndPlaySound(L"dzwieki/bieg.wav", SND_ASYNC);
	liczDial += 1;
	cout << nazwa << " pobiegł do " << miej << endl;
}
