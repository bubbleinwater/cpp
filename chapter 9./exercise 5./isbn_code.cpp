/*
2019.feb.21
I'll add a function for dealing with ISBN codes

*/

#include"book_isbn_Header.h"

namespace Book {

	Book vectorofbooks;//without this, error:E0245 at the calling of "vB.push_back(new_book);".
                      //but I don't know that is it worth declaring this only for that 

	const Book& default_Book()
	{
		static Book sb {" "," "," ", "00000000", false };
	}


	Book::Book()//default constructor
		:isbn{ default_Book().ISBN() }
		,title{default_Book().TITLE()}
		,author{default_Book().AUTHOR()}
		,copyright_Date{default_Book().COPYRIGHT_DATE()}
		,is_checkedout{default_Book().IS_CHECKEDOUT()}
	{}


	Book::Book(string i, string t, string a, string c, bool is_c) //constructor
		: isbn{ i }, title{ t }, author{ a }, copyright_Date{ c }, is_checkedout{ is_c }
	{}


	void storing_book() {
		string i; string t; string a; string c; string checked_out; bool is_c;
		cout << "Enter \"ISBN\" \"Title\" \"Author\" \"Copyright date.\"";
		cout << "\nISBN: ";
		cin >> i;
		cout << "\nTitle: ";
		cin >> t;
		cout << "\nAuthor: ";
		cin >> a;
		cout << "\nCopyright date: ";
		cin >> c;
		cout << "\nif you have this book now Enter f,you don't have the book(just register) Enter t.\n";
		cin >> checked_out;
		
		if (checked_out == "t") { is_c = true; }
		else if (checked_out == "f") { is_c = false; }
		else throw Book::invalid_data(); 

		Book new_book{ i, t, a, c, is_c };
		vectorofbooks.vB.push_back(new_book);
		
	}

}
