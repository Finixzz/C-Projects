#include "Korisnik.h"



void Korisnik::setImePrezime()
{
	cout << "Unesite ime i prezime korisnika: "; getline(cin, this->imePrezime);
}

void Korisnik::setEmail()
{
	cout << "Unesite email: "; getline(cin, this->email);
}

void Korisnik::setKorisnik()
{
	this->setImePrezime();
	this->setEmail();
	if (kartica.getStatusKartice() == false) {
		kartica.kreirajKarticu();
	}
}

string Korisnik::getImePrezime()
{
	return this->imePrezime;
}

string Korisnik::getEmail()
{
	return this->email;
}

ClanskaKartica Korisnik::getKartica()
{
	return this->kartica;
}
