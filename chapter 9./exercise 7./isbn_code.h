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

		string ISBN()const { return isbn; }
		void checking_ISBN(string isbn);
		void checking_date(string d);
		string TITLE()const { return title; }
		string AUTHOR() const { return author; }
		Genre GENRE() const { return genre; }
		string COPYRIGHT_DATE()const { return copyright_Date; }
		bool IS_CHECKEDOUT()const { return is_checkedout; }//when you call this, this function return you 
		void storing_book();//add new book's data
		vector<Book> vB;
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

}
