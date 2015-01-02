#pragma once

#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;
class Miejsce;

class Postac
{
public:
	string nazwa;
	string wyglad;
	string opis;
	int liczDial;
public:
	virtual void idz(string miej);		//dodac przesylanie obiektu???
	virtual void mow();
	virtual void spotyka();
	virtual void biegnie();
	virtual void czynnosc(string miej);
	virtual void czynnosc_os(string czyn, string naz);
	~Postac();
};


class Mezczyzna : public Postac
{
public:
	int liczDialogM;

public:
	void idz(string miej);
	Mezczyzna(string nazwaa, string opiss, string wygladd);
	~Mezczyzna();
	Mezczyzna();
};

class Kobieta : public Postac
{
public:
	int liczDialogK;

public:
	void idz(string miej);
	Kobieta(string nazwaa, string opiss, string wygladd);
	Kobieta();
	~Kobieta();
};

class Miejsce
{
public:
	string nazwa;
	string opis;

public:

	Miejsce();
	~Miejsce();
};

class Narrator
{

public:
	void opowiadanie(string Tab1[]);

	Narrator();
};


