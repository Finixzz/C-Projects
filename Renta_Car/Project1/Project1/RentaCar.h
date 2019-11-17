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
	Lista<string>listaIzvjestaja;
	int brojDanaZaKoristenjeAuta;
	int brojDostupnihAuta;
	int brojIznajmljenihAuta;

public:
	RentaCar() :
		listaKorisnika{}, listaAuta{}, listaIzvjestaja{}, brojDanaZaKoristenjeAuta{0}, brojDostupnihAuta{ 0 }, brojIznajmljenihAuta{ 0 }{};
	~RentaCar() {};

	void dodajKorisnika(Korisnik &k);
	int getBrojKorisnika();
	void printIdsAndImenaKorisnika();
	void printAllKorisnikInfo(Korisnik * korisnik);
	void printKorisniciKojiSuIznajmiliAutomobil();
	Korisnik *getKorisnikNaUnosClanskeKarte(int &unos);
	bool provjeriUsloveZaIznamjljivanjeAuta(Korisnik &korisnik);
	void vratiIznamljeniAutomobil(Korisnik &korisnik);
	void dodajAuto(Auto &a);
	void ispisiVozniPark();
	int getSizeOfListaAuta();
	int getUkupanBrojDostupnihAuta();

	void dodajIzvjestaj(string &izvjestaj);
	int izvrsiRezervaciju(Korisnik &korisnik,int &izbor);

	void setBrojDanaZaKoristenjeAuta();
	int getBrojKoristenihDana();

	void updateLoyalitiBodovi(Korisnik &korisnik,double Bodovi);

	int getBrojIzvjestaja();
	void printIzvjestaji();
};

