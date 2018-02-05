#include "tokenstack.h"

using namespace std;

TokenStack::TokenStack()
{
	currentSize = 0;
}

TokenStack::~TokenStack()
{
	if (element != NULL)
		delete element;
}

void TokenStack::newElement(int size)
{
	element = new char[size];
	currentSize = 0;
}

void TokenStack::push(char a)
{
	element[currentSize] = a;
	currentSize++;
}

char TokenStack::pop()
{
	if (currentSize>0)
	{
		currentSize--;
		return element[currentSize];
	}
	return ':';
}
void TokenStack::setCapacity(int size)
{
	capacity = size;
}
int TokenStack::getCurrentSize()
{
	return currentSize;
}