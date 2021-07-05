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

	sort(nums);

	cout << "Please enter the name of the output file.\n";
	string oname;
	cin >> oname;

	ofstream ofs(oname);
	if (!ofs)error("something went wrong with the file named ", oname);


	int count = 1;
	int tmp = nums[0];
	for (int i = 1; i < nums.size(); ++i) {
		if (tmp == nums[i]) { ++count; }
		else { 
			ofs <<'\n'<< nums[i - 1] << '\t';if(count != 1)ofs << count;
			tmp = nums[i]; ++count = 1;
		}
	}
	return 0;
}