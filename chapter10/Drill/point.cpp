#include"point.h"

namespace Pointp {

	Point::Point()
		:x{ 0 }, y{ 0 }
	{}

	Point::Point(int xx, int yy)
		:x{ xx }, y{ yy }
	{}
	
	istream& operator>>(istream& is, Point& p) {
		char ch1, ch2, ch3;
		int xx, yy;
		is >> ch1 >> xx >> ch2 >> yy >> ch3;
		if (!is)return is;
		if (ch1 != '(' || ch2 != ',' || ch3 != ')') {
			is.clear(ios_base::failbit);
			return is;
		}
		p = { xx, yy };

		return is;
	}

	ostream& operator<<(ostream& os, Point& p) {
		return os << '(' << p.X() << ',' << p.Y() << ")\n";
	}

}