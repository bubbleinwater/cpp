#include"../../std_lib_facilities.h"
#include"rev_string.h"

string rev_string(string& s) {
	char ch;

	for (int i = 1;i<=(s.size()/2);++i) {
		char tmp = s[s.size() - i];
		s[s.size() - i] = s[i - 1];
		s[i - 1] = tmp;
	}

	return s;
}