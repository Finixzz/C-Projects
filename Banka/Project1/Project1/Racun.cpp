#include "Racun.h"

Racun::Racun() :
	korisnik{}, datumTransakcije{ nullptr }, iznosTransakcije{ nullptr }, stanjeRacuna{ nullptr }, brTransakcija{ 0 }, otvoren{ false }
{
	this->datumTransakcije = new Datum[50]{ "X" };
	this->iznosTransakcije = new float[50]{ 0 };
	this->stanjeRacuna = new float[50]{ 0 };
}


Racun::~Racun()
{
	delete[]datumTransakcije; datumTransakcije = nullptr;
	delete[]iznosTransakcije; iznosTransakcije = nullptr;
	delete[]stanjeRacuna; stanjeRacuna = nullptr;

}

void Racun::setBrRacuna()
{
	cout << "Unesite broj racuna: "; cin >> this->brRacuna;
	cin.clear(); cin.ignore(10000, '\n');
}

void Racun::setLimit()
{
	cout << "Unesite iznos limita: "; cin >> this->limit;
	cin.clear(); cin.ignore(10000, '\n');
}
int Racun::getBrTansakcija()
{
	return brTransakcija;
}
int Racun::getBrRacuna()
{
	return this->brRacuna;
}

void Racun::otvoriRacun()
{
	if (this->otvoren == false) {
		korisnik.setIme();
		korisnik.setPrezime();
		korisnik.setAdresa();
		korisnik.setGrad();
		this->setBrRacuna();
		this->setLimit();
		this->otvoren = true;
	}
	else
		cout << "Racun vec postoji! " << endl;

}

void Racun::setUplata()
{
	Boja oboji;
	this->datumTransakcije[brTransakcija].setDatum();
	cout << "Unesite iznos prvobitne uplate: "; cin >> this->iznosTransakcije[brTransakcija];
	if (brTransakcija != 0)
		this->stanjeRacuna[brTransakcija] = this->stanjeRacuna[brTransakcija - 1] + this->iznosTransakcije[brTransakcija];
	else
		this->stanjeRacuna[brTransakcija] = this->stanjeRacuna[brTransakcija] + this->iznosTransakcije[brTransakcija];
	cin.clear(); cin.ignore(10000, '\n');
	this->brTransakcija++;
	oboji.setZelena(); cout << "Novac uspjesno stavljen na racun! Za provjeru odaberite opciju 4! " << endl; oboji.setDefault();

}

void Racun::setIsplata()
{
	Boja oboji;
	if (brTransakcija) {
		this->datumTransakcije[brTransakcija].setDatum();
		cout << "Unesite iznos za isplatu: ";

		cin >> this->iznosTransakcije[brTransakcija];
		if (this->stanjeRacuna[brTransakcija - 1] - this->iznosTransakcije[brTransakcija] < -this->limit) {
			oboji.setCrvena(); cout << "Nije moguce podignuti toliki novac! " << endl; oboji.setDefault();
			return;
		}
		this->iznosTransakcije[brTransakcija] *= -1;
		if (brTransakcija != 0)
			this->stanjeRacuna[brTransakcija] = this->stanjeRacuna[brTransakcija - 1] + this->iznosTransakcije[brTransakcija];
		else
			this->stanjeRacuna[brTransakcija] = this->stanjeRacuna[brTransakcija] + this->iznosTransakcije[brTransakcija];

		this->brTransakcija++;
		oboji.setZelena(); cout << "Novac uspjesno podignut! Za provjeru odaberite opciju 4! " << endl; oboji.setDefault();
		return;
	}
	else
		oboji.setCrvena(); cout << "Da udete u minus morate imati bar jednu uplatu na racunu! Odaberite prvo opciju 2!" << endl; oboji.setDefault();
}


void Racun::printTransakcije()
{
	Boja oboji;
	system("cls");
	cout << "\n**************************************************************************\n";
	cout << "Broj racuna: " << this->getBrRacuna();
	cout << "\nKorisnik: " << this->korisnik.getIme() << " "
		<< this->korisnik.getPrezime();
	cout << "\n-------------------------------------------------------------------------\n";
	cout.width(6); cout << "R. br.";
	cout.width(20); cout << "Datum transakcije";
	cout.width(23); cout << "Iznos transakcije";
	cout.width(24); cout << "Stanje raèuna";
	cout << "\n-------------------------------------------------------------------------\n";
	for (int i = 0; i < this->brTransakcija; i++) {
		cout.width(6); cout << i + 1;
		cout.width(20); cout << this->datumTransakcije[i].getDatum();
		cout.width(20); cout << std::right << std::setprecision(2)
			<< std::fixed << this->iznosTransakcije[i] << " KM";
		if (this->stanjeRacuna[i] < 0) {
			oboji.setCrvena();
			cout.width(20); cout << std::right << std::setprecision(2)
				<< std::fixed << this->stanjeRacuna[i] << " KM\n";
			oboji.setDefault();
		}
		else {
			cout.width(20); cout << std::right << std::setprecision(2)
				<< std::fixed << this->stanjeRacuna[i] << " KM\n";
		}
	}
	cout << "\n**************************************************************************\n";

}
