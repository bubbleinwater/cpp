/*
pseudo code
namespace Book{
Library
	:add_Book
	:display_Book
	:add_Patron
	:display_Patrons
	:vector_Book
	:vector_patron
	:vector_transaction
Book
Patron
Date
}


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

added patron class

2019.apr.02
I modified patron class.

2019.apr.06
I made this program better, but it's out of time.I'll go to bed now.soooo sleepy


2019.apr.08
I realize that I need to write comments in quite detail.
hey! me(apr.06) "better"? where?
me(apr.02) "modified patron"? what??? how?

today, I begun writing the struct Tansaction
I'm not sure It was needed to put Transaction body before Library body?
add_book() replaced storing_book() 
add_patron() replaced set_patron() too

the rest of this exercise is just add function to check out book and function for who leave the library.

oh I totally forgot that I made the struct called Transaction

in main()
			for (int i = 0; book != library_for_vector.v_b[i].TITLE()&&i < library_for_vector.v_b.size(); ++i) {
				b = library_for_vector.v_b[i];
			}
			for (int i = 0; name != library_for_vector.v_p[i].USER_NAME()&& i < library_for_vector.v_p.size(); ++i) {
				p = library_for_vector.v_p[i];
			}
didn't work well.I want to know why

2019.apr.10
checkout_book() didn't work, because I forgot assigning to the vector which included within the Library class.
and I realized class Date does not work well.which was solved by changing the function named string_to_Date()

*/


#include"isbn_code.h"


namespace Book {

	const Book& default_Book()
	{
		static Book sb {" "," "," ",Genre::others, Chrono::Date::Date(1994,Chrono::Month::jul,18 ),false };
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
		else throw Book::invalid_genre();
	}

	Book::Book()//default constructor
		:isbn{ default_Book().ISBN() }
		,title{default_Book().TITLE()}
		,author{default_Book().AUTHOR()}
		,genre{default_Book().GENRE()}
		/*,copyright_Date{default_Book().COPYRIGHT_DATE()}*/
		,chrono_copyright_Date{default_Book().Chrono_COPYRIGHT_DATE()}
		,is_checkedout{default_Book().IS_CHECKEDOUT()}
	{}


	Book::Book(string i, string t, string a,Genre ge, Chrono::Date c, bool is_c) //constructor
		: isbn{ i },
		title{ t },
		author{ a },
		genre{ ge },
		chrono_copyright_Date{ c },
		is_checkedout{ is_c }
	{}

//	void Book::checkout(Book& b) 

//	void Book::checkin(Book& b) 

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
		Chrono::Date d = a.Chrono_COPYRIGHT_DATE();//messy
		return os << "\nTITLE: " << a.TITLE()
			<< "\nAUTHOR: " << a.AUTHOR()
			<< "\nISBN: " << a.ISBN()
			<< "\nGENRE: "
			<< genre_to_string(a.GENRE())
			<< "\nCOPYRIGHT DATE: "
			<< d//Why just <<a.Chrono_COPYRIGHT_DATE() doesn't work? 
			<<"\nLoanable?: "
			<<a.LOANABLE()
			<< "\n";
	}

