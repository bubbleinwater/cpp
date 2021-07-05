/*
date 8.24.2020

Q.	Draw the Olympic five rings.
A.

*/

#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };

	Simple_window win{ tl,x_max() - 20,y_max() - 60,"Canvas" };

	Circle r_black{ Point{(x_max() - 20) / 2 ,(y_max() - 60) / 2 - 60 },80 };
	r_black.set_color(Color::black);
	r_black.set_style(Line_style(Line_style::solid, 7));
	win.attach(r_black);
	Circle r_blue{ Point{(x_max() - 20) / 2 - 190 ,(y_max() - 60) / 2 - 60 },80 };
	r_blue.set_color(Color::blue);
	r_blue.set_style(Line_style(Line_style::solid, 7));
	win.attach(r_blue);
	Circle r_red{ Point{(x_max() - 20) / 2 + 190,(y_max() - 60) / 2 - 60 },80 };
	r_red.set_color(Color::red);
	r_red.set_style(Line_style(Line_style::solid, 7));
	win.attach(r_red);
	Circle r_yellow{ Point{(x_max() - 20) / 2 - 95,(y_max() - 45) / 2 + 10 },80 };
	r_yellow.set_color(Color::yellow);
	r_yellow.set_style(Line_style(Line_style::solid, 7));
	win.attach(r_yellow);
	Circle r_green{ Point{(x_max() - 20) / 2 + 95,(y_max() - 45) / 2 + 10 },80 };
	r_green.set_color(Color::green);
	r_green.set_style(Line_style(Line_style::solid, 7));
	win.attach(r_green);

	win.wait_for_button();
}