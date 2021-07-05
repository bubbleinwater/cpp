#include"std_lib_facilities.h"

namespace Book {

	class Book {
	public:
		class invalid_data {};//for throwing exception
		class invalid_isbn {};//invalid ISBN
		string ISBN()const { return isbn; }
		void checking_ISBN(string isbn);
		string TITLE()const { return title; }
		string AUTHOR() const { return author; }
		string COPYRIGHT_DATE()const { return copyright_Date; }
		bool IS_CHECKEDOUT()const { return is_checkedout; }//when you call this, this function return you 
		void storing_book();//add new book's data
		vector<Book> vB;
		void checkout(Book& checked_out);//to checkout 
		void checkin(Book& checked_in);//to checkin

		Book();
		Book(string i, string t, string a, string c, bool is_c);

	private:
		string isbn;
		string title;
		string author;
		string copyright_Date;
		bool is_checkedout;

	};

}
