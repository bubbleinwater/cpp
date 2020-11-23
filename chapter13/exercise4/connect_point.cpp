#include"Graph.h"

namespace Graph_lib {
	Point n(Rectangle& r) {
		Point n(r.point(0).x + (r.width()) / 2, r.point(0).y);
		return n;
	}
	Point s(Rectangle& r) {
		Point s(r.point(0).x + (r.width()) / 2, r.point(0).y + r.height());
		return s;
	}
	Point e(Rectangle& r) {
		Point e(r.point(0).x + r.width(), r.point(0).y + (r.height() / 2));
		return e;
	}
	Point w(Rectangle& r) {
		Point w(r.point(0).x, r.point(0).y + (r.height() / 2));
		return w;
	}
	Point center(Rectangle& r) {
		Point center(r.point(0).x + r.width() / 2, r.point(0).y + r.height() / 2);
		return center;
	}
	Point ne(Rectangle& r) {//top right
		Point ne(r.point(0).x + r.width(), r.point(0).y);
		return ne;
	}
	Point se(Rectangle& r) {//bottom right
		Point se(r.point(0).x + r.width(), r.point(0).y + r.height());
		return se;
	}
	Point sw(Rectangle& r) {//bottom left
		Point sw(r.point(0).x, r.point(0).y + r.height());
		return sw;
	}
	Point nw(Rectangle& r) {//top right
		Point nw(r.point(0).x, r.point(0).y);
		return nw;
	}
}