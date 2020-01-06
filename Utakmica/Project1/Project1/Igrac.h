#pragma once
#include"Includes.h"
#include"Igrac.h"

enum Pozicija { pg = 1, sg, sf, f, c };
class Igrac
{
	char ime[25];
	char prezime[25];
	int brKoseva;
	Pozicija pozicija;
public:
	Igrac(const char *_ime = "Niko", const char *_prez = "Nikic", int _brk = 0, Pozicija _poz = pg) :
		ime{ NULL }, prezime{ NULL }, brKoseva{ _brk }, pozicija{ _poz }{
		strcpy_s(this->ime, _ime);
		strcpy_s(this->prezime, _prez);
	}
	Igrac(const Igrac &src) :
		ime{ NULL }, prezime{ NULL }, brKoseva{ src.brKoseva }, pozicija{ src.pozicija }{
		strcpy_s(this->ime, src.ime);
		strcpy_s(this->prezime, src.prezime);
	}
	~Igrac() {}

	void setIme();
	void setPrezime();
	void setBrKoseva(int);
	void setPozicija();
	void setIgrac();

	char *getIme();
	char *getPrezime();
	int getBrKoseva();
	int getPozicija();
	void printPozicija();

	friend ostream & operator<<(ostream &os, Igrac &i);
	friend istream &operator>>(istream &in, Igrac &i);
};
