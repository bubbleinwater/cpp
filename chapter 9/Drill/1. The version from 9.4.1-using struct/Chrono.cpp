
void init_date(Date& dd, int y, int m, int d) {
	if (y < 0)error("invalid state");
	dd.y = y;
	if (m < 1 || 12 < m)error("invalid state");
	dd.m = m;
	if (d < 1 || 31 < d)error("invalid state");
	dd.d = d;
}

Date& add_day(Date& dd, int n) {
	if (31 < dd.d + n)dd.d += (n - 31);
	else dd.d += n;

	return dd;
}

ostream& operator<<(ostream& os, const Date& dd) {
	return os << '(' << dd.y << ',' << dd.m << ',' << dd.d << ')';
};
