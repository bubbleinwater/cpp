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
			if (d < 1 ||31 < d) { return false; }
			else return true;
		}
		else if (m == Month::apr || m == Month::jun || m == Month::sep || m == Month::nov) {
			if (d < 1 ||30 < d) { return false; }
			else return false;
		}
		else if( m == Month::feb){
			if (leapyear(y)) {
				if (d < 1 ||29 < d) { return false; }
				else return true;
			}
			else {
				if (d < 1 ||28 < d) { return false; }
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
		if(m == Month::feb && d == 29 && !leapyear(y + n)){
			m = Month::mar;
			d = 1;
		}
		y += n;

	}
/*
	Date next_workday(Date d) {
//next_workday(today) returns wednesday's date if it is tuesday today.
//note also this function's range starts from 2000.01.01(is saturday)
		if (d.year() >= 2000) {
			for (int i = 0; i < d.month(); ++i) {

			}
		}
	}
	*/

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
