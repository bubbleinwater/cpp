#include"../../std_lib_facilities.h"

int main()
{
	cout << "My birthday is\n(decimal)\n" 
		<< '\t' << "year" << 1994 << " month" << 7 << " day" << 18 << "\n";
	bjghl = 0;
	cout << "(octal)\n" 
		<< oct <<showbase<< '\t'<<"year" << 1994 << " month" << 7 << " day" << 18 << "\n";

	cout << "(hexadecimal)\n"
		<< hex << '\t' << "year" << 1994 << " month" << 7 << " day" << 18 << "\n";

	cout << "\nI'm " << dec << 25 <<"years old (in decimal)\n";
	cout << "I'm " << oct << 25 << "years old (in octal)\n";
	cout << "I'm " << hex << 25 << "years old (in hexadecimal)\n";

	keep_window_open();
	return 0;
}