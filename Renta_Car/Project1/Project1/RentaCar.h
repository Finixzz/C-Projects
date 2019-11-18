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
	void printIdsAndImenaKorisnika();
	void printAllKorisnikInfo(Korisnik *);
	void printKorisniciKojiSuIznajmiliAutomobil();
	bool provjeriUsloveZaIznamjljivanjeAuta(Korisnik &);
	void vratiIznamljeniAutomobil(Korisnik &);
	void dodajAuto(Auto &);
	void ispisiVozniPark();
	void dodajIzvjestaj(string &);
	void setBrojDanaZaKoristenjeAuta();
	void updateLoyalitiBodovi(Korisnik &, double);
	void printIzvjestaji();

	int getBrojKorisnika();
	int getSizeOfListaAuta();
	int getUkupanBrojDostupnihAuta();
	Korisnik *getKorisnikNaUnosClanskeKarte(int &);
	int izvrsiRezervaciju(Korisnik &,int &);
	int getBrojKoristenihDana();
	int getBrojIzvjestaja();
};

