#ifndef STACK_H
#define STACK_H
#include "iostream"

using namespace std;

typedef struct data
{
	int Number;
	struct data* Next;
}data;

typedef struct stack
{
	int FixSize;
	int CurrentSize;
	data* Head;
}stack;

stack CreateStack(int size);
	// create the stack
data* CreateNode(int number);
	// create the node of data
int push(stack &s,data* i);
	// add a Node to top of Stack
int pop(stack &s);
	// delete the top Node of Stack
data* top(stack &s);
	// return thr top Node of Stack
void GetSize(stack s);
	// cout the Fixsize and currentsize of Stack
void Display(stack s);
	// display the data of Stack
void Release(stack &s);
	// delete the Stack


#endif