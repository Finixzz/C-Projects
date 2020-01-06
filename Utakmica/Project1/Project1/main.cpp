#include"Utakmica.h"
#include<Windows.h>
#include<synchapi.h>
#include"Igrac.h"

void odigrajUtakmicu(Utakmica &u) {
	int pocetniNapad = rand() % 1;
	int odigraniBrojNapada;
	int i;
	for (i = 1; i <= 4; i++) {
		odigraniBrojNapada = 0;
		while (odigraniBrojNapada <= 20) {
			if (i == 1 || i == 3) {
				if (odigraniBrojNapada >= 20)
					break;
				odigraniBrojNapada += 2;
				if (pocetniNapad == 0) {
					u++;
					Sleep(1000);
					++u;
					Sleep(1000);
				}
				else if (pocetniNapad == 1) {
					++u;
					Sleep(1000);
					u++;
					Sleep(1000);
				}
			}
			else if (i == 2 || i == 4) {
				if (odigraniBrojNapada >= 20)
					break;
				odigraniBrojNapada += 2;
				if (pocetniNapad == 0) {
					++u;
					Sleep(1000);
					u++;
					Sleep(1000);
				}
				else if (pocetniNapad == 1) {
					u++;
					Sleep(1000);
					++u;
					Sleep(1000);
				}
			}
		}
		cout << "-----------------\n";
		cout << i << " / 4 zavrsena!" << endl;
		cout << "-----------------\n";
		Sleep(4000);
	}
}
int main() {

	Utakmica utakmica;
	cin >> utakmica;
	odigrajUtakmicu(utakmica);
	utakmica.pobjednik();
	!utakmica;


	system("Pause");
	return 0;
}