#include"../../std_lib_facilities.h"

int main()
{
	string s;
	cout << "Please enter some sentences. enter | for end entering.\n";
	for (char ch; cin.get(ch);) {
		if (ch == '|')break;

		if (ch == '\"') {
			s += '\"';
			for (char ch; cin.get(ch);) {
				if (isalpha(ch)) {
					if (isupper(ch))s += tolower(ch);
					else s += ch;
				}
				else s += ch;

				if (ch == '\"')s += ch; break;//just	if(ch == '\"')break;	still works for here.
				//I couldn't figure it out why.
			}
		}
		else if (ch == '.') { s += ' '; }
		else if (ch == ';') { s += ' '; }
		else if (ch == ',') { s += ' '; }
		else if (ch == '?') { s += ' '; }
		else if (ch == '-') { s += ' '; }
		else if (ch == '\'') { s += ' '; }
		else if (isalpha(ch)) {

			if (ch == 'd' || ch == 'D') {//for don't
				char next_ch; cin.get(next_ch); 
				s += 'd';
				if (next_ch == 'o' || next_ch == 'O') {
					s += 'o';
					char d_next_ch; cin.get(d_next_ch);
					if (d_next_ch == 'n' || d_next_ch == 'N') {
						char dd_next_ch; cin.get(dd_next_ch);
						if (dd_next_ch == '\'') {
							char ddd_next_ch; cin.get(ddd_next_ch);
							if (ddd_next_ch == 't' || ddd_next_ch == 'T') {
								s += ' '; s += 'n'; s += 'o'; s += 't';
//								cin.get(next_ch);
							}
							else { cin.putback(ddd_next_ch); }
						}
						else { cin.putback(dd_next_ch); }
					}
					else { cin.putback(d_next_ch); }
				}
				else { /*cin.putback(next_ch);*/ }
//				s += ch;
			}//for don't;

			else if (ch == 'c' || ch == 'C') {//for can't
				char next_ch; cin.get(next_ch);
				s += 'c';
				if (next_ch == 'a' || next_ch == 'A') {
					s += 'a';
					char d_next_ch; cin.get(d_next_ch);
					if (d_next_ch == 'n' || d_next_ch == 'N') {
						s += 'n';
						char dd_next_ch; cin.get(dd_next_ch);
						if (dd_next_ch == '\'') {
							char ddd_next_ch; cin.get(ddd_next_ch);
							if (ddd_next_ch == 't' || ddd_next_ch == 'T') {
								s += ' '; s += 'n'; s += 'o'; s += 't';
								//								cin.get(next_ch);
							}
							else { cin.putback(ddd_next_ch); }
						}
						else { cin.putback(dd_next_ch); }
					}
					else { /*cin.putback(d_next_ch);*/ }
				}
				else { /*cin.putback(next_ch);*/ }
				//				s += ch;
			}//for can't;

			else s += ch;

			char next_ch; cin.get(next_ch);
			if (next_ch == '-') {
				char d_next_ch; cin.get(d_next_ch);
				if (isalpha(d_next_ch)) { s += next_ch; s += d_next_ch; /*s += tmp;*/ }
				else {
					cin.putback(d_next_ch);
					cin.putback(next_ch);
					//					s += ch;
				}
			}
			else { cin.putback(next_ch); /*s += ch;*/ }
		}
		else if (isupper(ch)) { s += tolower(ch); }
		else s += ch;
	}

	cout << "that will be\n" << s << '\n';

	keep_window_open();
	return 0;
}