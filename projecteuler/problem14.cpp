/*
*	problem 14
*	The following iterative sequence is defined for the set of positive integers:
*
*			n → n/2 (n is even)
*			n → 3n + 1 (n is odd)
*
*	Using the rule above and starting with 13, we generate the following sequence:
*
*			13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
*	It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.
*
*	Which starting number, under one million, produces the longest chain?
*
*	NOTE: Once the chain starts the terms are allowed to go above one million.
*/
#include "iostream"

long long next_term(long long current_term)
{
	if (current_term % 2 == 0)
		return current_term / 2;
	else
		return (current_term * 3) + 1;
}
long long count_term(long long number)
{
	long long count = 1;
	while(number > 1)
	{
		number = next_term(number);
		count++;
	}
	return count;
}
long long find_number()
{
	long long max = 0;
	long long number;
	long long term;
	long long i;
	for(i=1;i<1000000;i++)
	{
		term = count_term(i);
		if (max < term)
		{
			max = term;
			number = i;
		}
	}
	return number;
}
int main()
{
	std::cout<<find_number()<<std::endl;
	return 0;
}