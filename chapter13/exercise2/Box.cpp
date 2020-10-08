#include"Graph.h"
#include"std_lib_facilities.h"
#include<cmath>

namespace Graph_lib {


	struct Box : Shape {
	public:
		//top left and bottom right of the square bounding the box
		Box(Point tl, Point br)
			:topl{ tl }, topr{ br.x,tl.y }, botr{ br }, botl{ tl.x,br.y }{}
		Box(Point tl, int width, int height)
			:topl{ tl }, topr{ tl.x + width,tl.y }, botr{ tl.x + width,tl.y + height }
			, botl{ tl.x,tl.y + height }{}


	private:
		Lines lines;
		Point topl, topr, botr, botl;
	};



}