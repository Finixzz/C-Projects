#pragma once
#include"Includes.h"
#include"I_Lista.h"
template<class T>
class Lista : public I_Lista <T>{
private:
	struct cvor {
		T element;
		cvor *sljedeci;
		cvor():
			element{},sljedeci{NULL}{}
	};
	cvor *pocetak, *kraj, *tekuci;
	 int duzinaListe;
public:
	Lista():
		pocetak{ NULL }, kraj{ NULL }, tekuci{ NULL }, duzinaListe{ 0 }{}
	virtual ~Lista() {
		if (duzinaListe == 0)return;
		else {
			while (pocetak) {
				tekuci = pocetak->sljedeci;
				free(pocetak);
				pocetak = tekuci;
			}
		}
	}

	void dodaj(T &element) override;
	void dodajNaIndex(T &element, int &index) override;
	void obrisi()override;
	void obrisiSaIndexa(int &index)override;
	int getDuzina() override;
	T  &getClanSaIndexa(int &index)override;
	T &getClan()override;

};

template<class T>
void Lista<T>::dodaj(T &element) {
	cvor *novi_clan = new cvor;
	novi_clan->element = element;
	novi_clan->sljedeci = nullptr;
	if (novi_clan) {//Da li postoji element na hrpi, ako da ..
		if (pocetak == NULL) {
			this->pocetak = novi_clan;
			this->kraj = novi_clan;
		}
		else {
			this->kraj->sljedeci = novi_clan;
			this->kraj = novi_clan;
		}
		this->duzinaListe++;
	}
	else {
		return;
	}
}

template<class T>
void Lista<T>::dodajNaIndex(T &element, int &index) {
	boja oboji;
	cvor *novi_clan = new cvor;
	novi_clan->element = element;
	novi_clan->sljedeci = nullptr;
	if (index < 0 || index >= duzinaListe) {
		oboji.setCrvena();
		cout << "[INDEX ERROR]" << endl;
		oboji.setDefault();
		return;
	}
	if (novi_clan) {
		if (index == 0) {
			novi_clan->sljedeci = pocetak;
			pocetak = novi_clan;
		}
		else if (index == duzinaListe - 1) {
			kraj->sljedeci = novi_clan;
			kraj = novi_clan;
		}
		else {
			cvor *t1 = pocetak; cvor *t2 = NULL;
			for (int i = 0; i < index; i++) {
				t2 = t1;
				t1 = t1->sljedeci;
			}
			t2->sljedeci = novi_clan;
			novi_clan->sljedeci = t1;
		}
		duzinaListe++;
	}
	else {
		oboji.setCrvena();
		cout << "[STACK OVERFLOW!]" << endl;
		oboji.setDefault();
	}
}
template<class T>
void Lista<T>::obrisi() {
	boja oboji;
	if (duzinaListe != 0) {
		cvor *t1 = pocetak;
		cvor *t2 = pocetak->sljedeci;
		pocetak = t2;
		free(t1);
		duzinaListe--;
	}
	else {
		oboji.setCrvena();
		cout << "[LISTA JE PRAZNA!]" << endl;
		oboji.setDefault();
	}
}

template<class T>
void Lista<T>::obrisiSaIndexa(int &index) {
	boja oboji;
	if (duzinaListe != 0) {
		if (index < 0 || index >= duzinaListe) {
			oboji.setCrvena();
			cout << "[INDEX ERROR]" << endl;
			return;
		}
		cvor *t1 = pocetak;
		cvor *t2 = pocetak->sljedeci;
		if (index == 0) {
			pocetak = t2;
			free(t1);
		}
		else {
			for (int i = 0; i < index - 1; i++) {
				t1 = t2;
				t2 = t2->sljedeci;
			}
			if (!t2) {
				free(kraj);
				kraj = t1;
			}
			else {
				t1->sljedeci = t2->sljedeci;
				free(t2);
			}
		}
		duzinaListe--;
	}
	else {
		oboji.setCrvena();
		cout << "[LISTA JE PRAZNA!]" << endl;
		oboji.setDefault();
	}
}

template<class T>
int Lista<T>::getDuzina() { return this->duzinaListe; }

template<class T>
T &Lista<T>::getClanSaIndexa(int &index) {
	boja oboji;
	if (index < 0 || index >= duzinaListe) {
		throw 0;
	}
	else if (this->duzinaListe == 0) {
		throw 0;
	}
	else {
		tekuci = pocetak;
		for (int i = 0; i < index; i++)
			tekuci = tekuci->sljedeci;
		return tekuci->element;
	}
}

template<class T>
T &Lista<T>::getClan() {
	return this->kraj->element;
}