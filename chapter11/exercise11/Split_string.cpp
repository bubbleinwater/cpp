//#include"../../std_lib_facilities.h"
#include"isthis_whitespace.h"



vector<string> split(const string& s,const string& w) {
	vector<string> store_sep_st;
	char ch;

	istringstream is{ s };

	string tmp = " ";
	while(is >> ch){
		if (is_white(ch,w)) { store_sep_st.push_back(tmp); tmp = " "; }
		else tmp += ch;
	} store_sep_st.push_back(tmp);

	return store_sep_st;
}