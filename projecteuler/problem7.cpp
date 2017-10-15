/*By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
What is the 10 001st prime number?*/
#include "iostream"
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

int main()
{
	int i=1;
	int n=2;
	while(i!=10001)
	{
		n = nextPrime(n);
		i++;
	}
	cout<<n<<endl;
}