#include"Box.h"

namespace Graph_lib {

	void Boxb::draw_lines() const
	{
	//	lines.draw_lines();
//		c_a.draw_lines();

		if (color().visibility()) {
//			Shape::draw_lines();//write here only this will make the closed polyline
//			without the last line and also without corner arcs.

//			corner_Arcs ca(topl, topr, botr, botl);


			for (int i = 1; i <= number_of_points(); i += 2) {
				double z = 90;
				double d = 0;
				if (i == 1)z = 90;
					if (i == 3) {
					z = 0; d = 5;
					}
					if (i == 5) {
					z = 270; d = 5;
					}
					if (i == 7) {
					z = 180; d = 0;
					}
				fl_arc(point(i - 1).x + d, point(i - 1).y, 5, z, z + 90);//90,180, 0,90, 270
				
				fl_line(point(i - 1).x, point(i - 1).y, point(i).x, point(i).y);
			}
		}
	}
}