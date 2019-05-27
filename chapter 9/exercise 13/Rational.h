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

2019.may.18
added addition

I added one member fuction called reduction()
and I think it is better when I write this function as
	Rational& reduction();
not as
	Rational reduction();

2019.may.19
added subtraction
Is there any better way than write separately for the negative number? 

I added multiplication
I have not decided whether this function include reduction() or not

maybe not

for me at the date may 18
write WHY

2019.may.24
I couldn't figure out why at the main function
//#1
	cout << "reduces to " << (ra1 - ra2).reduction();
//#2
	cout << (ra1 - ra2).reduction();
#1 didn't work ,but #2 work.

so I have to write as like
cout << "reduces to ";
cout << (ra1 - ra2).reduction();

at the function called reduction()
I'm solving the problem caused when the number could be divided twice.
like 49/49

I realize that I totally forgot about assignment before returning the value
	numerator = tmp.NUMERATOR(); denominator = tmp.DENOMINATOR();

2019.may.25
I'm trying to provide equality operator

2019.may.27
today, I added function to conversion rational to double
reference http://www.cplusplus.com/doc/tutorial/typecasting/

*/


#include"../../std_lib_facilities.h"

namespace Rational {
	class Rational {
	public:
		class invalid{};
		Rational();
		Rational(int nume,char oper,int deno);
		int NUMERATOR() { return numerator; }
		char OP() { return op; }
		int DENOMINATOR() { return denominator; }
		Rational& reduction();

		operator double();

	private:
		int numerator;
		char op;
		int denominator;
	};


//helper functions
	ostream& operator<<(ostream& os, Rational r);
	istream& operator>>(istream& is, Rational& r);
	Rational operator+(Rational r, Rational l);
	Rational operator-(Rational r, Rational l);
	Rational operator*(Rational r, Rational l);
	Rational operator/(Rational r, Rational l);
	bool operator==(Rational r, Rational l);
//	Rational operator+(Rational r1, Rational r2);
}