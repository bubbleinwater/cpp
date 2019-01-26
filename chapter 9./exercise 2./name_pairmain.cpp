/*
2019,jan,26
this version have got a little bit mess.
I think calculate function will make this version better.
it was difficult for me to decide how far calculate function should have.

the part
ostream& operator<<(ostream& os, const Name_pairs& np) {
	return os << "(" << np.Name_pairs::name_please() << "," << np.age_please()<<")";
}
puzzled me.
that was np.Name_pairs::name_please() notation and  I forgot const after the declaration of name_please
*/



#include"name_pair.h"

int main()
{
	Name_pairs np;
	np.read_names();
	np.read_ages();
	np.push_back_namepair();
	np.print();

	np.sort();

	np.print();

	keep_window_open();
	return 0;
}
