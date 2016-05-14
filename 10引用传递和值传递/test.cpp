/*
	问:为什么引用传递比值传递效率更高。
    1.按引用传递对像，这样可以确保函数从虚函数受益。
	2.按引用传递对象可以节省内存和时间，尤其是大型对象。
	3.按值传递对象的主要优点在于可以保护原始数据，
	  但可以童工引用作为const类型传递，来达到同样的目的。
	
 */

//下面是对 1 的验证

#include <iostream>
using namespace std;

class A{
public:
	virtual void print(){
		cout << "A\n";
	}
};
class B : public A{
public:
	virtual void print(){
		cout << "B\n";
	} 
};
void fun1(A a){ //值传递
	a.print();
}
void fun2(A &a){ // 引用传递
	a.print();
}
int main(void)
{
	A a;
	B b;
	fun1(a);
	fun2(a);
	fun1(b);
	fun2(b);
	return 0;
}
/*	输出:A
		 A
		 A
		 B
 */
