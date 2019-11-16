#include"Lista.h"
#include"RentaCar.h"
#include"Korisnik.h"
#include"Auto.h"
boja oboji;

int menu() {

	int izbor;
	do {
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
		oboji.setZelena();
		cout << "-------------------------------------------\n";
		oboji.setDefault();
		cout << "Unesite izbor: "; cin >> izbor; 
		cin.clear(); cin.ignore(10000, '\n');
		system("pause"); system("cls");
		return izbor;
	} while (1);
}
int side_menu() {

	int izbor;
	do {
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
		cin.clear(); cin.ignore(10000, '\n');
		return izbor;
	} while (1);
}

void sideAction(RentaCar &rent,int &izbor,Korisnik &n) {
	boja oboji;
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
			}
			else {
				int izborAuta;
				rent.ispisiVozniPark();
				oboji.setCrvena();
				cout << "[Unesite 0 ako vam ne pase izbor automobila]" << endl;
				oboji.setDefault();
				cout << "Unesite redni broj automobila za iznajmljivanje: ";
				cin >> izborAuta;
				rent.izvrsiRezervaciju(n,izborAuta);
			}
			system("pause"); system("cls");
		}
	} while (1);
}

int main() {


	RentaCar rent;
	int izbor;
	do {
		izbor = menu();
		if (izbor < 0)
			break;
		if (izbor == 0) {
			Auto *a = new Auto;
			a->setAuto();
			rent.dodajAuto(*a);
			system("pause"); system("cls");
		}
		if (izbor == 1) {
			Korisnik n;
			n.setKorisnik();
				rent.dodajKorisnika(n);
			system("pause"); system("cls");
				sideAction(rent, izbor,n);
			system("pause"); system("cls");
			
		}
		if (izbor == 2) {
			if (rent.getUkupanBrojDostupnihAuta() == 0) {
				oboji.setCrvena();
				cout << "---------------------------------\n";
				cout << " Trenutno nema aktivnih vozila!" << endl;
				cout << "---------------------------------\n";
				oboji.setDefault();
			}
			else {
				oboji.setZelena();
				cout << "------------------------------------------------------\n";
				oboji.setDefault();
				cout << "Trenutno se na stanju nalazi ukupno " << rent.getUkupanBrojDostupnihAuta() << " automobila" << endl;
				oboji.setZelena();
				cout << "------------------------------------------------------\n";
				oboji.setDefault();
			}
			system("pause"); system("cls");
		}
		if (izbor == 3) {
			if (rent.getBrojIzvjestaja() == 0) {
				oboji.setCrvena();
				cout << "---------------------------------\n";
				cout << "Trenutno nema aktivnih izvjestaja\n";
				cout << "---------------------------------\n";
				oboji.setDefault();
			}
			else {
				rent.printIzvjestaji();
			}
			system("pause"); system("cls");

		}
	} while (1);

	system("Pause");
	return 0;
}