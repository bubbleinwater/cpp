#include"../../std_lib_facilities.h"

int main()
{

	cout << "Please enter iput file name\n";

	string iname;
	cin >> iname;
	ifstream ifs{ iname, ios_base::binary };
	if (!ifs)error("can't open input file ", iname);

	cout << "Please enter output file name\n";
	string oname;
	cin >> oname;
	ofstream ofs{ oname };
	if (!ofs)error("can't open output file ", oname);

	vector<int>v;

	for (int x; ifs.read(as_bytes(x), sizeof(int));)
		v.push_back(x);


	for (int x : v)
		ofs.write(as_bytes(x), sizeof(int));

	return 0;
}