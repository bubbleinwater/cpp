#include"Punct_stream.h"

Punct_stream& Punct_stream::operator>>(string& s) 
{
	while (!(buffer >> s)) {//try to read from bufer

		if (buffer.bad() || !source.good())return *this;

		buffer.clear();//replenish the buffer

		string line;
		getline(source, line);//get a line from source
		//do character replacement as needed:
		for (char& ch : line)
			if (is_whitespace(ch))ch = ' ';//to space
			else if (!sensitive) ch = tolower(ch);//to lower case
		buffer.str(line);//put string into stream
	}
	return *this;
}

bool Punct_stream::is_whitespace(char c) {
	for (char w : white)
		if (c == w)return true;
	return false;
}

Punct_stream::operator bool()
{
	return !(source.fail() || source.bad()) && buffer.good();
}