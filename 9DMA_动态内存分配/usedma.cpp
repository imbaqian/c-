#include <iostream>
#include "dma.h"
int main(void)
{
	using std::cout;
	using std::endl;
	baseDMA shirt("Portabelly",8);
	lackDMA balloon("Red","Blimpo",5);
	hasDMA  map("Mercator","Buffalo keys",5);
	cout << "shirt--------" << endl;
	cout << shirt << endl;
	cout << "ballon-------" << endl;
	cout << balloon << endl;
	cout << "map----------" << endl;
	cout << map << endl;

	lackDMA balloon2(balloon);
	  
	cout << "copy balloon-----" << endl;
	cout << balloon2 << endl;

	hasDMA map2;
	map2 = map;
	cout << "= map-----------" << endl;
	cout << map << endl;
	return 0;
}

