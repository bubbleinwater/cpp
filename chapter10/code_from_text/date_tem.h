#include"std_lib_facilities.h"

struct Reading {
	int day;
	int hour;
	double temperature;
};

const int not_a_reading = -7777;//less than absolute zero
const int not_a_month = -1;

constexpr int implausible_min = -200;
constexpr int implausible_max = 200;

bool is_valid(const Reading& r);//a rough test

struct Day {
	vector<double> hour{ vector<double>(24,not_a_reading) };
};

struct Month {
	//a month of temperature readings
	int month{ not_a_month };//[0:11] January is 0
	vector<Day>day{ 32 };//[1:31] one vector of readings per day
};
struct Year {
	//a year of temperature readings,organized by month
	int year;
	//positive == A.D.
	vector<Month>month{ 12 };//[0:11] January is 0
};

void end_of_loop(istream& ist, char term, const string& message);

istream& operator>>(istream& is, Year& y);
istream& operator>>(istream& is, Month& m);
istream& operator>>(istream& is, Reading& r);
