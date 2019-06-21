#include"store_temps.h"

int main()
{
	cout << "Please enter at least 50 reading_temperature.\n";

	vector<Reading> temps = fill_vector_from_cin() ;

	store_temps(temps);

	keep_window_open();
	return 0;
}