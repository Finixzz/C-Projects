#include "Datum.h"
#include"Includes.h"

Datum::Datum()
{
	this->dan = 1;
	this->mjesec = 1;
	this->godina = 1900;
}

void Datum::setDan()
{
	switch (this->mjesec) {
	case 1: case 3: case 5: case 7: case 8: case 10: case 12:
		do {
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan > 31) {
				cout << "[ERROR] " << this->mjesec << ". mjesec ima samo 31 dan.\n";
			}
			else if (this->dan < 1) {
				cout << "[ERROR] Dan u datumu ne moze biti 0 ili negativan.\n";
			}
		} while (this->dan < 1 || this->dan>31);
		cin.ignore();
		break;
	case 2:
		if (this->godina % 4 == 0) {
			do {
				cout << "Unesite dan: ";
				cin >> this->dan;
				if (this->dan > 29) {
					cout << "[ERROR] Prestupna godina, " << this->mjesec << ". mjesec ima samo 29 dana.\n";
				}
				else if (this->dan < 1) {
					cout << "[ERROR] Dan u datumu ne moze biti 0 ili negativan.\n";
				}
			} while (this->dan < 1 || this->dan>29);
		}
		else {
			do {
				cout << "Unesite dan: ";
				cin >> this->dan;
				if (this->dan > 28) {
					cout << "[ERROR] Nije prestupna godina, " << this->mjesec << ". mjesec ima samo 28 dana.\n";
				}
				else if (this->dan < 1) {
					cout << "[ERROR] Dan u datumu ne moze biti 0 ili negativan.\n";
				}
			} while (this->dan < 1 || this->dan>28);
		}
		cin.ignore();
		break;
	case 4: case 6: case 9: case 11:
		do {
			cout << "Unesite dan: ";
			cin >> this->dan;
			if (this->dan > 30) {
				cout << "[ERROR] " << this->mjesec << ". mjesec ima samo 30 dana.\n";
			}
			else if (this->dan < 1) {
				cout << "[ERROR] Dan u datumu ne moze biti 0 ili negativan.\n";
			}
		} while (this->dan < 1 || this->dan>30);
		cin.ignore();
		break;
	default:
		cout << "Pogresan mjesec!\n";
		break;
	}
}

void Datum::setMjesec()
{
	do {
		cout << "Unesite mjesec: ";
		cin >> this->mjesec;
		if (this->mjesec < 1 || this->mjesec>12) {
			cout << "[ERROR] Pogresan unos mjeseca!\n";
		}
	} while (this->mjesec < 1 || this->mjesec>12);
	cin.ignore();
}

void Datum::setGodina()
{
	do {
		cout << "Unesite godinu: ";
		cin >> this->godina;
		if (this->godina < 1900) {
			cout << "[ERROR] Pogresno unesena godina!\n";
		}
	} while (this->godina < 1900);
	cin.ignore();
}

int Datum::getDan()
{
	return this->dan;
}

int Datum::getMjesec()
{
	return this->mjesec;
}

int Datum::getGodina()
{
	return this->godina;
}

void Datum::postaviDatum()
{
	this->setGodina();
	this->setMjesec();
	this->setDan();
}

void Datum::ispisiDatum()
{
	cout << this->dan << "." << this->mjesec << "." << this->godina << ".";
}

Datum::~Datum() {}