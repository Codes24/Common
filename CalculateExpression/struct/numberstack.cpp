#include "numberstack.h"

using namespace std;

NumberStack::NumberStack()
{
	currentSize = 0;
}
NumberStack::~NumberStack()
{
	if (element != NULL)
		delete element;
}

void NumberStack::newElement(int size)
{
	element = new float[size];
	currentSize = 0;
}

void NumberStack::push(float a)
{
	element[currentSize] = a;
	currentSize++;
}

float NumberStack::pop()
{
	if (currentSize>0)
	{
		currentSize--;
		return element[currentSize];
	}
}
void NumberStack::setCapacity(int size)
{
	capacity = size;
}
int NumberStack::getCurrentSize()
{
	return currentSize;
}