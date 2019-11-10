#include "Datum.h"

Datum::Datum(const char *_datum) :
	datum{ nullptr } {
	this->datum = new char[12];
	strcpy_s(this->datum, 12, _datum);
}


Datum::~Datum() {
	delete[]datum; datum = nullptr;
}

char * Datum::getDatum()
{
	return datum;
}

void Datum::setDatum()
{
	datum = new char[12];
	cin.clear();
	cout << "Unesite datum: "; cin.getline(datum, 11);
}