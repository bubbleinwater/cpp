/*
2019.feb.21
dealing with ISBN-code for library

2019.feb.23
add comment
add check in and out code

*/


#include"std_lib_facilities.h"

namespace Book {

	class Book {
	public:
		class invalid_data {};//for throwing exception
		string ISBN()const { return isbn; }
		string TITLE()const { return title; }
		string AUTHOR() const { return author; }
		string COPYRIGHT_DATE()const { return copyright_Date; }
		bool IS_CHECKEDOUT()const { return is_checkedout; }//when you call this, this function return you 
		void storing_book();//add new book's data
		vector<Book> vB;
		bool checkout(Book checked_out);//to checkout 
		bool checkin(Book checked_in);//to checkin

		Book();
		Book(string i, string t, string a, string c, bool is_c);

	private:
		string isbn;
		string title;
		string author;
		string copyright_Date;
		bool is_checkedout;

	};
  
}//book
