#pragma once
#include"includes.h"
class Stvar{
	char *naziv;
	int kolicina;
public:
	static int brStvari;
	Stvar(const char *_naziv="Nova stvar",int _kolicina=0);
	~Stvar();

	void setNazivStvari();
	void setKolicinaStvari();
	void unesiStvar();
	void povecajKolicinu(int x);
	void smanjiKolicinu(int x);

	char *getNazivStvari();
	int getKolicinaStvari();
};

