#include"std_lib_facilities.h"

int main() {
	char c = ' ';
	cout << "enter some character.\n enter | for exit.\n";
	while(c != '|'){
		cin.get(c);
			if (isspace(c))cout << c << " is whitespace.\n";
			if (isalpha(c))cout <<c<< " is letter.\n";
			if (isdigit(c))cout << c << " is decimal digit.\n";
			if (isxdigit(c))cout << c << " is hexadecimal digit.\n";
			if (isupper(c))cout << c << " is an uppercase leter.\n";
			if (islower(c))cout << c << " is a lowercase letter.\n";
			if (isalnum(c))cout << c << " is a letter or a decimal digit.\n";
			if (iscntrl(c))cout << c << " is a control character.\n";
			if (ispunct(c))cout << c << " is not a letter, digit, whitespace, or invisible control character.\n";
			if (isprint(c))cout << c << " is printable.\n";
			if (isgraph(c))cout << c << " is not a space.\n";
	}

	keep_window_open();
	return 0;
}


