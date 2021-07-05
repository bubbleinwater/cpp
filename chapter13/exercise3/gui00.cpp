/*
Exercise 3.
Q Define a class Arrow, which draws a line with an arrowhead.


first, I will solve  the point 1/10 way back from the end point(which arrowhead starts)
*/




#include"Simple_window.h"
#include"Graph.h"
#include<cmath>
//#include"Arc.h"
#include"Arrow.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };
	Simple_window win{ tl,1000,800,"Canvas" };

	Arrow arr(Point{ 500, 300 }, Point{ 400, 400 });
	arr.set_color(Color::black);
	win.attach(arr);

	win.wait_for_button();
}
