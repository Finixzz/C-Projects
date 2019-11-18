#include "RentaCar.h"

void RentaCar::dodajKorisnika(Korisnik &k)
{
	this->listaKorisnika.dodaj(k);
}

int RentaCar::getBrojKorisnika()
{
	return this->listaKorisnika.getDuzina();
}

void RentaCar::printIdsAndImenaKorisnika()
{
	boja oboji;
	oboji.setCrvena();
	cout << "---------------------------\n";
	oboji.setDefault();
	cout << "   REGISTROVANI KORISNICI\n";
	oboji.setCrvena();
	cout << "---------------------------\n";
	oboji.setDefault();
	for (int i = 0; i < this->getBrojKorisnika(); i++) {
		oboji.setCrvena(); cout << listaKorisnika.getClanSaIndexa(i).getKartica().getBrojKartice(); oboji.setDefault();cout<< " , " << listaKorisnika.getClanSaIndexa(i).getImePrezime() << endl;
	}
	oboji.setCrvena();
	cout << "---------------------------\n";
	oboji.setDefault();
}



void RentaCar::printAllKorisnikInfo(Korisnik *korisnik)
{
	korisnik->printKorisnikInfo();
}

void RentaCar::printKorisniciKojiSuIznajmiliAutomobil()
{
	int uslov_zadovoljen=0;
	boja oboji;
	oboji.setCrvena();
	cout << "---------------------------------------------\n";
	oboji.setDefault();
	cout << " LISTA KORISNIKA KOJI SU ZADUZILI AUTOMOBILE\n";
	oboji.setCrvena();
	cout << "---------------------------------------------\n";
	oboji.setDefault();
	for (int i = 0; i < this->getBrojKorisnika(); i++) {
		if (listaKorisnika.getClanSaIndexa(i).getBrojIznamljenihAuta() != 0) {
			oboji.setCrvena(); cout << listaKorisnika.getClanSaIndexa(i).getKartica().getBrojKartice(); oboji.setDefault(); cout << " , " << listaKorisnika.getClanSaIndexa(i).getImePrezime() << endl;
			uslov_zadovoljen++;
		}
	}
	if (uslov_zadovoljen == 0)
		throw 0;
	oboji.setCrvena();
	cout << "---------------------------------------------\n";
	oboji.setDefault();
}

Korisnik *RentaCar::getKorisnikNaUnosClanskeKarte(int &unos)
{
	for (int i = 0; i < this->getBrojKorisnika(); i++) {
		if (listaKorisnika.getClanSaIndexa(i).getKartica().getBrojKartice() == unos)
			return &listaKorisnika.getClanSaIndexa(i);
	}
	return NULL;
}

bool RentaCar::provjeriUsloveZaIznamjljivanjeAuta(Korisnik & korisnik)
{
	if (korisnik.getBrojIznamljenihAuta() == 1)
		return false;
	else
		return true;
}

void RentaCar::vratiIznamljeniAutomobil(Korisnik & korisnik)
{
	boja oboji;
	int index;
	for (int i = 0; i < getSizeOfListaAuta(); i++) {
		if (korisnik.getObjekatIznajmljenoAuto().getMarka().getNaziv() == listaAuta.getClanSaIndexa(i).getMarka().getNaziv()) {
			listaAuta.getClanSaIndexa(i).jeVraceno();
			index = i;
		}
	}
	korisnik.vratiIznajmjenoAuto();
	string izvjestaj = korisnik.getImePrezime()+" je vratio automobil marke " + listaAuta.getClanSaIndexa(index).getMarka().getNaziv();
	this->dodajIzvjestaj(izvjestaj);
	oboji.setCrvena();
	cout << "---------------------------------------------------\n";
	oboji.setDefault();
	cout << izvjestaj << endl;
	oboji.setCrvena();
	cout << "---------------------------------------------------\n";

}


void RentaCar::dodajAuto(Auto &a)
{
	this->listaAuta.dodaj(a);
}

void RentaCar::dodajIzvjestaj(string &izvjestaj) {
	this->listaIzvjestaja.dodaj(izvjestaj);
}

