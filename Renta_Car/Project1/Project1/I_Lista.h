#pragma once
#include"Includes.h"

template<class T>
class I_Lista{
public:
	I_Lista() {};
	virtual ~I_Lista() {};

	virtual void dodaj(T &) = 0;
	virtual void dodajNaIndex(T &, int &) = 0;
	virtual void obrisi() = 0;
	virtual void obrisiSaIndexa(int &) = 0;
	virtual int getDuzina() = 0;
	virtual T &getClanSaIndexa(int &) = 0;
};

