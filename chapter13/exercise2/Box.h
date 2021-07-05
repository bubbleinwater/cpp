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
			if (p2.x - p1.x <= p2.y - p1.y)radius = (p2.x - p1.x) / 50.0;
			else radius = (p2.y - p1.y) / 50.0;
		}
		Boxb(Point p1, int w, int h) :topl{ p1 }, wid{ w }, hei{ h }{
			if (w <= h)radius = w / 50.0;
			else radius = h / 50.0;
		}

		void draw_lines()const;

		Point topl;
		int wid;
		int hei;
		double radius;

	};
}