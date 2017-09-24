#include "singlelinklist.h"

student* CreateList()
{
	return NULL;
}

student* CreateNode(char* name,char* id,int number)
{
	student* i = new student;
	i->Name = new char[strlen(name)+1];
	strcpy(i->Name,name);
	i->ID = new char[strlen(id)+1];
	strcpy(i->ID,id);
	i->Number = number;
	i->Next = NULL;
	return i;
}

void Insert(student* &Start,student* Node)
{
	if (Start == NULL)
	{
		Start = Node;
		return;
	}
	Insert(Start->Next,Node);
}

void DeleteNode(student* &Start,int number)
{
	if (Start->Number == number)
	{
		student* Temp = Start;
		Start = Start->Next;
		delete Temp;
		return;
	}
	else
	{
		while(Start->Next != NULL && Start->Next->Number != number)
		{
			Start = Start->Next;
		}
		if (Start->Next == NULL)
		{
			cout<<"LIST::STATUS::NOT::FOUND"<<endl;
			return;
		}
		student* Temp = Start->Next;
		Start->Next = Temp->Next;
		delete Temp;
		return;
	}
}

void DeleteList(student* &Start)
{
	student* Temp;
	while (Start != NULL)
	{
		Temp = Start;
		Start = Start->Next;
		delete Temp;
	}
	return;
}

void Display(student* Start)
{
	student* i = Start;
	for (;i!=NULL;i=i->Next)
	{
		cout<<"===================="<<endl;
		cout<<"Name: "<<i->Name<<endl;
		cout<<"ID: "<<i->ID<<endl;
		cout<<"Number: "<<i->Number<<endl;
	}
	return;
}