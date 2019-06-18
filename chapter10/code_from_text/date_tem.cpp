#include"date_tem.h"

/*
int month_to_int(string mm) {
	if (mm == "jan")return 0;
	else if (mm == "feb")return 1;
	else if (mm == "mar")return 2;
	else if (mm == "apr")return 3;
	else if (mm == "may")return 4;
	else if (mm == "jun")return 5;
	else if (mm == "jul")return 6;
	else if (mm == "arg")return 7;
	else if (mm == "sep")return 8;
	else if (mm == "oct")return 9;
	else if (mm == "nov")return 10;
	else if (mm == "dec")return 11;
	else error("bad month"); return 1;
}*/
vector<string> month_input_tbl = {
	"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"
};

vector<string> month_print_tbl = {
	"January","February","March","April","May","June","July","August","September","October","November","December"
};

int month_to_int(string s)
//is s the name of a month? If so, return its index[0:11], otherwise -1
{
	for (int i = 0; i < 12; ++i)if (month_input_tbl[i] == s)return i;

	return -1;
}

string int_to_month(int i)
//months[0:11]
{
	if (i < 0 || 12 <= i)error("bad month index");
	return month_print_tbl[i];
}

istream& operator>>(istream& is, Reading& r)
//read a temperature reading from is into r
//format:(3 4 9.7)
//check format,but don't bother with data validity

{
	char ch1;
	if (is >> ch1 && ch1 != '(') {//could it be a Reading?

		is.unget();
		is.clear(ios_base::failbit);
		return is;
	}

	char ch2;
	int d;
	int h;
	double t;
	is >> d >> h >> t >> ch2;
	
	if (!is || ch2 != '(')error("bad reading");//messed-up reading

	r.day = d;
	r.hour = h;
	r.temperature = t;
	return is;
}

istream& operator>>(istream& is, Year& y)
//read a year from is int y
//format:{year 1972 . . .}
{
	char ch;
	is >> ch;
	if (ch != '{') {
		is.unget();
		is.clear(ios::failbit);
		return is;
	}
	string year_marker;
	int yy;
	is >> year_marker >> yy;
	if (!is || year_marker != "year")error("bad start of year");
	y.year = yy;

	while (true) {
		Month m;//get a clean m each time around
		if (!(is >> m))break;
		y.month[m.month] = m;
	}
	end_of_loop(is, '}', "bad end of year");
	return is;
}

istream& operator>>(istream& is, Month& m) {
//read a month from is into m
//format: {month feb...}
	{
		char ch = 0;
		if (is >> ch && ch != '{') {
			is.unget();
			is.clear(ios_base::failbit);//we failed to read a Month
			return is;
		}

		string month_marker;
		string mm;
		is >> month_marker >> mm;
		if (!is || month_marker != "month")error("bad start of month");

		m.month = month_to_int(mm);
		int duplicates = 0;
		int invalids = 0;
		for (Reading r; is >> r;) {
			if (is_valid(r)) {
				if (m.day[r.day].hour[r.hour] != not_a_reading)
					++duplicates;
				m.day[r.day].hour[r.hour] = r.temperature;
			}
			else ++invalids;
		}
		if (invalids)error("invalid readings in month", invalids);
		if (duplicates)error("duplicate readings in month", duplicates);
		end_of_loop(is, '}', "bad end of month");
		return is;
	}
}