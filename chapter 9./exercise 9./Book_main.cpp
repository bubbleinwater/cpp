#include "isbn_code.h"

int main()
try {

	Book::Library library_for_vector;

	string st = "";
	while (st != "exit") {
		cout << "Please enter, addbook or addpatron or displaybooks or displaypatrons or exit.\n";
		cin >> st;
		if (st == "addbook") {
			Book::Book bookisbn;
			library_for_vector.add_book(bookisbn);
		}
		else if (st == "addpatron") {
			Book::Patron pt;
			library_for_vector.add_patron(pt);
		}
		else if (st == "displaybooks") {
			library_for_vector.display_books();
		}
		else if (st == "displaypatrons") {
			library_for_vector.display_patrons();
		}
		else {}
	}
//	keep_window_open();
	return 0;
}
catch(Book::Book::invalid_date){
	cerr << "error:invalid date\n";
	keep_window_open();
}
catch (Book::Book::invalid_isbn) {
	cerr << "error:invalid ISBN\n";
	keep_window_open();
}
catch (Book::Book::invalid_data) {
	cerr << "error:invalid data\n";
	keep_window_open();
}
catch (Book::Book::invalid_genre) {
	cerr << "error:invalid Genre\n";
	keep_window_open();
}
catch (Chrono::Date::Invalid) {
	cerr << "error:invalid date at type Date\n";
	keep_window_open();
}
