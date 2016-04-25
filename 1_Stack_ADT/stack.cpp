/*
	stack.cpp -- Stack member function
*/
#include "stack.h"
Stack::Stack()
{
	top = 0;
}
bool Stack::isfull()const
{
	return top == (MAX-1);
}
bool Stack::isempty()const
{
	return 0 == top;
}
bool Stack::push(const Item & item)
{
	if(!isfull()){
		items[top++] = item;
		return true;
	}
	else 
		return false;
}
bool Stack::pop(Item & item)
{
	if(!isempty()){
		item = items[--top];
		return true;
	}
	else
		return false;
}


