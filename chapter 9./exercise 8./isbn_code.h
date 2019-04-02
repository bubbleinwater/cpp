#include"std_lib_facilities.h"

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
		bool IS_CHECKEDOUT()const { return is_checkedout; }//when you call this, this function return you 
		void checkout(Book& checked_out);//to checkout 
		void checkin(Book& checked_in);//to checkin

		Book();
		Book(string i, string t, string a,Genre g, string c, bool is_c);

	private:
		string isbn;
		string title;
		string author;
		Genre genre;
		string copyright_Date;
		bool is_checkedout;

	};

	bool operator==(const Book& a, const Book& b);
	bool operator!=(const Book& a, const Book& b);

	ostream& operator<<(ostream& os, const Book& a);

	Book& storing_book(Book& b);//add new book's data

	class patron {
	public:
		string USER_NAME() const { return user_name; }
		string CARD_NUMBER() const { return card_number; }
		string FEE() const { return fee; }
		bool free(patron p) { if (fee == "0")return true; }
		void set_fee(string f);

		patron();
		patron(string u_n, string c_n, string f);

	private:
		bool owe_fee;
		string user_name;
		string card_number;
		string fee;

	};

	patron& set_patron(patron& pt);
	ostream& operator<<(ostream& os, const patron& pt);

}
