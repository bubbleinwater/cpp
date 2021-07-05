#include "isbn_code.h"

int main()
try {

	Book::Library library_for_vector;
	vector<Book::Transaction> v_t;
	Book::Transaction t;

	string st = "";
	while (st != "exit") {
		cout << "Please enter, addbook or addpatron or displaybooks or displaypatrons\n"
			<< "or checkoutbook or checkinbook or displaytransaction or whoowefee or exit.\n";
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
		else if (st == "checkoutbook") {
			string book, name;
			cout << "Please enter your name and the book.\n";
			cin >> name >> book;
			Book::Book b;
			Book::Patron p;
			for (int i = 0; i < library_for_vector.v_b.size(); ++i) {
				if (book == library_for_vector.v_b[i].TITLE()) {
					b = library_for_vector.v_b[i];
				}
			}
			for (int i = 0; i < library_for_vector.v_p.size(); ++i) {
				if (name == library_for_vector.v_p[i].USER_NAME()) {
					p = library_for_vector.v_p[i];
				}
			}
			library_for_vector.checkout_book(b, p, library_for_vector.v_b);
			t = { b, p, b.Chrono_COPYRIGHT_DATE() };
			v_t.push_back(t);
		}
		else if (st == "checkinbook") {
			string book, name;
			cout << "Please enter your name and the book.\n";
			cin >> name >> book;
			Book::Book b;
			Book::Patron p;
			for (int i = 0; i < library_for_vector.v_b.size(); ++i) {
				if (book == library_for_vector.v_b[i].TITLE()) {
					b = library_for_vector.v_b[i];
				}
			}
			for (int i = 0; i < library_for_vector.v_p.size(); ++i) {
				if (name == library_for_vector.v_p[i].USER_NAME()) {
					p = library_for_vector.v_p[i];
				}
			}
			library_for_vector.checkin_book(b, p, library_for_vector.v_b);
			t = { b, p, b.Chrono_COPYRIGHT_DATE() };
			v_t.push_back(t);
		}
		else if (st == "displaytransaction") {
			for (int i = 0; i < v_t.size(); ++i) {
				cout << v_t[i] << "\n";
			}
		}
		else if (st == "whoowefee") {
			for (int i = 0; i < library_for_vector.v_p.size(); ++i) {
				if (library_for_vector.v_p[i].OWE_FEE()) {
					cout << library_for_vector.v_p[i] << "\n";
				}
			}
		}
		else {}
	}

	//	keep_window_open();
	return 0;

}
catch (Book::Book::invalid_date) {
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
