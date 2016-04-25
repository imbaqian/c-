/*
	time类--头文件
 */
#ifndef MYTIME_H_
#define MYTIME_H_
#include <ostream>
using std::ostream;
class Time{
private:
	int m_hours;
	int m_minutes;
public:
	Time();
	Time(int h, int m);
	void AddMin(int m);
	void AddHour(int h);
	void Reset(int h = 0, int m = 0);
	Time Sum(Time &t)const;
	void Show()const;
	Time operator+(const Time &t)const;/*非成员函数不能加末尾的const*/
	Time operator-(const Time &t)const;
	Time operator*(const double n)const;
	friend Time operator*(const double n, const Time &t);/*友元函数,声明加friend*/
	friend ostream & operator<<(ostream &os, const Time &t);
};



#endif
