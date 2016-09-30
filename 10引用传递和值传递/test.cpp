/*
    问:为什么引用传递比值传递效率更高。
    1.按引用传递对像，这样可以确保函数从虚函数受益。
    2.按引用传递对象可以节省内存和时间，尤其是大型对象。
    3.按值传递对象的主要优点在于可以保护原始数据，但引用作为const类型传递，来达到同样的目的。
	
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
/*	output:A
	       A
               A		 
               B

第一句话的意思更通俗点讲就是，按值传递对象，会产生临时对象，传递的并不是当前对象本身，内部操作实际上是临时对象，这样虚函数识别会无法生效甚至产生逻辑歧义，
因为你传递的对象是实际参数类型的，可以是 派生类 这样传递实际参数就可以灵活的使用本类或基类函数，而临时对象，一定是参数声明的类型，即使你传递的是一个兼容类
对象，这样不存在利用虚函数的技巧了。
*/
