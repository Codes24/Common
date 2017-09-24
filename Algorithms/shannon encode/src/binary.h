#ifndef BINARY_H
#define BINARY_H
#include "stdio.h"
#include "stdlib.h"

/*	structure of a number in binary */
typedef struct binary
{
	int* _array_;	// a bits array  
	int size;		// number of bits
}binary;

binary* ftob(double base10);	// convert a base-10 double number to binary
void display_b(const binary* bin);
binary* ftob(double base10)
{
	binary* bin = malloc(sizeof(binary));
	bin->size = 10;
	bin->_array_ = malloc(10 * sizeof(int));
	int i;
	for (i=0;i<10;i++)
	{
		base10 *= 2;
		if (base10 >= 1)
		{
			bin->_array_[i] = 1;
			base10 -= 1;
		}
		else
			bin->_array_[i] = 0;
	}
	return bin;
} 

void display_b(const binary* bin)
{
	int i;
	for (i=0;i<bin->size;i++)
		printf("%d", bin->_array_[i]);
	return;
}
#endif