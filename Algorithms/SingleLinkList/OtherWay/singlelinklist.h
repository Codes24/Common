#ifndef SINGLELINKLIST_H
#define SINGLELINKLIST_H
#include "iostream"

using namespace std;

typedef struct data
{
	int Number;
	struct data* Next;
}data;

typedef struct list
{
	data* Head;
	data* Tail;
}list;

list CreateList();
	// create a NULL list
data* CreateNode(int number);
	// create a Node
void AddBegin(list &L,data* i);
	// add a Node at begin the list
void AddEnd(list &L,data* i);
	// add a Node at the end the list
void Delete(list &L,int number);
	// delete a node of list
void Release(list &L);
	// delete the list
void Display(list L);
	// display the list

#endif