#include"std_lib_facilities.h"

class Date {
	int y, m, d;

public:
	Date(int yy, int mm, int dd)
		:y{yy},m{mm},d{dd}
	{}
  
//----------------------------------when I wrote like this,not like as described above
//	public:
//	Date(int y,int m,int d);
//	Date();
//---------------------------------LNK2019 and LNK 1120 error occured


	void add_day(int n);
	int year(){return y;}
	int month(){ return m; }
	int day(){ return d; }
};

ostream& operator <<(ostream& os, const Date& dd);
