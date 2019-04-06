#include"Chrono.h"


namespace Chrono {
	const Date& default_date() {
		static Date dd{ 1978,Month::jun,25 };
		return dd;
	}

	Date::Date()
		:y{ default_date().year() }
		, m{ Month(default_date().month() - 1) }
		, d{ default_date().day() }//month's index starts with 0 is so error prone
	{}

	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }//initialize data members
	{
		if (!is_valid())throw Invalid{};//check for validity
	}

	bool Date::is_valid()//return true if date is valid
	{
		if (int(m) < 0 || 11 < int(m))return false;
		if (d < 1 || 31 < d)return false;
		if (y < 0)return false;

		return true;
	}

	int Date::month() const { //month() returns int not Month is error-prone
		string s = Date::int_to_month(int(m));
		return Date::month_to_int(s);
	}

	Month operator++(Month& m) {
		m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
		return m;
	}

	void Date::add_day(int n) {

		if (31 < (d + n))
		{
			d += (n - 31);
			if (m == Month::dec) { m = Month::jan, ++y; }
			else { ++m; }
		}
		else d += n;
	}


	ostream& operator<<(ostream& os, Date& dd) {
		return os << '(' << dd.year()<< ',' << dd.month()<< ',' << dd.day() << ')';
	};


	int Date::month_to_int(string s)const {
		for (int i = 0; i < 12; ++i)
			if (month_input_tbl[i] == s)return (i + 1);
		return -1;
	}

	string Date::int_to_month(int n)const {

		if (n < 0 || 12 <= n)error("bad month index");
		return month_input_tbl[n];

	}

	void Date::string_to_Date(string s) //this function is limited to the date which is xxxx.xx.xx style
	{
		if (s.size() != 10)throw Chrono::Date::Invalid();

		string year, month,day;
		for (int i = 0; i < 4; ++i) {
			year += s[i];
		}
		y = { stoi(year) };
		for (int i = 5; i < 7; ++i) {
			month += s[i];
		}m = { Month(stoi(month) - 1) };
		for (int i = 9; i < 11; ++i) {
			day += s[i];
		}d = { stoi(day) };
	}
}
