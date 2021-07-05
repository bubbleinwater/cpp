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

2019.mar.24
storing_book is now working.
I think storing_book function belongs helper function,
so I removed this function from Book class.
and put it within the scope of the namespace of Book.

I thought I should represent << operator only for Genre.
but I did not use this way. I'm using genre_to_string function.

I struggled to use storing_book function. the reason why was
I thought the function which access the variables at the
private: part within the scope of Book has to be put the public: part
within the scope of Book.
Since I thought like that I was not able to realize that I should write 
the argument pass by reference.
Like Book& storing_book(Book& b);
Not like Book& storing_book(Book b);


and at the
	ostream& operator<<(ostream& os, const Book& a) 
---------------------------------------------------------------------
			cout << (a.IS_CHECKEDOUT())? "\non loan": "\nloanable";
			cout << "\n";
---------------------------------------------------------------------does not work

I used this to know int-char match
	char a = 'a';
	int aa = a;
	char z = 'z';
	int zz = z;
	char A = 'A';
	int AA = A;
	char Z = 'Z';
	int ZZ = Z;
	cout << "a: " << aa << "z: " << zz << "A: " << AA << "Z: " << ZZ << "\n";

	char zero = 0;
	char one = 1;
	char nine = '	';

	int ze = zero;
	int on = one;
	int ni = nine;

	cout <<"0: "<< ze <<"1: "<< on <<"9: "<< ni << "\n";
but I realize that if I hit the F5(debug) I needn't to write this

2019.mar.25
I think the fuction
void Book::checking_ISBN(string isbn) {}
is a little bit mess.

I modified checking_date(string d); fuction to enable to use 2019-03-25 style

today, I added checking_genre(string i,Genre g); function.
so now this program can compare the Genre with the ISBN code. 
I searched on the internet,
int char_to_int( char ch ) { return c - '0';}
char int_to_char( int i ){return char( '0' + i );}

*/


#include"isbn_code.h"


namespace Book {

	Book book;

	const Book& default_Book()
	{
		static Book sb {" "," "," ",Genre::others, "00000000", false };
		return sb;
	}

	void Book::checking_ISBN(string isbn) {//or should I write this function to return bool?
		if (isbn.size() != 13 && isbn.size() != 17) throw Book::invalid_isbn();

		if (isbn.size() == 13) {//x-xxxxxx-xx-x
			if (isbn[isbn.size() - 12] != '-') throw Book::invalid_isbn();
			if (isbn[isbn.size() - 5] != '-')throw Book::invalid_isbn();
			if (isbn[isbn.size() - 2] != '-')throw Book::invalid_isbn();

		}
		else if (isbn.size() == 17) {//xxx-x-xxxxxx-xx-x
			if (isbn[isbn.size() - 14] != '-') throw Book::invalid_isbn();
			if (isbn[isbn.size() - 5] != '-')throw Book::invalid_isbn();
			if (isbn[isbn.size() - 2] != '-')throw Book::invalid_isbn();
		}

		for (int i = 2; i < isbn.size() + 1; ++i) {//isbn[isbn.size() - 1] will be a digit or a letter. so i starts from 2

			switch (isbn[isbn.size() - i]){
			case '0':case '1':case '2':case '3':case '4':
			case '5':case '6':case '7':case '8':case '9':
			case '-':
				break;
			default:
				throw Book::invalid_isbn();
			}
		}

//this part check the x (from n-n-n-x) presents in the range of A-Z or a-z or 0-9 
		if( 48 <= isbn[isbn.size() - 1] && isbn[isbn.size() - 1] <= 57){}
		else if(65 <= isbn[isbn.size() - 1] && isbn[isbn.size() - 1] <= 90){}
		else if(97 <= isbn[isbn.size() - 1] && isbn[isbn.size() - 1] <= 122){}
		else throw Book::invalid_isbn();
	}

	void Book::checking_date(string d)	{//better returning bool?
										//should this function accept 2019.3.4 and 19.03.04 and 19.3.4 too ?
										//should I make another function just for checking that is the character digit?
		if (d.size() != 10) { throw Book::invalid_date(); }
//		if (d[4] != '.' || d[7] != '.')throw Book::invalid_date();
		switch (d[4]) {
		case '-':case '.':
			break;
		default: throw Book::invalid_date(); 
		}
		switch (d[7]) {
		case '-':case '.':
			break;
		default: throw Book::invalid_date(); 
		}
	}

	void checking_genre(string isbn, Genre g) {
		int ten = isbn[isbn.size() - 4] - '0';
		int one = isbn[isbn.size() - 3] - '0';
		int genre_int = 10 * ten + one;

		if(genre_int - int(g) == 0){}
		else throw Book::invalid_data();
	}

	Book::Book()//default constructor
		:isbn{ default_Book().ISBN() }
		,title{default_Book().TITLE()}
		,author{default_Book().AUTHOR()}
		,genre{default_Book().GENRE()}
		,copyright_Date{default_Book().COPYRIGHT_DATE()}
		,is_checkedout{default_Book().IS_CHECKEDOUT()}
	{}


	Book::Book(string i, string t, string a,Genre ge, string c, bool is_c) //constructor
		: isbn{ i },
		title{ t },
		author{ a },
		genre{ ge },
		copyright_Date{ c },
		is_checkedout{ is_c }
	{}

	void Book::checkout(Book& checked_out) {
		checked_out.is_checkedout = false;
	}

	void Book::checkin(Book& checked_in) {
		checked_in.is_checkedout = true;
	}

	Genre int_to_genre(int i) {
		switch (i) {
		case 1:return Genre::fiction; break;
		case 2:return Genre::nonfiction; break;
		case 3:return Genre::periodical; break;
		case 4:return Genre::biography; break;
		case 5:return Genre::children; break;
//		case 6:
			return Genre::others; break;
		}
		return Genre::others;
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
		else {error("error at genre_to_string");
		return 0;
	}
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
		return os << "\nTITLE: " << a.TITLE()
			<< "\nAUTHOR: " << a.AUTHOR()
			<< "\nISBN: " << a.ISBN()
			<< "\nGENRE: "
			<< genre_to_string(a.GENRE())
			<< "\nCOPYRIGHT DATE: "
			<< a.COPYRIGHT_DATE()
//			cout << (a.IS_CHECKEDOUT())? "\non loan": "\nloanable"; 
			<< "\n";
	}


	Book& storing_book(Book& b) {
		string i; string t; string a; int g; string c; string checked_out; bool is_c;
		cout << "Enter \"ISBN\" \"Title\" \"Author\" \"Copyright date.\"";
		cout << "\nISBN(x-xxxxxx-xx-x or xxx-x-xxxxxx-xx-x style): ";
		cin >> i;
		b.checking_ISBN(i);
		cout << "\nTitle: ";
		cin >> t;
		cout << "\nAuthor: ";
		cin >> a;
		cout << "\nCopyright date(xxxx.xx.xx style): ";
		cin >> c;
		b.checking_date(c);
		cout << "\nIf this book is now on loan enter t.if it's loanable enter f.\n";
		cin >> checked_out;
		if (checked_out == "t") { is_c = true; }
		else if (checked_out == "f") { is_c = false; }
		else throw Book::Book::invalid_data();

		cout << "which genre? fiction(1),nonfiction(2),periodical(3),biography(4),children(5) \n";
		cin >> g;
		Genre ge = int_to_genre(g);
		checking_genre(i, ge);


		b = { i, t, a, ge, c, is_c };
		
		return b;
	}
}
