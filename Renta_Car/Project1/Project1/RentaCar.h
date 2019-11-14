#pragma once
#include"Includes.h"
#include"Lista.h"
#include"Datum.h"
#include"Korisnik.h"
#include"Auto.h"
class RentaCar{
private:
	Lista<Korisnik>listaKorisnika;
	Lista<Auto>listaAuta;
	Lista<string>izvjestaj;
	int brojDostupnihAuta;

public:
	RentaCar() :
		listaKorisnika{}, listaAuta{}, izvjestaj{}, brojDostupnihAuta{ 0 }{};
	~RentaCar() {};

	void dodajKorisnika(Korisnik &k);
	int getBrojKorisnika();

	void dodajAuto(Auto &a);
	void ispisiVozniPark();
	int getBrojAuta();
	int getUkupanBrojDostupnihAuta();
};

