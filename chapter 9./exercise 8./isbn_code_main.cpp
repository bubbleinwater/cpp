#include "isbn_code.h"

int main() 
try {

	Book::Book bookisbn;
	bookisbn.storing_book();
	Book::Book bk = bookisbn;


	cout << bookisbn;

	keep_window_open();
	return 0;

}catch(Book::Book::invalid_date){
	cerr << "error::invalid date\n";
	keep_window_open();
}
catch (Book::Book::invalid_isbn) {
	cerr << "error::invalid ISBN\n";
	keep_window_open();
}
