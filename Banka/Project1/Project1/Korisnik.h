#pragma once
#include"Includes.h"
class Korisnik {
	char *ime;
	char *prezime;
	char *adresa;
	char *grad;
public:
	Korisnik(const char *_ime = "Niko", const char *_prezime = "Nikic", const char *_adresa = "Tu i tamo", const char *_grad = "ovamo");
	~Korisnik();

	void setIme();
	void setPrezime();
	void setAdresa();
	void setGrad();

	char *getIme();
	char *getPrezime();
	char *getAdresa();
	char *getGrad();
};
