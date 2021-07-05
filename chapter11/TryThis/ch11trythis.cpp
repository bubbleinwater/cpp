#include"../../std_lib_facilities.h"

int main()
{
	cout << setw(15) << "last name|" << setw(15) << "first name|"
		<< setw(21) << "telephone number|"<< setw(24) << "email address|\n";
	cout << setw(15) << "Water " << setw(15) << "Bubble "
		<< setw(21) << "12345678910 " << setw(24) << "abcde.fghi.jk@amail.com \n";

	keep_window_open();
	return 0;
}