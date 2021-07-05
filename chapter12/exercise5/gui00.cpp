/*
* Date:8.24.2020
* 
* exercise 5
*Q. Draw a red 1/4-inch frame around a rectangle
* that is three-quarters the height of your screen
* and two-thirds the width.
* 
* 
* 29.3 x 16.5
* 1920 x 1080
* 1px nearly eq 0.01527cm
* = 0.1527mm
* 
* 1/4 inch 41.58pixel I'll use 42pixel as 1/4-inch here
*	1
* 4		2
*	3

*/


#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 100,100 };
	Simple_window win{ tl,x_max()-10,y_max() - 50,"Canvas" };

	double d_rec_wid = x_max() / 3.0 * 2;
	double d_rec_hei = y_max() / 4.0 * 3;
	int rec_wid;
	int rec_hei;

	if (d_rec_wid - round(d_rec_wid) < 0.5)rec_wid = round(d_rec_wid);
	else rec_wid = round(d_rec_wid) + 1;
	if (d_rec_hei - round(d_rec_hei) < 0.5)rec_hei = round(d_rec_hei);
	else rec_hei = round(d_rec_hei) + 1;

	Point p_r{ 200,80 };
	Graph_lib::Rectangle r{ p_r,rec_wid,rec_hei };
	r.set_fill_color(Color::black);
	win.attach(r);

	Graph_lib::Rectangle r_f1{ Point{p_r.x - 42,p_r.y - 42},rec_wid + 2 * 42,42 };
	r_f1.set_fill_color(Color::red);
	win.attach(r_f1);
	Graph_lib::Rectangle r_f2{ Point{p_r.x + rec_wid,p_r.y -42},42,rec_hei + 2 * 42 };
	r_f2.set_fill_color(Color::red);
	win.attach(r_f2);
	Graph_lib::Rectangle r_f3{ Point{p_r.x - 42,p_r.y + rec_hei},rec_wid + 2 * 42,42 };
	r_f3.set_fill_color(Color::red);
	win.attach(r_f3);
	Graph_lib::Rectangle r_f4{ Point{p_r.x - 42,p_r.y - 42},42, rec_hei + 2 * 42 };
	r_f4.set_fill_color(Color::red);
	win.attach(r_f4);
	win.wait_for_button();
}