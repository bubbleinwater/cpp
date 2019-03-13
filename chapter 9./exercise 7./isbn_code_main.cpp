#include "isbn_code.h"

int main() 
try {

	Book::Book bookisbn;
	bookisbn.storing_book();

	for (int i = 0; i < bookisbn.vB.size(); ++i) {
		cout << bookisbn.vB[i];
	}

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
