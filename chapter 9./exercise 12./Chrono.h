#include"std_lib_facilities.h"
/*
2019.04.04
how to use Date type in main() is like..

	Chrono::Date today;
	cout << today << '\n';

	today.add_day(1);
	Chrono::Date tomorrow = today;

	cout << tomorrow << '\n';

2019.apr.18
modified add_day.
but I could hardly understand what add_yaer means.A year has 365 day? so that add one year means equal add 365 day? or just increasing the y?

2019.apr.23
catch(Chrono::Date::Invalid){
	error("invalid date.");
	}
does not work.
{cerr<<"invalid date.}
works.

exercise 11.
first I'll implement enum class Day_of_the_week{}

2019,apr,27
I added operator== and != for Date
and ostream& operator<<(ostream& os, Day_of_the_week& day);
and == for day
and 	Day_of_the_week whats_the_day(Date d)
you must not write as Day_of_the_week whats_the_day(Date& d)
if you do, this function will change the value of d

bool operator==(const Day_of_the_week& a, const Day_of_the_week& b); did not needed.

if you want to use cout << style, you have to
write as
Date& next_workday(Date d);
not as
Date next_workday(Date d);

2019.may.1
at the main function,I wanted to write like this.

Chrono::Date today = {1999,Chrono::Month::apr,17};/*={1978, Month::jun, 25 };
cout << "today is " << today << '\n';
Chrono::Day_of_the_week dd = Chrono::whats_the_day(today);
cout << dd << '\n';
cout << "next work day is " << Chrono::next_workday(today);

but the last 2 line didn't work(they caused runtime error) so I changed them to this

Chrono::Date work_d = Chrono::next_workday(today);
cout << "next work day is " << work_d;

and also whats_the_day(Date &d) didn't work.(?)

2019.may.04
exercise 12.
change the representation of a Date to be the number of days since January1, 1970(day 0)

for this exercise I'll add calculatedate_function called calcudate .

2019.may.08
start over from exercise 11.
added dDate.(which will replace the Date. not now)
it seems that dDate should have written after Date

at the main function
you have to write as

	d = Chrono::CalcuDate(dD);

	cout << d <<'\n';

not as

	cout << Chrono::CalcuDate(dD) << '\n';

and I don't know why yet
*/


namespace Chrono {

	enum class Month {
		jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	enum class Day_of_the_week {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};

	//from 11.10.3-------------------------------------------------------
	static vector<string>month_input_tbl = {
	"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"
	};

	/*
	//if I should have use this month_print_tbl, I think I have to rewrite enum class Month.right?
	vector<string>month_print_tbl = {
		"Janualy","February","March","April","May","June","July","August","September","October","November","December"
	};
	string int_to_month(int i)//months[0:11]
	{
		if (i < 0 || 12 <= i)error("bad month index");
		return month_print_tbl[i];
	}
	*/
	//-------------------------------------------------------------------
	

	class Date {
	public:
		class Invalid {};		//to be used as exception
		Date();//default constructor
		Date(int yy, Month mm, int dd);	//constructor:check for valid date and initialize
		void add_day(int n);
		void add_year(int n);
		int year()const { return y; }
		int month()const;
		int day()const { return d; }
		bool is_valid();		//return true if date is valid
		int month_to_int(string s)const;
		string int_to_month(int n)const;
		void string_to_Date(string s);

	private:
		int y;
		Month m;
		int d;
	};

	class dDate {
	public:
		dDate();
		dDate(long int n);
		long int THE_DATE() { return the_Date; }
		
	private:
		long int the_Date;
	};

	Date& CalcuDate(dDate num);


	bool leapyear(int y);
	Month operator++(Month& m);
	ostream& operator<<(ostream& os, Date& dd);
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	Day_of_the_week whats_the_day(Date d);
	Date& next_workday(Date d);
	int week_of_year(Date d);
	ostream& operator<<(ostream& os, Day_of_the_week& day);
}
