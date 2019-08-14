/*
2019.aug.12

			if (!(s_num[1] == 'x' || s_num[1] == 'X')) {
				//				error("there's no such suffix.");
				cout << "Did you mean \'0x\'?\n"
					<< "if so, the number will be..\n";
				s_num[1]={ 'x' };
			}
did not work as I want.

*/

#include"../../std_lib_facilities.h"

void alphato_x(string& s) {
//	string result;
	for (char& c : s)if (c == s[1])c = 'x';
/*	istringstream ist{ s };
	char ch;
	int i = 0;
	while (ist.get(ch)) {
		if(i == 2){}
		else
		{
			result += ch;
		}
	}
	s = result;
*/
}

int main()
{
	cout << showbase;
	string s_num;

	cout << "Please enter several integers in any combination of"
		<< " decimal hexadecimal octal using the 0 or 0x base suffixes\n"
		<< "enter | for exit.\n";

	while (cin >> s_num) {
		if (s_num == "|")return 0;
		if (isalpha(s_num[0]))error("not a number ", s_num);
		
		if (s_num[0] == '0') {
			if (!(s_num[1] == 'x' || s_num[1] == 'X') && !isdigit(s_num[1])) {
//				error("there's no such suffix.");
				cout << "Did you mean \'0x\'?\n"
					<< "if so, the number will be..\n";
				alphato_x(s_num);
			}
			if (s_num[1] == 'x' || s_num[1] == 'X') {
				istringstream ist{ s_num };
				int num;
				ist >> hex >> num;
				cout << hex << num 
					<< " hexadecimal converts to " << dec << num << " decimal" << '\n';
			}
			else {
				istringstream ist{ s_num };
				int num;
				ist >> oct >> num;
				cout << oct << num << " octal converts to " << dec << num << " decimal" << '\n';
			}
		}
		else {
			istringstream ist{ s_num };
			int num;
			ist >> dec >> num;

			cout << dec << num << " decimal converts to " << dec << num << " decimal" << '\n';
		}
	}

	keep_window_open();
	return 0;
}