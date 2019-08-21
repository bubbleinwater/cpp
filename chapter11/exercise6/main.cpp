/*
chapter 11 exercise 6
Q.
	Write a program that replaces punctuation with whitespace.
	Consider .(dot),	;(semicolon),	,(comma),
	?(question mark),	-(dash), '(single quote)
	punctuation characters. Don't modify characters within a pair of double quotes (").
	For example,
	" - don't use" the as-if rule.
	becomes
	" - don't use" the as if rule

*/

#include"../../std_lib_facilities.h"

int main()
{
	string s;
	cout << "Please enter some sentences. enter | for exit.\n";
	for (char ch; cin.get(ch);) {
		if (ch == '|')break;
		if (ch == '\"') {
			s += '\"';
			for (char ch; cin.get(ch);) {
				s += ch;
				if (ch == '\"')break;
			}
		}
		else if (ch == '.') { s += ' '; }
		else if (ch == ';') { s += ' '; }
		else if (ch == ',') { s += ' '; }
		else if (ch == '?') { s += ' '; }
		else if (ch == '-') { s += ' '; }
		else if (ch == '\'') { s += ' '; }
		else s += ch;
	}

	cout <<"that will be\n"<< s<<'\n';

	keep_window_open();
	return 0;
}