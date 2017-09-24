#include "queue.h"

queue CreateQueue(int size)
{
	queue q;
	q.FixSize = size;
	q.Head = NULL;
	q.CurrentSize = 0;
	return q;
}

data* CreateNode(int number)
{
	data* i = new data;
	i->Number = number;
	i->Next = NULL;
	return i;
}

int Enqueue(queue &q,data* i)
{
	if (q.CurrentSize == q.FixSize)
	{
		cout<<"QUEUE::STATUS::FULL"<<endl;
		return 0;
	}
	else
	{
		if (q.Head == NULL)
		{
			q.Head = i;
			q.CurrentSize++;
		}
		else
		{
			i->Next = q.Head;
			q.Head = i;
			q.CurrentSize++;
		}
		return 1;
	}
}

int Dequeue(queue &q)
{
	if (q.CurrentSize == 0)
	{
		cout<<"QUEUE::STATUS::EMPTY"<<endl;
		return 0;
	}
	else
	{
		if (q.CurrentSize == 1)
		{
			data* i = q.Head;
			q.Head = NULL;
			delete i;
			q.CurrentSize--;
		}
		else
		{
			while(q.Head->Next->Next != NULL)
			{
				q.Head = q.Head->Next;
			}
			data* i = q.Head->Next;
			q.Head = NULL;
			delete i;
			q.CurrentSize--;
		}
		return 1;
	}
}

void GetSize(queue q)
{
	cout<<"The queue's fiz size: "<<q.FixSize<<endl;
	cout<<"The queue's current size: "<<q.CurrentSize<<endl;
	return;
}

void Display(queue q)
{
	data* i = q.Head;
	for (;i!=NULL;i=i->Next)
	{
		cout<<"   "<<i->Number<<endl;
	}
	return;
}

void Release(queue &q)
{
	while (q.Head != NULL)
	{
		data* i = q.Head;
		q.Head = q.Head->Next;
		delete i;
	}
	return;
}