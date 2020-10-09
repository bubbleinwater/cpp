#include"Box.h"

namespace Graph_lib {

	void Box::draw_lines() const
	{
	//	lines.draw_lines();
//		c_a.draw_lines();

		c_a.draw_lines();
		if (color().visibility()) {
//			Shape::draw_lines();//write here only this will make the closed polyline
//			without the last line and also without corner arcs.

			corner_Arcs ca(topl, topr, botr, botl);

			for (int i = 1; i < number_of_points(); i += 2) {
				fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
			}
		}
	}
}