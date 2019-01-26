#include"chap9ex1.h"

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

	if (name.size() == 1) error("error:you did not enter name yet.");
//	if (name[0] == "finish") error("error:you did not enter name yet.");
	
	else read_ages();
}

void Name_pairs::read_ages() {
	cout << "Please enter the age of this person. ";
	for (int i = 0; i < name.size() - 1; ++i) {
		cout << "\n" << name[i] << " : ";
		cin >> a_age;

		age.push_back(a_age);
	}

	for (int i = 0; i < name.size() - 1; ++i) {
		name_pairs.push_back(Name_pairs(name[i], age[i]));
	}
}

//void Name_pairs::print() {
//	for (int i = 0; i < name.size()-1;++i) {
//		cout << "(" << name[i] << "," << age[i] << ")"<<"\n";
//	}
//}

void Name_pairs::print() {
	for (int i = 0; i < name.size() - 1; ++i) {
		cout << Name_pairs::name_pairs[i] << "\n";
	}
}

ostream& operator<<(ostream& os, const Name_pairs& np) {
	return os << "(" << np.Name_pairs::name_please() << "," << np.age_please()<<")";
}


void Name_pairs::sort() {
	for (int i = 0; i < name.size()-1; ++i) {
		for (int j = i+1; j < name.size()-1; ++j) {
			if (name[i] > name[j]) {
				string s_tmp = name[i];
				double d_tmp = age[i];
 				name[i] = name[j];
				age[i] = age[j];
				name[j] = s_tmp;
				age[j] = d_tmp;
			}
		}
	}

	for (int i = 0; i < name.size() - 1; ++i) {
		name_pairs[i] = (Name_pairs(name[i], age[i]));
	}
}
