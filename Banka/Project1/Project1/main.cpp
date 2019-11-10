#include"Includes.h"
#include"Racun.h"

Boja oboji;

int menu() {
	int izbor;
	do {
		cout << "----------------------------\n";
		cout << "         MENU \n";
		cout << "----------------------------\n";
		cout << "1) Kreiraj racun\n";
		cout << "2) Uplati novac na racun\n";
		cout << "3) Podigini novac sa racuna\n";
		cout << "4) Ispisi transakcije\n";
		cout << "5) KRAJ\n";
		cout << "----------------------------\n";
		cout << "Unesite izbor: "; cin >> izbor;
		cin.clear(); cin.ignore(10000, '\n');
		return izbor;
	} while (1);
}
void provjeriUnosRacunIda(shared_ptr<Racun[]>niz, int &broj_racuna) {
	for (int i = 0; i < broj_racuna; i++) {
		if (i != broj_racuna) {
			while (niz[i].getBrRacuna() == niz[broj_racuna].getBrRacuna()) {
				cout << "Uneseni broj racuna vec postoji! \n";
				niz[broj_racuna].setBrRacuna();
			}
		}
	}
}
bool printRacuni(shared_ptr<Racun[]>niz, int &broj_racuna) {
	Boja oboji;
	if (broj_racuna) {
		cout << "------------------------------\n";
		cout << " BROJEVI REGISTROVANIH RACUNA\n";
		cout << "------------------------------\n";
		for (int i = 0; i < broj_racuna; i++) {
			oboji.setCrvena();
			cout << "R.BR[" << i + 1 << "]";
			oboji.setDefault();
			cout << " - " << "id RACUNA[" << niz[i].getBrRacuna() << "]" << endl;
		}
		cout << "------------------------------\n";
		return true;
	}
	else {
		oboji.setCrvena(); cout << "Trenutno nema registrovanih racuna! Odaberite prvo opciju 1" << endl; oboji.setDefault();
		return false;
	}

}
void printForInput() {
	cout << "Unesite";
	oboji.setCrvena();
	cout << " REDNI BROJ ";
	oboji.setDefault();
	cout << "racuna: ";
}
void printForFailedInput() {
	oboji.setCrvena();
	cout << "POGRESAN UNOS! " << endl;
	oboji.setDefault();
	cout << "Unesite";
	oboji.setCrvena();
	cout << " REDNI BROJ ";
	oboji.setDefault();
	cout << "racuna: ";
}
void uplatiNovacNaRacun(shared_ptr<Racun[]>niz, int &broj_racuna) {
	if (printRacuni(niz, broj_racuna)) {
		int izbor;
		printForInput();
		cin >> izbor;
		izbor--;
		while (!cin || izbor<0 || izbor>broj_racuna) {
			cin.clear(); cin.ignore(10000, '\n');
			printForFailedInput();
			cin >> izbor;
			izbor--;
		}
		cin.clear(); cin.ignore(10000, '\n');
		niz[izbor].setUplata();
	}
}
void podigniNovacSaRacuna(shared_ptr<Racun[]>niz, int &broj_racuna) {
	if (printRacuni(niz, broj_racuna)) {
		int izbor;
		printForInput();
		cin >> izbor;
		izbor--;
		while (!cin || izbor<0 || izbor>broj_racuna) {
			cin.clear(); cin.ignore(10000, '\n');
			printForFailedInput();
			cin >> izbor;
			izbor--;
		}
		cin.clear(); cin.ignore(10000, '\n');
		niz[izbor].setIsplata();
	}
}
void prikaziTransakcije(shared_ptr<Racun[]>niz, int &broj_racuna) {
	if (printRacuni(niz, broj_racuna)) {
		int izbor;
		printForInput();
		cin >> izbor;
		izbor--;
		while (!cin || izbor<0 || izbor>broj_racuna) {
			cin.clear(); cin.ignore(10000, '\n');
			printForFailedInput();
			cin >> izbor;
			izbor--;
		}
		cin.clear(); cin.ignore(10000, '\n');
		if (niz[izbor].getBrTansakcija())
			niz[izbor].printTransakcije();
		else
			cout << "Trenutno nema aktivnih transakcija, odaberite prvo opciju 1 ili 2!!" << endl;
	}
}

int main() {

	setlocale(LC_ALL, "");
	shared_ptr<Racun[]>r = shared_ptr<Racun[]>(new Racun[100], [](Racun *i) {delete[]i; });
	static int brojRacuna{ 0 };
	int izbor;
	do {
		izbor = menu();
		if (izbor < 1 || izbor>4)
			break;
		if (izbor == 1) {
			r[brojRacuna].otvoriRacun();
			provjeriUnosRacunIda(r, brojRacuna);
			brojRacuna++;
			system("pause"); system("cls");
		}
		if (izbor == 2) {
			uplatiNovacNaRacun(r, brojRacuna);
			system("pause"); system("cls");
		}
		if (izbor == 3) {
			podigniNovacSaRacuna(r, brojRacuna);
			system("pause"); system("cls");
		}
		if (izbor == 4) {
			prikaziTransakcije(r, brojRacuna);
			system("pause"); system("cls");
		}
	} while (1);


	system("pause");
	return 0;
}