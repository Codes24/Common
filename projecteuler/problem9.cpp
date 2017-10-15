/*
A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.
*/

#include "iostream"
#include "cmath"
using namespace std;
int main()
{
	int a,b,c;
	int product = 1;
	for(int i=3;i<1000;i++)
	{
		for (int j=i+1;j<1000;j++)
		{
			a = i;
			b = j;
			c = 1000 - a - b;
			if ( c > b)
			{
				if ((a*a + b*b) == (c*c))
				{
					cout<<a<<"\t"<<b<<"\t"<<c<<endl;
					product = a*b*c;
					break;
				}
			}
		}
	}
	cout<<product<<endl;
}