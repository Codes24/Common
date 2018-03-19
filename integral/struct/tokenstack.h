#ifndef TOKENSTACK_H
#define TOKENSTACK_H
#include "iostream"

class TokenStack
{
private:
	char* element;
	int capacity;	// max size
	int currentSize;
public:
	TokenStack();
	~TokenStack();
	int getCurrentSize();
	void setCapacity(int size);
	void newElement(int size);
	void push(char a);
	char pop();	
};

#endif
