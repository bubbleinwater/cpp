/*
2020.jan.10
I was planning to make isvowel(char c) function. using like

istringstream iss;
char ch;
while(iss >> ch){
isvowel(ch);
}

but istringstream didn't catch the whitespace.
so I changed the plan to make removevowel(string& s) function

*/

#include"../../std_lib_facilities.h"

void removevowel(string& s);

int main()
{
	string iname;
	cout << "enter the file name.\n";
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)error("can't open the file named, ", iname);

	string withvowel;
	vector<string> vs;

	while (ifs.good()) {
		getline(ifs, withvowel);
		istringstream iss(withvowel);
		string s;
		string withoutvowel;
		
		while(iss >> s){
			removevowel(s);
//			else if(isprint(ch)) withoutvowel += ch;
			withoutvowel += s += ' ';
		}
		vs.push_back(withoutvowel);
	}

	string oname;
	cout << "please enter a name for the output file.\n";
	cin >> oname;

	ofstream ofs{ oname };
	if (!ofs)error("something went wrong with the file named, ", oname);

	for (int i = 0; i < vs.size(); ++i) {
		ofs << vs[i]<<'\n';
	}

	keep_window_open();
	return 0;
}


void removevowel(string& s) {
	string r;
	for (char c : s) {
		switch (c) {
		case 'a':case 'i':case 'u':case 'e':case 'o':
		case 'A':case 'I':case 'U':case 'E':case 'O':
			break;
		default:
			r += c;
		}
	}
	s = r;
}
