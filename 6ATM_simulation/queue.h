/*
	queue.h
 */

#ifndef QUEUE_H_
#define QUEUE_H_

class Customer{
private:
	long arrive;
	int processtime;
public:
	Customer(){arrive = processtime = 0;}
	void set(long when);
	long when()const{return arrive;}
	int ptime()const{return processtime;}
};
typedef Customer Item;

class Queue{
private:
	struct Node{
		Item item;
		struct Node *next;	
	};
	enum {Q_SIZE = 10};

	Node *front;
	Node *rear;
	int items; // current number of item
	const int qsize;
	//防止公共拷贝
	Queue(const Queue &q) : qsize(0) {}
	Queue & operator=(const Queue &q){return *this;}
public:
	Queue(int qs = Q_SIZE);
	~Queue();
	bool isempty()const;
	bool isfull()const;
	int queuecount()const;
	bool AddQueue(const Item &it);//add to end
	bool DelQueue(Item &it);// remove from front
};

#endif
