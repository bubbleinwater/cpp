#include"point.h"
using namespace Pointp;

int main()
{
/*---
	cout << "Please enter seven (x,y) pairs.\n";
	
	vector<Point> original_points;
	Point p;
	for (int i = 0; i < 7;++i) {
		cin >> p;
		original_points.push_back(p);
	}

//	for (int i = 0; i < original_points.size(); ++i) {
//		cout << original_points[i];
//	}

	
	cout << "Please enter name of output file: ";
	string oname;
	cin >> oname;
	ofstream ost{ oname };//ost is an output stream for
							//a file named oname
	if (!ost)error("can't open output file", oname);

	for (Point p : original_points)
		ost << '(' << p.X() << ',' << p.Y() << ")\n";
	//close

---*/	
	cout << "Please enter input file name: ";
	string iname;
	cin >> iname;
	ifstream ist{ iname };//ist is an input stream for
							//the file named iname
	if (!ist)error("can't open input file", iname);

	vector<Point> processed_points;

	for (Point p; ist >> p;)
		processed_points.push_back(p);

	ist.close();

	for (int i = 0; i < processed_points.size(); ++i) {
		cout << processed_points[i];
	}

	keep_window_open();
	return 0;
}
