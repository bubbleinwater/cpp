/*
simple calculator


this program implements a basic expression calculator.
input from cin out to cout.

the grammer for input

calculate{

Statement:
Expression
Print
Quit
sqrt()
pow()
=
help

}

Print:
;

Quit:
exit




Expression:
Term
Expression + Term
Expression - Term

Term:
Primary
Term * Primary
Term / Primary
Term % Primary

Primary:
Number
( Expression )
- Primary
+ Primary

Number:
floating-point-literal

Variable:
constants
variables


Input comes from sin through the Token_stream called ts.

2019.jul.12
at the function get case default I add from x and to y which return token
then for read and write, I make the function 

2019.jul.13
read_numbers() will return ifstream
*/

#include"../../std_lib_facilities.h"

namespace calcu{

class Token {
public:
	char kind;
	double value;
	string name;
	Token(char ch);// :kind{ ch } {}
	Token(char ch, double val);// :kind{ ch }, value{ val } {}
	Token(char ch, string n);// :kind{ ch }, name{ n } {}
};

class Token_stream {
public:
	Token_stream() :full(0), buffer(0) ,state_write_file(0){ }

	Token get();
	Token get(ifstream& ifs);
	void putback(Token t);
	//	void unget(Token t) { buffer = t; full = true; }
	void ignore(char);
	void change_state(bool b);
	bool STATE_write_file() { return state_write_file; }

private:
	bool full;
	Token buffer;
	bool state_write_file;
};

class Variable {
public:
	string name;
	double value;
	double const_value;
};

class Symbol_table {
public:
	vector<Variable> var_table;
	double get(string s);
	void set(char ch, string s);
	bool is_declared(string s);
	double define_name(string var, double val);
};

void calculate();
void clean_up_mess();
double statement();
double statement(ifstream& ifs);
double const_declaration();
double declaration();
double expression();
double term();
double primary();

double expression(ifstream& ifs);
double term(ifstream& ifs);
double primary(ifstream& ifs);

ifstream& read_numbers();
void write_output();

}