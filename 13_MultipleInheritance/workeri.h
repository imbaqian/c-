//worker0.h
#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker{
private:
	std::string fullName;
	long id;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Worker() : fullName("no one"), id(0L){}
	Worker(const std::string &s,long n) : fullName(s), id(n) {}
	virtual ~Worker() = 0;//pure virtual destructor纯虚函数
	virtual void Set() = 0;
	virtual void Show()const = 0;	
};

class Waiter : virtual public Worker{
private:
	int panache;
protected:
	virtual void Data()const;
	virtual void Get();
public:
	Waiter() : Worker(),panache(0){}
	Waiter(const std::string &s, long n, int p = 0)
		:Worker(s,n),panache(p){}
	Waiter(const Worker &wk,int p = 0)
		:Worker(wk),panache(p){}
	virtual void Set();
	virtual void Show()const;
};

class Singer : virtual public Worker{
protected:
	enum {other, alto, contralto, soprano, bass, baritine, tenor};
	enum {Vtypes = 7};
	virtual	void Data()const;
	virtual void Get();
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other){}
	Singer(const std::string &s, long n, int v = other)
		:Worker(s,n),voice(v){}
	Singer(const Worker &wk, int v = other)
		:Worker(wk),voice(v){}
	virtual void Set();
	virtual void Show()const;

};

//multiple inheritance
class SingingWaiter : public Waiter, public Singer{
protected:
	virtual void Data()const;
	virtual void Get();
public:
	SingingWaiter(){}
	SingingWaiter(const std::string &s, long n, int p = 0, int v = other)
		:Worker(s,n), Waiter(s,n,p), Singer(s,n,v) {}
	
	SingingWaiter(const Worker &wk, int p = 0, int v = other)
		: Worker(wk), Waiter(wk,p), Singer(wk,v){}
	
	SingingWaiter(const Waiter &wk, int v = other)
		: Worker(wk), Waiter(wk), Singer(wk,v){}
	
	SingingWaiter(const Singer &wk, int p = 0)
		: Worker(wk), Waiter(wk,p), Singer(wk) {}
	virtual void Set();
	virtual void Show()const;
};

#endif
