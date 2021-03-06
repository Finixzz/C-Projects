#pragma once
#include"Datum.h"
#include"Includes.h"
class ClanskaKartica{
private:
	Datum datumKreiranjaKartice;
	bool postojiKartica;
	int brojKartice;
public:
	ClanskaKartica() :
		datumKreiranjaKartice{}, postojiKartica{ false }, brojKartice{ 0 }{};
	~ClanskaKartica(){}
	
	void kreirajKarticu(string &,string &);
	bool getStatusKartice();

	Datum getDatumKreiranjaKartice();
	int getBrojKartice();
};

