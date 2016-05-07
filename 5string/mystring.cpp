#include "mystring.h"
#include <cstring>

int mystring::num_string = 0;


/*static method*/
int mystring::HowMany()
{
	return num_string;
}


mystring::mystring(const char * s) /*construct string from c string*/ 
{
	len = std::strlen(s);
	str = new char[len + 1];
	std::strcpy(str, s);
	num_string++;
	std::cout << num_string << ": \"" << str << "\" object created\n";
}

mystring::mystring() /*default constructor*/
{
	len = 0;
	str = new char[1];
	str[0] = '\0';
	num_string++;
	std::cout << num_string << ": \"" << str << "\"default object created\n";
}
mystring::mystring(const mystring &s)
{
	num_string++;
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str,s.str);	
	std::cout << num_string << ": \"" << str << "\"object created\n";
}

mystring::~mystring()
{
	std::cout << "\"" << str << "\" object deleted\n";
	num_string--;
	delete[] str;
}

mystring & mystring::operator=(const mystring &s)
{
	if(this == &s) /*自我复制直接返回*/
		return *this; 
	delete[] str;
	len = s.len;
	str = new char[len + 1];
	std::strcpy(str,s.str);
	return *this;	
}
mystring & mystring::operator=(const char *s)
{
	delete[] str;
	len = strlen(s);
	str = new char[len + 1];
	std::strcpy(str,s);
	return *this;
}
char & mystring::operator[](int i) /*read-write non-const string*/ 
{
	return str[i];
}
const char & mystring::operator[](int i)const /*const mystring*/ 
{
	return str[i];
}

/* friend operator function*/
std::ostream & operator<<(std::ostream &os, const mystring &s)
{
	os << s.str;
	return os;
}

std::istream & operator>>(std::istream &is, mystring &s)
{
	char temp[mystring::CINLIM];
	is.get(temp,mystring::CINLIM);
	if(is)
		s = temp;
	while(is && is.get() != '\n')
		continue;
	return is;
}

bool operator<(const mystring &s1, const mystring &s2)
{
	return (std::strcmp(s1.str, s2.str) < 0);
}

bool operator>(const mystring &s1, const mystring &s2)
{
	return (std::strcmp(s1.str, s2.str) > 0);
}

bool operator==(const mystring &s1, const mystring &s2)
{
	return (std::strcmp(s1.str,s2.str) == 0);	
}

