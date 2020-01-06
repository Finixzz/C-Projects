#include "Klub.h"

void Klub::setNaziv()
{
	cout << "Unesite naziv kluba: ";
	cin.getline(this->naziv, 50);
}

void Klub::setIgraci()
{
	for (int i = 0; i < 5; i++) {
		Igrac igrac;
		cin >> igrac;
		igraci.push_back(igrac);
	}
}

void Klub::setKlub()
{
	this->setNaziv();
	this->setIgraci();
}

char * Klub::getNaziv()
{
	return this->naziv;
}

vector<Igrac>& Klub::getIgraci()
{
	return this->igraci;
}

istream & operator>>(istream & in, Klub & k)
{
	k.setKlub();
	return in;
}

ostream & operator<<(ostream & os, Klub & k)
{
	return os;
}