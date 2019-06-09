#include"Money.h"

int main()try {
	Money::Money money1,money2,money3;
	cout << "Please enter USDXXX.XXX or KKDXXX.XXX style(X is a digit)\n";

	cin >> money1;
	cout << money1;

	cin >> money2;
	cout << money2;

	Money::Money sum;
	sum = money1 + money2;
	cout << sum;

	Money::Money sub = money1 - money2;
	cout << sub;

	Money::Money mul = money1 * 1.5;
	cout << mul;

	cin >> money3;
	cout << money3;

	keep_window_open();
	return 0;
}
catch (Money::Money::Invalid()) {
	cerr << "invalid data was entered.\n";
	keep_window_open();
}