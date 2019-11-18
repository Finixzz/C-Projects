#pragma once
#include "Marka.h"
#include"Includes.h"
#include"Datum.h"
class Auto{
	Marka marka;
	Datum datumRegistracije;
	string tip, gorivo;
	int godinaProizvodnje;
	int brojBrzina;
	int brojAuta;
	double cijenaPoDanu;
public:
	Auto():
		marka{}, tip{ "empty" }, datumRegistracije{},gorivo{ "empty" },
		godinaProizvodnje{ 2000 }, brojBrzina{ 6 },
		brojAuta{ 0 },cijenaPoDanu{ 0 }{}
	~Auto() {};

	void setMarka();
	void setBrojTakvihAuta();
	void jeIznajmljeno();
	void jeVraceno();
	void setDatumRegistracije();
	void setTip();
	void setGorivo();
	void setGodinaProizvodnje();
	void setBrojBrzina();
	void setCijenaPoDanu();
	void setAuto();
	void printAutoInfo();

	Marka getMarka();
	string getTip();
	string getGorivo();
	int getGodinaProizvodnje();
	int getBrojBrzina();
	int getBrojAutaTogTipa();
	double getCijenaPoDanu();
};
