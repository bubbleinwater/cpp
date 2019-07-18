#include"../../std_lib_facilities.h"

int main(){

	string iname;
	cout << "enter a file name.\n";
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)error("error opening file named ", iname);

	cin.rdbuf(ifs.rdbuf());

	string words;
	while (cin) {
		cin >> words;
		cout << words;
	}

//I thought	cin.ignore(); and cin.clear(); would work, but didn't
	
	string name;
	cin >> name;
	cout << name;

	for (int i = 0; i < 1000000; ++i) { cout << "."; }
//this for sentence is for checking is the standard output really work
//because keep_window_open() doesn't work here

	keep_window_open();
	return 0;
}