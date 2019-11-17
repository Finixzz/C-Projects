#include"Lista.h"
#include"RentaCar.h"
#include"Korisnik.h"
#include"Auto.h"
#include"menu_section.h"


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
			Korisnik *n=new Korisnik;
			n->setKorisnik();
			system("pause"); system("cls");
				sideAction(rent,*n);
			rent.dodajKorisnika(*n);
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
						cout << "Za iznamljivanje novog auta, vratite vec iznamljeno auto\n!";
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