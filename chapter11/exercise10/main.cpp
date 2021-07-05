#include"../../std_lib_facilities.h"
#include"Split_string.h"


int main()
{
	string s;
	cout << "Enter a string type values.\nenter | for exit\n";
	
	cin >> s;
	vector<string> s_v = split(s);

	for (int i = 0; i < s_v.size(); ++i) {
		cout << s_v[i]<<'\n';
	}

	keep_window_open();
	return 0;
}