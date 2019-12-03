#include "Stvar.h"

int Stvar::brStvari{ 0 };

Stvar::Stvar(const char * _naziv, int _kolicina):
	naziv{nullptr},kolicina{_kolicina}
{
	this->naziv = new char[strlen(_naziv)];
	strcpy_s(this->naziv,strlen(this->naziv), _naziv);
}

Stvar::~Stvar()
{
	delete[]naziv; this->naziv = nullptr;
}

void Stvar::setNazivStvari()
{
	this->naziv = new char[50];
	cout << "Unesite naziv stvari: "; cin.getline(this->naziv, 50);

}

void Stvar::setKolicinaStvari()
{
	cout << "Unesite kolicinu stvari: "; cin >> this->kolicina;
	this->brStvari += this->kolicina;
	cin.clear(); cin.ignore(1000, '\n');
}

void Stvar::unesiStvar()
{
	this->setNazivStvari();
	this->setKolicinaStvari();
}

void Stvar::povecajKolicinu(int x)
{
	this->kolicina += x;
	this->brStvari += x;
}

void Stvar::smanjiKolicinu(int x)
{
	this->kolicina -= x;
	this->brStvari -= x;
}

char * Stvar::getNazivStvari()
{
	return this->naziv;
}

int Stvar::getKolicinaStvari()
{
	return this->kolicina;
}


