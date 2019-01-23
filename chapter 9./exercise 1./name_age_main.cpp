//---------------------------------------------------------------
//2019.jan.24
//
//when I had wrote
//#include"name_age.cpp"
//error : LNK2005 and LNK1169
//occured
//at the drill chapter 9, I wrote like this but this kind of error did not occured.
//I cannot understand!!!!!
//---------------------------------------------------------------

#include"name_age.h"

int main()
{
	Name_pairs np;
	np.read_names();

	keep_window_open();
	return 0;
}
