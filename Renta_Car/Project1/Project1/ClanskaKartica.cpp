#include "ClanskaKartica.h"

void ClanskaKartica::kreirajKarticu()
{
	this->datumKreiranjaKartice.postaviDatum();
	this->postojiKartica = true;
	this->brojKartice = int(datumKreiranjaKartice.getDan() + datumKreiranjaKartice.getGodina() + datumKreiranjaKartice.getGodina());
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