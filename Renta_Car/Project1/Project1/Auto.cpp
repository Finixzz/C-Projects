#include "Auto.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;



void Auto::setMarka()
{
	this->marka.setNaziv();
	this->marka.setZemljaPorijekla();
}
void Auto::setBrojTakvihAuta() {
	cout << "Unesite koliko takvih auta ima na stanju: ";
	cin >> this->brojAuta;
}
void Auto::setDatumRegistracije() {
	boja oboji;
	oboji.setCrvena();
	cout << "-----------------------\n";
	oboji.setDefault();
	cout << "Unesite datum registracije\n";
	oboji.setCrvena();
	cout << "-----------------------\n";
	oboji.setDefault();
	this->datumRegistracije.postaviDatum();

}
void Auto::setTip()
{
	cout << "Unesite tip auta: ";
	getline(cin, this->tip);
}

void Auto::setGorivo()
{
	cout << "Unesite vrstu goriva: ";
	getline(cin,this->gorivo);
}

void Auto::setGodinaProizvodnje()
{
	cout << "Unesite godinu proizvodnje: ";
	cin >> this->godinaProizvodnje;
	cin.clear(); cin.ignore(10000, '\n');
}

void Auto::setBrojBrzina()
{
	cout << "Unesite broj brzina: ";
	cin >> this->brojBrzina;
	cin.clear(); cin.ignore(10000, '\n');
}

Marka Auto::getMarka()
{
	return this->marka;
}

string Auto::getTip()
{
	return this->tip;
}

string Auto::getGorivo()
{
	return this->gorivo;
}
int Auto::getBrojAutaTogTipa() {
	return this->brojAuta;
}

int Auto::getGodinaProizvodnje()
{
	return this->godinaProizvodnje;
}

int Auto::getBrojBrzina()
{
	return this->brojBrzina;
}

void Auto::setCijenaPoDanu() {
	cout << "Unesite cijenu rentanja po danu[KM]: "; cin >> this->cijenaPoDanu;
}
double Auto::getCijenaPoDanu() {
	return this->cijenaPoDanu;
}

void Auto::setAuto()
{
	boja oboji;
	oboji.setCrvena();
	cout << "----------------------\n";
	oboji.setDefault();
	cout << "Unesite podatke o autu\n";
	oboji.setCrvena();
	cout << "----------------------\n";
	oboji.setDefault();
	this->setMarka();
	this->setBrojTakvihAuta();
	this->setCijenaPoDanu();
	this->setDatumRegistracije();
	this->setTip();
	this->setGorivo();
	this->setGodinaProizvodnje();
	this->setBrojBrzina();
}


void Auto::printAutoInfo() {
	boja oboji;
	cout << this->getMarka().getNaziv()
		<< " " << this->getTip() << " proizvedeno u "
		<< this->getMarka().getZemljaPorijekla()
		<< " " << this->getGodinaProizvodnje()
		<< " godine"<< ", registrovano dana ";
		this->datumRegistracije.ispisiDatum();
		cout << " i ima ukupno " << this->getBrojBrzina() << " brzina, " <<
		"na stanju trenutno dostupno " << this->getBrojAutaTogTipa() <<" takvih Auta"<< endl;
		cout << "Cijena po danu: " << this->getCijenaPoDanu();
}
