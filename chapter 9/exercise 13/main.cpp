#include"Rational.h"

int main()
{
	Rational::Rational ra1, ra2;

	cin >> ra1;

	cout << ra1.reduction();

	ra2 = { 5,'/', 7 };
	cout << ra2.reduction();

	cout << (ra1 + ra2).reduction();

	cout << (ra1 - ra2).reduction();

	ra1 = ra2;

	cout << ra1.reduction();

	keep_window_open();
	return 0;
}
