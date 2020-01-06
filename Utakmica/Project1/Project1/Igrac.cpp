#include "Igrac.h"

void Igrac::setIme()
{
	cout << "Unesite ime igraca: ";
	cin.getline(this->ime, 25);
}

void Igrac::setPrezime()
{
	cout << "Unesite prezime: ";
	cin.getline(this->prezime, 25);
}

void Igrac::setBrKoseva(int brKoseva)
{
	this->brKoseva += brKoseva;
}

void Igrac::setPozicija()
{
	int unosIgraca;
	cout << "-----------------------\n";
	cout << "Unesite poziciju igraca\n";
	cout << "-----------------------\n";
	cout << "1)PG\n";
	cout << "2)SG\n";
	cout << "3)SF\n";
	cout << "4)F\n";
	cout << "5)C\n";
	cout << "-----------------------\n";
	cout << "Unesite izbor: "; cin >> unosIgraca;
	this->pozicija = Pozicija(unosIgraca);
	cin.clear(); cin.ignore(10000, '\n');
}

void Igrac::setIgrac()
{
	this->setIme();
	this->setPrezime();
	this->setPozicija();
}

char * Igrac::getIme()
{
	return this->ime;
}

char * Igrac::getPrezime()
{
	return this->prezime;
}

int Igrac::getBrKoseva()
{
	return this->brKoseva;
}

int Igrac::getPozicija()
{
	return this->pozicija;
}

void Igrac::printPozicija()
{
	if (this->pozicija == sg)
		cout << "SG\n";
	if (this->pozicija == pg)
		cout << "PG\n";
	if (this->pozicija == sf)
		cout << "SF\n";
	if (this->pozicija == f)
		cout << "F\n";
	if (this->pozicija == c)
		cout << "C\n";



}

ostream & operator<<(ostream & os, Igrac & i)
{
	os << "--------------MVP--------------------\n";
	os << i.getIme() << " " << i.getPrezime() << endl;
	os << "Pozicija: "; i.printPozicija();
	os << "Broj poena: " << i.getBrKoseva() << endl;
	return os;
}

istream & operator>>(istream & in, Igrac & i)
{
	i.setIgrac();
	return in;
}