/*
2020. 10. 8
Arc should be the derive class from Shape
so I will change
*/

#include"Graph.h"
#include"std_lib_facilities.h"
//#include"Point.h"
#include<cmath>


namespace Graph_lib {

struct Arc : Shape {
	public:
		Arc(Graph_lib::Point pp, int ww, int hh, int s, int e) :w{ ww }, h{ hh }, start{ s }, end{ e }
		{ add( pp ); }

		//	fl_arc(500, 500, 100, 200, 0, 180);
		// example of half way ellipse

		void draw_lines()const;

//		void draw_Arc() { fl_arc(p.x, p.y, w, h, start, end); }
//fl_arc(p, w, h, start, end); wouldn't work
//
//AArc arc(Point{ 500,500 }, 200, 100, 0, 180);
//arc.draw_Arc();



	private:
//		Graph_lib::Point p;
		int w;
		int h;
		int start;
		int end;
	};
}