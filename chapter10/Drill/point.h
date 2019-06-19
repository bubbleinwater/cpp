#include"../../std_lib_facilities.h"

namespace Pointp {

	class Point {
	public:
		Point();
		Point(int xx, int xy);
		int X() { return x; }
		int Y() { return y; }
	private:
		int x;
		int y;
	};

	istream& operator>>(istream& is, Point& p);
	ostream& operator<<(ostream& os, Point& p);
}