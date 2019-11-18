#pragma once
class Datum
{
public:
	Datum();
	void setDan();
	void setMjesec();
	void setGodina();
	void postaviDatum();
	void ispisiDatum();

	int getDan();
	int getMjesec();
	int getGodina();

	~Datum();
private:
	int dan, mjesec, godina;
};
