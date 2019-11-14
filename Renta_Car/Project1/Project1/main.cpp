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
void sideAction(RentaCar &rent,int &izbor) {
	do {
		izbor = side_menu();
		if (izbor == 3)return;
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
				sideAction(rent, izbor);
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
				cout<<"Trenutno se na stanju nazali ukupno "<<
					rent.getUkupanBrojDostupnihAuta() << endl;
			}
			system("pause"); system("cls");
		}
	} while (1);

	system("Pause");
	return 0;
}