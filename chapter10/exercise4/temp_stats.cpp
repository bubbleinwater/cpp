#include"temp_stats.h"

double celsius_to_fahrenheit(double c) {
	double result = (c * 9 / 5) + 32;
	return result;
}

void temp_stats(ifstream& is) {
	char ch;
	int d, h;
	double t;
	char c_or_f;
	double sum = 0;
	double mea = 0;
	double med = 0;
	vector<Reading> temps;

	while (is >>ch >> d >> ch >> h >>ch>> t>>ch>>c_or_f>>ch) {
		double temp_f = t;
		if (c_or_f == 'c') {//all t will be converted to fahrenheit
//test
			cout << "temperature: " << temp_f << "C\n";
			temp_f = celsius_to_fahrenheit(t);
//test
			cout << "temperature: " << temp_f << "F\n";
		}
		Reading r = { d,h,temp_f,c_or_f };
		temps.push_back(r);
	}

	vector<double>temp;
	for (int i = 0; i < temps.size(); ++i) {
		temp.push_back(temps[i].temperature);
	}
	sort(temp);

//	for (int i = 0; i < temp.size(); ++i) {//just for test
//		cout << temp[i];
//	}

	if(temp.size()%2){
		med = temp[int(temp.size()) / 2 ];
	}
	else {
		med = (temp[temp.size() / 2 - 1] + temp[(temp.size() / 2)]) / 2.0;
	}

	for (int i = 0; i < temps.size(); ++i) {
		sum += temps[i].temperature;
	}
	mea = sum / temps.size();

	cout << "median: " << med << "F"
		<< "\nmean: " << mea << "F" << "\n";

}