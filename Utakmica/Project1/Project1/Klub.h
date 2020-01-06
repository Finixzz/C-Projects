#pragma once
#include"Igrac.h"
#include"Includes.h"
class Klub
{
	char naziv[50];
	vector<Igrac>igraci;
public:
	Klub() {
		strcpy_s(this->naziv, "Random");
	}
	~Klub() {}

	void setNaziv();
	void setIgraci();
	void setKlub();

	char *getNaziv();
	vector<Igrac>&getIgraci();

	friend istream & operator>>(istream &in, Klub &k);
	friend ostream &operator <<(ostream &os, Klub &k);
};
