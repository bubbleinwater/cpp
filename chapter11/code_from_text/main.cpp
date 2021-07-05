#include"Punct_stream.h"

int main()
//given text input, produce a sorted list of all words in that text
//ignore punctuation and case differences
//eliminate duplicates from the output
{
	Punct_stream ps{ cin };
	ps.whitespace(";:,.?!()\"{}<>/&$@#%^*|~");//note \" means " in string

	ps.case_sensitive(false);
	cout << "please enter words \n";
	vector<string>vs;
	for (string word; ps >> word;)
		vs.push_back(word);//read words
	sort(vs.begin(), vs.end());//sort in lexicographical order
	for (int i = 0; i < vs.size(); ++i)//write dictionary
		if (i == 0 || vs[i] != vs[i - 1])cout << vs[i] << '\n';

	keep_window_open();
	return 0;
}