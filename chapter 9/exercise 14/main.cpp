#include"Money.h"

int main()try {
	Money::Money money1,money2,money3;
	
	cin >> money1;
	cout << money1;

	cin >> money2;
	cout << money2;

	cin >> money3;
	cout << money3;

	keep_window_open();
	return 0;
}
catch (Money::Money::Invalid) {
	cerr << "invalid data was entered.\n";
	keep_window_open();
}