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

2019.jul.1

I should have written
	istream& operator>>(istream& is, Roman_int& r);
	ostream& operator<<(ostream& os, Roman_int& r);
not as
	istream& operator>>(istream& is, Roman_int r);
	ostream& operator<<(ostream& os, Roman_int r);
to avoid stack overflow

2019.jul.4
now I start to think about the way how to prevent styles like XXXX for 40
when the number comes from cin
2019.jul.6
I'm trying to add the fuction called roman_returner(int num);

2019.jul.10
skip this exercise for now

*/



#include"../../std_lib_facilities.h"

namespace Roman_num {

	class Roman_int {//only for less than 4000
	public:
		Roman_int(string r);
		Roman_int();
		string ROMAN()const;
		int as_int();
	private:
		string roman;
	};

	int roman_index_returner(char r);
	Roman_int roman_returner(int num);

	istream& operator>>(istream& is, Roman_int& r);
	ostream& operator<<(ostream& os, Roman_int& r);
	bool operator==(const Roman_int& l,const Roman_int& r);
	bool operator==(const Roman_int& l, string r);
	bool operator!=(const Roman_int& l, const Roman_int& r);
	bool operator!=(const Roman_int& l, string r);
}