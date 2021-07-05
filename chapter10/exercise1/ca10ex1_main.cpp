#include"sum_cal.h"

int main()
{
	cout << "Please enter the name of the file: ";
	
	string iname;

	cin >> iname;

	ifstream ifs{ iname };

	if (!ifs)error("can't open the input file ", iname);

	int num;
	int sum = 0;

	while (ifs >> num) {
		sum += num;
	}

	cout << "The sum of the integer of this file is: " << sum << "\n";

	keep_window_open();
	return 0;
	}