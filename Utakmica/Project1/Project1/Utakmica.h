#pragma once
#include"Igrac.h"
#include"Klub.h"
#include"Includes.h"
class Utakmica
{
	char datum[15];
	Klub domaci;
	Klub gosti;
	static int brKosevaDomaci;
	static int brKosevaGosti;
public:
	Utakmica() {
		strcpy_s(this->datum, "01.01.2019");
	}
	~Utakmica() {};

	void setDatumUtakmice();
	void setDomaci();
	void setGosti();
	void setUtakmica();

	char *getDatum();
	Klub getDomaci();
	Klub getGosti();
	int getBrKosevaDomaci();
	int getBrKosevaGosti();
	void pobjednik();

	friend istream & operator>>(istream &in, Utakmica &u);
	friend ostream &operator<<(ostream &os, Utakmica &u);
	void operator++();
	void operator++(int);
	void operator!();


};
