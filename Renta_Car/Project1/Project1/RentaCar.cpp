#include "RentaCar.h"

void RentaCar::dodajKorisnika(Korisnik &k)
{
	this->listaKorisnika.dodaj(k);
}

int RentaCar::getBrojKorisnika()
{
	return this->listaKorisnika.getDuzina();
}


void RentaCar::dodajAuto(Auto &a)
{
	this->listaAuta.dodaj(a);
}

void RentaCar::dodajIzvjestaj(string &izvjestaj) {
	this->listaIzvjestaja.dodaj(izvjestaj);
}

void RentaCar::ispisiVozniPark()
{
	boja oboji;
	oboji.setZelena();
	cout << " -----------------------------------------------------------------------------------------------------------------------------------------------\n";
	oboji.setDefault();
	cout << "                                                                    RENT - A - CAR PARK" << endl;
	oboji.setZelena();
	cout << " -----------------------------------------------------------------------------------------------------------------------------------------------\n";
	oboji.setDefault();
	for (int i = 0; i < this->getSizeOfListaAuta(); i++) {
		oboji.setCrvena();
		cout << "[" << i + 1 << ".]";
		oboji.setDefault();
		listaAuta.getClanSaIndexa(i).printAutoInfo();
		oboji.setCrvena();
		cout << " -----------------------------------------------------------------------------------------------------------------------------------------------\n";
		oboji.setDefault();
		cout << endl;
	}
}

int RentaCar::getSizeOfListaAuta()
{
	return listaAuta.getDuzina();
}


int RentaCar::getUkupanBrojDostupnihAuta() {
	this->brojDostupnihAuta = 0;
	for (int i = 0; i < listaAuta.getDuzina(); i++) {
		this->brojDostupnihAuta += listaAuta.getClanSaIndexa(i).getBrojAutaTogTipa();
	}
	return this->brojDostupnihAuta;
}

void RentaCar::updateLoyalitiBodovi(Korisnik &k, double Bodovi)
{
	k.setLoyalitiBodovi(Bodovi);
}

int RentaCar::getBrojIzvjestaja()
{
	return this->listaIzvjestaja.getDuzina();
}

void RentaCar::printIzvjestaji()
{
	boja oboji;
	for (int i = 0; i < this->getBrojIzvjestaja(); i++) {
		oboji.setZelena();
		cout << "----------------------------------\n";
		oboji.setDefault();
		cout << i + 1 << ". " << listaIzvjestaja.getClanSaIndexa(i) << endl;
		oboji.setZelena();
		cout << "----------------------------------\n";
		oboji.setDefault();
	}
}

void RentaCar::izvrsiRezervaciju(Korisnik &korisnik,int & izborAuta)
{
	boja oboji;
	izborAuta--;
	if (izborAuta < 0)
		return;
	while (izborAuta >= this->getSizeOfListaAuta()) {
		oboji.setCrvena(); cout << "[POGRESAN UNOS]" << endl; oboji.setDefault();
		cout << "Unesite redni broj automobila za iznajmljivanje: ";
		cin >> izborAuta;
		izborAuta--;
	}
	korisnik.dodajIznajmjenoAuto(listaAuta.getClanSaIndexa(izborAuta));
	listaAuta.getClanSaIndexa(izborAuta).jeIznajmljeno();
	this->setBrojDanaZaKoristenjeAuta();

	string izvjestaj;
	izvjestaj = korisnik.getImePrezime() + "je iznajmio " + listaAuta.getClanSaIndexa(izborAuta).getMarka().getNaziv() + " na ukupno " + to_string(this->getBrojKoristenihDana()) + " dana";
	double cijenaUsluge = this->listaAuta.getClanSaIndexa(izborAuta).getCijenaPoDanu()*this->brojDanaZaKoristenjeAuta;
	cout << "Ukupno za platit: " << cijenaUsluge << endl;
	this->dodajIzvjestaj(izvjestaj);
	this->updateLoyalitiBodovi(korisnik, cijenaUsluge / 100);
}

void RentaCar::setBrojDanaZaKoristenjeAuta()
{
	cout << "Unesite na koliko dana zelite da iznajmite automobil: ";
	cin >> this->brojDanaZaKoristenjeAuta;
}

int RentaCar::getBrojKoristenihDana()
{
	return this->brojDanaZaKoristenjeAuta;
}



