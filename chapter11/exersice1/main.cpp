/*
2019.aug.8
it seems that getline couldn't get the "whitespace(return)"
so I added while() to continue getting new line.
and for outputting, I wrote
line += tmp += '\n';

*/


#include"../../std_lib_facilities.h"

int main()
{
	cout << "Please enter the input file name.\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };

	if (!ifs)error("can't open the file named ", iname);

	string line;
	string tmp;
	while (getline(ifs, tmp)) {
		for (char& c : tmp) {
			if (isupper(c))c = tolower(c);
		}
		line += tmp +='\n';
	}

	cout << "Please enter a name for the output file.\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };

	ofs << line;

	keep_window_open();
	return 0;
}