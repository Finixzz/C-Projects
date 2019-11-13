#pragma once
class Datum
{
public:
	Datum();
	void setDan();
	void setMjesec();
	void setGodina();
	int getDan();
	int getMjesec();
	int getGodina();
	void postaviDatum();
	void ispisiDatum();

	~Datum();
private:
	int dan, mjesec, godina;
};
