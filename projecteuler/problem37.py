# The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, 
# and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

# Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

# NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
import math
def isPrime(n):
	i = 2
	if n == 0 | n == 1:
		return 0
	while i <= math.sqrt(n):
		if n%i == 0:
			return 0
		i += 1
	return 1
def next_prime(n):
	if isPrime(n+1) == 1:
		return n+1
	else:
		return next_prime(n+1)
def get_digits(n):
	digits = []
	while n//10 != 0:
		digits.append(n%10)
		n = n//10
	digits.append(n)
	return digits
def get_number(digits):
	number = 0
	i = 0
	while i < len(digits):
		number += digits[i] * (10**i)
		i += 1
	return number

def check_left(n):
	digits = get_digits(n)
	i = len(digits) - 1
	while i > 0:
		del digits[i]
		if isPrime(get_number(digits)) == 0:
			return 0
		i -= 1
	return 1

def check_right(n):
	digits = get_digits(n)
	i = 0
	while i < (len(digits) - 1):
		del digits[i]
		if isPrime(get_number(digits)) == 0:
			return 0
	return 1

def my_main():
	i = 11
	count = 0
	total = 0
	while count < 11:
		if (check_left(i) == 1) & (check_right(i) == 1):
			count += 1
			total += i
		i = next_prime(i)
	return total

print(my_main())