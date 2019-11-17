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
		kartica.kreirajKarticu(this->getImePrezime(), this->getEmail());
	}
}

void Korisnik::setLoyalitiBodovi(double Bodovi)
{
	this->loyalitiBodovi = this->loyalitiBodovi+Bodovi;
}

void Korisnik::dodajIznajmjenoAuto(Auto & a)
{
	this->jeIznajmio.dodaj(a);

}

void Korisnik::vratiIznajmjenoAuto()
{
	this->jeIznajmio.obrisi();

}

Auto Korisnik::getObjekatIznajmljenoAuto()
{
	return jeIznajmio.getClan();
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

double Korisnik::getLoyalitiBodivi()
{
	return this->loyalitiBodovi;
}

void Korisnik::printKorisnikInfo()
{
	boja oboji;
	oboji.setCrvena();
	cout << "-----------------------------\n";
	oboji.setDefault();
	cout << "Broj clanske kartice: "<< this->kartica.getBrojKartice() << endl;
	cout << "Datum kreiranja kartice: "; this->kartica.getDatumKreiranjaKartice().ispisiDatum();
	cout << endl;
	oboji.setCrvena();
	cout << "---------------------------------------------------\n";
	oboji.setDefault();
	cout << "Ime prezime: " << this->getImePrezime() << endl;
	cout << "Datum rodjednja: "; this->datumRodenja.ispisiDatum();
	cout << endl;
	cout << "Email: " << this->getEmail() << endl;
	oboji.setCrvena();
	cout << "---------------------------------------------------\n";
	oboji.setDefault();
	cout << "Broj loyaliti bodova: "; oboji.setZelena(); cout << this->getLoyalitiBodivi() << endl; oboji.setDefault();
	oboji.setCrvena();
	cout << "-----------------------------\n";
	oboji.setDefault();
}

int Korisnik::getBrojIznamljenihAuta()
{
	return this->jeIznajmio.getDuzina();
}
