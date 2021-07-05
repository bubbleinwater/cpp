#include"../../std_lib_facilities.h"

int main()
{
	int a, b, c, d;

	cin.unsetf(ios::dec);
	cin.unsetf(ios::hex);
	cin.unsetf(ios::oct);

	cin >> a >> b >> c >> d;

	cout << a <<'\t'<< b << '\t' << c << '\t' << d << '\n';

	
	/*

	cout <<showbase << 1234 << '\t' << hex << 1234 << '\t' << oct << 1234 << '\n';
	cout << 1234 << '\n';
	*/

	keep_window_open();
	return 0;
}