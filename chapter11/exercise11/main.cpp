#include"../../std_lib_facilities.h"
#include"Split_string.h"


int main()
{
	vector<string> s_v;
	vector<string>v_answer;
	string s;
	cout << "Enter a string type values.\nenter | for exit\n";
	
	while (cin.good()) {
		cin >> s;
		if (s == "|")break;
		s_v = split(s, "cg");
		for (int i = 0; i < s_v.size(); ++i) {
			v_answer.push_back(s_v[i]);
		}
	}

	for (int i = 0; i < v_answer.size(); ++i) {
		cout << v_answer[i]<<'\n';
	}

	keep_window_open();
	return 0;
}