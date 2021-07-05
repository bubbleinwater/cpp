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
		if (!is_valid())
			throw Invalid();//check for validity
	}

	bool Date::is_valid()//return true if date is valid
	{
		if (y < 0)return false;
		//----------
		if (m == Month::jan || m == Month::mar || m == Month::may || m == Month::jul || m == Month::aug || m == Month::oct || m == Month::dec) {
			if (d < 1 || 31 < d) { return false; }
			else return true;
		}
		else if (m == Month::apr || m == Month::jun || m == Month::sep || m == Month::nov) {
			if (d < 1 || 30 < d) { return false; }
			else return true;
		}
		else if (m == Month::feb) {
			if (leapyear(y)) {
				if (d < 1 || 29 < d) { return false; }
				else return true;
			}
			else {
				if (d < 1 || 28 < d) { return false; }
				else return true;
			}
		}
		else return false;
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

		if (m == Month::jan || m == Month::mar || m == Month::may || m == Month::jul || m == Month::aug || m == Month::oct || m == Month::dec) {
			//handle month(1,3,5,7,8,10,12)
			if (31 < (d + n))//when the size of day is larger than 31,m will be assigned by next month 
			{
				d += (n - 31);
				if (m == Month::dec) { m = Month::jan, ++y; }
				else { ++m; }
			}
			else d += n;
		}

		else if (m == Month::apr || m == Month::jun || m == Month::sep || m == Month::nov) {
			//handle month(4,6,9,11)
			if (30 < (d + n))//when the size of day is larger than 31,m will be assigned by next month 
			{
				d += (n - 30);
				++m;
			}
			else d += n;
		}

		else {
			if (leapyear(y)) {
				if (29 < (d + n))
				{
					d += (n - 29);
					++m;
				}
				else d += n;
			}
			else {
				if (28 < (d + n))
				{
					d += (n - 28);
					++m;
				}
				else d += n;
			}
		}
	}


	void Date::add_year(int n) {
		if (m == Month::feb && d == 29 && !leapyear(y + n)) {
			m = Month::mar;
			d = 1;
		}
		y += n;

	}

	Day_of_the_week whats_the_day(Date d) {
		//note also this function's range starts
		//from the reference point(2000.01.01(is saturday)) so 2000.01.08 is saturday
		if (d.year() >= 2000) {//start from 2000.jul.01 
			Date ref_date = { 2000,Chrono::Month::jul,1 };
			int i = 0;
			while (ref_date != d) {
				++i;
				ref_date.add_day(1);
			}
			int rest = i % 7;
			if (rest == 0) { return Day_of_the_week::saturday; }
			else if (rest == 1) { return Day_of_the_week::sunday; }
			else if (rest == 2) { return Day_of_the_week::monday; }
			else if (rest == 3) { return Day_of_the_week::tuesday; }
			else if (rest == 4) { return Day_of_the_week::wednesday; }
			else if (rest == 5) { return Day_of_the_week::thursday; }
			else return Day_of_the_week::friday;
		
		}
		else {
			Date ref_date = { 1999,Chrono::Month::dec,31/*is friday*/ };
			int i = 0;
			while (d != ref_date) {
				++i;
				d.add_day(1);
			}
			int rest = i % 7;
			if (rest == 0) { return Day_of_the_week::friday; }
			else if (rest == 1) { return Day_of_the_week::thursday; }
			else if (rest == 2) { return Day_of_the_week::wednesday; }
			else if (rest == 3) { return Day_of_the_week::tuesday; }
			else if (rest == 4) { return Day_of_the_week::monday; }
			else if (rest == 5) { return Day_of_the_week::sunday; }
			else return Day_of_the_week::saturday;
		}
	}

	Date& next_workday(Date d) {
//next_workday(today) returns wednesday's date if it is tuesday today.
		if (whats_the_day(d) == Day_of_the_week::friday) { d.add_day(3); return d; }
		else if (whats_the_day(d) == Day_of_the_week::saturday) { d.add_day(2); return d; }
		else { d.add_day(1);return d; }
	}

	int week_of_year(Date d) {
		Date first_day = { d.year(),Chrono::Month::jan,1 };
//		if (d == first_day) { return 1; }

		int i = 1;
		if (whats_the_day(first_day) == Chrono::Day_of_the_week::sunday) {  }
		else if (whats_the_day(first_day) == Chrono::Day_of_the_week::monday) { i += 1; }
		else if (whats_the_day(first_day) == Chrono::Day_of_the_week::tuesday) { i += 2; }
		else if (whats_the_day(first_day) == Chrono::Day_of_the_week::wednesday) { i += 3; }
		else if (whats_the_day(first_day) == Chrono::Day_of_the_week::thursday) { i += 4; }
		else if (whats_the_day(first_day) == Chrono::Day_of_the_week::friday) { i += 5; }
		else if (whats_the_day(first_day) == Chrono::Day_of_the_week::saturday) { i += 6; }
		else throw Date::Invalid();
		while (first_day != d) {
			first_day.add_day(1); ++i;
		}
		return (i / 7) + 1;
	}


	bool Chrono::leapyear(int y) {
		int leap = 0;
		for (int i = 0; leap <= y; ++i) {
			leap += 4;
			if (leap == y)return true;
		}
		return false;
	}

	ostream& operator<<(ostream& os, Date& dd) {
		return os << '(' << dd.year()<< ',' << dd.month()<< ',' << dd.day() << ')';
	};

	ostream& operator<<(ostream& os, Day_of_the_week& day) {
		if (day == Day_of_the_week(0)) { return os << "Sunday"; }
		else if (day == Day_of_the_week(1)) { return os << "Monday"; }
		else if (day == Day_of_the_week(2)) { return os << "Tuesday"; }
		else if (day == Day_of_the_week(3)) { return os << "Wednesday"; }
		else if (day == Day_of_the_week(4)) { return os << "Thursday"; }
		else if (day == Day_of_the_week(5)) { return os << "Friday"; }
		else return os << "saturday";
	}

	bool operator==(const Date& a,const Date& b) {
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();
	}

	bool operator!=(const Date& a,const Date& b) {
		return !(a == b);
	}

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
		for (int i = 8; i < 10; ++i) {
			day += s[i];
		}d = { stoi(day) };
	}
}
