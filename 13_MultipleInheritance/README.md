#g++ warning: base class 'Waiter' will be initialized after base 'Singer'

顾名思义，基类Waiter 应该在基类Singer后被初始化　　
<pre>
class SingingWaiter : public Singer, public Waiter{
        ...
public:
	SingingWaiter(const std::string &s, long n, int p = 0, int v = other)
		:Worker(s,n), Waiter(s,n,p), Singer(s,n,v) {}
        ...
};
</pre>

出错代码如上所示，仔细观察，可以看到　　
<pre>
    class SingingWaiter : public Singer, public Waiter
    继承顺序是　Singer Waiter
    
    而构造函数构造顺序是 Worker Waiter Singer
    
    Worker是虚基类，先不说，这里的Waiter 和　Singer的顺序
    与类声明继承顺序时候是不一样的，所以问题就出在这
    
    将class SingingWaiter : public Singer, public Waiter
    改为class SingingWaiter : public Waiter, public Singer
    
    warning 消失，问题解决～
    
</pre>


##还有一点就是

<pre>
下面代码
class A(){
    int a;
    int b;
    A():b(1),a(2){}
};
也会出现同样的警告

同样的解决方法，改变顺序
class A(){
    int a;
    int b;
    A():a(2),b(1){}
};
问题解决
</pre>