void RentaCar::ispisiVozniPark()
{
	boja oboji;
	oboji.setZelena();
	cout << " -----------------------------------------------------------------------------------------------------------------------------------------------\n";
	oboji.setDefault();
	cout << "                                                                    RENT - A - CAR PARK" << endl;
	oboji.setZelena();
	cout << " -----------------------------------------------------------------------------------------------------------------------------------------------\n";
	oboji.setDefault();
	for (int i = 0; i < this->getSizeOfListaAuta(); i++) {
		oboji.setCrvena();
		cout << "[" << i + 1 << ".]";
		oboji.setDefault();
		listaAuta.getClanSaIndexa(i).printAutoInfo();
		oboji.setCrvena();
		cout << " -----------------------------------------------------------------------------------------------------------------------------------------------\n";
		oboji.setDefault();
		cout << endl;
	}
}

int RentaCar::getSizeOfListaAuta()
{
	return listaAuta.getDuzina();
}


int RentaCar::getUkupanBrojDostupnihAuta() {
	this->brojDostupnihAuta = 0;
	for (int i = 0; i < listaAuta.getDuzina(); i++) {
		this->brojDostupnihAuta += listaAuta.getClanSaIndexa(i).getBrojAutaTogTipa();
	}
	return this->brojDostupnihAuta;
}

void RentaCar::updateLoyalitiBodovi(Korisnik &k, double Bodovi)
{
	k.setLoyalitiBodovi(Bodovi);
}


int RentaCar::getBrojIzvjestaja()
{
	return this->listaIzvjestaja.getDuzina();
}

void RentaCar::printIzvjestaji()
{
	boja oboji;
	for (int i = 0; i < this->getBrojIzvjestaja(); i++) {
		oboji.setZelena();
		cout << "----------------------------------------------------\n";
		oboji.setDefault();
		cout << i + 1 << ". " << listaIzvjestaja.getClanSaIndexa(i) << endl;
		oboji.setZelena();
		cout << "----------------------------------------------------\n";
		oboji.setDefault();
	}
}


int RentaCar::izvrsiRezervaciju(Korisnik &korisnik,int & izborAuta)
{
	boja oboji;
	izborAuta--;
	if (izborAuta < 0)
		return -1;
	while (izborAuta >= this->getSizeOfListaAuta() || listaAuta.getClanSaIndexa(izborAuta).getBrojAutaTogTipa()==0) {
		oboji.setCrvena(); cout << "[POGRESAN UNOS]" << endl; oboji.setDefault();
		cout << "Unesite redni broj automobila za iznajmljivanje: ";
		cin >> izborAuta;
		izborAuta--;
	}

	if (!this->provjeriUsloveZaIznamjljivanjeAuta(korisnik))
		return 0;
		
	korisnik.dodajIznajmjenoAuto(listaAuta.getClanSaIndexa(izborAuta));
	listaAuta.getClanSaIndexa(izborAuta).jeIznajmljeno();
	this->setBrojDanaZaKoristenjeAuta();

	string izvjestaj;
	izvjestaj = korisnik.getImePrezime() + " je iznajmio " + listaAuta.getClanSaIndexa(izborAuta).getMarka().getNaziv() + " na ukupno " + to_string(this->getBrojKoristenihDana()) + " dana";
	double cijenaUsluge = this->listaAuta.getClanSaIndexa(izborAuta).getCijenaPoDanu()*this->brojDanaZaKoristenjeAuta;
	oboji.setCrvena();
	cout << "----------------------------\n";
	oboji.setDefault();
	cout << "Ukupno za platit: " << cijenaUsluge << " [KM]" << endl;
	oboji.setCrvena();
	cout << "----------------------------\n";
	oboji.setDefault();
	this->dodajIzvjestaj(izvjestaj);
	this->updateLoyalitiBodovi(korisnik, cijenaUsluge / 100);
	return 1;
}

void RentaCar::setBrojDanaZaKoristenjeAuta()
{
	cout << "Unesite na koliko dana zelite da iznajmite automobil: ";
	cin >> this->brojDanaZaKoristenjeAuta;
}

int RentaCar::getBrojKoristenihDana()
{
	return this->brojDanaZaKoristenjeAuta;
}



