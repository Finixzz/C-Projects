#pragma once
#include"Datum.h"
class ClanskaKartica{
private:
	Datum datumKreiranjaKartice;
	bool postojiKartica;
public:
	ClanskaKartica() :
		datumKreiranjaKartice{}, postojiKartica{ false }{};
	~ClanskaKartica(){}
	
	void kreirajKarticu();
	bool getStatusKartice();
	Datum getDatumKreiranjaKartice();
};

