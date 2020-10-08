
#include"Simple_window.h"
#include"Graph.h"
#include<cmath>

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };
	Simple_window win{ tl,1000,800,"Canvas" };

	Lines grid;
	int x_grid = 100;
	int y_grid = 100;
	for (int x = x_grid; x <= 800; x += x_grid)
		grid.add(Point{ x,0 }, Point{ x,800 });
	for (int y = y_grid; y <= 800; y += y_grid)
		grid.add(Point{ 0,y }, Point{ 800,y });
	grid.set_color(Color::black);
	win.attach(grid);

	Vector_ref<Graph_lib::Rectangle> vr;

	for (int i = 0; i + 100 <= 800; i += 100) {
		vr.push_back(new Graph_lib::Rectangle { Point{i,i},Point{i + 100,i + 100} });
		vr[vr.size() -1].set_fill_color(Color::red);

		win.attach(vr[vr.size() - 1]);
	}


	win.wait_for_button();
}