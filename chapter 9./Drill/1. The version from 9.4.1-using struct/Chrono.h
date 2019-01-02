#include"std_lib_facilities.h"

struct Date {
	int y;
	int m;
	int d;
};

void init_date(Date& dd, int y, int m, int d);

Date& add_day(Date& dd, int n);

ostream& operator<<(ostream& os, const Date& d);
