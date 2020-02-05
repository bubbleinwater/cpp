#include"../../std_lib_facilities.h"

bool is_white(char ch) {
	string white = ";:,./-?";

	for (char c : white)
		if (ch == c)return true;

	return false;
}