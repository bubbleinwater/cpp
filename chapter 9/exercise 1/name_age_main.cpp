/*---------------------------------------------------------------
2019.jan.24
dear me from the future. or someone else
when I had wrote
#include"name_age.cpp"
error : LNK2005 and LNK1169
occured
at the drill chapter 9, I wrote like this but this kind of error did not occured.
I cannot understand!!!!!



commenting starts:
simple namne pairs holder

this program hold name and age pairs.

	Statement:
class Name_pairs
read_names()//this function read cin and push it back to vector<string> name. once user finish entering name, this function calls read_age() function for each names
read_age();
sort()
print()//this function prints names and ages out from vector<string> name and vector<double> age separately.

--------------------------------------------------------------
*/

#include"name_age.h"

int main()
{
	Name_pairs np;
	np.read_names();
	np.sort();
	np.print();

	keep_window_open();
	return 0;
}
