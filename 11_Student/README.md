#<center>double & operator[] (int i);与double operator[] (int i)const;</center>

正如c++ primer plus 14.2私有继承中的student类所示，
该类成员函数出现了。

于是写了个简单的类来测试一下：
<pre>
class A{
private:
      int a[10];
public:
      A(){
          for(int i = 0; i < 10; i++)
              a[i] = i;
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
 
int main(void){
      A a;
      cout << a[1] << endl;
      a[1] = 110;
      cout << a[1] << endl;
      int xxx = a[5];
      cout << xxx << endl;
      a[0] = a[1];
      return 0;
   
  }


输出结果为： int & []
           1
           int & []
           int & []
           110
           int & []
           5
           int & []
           int & []
           
怎么没有一个调用int [] const 呢？
应该是  int & operator[](int i) 左值右值
       int operator[](int i)const 右值
但是只调用了前者，后者没有被调用。

于是又加了点东西：
void demo(const A &a){
       cout << a[1];
}
 
int main(){
......
A a;
demo(a);
return 0;
}

这时候在demo中就调用了后者int operator[](int i)const

</pre>           