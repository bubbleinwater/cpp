#include"name_age.h"

Name_pairs::Name_pairs(string nn,double aa)
	:a_name{nn},a_age{aa}
{}
Name_pairs::Name_pairs()
	:a_name{ "" }, a_age{ 0 }
{}



void Name_pairs::read_names() {

	cout << "Now you can enter names.when you want to finish entering name, please enter \"finish\".\n";
	while (a_name != "finish") {
		if (a_name == "finish"){}
		else {
			cin >> a_name;
			name.push_back(a_name);
		}
	}

	if (name.size() == 1)error("you did not enter even one name.");
	else read_ages();

}

void Name_pairs::read_ages() {
	cout << "Please enter the age of this person. ";
	for (int i = 0; i < name.size()-1;++i) {
		cout << "\n" << name[i] << " : ";
			cin >> a_age;

		age.push_back(a_age);
	}

	print();
}

void Name_pairs::print() {
	for (int i = 0; i < name.size()-1;++i) {
		cout << "(" << name[i] << "," << age[i] << ")"<<"\n";
	}
}
