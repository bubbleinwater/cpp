#include"roman_numerals.h"

namespace Roman_num {

	Roman_int::Roman_int()
		:roman{0}
	{}

	Roman_int::Roman_int(string r)
		:roman{r}
	{}

	vector<string>ro_num = {
		"I","V","X","L","C","D","M"
	};

	int roman_index_returner(char r) {
		string rr = {r};
		for (int i = 0; i < ro_num.size(); ++i) {
			if (rr == ro_num[i])return i;
		}
		error("there is no such roman numerals.");
	}

	string Roman_int::ROMAN()const {
		return roman;
	}
	
	int Roman_int::as_int() {
		Roman_int rr = roman;
		if (rr == "nulla") { return 0; }//just for zero
		else if (rr == "I")return 1;
		else if (rr == "V")return 5;
		else if (rr == "X")return 10;
		else if (rr == "L")return 50;
		else if (rr == "C")return 100;
		else if (rr == "D")return 500;
		else if (rr == "M")return 1000;
		else {
			int sum = 0;
			for (int i = 0; i < rr.ROMAN().size(); ++i) {
				string tmp = { rr.ROMAN()[i] };
				Roman_int r = tmp;
				if (rr.ROMAN()[i + 1] && roman_index_returner(rr.ROMAN()[i]) < roman_index_returner(rr.ROMAN()[i + 1])) {
					int t = r.as_int();
					sum -= t;
				}
				else { 
					int t = r.as_int();
					sum += t;
				}
			}
			return sum;
		}
	}


	bool operator==(const Roman_int& l, const Roman_int& r) {
		if (l.ROMAN() == r.ROMAN())return true;
		else return false;
	}
	bool operator==(const Roman_int& l, string r) {
		if (l.ROMAN() == r)return true;
		else return false;
	}
	bool operator!=(const Roman_int& l, const Roman_int& r) {
		return !(l == r);
	}
	bool operator!=(const Roman_int& l, string r) {
		return !(l.ROMAN() == r);
	}


	istream& operator>>(istream& is, Roman_int& r) {
		string tmp;
		is >> tmp;
		if (!is)return is;
		r = Roman_int{ tmp };

		return is;
	}

	ostream& operator<<(ostream& os, Roman_int& r) {
		return os << r.ROMAN();
	}
}