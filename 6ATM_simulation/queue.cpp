#include "queue.h"
#include <cstdio>
#include <iostream>
Queue::Queue(int qs) : qsize(qs)
{
	front = rear = NULL;
	items = 0;	
}
Queue::~Queue()
{
	Node * temp;
	while(front != NULL){
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue::isempty()const
{
	return 0 == items;
}
bool Queue::isfull()const
{
	return qsize == items;
}

int Queue::queuecount()const
{
	return items;
}

bool Queue::AddQueue(const Item &it)
{
	if(isfull())
		return false;
	else{
		items++;
		Node *temp = new Node;
		temp->item = it;
		temp->next = NULL;
		if(front == NULL)
			front = temp;
		else
			rear->next = temp;
		rear = temp;
		return true;
	}
}
bool Queue::DelQueue(Item &it)
{
	if(!isempty())
		return false;
	else{
		items--;
		it = front->item;
		Node * temp = front;
		front = front->next;
		if(front == NULL)
			rear = NULL;
		delete temp;
		return true;
	}
}

void Customer::set(long when)
{
	//服务所需时间为1,2,3 分钟
	processtime = std::rand() % 3 + 1;
	arrive = when;
}
