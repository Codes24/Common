/*The prime factors of 13195 are 5, 7, 13 and 29.
What is the largest prime factor of the number 600851475143 ?*/

#include "iostream"
#include "cmath"

using namespace std;

long isPrime(long n)
{
	for (long i=2;i<n;i++)
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

long find(long n)	/* #Tue27Sep2016 */
{
	long i = 2;
	while(isPrime(n) == 0)
	{
		if (n%i == 0)
			n = n / i;
		else
			i = nextPrime(i);
	}
	return n;
}

int main()
{
	cout<<find(600851475143)<<endl;
}