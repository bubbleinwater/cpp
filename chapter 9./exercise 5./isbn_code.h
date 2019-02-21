/*
2019.feb.21
dealing with ISBN-code for library


*/


#include"std_lib_facilities.h"

namespace Book {

	class Book {
	public:
		class invalid_data{};
		string ISBN()const { return isbn; }
		string TITLE()const { return title; }
		string AUTHOR() const { return author; }
		string COPYRIGHT_DATE()const { return copyright_Date; }
		bool IS_CHECKEDOUT()const { return is_checkedout; }
		void storing_book();
		vector<Book> vB;

		Book();//default constructor
		Book(string i, string t, string a, string c, bool is_c);//constructor

	private:
		string isbn;
		string title;
		string author;
		string copyright_Date;
		bool is_checkedout;

	};
  
}//book
