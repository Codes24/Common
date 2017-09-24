#include "singlelinklist.h"

list CreateList()
{
	list L;
	L.Head = NULL;
	L.Tail = NULL;
	return L;
}

data* CreateNode(int number)
{
	data* i = new data;
	i->Number = number;
	i->Next = NULL;
	return i;
}

void AddBegin(list &L,data* i)
{
	if (L.Head == NULL)
	{
		L.Head = i;
		L.Tail = L.Head;
		return;
	}
	else
	{
		i->Next = L.Head;
		L.Head = i;
		return;
	}
}

void AddEnd(list &L,data* i)
{
	if (L.Head == NULL)
	{
		L.Head = i;
		L.Tail = L.Head;
	}
	else
	{
		L.Tail->Next = i;
		L.Tail = i;
	}
}

void Delete(list &L,int number)
{
	data* i = L.Head;
	if (i->Number == number)
	{
		L.Head = L.Head->Next;
		delete i;
		return;
	}
	else
	{
		while(i->Next != NULL)
		{
			if (i->Next->Number == number)
			{
				data* temp = i->Next;
				i->Next = temp->Next;
				delete temp;
				return;
			}
			i = i->Next;
		}
	}
}

void Release(list &L)
{
	while (L.Head != NULL)
	{
		data* i = L.Head;
		L.Head = L.Head->Next;
		delete i;
	}
	return;
}

void Display(list L)
{
	data* i = L.Head;
	for (;i!=NULL;i=i->Next)
	{
		cout<<i->Number<<endl;
	}
	return;
}