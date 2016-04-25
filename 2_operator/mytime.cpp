/*
 mytime -- cpp file
 */

#include "mytime.h"
#include <iostream>

Time::Time()
{
	m_hours = 0;
	m_minutes = 0;
}
Time::Time(int h,int m)
{
	m_hours = h;
	m_minutes = m;
}
void Time::Reset(int h, int m)
{
	m_hours = h;
	m_minutes = m;
}
void Time::AddHour(int h)
{
m_hours += h;
}
void Time::AddMin(int m)
{
	m_minutes += m;
	m_hours = m_minutes/60;
	m_minutes %= 60;
}
void Time::Show()const
{
	std::cout << m_hours << ":" << m_minutes << std::endl;
}
Time Time::operator+(const Time & t)const
{
	Time sum;
	sum.m_minutes = m_minutes + t.m_minutes;
	sum.m_hours = t.m_hours + sum.m_minutes/60;
	sum.m_minutes = sum.m_minutes % 60;
	return sum;
}

Time Time::operator-(const Time &t)const
{
	Time sub;
	sub.m_minutes = 60 *(m_hours - t.m_hours) + (m_minutes - t.m_minutes);
	sub.m_hours = sub.m_minutes / 60;
	sub.m_minutes %= 60;
	return sub;
}
Time Time::operator*(const double n)const
{
	Time product;
	product.m_minutes = (m_hours * 60 + m_minutes) * n;
	product.m_hours = product.m_minutes / 60;
	product.m_minutes %= 60;
	return product;
}
/*友元函数，函数定义不用加friend*/
Time operator*(const double n, const Time &t)
{
	
	Time product;
	product.m_minutes = (t.m_hours * 60 + t.m_minutes) * n;
	product.m_hours = product.m_minutes / 60;
	product.m_minutes %= 60;
	return product;
}

ostream & operator<<(ostream &os, const Time &s)
{
	os << s.m_hours << ":" << s.m_minutes << std::endl;
	return os;
}
