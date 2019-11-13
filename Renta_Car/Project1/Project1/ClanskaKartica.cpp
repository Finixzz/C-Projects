#include "ClanskaKartica.h"

void ClanskaKartica::kreirajKarticu()
{
	this->datumKreiranjaKartice.postaviDatum();
	this->postojiKartica = true;
}

bool ClanskaKartica::getStatusKartice()
{
	return this->postojiKartica;
}

Datum ClanskaKartica::getDatumKreiranjaKartice()
{
	return datumKreiranjaKartice;
}
