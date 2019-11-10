#pragma once
#include"Includes.h"

class Datum {
private:
	char *datum;
public:
	Datum(const char *_datum = "1.1.1990");
	~Datum();

	void setDatum();

	char *getDatum();
};
