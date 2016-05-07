#include <iostream>
using std::cout;
#include "mystring.h"

void callme1(mystring &s)
{
	cout << "passby reference: ";
	cout << s << "\n";
}
void callme2(mystring s)
{
	cout << "passby value: ";
	cout << s << "\n";
}

int main()
{
	using std::endl;
	{
		mystring headline1("Celery Stalks at Minnight");
		mystring headline2("Letture Prey");
		mystring headline3("spinach leaves bowl for dollars");

		cout << "headline1 :" << headline1 << endl;
		cout << "headline2 :" << headline2 << endl;
		cout << "headline3 :" << headline3 << endl;

		callme1(headline1);
		cout << "headline1 :" << headline1 << endl;
		callme2(headline2);
		cout << "headline2 :" << headline2 << endl;

		mystring sailor = headline3;
		cout << "sailor :" << sailor << endl;
		mystring knot;
		knot = headline1;
		cout << "knot :" << knot << endl;
	}

}
