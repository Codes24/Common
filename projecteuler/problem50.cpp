#include "iostream"

using namespace std;
int isPrime(int number)
{
	if (number == 2) return 1;
	if (number == 1 || number == 0) return 0;
	for(int i=2;i<number;i++)
	{
		if (number % i ==0)
			return 0;
	}
	return 1;
}

int nextPrime(int number)
{
	number = number + 1;
	while(1)
	{
		if (isPrime(number) == 1)
			return number;
		number++;
	}
}

int countPrime(int n)
{
	int min = 2;
	int count = 1;
	int subed = 2;
	int m = n;
	while(1)
	{
		subed = min;
		count = 1;
		m = n;
		while(1)
		{
			m = m - subed;
			count++;
			if (m < subed)
			{
				min = nextPrime(min);
				if (min > n)
					return 1;
				break;
			}
			else if (m == nextPrime(subed))
				return count;
			else
				subed = nextPrime(subed);
		}
	}
}

int sum()
{
	int sum = 0;
	int t = 1;
	int i = 2;
	while(sum <= 953)
	{
		sum += i;
		cout<<i<<endl;
		i = nextPrime(i);
	}
}

int main()
{
	int max = 0;
	int n;
	int i = 2;
	while(i < 1000)
	{
		n = countPrime(i);
		if (n > max)
			max = n;
		i = nextPrime(i);
	}
	cout<<max<<endl;
	// cout<<sum()<<endl;
}