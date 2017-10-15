#include "iostream"
#include "math.h"

using namespace std;

int check(long double fnumber)
{
	if (fnumber == 0)
		return 0;
	long n = 10,count = 1;
	long double fpart, nowf;
	double intpart, nowInt;
	long nowValue;
	while(1)
	{
		fpart = modf(fnumber * n, &intpart);
		nowValue = intpart;
		intpart = 0;
		nowf = modf(fpart * n, &intpart);
		if (nowValue == intpart)
			return count;
		else
		{
			if (intpart == 0)
				return count;
			else
			{
				n *= 10;
				count++;
			}
		}
		
	}
}

int main()
{
	int max = 0;
	long double n;
	long double result;
	long double fpart;
	double intpart;
	for(long double i=1;i<1000;i++)
	{
		fpart = modf(1/i, &intpart);
		if (check(fpart) > max)
		{
			max = check(fpart);
			result = i;
		}
	}
	cout<<result<<endl;
	return 0;
}