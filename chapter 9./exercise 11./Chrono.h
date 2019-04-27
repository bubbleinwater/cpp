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

	bool leapyear(int y);
	Month operator++(Month& m);
	ostream& operator<<(ostream& os, Date& dd);
	bool operator==(const Date& a, const Date& b);
	bool operator!=(const Date& a, const Date& b);
	Day_of_the_week whats_the_day(Date d);
//	Date next_workday(Date d);
	ostream& operator<<(ostream& os, Day_of_the_week& day);
//	bool operator==(const Day_of_the_week& a, const Day_of_the_week& b);
}
