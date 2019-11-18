#pragma once
#include"Includes.h"
#include"RentaCar.h"
boja oboji;

void ispisiBrojStudentskogIndeksa() {
	oboji.setCrvena();
	cout << "------------------------------------------\n";
	cout << "            Broj indeksa: 53\n";
	cout << "------------------------------------------\n";
	oboji.setDefault();
}


int menu() {

	int izbor;
	do {
		ispisiBrojStudentskogIndeksa();
		oboji.setZelena();
		cout << "-------------------------------------------\n";
		oboji.setDefault();
		cout << "      RENT - A - CAR MAIN MENU\n";
		oboji.setZelena();
		cout << "-------------------------------------------\n";
		oboji.setDefault();
		cout << "0) Dodaj Automobil/e na stanje\n";
		cout << "1) Dodaj korisnika\n";
		cout << "2) Ispisi ukupan broj dostupnih automobila\n";
		cout << "3) Ispisi izvjestaje\n";
		cout << "4) Ispisi registrovane korisnike\n";
		cout << "5) Iznajmi automobil\n";
		cout << "6) Vrati iznajmljeni automobil\n";
		cout << "7) KRAJ\n";
		oboji.setZelena();
		cout << "-------------------------------------------\n";
		oboji.setDefault();
		cout << "Unesite izbor: "; cin >> izbor;
		while (!cin) {
			oboji.setCrvena();
			cout << "[POGRESAN UNOS!]" << endl;
			oboji.setDefault();
			cin.clear(); cin.ignore(10000, '\n');
			cout << "Unesite izbor: "; cin >> izbor;
		}
		cin.clear(); cin.ignore(10000, '\n');
		system("pause"); system("cls");
		return izbor;
	} while (1);
}
int side_menu() {

	int izbor;
	do {
		ispisiBrojStudentskogIndeksa();
		oboji.setZelena();
		cout << "------------------------------\n";
		oboji.setDefault();
		cout << "  RENT - A - CAR SIDE MENU\n";
		oboji.setZelena();
		cout << "------------------------------\n";
		oboji.setDefault();
		cout << "1) Pregledaj vozni park\n";
		cout << "2) Iznajmi automobil\n";
		cout << "3) BACK TO MAIN MENU\n";
		oboji.setZelena();
		cout << "------------------------------\n";
		oboji.setDefault();
		cout << "Unesite izbor: "; cin >> izbor;
		while (!cin) {
			oboji.setCrvena();
			cout << "[POGRESAN UNOS!]" << endl;
			oboji.setDefault();
			cin.clear(); cin.ignore(10000, '\n');
			cout << "Unesite izbor: "; cin >> izbor;
		}
		cin.clear(); cin.ignore(10000, '\n');
		return izbor;
	} while (1);
}

void sideAction(RentaCar &rent, Korisnik &n) {
	boja oboji;
	int izbor;
	do {
		izbor = side_menu();
		if (izbor == 3)
			break;
		if (izbor == 1) {
			if (rent.getUkupanBrojDostupnihAuta() == 0) {
				oboji.setCrvena();
				cout << "---------------------------------\n";
				cout << " Trenutno nema aktivnih vozila!" << endl;
				cout << "---------------------------------\n";
				oboji.setDefault();
			}
			else {
				rent.ispisiVozniPark();
			}
			system("pause"); system("cls");
		}
		if (izbor == 2) {
			if (rent.getUkupanBrojDostupnihAuta() == 0) {
				oboji.setCrvena();
				cout << "---------------------------------\n";
				cout << " Trenutno nema aktivnih vozila!" << endl;
				cout << "---------------------------------\n";
				oboji.setDefault();
				break;
			}
			else {
				int izborAuta;
				rent.ispisiVozniPark();
				oboji.setCrvena();
				cout << "[Unesite 0 ako vam ne pase izbor automobila]" << endl;
				oboji.setDefault();
				cout << "Unesite redni broj automobila za iznajmljivanje: ";
				cin >> izborAuta;
				if (izborAuta == 0)
					break;
				else {
					rent.izvrsiRezervaciju(n, izborAuta);
					break;
				}
				
					
			}
			system("pause"); system("cls");
		}
	} while (1);
}

