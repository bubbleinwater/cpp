//#include "Graph.h"
//#include<map>
#include"Arc.h"

namespace Graph_lib{

	void Arc::draw_lines()const {
		if(color().visibility())
			fl_color(color().as_int());
		fl_arc(point(0).x, point(0).y, w + w, h + h, start, end);
	}


}