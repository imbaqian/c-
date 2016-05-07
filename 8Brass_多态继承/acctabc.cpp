//brass.cpp --bank account class methods
#include <iostream>
#include "acctabc.h"

using std::cout;
using std::endl;
using std::string;
using std::ios_base;


//Brass methods
AcctABC::AcctABC(const string &s, long ac, double bal)
{
	fullName = s;
	acctNum = ac;
	balance = bal;
}

void AcctABC::Deposit(double amt)
{
	if(amt < 0){
		cout << "Negative deposit not allowed;"
			 << "deposit is canceled." << endl;
	}
	else{
		balance += amt;
	}
}

void AcctABC::Withdraw(double amt)
{
	balance -= amt;
}

//protected 成员函数——设置格式
AcctABC::Formatting AcctABC::SetFormat()const
{
	//set  up  ###.## format
	Formatting f;
	f.flag = cout.setf(ios_base::fixed, ios_base::floatfield);
	f.pr = cout.precision(2);
	return f;
}
void AcctABC::Restore(Formatting &f)const
{
	cout.setf(f.flag, ios_base::floatfield);
	cout.precision(f.pr);
}

//Brass methods
void Brass::Withdraw(double amt)
{
	if(amt < 0)
		cout << "Withdraw amount must be positive;"
			 << "Withdraw is canceled." << endl;
	else if(amt > Balance())
		cout << "Withdraw amount of $ " << amt
			 << "exceeds your balance.\n"
			 << "Withdraw canceled.\n";
	else
		AcctABC::Withdraw(amt);
}

void Brass::ViewAcct()const
{
	Formatting f = SetFormat();
	cout << "Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
	cout << "Balance $: " << Balance() << endl;
	Restore(f);
}

//BrassPlus methods
BrassPlus::BrassPlus(const string & s,long an,double bal, 
					 double ml, double r) : AcctABC(s,an,bal)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

BrassPlus::BrassPlus(const Brass &ba, double ml, double r) : AcctABC(ba)
{
	maxLoan = ml;
	owesBank = 0.0;
	rate = r;
}

//redefine how ViewAcct() works
void BrassPlus::ViewAcct()const
{
	Formatting f = SetFormat();
	cout << "Client: " << FullName() << endl;
	cout << "Account Number: " << AcctNum() << endl;
	cout << "Balance $: " << Balance() << endl;
	cout << "Maximum loan: $" << maxLoan <<endl;
	cout << "owed to bank: $" << owesBank << endl;
	cout.precision(3);
	cout << "Loan Rate:" <<  100*rate << "%" << endl;
	Restore(f);
}
//redefine how Withdraw() works
void BrassPlus::Withdraw(double amt)
{	
	Formatting f = SetFormat();
	double bal = Balance();
	if(amt <= bal)// 0 <= amt <=bal
		AcctABC::Withdraw(amt);
	else if(amt <= bal + maxLoan - owesBank){ // bal < amt <= bal + maxLoan
		double advance = amt - bal; //算出超出余额的部分
		owesBank += advance * (1.0 + rate); //算出超出部分欠银行数目
		cout << "Bank advance: $"<< advance <<endl;
		cout << "Finance charge: $" << advance * rate << endl;
		Deposit(advance); //银行给用户贷款
		AcctABC::Withdraw(amt);//用户取出存款
	}
	else{
		cout << "Credit limit exceeded. Transaction cancelled.\n";
	Restore(f);
	}
}

format setFormat()
{
	//set up ###.## format
	return cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
}

void restoreFormat(format f, precis p)
{
	cout.setf(f, std::ios_base::floatfield);
	cout.precision(p);
}
