#pragma once
#include "windows.h"
#include "stdafx.h"
#include "iostream"
#include <string>
#include "Postac.h"
using namespace std;

class Mezczyzna : public Postac
{
public:
	int liczDialog;

public:
	void idz(string miej);
	void mow(string kwest);
	void biegnie(string miej);
	void zabija(string kog);
	Mezczyzna(string nazwaa, string opiss, string wygladd);
	~Mezczyzna();
	Mezczyzna();
};
