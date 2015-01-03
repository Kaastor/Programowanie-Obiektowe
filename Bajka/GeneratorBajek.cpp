// Gen Bajek.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Narrator.h"
#include "Postac.h"
#include "Mezczyzna.h"
#include "Kobieta.h"
#include "Miejsce.h"
#include "iostream"
#include <string>
#include <fstream>
#include <sstream>
#include "windows.h"


int main()
{
	setlocale(LC_ALL, "");

	fstream plik1;
	plik1.open("Narrator.txt");
	string TabPlik1[500];
	string linia;
	int i = 0;
	while (getline(plik1, linia))
	{
		TabPlik1[i] = linia;
		i++;
	}

	plik1.close();

	Narrator Narrator1;
	Narrator1.opowiadanie(TabPlik1);

	return 0;
}
