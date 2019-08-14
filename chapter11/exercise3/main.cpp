#include"../../std_lib_facilities.h"

int main()
{
	string iname;
	cout << "Please enter a file name.\n";
	cin >> iname;
	ifstream ifs { iname };
	if (!ifs)error("can't open the file named ", iname);

	string line;
	string tmp;
	string word;
//	ostringstream new_ost;
	while (getline(ifs, tmp)) {
		istringstream ist{ tmp };
		while (ist >> word) {
			string new_word;
			for (char& c : word) {
				if (c == 'a' || c == 'i' || c == 'u' || c == 'e' || c == 'o'
					|| c == 'A' || c == 'I' || c == 'U' || c == 'E' || c == 'O') {}
				else {
					new_word += c;
				}
			}
//			new_ost << new_word += ' ';
			line += new_word += ' ';
		}
//		line << '\n';
		line += '\n';
	}

	string oname;
	cout << "Please enter a output file name.\n";
	cin >> oname;
	ofstream ofs{ oname };
	ofs << line; 

	keep_window_open();
	return 0;

}