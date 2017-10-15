/*
The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.
*/
#include "iostream"
#include "cmath"
using namespace std;
long isPrime(long n)
{
	for (long i=2;i<=(int)sqrt(n);i++)
	{
		if (n%i==0) 
			return 0;
	}
	return 1;
}

long nextPrime(long n)
{
	n = n + 1;
	while(isPrime(n)==0)
	{
		n = n + 1;
	}
	return n;
}

int main()
{
	signed long long int a = 0;
	int i = 2;
	while (i < 2000000)
	{
		a = a + i;
		i = nextPrime(i);
	}
	cout<<a<<endl;
}
