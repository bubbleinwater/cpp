#include"Rational.h"

int main()
{

	Rational::Rational ra1, ra2;

	cin >> ra1;

	cout << ra1;

	ra2 = { 5,'/', 7 };
	cout << ra2;

	ra1 = ra2;

	cout << ra1;

	keep_window_open();
	return 0;
}
