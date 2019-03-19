/*
2019.feb.21
I'll add a function for dealing with ISBN codes
2019.mar.3
dealing with LNK1120 and LNK 2019
2019.mar.10
add == != << operator for Book


2019.mar.19
I realize I don't need to write about vector here,it's up to library class
so I deleted vector.
the switch statement at Genre int_to_genre was wrong.I have to write digit without ' '.

now storing_book doesn't work.
I'll figure it out.
*/


#include"book_isbn_Header.h"


namespace Book {

	Book book;//without this, error:E0245 at the calling of "vB.push_back(new_book);".
                      //but I don't know that is it worth declaring this only for that 


	const Book& default_Book()
	{
		static Book sb {" "," "," ",Genre::others, "00000000", false };
		return sb;
	}

	void Book::checking_ISBN(string isbn) {//or should I write this function to return bool?
		if (!(isbn.size() == 13 || isbn.size() == 17)) { throw Book::invalid_isbn(); }

		if (isbn.size() == 13) {//x-xxxxxx-xx-x
			if(isbn[1] != '-') throw Book::invalid_isbn();
		}
		else if (isbn.size() == 17) {//xxx-x-xxxxxx-xx-x
			if (isbn[3] != '-') throw Book::invalid_isbn();
		}

		if (isbn[isbn.size() - 5] != '-')throw Book::invalid_isbn();
		if (isbn[isbn.size() - 2] != '-')throw Book::invalid_isbn();
	}

	void Book::checking_date(string d) {//better returning bool?
										//should this function accept 2019.3.4 and 19.03.04 and 19.3.4 too ?
										//should I make another function just for checking that is the character digit?
		if (d.size() != 10)throw Book::invalid_date();
		if (d[4] != '.' || d[7] != '.')throw Book::invalid_date();
	}

	Book::Book()//default constructor
		:isbn{ default_Book().ISBN() }
		,title{default_Book().TITLE()}
		,author{default_Book().AUTHOR()}
		,genre{default_Book().GENRE()}
		,copyright_Date{default_Book().COPYRIGHT_DATE()}
		,is_checkedout{default_Book().IS_CHECKEDOUT()}
	{}


	Book::Book(string i, string t, string a,Genre g, string c, bool is_c) //constructor
		: isbn{ i }, title{ t }, author{ a }, genre{ g }, copyright_Date{ c }, is_checkedout{ is_c }
	{}

	void Book::checkout(Book& checked_out) {
		checked_out.is_checkedout = false;
	}

	void Book::checkin(Book& checked_in) {
		checked_in.is_checkedout = true;
	}

	Genre int_to_genre(int i) {
		switch (i) {
		case 1:return Genre::fiction;
		case 2:return Genre::nonfiction;
		case 3:return Genre::periodical;
		case 4:return Genre::biography;
		case 5:return Genre::children;
		case 6:return Genre::others;
		}
	}
/*
	Genre string_to_genre(string s) {
		if (s == "fiction") { return Genre::fiction; }
		if (s == "nonfiction") { return Genre::nonfiction; }
		if (s == "periodical") { return Genre::periodical; }
		if (s == "biography") { return Genre::biography; }
		if (s == "children") { return Genre::children; }
	}
*/
	string genre_to_string(Genre g) {
		if (g == Genre::fiction) { return "fiction"; }
		else if (g == Genre::nonfiction) { return "nonfiction"; }
		else if (g == Genre::periodical) { return "periodical"; }
		else if (g == Genre::biography) { return "biography"; }
		else if (g == Genre::children) { return "children"; }
		else if (g == Genre::others) { return "others"; }
		else error("error at genre_to_string");
	}


	Book& Book::storing_book() {
		string i; string t; string a; int g; Genre ge; string c; string checked_out; bool is_c;
		cout << "Enter \"ISBN\" \"Title\" \"Author\" \"Copyright date.\"";
		cout << "\nISBN(x-xxxxxx-xx-x or xxx-x-xxxxxx-xx-x style): ";
		cin >> i;
		checking_ISBN(i);
		cout << "\nTitle: ";
		cin >> t;
		cout << "\nAuthor: ";
		cin >> a;
		cout << "\nCopyright date(xxxx.xx.xx style): ";
		cin >> c;
		checking_date(c);
		cout << "\nif you have this book now Enter f,you don't have the book(just register) Enter t.\n";
		cin >> checked_out;
		cout << "which genre? fiction(1),nonfiction(2),periodical(3),biography(4),children(5) \n";
		cin >> g;
		ge = int_to_genre(g);


		if (checked_out == "t") { is_c = true; }
		else if (checked_out == "f") { is_c = false; }
		else throw Book::invalid_data(); 

		Book new_book{ i, t, a, ge, c, is_c };
		return new_book;
//		book.push_back(new_book);
		
//		for (int i = 0; i < book.size(); ++i)
//			cout << book[i];
	}

	bool operator==(const Book& a, const Book& b){
		return a.ISBN() == b.ISBN()
			&& a.AUTHOR() == b.AUTHOR()
			&& a.TITLE() == b.TITLE()
			&& a.COPYRIGHT_DATE() == b.COPYRIGHT_DATE();
	}

	bool operator!=(const Book& a, const Book& b) {
		return !(a == b);
	}


	ostream& operator<<(ostream& os, const Book& a) {
		return os << "TITLE: " << a.TITLE()
			<< "\nAUTHOR: " << a.AUTHOR()
			<< "\nISBN: " << a.ISBN()
			<< "\nGENRE: " << genre_to_string(a.GENRE())
			<<'\n';
	}

}
