#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 100,100 };
	Simple_window win{ tl,700,400,"Canvas" };

	Graph_lib::Rectangle r{ Point{50,50},300,200 };
	r.set_color(Color::blue);
	win.attach(r);

	Graph_lib::Polygon poly;
	poly.add(Point{ 360,50 });
	poly.add(Point{ 360,250 });
	poly.add(Point{ 660,250 });//I wrote {660,50} for here
	poly.add(Point{ 660,50 });//and {660,250} for here first, so I got was not a rectangle.
	poly.set_color(Color::red);
	win.attach(poly);
	win.wait_for_button();
}