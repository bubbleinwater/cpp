#include"../../std_lib_facilities.h"

int main() {
	string iname;
	cout << "Please enter the name of the file.\n";
	cin >> iname;
	ifstream ifs{iname};
	if (!ifs)error("error opening file named ",iname);

	int sum = 0;
	int num = 0;
	char ch;
	while (ifs >> ch) {
		switch (ch) {
		case '0':case '1':case '2':case '3':case '4':
		case '5':case '6':case '7':case '8':case '9':
		ifs.putback(ch);
		ifs >> num;
		sum += num; 
		break;
		}
	}

	cout << "sum of integers in a file: " << sum << "\n";

	keep_window_open();
	return 0;
}