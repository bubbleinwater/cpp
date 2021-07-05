//---------------------------------
//2019.jun.3
//
//I'm at the Drill of chapter 9
//C++ had been changed?
//I tried to use constructor within the scope of the struct Date, as I had written below,
//but link time error (?I think.) occured.LNK2019 and LNK1120. I'm not sure that the
//construtor made this linktime error.
//
//And I thought I had to write Date(); for Date tomorrow as default constructor, but 
//I don't have to write costructor here too.(I'm not sure too.)
//
//---------------------------------


#include"std_lib_facilities.h"

struct Date {
	int y, m, d;
//---------------------------------
//	Date(int y, int m, int d);      //error: LNK2019 and LNK 1120
//	Date();                         //but I don't know that the code written here really caused these errors or not.
//--------------------------------- 
	
	Date& add_day(Date& dd, int n);
};


ostream& operator<<(ostream& os, const Date& d);
