#include"Lista.h"
#include"Korisnik.h"

int main() {
	Korisnik k;
	Lista<Korisnik>korisnikList;
	korisnikList.dodaj(k);
	cout << korisnikList.getDuzina() << endl;
	int index;
	cin >> index;
	try {
		
		cout << korisnikList.getClanSaIndexa(index).getEmail() << endl;
	}
	catch (...) {
		boja oboji;
		oboji.setCrvena();
		cout << "[INDEX ERROR]" << endl;
		oboji.setDefault();
	}


	system("Pause");
	return 0;
}