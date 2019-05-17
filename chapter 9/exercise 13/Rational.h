/*
2019,may,14
for this program
	int num1, num2;
	char op;
	cin >> num1 >> op >> num2;
	cout << '\n' << num1 << " " << op << " " << num2;
input 1+2[enter]
will make
output 1 + 2

2019.may.15
does assignment mean copying?

2019.may.17
I added
	istream& operator>>(istream& is, Rational& r);
*/


#include"../../std_lib_facilities.h"

namespace Rational {
	class Rational {
	public:
		class invalid{};
		Rational();
		Rational(int nume,char oper, int deno);
		int NUMERATOR() { return numerator; }
		char OP() { return op; }
		int DENOMINATOR() { return denominator; }
		
	private:
		int numerator;
		char op;
		int denominator;
	};

	ostream& operator<<(ostream& os, Rational r);
	istream& operator>>(istream& is, Rational& r);

//	Rational operator+(Rational r1, Rational r2);
}