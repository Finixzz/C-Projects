#pragma once
#include"Includes.h"
#include"Korisnik.h"
#include"Datum.h"
class Racun {

	int brRacuna;
	Korisnik korisnik;
	Datum *datumTransakcije;
	float *iznosTransakcije;
	float *stanjeRacuna;
	float limit;
	int brTransakcija;
	bool otvoren;
public:
	Racun();
	~Racun();

	void setBrRacuna();
	void setLimit();
	int getBrTansakcija();
	int getBrRacuna();
	void otvoriRacun();
	void setUplata();
	void setIsplata();
	void printTransakcije();


};
