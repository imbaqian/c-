//tempparm.cpp --template as parameters
//将模板用于参数
#include <iostream>
#include "stacktp.h"

template <template <typename T> class Thing>
class Crab{
private:
	Thing<int> s1;
	Thing<double> s2;
public:
	Crab(){};
	bool push(int a, double x){return s1.push(a) && s2.push(x);}
	bool pop(int &a, double &x){return s1.pop(a) && s2.pop(x);}
	
};

int main(){
	using namespace std;
	Crab<Stack> nebula;
	int ni;
	double nb;
	cout << "enter int double pairs, such an 4 3.5 (0 0 to end):\n";
	while(cin >> ni >> nb  && ni > 0 && nb > 0){
		if(!nebula.push(ni,nb))
			break;
	}
	while(nebula.pop(ni,nb))
		cout << ni << ", " << nb << endl;
	cout << "done!\n";
	return 0;
}
