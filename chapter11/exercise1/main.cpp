/*
2019.aug.8
it seems that getline couldn't get the "whitespace(return)"
so I added while() to continue getting new line.
and for outputting, I wrote
line += tmp += '\n';

2019.dec.29
is previous version better than this one?

*/


#include"std_lib_facilities.h"

void tolower(string& s);

int main()
{
	string iname;
	cout << "enter the file name.\n";
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)error("can't open the file named ", iname);

	string s;
	vector<string> vs;
	
	while (ifs.good()) {
		getline(ifs, s);

		tolower(s);
		vs.push_back(s);
	}

	string oname;
	cout << "Please enter the output file name.\n";
	cin >> oname;
	ofstream ofs{ oname };

	if (!ofs)error("something wrong with the file name ", oname);
	
	for (int i = 0; i < vs.size(); ++i) {
		ofs << vs[i] <<'\n';
	}

	keep_window_open();
	return 0;
}

void tolower(string& s) {
	for (char& c : s)
		c = tolower(c);
}
