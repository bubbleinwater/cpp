#include"store_temps.h"


vector<Reading> fill_vector_from_cin() 
{
	vector<Reading> result;

	int d, h;
	double t;

	while (cin >> d >> h >> t) {
		Reading r = { d,h,t };
		result.push_back(r);
	}

	if (!cin) {
		if (cin.bad()) { error("cin is bad"); }
		if (cin.fail()) {
			cin.clear();
			char ch;
			cin >> ch;
//			cout << ch << " was entered.\n";//maybe that is a terminator
			return result;
		}
		if (cin.eof()) {
			cout << "end of file?\n";
			//when you hit the end of file key(ctrl + z), if(cin.fail) are
			//going to be handle them so I think this if() do nothing 
		}
	}
}


void store_temps(vector<Reading> v_r)
{
	cout << "Please enter an output file name: ";
	string oname;

	cin >> oname;

	ofstream ofs{ oname };

	if (!ofs)error("can't open the output file ", oname);

	for (int i = 0; i < v_r.size(); ++i) {
		ofs << '(' << v_r[i].day << ',' << v_r[i].hour << ',' << v_r[i].temperature << ')' << '\n';
	}

//	ofs.close();

}