
//AcctABC.h brass account classes
#ifndef ACCTABC_H_
#define ACCTABC_H_
#include <iostream>
#include <string>
using std::string;
//Brass account class
class AcctABC{
private:
	//用户名
	string fullName;
	//账户
	long acctNum;
	//余额
	double balance;
protected:
	struct Formatting{
		std::ios_base::fmtflags flag;
		std::streamsize pr;
	};
	const string & FullName()const{return fullName;}
	long AcctNum()const{return acctNum;}
	Formatting SetFormat()const;
	void Restore(Formatting &f)const;
public:
	AcctABC(const string &s = "NullBody",long ac = -1,double bal = 0.0);
	//存款
	void Deposit(double amt);
	//取款
	virtual void Withdraw(double amt) = 0;
	//查看余额
	double Balance()const;
	//查看账户
	virtual void ViewAcct()const = 0;
	virtual ~AcctABC(){}
};

//Brass Account Class
class Brass : public AcctABC{
public:
	Brass(const string &s = "NullBody", long ac = -1, double bal = 0.0) : AcctABC(s,ac,bal){}
	virtual void Withdraw(double amt);
	virtual void ViewAcct() const;
	virtual ~Brass(){}
};

//Brass Plus Account Class
class BrassPlus : public AcctABC{
private:
	double maxLoan;
	double rate;
	double owesBank;
public:
	BrassPlus(const string &s = "NullBody",long ac = -1,
			  double bal = 0.0, double ml = 500, 
			  double r = 0.11125);
	BrassPlus(const Brass &ba,double ml = 500,
			  double r = 0.11125);
	virtual void ViewAcct()const;
	virtual void Withdraw(double amt);
	void ResetMax(double m){maxLoan = m;}
	void ResetRate(double r){rate = r;}
	void ResetOwes(double o) {owesBank = o;}
};

#endif


