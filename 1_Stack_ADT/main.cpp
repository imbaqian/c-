#include <iostream>
#include "stack.h"
using namespace std;
int main(void)
{
	Stack st;
	char ch;
	unsigned long po;
	cout << "please enter A to add purchase order\n"
		 << "P to process a PO ,or Q to quit\n";
	while(cin >> ch && toupper(ch) != 'Q'){
		while(cin.get() != '\n')
			continue;
		if(!isalpha(ch)){
			cout << '\a';
			continue;
		}
		switch(ch){
			case 'A':
			case 'a': cout<<"enter a PO number to add:";
					  cin>>po;
					  if(st.isfull())
						  cout<<"stack is full\n";
					  else
						  st.push(po);
					  break;
			case 'p':
			case 'P': if(st.isempty())
						  cout<<"stack is empty\n";
					  else{
						st.pop(po);
						cout<<"PO #"<<po<<"poped\n";
					  }
					  break;
		}
		cout<<"please enter A to add a purchase order,\n"
			<<"P to process a PO,or Q to quit.\n";
	}
	cout<<"bey\n";
	return 0;
}
