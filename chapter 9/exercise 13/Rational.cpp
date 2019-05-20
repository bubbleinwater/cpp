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

	Rational operator+(Rational r, Rational l) {
		Rational result;
		int num, den;
		num = (r.NUMERATOR()*l.DENOMINATOR()) + (r.DENOMINATOR()*l.NUMERATOR());
		den = r.DENOMINATOR()*l.DENOMINATOR();
		result = { num,'/',den };
		return result;
	}

	Rational operator-(Rational r, Rational l) {
		Rational result;
		int num, den;
		num = (r.NUMERATOR()*l.DENOMINATOR()) - (r.DENOMINATOR()*l.NUMERATOR());
		den = r.DENOMINATOR()*l.DENOMINATOR();
		result = { num,'/',den };
		return result;
	}
	Rational operator*(Rational r, Rational l) {
		Rational result = { r.NUMERATOR()*l.NUMERATOR(),'/',r.DENOMINATOR()*l.DENOMINATOR() };
		return result;
	}

	Rational Rational::reduction() {
		if (numerator < 0) {
			Rational tmp = { - numerator,'/',denominator };
			for (int i = 2; i <= tmp.NUMERATOR(); ++i) {
				if (tmp.NUMERATOR() % i == 0) {
					if (tmp.DENOMINATOR() < i) {}
					else {
						if (tmp.DENOMINATOR() % i == 0) {
							tmp = { - tmp.NUMERATOR() / i ,'/',tmp.DENOMINATOR() / i };
							tmp.reduction();
						}
						else {
							tmp = { - tmp.NUMERATOR(),'/',tmp.DENOMINATOR() };
							tmp.reduction();
						}
					}
				}else {}
			}
			if(tmp.numerator > 0){ tmp = { - tmp.NUMERATOR(),'/',tmp.DENOMINATOR() }; }
			return tmp;
		}
		else{
			Rational tmp = { numerator,'/',denominator };
			for (int i = 2; i <= tmp.NUMERATOR(); ++i) {
				if (tmp.NUMERATOR() % i == 0) {
					if (tmp.DENOMINATOR() < i) {}
					else {
						if (tmp.DENOMINATOR() % i == 0) {
							tmp = { (tmp.NUMERATOR() / i),'/',(tmp.DENOMINATOR() / i) };
							tmp.reduction();
						}
						else {}
					}
				}
				else{}
			}
			return tmp;
		}
	}
}

