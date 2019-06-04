#include"Money.h"

namespace Money {
	Money::Money()
		:amount_of_money{0}
	{}

	Money::Money(long int m)
	{
		double mm = m;
		long int M = long int(mm);
		if ((mm - M) == 0) { amount_of_money = { M }; }
		else if ((mm - M) < 0.5) { amount_of_money = { M }; }
		else if ((mm - M) >= 0.5) { amount_of_money = { M + 1 }; }
		else { throw Invalid(); }
	}

	long int Money::DOLLAR() {//return 0 if amount_of_money is less than 100  
		double M = amount_of_money;
		M /= 100;
		long int result = long int (M);
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


	istream& operator>>(istream& is, Money& m) {
		long int dollar, cent,result;
		char ch1 = ' ';
		char ch2 = ' ';

		is >> ch1;
		if (ch1 != '$') { throw Money::Invalid(); }

		//123.05 will be 12305 .and 123.4 will be 1234 not 12304
		is >> dollar;
		is >> ch2;

		if (ch2 == '.') {
			is >> cent;
			if (100 < cent && cent < 1000) {
				long int tmp = cent;
				tmp /= 10;
				tmp *= 10;
				tmp -= cent;
				cent /= 10;
				if (tmp <= -5) { cent += 1; }//tmp will be negative number
				else {}
				result = (dollar * 100) + cent;
				m = { result };
				return is;
			}
			else if (1000 < cent) { throw Money::Invalid(); }
			else {
				result = (dollar * 100) + cent;
				m = { result };
				return is;
			}
			/*	else {
					result = (dollar * 100) + cent;
					m = { result };
					return is;
				}*/
		}
		else if (ch2 == 'Ì') {
			cin.putback(ch2);
			result = dollar * 100;
			m = { result };
			return is;
		}
		else if (ch2 == '$') {
			cin.putback(ch2);
			result = dollar * 100;
			m = { result };
			return is;
		}
		else if (ch2 == ' ') {
			cin.putback(ch2);
			result = dollar * 100;
			m = { result };
			return is;
		}
		else {
			cin.putback(ch2);
			result = dollar * 100;
			m = { result };
			return is;
		}
	}
}