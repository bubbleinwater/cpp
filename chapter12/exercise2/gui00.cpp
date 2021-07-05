#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 100,100 };
	Simple_window win{ tl,700,400,"Canvas" };

	Graph_lib::Rectangle r{ Point{50,50},100,30 };
	r.set_color(Color::blue);
	win.attach(r);

	Text t{ Point{60,70},"Howdy!" };
	t.set_color(Color::black);
	win.attach(t);
	
	win.wait_for_button();
}