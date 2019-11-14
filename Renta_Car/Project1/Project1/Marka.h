#pragma once
#include"Includes.h"
class Marka{
	string naziv;
	string  zemljaPorijekla;
public:
	Marka() :
		naziv{ "empty" }, zemljaPorijekla{ "empty" }{};
	~Marka(){};
	void setNaziv();
	void setZemljaPorijekla();
	string getNaziv();
	string  getZemljaPorijekla();
};
