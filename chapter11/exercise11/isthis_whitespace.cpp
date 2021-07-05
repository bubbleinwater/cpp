#include"../../std_lib_facilities.h"

bool is_white(char ch,const string& w) {
	string white = w;

	for (char c : white)
		if (ch == c)return true;

	return false;
}