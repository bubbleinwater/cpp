#include"calculate_from_to_file.h"
using namespace calcu;

//Symbol_table St;

int main()
try {
//	St.define_name("k", 1000);
	calculate();

	keep_window_open();
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << endl;
	char c;
	while (cin >> c && c != ';');
	return 1;
}
catch (...) {
	cerr << "exception\n";
	char c;
	while (cin >> c && c != ';');
	return 2;
}