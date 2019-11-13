#pragma once
#include"ClanskaKartica.h"
#include"Includes.h"

class Korisnik{
	string imePrezime;
	string email;
	ClanskaKartica kartica;

public:
	Korisnik(string _imePrezime="empty",string _email="empty@gmail.com"):
		imePrezime{_imePrezime},email{_email},kartica{}{}
	~Korisnik() {};

	void setImePrezime();
	void setEmail();
	void setKorisnik();
	string getImePrezime();
	string getEmail();
	ClanskaKartica getKartica();
};
