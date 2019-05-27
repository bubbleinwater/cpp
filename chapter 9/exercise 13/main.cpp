#include"Rational.h"

int main()try
{
	Rational::Rational ra1, ra2;

	cin >> ra1;

	cout << ra1.reduction();

	cout <<"ra1 == "<< ra1;

	ra2 = { 20,'/', 7 };
	
	cout << ra2.reduction();

	double d_r = ra2;
	cout << "type:double ra2 == ";
	cout << d_r << '\n';

	cout <<"ra2 == "<< ra2;

	cout << "ra1+ra2 == ";
	cout << (ra1 + ra2).reduction();

	cout << "ra1-ra2 == " << ra1 - ra2;
	cout << "reduces to ";
	cout << ((ra1 - ra2).reduction());

	cout << "ra1*ra2 == ";
	cout << (ra1 * ra2).reduction();

	if (ra1 == ra2) cout << "ra1 == ra2\n";
	else cout << "ra1 != ra2\n";

	ra1 = ra2;

	if (ra1 == ra2) { cout << "ra1 == ra2\n"; }
	else cout << "ra1 != ra2\n";

	cout << ra1.reduction();

	keep_window_open();
	return 0;
}
catch (Rational::Rational::invalid) {
	cerr << "Invalid data.";
	keep_window_open();
	return 0;
}