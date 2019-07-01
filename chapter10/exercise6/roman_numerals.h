/*
2019.jun.29
I think I have to make some grammar


first I will erase all of the first code
then as the order of this

I < V
X < L
X < C
C < D
C < M

I will make this vector
	vector<string>ro_num = {
		"I","V","X","L","C","D","M"
	};

and compare one by one by the index

*/



#include"../../std_lib_facilities.h"

namespace Roman_num {

	class Roman_int {//only for less than 4000
	public:
		Roman_int(string r);
		Roman_int();
		int as_int();
	private:
		string roman;
	};

	int roman_index_returner(char r);

//	ostream operator<<(ostream& os, Roman_int);
//	ostream operator>>(istream& is, Roman_int);


}