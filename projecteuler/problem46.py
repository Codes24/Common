# problem:	https://projecteuler.net/problem=46
# 31 January, 2017 by me
import math

def is_prime(number):
	i = 2
	while i <= math.sqrt(number):
		if number%i == 0:
			return False
		else:
			i = i+1
	return True

def next_prime(number):
	n = number + 1
	while(1):
		if is_prime(n) == True:
			return n
		n = n + 1

def is_odd_composite(number):
	if is_prime(number) == True:
		return False
	return True

def next_odd_composite(number):
	n = number + 2
	while(1):
		if is_odd_composite(n) == True:
			return n
		n = n + 2

def find_square(number):
	if number%2 != 0:
		return False
	n = number / 2
	return math.sqrt(n) == int(math.sqrt(n))


def MAIN():
	i = next_odd_composite(33)
	while(1):
		prime = 3
		while(prime < i):
			twice_square = i - prime
			if find_square(twice_square) == True:
				prime = i
			else:
				prime = next_prime(prime)
				if prime >= i:
					return i
		i = next_odd_composite(i)



print(MAIN())