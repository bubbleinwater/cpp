#include"../../std_lib_facilities.h"

int main()
{
	cout << "Please enter the name of input file.\n";
	string iname;
	cin >> iname;
	ifstream ifs(iname);
	if (!ifs)error("can't open the file named ", iname);

	vector<int>	nums;
	
	while (ifs.good()) {
		int num;
		ifs >> num;
		nums.push_back(num);
	}

	cout << "Please enter the name of the output file.\n";
	string oname;
	cin >> oname;

	ofstream ofs(oname);
	if (!ofs)error("something went wrong with the file name ", oname);

	for (int i = 0; i < nums.size();++i) {
		if ((i + 1) % 4 == 1) { ofs << "|"; }
		ofs << setw(20) << scientific << setprecision(8) << nums[i]<<"|";
		if ((i + 1) % 4 == 0) { ofs << "\n"; }
	}
}