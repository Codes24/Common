#ifndef INTEGRAL_H
#define INTEGRAL_H
#include "iostream"
#include "../calculate/calculate.h"

class integral
{
private:
	char* function;
	float startPoint;
	float endPoint;
	float result;
	float accuracy;
	calculate* cal;
public:
	integral();
	~integral();
	void input();
	void setup();
	void output();
	void solve();
	/*	replace x with number in function */
	char* replaceX(float x);
	/*	this function will return area of a rectangle at a x value */
	float atPoint(const char* y, float x);
};

#endif