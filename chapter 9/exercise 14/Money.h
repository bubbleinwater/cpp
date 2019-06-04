/*
2019.jun.1
I tried
I should have represented input and output as dollars and cents. 

*/



#include"../../std_lib_facilities.h"

namespace Money {
	class Money {
	public:
		class Invalid{};
		Money();
		Money(double m);
		long int AOM() { return amount_of_money; }
		long int DOLLAR();
		long int CENT();

	private:
		long int amount_of_money;
	};

	//helpernfunction

	ostream& operator<<(ostream& os, Money& m);

}