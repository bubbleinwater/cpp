//file Chrono.h

//------------
//
//(2019,1,1)
//
//-------------

namespace Chrono {

	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

	enum class Day {
		sunday, monday, tuesday, wednesday, thursday, friday, saturday
	};


	class Date {
	public:
		class Invalid {};//to throw as exception
		Date(int yy, Month mm, int dd);//check for valid date and initialize
		Date();//default constructor
				//the default copy operations are fine

		//nonmodifying operation:
		int day()const { return d; }
		Month month() const { return m; }
		int year()const { return y; }
		static void init_day(Date& dd, int y, Chrono::Month m, int d);
		static void add_day(Date& dd,int n);
		void add_month(int n);
		void add_year(int n);
	private:
		int y;
		Month m;
		int d;
	};

	//modifying operation:void add_day(int n);void add_month(int n);void add_year(int n);

	bool is_date(int y, Month m, int d);// true for valid date
	bool leapyear(int y);//true if y is a leap year
	bool operator == (const Date& a, const Date& b);
	bool operator !=(const Date& a, const Date& b);
	ostream& operator<<(ostream& os, const Date& d);
	istream& operator>>(istream& is, Date& dd);
	Day day_of_week(const Date& d);//day of week of d
	Date next_Sunday(const Date d);//next sunday after d
	Date next_weekday(const Date& d);//next weekday after d

}//Chrono
