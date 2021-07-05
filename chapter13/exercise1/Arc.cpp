#include"Graph.h"
#include"std_lib_facilities.h"
#include"Point.h"
#include<cmath>

class AArc{
public:
	AArc(Graph_lib::Point pp, int ww, int hh, int s, int e) :p{ pp }, w{ ww }, h{ hh }, start{ s }, end{ e } {}

//	fl_arc(500, 500, 100, 200, 0, 180);
// example of half way ellipse
	void draw_Arc() { fl_arc(p.x,p.y, w, h, start, end); }//fl_arc(p, w, h, start, end); wouldn't work

private:
	Graph_lib::Point p;
	int w;
	int h;
	int start;
	int end;
};