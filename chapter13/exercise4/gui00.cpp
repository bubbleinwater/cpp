/*
Exercise 5.
Q Define the functions from exercise4 for a Circle
and an Ellipse. Place the connection points on or
outside the shape but not outside the bounding rectangle.


*/




#include"Simple_window.h"
#include"Graph.h"
#include<cmath>
#include"connect_point.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 30,70 };
	Simple_window win{ tl,900,700,"Canvas" };

	Graph_lib::Rectangle r(Point{ 70,300 }, Point{ 470,600 });
	r.set_color(Color::black);
	win.attach(r);
	Point ret{ n(r) };
	cout << "n() point of r is (" << ret.x << ","<< ret.y << ")\n";
	Point ret1{ s(r) };
	cout << "s() point of r is (" << ret1.x << "," << ret1.y << ")\n";
	Point ret2{ e(r) };
	cout << "e() point of r is (" << ret2.x << "," << ret2.y << ")\n";
	Point ret3{ w(r) };
	cout << "w() point of r is (" << ret3.x << "," << ret3.y << ")\n";
	Point ret4{ center(r) };
	cout << "center() point of r is (" << ret4.x << "," << ret4.y << ")\n";
	Point ret5{ ne(r) };
	cout << "ne() point of r is (" << ret5.x << "," << ret5.y << ")\n";
	Point ret6{ se(r) };
	cout << "se() point of r is (" << ret6.x << "," << ret6.y << ")\n";
	Point ret7{ sw(r) };
	cout << "sw() point of r is (" << ret7.x << "," << ret7.y << ")\n";
	Point ret8{ nw(r) };
	cout << "nw() point of r is (" << ret8.x << "," << ret8.y << ")\n";


	win.wait_for_button();
}
