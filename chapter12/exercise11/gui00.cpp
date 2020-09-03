/*
date 9.3.2020

Q.	Draw a series of regular polygons, one inside the other.
	The innermost should be an equilateral triangle, enclosed
	by a square, enclosed by a pentagon, etc.
	For the mathematically adept only:
	let all the points of each N-polygon touch sides
	of the (N + 1)-polygon. Hint: The trigonometric
	functions will be found in <cmath>

A.
I am not the mathematically adept.

*/

#include"Simple_window.h"
#include"Graph.h"
#include<cmath>

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };
	Simple_window win{ tl,x_max() - 20,y_max() - 60,"Canvas" };

	Point center{ win.x_max() / 2 ,win.y_max() / 2 };

	constexpr double pi = 3.14159265;

	Graph_lib::Polygon poly1;//regular triangle, corner 50
	double tpx1, tpy1;
	tpx1 = center.x + 50 * cos(pi / 2);
	tpy1 = center.y - 1 * 50 * sin(pi / 2);
	double tpx2, tpy2;
	tpx2 = center.x + 50 * sin(pi / 3);
	tpy2 = center.y + 50 * cos(pi / 3);
	double tpx3, tpy3;
	tpx3 = center.x - 50 * sin(pi / 3);
	tpy3 = center.y + 50 * cos(pi / 3);
	
	poly1.add(Point{ int(tpx1),int(tpy1) });
	poly1.add(Point{ int(tpx2),int(tpy2) });
	poly1.add(Point{ int(tpx3),int(tpy3) });
	poly1.set_color(Color::blue);
	win.attach(poly1);
	//-------
//	Circle c(Point{ center.x,center.y }, 50);
//	c.set_color(Color::red);
//	win.attach(c);
	//-------wrote for checking and this made me ummmmmmm...

	constexpr double root2 = 1.414;

	Graph_lib::Polygon poly2;// square, center to corner 55*sqrt(2)
	poly2.add(Point{ center.x - 55,center.y - 55 });
	poly2.add(Point{ center.x + 55,center.y - 55 });
	poly2.add(Point{ center.x + 55,center.y + 55});
	poly2.add(Point{ center.x - 55,center.y + 55 });
	poly2.set_color(Color::black);
	win.attach(poly2);


	Graph_lib::Polygon poly3;//pentagon
	double ppx1, ppy1,ppx2,ppy2,ppx3,ppy3,ppx4,ppy4,ppx5,ppy5;
	ppx1 = center.x;
	ppy1 = center.y - 105.0;//s^2 = 105^2 + 105^2 - 2*105*105*cos(2*pi/5)
	ppx2 = center.x + sin((pi - (2 * pi / 5))/2) * sqrt(105.0 * 105 + 105.0 * 105 - 2 * 105.0 * 105 * cos(2 * pi / 5));
	ppy2 = center.y - 105.0 + cos((pi - (2 * pi / 5)) / 2) * sqrt(105.0 * 105 + 105.0 * 105 - 2.0 * 105 * 105 * cos(2 * pi / 5));
	ppx3 = center.x + 105 * sin(2 * pi / 10);
	ppy3 = center.y + 105 * cos(2 * pi / 10);
	ppx4 = center.x - 105 * sin(2 * pi / 10);
	ppy4 = center.y + 105 * cos(2 * pi / 10);
	ppx5 = center.x - sin((pi - (2 * pi / 5)) / 2) * sqrt(105.0 * 105 + 105.0 * 105 - 2 * 105.0 * 105 * cos(2 * pi / 5));
	ppy5 = center.y - 105.0 + cos((pi - (2 * pi / 5)) / 2) * sqrt(105.0 * 105 + 105.0 * 105 - 2.0 * 105 * 105 * cos(2 * pi / 5));


	poly3.add(Point{ int(ppx1) ,int(ppy1) });
	poly3.add(Point{ int(ppx2),int(ppy2) });
	poly3.add(Point{ int(ppx3),int(ppy3) });
	poly3.add(Point{ int(ppx4),int(ppy4) });
	poly3.add(Point{ int(ppx5),int(ppy5) });
	poly3.set_color(Color::black);
	win.attach(poly3);

	//-------
//	Circle c(Point{ center.x,center.y },105);
//	c.set_color(Color::red);
//	win.attach(c);
	//-------

		
	win.wait_for_button();
}