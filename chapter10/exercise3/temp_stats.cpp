#include"temp_stats.h"

void temp_stats(ifstream& is) {
	char ch;
	int d, h;
	double t;
	double sum = 0;
	double mea = 0;
	double med = 0;
	vector<Reading> temps;

	while (is >>ch >> d >> ch >> h >>ch>> t>>ch) {
		Reading r = { d,h,t };
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

	cout << "median: " << med
		<< "\nmean: " << mea <<"\n";

}