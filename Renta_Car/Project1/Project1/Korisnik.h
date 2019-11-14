#pragma once
#include"Datum.h"
#include"ClanskaKartica.h"
#include"Includes.h"

class Korisnik{
	string imePrezime;
	Datum datumRodenja;
	string email;
	ClanskaKartica kartica;
	double loyalitiBodovi;


public:
	Korisnik(string _imePrezime="empty",string _email="empty@gmail.com"):
		imePrezime{ _imePrezime }, datumRodenja{}, email{ _email }, kartica{}, loyalitiBodovi{ 0 }{}
	~Korisnik() {};

	void setImePrezime();
	void setDatumRodenja();
	void setEmail();
	void setKorisnik();
	string getImePrezime();
	string getEmail();
	Datum getDatumRodjenja();
	ClanskaKartica getKartica();
};
