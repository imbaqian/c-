//worker0.h
#ifndef WORKER0_H_
#define WORKER0_H_

#include <string>

class Worker{
private:
	std::string fullName;
	long id;
public:
	Worker() : fullName("no one"), id(0L){}
	Worker(const std::string &s,long n) : fullName(s), id(n) {}
	virtual ~Worker(){}
	virtual void Set();
	virtual void Show()const;	
};

class Waiter : public Worker{
private:
	int panache;
public:
	Waiter() : Worker(),panache(0){}
	Waiter(const std::string &s, long n, int p = 0)
		:Worker(s,n),panache(p){}
	Waiter(const Worker &wk,int p = 0)
		:Worker(wk),panache(p){}
	virtual void Set();
	virtual void Show()const;

};

class Singer : public Worker{
protected:
	enum {other, alto, contralto, soprano, bass, baritine, tenor};
	enum {Vtypes = 7};
private:
	static char *pv[Vtypes];
	int voice;
public:
	Singer() : Worker(), voice(other){}
	Singer(const std::string &s, long n, int v = other)
		:Worker(s,n),voice(v){}
	virtual void Set();
	virtual void Show()const;

};



#endif
