#include "isbn_code.h"


int main()
try {
	
	Book::Book bookisbn;
	cout << storing_book(bookisbn);

	Book::patron pt;	
	cout << set_patron(pt);



	keep_window_open();
	return 0;

}catch(Book::Book::invalid_date){
	cerr << "error:invalid date\n";
	keep_window_open();
}catch (Book::Book::invalid_isbn) {
	cerr << "error:invalid ISBN\n";
	keep_window_open();
}catch (Book::Book::invalid_data) {
	cerr << "error:invalid data\n";
	keep_window_open();
}catch (Book::Book::invalid_genre) {
	cerr << "error:invalid Genre\n";
	keep_window_open();
}
catch (Chrono::Date::Invalid) {
	cerr << "error:invalid date at type Date\n";
	keep_window_open();
}
