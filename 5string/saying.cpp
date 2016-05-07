#include <iostream>
#include "mystring.h"
using namespace std;
int main(void)
{
	mystring sayings[10];
	char temp[81];
	int i;
	for(i=0;i<10;i++){
		cin.get(temp,80);
		while(cin && cin.get() != '\n')
			continue;
		if(!cin || temp[0] == '\0')
			break;
		else
			sayings[i] = temp;
	}
	int total = i;
	if(total > 0 ){
		for(i=0; i < total; i++){
			cout << sayings[i] << endl;
		}
	}
	return 0;
}
