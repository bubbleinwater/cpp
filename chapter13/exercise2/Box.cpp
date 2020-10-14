#include"Box.h"

namespace Graph_lib {
	void Boxb::draw_lines()const {
		constexpr double radius = 30;
		fl_line(topl.x + radius, topl.y, topl.x + wid - radius, topl.y);
		fl_line(topl.x + wid, topl.y + radius, topl.x + wid, topl.y + hei - radius);
		fl_line(topl.x + wid - radius, topl.y + hei, topl.x + radius, topl.y + hei);
		fl_line(topl.x, topl.y + hei - radius, topl.x, topl.y + radius);

		fl_arc(topl.x, topl.y, 2 * radius , 2 * radius , 90, 180);
		fl_arc(topl.x + wid - 2 * radius , topl.y, 2 * radius , 2 * radius , 0, 90);
		fl_arc(topl.x + wid - 2 * radius, topl.y + hei - 2 * radius, 2 * radius, 2 * radius, 270, 360);
		fl_arc(topl.x, topl.y + hei - 2 * radius, 2 * radius, 2 * radius, 180, 270);
	}
}