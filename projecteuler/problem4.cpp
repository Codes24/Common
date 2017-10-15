/*A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.*/

#include "iostream"
#include "cmath"

using namespace std;

int is(int n)
{
	int a,b,c,d,e,f;
	a = n/100000;
	n = n%100000;
	b = n/10000;
	n = n%10000;
	c = n/1000;
	n = n%1000;
	d = n/100;
	n = n%100;
	e = n/10;
	n = n%10;
	f = n;
	if (a==f && b==e && c==d)
		return 1;
	else
		return 0;
}

int carryOut(int n)
{
	int i = 100;
	while(n>99)
	{
		if (is(n) == 1)
		{
			for (i=100;i<1000;i++)
			{
				if (n%i==0 && n/i<1000)
				{
					cout<<i<<endl;
					return n;
				}
			}
		}
		n--;
	}
}

int main()
{
	cout<<carryOut(999999)<<endl;
}