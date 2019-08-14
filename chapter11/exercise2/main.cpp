#include"../../std_lib_facilities.h"

int main()
{
	cout << "Pleease enter the input file name.\n";
	string iname;
	cin >> iname;
	ifstream ifs{ iname };
	if (!ifs)error("can't open the file named ", iname);

	string word;
	cout << "now,please enter a word which you want to identify the location(line number).\n";
	cin >> word;


	string line;
	string tmp;
	string target;
	int line_number = 0;
	while (getline(ifs, tmp)) {
		++line_number;

		istringstream ist{ tmp };
		while (ist >> target) {
			if (word == target) {
				cout << target << ": found on the line number " << line_number << '\n';
				cout << "[ " << tmp << " ]\n";
			}
		}
		/*
			string line;
			string tmp;
			while (getline(ifs, tmp)) {
				for (char& c : tmp) {
					if (isupper(c))c = tolower(c);
				}
				line += tmp +='\n';
			}
		*/
//		line += tmp += '\n';
	}
/*
	cout << "Please enter a name for the output file.\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };

	ofs << line;
*/
	keep_window_open();
	return 0;
}