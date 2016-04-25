#include "stock.h"
#include <iostream>
void Stock::show()const
{
    using std::cout;
	using std::endl;
    using std::ios_base;
    /*设置输出格式#.###*/
    ios_base::fmtflags orig = cout.setf(ios_base::fixed, ios_base::floatfield);//orig存储了所有标记
    std::streamsize prec = cout.precision(3);//记录原始精度
    
    cout << "Company:" << m_company
         << " Shares:" << m_shares << endl;
    cout << "Share Price :$" << m_share_val;
    
    /*设置输出格式#.##*/
    cout.precision(2);
    cout << "Total Worth: $" << m_total_val << endl;
    
    /*还原输出格式*/
    cout.setf(orig,ios_base::floatfield);
    cout.precision(prec);
    
    
}

Stock::Stock()
{
    std::cout << "Default constructor called\n";
    m_company = "No Name";
    m_shares = 0;
    m_share_val = 0.0;
    m_total_val = 0.0;
}

Stock::Stock(const std::string &co, long n, double pr)
{
    std::cout << "Constructor using " << co << "called\n";
    m_company = co;
    if(n < 0){
        std::cout << "Number of shares can't be negative"
                  << m_company << "shares set to 0.\n";
        m_shares = 0;
    }
    else{
        m_shares = n;
    }
    
    m_share_val = pr;
    set_tot();
}

Stock::~Stock()
{
    std::cout << "Bey, " << m_company << "!\n";
}

void Stock::buy(long num, double price)
{
    if(num < 0){
        std::cout << "Number of shares purchased can't be negative. "
                  << "Transaction is abort.\n";
    }
    else{
        m_shares += num;
        m_share_val = price;
        set_tot();
    }
}


void Stock::sell(long num, double price)
{
    using std::cout;
    if(num < 0){
        cout << "Number of shares can't be negative."
             << "Transaction is abort.\n";
    }
    else if(num > m_shares){
        cout << "You can't sell more than you have! "
             << "Transaction is abort.\n";
    }
    else{
        m_shares -= num;
        m_share_val = price;
        set_tot();
    }
}

void Stock::update(double price)
{
    m_share_val = price;
    set_tot();
    
}

const Stock& Stock::topval(const Stock& s)const
{
	/*注意这里，参数s 可以直接访问s的私有成员变量*/
	if(s.m_total_val > m_total_val)
		return s;
	else
		return *this;
}
