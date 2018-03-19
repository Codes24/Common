#include "calculate.h"
#include "string.h"

using namespace std;

calculate::calculate(){}
calculate::~calculate()
{
	delete expression;
	delete tokenStack;
	delete numberStack;
}

int calculate::countToken()
{
	int i = 0;
	int count = 0;
	while(expression[i] != '\0')
	{
		if (expression[i] == '*' || expression[i] == '+' ||
			expression[i] == '-' || expression[i] == '/')
		{
			count++;
		}
		i++;
	}
	return count;
}

int calculate::countNumber()
{
	int i = 0;
	int j;
	int count = 0;
	while(expression[i] != '\0')
	{
		if (expression[i] > 48 && expression[i] <= 57)
		{
			count++;
			while(expression[i] >= 48 && expression[i] <= 57)
			{
				i++;
			}
		}
		i++;
	}
	return count;
}
void calculate::setup(const char* exp)
{
	expression = new char[strlen(exp) + 1];
	strcpy(expression, exp);
}
void calculate::input()
{
	char temp[100];
	fgets(temp, 100, stdin);	
	expression = new char[strlen(temp) + 1];
	strcpy(expression, temp);
}

float calculate::get()
{
	return result;
}
void calculate::init()
{
	numberStack = new NumberStack();
	numberStack->newElement(countNumber());
	numberStack->setCapacity(countNumber());
	tokenStack = new TokenStack();
	tokenStack->newElement(countToken());
	tokenStack->setCapacity(countToken());
	currentIndex = 0;
	result = 0;
}

char* calculate::getNumber()
{
	char* number = new char[10];
	int i = currentIndex;
	int j = 0;
	while(expression[i] != ' ' && expression[i] != '+' && 
		expression[i] != '-' && expression[i] != '*' &&
		expression[i] != '/' && expression[i] != ')' &&
		expression[i] != '\0' && expression[i] != '\n')
	{
		number[j] = expression[i];
		j++;
		i++;
	}
	number[j] = '\0';
	currentIndex = i-1;
	return number;
}
float calculate::cal(float oper1, char sign, float oper2)
{
	if (sign == '+') return oper1 + oper2;
	else if (sign == '-') return oper1 - oper2;
	else if (sign == '*') return oper1 * oper2;
	else return oper1 / oper2;
}

void calculate::analyze()
{
	while(expression[currentIndex] != '\0')
	{
		if (expression[currentIndex] == '(' || expression[currentIndex] == '*' || expression[currentIndex] == '/' ||
			expression[currentIndex] == '+' || expression[currentIndex] == '-')
		{
			tokenStack->push(expression[currentIndex]);
		}
		else if ((expression[currentIndex] >= 48 && expression[currentIndex] <= 57) || 
			expression[currentIndex] == ',' || expression[currentIndex] == '.')
		{
			char* num = getNumber();
			numberStack->push(toFloat(num));
			if(tokenStack->getCurrentSize() > 0)
			{
				char sign = tokenStack->pop();
				if (sign == '*' || sign == '/')
				{
					int i = currentIndex + 1;
					while(i == ' ')
						i++;
					if (expression[i] != '(')
					{
						float oper2 = numberStack->pop();
						float oper1 = numberStack->pop();
						float oper3 = cal(oper1, sign, oper2);
						numberStack->push(oper3);
					}
					else
						tokenStack->push(sign);
				}
				else if (sign == '+' || sign == '-')
				{
					int i = currentIndex + 1;
					while(i == ' ')
						i++;
					if (expression[i] == '+' || expression[i] == '-' || expression[i] == ')' || 
						expression[i] == '\0' || expression[i] == '\n')
					{
						float oper2 = numberStack->pop();
						float oper1 = numberStack->pop();
						float oper3 = cal(oper1, sign, oper2);
						numberStack->push(oper3);
					}
					else
						tokenStack->push(sign);
				}
			}
		}
		currentIndex++;
	}
	while (numberStack->getCurrentSize() > 1)
	{
		char sign = tokenStack->pop();
		float oper2 = numberStack->pop();
		float oper1 = numberStack->pop();
		float oper3 = cal(oper1, sign, oper2);
		numberStack->push(oper3);
	}
	result = numberStack->pop();
}

void calculate::solve()
{
	init();
	analyze();
}

void calculate::output()
{
	cout<<" = "<<result<<endl;
}