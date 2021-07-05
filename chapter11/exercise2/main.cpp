/*
2019.dec.29
I use ostringstream. add is_match function.

*/


#include"std_lib_facilities.h"

void tolower(string& s);
int is_match(string word, string s);

int main()
{
	string iname, word;
	cout << "enter the file name.\n";
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)error("can't open the file named ", iname);
	cout << "enter a word which you want to find out where.\n";
	cin >> word;
	tolower(word);

	string s;
	vector<string> vs;
	
	for (int line_number = 1; ifs.good(); ++line_number) {
		getline(ifs, s);

		tolower(s);
		int count = is_match(word, s);
		if (count == 1) { 
			ostringstream ost;
			ost << line_number <<" "<<s;
			vs.push_back(ost.str());
//			vs.push_back(" ");
//			vs.push_back(s);
		}
	}

	string oname;
	cout << "Please enter the output file name.\n";
	cin >> oname;
	ofstream ofs{ oname };

	if (!ofs)error("something wrong with the file name ", oname);

	ofs << word << " at" << '\n';
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

int is_match(string word, string s) {
	if (word.size() > s.size())return 0;

	int j = 0;//counter for string s
	for (int i = 0; i < word.size(); ++i) {//i is the counter for the string word's position of char
		if (j > s.size())return 0;
		for (; !(word[i] == s[j])&&j < s.size(); ++j) {
			if (i != 0)return 0;
		}
		++j;//for when the two char from word and s was match
	}

	return 1;
}
