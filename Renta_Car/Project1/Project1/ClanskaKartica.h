#pragma once
#include"Datum.h"
class ClanskaKartica{
private:
	Datum datumKreiranjaKartice;
	bool postojiKartica;
	int brojKartice;
public:
	ClanskaKartica() :
		datumKreiranjaKartice{}, postojiKartica{ false }, brojKartice{ 0 }{};
	~ClanskaKartica(){}
	
	void kreirajKarticu();
	bool getStatusKartice();
	Datum getDatumKreiranjaKartice();
	int getBrojKartice();
};

