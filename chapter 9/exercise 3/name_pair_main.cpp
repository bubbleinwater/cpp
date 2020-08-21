#include"name_pair.h"

int main()
{
	NameAge::Name_pairs np;
	np.read_names();
	np.read_ages();
	np.push_back_namepair();
	np.print();

	np.sort();
	np.print();

	keep_window_open();
	return 0;
}
