#include"../../std_lib_facilities.h"

int main()
{
	int birth_year;
	birth_year = 1994;

	cout <<showbase << "dec\t" << birth_year << '\n' << "hex\t" << hex << birth_year << '\n' << "oct\t" << oct << birth_year << '\n';

	int age;
	age = 25;

	cout << "dec\t" <<dec << age << '\n' << "hex\t" << hex << age << '\n' << "oct\t" << oct << age << '\n';

	keep_window_open();
	return 0;
}