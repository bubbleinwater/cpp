//file Chrono.h

namespace Chrono {

	enum class Month {
		jan = 1, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
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
	Date day_of_week(const Date& d);//day of week of d
	Date next_Sunday(const Date d);//next sunday after d
	Date next_weekday(const Date& d);//next weekday after d

}//Chrono
{
	if(m==feb && d == 29 && leapyear(y + n)){//beware of leap years!
		m = month::mar;//use March 1 instead of February 29
		d = 1;
	}
	y += n;
}

//helper function:
