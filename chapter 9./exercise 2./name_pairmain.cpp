#include"name_pair.h"

int main()
{
	Name_pairs np;
	np.read_names();
	np.print();

	np.sort();

	np.print();

	keep_window_open();
	return 0;
}
