/*
date 8.24.2020

Q.	Display an image on the screen, e.g.,a photo of a friend.
Label the image both with a title on the window and with a capition in the window.

A.

*/

#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };

	Simple_window win{ tl,x_max() - 20,y_max() - 60,"Canvas" };

	Image ii{ Point{10,10},"RED.jpg" };
	win.attach(ii);
	win.set_label("RED");

	Text t{ Point{430,350},("K and T") };
	t.set_color(Color::white);
	t.set_style(Line_style(Line_style::dash, 300));
	win.attach(t);

	win.wait_for_button();
}