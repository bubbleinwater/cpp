/*
2019.jun.01
I tried
I should have represented input and output as dollars and cents. 

2019.jun.04
I thought that 

		if(!(is >> ch2)) {
			result = dollar * 100;
			m = { result };
			return is;
		}
after
	is >> dollar
work, but did not work. it seems that (is >> ch2) was executed
and did not finish so if() could not decide true or false
so user have to enter $XXX.XXX all the way

2019.jun.09
I added operator + ,* and -.but, at the main function,
	Money money1 = 12345;
	cout << money1 + 1.5;
does not work.
I still could not figure out why this kind of code doesn't work.

for now,at the operator- returning negative number throws exception

for the currency I modified operator>> but got a little bit mess

//--------------------------the part
	Money& kroner_to_dollar(Money& kroner) {
		Money result = kroner * 6.95;
		return result;//actually this function returns USD. not KKD
	}

	Money& operator*(Money a, double d) {
		Money tmp = a;
		if (tmp.CURRENCY() == "KKD") {
			a = kroner_to_dollar(tmp);
		}

//----------- cause stack overflow

cout <<sum inside the main function doesn't work
but cout <<"for check: " works.
WHY!!!!!!!!!

*/

#include"../../std_lib_facilities.h"

namespace Money {
	class Money {
	public:
		class Invalid{};
		Money();
		Money(string c,long int m);
		long int AOM() { return amount_of_money; }
		string CURRENCY() { return currency; }
		long int DOLLAR();
		long int CENT();
		
	private:
		string currency;
		long int amount_of_money;
	};

//helpernfunction
//all operator will change the currency kkd to usd

	ostream& operator<<(ostream& os, Money& m);
	istream& operator>>(istream& is, Money& m);
	Money& operator+(Money& a, Money& b);
	Money& operator-(Money a, Money b);
	Money& operator*(Money a, double d);
	Money kroner_to_dollar (Money kroner);

}