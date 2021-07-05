
#include"Simple_window.h"
#include"Graph.h"
#include<cmath>
#include"Arc.cpp"

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };
	Simple_window win{ tl,1000,800,"Canvas" };

	AArc arc(Point{ 500,500 }, 200, 100, 0, 180);
	arc.draw_Arc();

	win.wait_for_button();
}