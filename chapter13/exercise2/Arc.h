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
		Arc(Graph_lib::Point pp, int ww, int hh, int s, int e) :w{ ww }, h{ hh }, start{ s }, end{ e }
		{ add( pp ); }
		Arc() :w{ 0 }, h{ 0 }, start{ 0 }, end{ 0 }{add(Point{ 0,0 }); }


		//	fl_arc(500, 500, 100, 200, 0, 180);
		// example of half way ellipse

		void draw_lines()const;

//		void draw_Arc() { fl_arc(p.x, p.y, w, h, start, end); }
//		fl_arc(p, w, h, start, end); wouldn't work
//
//Arc arc(Point{ 500,500 }, 200, 100, 0, 180);
//arc.draw_Arc();



//		Graph_lib::Point p;
		int w;
		int h;
		int start;
		int end;
	};


struct corner_Arcs : Shape {//corner arc's radius will be 5
	corner_Arcs() {}
	corner_Arcs(Point tl, Point tr, Point br, Point bl) {
		add(tl, tr, br, bl);
	}
	corner_Arcs(initializer_list<Point> lst) :Shape{ lst } { if (lst.size() % 4)error("couldn't make box from that"); }

	void draw_lines() const;

	void add(Point topleft, Point topright, Point bottomright, Point bottomleft) {
		Shape::add(topleft);
		Shape::add(topright);
		Shape::add(bottomright);
		Shape::add(bottomleft);
	};

};

}