#include"Money.h"

namespace Money {
	Money::Money()
		:amount_of_money{0}
	{}

	Money::Money(string c,long int m)
	{
		currency = c;
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

	Money kroner_to_dollar(Money kroner) {
		//	Money result = { "USD",("USD",kroner) * 6.95 };
		if (kroner.CURRENCY() == "USD") { return kroner; }
		else {
			double num = kroner.AOM() * 6.95;
			int i = 0;
			for (; i < num; ++i) {}
			num -= i;
			if (num < 0.5) {//rounds down
				Money result = { "USD",i };
				return result;
			}
			else {//or rounds up
				Money result = { "USD",(i + 1) };
				return result;
			}
		}
	}
	ostream& operator<<(ostream& os, Money& m) {
		Money tmp = kroner_to_dollar(m);
//		if (tmp.CURRENCY() == "KKD") { m = kroner_to_dollar(tmp); }

		if (tmp.CURRENCY() == "USD") {
			if (tmp.CENT() < 10) {
				return os << "USD" << tmp.DOLLAR() << ".0" << tmp.CENT() << "\n";
			}
			else { return os << "USD" << tmp.DOLLAR() << "." << tmp.CENT() << "\n"; }
		}
		else { throw Money::Invalid(); }
	}


	istream& operator>>(istream& is, Money& m) {
		long int dollar, cent, result;
		char ch1 = ' ';
		string st1;

//123.05 should be 12305 .and 123.4 should be 1234 not 12304
//,but I could not figure it out. so user has to enter $123.40 for $123.4 
		while (is >> ch1) {
			if (ch1 != '.') {
				switch (ch1) {
				case'1':case'2': case'3':case'4':case'5':
				case'6':case'7':case'8':case'9':case'0':
					cin.putback(ch1);
					is >> dollar;
					break;
				default:
					st1 += ch1;
				}
			}
			else if (ch1 == '.') {
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
					m = { st1,result };
					return is;
				}
				else if (1000 < cent) { throw Money::Invalid(); }
				else {
					result = (dollar * 100) + cent;
					m = { st1,result };
					return is;
				}
			}
			else {
				throw Money::Invalid();
			}
		}
	}

	Money& operator+(Money& a, Money& b) {
		if (a.CURRENCY() == "KKD") { a = kroner_to_dollar(a); }
		if (b.CURRENCY() == "KKD") { b = kroner_to_dollar(b); }
		
		Money result;
		result = 
//		{"USD",((a.DOLLAR() + b.DOLLAR()) * 100 + (a.CENT() + b.CENT())) };
		{"USD", a.AOM() + b.AOM()};
		cout << "for check: " << result;
		return result;
	}

	Money& operator-(Money a, Money b) {
		Money tmp = a;
		if (tmp.CURRENCY() == "KKD") { a = kroner_to_dollar(tmp); }
		tmp = b;
		if (tmp.CURRENCY() == "KKD") { b = kroner_to_dollar(tmp); }

		Money result;
		result = {"USD",((a.DOLLAR() - b.DOLLAR()) * 100 + (a.CENT() - b.CENT()))};
		if (result.AOM() < 0) { throw Money::Invalid(); }
		return result;
	}

	Money& operator*(Money a, double d) {
		Money tmp = a;
		if (tmp.CURRENCY() == "KKD") {
			a = kroner_to_dollar(tmp); 
		}

		double num = a.AOM() * d;
		int i = 0;
		for (; i < num; ++i) {
		}
		num -= i;
		if(num < 0.5){//rounds down
			Money result = { "USD",i };
			return result;
		}
		else {//or rounds up
			Money result = { "USD",i + 1 };
			return result;
		}
	}
}