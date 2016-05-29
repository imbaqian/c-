/*
	用c语言模拟getline() 函数
*/
#include <iostream>
using namespace std;
#include <stdio.h>
int getline_(char s[],int lim){
	int c;
	int i;
	i = 0;
	while((c = getchar()) != EOF && c != '\n' && i < lim-1)
		s[i++] = c;
	if(c == EOF && i == 0)
		return -1;
	s[i] = '\0';
	return i;
}

int main1(void)
{
	char str[128];
	int len;
	while( (len = getline_(str,128)) != -1)
		printf("%s\n",str);
	return 0;
}


class A{
private:
	int a[10];
public:
	A(){
		for(int i = 0; i < 10; i++){
			a[i] = i;
		}
	}
	int & operator[](int i){
		cout << "int & []" << endl;
		return a[i];
	}
	int operator[](int i)const{
		cout << "int [] const" << endl;
		return a[i];
	}
};
void demo(const A & a){
	cout << a[0]<<endl;
}
int main(void){
	A a;
	cout << a[1] << endl;
	a[1] = 110;
	cout << a[1] << endl;
	int xxx = a[5];
	cout << xxx << endl;
	a[0] = a[1];
	demo(a);
	return 0;

}
