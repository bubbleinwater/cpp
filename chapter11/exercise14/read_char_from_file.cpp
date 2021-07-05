#include"../../std_lib_facilities.h"

class count_char {


public:

	count_char()
		:space{0}, alpha{0}, digit{0}, upper{0}, lower{0}, cntrl{0}, punct{0}, print{0}, graph{0}{}

	void is_what(char c) {
		if (isspace(c)) count_up("space");
		if (isalpha(c)) count_up("alpha");
		if (isdigit(c)) count_up("digit");
		if (isupper(c)) count_up("upper");
		if (islower(c)) count_up("lower");
//		if (isalnum(c))cout << c << " is a letter or a decimal digit.\n";
		if (iscntrl(c)) count_up("cntrl");
		if (ispunct(c)) count_up("punct");
		if (isprint(c)) count_up("print");
		if (isgraph(c)) count_up("graph");
	}

	void count_up(string s){
		if (s == "space")++space;
		else if (s == "alpha")++alpha;
		else if (s == "digit")++digit;
		else if (s == "upper")++upper;
		else if (s == "lower")++lower;
		else if (s == "cntrl")++cntrl;
		else if (s == "punct")++punct;
		else if (s == "print")++print;
		else if (s == "graph")++graph;
		else error("did not hit with any classification, ", s);
	}

	void writeout_count() {
		cout << "This file has\n"
			<< space << " spaces\n"
			<< alpha << " allphabets\n"
			<< digit << " digits\n"
			<< upper << " uppercase letters\n"
			<< lower << " lowercase letters\n"
			<< cntrl << " control characters\n"
			<< punct << " punctuations\n"
			<< print << " printable characters\n"
			<< graph << " not-space characters\n";
	}

private:
	int space, alpha, digit, upper, lower, cntrl, punct, print, graph;
};

int main() {
	cout << "Pleaes enter the input file name.\n";
	string iname;
	cin >> iname;
	ifstream ifs(iname);

	if (!ifs)error("can't open the file named ", iname);

	count_char cc;
	char c;
	while (ifs.good()) {
		ifs.get(c);
		cc.is_what(c);
	}

	cc.writeout_count();

	keep_window_open();
	return 0;

}