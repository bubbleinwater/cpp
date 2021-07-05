#include"../../std_lib_facilities.h"
#include"rev_string.h"

int main()
{
	
	cout << "Please enter the input file name.\n";
	string iname;
	cin >> iname;
	ifstream ifs(iname);

	if (!ifs)error("can't open the input file named ", iname);

	string s;
	vector<string> v_s;


	while (ifs >> s) {
		v_s.push_back(s);
	}
	

	
	cout << "Please enter the output file name.\n";
	string oname;
	cin >> oname;
	ofstream ofs(oname);

	if (!ofs)error("something went wrong with the file named ", oname);

	for (int i = 1; i <= v_s.size(); ++i) {
		ofs << v_s[v_s.size() - i]<<" ";
	}

	return 0;
}