#include <iostream>
using std::cout;
using std::endl;
class Golfer{
private:
	char *fullname;
	int games;
	int *scores;
public:
	Golfer(){
		cout << "Golfer()" << endl;
	}
	Golfer(const Golfer &g){
		cout << "Golfer(const Golfer &g)" << endl;
	}
	Golfer(const char *name,int g=0){
		cout << "Golfer(const char *name,int g=0)" << endl;
	}
	Golfer & operator=(const Golfer& g){
		cout << "Golfer & operator=(const Golfer& g)" << endl;
	}	
};

int main(void)
{
	cout << 1;
	Golfer nancy;
	cout << 2;
	Golfer lulu("lulu");
	cout << 3;
	Golfer roy("roy",3);
	cout << 4;
	Golfer *par = new Golfer;
	cout << 5;
	Golfer next = lulu;
	cout << 6;
	Golfer hazzard = "Weed";
	cout << 7;
	*par = nancy;
	cout << 8;
	nancy = "Nancy";
	return 0;
}
