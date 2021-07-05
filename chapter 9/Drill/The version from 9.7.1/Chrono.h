#include"std_lib_facilities.h"

enum class Month {
	jan , feb, mar, apr, may, jun, jul, aug, sep, oct, nov, dec
};

//from 11.10.3-------------------------------------------------------

vector<string>month_input_tbl = {
"jan","feb","mar","apr","may","jun","jul","aug","sep","oct","nov","dec"
};

int month_to_int(string s) {
	for (int i = 0; i < 12; ++i)
		if (month_input_tbl[i] == s)return (i+1);
	return -1;
}

string int_to_month(int n) {
if (n < 0 || 12 <= n)error("bad month index");
	return month_input_tbl[n];
}


//--------if I should have use this month_print_tbl, I think I have to rewrite enum class Month.right?
/*
vector<string>month_print_tbl = {
	"Janualy","February","March","April","May","June","July","August","September","October","November","December"
};

string int_to_month(int i)//months[0:11]
{
	if (i < 0 || 12 <= i)error("bad month index");
	return month_print_tbl[i];
}
*/
//--------
//-------------------------------------------------------------------


class Date {
public:
	class Invalid{};		//to be used as exception
	Date(int yy, Month mm, int dd);	//constructor:check for valid date and initialize
	void add_day(int n);
	int year(){return y;}
	int month() {                   //I think I've made this member function a little mess.
		string s = int_to_month(int(m)); 
		return month_to_int(s);
	}
	int day(){ return d; }

private:
	int y;
	Month m;
	int d;
	bool is_valid();		//return true if date is valid
};
