#include"Graph.h"
#include"std_lib_facilities.h"
#include<cmath>
#include"Arc.h"

namespace Graph_lib {

	struct Boxb : Shape {
		//top left and bottom right of the square bounding the box
		Boxb(Point tl, Point br)
			:topl{ tl }, topr{ br.x,tl.y }, botr{ br }, botl{ tl.x,br.y }
		{
//			c_a.add(topl, topr, botr, botl);
			/*didn't work
			lines.add(Point{ topl.x + 5,topl.y }, Point{ topr.x - 5,topr.y });
			lines.add(Point{ topr.x ,topr.y + 5 }, Point{ topr.x,botr.y - 5 });
			lines.add(Point{ botr.x -5,botr.y }, Point{ botl.x + 5,botl.y });
			lines.add(Point{ botl.x ,botl.y -5}, Point{ topl.x ,topl.y +5 });
			*/
			add(Point{ topl.x + 5,topl.y });
			add(Point{ topr.x - 5,topr.y });
			add(Point{ topr.x ,topr.y + 5 });
			add(Point{ topr.x,botr.y - 5 });
			add(Point{ botr.x - 5,botr.y });
			add(Point{ botl.x + 5,botl.y });
			add(Point{ botl.x ,botl.y - 5 });
			add(Point{ topl.x ,topl.y + 5 });

		}
/*		Box(Point tl, int width, int height)
			:topl{ tl }, topr{ tl.x + width,tl.y }, botr{ tl.x + width,tl.y + height }
			, botl{ tl.x,tl.y + height }
		{	
			c_a.add(topl, topr, botr, botl);
			lines.add(Point{ topl.x + 5,topl.y }, Point{ topr.x - 5,topr.y });
			lines.add(Point{ topr.x ,topr.y + 5 }, Point{ topr.x,botr.y - 5 });
			lines.add(Point{ botr.x - 5,botr.y }, Point{ botl.x + 5,botl.y });
			lines.add(Point{ botl.x ,botl.y - 5 }, Point{ topl.x ,topl.y + 5 });
			}
			*/
		void draw_lines()const;

//		Lines lines;
		Point topl, topr, botr, botl;
//		corner_Arcs c_a;
	};
}
