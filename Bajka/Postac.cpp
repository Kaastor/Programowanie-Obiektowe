#include "Postac.h"


Postac::Postac(){}
Postac::~Postac(){}

void Postac::mow(){}
void Postac::biegnie(){}
void Postac::zabija(){}
void Postac::idz(string miej){}

void Postac::spotyka(string kog, string gdz)
{
	cout << nazwa << " spotyka w/na " << gdz << " " << kog << endl;
}

void Postac::czynnosc(string czyn)
{
	sndPlaySound(L"dzwieki/pstryk.wav", SND_ASYNC);
	cout << nazwa << " " << czyn << endl;

}

void Postac::czynnosc_os(string czyn, string naz)
{
	sndPlaySound(L"dzwieki/pstryk.wav", SND_ASYNC);
	cout << nazwa << " " << czyn << " " << naz << endl;
}
