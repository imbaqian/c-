/*
    stock类
*/
#ifndef STOCK_H_
#define STOCK_H_

#include <string>

class Stock{
 private: 
    std::string m_company;//公司名称
    long m_shares; //所持股票数量
    double m_share_val;//每股的价格
    double m_total_val;//股票总价
    void set_tot(){
      m_total_val = m_shares * m_share_val;
    }
public:
    Stock(); //default constructor
    Stock(const std::string &co, long n = 0, double pr = 0.0);
    ~Stock();//noisy destructor
    void buy(long num, double price);
    void sell(long num, double price);
    void update(double price);
    void show()const;
	const Stock& topval(const Stock& s)const;
	double total() const{ return m_total_val;}
};

#endif
