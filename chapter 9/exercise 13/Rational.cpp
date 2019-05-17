#include"Rational.h"


namespace Rational {

	Rational::Rational()
		:numerator{ 1 }
		, op{ '/' }
		, denominator{ 1 }
	{}

	Rational::Rational(int nume, char oper, int deno)
		: numerator{ nume }
		, op{ oper }
		, denominator{ deno }
	{if (oper != '/')throw invalid(); }



	//helper function
	ostream& operator<<(ostream& os, Rational r) {
		return os << r.NUMERATOR()
			<< r.OP()
			<< r.DENOMINATOR()
			<< '\n';
	}

	istream& operator>>(istream& is, Rational& r) {
		
		int num;// = r.NUMERATOR();
		char ch;// = r.OP();
		int den;// = r.DENOMINATOR();

		is >> num;
		is >> ch;
		is >> den;
		r = { num,ch,den };

		return is;
	}

	/*

		Rational operator+(Rational r1, Rational r2) {
			Rational result;
			while (r1.DENOMINATOR() != r2.DENOMINATOR()) {

			}
		}
		*/

}

