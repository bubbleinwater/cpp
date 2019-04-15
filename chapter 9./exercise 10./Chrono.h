#include"std_lib_facilities.h"
/*
2019.apr.04
how to use Date type in main() is like..
	Chrono::Date today;
	cout << today << '\n';
	
2019.apr.15
I added leapyaer() and add_year()
*/


namespace Chrono {

	enum class Month {
		jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
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
}