//----implementation of patron class's helperfunction starts here

	const Patron& default_patron()
	{
		static Patron d_pt{ false,"tomeiningen","0000","0000",false };
		return d_pt;
	}

	Patron::Patron()
		:owe_fee{ default_patron().OWE_FEE()}
		,user_name{ default_patron().USER_NAME() }
		,card_number{ default_patron().CARD_NUMBER() }
		, fee{ default_patron().FEE() }
		,in_the_library{default_patron().IN_THE_LIBRARY()}
	{}

		Patron::Patron(bool o_f ,string u_n,string c_n,string f,bool in_lib)
			:owe_fee{ o_f }
			,user_name {u_n}
			,card_number{c_n}
			,fee{f}
			,in_the_library{in_lib}
		{}


	void Patron::set_fee(string f) {
		if (!(owe_fee)) {
			fee = f;
			owe_fee = true;
		}
		else {
			cout << "changed fee from " << fee << " to " << f << ".\n";
			fee = f;
		}
	}


	ostream& operator<<(ostream& os, const Patron& pt) {
		if (pt.IN_THE_LIBRARY()) {
			return os << "\nNAME: " << pt.USER_NAME()
				<< "\nCARD NUMBER: " << pt.CARD_NUMBER()
				<< "\nFEE: " << pt.FEE()
				<< "\nIn the library?: "
				<< "YES\n";
		}
		else {
			return os << "\nNAME: " << pt.USER_NAME()
				<< "\nCARD NUMBER: " << pt.CARD_NUMBER()
				<< "\nFEE: " << pt.FEE()
				<< "\nIn the library?: "
				<< "NO\n";
		}
	}

	void Library::add_book(Book b){
		string i; string t; string a; int g; string c; Chrono::Date d_c; string checked_out; bool is_c;
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
		d_c.string_to_Date(c);//messy?
		cout << "\nIf this book is now on loan enter t.if it's loanable enter f.\n";
		cin >> checked_out;
		if (checked_out == "t") { is_c = true; }
		else if (checked_out == "f") { is_c = false; }
		else throw Book::Book::invalid_data();

		cout << "which genre? fiction(1),nonfiction(2),periodical(3),biography(4),children(5) \n";
		cin >> g;
		Genre ge = int_to_genre(g);
		checking_genre(i, ge);


		b = { i, t, a, ge, d_c, is_c };

		v_b.push_back(b);
	}


	void Library::display_books() {
		for (int i = 0; i < v_b.size(); ++i) {
			cout << v_b[i] << '\n';
		}
	}

	void Library::add_patron(Patron pt) {

		char fee_yes_no, inlib_yes_no;
		bool f_yes_no, i_yes_no;
		string name;
		string number;
		string fee = "0";

		cout << "\nPlease enter patron's info."
			<< "\nneed to pay?(t for yes,f for no): ";
		cin >> fee_yes_no;
		if (fee_yes_no == 't') { f_yes_no = true; }
		else { f_yes_no = false; }
		cout << "\nName: ";
		cin >> name;
		cout << "\nCard number: ";
		cin >> number;
		if (f_yes_no) {
			cout << "\nFee: ";
			cin >> fee;
		}
		cout << "\nin the library now?(t for yes,f for no): ";
		cin >> inlib_yes_no;
		if (inlib_yes_no == 't') { i_yes_no = true; }
		else i_yes_no = false;

		pt = { f_yes_no,name, number, fee,i_yes_no };

		v_p.push_back(pt);
	}

	void Library::display_patrons() {
		for (int i = 0; i < v_p.size(); ++i) {
			cout << v_p[i] << '\n';
		}
	}

	void Library::checkout_book(Book& b, Patron& p,vector<Book>& v_b) {
		if (b.IS_CHECKEDOUT()) { cout << "This book is now on loan.\n"; }
		else if (p.IN_THE_LIBRARY()) { 
			b.checkout();
//			cout <<"\ntest\n"<< b << "\ntest\n";
			for (int i = 0; i < v_b.size(); ++i) {
				if (b.TITLE() == v_b[i].TITLE()) {
					v_b[i] = b;
				}
			}
			cout << "Transaction completed.\n\n";
		}
		else {
			cout << "This person is not in this library now.\n";
		}
	}
	void Library::checkin_book(Book& b, Patron& p, vector<Book>& v_b) {
		if (b.IS_CHECKEDOUT() == false) { cout << "The book you have is not our library's book.\n"; }
		else if (p.IN_THE_LIBRARY()) {
			b.checkin();
			for (int i = 0; i < v_b.size(); ++i) {
				if (b.TITLE() == v_b[i].TITLE()) {
					v_b[i] = b;
				}
			}
			cout << "Transaction completed.\n\n";
		}
		else {
			cout << "This person is not in this library now.\n";
		}
	}

	Library::Library()
		:a_b{}
		,a_p{}
		,a_t{}
	{}

	Library::Library(Book b, Patron p, Transaction t)
		:a_b{b}
		,a_p{p}
		,a_t{t}
	{
		Library::v_b.push_back(b);
		Library::v_p.push_back(p);
		Library::v_t.push_back(t);
	}

	Transaction::Transaction()
		:b{}
		,p{}
		,d{}
	{}

	Transaction::Transaction(Book bb,Patron pp, Chrono::Date dd)
		:b{bb}
		,p{pp}
		,d{dd}
	{}
}
