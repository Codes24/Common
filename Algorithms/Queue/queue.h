#ifndef QUEUE_H
#define QUEUE_H
#include "iostream"

using namespace std;

typedef struct data
{
	int Number;
	struct data* Next;
}data;

typedef struct queue
{
	int FixSize;	// the queue's maximum size
	int CurrentSize;	// the queue's current size	
	data* Head;		
}queue;

queue CreateQueue(int size);
	// create a empty queue
data* CreateNode(int number);
	// create a Node with number
int Enqueue(queue &q,data* i);
	// add a Node to queue
int Dequeue(queue &s);
	// delete a Node of queue
void GetSize(queue q);
	// get fixsize and currentsize of queue
void Display(queue q);
	// display the queue's data
void Release(queue &q);
	// delete the queue

#endif
