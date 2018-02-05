#ifndef CALCULATE_H
#define CALCULATE_H
#include "iostream"
#include "cstdio"
#include "../struct/numberstack.h"
#include "../struct/tokenstack.h"
#include "convert.h"

class calculate
{
private:
	char* expression;
	NumberStack* numberStack;
	TokenStack* tokenStack;
	int currentIndex;
	float result;
public:
	calculate();
	~calculate();
	int countToken();
	int countNumber();
	void setup(const char* exp);
	void input();
	void output();
	float get();
	void init();
	char* getNumber();
	char* getTrigonometric();
	void analyze();
	float cal(float oper1, char sign, float oper2);
	void solve();
};

#endif