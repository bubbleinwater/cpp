#include"std_lib_facilities.h"

namespace NameAge {

	class Name_pairs {

		string a_name;
		double a_age;
		vector<Name_pairs> name_pairs;
		vector<string> name;
		vector<double> age;

	public:

		Name_pairs(string nn, double aa);
		Name_pairs();
		void read_names();
		void read_ages();
		void push_back_namepair();
		void print();
		void sort();
		string name_please()const { return a_name; }
		double age_please()const { return a_age; }

	};

	bool operator==(const Name_pairs& a, const Name_pairs& b);
	bool operator!=(const Name_pairs& a, const Name_pairs& b);
	ostream& operator<<(ostream& os, const Name_pairs& np);
}
