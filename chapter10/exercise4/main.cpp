#include"temp_stats.h"

int main()
{
	cout << "Please enter the input file name.\n";

	string iname;
	cin >> iname;

	ifstream ifs{ iname };

	if (!ifs)error("can't open the input file ", iname);

	temp_stats(ifs);

	keep_window_open();
	return 0;

}