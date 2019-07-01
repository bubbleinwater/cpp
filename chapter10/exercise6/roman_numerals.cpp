#include"roman_numerals.h"

namespace Roman_num {

	Roman_int::Roman_int()
		:roman{0}
	{}

	Roman_int::Roman_int(string r)
		:roman{r}
	{}

//	vector<string>romannum_first_place_tbl = {
//		"I","II","III","IV","V","VI","VII","VIII","IX"
//	};

	vector<string>ro_num = {
		"I","V","X","L","C","D","M"
	};

	int roman_index_returner(char r) {
		string roman = {r};
		for (int i = 0; i < ro_num.size(); ++i) {
			if (roman == ro_num[i])return i;
		}
		error("there is no such roman numerals.");
	}
	
	
//no need any more
//	int I_V_part(string r) {
//		for (int i = 1; i <= 9; ++i) {// 1 for I, 2 for II ...9 for IX.
//			if (r == romannum_first_place_tbl[i - 1])return i;//see. 1 for I, 2 for II
//		}//[1:9]
//		return 0;//when its out of the range of [1:9]
//	}

//oh no I realized I have not dicided how to handle with when its like XC
//---------------------
/*	
	int roman_not_I_V_part(string without_first_roman) {
		if (without_first_roman == "nulla")return 0;
		else if (without_first_roman == "X")return 10;
		else if (without_first_roman == "L")return 50;
		else if (without_first_roman == "C")return 100;
		else if (without_first_roman == "D")return 500;
		else if (without_first_roman == "M")return 1000;
		else {
//			string first = { without_first_roman[0] };
			int num = 0;
			string check;
			for (int i = 0; i < without_first_roman.size(); ++i) {
				check = without_first_roman[i];
				num += roman_not_I_V_part({ without_first_roman[i] });
			}
			int num = roman_not_I_V_part();
			for (int i = 0; i < without_first_roman.size(); ++i) {

			}

		}
//------do until we hit on I or V
		int sum;
		string unit = "nulla";
		for(int i = 0; without_first_roman[i]!='I' || without_first_roman[i]!='V';++i){
			if (unit == "nulla") { unit = without_first_roman[i]; }
			else { unit += without_first_roman[i]; }//for example XX,LXX
		}
		int sum = roman_not_I_V_part(unit);
//-----

	}
//----------------------
	*/


	int Roman_int::as_int() {
		if (roman == "nulla") { return 0; }//just for zero
		else if (roman == "I")return 1;
		else if (roman == "V")return 5;
		else if (roman == "X")return 10;
		else if (roman == "L")return 50;
		else if (roman == "C")return 100;
		else if (roman == "D")return 500;
		else if (roman == "M")return 1000;
		else {
			int sum = 0;
			for (int i = 0; i < roman.size(); ++i) {
				string tmp = { roman[i] };
				Roman_int r = tmp;
				if (roman[i + 1] && roman_index_returner(roman[i]) < roman_index_returner(roman[i + 1])) {
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



//		int result = I_V_part(roman);//[1:9]?
//		if (result != 0) { return result; }

//when the result == 0 then the numrals doesn't fit [1:9] range
//so exe following sentence

//		if (roman[0] != 'I' && roman[0] != 'V') {
//			string not_I_V_roman;
//			for (int i = 0; i < roman.size(); ++i) {//like  X or XX or C etc..
//				not_I_V_roman += roman[i];
//			}
//			int roman_s = roman_not_I_V_part(roman);
//		}

	}

/*	ostream operator<<(ostream& os, Roman_int) {

	}
	ostream operator>>(istream& is, Roman_int) {

	}

*/


}