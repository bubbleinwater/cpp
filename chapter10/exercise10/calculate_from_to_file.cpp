#include"calculate_from_to_file.h"

namespace calcu {

	Token::Token(char ch)
		:kind{ ch }
	{}
	Token::Token(char ch, double val)
		:kind{ ch }, value{ val }
	{}
	Token::Token(char ch, string n)
		:kind{ ch }, name{ n }
	{}


	Token_stream ts;

	double Symbol_table::get(string s)
	{
		for (int i = 0; i < var_table.size(); ++i)
			if (var_table[i].name == s) return var_table[i].value;
		error("get: undefined name ", s);
	}

	void Symbol_table::set(char ch, string s)//when user use const keyword this function will be called 
	{
		Token t = { ch,s };
		/*	for (int i = 0; i <= var_table.size(); ++i)*/
		for (Variable& v : var_table)
			if (v.name == s) {
				if (!v.const_value)error("it's a const number");
			}
		ts.putback(t);
		//	error("set: undefined name ", s);
	}

	Symbol_table St;

	bool Symbol_table::is_declared(string s)
	{
		for (int i = 0; i < var_table.size(); ++i)
			if (var_table[i].name == s) return true;
		return false;
	}
	double Symbol_table::define_name(string var, double val)
	{
		if (St.is_declared(var))error(var, " declared twice");
		var_table.push_back(Variable{ var,val });
		return val;
	}


	const char let = '#';
	const char const_let = '$';
	const char quit = 'Q';
	const char print = ';';
	const char number = '8';
	const char name = 'a';
	const char help = 'h';
	const char read = 'r';
	const char write = 'w';

	double expression();
	//void Symbol_table::set(char ch, string s);

	void Token_stream::change_state(bool b) {
		state_write_file = b;
	}

//-------------?
	ifstream& read_numbers() {
		string iname;
		cin >> iname;
		ifstream ifs{ iname };
		if (!ifs)error("error opening file named ", iname);

		return ifs;
	}
//----------------

