#include"roman_numerals.h"
using namespace Roman_num;

int main() {

	cout << "Please enter two roman numerals.\n";

	Roman_int r1, r2;

	cin >> r1 >> r2;

	cout << "Roman " << r1 << " equals " << r1.as_int() << '\n';
	cout << "Roman " << r2 << " equals " << r2.as_int() << '\n';

	keep_window_open();
	return 0;
}