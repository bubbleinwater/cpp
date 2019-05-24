#include"Rational.h"

int main()try
{
	Rational::Rational ra1, ra2;

	cin >> ra1;

	cout << ra1.reduction();

	cout << ra1;

	ra2 = { -21,'/', 7 };
	
	cout << ra2.reduction();

	cout << ra2;

	cout << (ra1 + ra2).reduction();

	cout << ra1 - ra2;
	cout << "reduces to ";
	cout << ((ra1 - ra2).reduction());

	cout << (ra1 * ra2).reduction();

	ra1 = ra2;

	cout << ra1.reduction();

	keep_window_open();
	return 0;
}
catch (Rational::Rational::invalid) {
	cerr << "Invalid data.";
	keep_window_open();
	return 0;
}