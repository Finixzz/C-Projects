#include "ClanskaKartica.h"

void ClanskaKartica::kreirajKarticu(string &imePrezime,string &email)
{
	this->datumKreiranjaKartice.postaviDatum();
	this->postojiKartica = true;
	
	char *imePrezimeTemp = new char[imePrezime.size()+1];
	strcpy_s(imePrezimeTemp, imePrezime.size() + 1, imePrezime.c_str());
	char *emailTemp = new char[email.size()+1];
	strcpy_s(emailTemp, email.size() + 1, email.c_str());
	
	this->brojKartice = int(datumKreiranjaKartice.getDan() + datumKreiranjaKartice.getGodina() + datumKreiranjaKartice.getGodina()) + int(imePrezimeTemp) + int(emailTemp);
	this->brojKartice /= 1000;

	delete[]imePrezimeTemp; imePrezimeTemp = nullptr;
	delete[]emailTemp; emailTemp = nullptr;
}



bool ClanskaKartica::getStatusKartice()
{
	return this->postojiKartica;
}

Datum ClanskaKartica::getDatumKreiranjaKartice()
{
	return datumKreiranjaKartice;
}

int ClanskaKartica::getBrojKartice() { return this->brojKartice; }