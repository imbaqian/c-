#include <iostream>
#include "mystring.h"

int main(void)
{
	mystring *pst = new mystring;
	{
		mystring automatic;
	}
	delete pst;
	return 0;
}
