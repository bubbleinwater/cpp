#include"Arrow.h"

namespace Graph_lib{
	void Arrow::Arrow_head() {

		int mag = sqrt(pow(point(1).x - point(0).x, 2) + pow(point(1).y - point(0).y, 2));
		constexpr int a_size = 9;

		Point unit = Point{ (point(1).x - point(0).x) * a_size / mag, (point(1).y - point(0).y) * a_size / mag };

		Point perp1 = Point{ -unit.y, unit.x };
		Point perp2 = Point{ unit.y, -unit.x };

		end1 = { point(1).x + perp1.x - unit.x,point(1).y + perp1.y - unit.y };
		end2 = { point(1).x + perp2.x - unit.x,point(1).y + perp2.y - unit.y };

	}

	void Arrow::draw_lines()const {

		if (color().visibility()) {
			Shape::draw_lines();

			fl_line(point(1).x, point(1).y, end1.x, end1.y);
			fl_line(point(1).x, point(1).y, end2.x, end2.y);
	
		}
	}
}