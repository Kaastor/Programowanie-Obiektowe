#pragma once
#include "windows.h"
#include "stdafx.h"
#include "iostream"
#include <string>
using namespace std;

class Postac
{
public:
	string nazwa;
	string wyglad;
	string opis;
	int liczDial;
public:
	virtual void idz(string miej);	
	virtual void mow();
	virtual void spotyka(string kog, string gdz);
	virtual void biegnie();
	virtual void czynnosc(string miej);
	virtual void czynnosc_os(string czyn, string naz);
	virtual void zabija();
	~Postac();
	Postac();
};
