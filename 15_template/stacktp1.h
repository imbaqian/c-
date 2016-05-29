//stacktp.h -- a stack template
#ifndef STACKTP1_H_
#define STACKTP1_H_

template <class Type>
class Stack{
private:
	enum {SIZE = 10};
	Type *items;
	int stacksize;
	int top;
public:
	explicit Stack(int ss = SIZE);
	Stack(const Stack<Type> &st);
	~Stack(){delete[] items;}
	bool isempty(){return 0 == top;}
	bool isfull(){return stacksize == top;}
	bool push(const Type &item);
	bool pop(Type &item);
	Stack & operator=(const Stack &st);
};

template <class Type>
Stack<Type>::Stack(int ss/*默认参数只能在声明中或定义中出现一次*/):stacksize(ss), top(0){
	items = new Type[stacksize];	
}

template <class Type>
bool Stack<Type>::push(const Type &item){
	if(top < stacksize){
		items[top++] = item;
		return true;
	}
	else
		return false;
}

template <class Type>
Stack<Type>::Stack(const Stack<Type> &st){ /*？？？*/
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for(int i = 0; i < top; i++){
		items[i] = st.items[i];
	}
}

template <class Type>
bool Stack<Type>::pop(Type &item){
	if(0 == top)
		return false;
	else{
		item = items[--top];
		return true;
	}
}

template <class Type>
Stack<Type> & Stack<Type>::operator=(const Stack<Type> &st){
	delete[] items;
	stacksize = st.stacksize;
	top = st.top;
	items = new Type[stacksize];
	for(int i = 0; i < top; i++){
		items[i] = st.items[i];
	}
	return *this;
}
#endif
