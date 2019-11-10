#include "Korisnik.h"



Korisnik::Korisnik(const char *_ime, const char *_prezime, const char *_adresa, const char *_grad) :
	ime{ nullptr }, prezime{ nullptr }, adresa{ nullptr }, grad{ nullptr }{
	this->ime = new char[20];
	strcpy_s(this->ime, 20, _ime);
	this->prezime = new char[30];
	strcpy_s(this->prezime, 30, _prezime);
	this->adresa = new char[50];
	strcpy_s(this->adresa, 50, _adresa);
	this->grad = new char[30];
	strcpy_s(this->grad, 30, _adresa);
}


Korisnik::~Korisnik() {
	delete[]ime; ime = nullptr;
	delete[]prezime; prezime = nullptr;
	delete[]adresa; adresa = nullptr;
	delete[]grad; grad = nullptr;
}

void Korisnik::setIme()
{
	this->ime = new char[20];
	cout << "Unesite ime korisnika: "; cin.getline(this->ime, 30);
}

void Korisnik::setPrezime()
{
	this->prezime = new char[30];
	cout << "Unesite prezime: "; cin.getline(this->prezime, 30);
}

void Korisnik::setAdresa()
{
	this->adresa = new char[50];
	cout << "Unesite adresu: "; cin.getline(this->adresa, 50);
}

void Korisnik::setGrad()
{
	this->grad = new char[30];
	cout << "Unesite grad: "; cin.getline(this->grad, 30);
}

char * Korisnik::getIme()
{
	return this->ime;
}

char * Korisnik::getPrezime()
{
	return this->prezime;
}

char * Korisnik::getAdresa()
{
	return this->adresa;
}

char * Korisnik::getGrad()
{
	return this->grad;
}