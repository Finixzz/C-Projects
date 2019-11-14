#include "Marka.h"
#include <iostream>
#include <string>
using std::cout;
using std::cin;


void Marka::setNaziv()
{
	string nazivTemp;
	cout << "Unesite naziv marke: ";
	getline(cin, this->naziv);
}

void Marka::setZemljaPorijekla()
{
	cout << "Unesite zemlju porijekla auta: ";
	getline(cin, this->zemljaPorijekla);
}

string Marka::getNaziv()
{
	return this->naziv;
}

string Marka::getZemljaPorijekla()
{
	return this->zemljaPorijekla;
}
