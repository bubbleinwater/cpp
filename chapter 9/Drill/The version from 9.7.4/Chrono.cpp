
/*
//---from 9.7.1
vector<string>month_tbl;
ostream& operator<<(ostream& os, Month m) {
	return os << month_input_tbl[int(m)];
}
//---
*/

Date::Date()
	:y{default_date().year()},m{Month(default_date().month()-1)},d{default_date().day()}//month's index starts with 0 is so error-prone
{}

Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }//initialize data members
{
	if (!is_valid())throw Invalid{};//check for validity
}
bool Date::is_valid()//return true if date is valid
{
	if (int(m) < 0 || 11 < int(m))return false;
	if (d < 1 || 31 < d)return false;
	if (y < 0)return false;
}



Month operator++(Month& m) {
	m = (m == Month::dec) ? Month::jan : Month(int(m) + 1);
	return m;
}

void Date::add_day(int n) {
	
	if (31 < (d + n))
	{
		d += (n - 31);
		if (m == Month::dec) { m = Month::jan, ++y; }
		else { ++m; }
	}
	else d += n;
}


	ostream& operator<<(ostream& os, Date& dd) {
		return os << '(' << dd.year()
			<< ',' << dd.month()
			<< ',' << dd.day() << ')';
	};

