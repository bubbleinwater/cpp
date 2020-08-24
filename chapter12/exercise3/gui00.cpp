/*
* Date:8.21.2020
* 
exercise 3
Q.Draw your initials 150 pixels high.
Use a thick line.Draw each initial in a different color.

*/


#include"Simple_window.h"
#include"Graph.h"

int main()
{
	using namespace Graph_lib;
	Point tl{ 100,100 };
	Simple_window win{ tl,700,400,"Canvas" };

	Text first_t{ Point{50,150},"R" };
	first_t.set_color(Color::red);
	win.attach(first_t);
	first_t.set_font_size(209);//I've tried 150,250,230,220,210,
						//205,206,207,208,209 to find which
						//font size make my initial "R" 150 pixels high.
	first_t.set_style(Line_style(Line_style::solid));
	
	Text fam_t{ Point{250,150},"I" };
	fam_t.set_color(Color::blue);
	win.attach(fam_t);
	fam_t.set_font_size(209);//I've tried 209,205,208.
	fam_t.set_style(Line_style(Line_style::solid));//I couldn't figure it out how to use a thick line
	win.wait_for_button();
}