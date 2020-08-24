/*
* Date:8.21.2020
* 
exercise 4
Q.Draw a 3-by-3 tic tac toe board of alternating white and red squares.

A.
00|01|02
10|11|12
20|21|22
*/


#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 100,100 };
	Simple_window win{ tl,700,400,"Canvas" };
	
	constexpr int w = 50;//width
	constexpr int h = 50;//height

	Graph_lib::Point pTL{ 30,30 };
	
	Graph_lib::Rectangle r00{ pTL,w,h };
//	r00.set_color(Color::black);
	r00.set_fill_color(Color::red);
	win.attach(r00);

	Graph_lib::Rectangle r01{ Point{pTL.x+w,pTL.y},w,h };
//	r01.set_color(Color::invisible);
	r01.set_fill_color(Color::white);
	win.attach(r01);

	Graph_lib::Rectangle r02{ Point{pTL.x + 2*w,pTL.y},w,h };
//	r02.set_color(Color::black);
	r02.set_fill_color(Color::red);
	win.attach(r02);

	Graph_lib::Rectangle r10{ Point{pTL.x ,pTL.y + h},w,h };
//	r10.set_color(Color::black);
	r10.set_fill_color(Color::white);
	win.attach(r10);

	Graph_lib::Rectangle r11{ Point{pTL.x + w,pTL.y + h},w,h };
//	r11.set_color(Color::black);
	r11.set_fill_color(Color::red);
	win.attach(r11);

	Graph_lib::Rectangle r12{ Point{pTL.x + 2 * w,pTL.y + h},w,h };
//	r12.set_color(Color::black);
	r12.set_fill_color(Color::white);
	win.attach(r12);

	Graph_lib::Rectangle r20{ Point{pTL.x ,pTL.y + 2 * h},w,h };
//	r20.set_color(Color::black);
	r20.set_fill_color(Color::red);
	win.attach(r20);

	Graph_lib::Rectangle r21{ Point{pTL.x + w,pTL.y + 2 * h},w,h };
//	r21.set_color(Color::black);
	r21.set_fill_color(Color::white);
	win.attach(r21);

	Graph_lib::Rectangle r22{ Point{pTL.x + 2 * w,pTL.y + 2 * h},w,h };
//	r22.set_color(Color::black);
	r22.set_fill_color(Color::red);
	win.attach(r22);

	Line l01{ Point{pTL.x + w,pTL.y} ,Point{pTL.x + w,pTL.y + 3 * h} };
	l01.set_color(Color::black);
	win.attach(l01);

	Line l02{ Point{pTL.x + 2 * w,pTL.y} ,Point{pTL.x + 2 * w,pTL.y + 3 * h} };
	l02.set_color(Color::black);
	win.attach(l02);

	Line l11{ Point{pTL.x,pTL.y + h} ,Point{pTL.x + 3 * w,pTL.y + h} };
	l11.set_color(Color::black);
	win.attach(l11);

	Line l12{ Point{pTL.x,pTL.y +2 * h} ,Point{pTL.x + 3 * w,pTL.y + 2 * h} };
	l12.set_color(Color::black);
	win.attach(l12);

	win.wait_for_button();
}