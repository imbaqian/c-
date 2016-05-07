


#include <iostream>
#ifndef MYSTRING_H_
#define MYSTRING_H_
class mystring{
private:
	char *str;
	int len;
	static int num_string;	/*num of object*/
	const static int CINLIM = 80;	/*cin input limit*/
public:
	mystring(const char *s);
	mystring();
	mystring(const mystring &s);
	~mystring();
	int length()const {return len;}
	/*overloaded operator methods*/
	mystring & operator=(const mystring &s);
	mystring & operator=(const char *s);
	char & operator[](int i);
	const char & operator[](int i)const;
	/*overload friend operator*/
	friend std::ostream & operator<<(std::ostream &os, const mystring & s);
	friend std::istream & operator>>(std::istream &is, mystring & s);
	friend bool operator>(const mystring & s1, const mystring & s2);
	friend bool operator<(const mystring & s1, const mystring & s2);
	friend bool operator==(const mystring & s1, const mystring & s2);
	// static funtion
	static int HowMany();
};
#endif
