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
		cout << "4) Ispisi registrovane korisnike\n";
		cout << "5) Iznajmi automobil\n";
		cout << "6) Vrati iznajmljeni automobil\n";
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
				if (!rent.izvrsiRezervaciju(n, izborAuta)) {
					oboji.setCrvena();
					cout << "------------------------------------------------------\n";
					oboji.setDefault();
					cout << "Za iznamljivanje novog auta, vratite vec iznamljeno auto!";
					oboji.setCrvena();
					cout << "------------------------------------------------------\n";
					oboji.setDefault();
				}
			}
			system("pause"); system("cls");
		}
	} while (1);
}

int main() {


	RentaCar rent;
	int izbor;
LOOP:do {
		izbor = menu();

		if (izbor < 0)
			break;

		else

		if (izbor == 0) {
			Auto *a = new Auto;
			a->setAuto();
			rent.dodajAuto(*a);
			system("pause"); system("cls");
		}

		else

		if (izbor == 1) {
			Korisnik n;
			n.setKorisnik();
				rent.dodajKorisnika(n);
			system("pause"); system("cls");
				sideAction(rent, izbor,n);
			system("pause"); system("cls");
			
		}

		else

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

		else

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

		else

		if (izbor == 4) {
			if (rent.getBrojKorisnika() == 0) {
				oboji.setCrvena();
				cout << "-------------------------------------\n";
				cout << "Trenutno nema registrovanih korisnika\n";
				cout << "-------------------------------------\n";
				oboji.setDefault();
			}
			else {
				rent.printIdsAndImenaKorisnika();
				int unos;
				cout << "Za ispish svih informacija unesite broj clanske karte: "; cin >> unos;
				while (!rent.getKorisnikNaUnosClanskeKarte(unos)) {
					oboji.setCrvena();
					cout << "[POGRESAN UNOS!]" << endl;
					oboji.setDefault();
					cout << "Unesite broj clanske kartice: "; cin >> unos;
				}
				Korisnik *korisnik = rent.getKorisnikNaUnosClanskeKarte(unos);
				rent.printAllKorisnikInfo(korisnik);
			}
			system("pause"); system("cls");
		}

		else

		if (izbor == 5) {
			if (rent.getBrojKorisnika() == 0) {
				oboji.setCrvena();
				cout << "-------------------------------------\n";
				cout << "Trenutno nema registrovanih korisnika\n";
				cout << "-------------------------------------\n";
				oboji.setDefault();
			}
			else {
				rent.printIdsAndImenaKorisnika();
				int unos;
				cout << "Unesite broj clanske karte za iznajmljivanje: "; cin >> unos;
				while (!rent.getKorisnikNaUnosClanskeKarte(unos)) {
					oboji.setCrvena();
					cout << "[POGRESAN UNOS!]" << endl;
					oboji.setDefault();
					cout << "Unesite broj clanske kartice: "; cin >> unos;
				}
				Korisnik &korisnik = *rent.getKorisnikNaUnosClanskeKarte(unos);
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
					if (izborAuta == 0) {
						system("pause"); system("cls");
						goto LOOP;
					}
					
					else

					if (!rent.izvrsiRezervaciju(korisnik, izborAuta)) {
						oboji.setCrvena();
						cout << "------------------------------------------------------\n";
						oboji.setDefault();
						cout << "Za iznamljivanje novog auta, vratite vec iznamljeno auto!";
						oboji.setCrvena();
						cout << "------------------------------------------------------\n";
						oboji.setDefault();
					}
				}
			}
			system("pause"); system("cls");
		}

		else

		if (izbor == 6) {
			if (rent.getBrojKorisnika() == 0) {
				oboji.setCrvena();
				cout << "-------------------------------------\n";
				cout << "Trenutno nema registrovanih korisnika\n";
				cout << "-------------------------------------\n";
				oboji.setDefault();
			}
			else {
				try {
					rent.printKorisniciKojiSuIznajmiliAutomobil();
					int unos;
					cout << "Unesite broj clanske karte za iznajmljivanje: "; cin >> unos;
					while (!rent.getKorisnikNaUnosClanskeKarte(unos)) {
						oboji.setCrvena();
						cout << "[POGRESAN UNOS!]" << endl;
						oboji.setDefault();
						cout << "Unesite broj clanske kartice: "; cin >> unos;
					}
					Korisnik &korisnik = *rent.getKorisnikNaUnosClanskeKarte(unos);
					rent.vratiIznamljeniAutomobil(korisnik);
				}
				catch (...) {
					cout << " Niti jedan korisnik nije zaduzio automobil\n";
					oboji.setCrvena();
					cout << "---------------------------------------------\n";
					oboji.setDefault();
				}
				
			}
			system("pause"); system("cls");
		}
	} while (1);

	system("Pause");
	return 0;
}