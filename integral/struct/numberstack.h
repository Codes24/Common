#ifndef NUMBERSTACK_H
#define NUMBERSTACK_H
#include "iostream"

class NumberStack
{
private:
	float* element;
	int capacity;	// max size
	int currentSize;
public:
	NumberStack();
	~NumberStack();
	int getCurrentSize();
	void setCapacity(int size);
	void newElement(int size);
	void push(float a);
	float pop();
};


#endif
