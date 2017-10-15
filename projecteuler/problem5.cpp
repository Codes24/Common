/*2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.
What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?*/
#include "iostream"
#include "cmath"

using namespace std;

int main()
{
	long n = 2520;
	int t=0;
	while(t==0)
	{
		for (long i=1;i<=21;i++)
		{
			if (i==21)
			{
				cout<<n<<endl;
				t = 1;
				break;
			}
			else if (n%i != 0)
			{
				break;
			}	
		}
		n++;
	}
}