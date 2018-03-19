#include "integral.h"
#include "cstring"

using namespace std;

integral::integral(){}
integral::~integral()
{
	delete cal;
}

void integral::input()
{
	char* func = new char[100];
	cout<<"-------	Read this -------------------------------"<<endl;
	cout<<"The function contain only some operator ( + - * /)"<<endl;
	cout<<"--------------------------------------------------"<<endl<<endl;;
	cout<<"Enter a function: ";
	fgets(func, 100, stdin);
	function = new char[strlen(func) + 1];
	strcpy(function, func);
	cout<<"Start point: ";
	cin>>startPoint;
	cout<<"End point: ";
	cin>>endPoint;
	cout<<"-------- Read this ---------------------------------------------------"<<endl;
	cout<<"Give a number which determine the accuracy of the final result"<<endl;
	cout<<"A smaller number, a higher accuracy but program's speed will be slower"<<endl;
	cout<<"----------------------------------------------------------------------"<<endl;
	cout<<"Accuracy: ";
	cin>>accuracy;
	setup();
	delete func;
}
void integral::setup()
{
	result = 0;
	cal = new calculate();
}
void integral::output()
{
	cout<<" = "<<result<<endl;
}

void integral::solve()
{
	if (startPoint == endPoint)
		return;
	float i = startPoint;
	for(i;i<=endPoint;i+=accuracy)
	{
		result += atPoint(replaceX(i) ,accuracy);
	}
}

char* integral::replaceX(float x)
{
	char* exp = new char[100];
	char* xStr = new char[20];
	sprintf(xStr, "%f", x);
	strcpy(exp, "");
	int i = 0;
	while (function[i] != '\0' && function[i] != '\n')
	{
		if (function[i] == 'x')
		{
			strcat(exp, xStr);
			i++;
		}
		else
		{
			char* temp = new char[20];
			int j = 0;
			while(function[i] != 'x' && function[i] != '\0' && function[i] != '\n')
			{
				temp[j] = function[i];
				j++;
				i++;
			}
			temp[j] = '\0';
			strcat(exp, temp);
		}
	}
	return exp;
}

float integral::atPoint(const char* y, float x)
{
	cal->setup(y);
	cal->solve();
	return x*cal->get();
}