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
	listaAuta.dodaj(a);
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
	for (int i = 0; i < this->getBrojAuta(); i++) {
		cout << i + 1 << ". ";
		listaAuta.getClanSaIndexa(i).printAutoInfo();
		oboji.setCrvena();
		cout << " -----------------------------------------------------------------------------------------------------------------------------------------------\n";
		oboji.setDefault();
		cout << endl;
	}
		
}

int RentaCar::getBrojAuta()
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