#include "Korisnik.h"



void Korisnik::setImePrezime()
{
	cout << "Unesite ime i prezime korisnika: "; getline(cin, this->imePrezime);
}

void Korisnik::setDatumRodenja()
{
	boja oboji;
	oboji.setCrvena();
	cout << "-------------------------------\n";
	oboji.setDefault();
	cout << "Unesite datum rodenja korisnika" << endl;
	oboji.setCrvena();
	cout << "-------------------------------\n";
	oboji.setDefault();
	datumRodenja.postaviDatum();
}

void Korisnik::setEmail()
{
	cout << "Unesite email: "; getline(cin, this->email);
}

void Korisnik::setKorisnik()
{
	boja oboji;
	this->setImePrezime();
	this->setDatumRodenja();
	this->setEmail();
	if (kartica.getStatusKartice() == false) {
		oboji.setCrvena();
		cout << "-------------------------------\n";
		oboji.setDefault();
		cout << "Unesite datum kreiranja kartice" << endl;
		oboji.setCrvena();
		cout << "-------------------------------\n";
		oboji.setDefault();
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

Datum Korisnik::getDatumRodjenja()
{
	return this->datumRodenja;
}

ClanskaKartica Korisnik::getKartica()
{
	return this->kartica;
}
