/*
2019.aug.12

			if (!(s_num[1] == 'x' || s_num[1] == 'X')) {
				//				error("there's no such suffix.");
				cout << "Did you mean \'0x\'?\n"
					<< "if so, the number will be..\n";
				s_num[1]={ 'x' };
			}
did not work as I want.

2020.jan.13
update
*/

#include"../../std_lib_facilities.h"

string hex_or_oct(string j);
void o_to_zero(string& s);

int main()
{

//	cin.unsetf(ios::dec);
	cout << showbase;

	cout << "Please enter several integers.in any combination of"
		<< "\noctal, decimal,hexadecimal, using base suffixes: o(for octal)"
		<< "\nor 0x(for hexadecimal).\n"
		<<"when you want to exit, enter |.\n";

	string s;
	while (cin >> s) {
		if (s == "|")return 0;

		istringstream is{ s };
		int i;
		cout << setw(8);

		if (hex_or_oct(s) == "hexadecimal") {
			o_to_zero(s);
			istringstream hex_is{ s };
			hex_is >> hex >> i;
			cout << hex << i;
		}
		else if (hex_or_oct(s)=="octal") {
			o_to_zero(s);
			istringstream oct_is{ s };
			oct_is >> oct >> i;
			cout << oct << i;
		}
		else {
			is >> i;
			cout << dec << i;
		}
		cout << setw(15) << hex_or_oct(s) << " converts to "
			<< setw(10) << dec << i << " decimal\n";
	}

	keep_window_open();
	return 0;
}


string hex_or_oct(string j) {
	ostringstream os{ j };

	if (os.str()[0] == '0' || os.str()[0] == 'o' || os.str()[0] == 'O') {
		if (os.str()[1] == 'x' || os.str()[1] == 'X') {
			return "hexadecimal";
		}
		else return "octal";
	}
	else return "decimal";
}

void o_to_zero(string& s) {
	s[0] = '0';
}
