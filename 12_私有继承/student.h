//student.h

#ifndef STUDENT_H_
#define STUDENT_H_

#include <iostream>
#include <valarray>
#include <string>

class Student : private std::string, std::valarray<double>{
private:
	typedef std::valarray<double> ArrayDb;
	// private method for scores output
	std::ostream & arr_out(std::ostream &os)const;
public:
	Student() : std::string("Null Student"), ArrayDb() {}
	explicit Student(const std::string &s) : std::string(s), ArrayDb() {}
	explicit Student(int n) : std::string("Nully"), ArrayDb(n) {}
	Student(const std::string &s, int n) : std::string(s), ArrayDb(n) {}
	Student(const char *str, const double *pd, int n)
		: std::string(str),ArrayDb(pd, n) {}
	~Student(){}
	double Average()const;
	/*--------这是个问题---------------*/
	/*返回的值能做左值 ↓ */
	double & operator[](int i);
	/*返回的值只能做右值 ↓ */
	double operator[](int i)const;
	/*---------------------------------*/
	const std::string & Name()const;
//friend
	//input
	friend std::istream & operator>>(std::istream & is, Student &stu);
	friend std::istream & getline(std::istream & is, Student &stu);
	//output
	friend std::ostream & operator<<(std::ostream & os, Student &stu);
};

#endif
