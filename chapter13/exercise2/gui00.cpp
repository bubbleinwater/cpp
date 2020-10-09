/*
Exercise 2.
Q Draw a box with rounded corners. Define a class Box,
consisting of four lines andd four arcs.


*/




#include"Simple_window.h"
#include"Graph.h"
#include<cmath>
//#include"Arc.h"
#include"Box.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };
	Simple_window win{ tl,1000,800,"Canvas" };

//	Graph_lib::Arc a{ Point{300,400},120,120,0,180 };
//	a.set_color(Color::black);
//	win.attach(a);
	Box b(Point{ 50,100 }, Point{ 200,300 });
	b.set_color(Color::red);
	win.attach(b);


	win.wait_for_button();
}