	Token Token_stream::get()
	{
		if (full) { full = false; return buffer; }

		char ch;
		cin >> ch;
		
//		if (isspace(ch)) { return Token(ch); }
		switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case print:
		case quit:
		case '=':
		case ',':
		case let:
		case const_let:
			//	case help:		//for help lowercase
			return Token(ch);
			//	case 'H':		//for help ,upper- case
			//		return help;
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			cin.putback(ch);
			double val;
			cin >> val;
			return Token(number, val);
		}
		default:
//			if (isalpha(ch) || ch == '_') {
				string s;
				s += ch;
				while (cin.get(ch) && ch != '(' && (isalpha(ch) || isdigit(ch))) { s += ch; }
				cin.putback(ch);
				if (s == "#") return Token(let);
				if (s == "exit") return Token(quit);
				if (s == "sqrt") {
					double d = expression();
					if (d < 0)error("square root does not exist");
					double val = sqrt(d);
					return Token(number, val);
				}
				if (s == "pow") {
					double val1;
					double val2;
					Token t = ts.get();
					if (t.kind != '(')error("'(' expected.");
					t = ts.get();
					if (t.kind != number)error("num ber expected");
					val1 = t.value;
					t = ts.get();
					if (t.kind != ',')error("',' expected");
					t = ts.get();
					if (t.kind != number)error("number expected");
					val2 = t.value;
					t = ts.get();
					if (t.kind != ')')error("')' expected.");
					double d = pow(val1, val2);
					return Token(number, d);
				}
				if (s == "const") 	return Token(const_let);
				if (s == "help") return help;
				if (s == "from") return Token(read);
				if (s == "to") return Token(write);
				return Token(name, s);
//			}
			error("Bad token");
		}
	}


	Token Token_stream::get(ifstream& ifs)
	{
		if (full) { full = false; return buffer; }

		char ch;
		ifs >> ch;

		if (isspace(ch)) { return Token(ch); }
		switch (ch) {
		case '(':
		case ')':
		case '+':
		case '-':
		case '*':
		case '/':
		case '%':
		case print:
		case quit:
		case '=':
		case ',':
		case let:
		case const_let:
			//	case help:		//for help lowercase
			return Token(ch);
			//	case 'H':		//for help ,upper- case
			//		return help;
		case '.':
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
		{
			ifs.putback(ch);
			double val;
			ifs >> val;
			return Token(number, val);
		}
		default:
			if (isalpha(ch) || ch == '_') {
				string s;
				s += ch;
				while (ifs.get(ch) && ch != '(' && (isalpha(ch) || isdigit(ch))) { s += ch; }
				ifs.putback(ch);
				if (s == "#") return Token(let);
				if (s == "exit") return Token(quit);
				if (s == "sqrt") {
					double d = expression(ifs);
					if (d < 0)error("square root does not exist");
					double val = sqrt(d);
					return Token(number, val);
				}
				if (s == "pow") {
					double val1;
					double val2;
					Token t = ts.get(ifs);
					if (t.kind != '(')error("'(' expected.");
					t = ts.get(ifs);
					if (t.kind != number)error("num ber expected");
					val1 = t.value;
					t = ts.get(ifs);
					if (t.kind != ',')error("',' expected");
					t = ts.get(ifs);
					if (t.kind != number)error("number expected");
					val2 = t.value;
					t = ts.get(ifs);
					if (t.kind != ')')error("')' expected.");
					double d = pow(val1, val2);
					return Token(number, d);
				}
				if (s == "const") 	return Token(const_let);
				if (s == "help") return help;
				if (s == "from") return Token(read);
				if (s == "to") return Token(write);
				return Token(name, s);
			}
			error("Bad token");
		}
	}

	void Token_stream::putback(Token t)
	{
		if (full)error("putback() into a full buffer");
		buffer = t;		//copy t to buffer
		full = true;	//buffer is now full
	}

	void Token_stream::ignore(char c)
	{
		if (full && c == buffer.kind) {
			full = false;
			return;
		}
		full = false;

		char ch;
//		if (STATE_write_file()) {
//			while (ifs >> ch)
//				if (ch == c)return;
//		}
		while (cin >> ch)
			if (ch == c) return;
	}

	double primary()
	{
		Token t = ts.get();
		switch (t.kind) {
		case '(':
		{
			double d = expression();
			t = ts.get();
			if (t.kind != ')') error("')' expected");
			return d;
		}
		return -primary();	case '-':

		case '+':
			return primary();
		case number:
			return t.value;
		case name:
			return St.get(t.name);
//		default:
//			error("primary expected"); //this default case is not good but I don't know how to modify.
		}
	}


	double primary(ifstream& ifs)
	{
		Token t = ts.get(ifs);
		switch (t.kind) {
		case '(':
		{
			double d = expression(ifs);
			t = ts.get(ifs);
			if (t.kind != ')') error("')' expected");
			return d;
		}
		return -primary(ifs);	case '-':

		case '+':
			return primary(ifs);
		case number:
			return t.value;
		case name:
			return St.get(t.name);
			//		default:
			//			error("primary expected"); //this default case is not good but I don't know how to modify.
		}
	}


	double term()
	{
		double left = primary();
		Token t = ts.get();
		while (true) {
			switch (t.kind) {
			case '*':
				left *= primary();
				t = ts.get();
				break;
			case '/':
			{	double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
			}
			default:
				ts.putback(t);
				return left;
			}
		}
	}


	double term(ifstream& ifs)
	{
		double left = primary(ifs);
		Token t = ts.get(ifs);
		while (true) {
			switch (t.kind) {
			case '*':
				left *= primary(ifs);
				t = ts.get(ifs);
				break;
			case '/':
			{	double d = primary(ifs);
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get(ifs);
			break;
			}
			default:
				ts.putback(t);
				return left;
			}
		}
	}


	double expression()
	{
		double left = term();
		while (true) {
			Token t = ts.get();
			switch (t.kind) {
			case '+':
				left += term();
				break;
			case '-':
				left -= term();
				break;
			default:
				ts.putback(t);
				return left;
			}
		}
	}


	double expression(ifstream& ifs)
	{
		double left = term(ifs);
		while (true) {
			Token t = ts.get(ifs);
			switch (t.kind) {
			case '+':
				left += term(ifs);
				break;
			case '-':
				left -= term(ifs);
				break;
			default:
				ts.putback(t);
				return left;
			}
		}
	}

	double declaration()
	{
		Token t = ts.get();
		if (t.kind != 'a') error("name expected in declaration");
		string name = t.name;
		if (St.is_declared(name)) {
			Token t2 = ts.get();
			if (t2.kind != '=') error("= missing in declaration of ", name);
			double d = expression();
			for (Variable& x : St.var_table) { if (x.name == name) { x.value = d; } }
			return d;
			// error(name, " declared twice");
		}
		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		St.var_table.push_back(Variable{ name, d });
		return d;
	}

	//--
	double declaration(ifstream& ifs)
	{
		Token t = ts.get(ifs);
		if (t.kind != 'a') error("name expected in declaration");
		string name = t.name;
		if (St.is_declared(name)) {
			Token t2 = ts.get(ifs);
			if (t2.kind != '=') error("= missing in declaration of ", name);
			double d = expression(ifs);
			for (Variable& x : St.var_table) { if (x.name == name) { x.value = d; } }
			return d;
			// error(name, " declared twice");
		}
		Token t2 = ts.get(ifs);
		if (t2.kind != '=') error("= missing in declaration of ", name);
		double d = expression(ifs);
		St.var_table.push_back(Variable{ name, d });
		return d;
	}

	double const_declaration()
	{
		Token t = ts.get();
		if (t.kind != 'a') error("name expected in const_declaration");
		string name = t.name;
		if (St.is_declared(name)) {
			Token t2 = ts.get();
			if (t2.kind != '=') error("= missing in declaration of ", name);
			double d = expression();
			for (Variable& x : St.var_table) { if (x.name == name) { x.const_value = d; } }
			return d;
			// error(name, " declared twice");
		}
		Token t2 = ts.get();
		if (t2.kind != '=') error("= missing in declaration of ", name);
		double d = expression();
		St.var_table.push_back(Variable{ name, d });
		return d;
	}


	double const_declaration(ifstream& ifs)
	{
		Token t = ts.get(ifs);
		if (t.kind != 'a') error("name expected in const_declaration");
		string name = t.name;
		if (St.is_declared(name)) {
			Token t2 = ts.get(ifs);
			if (t2.kind != '=') error("= missing in declaration of ", name);
			double d = expression(ifs);
			for (Variable& x : St.var_table) { if (x.name == name) { x.const_value = d; } }
			return d;
			// error(name, " declared twice");
		}
		Token t2 = ts.get(ifs);
		if (t2.kind != '=') error("= missing in declaration of ", name);
		double d = expression(ifs);
		St.var_table.push_back(Variable{ name, d });
		return d;
	}

	double statement()
	{
		Token t = ts.get();
		switch (t.kind) {
		case let:
			t = ts.get();
			St.set(t.kind, t.name);
			return declaration();
		case const_let:
			t = ts.get();
			St.set(t.kind, t.name);
			return const_declaration();
		case help:
			cout << "--HELP--\n";
			cout << "This calculator handle +, -, *, /, %, ( ),\n and if you want";
			cout << "\nfor result enter [;]\nto exit program enter [exit]";
			cout << "\ndecalrate a variable: enter [#] [name of object] [=] [number] [;]";
			cout << "\n--HELP--\n";
			cout << "if something went wrong,it is worth to try to enter [;]";
			return 0;
		default:
			ts.putback(t);
			return expression();
		}
	}
	//--
	double statement(ifstream& ifs)
	{
		Token t = ts.get(ifs);
		switch (t.kind) {
		case let:
			t = ts.get(ifs);
			St.set(t.kind, t.name);
			return declaration(ifs);
		case const_let:
			t = ts.get(ifs);
			St.set(t.kind, t.name);
			return const_declaration(ifs);
		case help:
			cout << "--HELP--\n";
			cout << "This calculator handle +, -, *, /, %, ( ),\n and if you want";
			cout << "\nfor result enter [;]\nto exit program enter [exit]";
			cout << "\ndecalrate a variable: enter [#] [name of object] [=] [number] [;]";
			cout << "\n--HELP--\n";
			cout << "if something went wrong,it is worth to try to enter [;]";
			return 0;
		default:
			ts.putback(t);
			return expression(ifs);
		}
	}
	//--
	void clean_up_mess()
	{
		ts.ignore(print);
	}

	const string prompt = "> ";
	const string result = "= ";


	void write_output() {

	}



	void calculate()
	{
		while (cin) try {
			cout << prompt;//const string prompt = "> "
			Token t = ts.get();
			if (t.kind == read) {//read == from
//				ts.change_state(true);
				string iname;
				cout << "Please enter a file name.\n";
				cin >> iname;
				ifstream ifs{ iname };
				if (!ifs)error("error opening file named ", iname);
				cin.rdbuf(ifs.rdbuf());
			}
/*
				while (t.kind == print)t = ts.get(ifs);

				if (t.kind == quit) return;//const char quit = 'Q';
				ts.putback(t);
					cout << result//const string result = "= "
						<< statement(ifs)
						<< '\n';
//			}
//			if (ts.STATE_write_file()) { 
//				while (t.kind == print)t = ts.get(ifs);
//			}
			else {
	*/			while (t.kind == print) t = ts.get(); //const char print = ';'

				if (t.kind == quit) return;//const char quit = 'Q';

				/*		cout << "Token t = " << t.kind;
						if (t.kind == help) {
							void write_help();
						}*/
				ts.putback(t);
					cout << result//const string result = "= "
						<< statement()
						<< '\n';
//			}
		}
		catch (runtime_error& e) {
			cerr << e.what() << '\n';
			clean_up_mess();
		}
	}
}