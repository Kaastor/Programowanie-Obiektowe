#include "Kobieta.h"


Kobieta::Kobieta()
{
}


Kobieta::~Kobieta()
{
}

Kobieta::Kobieta(string nazwaa, string opiss, string wygladd)
{
	nazwa = nazwaa;
	opis = opiss;
	wyglad = wygladd;
	cout << nazwa << " - " << opis << "\n" << wyglad << endl;
	getchar();
}

void Kobieta::idz(string miej)
{
	sndPlaySound(L"dzwieki/kroki.wav", SND_ASYNC);
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

void Kobieta::mow(string kwest)
{
	sndPlaySound(L"dzwieki/womantalk.wav", SND_ASYNC);
	if (liczDialog % 2 == 0)
	{
		cout << kwest << " " << "- powiedziała " << nazwa << endl;
	}
	else if (liczDialog % 3 == 0)
	{
		cout << kwest << " " << "- rzekła " << nazwa << endl;
	}
	else
	{
		cout << kwest << " " << "- odparła " << nazwa << endl;
	}

}

void Kobieta::zabija(string kog)
{
	sndPlaySound(L"dzwieki/kill.wav", SND_ASYNC);
	cout << nazwa << " zabiła " << kog << endl;
}

void Kobieta::biegnie(string miej)
{
	sndPlaySound(L"dzwieki/bieg.wav", SND_ASYNC);
	liczDial += 1;
	cout << nazwa << " pobiegła do " << miej << endl;
}
