#include"ex8_concatenate.h"

int main() {
	cout << "This program will produce a new file.\n";
	cout << "Please enter two file name.\n";

	string f1, f2;

	cin >> f1 >> f2;

	ifstream ifs1{ f1 };
	if (!ifs1)error("error opening ", f1);

	ifstream ifs2{ f2 };
	if (!ifs2)error("error opening ", f2);

	string new_file;
	cout << "Please enter a name for new file.\n";
	cin >> new_file;

	ofstream ofs { new_file };

	string tmp;

	while (ifs1 >> tmp) {
		ofs <<" "<< tmp<<" ";
	}
	while (ifs2 >> tmp) {
		ofs << " " << tmp << " ";
	}

	keep_window_open();
	return 0;
}
