#include "stack.h"

stack CreateStack(int size)
{
	stack i;
	i.FixSize = size;
	i.CurrentSize = 0;
	i.Head = NULL;
	return i;
}

data* CreateNode(int number)
{
	data* i = new data;
	i->Number = number;
	i->Next = NULL;
	return i;
}

int push(stack &s,data* i)
{
	if (s.CurrentSize == s.FixSize)
	{
		cout<<"STACK::STATUS::FULL"<<endl;
		return 0;
	}
	else
	{
		if (s.CurrentSize == 0)
		{
			s.Head = i;
			s.CurrentSize++;
			return 1;
		}
		else
		{
			i->Next = s.Head;
			s.Head = i;
			s.CurrentSize++;
			return 1;
		}
	}
}

int pop(stack &s)
{
	if (s.CurrentSize == 0)
	{
		cout<<"STACK::STATUS::EMPTY"<<endl;
		return 0;
	}
	else
	{
		data* i = s.Head;
		s.Head = s.Head->Next;
		delete i;
		s.CurrentSize--;
		return 1;
	}
}

void GetSize(stack s)
{
	cout<<"The stack's fix size: "<<s.FixSize<<endl;
	cout<<"The stack's current size: "<<s.CurrentSize<<endl;
	return;
}

void Display(stack s)
{
	data* i = s.Head;
	for (;i!=NULL;i=i->Next)
	{
		cout<<"   "<<i->Number<<endl;
	}
	return;
}

void Release(stack &s)
{
	if (s.Head == NULL) return;
	data* i = s.Head;
	s.Head = s.Head->Next;
	delete i;
}