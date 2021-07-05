/*
date 8.24.2020

Q.	Draw a two-dimentional house seen from the front, the way a child would: 
with a door,two windows, and a roof with a chimney.
feel free to add details;maybe have "smoke" come out of the chimney.

A.

*/

#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 10,50 };
	Simple_window win{ tl,x_max() - 20,y_max() - 60,"Canvas" };

	Graph_lib::Polygon roof;
	Point top_of_roof{ x_max() / 2, 120 };

	Circle s1{ Point{x_max() / 2 + 190 , top_of_roof.y + -25},20 };
	s1.set_color(Color::black);
	s1.set_fill_color(Color::white);
	win.attach(s1);
	Circle s2{ Point{x_max() / 2 + 173 , top_of_roof.y + -49},8 };
	s2.set_color(Color::black);
	s2.set_fill_color(Color::white);
	win.attach(s2);
	Circle s3{ Point{x_max() / 2 + 175 , top_of_roof.y + -71},12 };
	s3.set_color(Color::black);
	s3.set_fill_color(Color::white);
	win.attach(s3);

	Circle s4{ Point{x_max() / 2 + 199 , top_of_roof.y + -88},25 };
	s4.set_color(Color::black);
	s4.set_fill_color(Color::white);
	win.attach(s4);
//I was not sure where to put chimney so I wrote about chimney after the code of the roof
//then I cut the code about chimney and paste here
	constexpr int chim = -35;//started here with 100(misunderstand),-100,-90,-80,-70,-55
	Graph_lib::Polygon chimney;
	chimney.add(Point{ x_max() / 2 + 150 , top_of_roof.y + chim });//here, for x I started with 150
	chimney.add(Point{ x_max() / 2 + 220 , top_of_roof.y + chim });//here 220
	chimney.add(Point{ x_max() / 2 + 220 , top_of_roof.y + chim + 110 });//for y with 150
	chimney.add(Point{ x_max() / 2 + 150 , top_of_roof.y + chim + 110 });
	chimney.set_fill_color(Color::white);
	win.attach(chimney);

	roof.add(top_of_roof);
	roof.add(Point{ x_max() / 2 - 500,top_of_roof.y + 160 });
	roof.add(Point{ x_max() / 2 + 500,top_of_roof.y + 160 });

	roof.set_fill_color(Color::black);
	win.attach(roof);

	Graph_lib::Rectangle home{ Point{x_max() / 2 - 350,top_of_roof.y + 160},700,450 };
	home.set_color(Color::black);
	home.set_fill_color(Color::blue);
	win.attach(home);

	Graph_lib::Rectangle window1{ Point{x_max() / 2 - 300,top_of_roof.y + 260},110,180 };
	window1.set_color(Color::black);
	window1.set_style(Line_style( Line_style::solid,7 ));
	window1.set_fill_color(Color::cyan);
	win.attach(window1);

	Graph_lib::Rectangle window2{ Point{x_max() / 2 - 110,top_of_roof.y + 260},110,180 };
	window2.set_color(Color::black);
	window2.set_style(Line_style(Line_style::solid, 7));
	window2.set_fill_color(Color::cyan);
	win.attach(window2);

	Graph_lib::Rectangle door{ Point{x_max() / 2 + 105, top_of_roof.y + 250},195,360 };
	door.set_fill_color(Color::black);
	win.attach(door);

	Circle knob{ Point{x_max() / 2 + 135,top_of_roof.y + 440},8 };
	knob.set_fill_color(Color::white);
	win.attach(knob);
	
	
	win.wait_for_button();
}