/*
Q.--
Write some code to print the number 1234567.89 three times,
first using defaultfloat,next fixed,then scientific forms.
Which output form presents the user with the most accurate representation?
Explain why.
----

My answer
first defaultfloat one is going to be printed using only six digits and
the second fixed one is going to be printed only six digits after the decimal point and
third scientific one have the same aspect as the fixed one which is the number after
the dicimal point will be printed only six digits,but the difference between
scientific and fixed which scientific form is to move the decimal point to right after the
first digit and that was made fixed form won  
*/


#include"../../std_lib_facilities.h"

int main()
{
	cout << 1234567.89 <<"\t(defaultfloat)"<<'\n'
		<<fixed<< 1234567.89 <<"\t(fixed)"<< '\n' 
		<<scientific << 1234567.89 <<"\t(scientific)"<< '\n';


	keep_window_open();
	return 0;
}