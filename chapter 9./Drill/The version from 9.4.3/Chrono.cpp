
void Date::add_day(int n) {
	if (31 < (d + n)) 
	{
		d += (n - 31); 
		(m == 12) ? m = 1, ++y : ++m;
	}
	else d += n;
}

	ostream& operator<<(ostream& os, Date& dd) {
		return os << '(' << dd.year()
			<< ',' << dd.month()
			<< ',' << dd.day() << ')';
	};
