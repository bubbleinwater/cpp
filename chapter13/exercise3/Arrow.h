#include"Graph.h"

namespace Graph_lib {
	
	struct Arrow : Shape {
		Arrow(Point p1, Point p2) { add(p1); add(p2); Arrow_head(); }
		void draw_lines()const;

		void Arrow_head();

		Point end1;
		Point end2;
	};
	
	
/*
1/10 back from arrow head point
L^2 = (p2.x - p1.x)^2 + (p2.y - p1.y)^2

L = sqrt( @ )
L / 10

p1.x + ( p2.x - p1.x )* 9 / 10



*/
	
	
		struct Arrows : Shape {
			Arrows(){}
			Arrows(initializer_list<Point> lst) : Shape{ lst } { if (lst.size() % 2) error("odd number of points for Lines"); }
	
			void draw_lines()const;
			void add(Point p1, Point p2) { Shape::add(p1); Shape::add(p2); }
	};
	

}


