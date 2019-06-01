#include"Money.h"

namespace Money {
	Money::Money()
		:amount_of_money{0}
	{}

	Money::Money(double m)
	{
		long int M = m;
		if ((m - M) == 0) { amount_of_money = { M }; }
		else if ((m - M) < 0.5) { amount_of_money = { M }; }
		else if ((m - M) >= 0.5) { amount_of_money = { M + 1 }; }
		else { throw Invalid(); }
	}

	long int Money::DOLLAR() {//return 0 if amount_of_money is less than 100  
		double M = amount_of_money;
		M /= 100;
		long int result = M;
		return result;
	}
	long int Money::CENT() {// return the value which does not reach 1 dollar.
		if (amount_of_money < 100) { return amount_of_money; }
		else {
			long int M = amount_of_money;
			M /= 100;
			M *= 100;
			return amount_of_money - M;
		}
	}

//helper function

	ostream& operator<<(ostream& os, Money& m) {
		if (m.CENT() < 10) {
			return os << "$" << m.DOLLAR() << ".0" << m.CENT() << "\n";
		}
		else { return os << "$" << m.DOLLAR() << "." << m.CENT() << "\n"; }
	}
/*{
		if (m.AOM() < 100) {
			if (m.AOM() < 10) { return os << "$0.0" << m.AOM() << "\n"; }
			else { return os << "$0." << m.AOM() << "\n"; }
		}
		else {
			double dollar = m.AOM();
			return os << "$" <<
		}
	}*/
}