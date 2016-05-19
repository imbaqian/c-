# <center>C++枚举</center>

c++的enum工具提供了另一种创建符号常量的方式，这种方式可以代替const。

###　基本使用方法:
    enum spectrum {red, orange, yellow, green, blue, violet, indigo, ultraviolet};
    
该语句完成两项工作：　　

1. 让spectrum成为新类型的名称；spectrum被称为枚举(enumeration),就像struct变量被成为结构体一样。　　
2. 将red, orange, yellow　等作为符号常量，其对应值为 0~7  

###设置枚举量的值:  
1. 可以使用复制运算符来显示地设置枚举量的值：  
    enum bits{one = 1, two = 2, four = 4, eight = 8};
2. 指定的值必须是整数，也可以值显示地定义其中一些枚举的量:  
    enum bigstep{first, second = 100, third};  
    first = 0, second = 100, third = 101 没有指定的比前面的大１
3. 可以创建多个值相同的枚举量：  
enum{zero, null = 0, one ,numero_uno = 1};  
    zero = 0, null = 0, one = 1, numero_uno = 1
    
###枚举的取值范围　　
每个枚举都有取值范围(range)，通过强制类型转换，可将取值范围中的任意一个值赋给枚举变量，即使这个值不是枚举变量.  
<pre>
    enum bits{one = 1, two = 2, four = 4, eight = 8};  
    bits flag;  
    flag = bits(6);　//valid,because is in bits range  
</pre>
    
取值范围的计算：找到枚举最大值的最小２的幂,将他减去１得到的便是取值上限,下限是０，对于负数和正数的取值范围一样的算法.  


##枚举作用域为类的常量:

问题:
<pre>
class Bakery{
private:
    const int months = 12;
    double costs[months];
};
</pre>

这样做是行不通的，因为声明只是描述了对象的形式，并没有创建对象。因此在创建前，将没有用于存储值的空间.  

###第一种解决方法：声明一个枚举

<pre>
class Bakery{
private:
    enum {months = 12};
    double costs[months];
};
</pre>

###第二种方法：使用关键字static

<pre>
class Bakery{
private:
    static const int months = 12;
    double costs[months];
};
</pre>