#pragma once
#include"Datum.h"
#include"ClanskaKartica.h"
#include"Includes.h"
#include"Auto.h"
#include"Lista.h"
class Korisnik{
private:
	string imePrezime;
	Datum datumRodenja;
	string email;
	ClanskaKartica kartica;
	Lista<Auto>jeIznajmio;
	double loyalitiBodovi;


public:
	Korisnik(string _imePrezime="empty",string _email="empty@gmail.com"):
		imePrezime{ _imePrezime }, datumRodenja{}, email{ _email }, kartica{}, jeIznajmio{}, loyalitiBodovi{ 0 }{}
	~Korisnik() {};

	void setImePrezime();
	void setDatumRodenja();
	void setEmail();
	void setKorisnik();
	void setLoyalitiBodovi(double Bodovi);
	void dodajIznajmjenoAuto(Auto &a);
	void vratiIznajmjenoAuto();
	void printKorisnikInfo();

	Auto getObjekatIznajmljenoAuto();
	string getImePrezime();
	string getEmail();
	Datum getDatumRodjenja();
	ClanskaKartica getKartica();
	double getLoyalitiBodivi();
	int getBrojIznamljenihAuta();
};
