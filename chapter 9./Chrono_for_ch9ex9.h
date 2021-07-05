#include"std_lib_facilities.h"

namespace Chrono {

	enum class Month {
		jan, feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
	};

//I don't know why but static is needed here.I want to know why
	static vector<string>month_input_tbl = {
	"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"
	};



	class Date {
	public:
		class Invalid {};		//to be used as exception
		Date();//default constructor
		Date(int yy, Month mm, int dd);	//constructor:check for valid date and initialize
		void add_day(int n);
		int year()const { return y; }
		int month()const;
		int day()const { return d; }
		bool is_valid();		//return true if date is valid
		int month_to_int(string s)const;
		string int_to_month(int n)const;

	private:
		int y;
		Month m;
		int d;
	};


	Month operator++(Month& m);
	ostream& operator<<(ostream& os, Date& dd);
}
