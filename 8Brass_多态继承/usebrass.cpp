#include <iostream>
using namespace std;
class A
{
public:
	virtual void print(int aa)
	{
		cout << aa << endl;
	}
};

class B : public A
{
public:
	virtual void print(int aa)
	{
		cout << "B print\n";
	}
};

int main(void)
{
	A a;
	B b;
	a.print(3);
	b.print(4);
	A *pa = &b;
	pa->print(4);
	
	return 0;
}
