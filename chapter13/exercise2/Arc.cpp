//#include "Graph.h"
//#include<map>
#include"Arc.h"

namespace Graph_lib{

	void Arc::draw_lines()const {
		if(color().visibility())
			fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w + w, h + h, start, end);
	}

//	void corner_Arcs::draw_lines()const {
//		if (color().visibility())
/*			for (int i = 1; i < number_of_points(); i += 2) {
				double z = 90;
				double d = 0;
				if (i == 1)z = 90;
				else if (i == 3) {
					z = 0; d = 5;
				}
				else if (i == 5) {
					z = 270; d = 5;
				}
				else if (i == 7) {
					z = 180; d = 0;
				}
*///				fl_arc(point(i - 1).x + d , point(i - 1).y, 5, z, z + 90);//90,180, 0,90, 270,360, 180,270	
		//	}
//	}
}