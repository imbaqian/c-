//student.cpp

#include "student.h"
using std::ostream;
using std::endl;
using std::istream;
using std::string;

//public methods

double Student::Average()const{
	if(ArrayDb::size() > 0)
		return ArrayDb::sum() / ArrayDb::size();
	else 
		return 0;
}

const string & Student::Name()const{
	return (const string &)*this; //注意哦
}

double & Student::operator[](int i){
	cout << "double &" << endl;
	return ArrayDb::operator[](i); //注意！！！
}

double Student::operator[](int i)const{
	cout << "double  const" << endl;
	return ArrayDb::operator[](i);
}

//private methods

ostream & Student::arr_out(ostream & os)const{
	int i;
	int lim = ArrayDb::size();
	if(lim > 0){
		for(i = 0; i < lim; i++){
			os << ArrayDb::operator[](i) << " ";
			if(i % 5 == 4)
				os << endl;
		}
		if(i % 5 != 0)
			os << endl;
	}
	else
		os << "empty array" << endl;
	return os;
}

//friends
//use string version of operator>>()

istream & operator>>(istream &is, Student &stu){
	is >> (string &)stu;
	return is;
}

istream & getline(istream &is, Student &stu){
	getline(is,(string &)stu);
	return is;
}

//use string version of operator<<()
ostream & operator<<(ostream &os, Student &stu){
	os << "Scores for " << (const string &)stu << ":\n";
	stu.arr_out(os);
	return os;
}

