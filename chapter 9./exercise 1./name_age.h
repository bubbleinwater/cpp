#include"std_lib_facilities.h"


class Name_pairs {
public:

	Name_pairs(string nn, double aa);
	Name_pairs();
	void read_names();
	void read_ages();
	void print();
	void sort();

private:
	string a_name;
	double a_age;
	vector<string> name;
	vector<double> age;

};
