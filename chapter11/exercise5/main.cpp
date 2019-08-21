#include"../../std_lib_facilities.h"

int main()
{
	cout << "Please enter some string type values.\n";

	for (char ch; cin.get(ch);) {
		if (ch == '|') { break; }
		if(isprint(ch))cout <<"\'"<<ch<<"\' is printable character.\n";
		else cout << " can not print this character\n";

		if (isspace(ch)) { cout << " It's a space\n"; }
		else if (isxdigit(ch)) {
			if (isdigit(ch)) { cout << "\'" << ch << "\'" << " is a digit character.\n"; }
			else if (isalpha(ch)) {
				if (isupper(ch)) { cout << "\'" << ch << "\'"<< " is a alphabet,upper case alphsbet character.\n"; }
				else if (islower(ch)) {
					cout << "\'" << ch << "\'"<< " is a alphabet, lower case alphsbet character.\n"; }
			}
		}
		else if (isalpha(ch)) {
			if (isupper(ch)) { cout << "\'" << ch << "\'" << " is a alphabet,upper case alphsbet character.\n"; }
			else if (islower(ch)) {
				cout << "\'" << ch << "\'" << " is a alphabet, lower case alphsbet character.\n";
			}
		}
		else if (iscntrl(ch)) {
			cout << "\'" << ch << "\'" << " is a control character\n";
		}
		else if (ispunct(ch)) { cout << "\'" << ch << "\'" << " is a punctutation character.\n"; }

		else if (isgraph(ch)) { cout << "\'" << ch << "\'" << " is a not-space character.\n"; }
	}

	keep_window_open();
	return 0;
}