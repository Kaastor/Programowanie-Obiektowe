#pragma once
#include "windows.h"
#include "stdafx.h"
#include "iostream"
#include <string>
#include "Postac.h"
using namespace std;

class Kobieta : public Postac
{
public:
	int liczDialog;

public:
	void idz(string miej);
	void mow(string kwest);
	void biegnie(string miej);
	void zabija(string kog);
	Kobieta(string nazwaa, string opiss, string wygladd);
	Kobieta();
	~Kobieta();
};
