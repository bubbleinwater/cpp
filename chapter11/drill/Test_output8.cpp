/*
chapter 11 drill 8.
Q.--
Try reading as octal,hexadecimal,etc.:
cin >> a >> oct >> b >> hex >> c >> d;
cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
Run this code with the input
1234 1234 1234 1234
Explain the results.
----

My answer
'a' assigned as decimal,'b' assigned as octal,'c' and 'd' assigned as hexadecimal
so output as	'dec'	'oct'	'hex'	'hex' style
*/



#include"../../std_lib_facilities.h"

int main()
{
	int a, b, c, d;

	cin >> a >> oct >> b >> hex >> c >> d;

	cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';

	keep_window_open();
	return 0;
}