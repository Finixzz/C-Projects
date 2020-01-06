#include "Utakmica.h"

int Utakmica::brKosevaDomaci{ 0 };
int Utakmica::brKosevaGosti{ 0 };

void Utakmica::operator++()
{
	srand(time(0));
	int vrijednostKosa = rand() % 4;
	this->brKosevaDomaci += vrijednostKosa;
	int randIgrac = rand() % 5;
	this->domaci.getIgraci()[randIgrac].setBrKoseva(vrijednostKosa);
	if (vrijednostKosa == 0) {
		cout << this->domaci.getNaziv() << " " << this->getBrKosevaDomaci() << " : " << this->gosti.getNaziv() << " " << this->getBrKosevaGosti() << endl;
		cout << "Izgubljena lopa " << this->domaci.getNaziv() << endl;
	}
	else {
		cout << this->domaci.getNaziv() << " " << this->getBrKosevaDomaci() << " : " << this->gosti.getNaziv() << " " << this->getBrKosevaGosti() << endl;
		cout << this->domaci.getIgraci()[randIgrac].getIme() << " " << this->domaci.getIgraci()[randIgrac].getPrezime() << " " << vrijednostKosa << " poena\n";
	}
}

void Utakmica::operator++(int)
{
	srand(time(0));
	int vrijednostKosa = rand() % 4;
	this->brKosevaGosti += vrijednostKosa;
	int randIgrac = rand() % 5;
	this->gosti.getIgraci()[randIgrac].setBrKoseva(vrijednostKosa);
	if (vrijednostKosa == 0) {
		cout << this->domaci.getNaziv() << " " << this->getBrKosevaDomaci() << " : " << this->gosti.getNaziv() << " " << this->getBrKosevaGosti() << endl;
		cout << "Izgubljena lopa " << this->gosti.getNaziv() << endl;
	}
	else {
		cout << this->domaci.getNaziv() << " " << this->getBrKosevaDomaci() << " : " << this->gosti.getNaziv() << " " << this->getBrKosevaGosti() << endl;
		cout << this->gosti.getIgraci()[randIgrac].getIme() << " " << this->gosti.getIgraci()[randIgrac].getPrezime() << " " << vrijednostKosa << " poena\n";
	}
}

void Utakmica::operator!()
{
	int maxBrPoena = this->domaci.getIgraci()[0].getBrKoseva();
	int index = 0;
	for (int i = 0; i < 5; i++) {
		if (this->domaci.getIgraci()[i].getBrKoseva() > maxBrPoena) {
			maxBrPoena = this->domaci.getIgraci()[i].getBrKoseva();
			index = i;
		}
	}

	int maxBrPoena2 = this->gosti.getIgraci()[0].getBrKoseva();
	int index2 = 0;
	for (int i = 0; i < 5; i++) {
		if (this->gosti.getIgraci()[i].getBrKoseva() > maxBrPoena) {
			maxBrPoena2 = this->gosti.getIgraci()[i].getBrKoseva();
		}
	}
	if (maxBrPoena > maxBrPoena2)
		cout << this->domaci.getIgraci()[index] << endl;
	else
		cout << this->gosti.getIgraci()[index2] << endl;
}


void Utakmica::setDatumUtakmice()
{
	cout << "Unesite datum utakmice: ";
	cin.getline(this->datum, 15);
}

void Utakmica::setDomaci()
{
	cout << "Unesite podatke o domacem timu\n";
	domaci.setKlub();
}

void Utakmica::setGosti()
{
	cout << "Unesite podatke o gostujucem timu\n";
	gosti.setKlub();
}

void Utakmica::setUtakmica()
{
	this->setDatumUtakmice();
	this->setDomaci();
	this->setGosti();
}

char * Utakmica::getDatum()
{
	return this->datum;
}

Klub Utakmica::getDomaci()
{
	return this->domaci;
}

Klub Utakmica::getGosti()
{
	return this->gosti;
}

int Utakmica::getBrKosevaDomaci()
{
	return this->brKosevaDomaci;
}

int Utakmica::getBrKosevaGosti()
{
	return this->brKosevaGosti;
}

void Utakmica::pobjednik()
{
	cout << "---------------------------------\n";
	if (this->brKosevaDomaci > this->brKosevaGosti)
		cout << "POBLEDNIK: " << this->domaci.getNaziv() << endl;
	else
		cout << "POBJEDNIK: " << this->gosti.getNaziv() << endl;
	cout << "---------------------------------\n";
}

istream & operator>>(istream & in, Utakmica & u)
{
	u.setUtakmica();
	return in;
}