#include"Graph.h"


namespace Graph_lib {
	
	struct Boxb :Shape {
		Boxb(Point p1,Point p2,double rad):topl{p1},wid{p2.x - p1.x},hei{p2.y - p1.y},radius{rad}
		{

		}
		Boxb(Point p1,int w,int h,double rad):topl{p1},wid{w},hei{h}, radius{ rad }{
		}
		Boxb(Point p1, Point p2) :topl{ p1 }, wid{ p2.x - p1.x }, hei{ p2.y - p1.y }
		{

		}
		Boxb(Point p1, int w, int h) :topl{ p1 }, wid{ w }, hei{ h }{
		}

		void draw_lines()const;

		Point topl;
		int wid;
		int hei;
		double radius = 5;

	};
}