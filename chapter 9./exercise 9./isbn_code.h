#include"std_lib_facilities.h"
#include"Chrono.h"

namespace Book {

	enum class Genre {
		fiction = 1, nonfiction, periodical, biography, children, others
	};

	class Book {
	public:
		class invalid_date {};//for throwing exception
		class invalid_isbn {};//invalid ISBN
		class invalid_data {};
		class invalid_genre {};//for invalid genre

		string ISBN()const { return isbn; }
		void checking_ISBN(string isbn);
		void checking_date(string d);
		void checking_genre(string isbn, Genre g);
		string TITLE()const { return title; }
		string AUTHOR() const { return author; }
		Genre GENRE() const { return genre; }
		string COPYRIGHT_DATE()const { return copyright_Date; }
		Chrono::Date Chrono_COPYRIGHT_DATE()const{ return chrono_copyright_Date; }
		bool IS_CHECKEDOUT()const { return is_checkedout; }//when you call this, this function return you 
		void checkout();//to checkout 
		void checkin();//to checkin

		Book();
		Book(string i, string t, string a,Genre g, Chrono::Date c, bool is_c);

	private:
		string isbn;
		string title;
		string author;
		Genre genre;
		string copyright_Date;
		Chrono::Date chrono_copyright_Date;
		bool is_checkedout;

	};

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);

	ostream& operator<<(ostream& os, const Book& a);

	class Patron {
	public:
		bool OWE_FEE() const{ return owe_fee; }
		string USER_NAME() const { return user_name; }
		string CARD_NUMBER() const { return card_number; }
		string FEE() const { return fee; }
		bool IN_THE_LIBRARY()const{ return in_the_library; }
		bool free(Patron p) { if (fee == "0")return true; }
		void set_fee(string f);

		Patron();
		Patron(bool o_f, string u_n, string c_n, string f, bool in_lib);

	private:
		bool owe_fee;
		string user_name;
		string card_number;
		string fee;
		bool in_the_library;

	};

	ostream& operator<<(ostream& os, const Patron& pt);


	struct Transaction {
		Book b;
		Patron p;
		Chrono::Date d;

		Transaction();
		Transaction(Book bb, Patron pp, Chrono::Date dd);
	};

	class Library {
	public:
		void add_book(Book b);
		void display_books();

		void add_patron(Patron pt);
		void display_patrons();

		void checkout_book(Book& b,Patron p);

		Library();
		Library(Book b,Patron p,Transaction t);

		vector<Book> v_b;
		vector<Patron> v_p;
		vector<Transaction> v_t;

	private:
		Book a_b;
		Patron a_p;
		Transaction a_t;
	};

}
