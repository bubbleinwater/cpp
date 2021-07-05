

Date& add_day(Date& dd, int n) {
	if (31 < dd.d + n)dd.d += (n - 31);
	else dd.d += n;

	return dd;
}

ostream& operator<<(ostream& os, const Date& dd) {
	return os << '(' << dd.y << ',' << dd.m << ',' << dd.d << ')';
};
